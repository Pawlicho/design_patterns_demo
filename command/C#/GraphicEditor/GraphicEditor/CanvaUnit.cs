using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphicEditor
{
    internal class CanvaUnit
    {
        private bool isFilled;

        public bool IsFilled
        { get { return isFilled; } }

        public CanvaUnit() 
        {
            isFilled = false;
        }

        public void Fill()
        { isFilled = true; }
        public void Wipe()
        { isFilled = false; }
    }
}
