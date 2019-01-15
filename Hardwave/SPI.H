/*	SPI��������		*/
//20110625
//�޸�ʱ�� 20110625


#ifndef __SPI_H_
#define __SPI_H_
#include "system.h"


//SPI���ýṹ��
typedef struct
{
  u8	En16bit;	//ʹ��16bit��ʽ������Ϊ8bitģʽ
  u8	EnLSB;		//ʹ�ܵ�λ��ǰ�������λ��ǰ
  u8	EnCPOH;		//ʹ�ܿ���ʱ��Ϊ�ߵ�ƽ������Ϊ�͵�ƽ
  u8	EnCPHA;		//ʹ�����ݲ����ӵڶ������ؿ�ʼ
  u8	EnSSM;		//ʹ����������CS�ź�
  u8	EnRxOnly;	//��ֹ���,ֻ����,����Ϊȫ˫��ģʽ
  u8	EnBIDI;		//ʹ�ܵ���˫��ģʽ
  u8	EnCRC;		//ʹ��CRCУ��
  u8	EnMSTR;		//ʹ�����豸ģʽ
  u8	EnTxINT;	//���������ж�
  u8	EnRxINT;	//���������ж�
  u8	EnErrorINT;	//���������ж�
  u8	EnSSOE;		//ʹ����ģʽ��SS���
  u8	EnTxDMA;	//ʹ�ܷ���DMA
  u8	EnRxDMA;	//ʹ�ܽ���DMA
} SPI_Config_Type;




//SPIͨ������
typedef enum
{
	SPI_CH1		=	0,	//SPI1
	SPI_CH2		=	1,	//SPI2
	SPI_CH3		=	2,	//SPI3
} SPI_CH_Type;




//SPIͨ������
typedef enum
{
	SPI_1_2  	=			0,   		//SPI ʱ��2��Ƶ,(ֻ������SPI1)
	SPI_1_4    	=			1,   		//SPI ʱ��4��Ƶ
	SPI_1_8   	=			2, 			//SPI ʱ��8��Ƶ
	SPI_1_16  	=			3, 			//SPI ʱ��16��Ƶ
	SPI_1_32   	=			4,   		//SPI ʱ��32��Ƶ
	SPI_1_64  	=			5,   		//SPI ʱ��64��Ƶ
	SPI_1_128  	=			6,  		//SPI ʱ��128��Ƶ
	SPI_1_256 	=			7,			//SPI ʱ��256��Ƶ
	SPI_1_512 	=			8,			//SPI ʱ��512��Ƶ,(ֻ������SPI2,3)
} SPI_SPEED_Type;





extern const SPI_Config_Type SPI_DEFAULT_01;	//����ģʽ1

extern const SPI_Config_Type SPI_DEFAULT_02;	//����ģʽ2

//���API
u8 SPIx_Init(SPI_CH_Type ch,const SPI_Config_Type *SPI_Config,SPI_SPEED_Type Speed);//SPI��ʼ������
u32 SPIx_SetSpeed(SPI_CH_Type ch,SPI_SPEED_Type Speed);							//SPI�ٶ�����
u8 SPIx_ReadWriteByte(SPI_CH_Type ch,u8 TxData);						//SPI ��дһ���ֽ�
u8 SPIx_Config(SPI_CH_Type ch,const SPI_Config_Type *SPI_Config);		//SPI����

bool SPIx_GetNewDataFlag(SPI_CH_Type ch);//��ȡSPI�����ݱ�־
bool SPIx_GetRxBuffFullFlag(SPI_CH_Type ch);//��ȡSPI���ջ���������־
u8 SPIx_GetNewData(SPI_CH_Type ch);//��ȡSPI������
void SPIx_SetRxBuff(SPI_CH_Type ch,u8 *RxBuff,u16 RxBuffSize);//����SPI���ջ�����
u32 SPIx_GetRxCnt(SPI_CH_Type ch);//��ȡSPI�������ݼ�����
void SPIx_ClearRxCnt(SPI_CH_Type ch);//���SPI�������ݼ�����
	

//spi����
void SPIx_PowerDown(SPI_CH_Type ch);
//spi�ϵ�
void SPIx_PowerUp(SPI_CH_Type ch);
#endif