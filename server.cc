#include "MatCom.hpp"

int main(int argc, char ** argv)
{
	MatCom mc("server");
	mc.init(12345, "192.168.0.2");
	VideoCapture cap(0);
	Mat frame;
	namedWindow("sent");
	for (;;)
	{
		cap >> frame;
		mc.sendMat(frame);
		imshow("sent", frame);
		waitKey(30);
	}
	return 0;
}
