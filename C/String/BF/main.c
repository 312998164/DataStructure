/*****************************************************************************
 * �ļ����ƣ� main.c
 * ����ժҪ�� BF�㷨����main�ļ�
 * ��ǰ�汾�� V1.0
 * ��    �ߣ�liao
 * ������ڣ� 2014��12��21��
 *
 * �޸ļ�¼1��// �޸���ʷ��¼�������޸����ڡ��޸��߼��޸�����
 * �޸����ڣ�
 * �� �� �ţ�
 * �� �� �ˣ�
 * �޸����ݣ�
 * �޸ļ�¼2����
 * @license ZPL (http://zpl.pub/v1)
 * Copyright (c) 2014  SmallLeg Team
 ******************************************************************************/

#include "BruteForce.h"

int main(int argc, const char * argv[])
{
	SString S = {13,'a','b','a','b','c','a','b','c','a','c','b','a','b'};
    SString T = {5,'a','b','c','a','c'};  
    int iPos;  
    iPos = BFindex( S,  T, 1);
	printf("%d\n",iPos);
	if(FALSE == iPos)
	{
		printf("û���ҵ���");
	}
	else
	{
		printf("�Ӵ�T������S�е�%dλ��֮���λ��",iPos);
	}

	return 0; 
}