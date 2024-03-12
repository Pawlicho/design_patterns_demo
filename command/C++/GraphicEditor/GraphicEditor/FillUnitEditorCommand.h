#pragma once

#include "EditorCommand.h"
#include "CanvaUnit.h"

class FillUnitEditorCommand : public EditorCommand 
{
private:
    CanvaUnit& receiverUnit;

public:
    FillUnitEditorCommand(CanvaUnit& receiverUnit_) : receiverUnit(receiverUnit_) 
    {}

    void Execute() override 
    {
        receiverUnit.Fill();
    }
};