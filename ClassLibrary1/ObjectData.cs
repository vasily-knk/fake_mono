using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace ClassLibrary1
{
    class ObjectData
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
}
