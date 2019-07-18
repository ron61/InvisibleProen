#include "FTAUTD.h"
#include "myHeader.h"
#include <stdio.h>
#include <conio.h>
#include <iostream>
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ja_JP.UTF-8");
    FTAUTD autd(AUTDConnectorTypeUM232HSinglePort);
    unsigned int ids[4] = { 5,4,12,14 };
    const float distance1 = 434.0;
    const float distance2 = 434.0;
    const float width = 182.0;
    const float height = 142.0;
    autd.add_unit(ids[0], AUTUnitPosition(AUTVector3f(-width / 2, -height / 2, -distance1 / 2), AUTVector3f(0, 0, 0)), 0);
    autd.add_unit(ids[1], AUTUnitPosition(AUTVector3f(-distance2 / 2, -height / 2, width / 2), AUTVector3f(0, M_PI / 2, 0)), 0);
    autd.add_unit(ids[2], AUTUnitPosition(AUTVector3f(width / 2, -height / 2, distance1 / 2), AUTVector3f(0, -M_PI, 0)), 0);
    autd.add_unit(ids[3], AUTUnitPosition(AUTVector3f(distance2 / 2, -height / 2, -width / 2), AUTVector3f(0, -M_PI / 2, 0)), 0);
    autd.open();
    autd.max_amp = 255;
    autd.all_zero();
    autd.consider_reflection(false);
    AUTVector3f pos = AUTVector3f(0, 0, 0);
    AUTVector3f pos2 = AUTVector3f(width / 2, height / 2, 100);
    vector<int> amps(2, 255);
    float maxY = -55;
    float numX = 200;
    float numY = 200;
    float dY = maxY / (numY - 1);
    float radius = 30;
    float numTheta = 1000;
    float dTheta = 2 * M_PI / numTheta;
    int state = 0;
    while (1) {
        if (state == 1) autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
        Sleep(5);
        if (_kbhit()) {
            char buf = _getch();
            if (buf == 'q') break;
            else if (buf == 's') {
                for (int i = 0; i < 10000; i++) {
                    pos.y = pos.y + 1;
                    autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
                    Sleep(1);
                    if (i > 130) {
                        Sleep(15000);
                        pos = AUTVector3f(0, 0, 0);
                        break;
                    }
                }
                Sleep(500);
            }
            else if (buf == 't') {
                autd.all_zero(AUTD_ID_GLOBAL);
                Sleep(1000);
            }
            else if (buf == 'f') {
                for (int i = 0; i < numY+60; i++) {
                    AUTVector3f offset = AUTVector3f(0, -maxY + dY * i, 0);
                    autd.focal_point(AUTD_ID_GLOBAL, pos - offset, 255, false);
                    Sleep(15);
                    if (i == 0) state = 1;
                }
                for (int i = numY+59; i >=numY-1; i--) {
                    AUTVector3f offset = AUTVector3f(0, -maxY + dY * i, 0);
                    autd.focal_point(AUTD_ID_GLOBAL, pos - offset, 255, false);
                    Sleep(38);
                    if (i == 0) state = 1;
                }
            }
            else if (buf == 'h') {
                autd.all_zero(AUTD_ID_GLOBAL);
                autd.focal_point(ids[0], pos, 255, false);
                Sleep(1000);
            }
            else if (buf == 'r') {
                for (int i = 0; i < numX; i++) {
                    AUTVector3f offset = AUTVector3f(radius / numX * i, 0, 0);
                    autd.focal_point(AUTD_ID_GLOBAL, pos + offset, 255, false);
                }
                for (int i = 0; i < numTheta; i++) {
                    AUTVector3f offset = AUTVector3f(radius * cos(i * dTheta), 0, radius * sin(i * dTheta));
                    autd.focal_point(AUTD_ID_GLOBAL, pos + offset, 255, false);
                    Sleep(5);
                }
                for (int i = numX - 1; i >= 0; i--) {
                    AUTVector3f offset = AUTVector3f(radius / numX * i, 0, 0);
                    autd.focal_point(AUTD_ID_GLOBAL, pos + offset, 255, false);
                }
                Sleep(4000);
            }
            else if (buf == 'j') {
                pos = AUTVector3f(0, 0, 0);
                autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
                /*autd.focal_point(ids[1], pos, 255, false);
                autd.focal_point(ids[3], pos, 255, false);
                autd.focal_point(ids[0], pos, 255, false);
                autd.focal_point(ids[2], pos, 255, false);*/
                //Sleep(1);
                //break;
            }
            else if (buf == 'a') {
                for (int i = 0; i < 10000; i++) {
                    pos.y = pos.y + 1;
                    autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
                    Sleep(1);
                    if (i > 130) {
                        Sleep(9000);
                        pos = AUTVector3f(0, 0, 0);
                        break;
                    }
                }
                Sleep(500);
            }
            else if (buf == 'b') {
                for (int i = 0; i < numY; i++) {
                    AUTVector3f offset = AUTVector3f(0, -maxY + dY * i, 0);
                    autd.focal_point(AUTD_ID_GLOBAL, pos - offset, 255, false);
                    Sleep(5);
                    if (i == 0) state = 1;
                }
            }
        }
    }
    autd.all_zero(AUTD_ID_GLOBAL);
    Sleep(1000);
    autd.close();
    return 0;
}