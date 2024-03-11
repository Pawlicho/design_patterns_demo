using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GraphicEditor
{
    internal class Canva
    {
        private uint width;
        private uint height;

        private List<List<CanvaUnit>> space;

        public Canva(uint width_, uint height_)
        {
            width = width_;
            height = height_;

            space = new List<List<CanvaUnit>>();

            for (int i = 0; i < height; i++)
            {
                List<CanvaUnit> row = new List<CanvaUnit>();
                for (int j = 0; j < width; j++)
                    row.Add(new CanvaUnit());

                space.Add(row);
            }
        }

        public CanvaUnit GetUnit(Coordinations coord) 
        {
            return space[coord.Y][coord.X];
        }

        public String GetCanvaRepresentation()
        {
            var retVal = new String("");
            foreach (var row in space) 
            {
                foreach (var unit in row)
                {
                    if (unit.IsFilled)
                    {
                        retVal += "X";
                    }
                    else
                    {
                        retVal += " ";
                    }
                }
                retVal += "\n";
            }
            return retVal;
        }
    }
}
