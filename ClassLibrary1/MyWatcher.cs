using System;
using System.Collections.Generic;
using System.Text;
using UnityEngine;
using System.Runtime.CompilerServices;
using System.Linq;


namespace ClassLibrary1
{
    public class MyWatcher
        : MonoBehaviour
    {
        private int _numReports = 0;
        private long _frame = 0;
        private WeakReference[] _oldObjectsWeak = {};

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
            var oldObjects = _oldObjectsWeak.Where(w => w.IsAlive).Select(w => w.Target as GameObject);
            var newObjects = FindObjectsOfType<GameObject>();

            var removed = oldObjects.Except(newObjects);
            var added = newObjects.Except(oldObjects);

            if (removed.Any() || added.Any())
            {
                var s = new StringBuilder();
                s.AppendFormat("\nFrame {0}\n", _frame);

                if (removed.Any())
                {
                    s.Append("Removed objects:\n");

                    foreach (var o in removed)
                        s.AppendFormat("    {0}\n", o.name);
                }
                
                if (added.Any())
                {
                    s.Append("Added objects:\n");

                    foreach (var o in added)
                        s.AppendFormat("    {0}\n", o.name);
                }

                Class1.Print(s.ToString());
            }

            _oldObjectsWeak = newObjects.Select(o => new WeakReference(o)).ToArray();

            ++_frame;
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

    }
}
