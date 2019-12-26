/*
 * json �������Ϳ��Է�Ϊ 4 �ֻ������ͣ�
 * Number Array String Object
 * json ������Կ���һ�� Object
 * ��ֵ�Բ���hashMap�ķ�ʽ���д��
 * ͨ�� �������� ��ʽ��� hash ��ͻ
 * �������ʱ���������ֵ�Ѿ����ڣ����滻
*/
#define _CRT_SECURE_NO_WARNINGS
#ifndef __JSON_LIB__H_
#define __JSON_LIB__H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "md5.h"
#include "jsonDataStruct.h"

/*
* ���� Object �ն���
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreate();

/*
* ���� Array ������
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONCreateArray();

/*
 * json ��ʽ���������� json �ַ���ת���� json ����
 * @param	input		json �ַ���
 * @return	pJsonObjectNode
*/
pJsonObjectNode JSONParse(char* input);

/*
* json ���л����� json ����ת���� json �ַ���
* @param	pNode pJsonNode			json �ڵ�
* @param	output	char**			�����ַ�����ָ��
* @return	void
*/
void JSONStringify(pJsonNode pNode /* in */, char** output /* out */);

/*
* ��ӡ json �ڵ�
* @param	pNode pJsonNode		json �ڵ�
* @return	void
*/
void JSONPrint(pJsonNode pNode /* in */);

/*
* ���� json �ڵ�
* @param	pObject		json �ڵ�
* @return	void
*/
void JSONDestroy(pJsonNode pNode /* in */);

/*
 * �ж� json �Ƿ��������
 * @param	pObject		json ����
 * @param	key			��������
 * @return	BOOLEAN		�Ƿ��������
*/
BOOLEAN JSONIsContainsAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
 * �� json ��������� Number���� ��ֵ����
 * @param	pObject		json ����
 * @param	key			��������
 * @param	value		����ֵ
 * @return	void
*/
void JSONSetNumberAttr(pJsonObjectNode pObject /* in */, char* key /* in */, double value /* in */);

/*
 * �� json ��������� String���� ��ֵ����
 * @param	pObject		json ����
 * @param	key			��������
 * @param	value		����ֵ
 * @return	void
*/
void JSONSetStringAttr(pJsonObjectNode pObject /* in */, char* key /* in */, char* value /* in */);

/*
 * �� json ��������� Array���� ��ֵ������ӵ�����Ϊ������
 * @param	pObject		json ����
 * @param	key			��������
 * @return	void
*/
void JSONSetEmptyArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* �� json ��������� Array���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @param	value		pJsonArrayNode	����ڵ�
* @param	isDeepClone	BOOLEAN �Ƿ������ȿ���
 * @return	void
*/
void JSONSetArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonArrayNode pArray, BOOLEAN isDeepClone);

/*
 * �� json ��������� Object���� ��ֵ����
 * @param	pObject		json ����
 * @param	key			��������
 * @param	value		����ֵ
* @param	isDeepClone	BOOLEAN �Ƿ������ȿ���
 * @return	void
*/
void JSONSetObjectAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonObjectNode value /* in */, BOOLEAN isDeepClone);

/*
* �� json ��������� null���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @return	void
*/
void JSONSetNullAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* �� json ��������� Boolean���� ��ֵ����
* @param	pObject				json ����
* @param	key char*			��������
* @param	value Boolean		����ֵ
* @return	void
*/
void JSONSetBooleanAttr(pJsonObjectNode pObject /* in */, char* key /* in */, BOOLEAN value /* in */);

/*
 * �Ƴ� json �����е�����
 * @param	pObject		json ����
 * @param	key			��������
 * @return	void
*/
void JSONRemoveAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* json �������
* @param	pObject json����
* @return	pJsonObjectNode	�´�����json����
*/
pJsonObjectNode JSONObjectDeepClone(pJsonObjectNode pObject /* in */);

/*
* json �������
* @param	pArray json����
* @return	pJsonArrayNode	�´�����json Array
*/
pJsonArrayNode JSONArrayDeepClone(pJsonArrayNode pArray /* in */);

/*
* �� json ����ڵ�������β��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	number double	��Ҫ��ӵ�����
* @return	void
*/
void JSONArrayPushNumber(pJsonArrayNode pArrayNode /* in */, double number /* in */);

/*
* �� json ����ڵ�������β��׷���ַ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pString char*	��Ҫ��ӵ��ַ���
* @return	void
*/
void JSONArrayPushString(pJsonArrayNode pArrayNode /* in */, char* pString /* in */);

/*
* �� json ����ڵ�������β��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pArr pJsonArrayNode	��Ҫ��ӵ�����ڵ�
* @return	void
*/
void JSONArrayPushArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */);

/*
* �� json ����ڵ�������β��׷�Ӷ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pObject pJsonObjectNode	��Ҫ��ӵĶ���ڵ�
* @return	void
*/
void JSONArrayPushObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */);

/*
* �� json ����ڵ�������β��׷�� null
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayPushNull(pJsonArrayNode pArrayNode /* in */);

/*
* �� json ����ڵ�������β��׷�� Boolean
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	value BOOLEAN	��Ҫ��ӵ� Boolean
* @return	void
*/
void JSONArrayPushBoolean(pJsonArrayNode pArrayNode /* in */, BOOLEAN value /* in */);

/*
* �� json ����ڵ�������ͷ��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	number double	��Ҫ��ӵ�����
* @return	void
*/
void JSONArrayUnshiftNumber(pJsonArrayNode pArrayNode /* in */, double number /* in */);

/*
* �� json ����ڵ�������ͷ��׷���ַ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pString char*	��Ҫ��ӵ��ַ���
* @return	void
*/
void JSONArrayUnshiftString(pJsonArrayNode pArrayNode /* in */, char* pString /* in */);

/*
* �� json ����ڵ�������ͷ��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pArr pJsonArrayNode	��Ҫ��ӵ�����
* @return	void
*/
void JSONArrayUnshiftArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */);

/*
* �� json ����ڵ�������ͷ��׷�Ӷ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pObject pJsonObjectNode	��Ҫ��ӵĶ���
* @return	void
*/
void JSONArrayUnshiftObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */);

/*
* �� json ����ڵ�������ͷ��׷�� null
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayUnshiftNull(pJsonArrayNode pArrayNode /* in */);

/*
* �� json ����ڵ�������ͷ��׷�� Boolean
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	value BOOLEAN	��Ҫ��ӵ� Boolean
* @return	void
*/
void JSONArrayUnshiftBoolean(pJsonArrayNode pArrayNode /* in */, BOOLEAN value /* in */);

/*
* ��ȡ�������͵����ݳ���
* @param	pArray	pJsonArrayNode ����ڵ�
* @return	unsigned int	���鳤��
*/
unsigned int JSONArrayGetLength(pJsonArrayNode pArray /* in */);

/*
* ��ȡ����ָ��λ��Ԫ��
* @param	pArray	pJsonArrayNode ����ڵ�
* @param	pos		int
* @return	pJsonNode	����Ԫ��
*/
pJsonNode JSONArrayGetNode(pJsonArrayNode pArray /* in */, int pos /* in */);

/*
* �� json ����ڵ�������β��ɾ��Ԫ�أ������ٸ�Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayPop(pJsonArrayNode pArrayNode /* in */);

/*
* �� json ����ڵ�������ͷ��ɾ��Ԫ�أ������ٸ�Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayShift(pJsonArrayNode pArrayNode /* in */);

/*
* ��ȡ Object ������������
* @param	pObject	pJsonObjectNode	json ����
* @param	key char*		��ֵ
* @return	JSON_DATA_TYPE		json �ڵ����������
*/
JSON_DATA_TYPE JSONObjectGetAttrType(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* ��ȡ �ڵ� ��������
* @param	pNode	pJsonNode	�ڵ�
* @return	JSON_DATA_TYPE		json �ڵ����������
*/
JSON_DATA_TYPE JSONNodeGetType(pJsonNode pNode /* in */);

/*
* ��ȡ���ֽڵ����ֵ
* @param	pNode	pJsonNumberNode	���ֽڵ�
* @param	pValue	double*
* @return	void
*/
void JSONNodeGetNumberValue(pJsonNumberNode pNode /* in */, double* pValue /* out */);

/*
* ��ȡ�ַ����ڵ�ĵ��ַ���
* @param	pNode	pJsonStringNode	�ַ����ڵ�
* @param	ppValue	char**
* @return	void
*/
void JSONNodeGetStringValue(pJsonStringNode pNode /* in */, char** ppValue /* out */);

/*
* ��ȡ Boolean �ڵ��ֵ
* @param	pNode	pJsonBooleanNode	Boolean�ڵ�
* @param	pValue	BOOLEAN*
* @return	void
*/
void JSONNodeGetBooleanValue(pJsonBooleanNode pNode /* in */, BOOLEAN* pValue /* out */);

/*
* ��ȡ json �������Խڵ����ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*			��
* @param	pValue		double*			ֵ
* @return	void
*/
void JSONObjectGetNumberAttr(pJsonObjectNode pObject /* in */, char* key /* in */, double* pValue /* out */);

/*
* ��ȡ json �ַ������Խڵ���ַ���
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*			��
* @param	ppValue		char**			ֵ
* @return	void
*/
void JSONObjectGetStringAttr(pJsonObjectNode pObject /* in */, char* key /* in */, char** ppValue /* out */);

/*
* ��ȡ json �������Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*			��
* @param	ppValue		pJsonArrayNode*	ֵ
* @return	void
*/
void JSONObjectGetArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonArrayNode* ppValue /* out */);

/*
* ��ȡ json �������Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*				��
* @param	ppValue		pJsonObjectNode*	ֵ
* @return	void
*/
void JSONObjectGetObjectAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonObjectNode* ppValue /* out */);

/*
* ��ȡ json  null ���Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*				��
* @param	pValue		pJsonNullNode*
* @return	void
*/
void JSONObjectGetNullAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonNullNode* ppValue /* out */);

/*
* ��ȡ json  Boolean ���Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*				��
* @param	pValue		BOOLEAN*
* @return	void
*/
void JSONObjectGetBooleanAttr(pJsonObjectNode pObject /* in */, char* key /* in */, BOOLEAN* pValue /* out */);

#endif
