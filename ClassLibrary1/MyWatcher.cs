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

    struct UpdateData
    {
        public readonly long Frame;
        public readonly Vector3 Pos;

        public UpdateData(long frame, GameObject o)
        {
            Frame = frame;
            Pos = o.transform.position;
        }

        public bool UpdateEquals(UpdateData prev)
        {
            return Pos.Equals(prev.Pos);
        }
    }

    public class ObjectData
    {
        private bool _isInitialized = false;
        private readonly long _initialFrame;
        private readonly WeakReference _objectRef;
        private readonly List<UpdateData> _updates = new List<UpdateData>();

        public readonly int Id;
        public String Name { get; private set; }

        public bool IsAlive
        {
            get
            {
                return _objectRef.IsAlive;
            }
        }

        public ObjectData(long frame, GameObject o)
        {
            _initialFrame = frame;
            _objectRef = new WeakReference(o);

            Id = o.GetInstanceID();
            Name = "--unnamed--";
        }

        public void Update(long frame)
        {
            var o = _objectRef.Target as GameObject;
            if (!o)
                return;

            if (!_isInitialized)
            {
                Name = o.name;
                _isInitialized = true;
            }

            var ud = new UpdateData(frame, o);
            if (!_updates.Any() || !_updates.Last().UpdateEquals(ud))
                _updates.Add(ud);
        }

    }

    public class MyWatcher
        : MonoBehaviour
    {
        private long _frame = 0;
        private int _objectsUpdateRate = 32;
        private List<ObjectData> _objectDatas = new List<ObjectData>();

        public static MyWatcher CreateObject()
        {
            var o = new GameObject("MyWatcher");
            var w = o.AddComponent<MyWatcher>();
            return w;
        }

        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void OnObjectDestroying(MyWatcher o);

        public void RegisterObject(GameObject o)
        {
            if (o == gameObject)
                return;

            _objectDatas.Add(new ObjectData(_frame, o));
        }

        void Start()
        {
            Class1.Print("MyWatcher started.\n");
        }

        void OnDestroy()
        {
            Class1.Print("MyWatcher being destroyed.\n");
            OnObjectDestroying(this);
        }

        void FixedUpdate()
        {
            try
            {
                if (_frame % _objectsUpdateRate == 0)
                    UpdateObjectsCache();

                foreach (var data in _objectDatas)
                    data.Update(_frame);

            }
            catch (Exception e)
            {
                Class1.Print(String.Format("Error: {0}\nStack: {1}\n", e.Message, e.StackTrace));
                throw e;
            }
            
            ++_frame;
        }

        void Update()
        {
            if (Input.GetKeyDown(KeyCode.L))
                Destroy(gameObject);
   
            if (Input.GetKeyDown(KeyCode.O))
            {
                var oris = _objectDatas.Where(o => o.Name.ToLower().Contains("ori")).ToArray();
            }
        }

        private void UpdateObjectsCache()
        {
            var alive = _objectDatas.Where(d => d.IsAlive);
            _objectDatas = alive.ToList();
        }

//        private void updateFPS()
//        {
//            const int numFrames = 60;
//            if (_frame % numFrames == 0)
//            {
//                var s = new StringBuilder();
//                s.Append("Stats:\n")
//                    .AppendFormat("   Retrival  : {0}\n", getAvgProfMicrosecs(_profilerRetrieval , numFrames))
//                    .AppendFormat("   Processing: {0}\n", getAvgProfMicrosecs(_profilerProcessing, numFrames))
//                    .AppendFormat("   Total     : {0}\n", getAvgProfMicrosecs(_profilerTotal     , numFrames))
//                    ;
//
//                Class1.Print(s.ToString());
//            }
//        }
//
//        private long getAvgProfMicrosecs(Stopwatch prof, int numFrames)
//        {
//            var avgTicks = prof.Elapsed.Ticks / numFrames;
//            var avgMicrosecs = avgTicks / 10;
//            prof.Reset();
//            return avgMicrosecs;
//        }
    }
}
