#include <stdio.h>
#include <hls_opencv.h>
#include <opencv2/opencv.hpp>
#include "image_process.h"
using namespace cv;

//sobel dim

char dim[MATRIX_DIM * MATRIX_DIM]=
{
	-1, -2, -1,
	 0,  0,  0,
	 1,  2,  1,
};


int main()
{
	IplImage * SrcImage;//输入的图像
	IplImage * DstImage;//输出的图像
	SrcImage = cvLoadImage(INPUT_IMAGE,-1);//导入图像

	DstImage = cvCreateImage(cvGetSize(SrcImage),SrcImage->depth, SrcImage->nChannels);
	//AXI-Stream数据流
	AXI_STREAM inStream;
	AXI_STREAM outStream;
	IplImage2AXIvideo(SrcImage,inStream);
	image_process(inStream,outStream,dim);	//可综合的函数

	AXIvideo2IplImage(outStream,DstImage);	//保存输出结果
	cvSaveImage(OUTPUT_IMAGE,DstImage);

	cvShowImage(OUTPUT_IMAGE, DstImage);
	cvWaitKey(0);
	//释放图片
	cvReleaseImage(&SrcImage);
	cvReleaseImage(&DstImage);
	return 0;


}

