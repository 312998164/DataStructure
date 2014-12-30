/*****************************************************************************
This file defines the structures, values, macros, and functions
used often.
@license ZPL (http://zpl.pub/v1)
Copyright (c) 2014  SmallLeg Team
******************************************************************************/

#ifndef _COMMON_H_
#define _COMMON_H_

#ifdef  __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/**************************************************************************
 *                          ����                                            *
 **************************************************************************/

typedef unsigned char       BYTE;
typedef signed   short  int WORD;
typedef signed   long   int DWORD;

/**************************************************************************
 *                          �궨��                                         *
 **************************************************************************/


#define ILLEGAL    5	// ���Ϸ�
#define OVERFLOW1  -5	// ���

#define OK         2	// �ɹ�
#define ERROR     -2	// ����

#define NOEXIST    3    // ������
#define ISEXIST   -3    // �Ѿ�����

#define EQUAL     4		// ���
#define UNEQUAL  -4		// ����

#define TRUE      1
#define FALSE	  0

typedef enum bool
{
    false,
    true
}bool;

#ifdef  __cplusplus
}
#endif

#endif // end of _TYPES_H_