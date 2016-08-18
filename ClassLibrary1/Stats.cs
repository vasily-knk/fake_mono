using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ClassLibrary1
{
    class Stats
    {
        private IList<StatsFrame> frames = new List<StatsFrame>();

        public void Append(StatsFrame frame)
        {
            frames.Add(frame);
        }
    }
}
