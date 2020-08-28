#include "battleTransitionAnimation.h"


int TransitionFrame{ 0 };
int maxFrames2{ 60 };
bool activeTransition{ false };

int endRow2 = 1;

void battleTransitionAnimation(Console& g_Console, double dt, EGAMESTATES& g_eGameStates) {

    if (!activeTransition)
        return;

    if (TransitionFrame == maxFrames2) {
        TransitionFrame = 0;
        activeTransition = false;
        g_eGameStates = S_BATTLE;

    }

    COORD outputCoord;
    outputCoord.X = 0;
    outputCoord.Y = 0;
    
    

    COLOURS renderColour = COLOURS::WHITE;
    //frame increase
    for (int row = 0; row < endRow2; row++) {
        for (int col = 0; col < 140; col++) {
            g_Console.writeToBuffer(outputCoord, ' ', renderColour);
            outputCoord.X++;
        }

        outputCoord.Y++;
        outputCoord.X = 0;
        

        
    }

    endRow2++;
    TransitionFrame++;


}

void triggerBattleAnimation() {
    activeTransition = true;
}







