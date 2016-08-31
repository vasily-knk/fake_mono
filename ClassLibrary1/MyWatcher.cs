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
        public int Id;
        public Vector3 Pos;

        public ObjectData(GameObject o)
        {
            Id = o.GetInstanceID();
            Pos = ObjectDataOps.ExtractPos(o);
        }

        public void Fill(GameObject o)
        {
            Id = o.GetInstanceID();
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
        private readonly Stopwatch _profilerTotal = new Stopwatch();
        private readonly Stopwatch _profilerRetrieval = new Stopwatch();
        private readonly Stopwatch _profilerProcessing = new Stopwatch();
        private int _objectsUpdateRate = 16;

        private WeakReference[] _objectsCache = {};
        private ObjectData[] _objectDatas = {};
        private int _numObjectDatas = 0;

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
            using (new StopwatchWrapper(_profilerTotal))
            {
                using (new StopwatchWrapper(_profilerRetrieval))
                {
                    if (_frame%_objectsUpdateRate == 0)
                        UpdateObjectsCache();
                }

                using (new StopwatchWrapper(_profilerProcessing))
                {
                    if (_objectDatas.Length < _objectsCache.Length)
                    {
                        int newSize = 1;
                        for (; newSize < _objectsCache.Length; newSize *= 2) { }

                        Class1.Print(String.Format("Resizing array to {0}\n", newSize));
                        _objectDatas = new ObjectData[newSize];
                    }

                    int i = 0;

                    foreach (var w in _objectsCache)
                    {
                        if (w.IsAlive)
                        {
                            _objectDatas[i].Fill(w.Target as GameObject);
                            ++i;
                        }
                    }

                    _numObjectDatas = i;
                }

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
                Class1.Print(String.Format("Objects update rate: {0}\n", _objectsUpdateRate));
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
                var s = new StringBuilder();
                s.Append("Stats:\n")
                    .AppendFormat("   Retrival  : {0}\n", getAvgProfMicrosecs(_profilerRetrieval , numFrames))
                    .AppendFormat("   Processing: {0}\n", getAvgProfMicrosecs(_profilerProcessing, numFrames))
                    .AppendFormat("   Total     : {0}\n", getAvgProfMicrosecs(_profilerTotal     , numFrames))
                    ;

                Class1.Print(s.ToString());
            }
        }

        private long getAvgProfMicrosecs(Stopwatch prof, int numFrames)
        {
            var avgTicks = prof.Elapsed.Ticks / numFrames;
            var avgMicrosecs = avgTicks / 10;
            prof.Reset();
            return avgMicrosecs;
        }
    }
}
