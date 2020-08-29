#include "renderBlob.h"
#include <fstream>

int frametimer{ 0 };
int anothertimer{ 0 };




void renderblob(Console& g_Console, int x, int y, bool spinny)
{
    std::string blob = "Sprite_data/Blob_data/blob.txt";
    std::ifstream actualblob(blob, std::ios::in);
    if (!actualblob)
        return;

    COORD bloby;
    bloby.X = x;
    bloby.Y = y;

    COLOURS outputColour = COLOURS::WHITE;

    for (int row = 0; row < 16; row++) {
        std::string blob2;
        std::getline(actualblob, blob2);

        for (int col = 0; col < 32; col++) {
            switch (blob2[col]) {
            case '0': outputColour = COLOURS::BLACK;
                break;
            case '1': outputColour = COLOURS::YELLOW;
                break;
            }
            g_Console.writeToBuffer(bloby, ' ', outputColour);
            bloby.X++;
        }
        bloby.Y++;
        bloby.X = x;
    }


    for (int i = 1; i < 31; i++) {
        if (frametimer == i + 3) {
            renderEye(g_Console, x + 30 - i, y + 7);
            break;
        }
    }

    for (int i = 1; i < 31; i++) {
        if (frametimer == i + 11) {
            renderEye(g_Console, x + 30 - i, y + 7);
            break;
        }
    }

    for (int i = 1; i < 45; i++) {
        if (frametimer == i) {
            renderMouth(g_Console, x + 32 - i, y + 11, i, x);
            break;
        }
    }

    anothertimer++;
    if (spinny == true) {
        if (anothertimer == 1) {
            frametimer += 2;
            anothertimer = 0;
        }
    }
    else {
        if (anothertimer == 4) {
            frametimer++;
            anothertimer = 0;
        }
    }


    if (frametimer == 70)
        frametimer = 0;

}

void renderEye(Console& g_Console, int PosX, int PosY)
{
    COORD eye;
    eye.X = PosX;
    eye.Y = PosY;
    for (int row = 0; row < 2; row++) {
        for (int col = 0; col < 3; col++) {
            g_Console.writeToBuffer(eye, ' ', COLOURS::BLACK);
            eye.X++;
        }
        eye.Y++;
        eye.X = PosX;
    }
}

void renderMouth(Console& g_Console, int PosX, int PosY, int size, int start)
{
    COORD mouth;
    mouth.X = PosX;
    mouth.Y = PosY;
    for (int col = 0; col < size; col++) {
        if (size > 13)
            size = 13;
        if (mouth.X > start - 1) {
            g_Console.writeToBuffer(mouth, ' ', COLOURS::RED);
        }
        mouth.X++;
    }

    mouth.X = PosX + 1;
    mouth.Y++;

    if (size > 1) {
        for (int col = 0; col < size - 1; col++) {
            if (size > 12)
                size = 12;
            if (mouth.X > start - 1) {
                g_Console.writeToBuffer(mouth, ' ', COLOURS::RED);
            }
            mouth.X++;
        }
    }

    mouth.X = PosX + 3;
    mouth.Y++;

    if (size > 4) {
        for (int col = 0; col < size - 4; col++) {
            if (size > 11)
                size = 11;
            if (mouth.X > start) {
                g_Console.writeToBuffer(mouth, ' ', COLOURS::RED);
            }
            mouth.X++;
        }
    }
}
