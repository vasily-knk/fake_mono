using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using UnityEngine;

namespace ClassLibrary1
{
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
}
