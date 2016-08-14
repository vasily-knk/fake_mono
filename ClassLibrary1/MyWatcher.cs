using System;
using System.Text;
using UnityEngine;
using System.Runtime.CompilerServices;


namespace ClassLibrary1
{
    public class MyWatcher
        : MonoBehaviour
    {
        private int numReports = 0;

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

        void Update()
        {
            if (Input.GetKeyDown(KeyCode.O))
            {
                PrintObjects();
                ++numReports;
            }
        }

        private void PrintObjects()
        {
            var objects = FindObjectsOfType<GameObject>();

            var builder = new StringBuilder();
            builder.Append(String.Format("----- MyWatcher report {0}:\n", numReports));

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

            builder.Append(String.Format("----- End of MyWatcher report {0}\n", numReports));

            Class1.Print(builder.ToString());
        }

    }
}
