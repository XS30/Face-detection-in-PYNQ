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
	IplImage * SrcImage;//�����ͼ��
	IplImage * DstImage;//�����ͼ��
	SrcImage = cvLoadImage(INPUT_IMAGE,-1);//����ͼ��

	DstImage = cvCreateImage(cvGetSize(SrcImage),SrcImage->depth, SrcImage->nChannels);
	//AXI-Stream������
	AXI_STREAM inStream;
	AXI_STREAM outStream;
	IplImage2AXIvideo(SrcImage,inStream);
	image_process(inStream,outStream,dim);	//���ۺϵĺ���

	AXIvideo2IplImage(outStream,DstImage);	//����������
	cvSaveImage(OUTPUT_IMAGE,DstImage);

	cvShowImage(OUTPUT_IMAGE, DstImage);
	cvWaitKey(0);
	//�ͷ�ͼƬ
	cvReleaseImage(&SrcImage);
	cvReleaseImage(&DstImage);
	return 0;


}

