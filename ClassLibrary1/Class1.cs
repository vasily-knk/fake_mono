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

            foreach(var o in objects)
            {
                Vector3 pos = o.transform.position;
                
                builder.Append(o.name)
                       .Append(": ")
                       .Append(pos)
                       .Append("\n");
            }

            return builder.ToString();
        }
    }
}
