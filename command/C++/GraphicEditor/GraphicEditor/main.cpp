#include <iostream>
#include "EditorMenu.h"

int main() {
    EditorMenu editor;

    std::cout << editor.GetCanvasRepresentation() << std::endl;

    editor.FillLine(Coordinates(0, 0), Coordinates(5, 0));
    editor.Execute();

    std::cout << editor.GetCanvasRepresentation() << std::endl;

    editor.WipeLine(Coordinates(0, 0), Coordinates(5, 0));
    editor.Execute();

    std::cout << editor.GetCanvasRepresentation() << std::endl;

    editor.FillLine(Coordinates(1, 3), Coordinates(1, 5));
    editor.Execute();

    std::cout << editor.GetCanvasRepresentation() << std::endl;

    return 0;
}