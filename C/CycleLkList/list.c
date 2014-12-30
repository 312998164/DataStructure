#include "list.h"

/**************************************************
* ��������: ListInit
* ��������: ��ʼ������Ϊ�亯��ָ�븳ֵ
* �������: ָ�������ָ���ָ��
* �������: ��
* �� �� ֵ: OK ��ʾ�ɹ�   ILLEGAL ��ʾ�Ƿ�
* ����˵��:
* �޸�����		�汾��		�޸���		�޸��ڴ�
* --------------------------------------------------
* 14/12/22      v1.0         xxxxx        xxxxx
****************************************************/
WORD ListInit(List **list)
{
	//�ж��Ƿ�Ϸ�
	if (NULL == list)
	{
		return ILLEGAL;
	}

	//��������
	(*list)->LkListInit = lkListInit;
	(*list)->LkListClear = lkListClear;
	(*list)->LkListCreate = lkListCreate;
	(*list)->LkListIsEmpty = lkListIsEmpty;
	(*list)->LkListDisplay = lkListDisplay;
	(*list)->LkListHeadInsert = lkListHeadInsert;
	(*list)->LkListTrailInsert = lkListTrailInsert;
	(*list)->LkListUpdateByOrder = lkListUpdateByOrder;
	(*list)->LkListDeleteByOrder = lkListDeleteByOrder;
	(*list)->LkListFindByOrder = lkListFindByOrder;
	(*list)->LkListFindByLkNodeMember = lkListFindByLkNodeMember;

	//ѭ����������
	(*list)->CycleLkListInit = cycleLkListInit;
	(*list)->CycleLkListClear = cycleLkListClear;
	(*list)->CycleLkListCreate = cycleLkListCreate;
	(*list)->CycleLkListIsEmpty = cycleLkListIsEmpty;
	(*list)->CycleLkListDisplay = cycleLkListDisplay;
	(*list)->CycleLkListHeadInsert = cycleLkListHeadInsert;
	(*list)->CycleLkListTrailInsert = cycleLkListTrailInsert;
	(*list)->CycleLkListUpdateByOrder = cycleLkListUpdateByOrder;
	(*list)->CycleLkListDeleteByOrder = cycleLkListDeleteByOrder;
	(*list)->CycleLkListInsertByOrder = cycleLkListInsertByOrder;
	(*list)->CycleLkListFindByOrder = cycleLkListFindByOrder;
	(*list)->CycleLkListFindByLkNodeMember = cycleLkListFindByLkNodeMember;

	return OK;
}

