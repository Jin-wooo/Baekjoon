#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

#define MAX_BOARD_SIZE 8

using namespace std;

struct CoordDist
{
	int x;
	int y;
	int radius;
};

int main()
{
	CoordDist coordJoe;
	CoordDist coordBaek;
	int numLimit = 0;
	double numDistance = 0;
	int numRadiusAdd = 0;
	CoordDist coordWide, coordNarrow;

	cin >> numLimit;
	int *listQues = new int[numLimit];
	for (int iterLim = 0; iterLim < numLimit; iterLim++)
	{
		cin >> coordJoe.x >> coordJoe.y >> coordJoe.radius;
		cin >> coordBaek.x >> coordBaek.y >> coordBaek.radius;

		numDistance = sqrt(pow(coordBaek.x - coordJoe.x, 2) + pow(coordBaek.y - coordJoe.y, 2));
		numRadiusAdd = coordBaek.radius + coordJoe.radius;

		if (coordBaek.radius == coordJoe.radius) {
			if (numDistance == 0) {
				listQues[iterLim] = -1;
			}
			else if (numDistance < numRadiusAdd) {
				listQues[iterLim] = 2;
			}
			else if (numDistance == numRadiusAdd) {
				listQues[iterLim] = 1;
			}
			else if (numDistance > numRadiusAdd) {
				listQues[iterLim] = 0;
			}
		}
		else {
			// 큰 원과 작은 원을 구별해서 판단한다.
			if (coordBaek.radius > coordJoe.radius) {
				coordWide = coordBaek;
				coordNarrow = coordJoe;
			}
			else {
				coordWide = coordJoe;
				coordNarrow = coordBaek;
			}

			if (numDistance < numRadiusAdd) {
				if (numDistance + coordNarrow.radius < coordWide.radius) {
					listQues[iterLim] = 0;
				}
				else if (numDistance + coordNarrow.radius == coordWide.radius) {
					listQues[iterLim] = 1;
				}
				else {
					listQues[iterLim] = 2;
				}
			}
			else if (numDistance == numRadiusAdd) {
				listQues[iterLim] = 1;
			}
			else {
				listQues[iterLim] = 0;
			}
		}
	}

	for (int iterAns = 0; iterAns < numLimit; iterAns++)
	{
		cout << listQues[iterAns] << endl;
	}

	delete[] listQues;
	return 0;
}