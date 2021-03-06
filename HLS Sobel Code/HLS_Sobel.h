#ifndef __TEST_HEAD_H__
#define __TEST_HEAD_H__

#include <hls_video.h>
#include <ap_axi_sdata.h>

#define MATRIX_DIM 3
#define IMG_WIDTH 1024
#define IMG_HEIGHT 768
#define INPUT_IMAGE "image.bmp"
#define OUTPUT_IMAGE "outimage.bmp"


//�����������е�����
typedef ap_axiu<32,1,1,1> 	uint_side_channel;
typedef ap_axis<32,1,1,1> 	int_side_channel;
//����AXI��Stream������
typedef hls::stream<uint_side_channel> 							AXI_STREAM;
//����char���͵ľ������
typedef hls::Window<MATRIX_DIM,MATRIX_DIM,char> 				CHAR_WINDOW;
//����short���͵ľ������
typedef hls::Window<MATRIX_DIM,MATRIX_DIM,short> 				SHORT_WINDOW;
//����LineBuffer������ʱ
typedef hls::LineBuffer<MATRIX_DIM,IMG_WIDTH,unsigned char> 	BUFFER;
short sumWindow(SHORT_WINDOW *window);//������
//���㺯��
void image_process(AXI_STREAM & inStream,AXI_STREAM & outStream, char kernel[MATRIX_DIM*MATRIX_DIM]);

#endif
