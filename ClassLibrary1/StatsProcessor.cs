using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace ClassLibrary1
{
    class StatsProcessor
    {
        private long _frame = 0;
        private List<ObjectData> _objectDatas = new List<ObjectData>();

        public void RegisterObject(GameObject o)
        {
            _objectDatas.Add(new ObjectData(_frame, o));
        }

        public void Update()
        {
            try
            {
//                if (_frame % _objectsUpdateRate == 0)
//                    UpdateObjectsCache();
//
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

        public void FindOris()
        {
            var oris = _objectDatas.Where(o => o.Name.ToLower().Contains("ori")).ToArray();
        }
        
        private void Cleanup()
        {
            var alive = _objectDatas.Where(d => d.IsAlive);
            _objectDatas = alive.ToList();
        }
    }
}
