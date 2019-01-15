#ifndef __DMA_H
#define	__DMA_H	   
#include "system.h"



//��������λ������
#define DMA_SIZE_8BIT	0
#define DMA_SIZE_16BIT	1
#define DMA_SIZE_32BIT	2



void DMA_MemoryToPeripheralConfig(DMA_Channel_TypeDef *DMA_CHx,u32 ParADD,u8 SIZE_xbit);			//�洢���������DMA��������
void DMA_StartChannel(DMA_Channel_TypeDef *DMA_CHx,u32 MemoryADD, u16 DataSize);					//����DMA����
void DMA_WaitComplete(DMA_Channel_TypeDef *DMA_CHx);												//�ȴ��������
void DMA_PeripheralToMemory(DMA_Channel_TypeDef *DMA_CHx,u32 MemoryADD,u32 ParADD,u8 SIZE_xbit,u16 DataSize);//���赽�洢����DMA��������
void DMA_SetPeripheralToMemoryDataSize(DMA_Channel_TypeDef *DMA_CHx,u32 MemoryADD, u16 DataSize);	//���赽�洢����DMA��������������
u16 DMA_GetCompleteResidualCnt(DMA_Channel_TypeDef *DMA_CHx);										//��ȡ�����ʣ��������
void DMA_SetPeripheralToMemoryDataSize(DMA_Channel_TypeDef *DMA_CHx,u32 MemoryADD, u16 DataSize);	//���赽�洢����DMA��������������   


#endif





























