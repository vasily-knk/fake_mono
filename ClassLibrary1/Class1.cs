using System;
using System.Text;
using UnityEngine;

namespace ClassLibrary1
{
    public class Class1
    {
        static String GetObjects()
        {
            var objects = UnityEngine.Object.FindObjectsOfType<GameObject>();

            var builder = new StringBuilder();

            foreach (GameObject obj in objects)
            {
                builder.Append(obj.name)
                    .Append(":\n");

                var comps = obj.GetComponents<Component>();
                foreach (Component comp in comps)
                {
                    builder.Append(String.Format("    {0}\n", comp.ToString()));
                }
            }


            return builder.ToString();
        }
    }
}
