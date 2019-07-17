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
	// std::cout << "Frame available" << std::endl;
	const Frame frame = controller.frame();
	std::cout << "Frame id: " << frame.id()
		<< ", timestamp: " << frame.timestamp()
		<< ", hands: " << frame.hands().count()
		<< ", fingers: " << frame.fingers().count() << std::endl;
	Leap::FingerList fingers = frame.hands()[0].fingers();
	//for (Leap::FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); fl++) {
	Leap::FingerList::const_iterator fl = fingers.begin();
	Leap::Bone bone;
	Leap::Bone::Type boneType;
	boneType = static_cast<Leap::Bone::Type>(1);
	bone = (*fl).bone(boneType);
	std::cout << "Finger index: " << (*fl).type() << " " << bone << std::endl;
	Vector currentPosition = bone.center();
	std::cout << currentPosition << std::endl;
	Sleep(50);
	//}
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
	//autd.add_unit(ids[4], AUTUnitPosition(AUTVector3f(0, 0, 0), AUTVector3f(0, 0, 0)), 0);
	/*autd.add_unit(ids[5], AUTUnitPosition(AUTVector3f(0, 0, 0), AUTVector3f(0, 0, 0)), 0);
	autd.add_unit(ids[6], AUTUnitPosition(AUTVector3f(0, 0, 0), AUTVector3f(0, 0, 0)), 0);
	autd.add_unit(ids[7], AUTUnitPosition(AUTVector3f(0, 0, 0), AUTVector3f(0, 0, 0)), 0); */
	autd.open();
	autd.max_amp = 255;
	autd.all_zero();
	autd.consider_reflection(false);
	AUTVector3f pos = AUTVector3f(0, 0, 0);
	//vector<AUTVector3f> points;
	/*for (
	
	int i = 0; i < 2; i++) {
		points.emplace_back(i*30, i*30, i*30);
	}*/
	/*points.emplace_back(0, 0, 0);
	points.emplace_back(0, 50, 0);
	points.emplace_back(0, -50, 0);*/
	vector<int> amps(2, 255);
	//pos = AUTVector3f(0,0,0);
	float maxY = -55;
	float numY = 200;
	float dY =  maxY / (numY - 1);
	//autd.focal_point(AUTD_ID_GLOBAL, pos - AUTVector3f(0, 0, maxZ), 255, false);
	//getchar();
	//for (int i = 0; i < numZ; i++) {
	//  AUTVector3f offset = AUTVector3f(0, 0, maxZ - dZ * i);
	//  autd.focal_point(AUTD_ID_GLOBAL, pos - offset, 255, false);
	//  Sleep(10);
	//}
	//getchar();
	/*float radius = 30;
	float numTheta = 100;
	float dTheta = 2 * M_PI / numTheta;
	autd.focal_point(ids[0], pos + AUTVector3f(radius, 0, 0), 255, false);
	autd.focal_point(ids[1], pos + AUTVector3f(radius, 0, 0), 255, false);
	autd.focal_point(ids[2], pos + AUTVector3f(radius, 0, 0), 255, false);
	autd.focal_point(ids[3], pos + AUTVector3f(radius, 0, 0), 255, false);
	getchar();
	while (1) {
	for (int i = 0; i < numTheta; i++) {
	AUTVector3f offset = AUTVector3f(radius * cos(i * dTheta), 0, radius * sin(i * dTheta));
	autd.focal_point(ids[0], pos + offset, 255, false);
	autd.focal_point(ids[1], pos + offset, 255, false);
	autd.focal_point(ids[2], pos + offset, 255, false);
	autd.focal_point(ids[3], pos + offset, 255, false);
	Sleep(5);
	}
	if (_kbhit()) {
	char buf = _getch();
	if (buf == 'q') {
	break;
	}
	}
	}*/
	/*float maxX = 30;
	float num = 50;
	float dX = 2 * maxX / (num - 1);
	//float dZ = 2 * maxX / (num - 1);
	autd.focal_point(ids[0], pos + AUTVector3f(-maxX, 0, -maxX), 255, false);
	autd.focal_point(ids[1], pos + AUTVector3f(-maxX, 0, -maxX), 255, false);
	autd.focal_point(ids[2], pos + AUTVector3f(-maxX, 0, -maxX), 255, false);
	autd.focal_point(ids[3], pos + AUTVector3f(-maxX, 0, -maxX), 255, false);
	//autd.focal_point(ids[4], pos + AUTVector3f(-maxX, 0, 0), 255, false);
	//autd.focal_point(ids[5], pos - AUTVector3f(-maxX, 0, 0), 255, false);
	autd.focal_point(ids[6], pos + AUTVector3f(-maxX, 0, 0), 255, false);
	autd.focal_point(ids[7], pos - AUTVector3f(-maxX, 0, 0), 255, false); */
	//getchar();
	/* while (1) {
	Leap::FingerList fingers = frame.hands()[0].fingers();
	for (Leap::FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); fl++) {
	Leap::Bone bone;
	Leap::Bone::Type boneType;
	boneType = static_cast<Leap::Bone::Type>(1);
	bone = (*fl).bone(boneType);
	// std::cout << "Finger index: " << (*fl).type() << " " << bone << std::endl;
	Vector currentPosition = bone.TipPosition;
	std::cout << currentPosition << std::endl;
	Sleep(50);
	}
	} */
	/* while (1) {
	for (int i = 0; i < num; i++) {
	AUTVector3f offset = AUTVector3f(-maxX + dX * i,0,0);
	autd.focal_point(ids[0], pos + offset, 255, false);
	autd.focal_point(ids[1], pos + offset, 255, false);
	autd.focal_point(ids[2], pos + offset, 255, false);
	autd.focal_point(ids[3], pos + offset, 255, false);
	//autd.focal_point(ids[4], pos + offset, 255, false);
	//Sleep(5);
	}
	for (int i = 0; i < num; i++) {
	AUTVector3f offset = AUTVector3f(maxX - dX * i,0, 0);
	autd.focal_point(ids[0], pos + offset, 255, false);
	autd.focal_point(ids[1], pos + offset, 255, false);
	autd.focal_point(ids[2], pos + offset, 255, false);
	autd.focal_point(ids[3], pos + offset, 255, false);
	//autd.focal_point(ids[4], pos + offset, 255, false);
	//Sleep(5);
	}
	if (_kbhit()) {
	char buf = _getch();
	if (buf == 'q') {
	break;
	}
	}
	} */
	//////////////////////////////////////////////////////
	//////////////////////////////////////////////////////
	//SampleListener listener;
	Controller controller;
	int64_t previd = -1;
	//controller.addListener(listener);
	double x, y, z, x0, y0, z0;
	x = 0;
	y = 0;
	z = 0;
	x0 = 0;
	y0 = 0;
	z0 = 0;
	/*AUTVector3f pos0 = AUTVector3f(0, 0, 50000);
	AUTVector3f pos1 = AUTVector3f(50000, 0, 0);
	AUTVector3f pos2 = AUTVector3f(0, 0, -50000);
	AUTVector3f pos3 = AUTVector3f(-50000, 0, 0);*/
	////////////////////////////////////////////////	/////
	//////////////////////////////////////////////////////
	//while (1) {
		/*for (int i = 0; i < numZ; i++) {
		AUTVector3f offset = AUTVector3f(-maxZ + dZ * i, 0, 0);
		autd.focal_point(ids[0], pos + offset, 255, false);
		autd.focal_point(ids[1], pos + offset, 255, false);
		autd.focal_point(ids[2], pos + offset, 255, false);
		autd.focal_point(ids[3], pos + offset, 255, false);
		//autd.focal_point(ids[4], pos + offset, 255, false);
		//Sleep(5);
		}
		for (int i = numZ-1; i > -1; i--) {
		AUTVector3f offset = AUTVector3f(-maxZ + dZ * i, 0, 0);
		autd.focal_point(ids[0], pos + offset, 255, false);
		autd.focal_point(ids[1], pos + offset, 255, false);
		autd.focal_point(ids[2], pos + offset, 255, false);
		autd.focal_point(ids[3], pos + offset, 255, false);
		//autd.focal_point(ids[4], pos + offset, 255, false);
		//Sleep(5);
		}*/
		//autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
		/*
		if (timer == 0) {
		points.emplace_back(-50, 0, 0);
		}
		else if (timer == 1000) {
		points.emplace_back(-50,50,50);
		}
		else if (timer == 2000) {
		points.emplace_back(-50,-50,-50);
		timer = 0;
		}
		else if (timer == 600) {
		points.emplace_back(-50, -50, 50);
		timer = 0;
		}
		if (points[0].x > 500) {
		points.erase(points.begin());
		}
		for (int i = 0; i < points.size(); i++) {
		points[i].x = points[i].x + 0.5;
		}
		*/
		/*autd.multi_focal_point(ids[1], points, 255, false);
		autd.multi_focal_point(ids[3], points, 255, false);
		autd.multi_focal_point(ids[0], points, 255, false);
		autd.multi_focal_point(ids[2], points, 255, false);*/
		//timer++;
		//Sleep(5);
		/*if (_kbhit()) {
			char buf = _getch();
			if (buf == 'q') break;
			else if (buf == 'd') {
				pos = AUTVector3f(0, 0, 10);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, 0, 20);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, 0, 30);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
				autd.focal_point(ids[2], offset, 255, false);
				autd.focal_point(ids[3], offset, 255, false);
				*/
				//AUTVector3f dist = AUTVector3f(0, 0, 500);
				//autd.focal_point(ids[4], dist, 255, false);
				//Sleep(1);
				//autd.all_zero(AUTD_ID_GLOBAL);
				//Sleep(1000);
			//}
			/*else if (buf == 's') {
				pos = AUTVector3f(0, 7, 7);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, 14, 14);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, 21, 21);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
				autd.focal_point(ids[2], offset, 255, false);
				autd.focal_point(ids[3], offset, 255, false);
				Sleep(1);
				autd.all_zero(AUTD_ID_GLOBAL);
				Sleep(1000);
			}
			else if (buf == 'f') {
				pos = AUTVector3f(0, -7, 7);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, -14, 14);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, -21, 21);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
				autd.focal_point(ids[2], offset, 255, false);
				autd.focal_point(ids[3], offset, 255, false);
				Sleep(1);
				autd.all_zero(AUTD_ID_GLOBAL);
				Sleep(1000);
			}
			else if (buf == 'e') {
				pos = AUTVector3f(-7, 0, 7);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(-14, 0, 14);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(-21, 0, 21);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
				autd.focal_point(ids[2], offset, 255, false);
				autd.focal_point(ids[3], offset, 255, false);
				Sleep(1);
				autd.all_zero(AUTD_ID_GLOBAL);
				Sleep(1000);
			}
			else if (buf == 'j') {
				pos = AUTVector3f(0, 0, 0);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				autd.focal_point(ids[1], pos, 255, false);
				autd.focal_point(ids[3], pos, 255, false);
				autd.focal_point(ids[0], pos, 255, false);
				autd.focal_point(ids[2], pos, 255, false);
				Sleep(1);
				break;
			}
			else if (buf == 'k') {
				pos = AUTVector3f(0, 0, 40);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				//autd.focal_point(ids[1], pos, 255, false);
				//autd.focal_point(ids[3], pos, 255, false);
				//autd.focal_point(ids[0], pos, 255, false);
				//autd.focal_point(ids[2], pos, 255, false);
				//Sleep(1);
				//break;
			}
			else if (buf == 'r') {
				pos = pos - AUTVector3f(0, 0, 5);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				//autd.focal_point(ids[1], pos, 255, false);
				//autd.focal_point(ids[3], pos, 255, false);
				//autd.focal_point(ids[0], pos, 255, false);
				//autd.focal_point(ids[2], pos, 255, false);
				//Sleep(1);
				//break;
			}
			else if (buf == 'l') {
				pos = pos + AUTVector3f(0, 0, 5);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				//autd.focal_point(ids[1], pos, 255, false);
				//autd.focal_point(ids[3], pos, 255, false);
				//autd.focal_point(ids[0], pos, 255, false);
				//autd.focal_point(ids[2], pos, 255, false);
				//Sleep(1);
				//break;
			}
		}
	}*/
int state = 0;

	while (1) {
		//vector<AUTVector3f> points;
		/*for (int i = 0; i < 4; i++) {
			points.emplace_back(i, i, i);
		}*/
		/*points.emplace_back(x,y,z);
		points.emplace_back(x+20, y + 20, z + 20);
		points.emplace_back(x - 20, y - 20, z - 20)*/
		//autd.multi_focal_point(AUTD_ID_GLOBAL, points, 255, false);
		//pos = AUTVector3f((x - x0) / 5, (y - y0) / 5, (z - z0) / 5);
		// autd.focal_point(ids[0], pos, 255, false);
		//autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);

		//Sleep(5);
		if (_kbhit()) {
			char buf = _getch();
			if (buf == 'q') {
				break;
			}
			else if (buf == 'd') {
				pos = AUTVector3f(0, 0, 5);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, 0, 10);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				pos = AUTVector3f(0, 0, 15);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
				autd.focal_point(ids[2], offset, 255, false);
				autd.focal_point(ids[3], offset, 255, false);
				
					//AUTVector3f dist = AUTVector3f(0, 0, 500);
					//autd.focal_point(ids[4], dist, 255, false);
					//Sleep(1);
					//autd.all_zero(AUTD_ID_GLOBAL);
					//Sleep(1000);
				}
				/*else if (buf == 's') {
					pos = AUTVector3f(0, 7, 7);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					pos = AUTVector3f(0, 14, 14);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					pos = AUTVector3f(0, 21, 21);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
					autd.focal_point(ids[2], offset, 255, false);
					autd.focal_point(ids[3], offset, 255, false);
					Sleep(1);
					autd.all_zero(AUTD_ID_GLOBAL);
					Sleep(1000);
				}*/
				else if (buf == 'f') {
					pos = AUTVector3f(0, -7, 7);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					pos = AUTVector3f(0, -14, 14);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					pos = AUTVector3f(0, -21, 21);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
					autd.focal_point(ids[2], offset, 255, false);
					autd.focal_point(ids[3], offset, 255, false);
					Sleep(1);
					autd.all_zero(AUTD_ID_GLOBAL);
					Sleep(1000);
				}
				else if (buf == 'e') {
					pos = AUTVector3f(-7, 0, 7);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					pos = AUTVector3f(-14, 0, 14);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					pos = AUTVector3f(-21, 0, 21);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					AUTVector3f offset = AUTVector3f(10000, 10000, 10000);
					autd.focal_point(ids[2], offset, 255, false);
					autd.focal_point(ids[3], offset, 255, false);
					Sleep(1);
					autd.all_zero(AUTD_ID_GLOBAL);
					Sleep(1000);
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
				else if (buf == 'k') {
					pos = AUTVector3f(0, 0, 20);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					//autd.focal_point(ids[1], pos, 255, false);
					//autd.focal_point(ids[3], pos, 255, false);
					//autd.focal_point(ids[0], pos, 255, false);
					//autd.focal_point(ids[2], pos, 255, false);
					//Sleep(1);
					//break;
				}
				else if (buf == 'r') {
					pos = pos - AUTVector3f(0, 0, 5);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					//autd.focal_point(ids[1], pos, 255, false);
					//autd.focal_point(ids[3], pos, 255, false);
					//autd.focal_point(ids[0], pos, 255, false);
					//autd.focal_point(ids[2], pos, 255, false);
					//Sleep(1);
					//break;
				}
				else if (buf == 'l') {
					pos = pos + AUTVector3f(0, 0, 5);
					autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
					//autd.focal_point(ids[1], pos, 255, false);
					//autd.focal_point(ids[3], pos, 255, false);
					//autd.focal_point(ids[0], pos, 255, false);
					//autd.focal_point(ids[2], pos, 255, false);
					//Sleep(1);
					//break;
				}
				else if (buf == 'u') {
				pos = pos + AUTVector3f(0, 5, 0);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				//autd.focal_point(ids[1], pos, 255, false);
				//autd.focal_point(ids[3], pos, 255, false);
				//autd.focal_point(ids[0], pos, 255, false);
				//autd.focal_point(ids[2], pos, 255, false);
				//Sleep(1);
				//break;
				}
				else if (buf == 'n') {
				pos = pos - AUTVector3f(0, 5, 0);
				autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
				//autd.focal_point(ids[1], pos, 255, false);
				//autd.focal_point(ids[3], pos, 255, false);
				//autd.focal_point(ids[0], pos, 255, false);
				//autd.focal_point(ids[2], pos, 255, false);
				//Sleep(1);
				//break;
				}
				else if (buf == 's') {
				//for (int i = numY - 1; i > -1; i--) {
					//AUTVector3f offset = AUTVector3f(0, maxY - dY * i, 0);
					//autd.focal_point(AUTD_ID_GLOBAL, pos + offset, 255, false);
					/*autd.focal_point(ids[0], pos + offset, 255, false);
				autd.focal_point(ids[1], pos + offset, 255, false);
				autd.focal_point(ids[2], pos + offset, 255, false);
				autd.focal_point(ids[3], pos + offset, 255, false);*/
				//autd.focal_point(ids[4], pos + offset, 255, false);
					//Sleep(5);
				//}
				for (int i = 0; i < numY; i++) {
					AUTVector3f offset = AUTVector3f(0, -maxY + dY * i, 0);
					autd.focal_point(AUTD_ID_GLOBAL, pos - offset, 255, false);
					/*autd.focal_point(ids[0], pos + offset, 255, false);
					autd.focal_point(ids[1], pos + offset,  255, false);
					autd.focal_point(ids[2], pos + offset, 255, false);
					autd.focal_point(ids[3], pos + offset, 255, false);
					//autd.focal_point(ids[4], pos + offset, 255, false);*/
					//Sleep(1);
					if (i == 0) state = 1;
				}
			}
		}
		if (state == 1) autd.focal_point(AUTD_ID_GLOBAL, pos, 255, false);
		Sleep(5);
		
		
		

		
		/*autd.focal_point(ids[0], pos0, 255, false);
		autd.focal_point(ids[1], pos1, 255, false);
		autd.focal_point(ids[2], pos2, 255, false);
		autd.focal_point(ids[3], pos3, 255, false);*/
		/*auto frame = controller.frame();
		if (previd == frame.id()) {
			continue;
		}
		previd = frame.id();
		//const Frame frame = controller.frame();
		std::cout << "Frame id: " << frame.id()
			<< ", timestamp: " << frame.timestamp()
			<< ", hands: " << frame.hands().count()
			<< ", fingers: " << frame.fingers().count() << std::endl;
		Leap::FingerList fingers = frame.hands()[0].fingers();
		//for (Leap::FingerList::const_iterator fl = fingers.begin(); fl != fingers.end(); fl++) {
		Leap::FingerList::const_iterator fl = fingers.begin();
		Leap::Bone bone;
		Leap::Bone::Type boneType;
		boneType = static_cast<Leap::Bone::Type>(1);
		bone = (*fl).bone(boneType);
		std::cout << "Finger index: " << (*fl).type() << " " << bone << std::endl;
		Vector currentPosition = bone.center();
		z = currentPosition.x;
		x = currentPosition.y;
		y = currentPosition.z;
		std::cout << x << "  " << y << "  " << z << std::endl;

		//autd.multi_focal_point(AUTD_ID_GLOBAL, points, 255, false);
		//autd.vertices(AUTD_ID_GLOBAL, points, amps);
		//Sleep(5);
		//autd.focal_point(ids[0], pos, 0, false);
		//autd.focal_point(AUTD_ID_GLOBAL, pos, 0, false);
		//Sleep(10);
		if (_kbhit()) {
			char buf = _getch();
			if (buf == 'q') break;
			if (buf == 'o') {
				z0 = currentPosition.x;
				x0 = currentPosition.y;
				y0 = currentPosition.z;
			}
		}*/
	}
	autd.all_zero(AUTD_ID_GLOBAL);
	Sleep(1000);
	autd.close();
	return 0;
}