#pragma once


#include <vector>
#include <string>
#include <cmath>
#include "Canva.h"
#include "EditorCommand.h"
#include "FillUnitEditorCommand.h"
#include "WipeUnitEditorCommand.h"
#include "Coordinates.h"

class EditorMenu 
{
private:
    Canva editorCanva;
    std::vector<EditorCommand*> commandBuffer;

    static const int CANVAS_X_SIZE = 10;
    static const int CANVAS_Y_SIZE = 10;

public:
    EditorMenu() : editorCanva(CANVAS_X_SIZE, CANVAS_Y_SIZE), commandBuffer() 
    {}

    void FillLine(Coordinates a, Coordinates b) 
    {
        if (a.X == b.X) 
        {
            int length = std::abs(a.Y - b.Y);
            int y_start = (a.Y < b.Y) ? a.Y : b.Y;

            for (int i = 0; i < length; ++i) 
            {
                Coordinates processedCoords(a.X, y_start + i);
                CanvaUnit& processedUnit = editorCanva.GetUnit(processedCoords);
                commandBuffer.push_back(new FillUnitEditorCommand(processedUnit));
            }
        }
        else if (a.Y == b.Y) 
        {
            int length = std::abs(a.X - b.X);
            int x_start = (a.X < b.X) ? a.X : b.X;
            for (int i = 0; i < length; ++i) 
            {
                Coordinates processedCoords(x_start + i, a.Y);
                CanvaUnit& processedUnit = editorCanva.GetUnit(processedCoords);
                commandBuffer.push_back(new FillUnitEditorCommand(processedUnit));
            }
        }
    }

    void WipeLine(Coordinates a, Coordinates b) 
    {
        if (a.X == b.X) {
            int length = std::abs(a.Y - b.Y);
            int y_start = (a.Y < b.Y) ? a.Y : b.Y;

            for (int i = 0; i < length; ++i) 
            {
                Coordinates processedCoords(a.X, y_start + i);
                CanvaUnit& processedUnit = editorCanva.GetUnit(processedCoords);
                commandBuffer.push_back(new WipeUnitEditorCommand(processedUnit));
            }
        }
        else if (a.Y == b.Y) 
        {
            int length = std::abs(a.X - b.X);
            int x_start = (a.X < b.X) ? a.X : b.X;

            for (int i = 0; i < length; ++i) 
            {
                Coordinates processedCoords(x_start + i, a.Y);
                CanvaUnit& processedUnit = editorCanva.GetUnit(processedCoords);
                commandBuffer.push_back(new WipeUnitEditorCommand(processedUnit));
            }
        }
    }

    void Execute() {
        for (auto command : commandBuffer) 
        {
            command->Execute();
            delete command;
        }

        commandBuffer.clear();
    }

    std::string GetCanvasRepresentation() 
    {
        return editorCanva.GetCanvasRepresentation();
    }
};