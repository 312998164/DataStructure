#include "cyclelklist.h"

/**************************************************
* ��������: cycleLkListInit
* ��������: ��ʼ��ѭ��������
* �������: ָ��ѭ���������ָ���ָ��
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ�   ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListInit(CycleLkList **cycleLkList)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	(*cycleLkList)->head = NULL;
	(*cycleLkList)->current = NULL;
	(*cycleLkList)->trail = NULL;
	(*cycleLkList)->length = 0;

	return OK;
}

/**************************************************
* ��������: cycleLkListClear
* ��������: ���ѭ��������
* �������: ָ��ѭ���������ָ��
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ�   ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListClear(CycleLkList *cycleLkList)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	cycleLkList->current = cycleLkList->head;
	for (; cycleLkList->current->next != cycleLkList->head;)
	{
		cycleLkList->head = cycleLkList->current->next;
		cycleLkList->trail->next = cycleLkList->head;

		cycleLkList->current->next = NULL;
		free(cycleLkList->current);
		cycleLkList->length -= 1;

		cycleLkList->current = cycleLkList->head;
	}

	cycleLkList->current->next = NULL;
	free(cycleLkList->current);
	cycleLkList->length -= 1;

	cycleLkListInit(&cycleLkList);

	return OK;

}

/**************************************************
* ��������: cycleLkListIsEmpty
* ��������: �ж�ѭ�������Ƿ�Ϊ��
* �������: ָ��ѭ���������ָ��
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ� FALSE ��ʾʧ�� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListIsEmpty(CycleLkList *cycleLkList)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (0 == cycleLkList->length)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

/**************************************************
* ��������: cycleLkListClear
* ��������: ����ѭ��������ĵ�һ�����
* �������: ָ��ѭ���������ָ�룬���
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ� FALSE ��ʾʧ�� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListCreate(CycleLkList *cycleLkList, LkNode lkNode)
{
	LkNode *lkNd;
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (TRUE != cycleLkListIsEmpty(cycleLkList))
	{
		return FALSE;
	}

	lkNd = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNd)
	{
		return FALSE;
	}

	LkNodeCpy(lkNd,&lkNode);
	cycleLkList->head = lkNd;
	cycleLkList->trail = lkNd;
	cycleLkList->trail->next = cycleLkList->head;
	cycleLkList->length += 1;

	lkNd = NULL;

	return TRUE;
}

/**************************************************
* ��������: cycleLkListDisplay
* ��������: ѭ���������
* �������: ָ��ѭ���������ָ��
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ�  ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListDisplay(CycleLkList *cycleLkList)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	LkNodeDisplay(cycleLkList->head);

	cycleLkList->current = cycleLkList->head->next;
	for (;cycleLkList->current != cycleLkList->head;)
	{
		LkNodeDisplay(cycleLkList->current);
		cycleLkList->current = cycleLkList->current->next;

	}

	return OK;
}

/**************************************************
* ��������: cycleLkListHeadInsert
* ��������: ѭ������ͷ�巨
* �������: ָ��ѭ���������ָ�룬���
* �������: ��
* �� �� ֵ: TRUE ��ʾ�ɹ� FALSE ��ʾʧ�� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListHeadInsert(CycleLkList *cycleLkList, LkNode lkNode)
{
	LkNode *lkNd;
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (TRUE == cycleLkListIsEmpty(cycleLkList))
	{
		return FALSE;
	}

	lkNd = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNd)
	{
		return FALSE;
	}

	LkNodeCpy(lkNd,&lkNode);
	lkNd->next = cycleLkList->head;
	cycleLkList->head = lkNd;
	cycleLkList->trail->next = cycleLkList->head;
	cycleLkList->length += 1;

	lkNd = NULL;

	return TRUE;
}

/**************************************************
* ��������: cycleLkListTrailInsert
* ��������: ѭ������β�巨
* �������: ָ��ѭ���������ָ�룬���
* �������: ��
* �� �� ֵ: TRUE ��ʾ�ɹ� FALSE ��ʾʧ�� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListTrailInsert(CycleLkList *cycleLkList, LkNode lkNode)
{
	LkNode *lkNd;
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}

	if (TRUE == cycleLkListIsEmpty(cycleLkList))
	{
		return FALSE;
	}

	lkNd = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNd)
	{
		return FALSE;
	}

	LkNodeCpy(lkNd,&lkNode);
	cycleLkList->trail->next = lkNd;
	cycleLkList->trail = lkNd;
	cycleLkList->trail->next = cycleLkList->head;
	cycleLkList->length += 1;

	lkNd = NULL;

	return TRUE;
}

/**************************************************
* ��������: cycleLkListDelete
* ��������: ѭ������βɾ��ָ����Ž��
* �������: ָ��ѭ���������ָ�룬���
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ� ERROR ��ʾ�Ƿ���� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListDeleteByOrder(CycleLkList *cycleLkList,const int order)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//�ж�����Ƿ�С��0�������ѭ��������ĳ���
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}
	
	//�����ŵ���1����ɾ��ͷ���
	if (1 == order)
	{
		cycleLkList->current = cycleLkList->head;
		
		//�������ɾ���Ľ��
		cycleLkList->head = cycleLkList->head->next;
		cycleLkList->trail->next = cycleLkList->head;
		cycleLkList->current->next = NULL;

		free(cycleLkList->current);
	} 
	else if (cycleLkList->length == order)//�����ŵ���ѭ��������ĳ��ȣ���ɾ��β���
	{
		int i;
		//�ҵ�β����ǰһ�����
		cycleLkList->current = cycleLkList->head;
		for (i = 1; i < order - 1; i++)
		{
			cycleLkList->current = cycleLkList->current->next;
		}

		//�������ɾ���Ľ��
		cycleLkList->trail = cycleLkList->current;
		cycleLkList->current = cycleLkList->current->next;
		cycleLkList->trail->next = cycleLkList->head;
		cycleLkList->current->next = NULL;

	}
	else
	{
		int i;
		LkNode *lkNodeTemp;

		//�ҵ���ɾ������ǰһ�����
		cycleLkList->current = cycleLkList->head;
		for (i = 1; i < order - 1; i++)
		{
			cycleLkList->current = cycleLkList->current->next;
		}

		lkNodeTemp = cycleLkList->current;
		cycleLkList->current = cycleLkList->current->next;
		lkNodeTemp->next = cycleLkList->current->next;
		cycleLkList->current->next = NULL;

		lkNodeTemp = NULL;
	}

	//ɾ����㣬��ѭ��������-1
	free(cycleLkList->current);
	cycleLkList->length -= 1;

	return OK;
}

/**************************************************
* ��������: cycleLkListUpdateByOrder
* ��������: ѭ������β����ָ����Ž��
* �������: ָ��ѭ���������ָ�룬��ţ����
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ� ERROR ��ʾ�Ƿ���� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListUpdateByOrder(CycleLkList *cycleLkList,const int order, LkNode lkNode)
{
	int i;
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//�ж�����Ƿ�С��0�������ѭ��������ĳ���
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}
	
	//�ҵ�����½��
	cycleLkList->current = cycleLkList->head;
	for (i = 1; i < order; i++)
	{
		cycleLkList->current = cycleLkList->current->next;
	}

	LkNodeCpy(cycleLkList->current,&lkNode);

	return OK;
}

/**************************************************
* ��������: cycleLkListInsertByOrder
* ��������: ѭ������β����ָ����Ž��
* �������: ָ��ѭ���������ָ�룬��ţ����
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ� ERROR ��ʾ�Ƿ���� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListInsertByOrder(CycleLkList *cycleLkList,const int order, LkNode lkNode)
{
	int i;
	LkNode *lkNodeTemp;
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//�ж�����Ƿ�С��0�������ѭ��������ĳ���
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}

    lkNodeTemp = (LkNode *)malloc(sizeof(LkNode));
	if (NULL == lkNodeTemp)
	{
		return ERROR;
	}
	//��㸳ֵ
	LkNodeCpy(lkNodeTemp,&lkNode);

	if (cycleLkList->length == order)
	{
		cycleLkList->current = cycleLkList->trail;
		cycleLkList->current->next = lkNodeTemp;
		cycleLkList->trail = lkNodeTemp;
		cycleLkList->trail->next = cycleLkList->head;
	}
	else
	{
		//�ҵ�����½��
		cycleLkList->current = cycleLkList->head;
		for (i = 1; i < order; i++)
		{
			cycleLkList->current = cycleLkList->current->next;
		}

		lkNodeTemp->next = cycleLkList->current->next;
		cycleLkList->current->next = lkNodeTemp;
	}

	return OK;
}

/**************************************************
* ��������: cycleLkListFindByOrder
* ��������: ѭ������β����ָ����Ž��
* �������: ָ��ѭ���������ָ�룬���
* �������: ���ṹ��
* �� �� ֵ: OK ��ʾ�ɹ� ERROR ��ʾ�Ƿ���� ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListFindByOrder(CycleLkList *cycleLkList, const int order, LkNode *outLkNode)
{
	int i;
	//�ж��Ƿ�Ϸ�
	if (NULL == cycleLkList)
	{
		return ILLEGAL;
	}
	
	//�ж�����Ƿ�С��0�������ѭ��������ĳ���
	if ((order < 1) || (order > cycleLkList->length))
	{
		return ERROR;
	}

	//�ҵ�����½��
	cycleLkList->current = cycleLkList->head;
	for (i = 1; i < order; i++)
	{
		cycleLkList->current = cycleLkList->current->next;
	}

	LkNodeCpy(outLkNode,cycleLkList->current);

	return OK;
}

/**************************************************
* ��������: cycleLkListFindByLkNodeMember
* ��������: ͨ������Ա����ѭ����������
* �������: ָ��ѭ���������ָ�룬����Ա���뺯��ָ�룬����Ա�ȽϺ���ָ��
* �������: ѭ��������ָ��
* �� �� ֵ: TRUE ��ʾ�ɹ� FALSE ��ʾ�ڴ治�� ILLEGAL ��ʾ�Ƿ�
* ����˵��: �Ƚϲ�ͬ����Ա��LkNodeMemberEqual��ֵ��ͬ����
* �޸�����		�汾��		�޸���		�޸�����
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD cycleLkListFindByLkNodeMember(CycleLkList *cycleLkList, CycleLkList *outCycleLkList, WORD (*LkNodeMemberInput)(LkNode *inLkNode),WORD (*LkNodeMemberEqual)(LkNode *fristLkNode, LkNode *secondNode))
{
	int flag = 1;
	int i;
	LkNode *outLkNode,*inLkNode;
	//�ж��Ƿ�Ϸ�
	if ((NULL == cycleLkList) || (NULL == outCycleLkList))
	{
		return ILLEGAL;
	}
	
	outLkNode = (LkNode *)(malloc)(sizeof(LkNode));
	inLkNode = (LkNode *)(malloc)(sizeof(LkNode));
	if (NULL == outLkNode || NULL == inLkNode)
	{
		return FALSE;
	}
	
	LkNodeMemberInput(inLkNode);
	cycleLkList->current = cycleLkList->head;
	for (i = 1; i <= cycleLkList->length; i++)
	{
		if (TRUE == LkNodeMemberEqual(cycleLkList->current,inLkNode))
		{
			LkNodeCpy(outLkNode,cycleLkList->current);
			outLkNode->next = NULL;
			
			if (1 != flag)
			{
				cycleLkListTrailInsert(outCycleLkList,*outLkNode);

			}
			else
			{
				flag = 0;
				cycleLkListCreate(outCycleLkList,*outLkNode);
			}
		}
		cycleLkList->current = cycleLkList->current->next;
	}

	return TRUE;
}
