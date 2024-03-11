using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphicEditor
{
    internal class FillUnitEditorCommand : EditorCommand
    {
        private CanvaUnit receiverUnit;

        public FillUnitEditorCommand(CanvaUnit receiverUnit_)
        {
            receiverUnit = receiverUnit_;
        }

        public void Execute()
        {
            receiverUnit.Fill();
        }
    }
}
