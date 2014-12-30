#ifndef _CYCLELKLIST_H_
#define _CYCLELKLIST_H_

#include "type.h"
#include "common.h"

/**
* ѭ��������
* *headָ��������ͷ����ָ��
* *currentָ��������ǰ����ָ��
* lengthΪ��������ĳ���
*/
typedef struct CycleLkList
{
	LkNode *head;//ָ��ѭ���������ͷ
	LkNode *current;//����ָ��ǰ���
	LkNode *trail;//����ָ��ѭ�������β
	int length;//������ĳ���
}CycleLkList;

//ѭ���������ʼ��
WORD cycleLkListInit(CycleLkList**);
//ѭ�����������
WORD cycleLkListClear(CycleLkList*);
//�ж�ѭ���������Ƿ�Ϊ��
WORD cycleLkListIsEmpty(CycleLkList*);
//ѭ������������һ�����
WORD cycleLkListCreate(CycleLkList*, LkNode);
//ѭ�����������
WORD cycleLkListDisplay(CycleLkList*);
//ѭ��������ͷ�巨
WORD cycleLkListHeadInsert(CycleLkList*, LkNode);
//ѭ��������β�巨
WORD cycleLkListTrailInsert(CycleLkList*, LkNode);
//�����ɾ��ָ�����
WORD cycleLkListDeleteByOrder(CycleLkList*,const int);
//����Ÿ���ָ�����
WORD cycleLkListUpdateByOrder(CycleLkList*,const int, LkNode);
//��ָ�������ź�߲���һ�����
WORD cycleLkListInsertByOrder(CycleLkList*,const int, LkNode);
//����Ų���ָ�����
WORD cycleLkListFindByOrder(CycleLkList*, const int, LkNode*);
//������еĳ�Ա�Ƿ�����ҳ����н��
WORD cycleLkListFindByLkNodeMember(CycleLkList*, CycleLkList*, WORD (*LkNodeMemberInput)(LkNode*),WORD (*LkNodeMemberEqual)(LkNode*, LkNode*));

#endif