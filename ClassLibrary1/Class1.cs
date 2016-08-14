using System;
using System.Text;
using UnityEngine;
using System.Runtime.CompilerServices;

namespace ClassLibrary1
{
    public class Class1
    {
        [MethodImplAttribute(MethodImplOptions.InternalCall)]
        public static extern void Print(String str);
    }
}
