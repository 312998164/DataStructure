#ifndef _LIST_H_
#define _LIST_H_

/**
*������
*��ӽ��
*ɾ�����
*�޸Ľ��
*��ѯ���
*������
*/
#include "type.h"
#include "common.h"
#include "lklist.h"
#include "cyclelklist.h"

typedef struct List
{
	//������������ָ��
	WORD (*LkListInit)(LkList**);
	WORD (*LkListClear)(LkList*);
	WORD (*LkListCreate)(LkList*, LkNode);
	WORD (*LkListDisplay)(LkList*);
	WORD (*LkListHeadInsert)(LkList*, LkNode);
	WORD (*LkListTrailInsert)(LkList*, LkNode);
	WORD (*LkListIsEmpty)(LkList*);
	WORD (*LkListDeleteByOrder)(LkList*,const int);
	WORD (*LkListUpdateByOrder)(LkList*,const int, LkNode);
	WORD (*LkListFindByOrder)(LkList*, const int, LkNode*);
	WORD (*LkListFindByLkNodeMember)(LkList*, LkNode, LkList*, WORD (*LkNodeMemberEqual)(LkNode*, LkNode*));
	//ѭ��������������ָ��
	WORD (*CycleLkListInit)(CycleLkList**);
	WORD (*CycleLkListClear)(CycleLkList*);
	WORD (*CycleLkListCreate)(CycleLkList*, LkNode);
	WORD (*CycleLkListDisplay)(CycleLkList*);
	WORD (*CycleLkListHeadInsert)(CycleLkList*, LkNode);
	WORD (*CycleLkListTrailInsert)(CycleLkList*, LkNode);
	WORD (*CycleLkListIsEmpty)(CycleLkList*);
	WORD (*CycleLkListDeleteByOrder)(CycleLkList*,const int);
	WORD (*CycleLkListUpdateByOrder)(CycleLkList*,const int, LkNode);
	WORD (*CycleLkListInsertByOrder)(CycleLkList*,const int, LkNode);
	WORD (*CycleLkListFindByOrder)(CycleLkList*, const int, LkNode*);
	WORD (*CycleLkListFindByLkNodeMember)(CycleLkList*, CycleLkList*, WORD (*LkNodeMemberInput)(LkNode*),WORD (*LkNodeMemberEqual)(LkNode*, LkNode*));
}List;

WORD ListInit(List **list);


#endif