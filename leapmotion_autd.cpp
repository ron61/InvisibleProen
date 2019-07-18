#include "FTAUTD.h"
#include "myHeader.h"
#include <stdio.h>
#include "C:\LeapDeveloperKit_2.3.1+31549_win\LeapSDK\include\Leap.h"
#include <conio.h>
#include <iostream>
using namespace Leap;
#pragma region
class SampleListener : public Listener {
public:
    virtual void onConnect(const Controller&);
    virtual void onFrame(const Controller&);
};
void SampleListener::onConnect(const Controller& controller) {
    std::cout << "Connected" << std::endl;
}
void SampleListener::onFrame(const Controller& controller) {
    const Frame frame = controller.frame();
    std::cout << "Frame id: " << frame.id()
        << ", timestamp: " << frame.timestamp()
        << ", hands: " << frame.hands().count()
        << ", fingers: " << frame.fingers().count() << std::endl;
    Leap::FingerList fingers = frame.hands()[0].fingers();
    Leap::FingerList::const_iterator fl = fingers.begin();
    Leap::Bone bone;
    Leap::Bone::Type boneType;
    boneType = static_cast<Leap::Bone::Type>(1);
    bone = (*fl).bone(boneType);
    std::cout << "Finger index: " << (*fl).type() << " " << bone << std::endl;
    Vector currentPosition = bone.center();
    std::cout << currentPosition << std::endl;
    Sleep(50);
}
#pragma endregion
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
    vector<int> amps(2, 255);
    Controller controller;
    int64_t previd = -1;
    double x, y, z, x0, y0, z0;
    x = 0;
    y = 0;
    z = 0;
    x0 = 0;
    y0 = 0;
    z0 = 0;
    while (1) {
        if (_kbhit()) {
            char buf = _getch();
            if (buf == 'q') {
                break;
            }
        }
        AUTVector3f pos = AUTVector3f((x - x0) / 10, (y - y0) / 10, (z - z0) / 10);
        autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
        Sleep(5);
        auto frame = controller.frame();
        if (previd == frame.id()) {
            continue;
        }
        previd = frame.id();
        std::cout << "Frame id: " << frame.id()
            << ", timestamp: " << frame.timestamp()
            << ", hands: " << frame.hands().count()
            << ", fingers: " << frame.fingers().count() << std::endl;
        Leap::FingerList fingers = frame.hands()[0].fingers();
        Leap::FingerList::const_iterator fl = fingers.begin();
        Leap::Bone bone;
        Leap::Bone::Type boneType;
        boneType = static_cast<Leap::Bone::Type>(1);
        bone = (*fl).bone(boneType);
        std::cout << "Finger index: " << (*fl).type() << " " << bone << std::endl;
        Vector currentPosition = bone.center();
        x = currentPosition.x;
        y = currentPosition.y;
        z = currentPosition.z;
        std::cout << x << "  " << y << "  " << z << std::endl;
        if (_kbhit()) {
            char buf = _getch();
            if (buf == 'q') break;
            if (buf == 'o') {
                x0 = currentPosition.x;
                y0 = currentPosition.y;
                z0 = currentPosition.z;
            }
        }
    }
    autd.all_zero(AUTD_ID_GLOBAL);
    Sleep(1000);
    autd.close();
    return 0;
}