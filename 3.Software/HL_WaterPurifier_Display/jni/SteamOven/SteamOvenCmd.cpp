
#include "../include.h"
#include "crc.h"
#include <arpa/inet.h>

#define STEAMOVEN_CMD_RECV_BUF_SIZE 64
#define STEAMOVEN_CMD_SEND_BUF_SIZE 64

SteamOvenCmd::~SteamOvenCmd()
{

	if (m_pRecvBuf != NULL) {
		delete[] m_pRecvBuf;
		m_pRecvBuf			= NULL;
	}

	if (m_pSendBuf != NULL) {
		delete[] m_pSendBuf;
		m_pSendBuf			= NULL;
	}

}


SteamOvenCmd::SteamOvenCmd()
{
	m_pRecvBuf			= new BYTE[STEAMOVEN_CMD_RECV_BUF_SIZE];
	m_pSendBuf			= new BYTE[STEAMOVEN_CMD_SEND_BUF_SIZE];
}


SteamOvenCmd * SteamOvenCmd::getInstance()
{
	static SteamOvenCmd SteamOvenCmd;

	return & SteamOvenCmd;
}


void SteamOvenCmd::RecvByte(BYTE in)
{


	if ((m_RecvCont == 0) && (in != 0x5a)) {
		return;
	}

	if ((m_RecvCont == 1) && (in != 0xa5)) {
		m_RecvCont			= 0;
		return;
	}


	m_pRecvBuf[m_RecvCont++] = in;


	if (m_RecvCont >= sizeof(STEAM_OVEN_ACK_T) + 2) {

		RecvCmd(m_pRecvBuf,m_RecvCont);

		memset(m_pRecvBuf, 0, STEAMOVEN_CMD_RECV_BUF_SIZE);
		m_RecvCont			= 0;
	}

}

void SteamOvenCmd::RecvCmd(BYTE * in,uint8 len)
{

	PSTEAM_OVEN_ACK_T pAck;
	uint16			crc16;

	SendCmd();

	crc16				= CRC16_Modbus(m_pRecvBuf, sizeof(STEAM_OVEN_ACK_T));

	pAck				= (PSTEAM_OVEN_ACK_T) (m_pRecvBuf + 2);

	//ILOGD("Recv Cmd crc:%04X,oldCrc:%04X\n", crc16, pAck->crc16);


	if (crc16 == htons(pAck->crc16)) {

		SteamOvenView::getInstance()->SetCmd(pAck);

	}
	else{
		
		LOGE("Recv Cmd crc:%04X,oldCrc:%04X, len:%d\n", crc16, pAck->crc16,len);

	}

}


void SteamOvenCmd::SendCmd()
{

	PSTEAM_OVEN_CMD_T pCmd;
	
		

	m_pSendBuf[0]		= 0x5a;
	m_pSendBuf[1]		= 0xa5;

	pCmd				= (PSTEAM_OVEN_CMD_T) (m_pSendBuf + 2);

	SteamOvenView::getInstance()->GetCmd(pCmd);
	
	pCmd->crc16 		= htons(CRC16_Modbus(m_pSendBuf, sizeof(STEAM_OVEN_CMD_T)));

	UartContext::getInstance()->send(m_pSendBuf, sizeof(STEAM_OVEN_CMD_T) + 2);

}


