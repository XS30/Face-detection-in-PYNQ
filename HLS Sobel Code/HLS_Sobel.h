#ifndef __TEST_HEAD_H__
#define __TEST_HEAD_H__

#include <hls_video.h>
#include <ap_axi_sdata.h>

#define MATRIX_DIM 3
#define IMG_WIDTH 1024
#define IMG_HEIGHT 768
#define INPUT_IMAGE "image.bmp"
#define OUTPUT_IMAGE "outimage.bmp"


//定义数据流中的数据
typedef ap_axiu<32,1,1,1> 	uint_side_channel;
typedef ap_axis<32,1,1,1> 	int_side_channel;
//定义AXI—Stream数据流
typedef hls::stream<uint_side_channel> 							AXI_STREAM;
//定义char类型的卷积窗口
typedef hls::Window<MATRIX_DIM,MATRIX_DIM,char> 				CHAR_WINDOW;
//定义short类型的卷积窗口
typedef hls::Window<MATRIX_DIM,MATRIX_DIM,short> 				SHORT_WINDOW;
//定义LineBuffer用于延时
typedef hls::LineBuffer<MATRIX_DIM,IMG_WIDTH,unsigned char> 	BUFFER;
short sumWindow(SHORT_WINDOW *window);//求卷积和
//顶层函数
void image_process(AXI_STREAM & inStream,AXI_STREAM & outStream, char kernel[MATRIX_DIM*MATRIX_DIM]);

#endif
