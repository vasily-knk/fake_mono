using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Text;
using UnityEngine;
using System.Runtime.CompilerServices;
using System.Linq;
using System.Threading;


namespace ClassLibrary1
{
    class ObjectDataOps
    {
        public static Vector3 ExtractPos(GameObject o)
        {
            return o.transform.position;
        }
    }

    public struct ObjectData
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

    public struct TempStruct
    {
        public readonly int i;
        public readonly float f;

        public TempStruct(int i, float f)
        {
            this.i = i;
            this.f = f;
        }
    }

    public class MyWatcher
        : MonoBehaviour
    {
        private int _numReports = 0;
        private long _frame = 0;
        private List<Delta> _deltas = new List<Delta>();
        private readonly Stopwatch _stopwatch = new Stopwatch();
        private bool _slideshow = false;

        private int _objectsUpdateRate = 1;

        private FrameRegister _frameRegister = new FrameRegister(RegisterNewFrame);

        HashSet<long> _prevOjects = new HashSet<long>();
        private WeakReference[] _objectsCache = {};

        public static GameObject CreateObject()
        {
            var o = new GameObject("MyWatcher");
            o.AddComponent<MyWatcher>();
            return o;
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void OnObjectDestroying(GameObject o);

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void ReportMe(TempStruct s);

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
            using (new StopwatchWrapper(_stopwatch))
            {
                if (_frame % _objectsUpdateRate == 0)
                    UpdateObjectsCache();

                var objectsData = new ObjectData[_objectsCache.Length];
                for (int i = 0; i < _objectsCache.Length; ++i)
                {
                    if (_objectsCache[i].IsAlive)
                        objectsData[i] = new ObjectData(_objectsCache[i].Target as GameObject);
                }


                //            var currentObjects = _objectsCache
                //                .Where(w => w.IsAlive)
                //                .Select(w => w.Target as GameObject);
                //
                //            var objectsData = currentObjects
                //                .Select(o => new ObjectData(o))
                //                .ToArray();

                //_frameRegister.Invoke(objectsData);

                ++_frame;
            }

            updateFPS();
        }

        private static void BeSlow()
        {
            //Thread.Sleep(1000);
            Class1.Print("Hello!\n");
        }


        void Update()
        {
            if (Input.GetKeyDown(KeyCode.L))
                Destroy(gameObject);

            bool printUpdateRate = false;
            if (Input.GetKeyDown(KeyCode.O))
            {
                if (_objectsUpdateRate > 1)
                    _objectsUpdateRate /= 2;
                printUpdateRate = true;
            }
            
            if (Input.GetKeyDown(KeyCode.P))
            {
                _objectsUpdateRate *= 2;
                printUpdateRate = true;
            }

            if (printUpdateRate)
                Class1.Print(String.Format("Objects update rate: {0}", _objectsUpdateRate));
        }

        private delegate void FrameRegister(ObjectData[] data);
        
        private static void RegisterNewFrame(ObjectData[] data)
        {
            foreach (var d in data)
            {
                
            }
        }

        private void UpdateObjectsCache()
        {
            var foundObjects = FindObjectsOfType<GameObject>();
            _objectsCache = foundObjects.Select(o => new WeakReference(o)).ToArray();
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
