#include <stdio.h>
#include "list.h"

void menu();

int main()
{
	int no;
	List *list;
	LkNode *lkNode;
	CycleLkList *cycleLkList,*outCycleLkList;

	list = (List *)malloc(sizeof(List));
	lkNode = (LkNode *)malloc(sizeof(LkNode));
	cycleLkList = (CycleLkList *)malloc(sizeof(CycleLkList));
	outCycleLkList = (CycleLkList *)malloc(sizeof(CycleLkList));

	menu();
	ListInit(&list);
	for (;;)
	{
		printf("\n��������Թ��ܴ��ţ�");
		scanf("%d",&no);
		switch (no)
		{
		case 0:
			{
				printf("��ѡ���˳�\n");
				exit(0);
			}
		case 1:
			{
				printf("��ѡ���ʼ��ѭ�����������Է���Ϊ��CycleLkListInit\n");
				list->CycleLkListInit(&cycleLkList);
				break;
			}
		case 2:
			{
				printf("��ѡ�񴴽�ѭ���������һ����㣬���Է���Ϊ��CycleLkListCreate\n");
				LkNodeInput(lkNode);
				list->CycleLkListCreate(cycleLkList,*lkNode);
				break;
			}
		case 3:
			{
				printf("��ѡ��ͷ�巨��ѭ���������в���һ����㣬���Է���Ϊ��CycleLkListHeadInsert\n");
				LkNodeInput(lkNode);
				list->CycleLkListHeadInsert(cycleLkList,*lkNode);
				break;
			}
		case 4:
			{
				printf("��ѡ��β�巨��ѭ���������в���һ����㣬���Է���Ϊ��CycleLkListTrailInsert\n");
				LkNodeInput(lkNode);
				list->CycleLkListTrailInsert(cycleLkList,*lkNode);
				break;
			}
		case 5:
			{
				printf("��ѡ����ѭ����������������Ϊ��length\n");
				printf("ѭ��������ĳ���length = %d\n",cycleLkList->length);
				break;
			}
		case 6:
			{
				int order;
				printf("��ѡ�����ѭ����������ָ����ŵĽ�㣬���Է���Ϊ��CycleLkListFindByOrder\n");
				printf("��������Ҫ���ҵ���ţ�");
				scanf("%d",&order);
				if (ERROR == list->CycleLkListFindByOrder(cycleLkList,order,lkNode))
				{
					printf("ָ����ų�����Χ��������\n");
				}
				else
				{
					LkNodeDisplay(lkNode);
				}

				break;
			}
		case 7:
			{
				printf("��ѡ�񰴽���Ա����ѭ���������е����н�㣬���Է���Ϊ��CycleLkListFindByLkNodeMember\n");
				list->CycleLkListInit(&outCycleLkList);
				if (FALSE == list->CycleLkListFindByLkNodeMember(cycleLkList,outCycleLkList,LkNodeMemberInput,LkNodeMemberEqual))
				{
					printf("δ�����ڴ棬������\n");
				}
				else
				{
					list->CycleLkListDisplay(outCycleLkList);
				}
				break;
			}
		case 8:
			{
				int order;
				LkNode *inLkNode;
				printf("��ѡ�����ѭ��������ָ����ŵĽ�㣬���Է���Ϊ��CycleLkListUpdateByOrder\n");
				printf("��������Ҫ���µ���ţ�");
				scanf("%d",&order);
				if (order < 1 || order > cycleLkList->length)
				{
					printf("ָ����ų�����Χ��������\n");
					break;
				}
				inLkNode = (LkNode *)malloc(sizeof(LkNode));
				if (NULL == inLkNode)
				{
					printf("δ�ܸ��½�����ռ�\n");
				}
				LkNodeInput(inLkNode);
				list->CycleLkListUpdateByOrder(cycleLkList,order,*inLkNode);
				list->CycleLkListDisplay(cycleLkList);
				
				break;
			}
		case 9:
			{
				int order;
				LkNode *inLkNode;
				printf("��ѡ����ָ����ź����һ����㣬���Է���Ϊ��CycleLkListInsertByOrder\n");
				printf("��������Ҫ���µ���ţ�");
				scanf("%d",&order);
				if (order < 1 || order > cycleLkList->length)
				{
					printf("ָ����ų�����Χ��������\n");
					break;
				}
				inLkNode = (LkNode *)malloc(sizeof(LkNode));
				if (NULL == inLkNode)
				{
					printf("δ�ܸ��½�����ռ�\n");
				}
				LkNodeInput(inLkNode);
				list->CycleLkListInsertByOrder(cycleLkList,order,*inLkNode);
				list->CycleLkListDisplay(cycleLkList);
				break;
			}
		case 10:
			{
				int order;
				printf("��ѡ��ɾ��ѭ��������ָ����㣬���Է���Ϊ��CycleLkListDeleteByOrder\n");
				printf("��������Ҫ���µ���ţ�");
				scanf("%d",&order);
				if (order < 1 || order > cycleLkList->length)
				{
					printf("ָ����ų�����Χ��������\n");
					break;
				}
				list->CycleLkListDeleteByOrder(cycleLkList,order);
				list->CycleLkListDisplay(cycleLkList);
				break;
			}
		case 11:
			{
				printf("��ѡ�����ѭ�����������Է���Ϊ��CycleLkListClear\n");
				list->CycleLkListClear(cycleLkList);
				break;
			}
		case 12:
			{
				printf("��ѡ���ж�ѭ�������Ƿ�Ϊ�գ����Է���Ϊ��CycleLkListIsEmpty\n");
				if (TRUE != list->CycleLkListIsEmpty(cycleLkList))
				{
					printf("ѭ��������Ϊ��\n");
				}
				else
				{
					printf("ѭ��������Ϊ��\n");
				}
				break;
			}
		case 13:
			{
				printf("��ѡ�����ѭ���������Է���Ϊ��CycleLkListDisplay\n");
				list->CycleLkListDisplay(cycleLkList);
				break;
			}
		default:
			{
				printf("��ѡ��Ĭ�ϡ����˳�\n");
				exit(0);
			}
		}
	}
	return 0;
}

void menu()
{
	printf("***********************************************  ");
	printf("\n*          ѭ �� �� �� �� �� ϵ ͳ            *");
	printf("\n***********************************************");
	printf("\n*     ��ע��ͷ��㲻Ϊ��ѭ��������            *");
	printf("\n*     ��ע�����·�����������List�ṹ����      *");
	printf("\n*     ��ע���ȳ�ʼ��List�ṹ�塪ListInit(Ĭ��)*");
	printf("\n*     ��ע��ѭ���������ȳ�ʼ�����󴴽����ڲ���*");
	printf("\n***********************************************");
	printf("\n*          0----------��        ��            *");
	printf("\n*          1----------��   ʼ   ��            *");
	printf("\n*          2----------��        ��            *");
	printf("\n*          3----------ͷ   ��   ��            *");
	printf("\n*          4----------β   ��   ��            *");
	printf("\n*          5----------��   ��   ��            *");
	printf("\n*          6----------����� �� ��            *");
	printf("\n*          7----------�� ֵ  �� ��            *");
	printf("\n*          8----------��        ��            *");
    printf("\n*          9----------��        ��            *");
	printf("\n*         10----------ɾ        ��            *");
	printf("\n*         11----------��        ��            *");
	printf("\n*         12----------��        ��            *");
	printf("\n*         13----------��        ʾ            *");
	printf("\n***********************************************");
}