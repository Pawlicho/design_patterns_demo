namespace GraphicEditor
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var editor = new EditorMenu();

            Console.WriteLine(editor.GetCanvaRepresentation());

            editor.FillLine(new Coordinations(0,0), new Coordinations(5,0));
            editor.Execute();

            Console.WriteLine(editor.GetCanvaRepresentation());

            editor.WipeLine(new Coordinations(0, 0), new Coordinations(5, 0));
            editor.Execute();

            Console.WriteLine(editor.GetCanvaRepresentation());

            editor.FillLine(new Coordinations(1, 3), new Coordinations(1, 5));
            editor.Execute();

            Console.WriteLine(editor.GetCanvaRepresentation());
        }
    }
}