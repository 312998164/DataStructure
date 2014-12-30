#include "type.h"

/***************************************
 * ������Ͳ��ã��޸�type.c��type.h�ļ�
 **************************************/

WORD LkNodeInput(LkNode *lkNode)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == lkNode)
	{
		return ILLEGAL;
	}

	printf("���������Ա��ţ�");
	scanf("%d",&(lkNode->data));

	return OK;
}

WORD LkNodeMemberInput(LkNode *lkNode)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == lkNode)
	{
		return ILLEGAL;
	}

	printf("���������Ա��ţ�");
	scanf("%d",&(lkNode->data));

	return OK;
}

WORD LkNodeDisplay(LkNode *lkNode)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == lkNode)
	{
		return ILLEGAL;
	}

	printf("data = %d\n",lkNode->data);

	return OK;
}

WORD LkNodeCpy(LkNode *targetLkNode, LkNode *sourceLkNode)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == targetLkNode || NULL == sourceLkNode)
	{
		return ILLEGAL;
	}

	targetLkNode->data = sourceLkNode->data;
	//����ָ��Ŀ�����next����ȥ��ѡ�񣬷�ֹ���������н�����ݽ�����Ͽ�

	return OK;
}

WORD LkNodeMemberEqual(LkNode *fristLkNode, LkNode *secondLkNode)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == fristLkNode || NULL == secondLkNode)
	{
		return ILLEGAL;
	}

	if (fristLkNode->data == secondLkNode->data)
	{
		return TRUE;
	}
	
	return FALSE;
}
