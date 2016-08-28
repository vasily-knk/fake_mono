using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using UnityEngine;
using System.Runtime.CompilerServices;
using System.Linq;


namespace ClassLibrary1
{
    class ObjectDataOps
    {
        public static Vector3 ExtractPos(GameObject o)
        {
            return o.transform.position;
        }
    }
    
    struct ObjectData
    {
        public readonly String Name;
        public readonly Vector3 Pos;

        public ObjectData(GameObject o)
        {
            Name = o.name;
            Pos = ObjectDataOps.ExtractPos(o);
        }
    }

    struct Delta
    {
        public readonly KeyValuePair<long, ObjectData>[] Created;
        public readonly long[] Deleted;
        public readonly KeyValuePair<long, Vector3>[] DeltaPos;

        public Delta(KeyValuePair<long, ObjectData>[] created, long[] deleted, KeyValuePair<long, Vector3>[] deltaPos)
        {
            Created = created;
            Deleted = deleted;
            DeltaPos = deltaPos;
        }
    }

    public class MyWatcher
        : MonoBehaviour
    {
        private int _numReports = 0;
        private long _frame = 0;
        private Dictionary<long, ObjectData> _currentObjects = new Dictionary<long, ObjectData>();
        private List<Delta> _deltas = new List<Delta>();
        private readonly Stopwatch _stopwatch = new Stopwatch();

        public static GameObject CreateObject()
        {
            var o = new GameObject("MyWatcher");
            o.AddComponent<MyWatcher>();
            return o;
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void OnObjectDestroying(GameObject o);

        void Start()
        {
            Class1.Print("MyWatcher started.\n");
        }

        void OnDestroy()
        {
            Class1.Print("MyWatcher being destroyed.\n");
            OnObjectDestroying(gameObject);
        }


        void FixedUpdate()
        {
            _stopwatch.Start();

            var newObjects = FindObjectsOfType<GameObject>();
            var newObjectIDs = newObjects.Select(idForObject);
            var removedIDs = _currentObjects.Select(r => r.Key).Except(newObjectIDs);

            var createdObjects = newObjects
                .Where(o => !_currentObjects.ContainsKey(idForObject(o)))
                .Select(o => new KeyValuePair<long, ObjectData>(idForObject(o), new ObjectData(o)));

            var keptObjects = newObjects
                .Where(o => _currentObjects.ContainsKey(idForObject(o)));

            var deltasPos = keptObjects
                .Where(o => ObjectDataOps.ExtractPos(o) != _currentObjects[idForObject(o)].Pos)
                .Select(o => new KeyValuePair<long, Vector3>(idForObject(o), ObjectDataOps.ExtractPos(o)));

            _deltas.Add(new Delta(createdObjects.ToArray(), removedIDs.ToArray(), deltasPos.ToArray()));

            _currentObjects = newObjects.ToDictionary(idForObject, o => new ObjectData(o));

            ++_frame;
            _stopwatch.Stop();

            updateFPS();
        }

        void Update()
        {
            if (Input.GetKeyDown(KeyCode.O))
            {
                PrintObjects();
                ++_numReports;
            }
        }

        private void PrintObjects()
        {
            var objects = FindObjectsOfType<GameObject>();

            var builder = new StringBuilder();
            builder.Append(String.Format("----- MyWatcher report {0}:\n", _numReports));

//             foreach (GameObject obj in objects)
//             {
//                 builder.Append(String.Format("  {0}:\n", obj.name));
// 
//                 var comps = obj.GetComponents<Component>();
//                 foreach (Component comp in comps)
//                 {
//                     builder.Append(String.Format("    {0}\n", comp.ToString()));
//                 }
//             }

            builder.Append(String.Format("----- End of MyWatcher report {0}\n", _numReports));

            Class1.Print(builder.ToString());
        }

        private long idForObject(GameObject o)
        {
            return o.GetInstanceID();
        }

        private void updateFPS()
        {
            const int numFrames = 60;
            if (_frame % numFrames == 0)
            {
                var avgTicks = _stopwatch.Elapsed.Ticks / numFrames;
                var avgMicrosecs = avgTicks / 10;
                Class1.Print(String.Format("\nAvg FixedUpdate time: {0}\nDeltas: {1}\n", avgMicrosecs, _deltas.Count));
                _stopwatch.Reset();
            }
        }

    }
}
