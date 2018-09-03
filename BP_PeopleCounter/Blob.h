#ifndef MY_BLOB
#define MY_BLOB
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace cv;
using namespace std;

class Blob {
public:
	vector<Point> currentContour;
	Rect currentBoundingRect;
	vector<Point> centerPositions;
	double dblCurrentDiagonalSize;
	double dblCurrentAspectRatio;
	bool blnCurrentMatchFoundOrNewBlob;
	bool blnStillBeingTracked;
	int intNumOfConsecutiveFramesWithoutAMatch;
	Point predictedNextPosition;

	Blob(vector<Point> _contour);
	void predictNextPosition(void);
};

#endif