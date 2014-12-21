/******************************************************************************
 * 文件名称： KMP.c
 * 内容摘要： 串的模式匹配KMP算法
 * 当前版本： V1.0
 * 作    者： liao
 * 完成日期： 2014年12月21日
 *
 * 修改记录1：// 修改历史记录，包括修改日期、修改者及修改内容
 * 修改日期：
 * 版 本 号：
 * 修 改 人：
 * 修改内容：
 * 修改记录2：…
 * @license ZPL (http://zpl.pub/v1)
 * Copyright (c) 2014  SmallLeg Team
 ******************************************************************************/

#include "KMP.h"
/*****************************************************************************
 *                           局部函数原型                                    *
 *****************************************************************************/
void GetNext(SString T, int next[]);

/*****************************************************************************
 *                     函数实现--公有部分                                    *
 *****************************************************************************/

/*****************************************************************************
 * 功能描述： 串的模式匹配KMP算法
 *
 * @param   SString S 主串
 * @param   SString T 子串
 * @param   int iPos 从主串的第一个位置开始
 *
 * @return  FALSE 表示失败，返回正数为成功
 ******************************************************************************/
int KMPindex(SString S, SString T, int iPos)  
{  
	int i = iPos, j =1;
	int next[MAXSTRLEN];

    if (iPos <1 ||  iPos > S[0] ) exit(0);  
    
    GetNext(T, next);
	
    while (i <= S[0] && j <= T[0])  
    {  
        if (S[i] == T[j]){  
            ++i; ++j;  
        } else{  
            j = next[j];
        }  
    }  
    if(j > T[0]) return i - T[0];  
    return FALSE;  
}  



/*****************************************************************************
 *                     函数实现--局部部分                                    *
*****************************************************************************/

/*****************************************************************************
 * 功能描述： 求子串next[i]值的算法
 *
 * @param   SString T 子串
 * @param   int next[] 模式串next
 *
 * @return  FALSE 表示失败，返回正数为成功
 ******************************************************************************/

void GetNext(SString T, int next[])
{
	int j = 1, k = 0;
	next[1] = 0;

	while(j<T[0]){
		if(0 == k || T[j] == T[k]){
			++j;
			++k;
			next[j] = k;
		} // end of if 
		else{
			k = next[k];
		} // end if else
	} // end of while
}