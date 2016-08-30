using System;
using System.Diagnostics;

namespace ClassLibrary1
{
    class StopwatchWrapper : IDisposable
    {
        private readonly Stopwatch _stopwatch;

        public StopwatchWrapper(Stopwatch stopwatch)
        {
            _stopwatch = stopwatch;
            _stopwatch.Start();
        }
        
        public void Dispose()
        {
            _stopwatch.Stop();
        }
    }
}
