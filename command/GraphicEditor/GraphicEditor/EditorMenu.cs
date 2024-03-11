using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphicEditor
{
    internal class EditorMenu
    {
        private Canva editorCanva;

        private List<EditorCommand> commandBuffer;

        private const int  CANVA_X_SIZE = 10;
        private const int  CANVA_Y_SIZE = 10;

        public EditorMenu()
        {
            editorCanva = new Canva(CANVA_X_SIZE, CANVA_Y_SIZE);
            commandBuffer = new List<EditorCommand>();
        }

        /* To reduce the complexity of an algorithm, which is not a purpose of this demo */
        /* Only straight lines are supported */
        public void FillLine(Coordinations a, Coordinations b)
        {
            if (a.X == b.X) 
            {
                var length = Math.Abs(a.Y - b.Y);
                int y_start;
                if (a.Y < b.Y)
                {
                    y_start = a.Y; 
                }
                else
                {
                    y_start = b.Y;
                }
                for (int i = 0; i < length; i++)
                {
                    var processed_cords = new Coordinations(a.X, y_start + i);
                    var processed_unit = editorCanva.GetUnit(processed_cords);
                    commandBuffer.Add(new FillUnitEditorCommand(processed_unit));
                }
            }
            else if (a.Y == b.Y)
            {
                var length = Math.Abs(a.X - b.X);
                int x_start;
                if (a.X < b.X)
                {
                    x_start = a.X;
                }
                else
                {
                    x_start = b.X;
                }
                for (int i = 0; i < length; i++)
                {
                    var processed_cords = new Coordinations(x_start + i, a.Y);
                    var processed_unit = editorCanva.GetUnit(processed_cords);
                    var temp = new FillUnitEditorCommand(processed_unit);
                    commandBuffer.Add(temp);
                }
            }
            else
            {
                return;
            }
        }

        public void WipeLine(Coordinations a, Coordinations b)
        {
            if (a.X == b.X)
            {
                var length = Math.Abs(a.Y - b.Y);
                int y_start;
                if (a.Y < b.Y)
                {
                    y_start = a.Y;
                }
                else
                {
                    y_start = b.Y;
                }
                for (int i = 0; i < length; i++)
                {
                    var processed_cords = new Coordinations(a.X, y_start + i);
                    var processed_unit = editorCanva.GetUnit(processed_cords);
                    commandBuffer.Add(new WipeUnitEditorCommand(processed_unit));
                }
            }
            else if (a.Y == b.Y)
            {
                var length = Math.Abs(a.X - b.X);
                int x_start;
                if (a.X < b.X)
                {
                    x_start = a.X;
                }
                else
                {
                    x_start = b.X;
                }
                for (int i = 0; i < length; i++)
                {
                    var processed_cords = new Coordinations(x_start + i, a.Y);
                    var processed_unit = editorCanva.GetUnit(processed_cords);
                    commandBuffer.Add(new WipeUnitEditorCommand(processed_unit));
                }
            }
            else
            {
                return;
            }
        }

        public void Execute()
        {
            foreach (var command in commandBuffer)
            {
                command.Execute();
            }

            commandBuffer.Clear();
        }
        public String GetCanvaRepresentation()
        {
            return editorCanva.GetCanvaRepresentation();
        }
    }
}
