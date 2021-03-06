#include "image_process.h"

void image_process(AXI_STREAM & inStream,AXI_STREAM & outStream, char matrix[MATRIX_DIM*MATRIX_DIM])
{
	#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
	#pragma HLS INTERFACE s_axilite port=matrix bundle=CTRL
	#pragma HLS ARRAY_PARTITION COMPLETE variable=matrix
	#pragma HLS INTERFACE axis register both port=outStream
	#pragma HLS INTERFACE axis register both port=inStream

	BUFFER lineBuf;
	SHORT_WINDOW window;
	int pixConvolved = 0;

	int waitPixel = IMG_WIDTH + 1;
	int cntWait = 0;
	int sentPixel = 0;
	unsigned char pix;//灰度像素变量
	short valOut;
	uint_side_channel dataOutChannel;
	uint_side_channel currentChannel;
	short  pix_data_tmp=0;
	for(int i = 0; i < (IMG_HEIGHT); i++ )
	{
		for(int j = 0; j < (IMG_WIDTH); j++)
		{
			#pragma HLS PIPELINE//流水操作，提高效率
			currentChannel = inStream.read();
			//输入像素值取RGB三个分量
			unsigned char R = currentChannel.data & 0xFF;
			unsigned char G = (currentChannel.data >> 8) & 0xFF;
			unsigned char B = (currentChannel.data >> 16) & 0xFF;

			pix = (R*76 + G*150 + B*30) >> 8;//RGB数据计算灰度分量，YCBCR颜色空间的Y分量
			lineBuf.shift_pixels_up(j);
			lineBuf.insert_bottom_row(pix,j);
			//3x3矩阵运算
			for(int idxWinRow = 0; idxWinRow < MATRIX_DIM; idxWinRow++)
			{
				for(int idxWinCol=0; idxWinCol < MATRIX_DIM; idxWinCol++)
				{
					//计算矩阵的结果
					short val = (short)lineBuf.getval(idxWinRow, idxWinCol + pixConvolved);
					val = (short)matrix[(idxWinRow * MATRIX_DIM) + idxWinCol] * val;
					window.insert(val,idxWinRow,idxWinCol);
				}
			}

			//满足矩阵计算结果打包成数据流输出
			if((i >= MATRIX_DIM-1) && (j >= MATRIX_DIM -1))
			{
				pix_data_tmp=sumWindow(&window);
				if(pix_data_tmp<0)pix_data_tmp=0;
				else if(pix_data_tmp>255)pix_data_tmp=255;
				valOut = 255-pix_data_tmp;
				//if(valOut < 0 )valOut = 0;
				pixConvolved++;
				dataOutChannel.data = (valOut << 16) | (valOut << 8) | valOut;
				dataOutChannel.dest = currentChannel.dest;
				dataOutChannel.id = currentChannel.id;
				dataOutChannel.keep = currentChannel.keep;
				dataOutChannel.strb = currentChannel.strb;
				dataOutChannel.user = currentChannel.user;
				dataOutChannel.last = currentChannel.last;
				outStream.write(dataOutChannel);
				sentPixel++;
			}
			else
			{
				dataOutChannel.data = 0;
				dataOutChannel.dest = currentChannel.dest;
				dataOutChannel.id = currentChannel.id;
				dataOutChannel.keep = currentChannel.keep;
				dataOutChannel.strb = currentChannel.strb;
				dataOutChannel.user = currentChannel.user;
				dataOutChannel.last = currentChannel.last;
				outStream.write(dataOutChannel);
				sentPixel++;
			}
		}
		pixConvolved = 0;
	}
}

short sumWindow(SHORT_WINDOW *window)//求卷积和函数
{
	short sum=0;
	for(int idxRow = 0; idxRow < MATRIX_DIM; idxRow++)
	{
		for(int idxCol = 0;idxCol < MATRIX_DIM;idxCol++)
		{
			sum += (short)window->getval(idxRow, idxCol);
		}
	}
	return sum;
}


