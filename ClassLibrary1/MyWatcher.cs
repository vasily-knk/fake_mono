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
    public class MyWatcher
        : MonoBehaviour
    {
        private readonly StatsProcessor _statsProcessor = new StatsProcessor();

        public static MyWatcher CreateObject()
        {
            var o = new GameObject("MyWatcher");
            var w = o.AddComponent<MyWatcher>();
            return w;
        }

        public void RegisterObject(GameObject o)
        {
            if (o == gameObject)
                return;

            _statsProcessor.RegisterObject(o);
        }

        public void Start()
        {
            Class1.Print("MyWatcher started.\n");
        }

        public void OnDestroy()
        {
            Class1.Print("MyWatcher being destroyed.\n");
            OnObjectDestroying(this);
        }

        public void FixedUpdate()
        {
            _statsProcessor.Update();
        }

        public void Update()
        {
            if (Input.GetKeyDown(KeyCode.L))
                Destroy(gameObject);
   
            if (Input.GetKeyDown(KeyCode.O))
            {
                _statsProcessor.FindOris();
            }
        }
        
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        private static extern void OnObjectDestroying(MyWatcher o);
    }
}
