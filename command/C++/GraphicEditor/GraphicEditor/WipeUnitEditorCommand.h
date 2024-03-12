#pragma once

#include "EditorCommand.h"
#include "CanvaUnit.h"

class WipeUnitEditorCommand : public EditorCommand 
{
private:
    CanvaUnit& receiverUnit;

public:
    WipeUnitEditorCommand(CanvaUnit& receiverUnit_) : receiverUnit(receiverUnit_) 
    {}

    void Execute() override 
    {
        receiverUnit.Wipe();
    }
};