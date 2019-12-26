#include "jsonLib.h"

/*����һЩ����Ҫ��¶�Ĺ���*/
/*
* ���� md5 ���ܺ���ַ���
* @param input ��Ҫ���ܵ��ַ���
* @param output ���ܺ���ַ������ڴ��С������33���ֽ�
* @return void
*/
void encryptionStr(char *input /* in */, char *output /* out */);

/*
* �����ַ���������hashֵ
* @param	input ��Ҫ������ַ���
* @return	unsigned long int ������
*/
unsigned long int getHashVal(char *input /* in */);

/*
* ���� Number �ڵ�
* @param	key		char*	������
* @param	value	double	��ֵ
* @return	pJsonNumberNode Number�ڵ�ָ��
*/
pJsonNumberNode JSONCreateNumberNode(char* key /* in */, double value /* in */);

/*
* ���� String �ڵ�
* @param	key		char* ������
* @param	value	char* ��ֵ
* @return	pJsonStringNode String�ڵ�ָ��
*/
pJsonStringNode JSONCreateStringNode(char* key /* in */, char* value /* in */);

/*
* ���� Array ���������
* @param	key		char* ������
* @return	pJsonArrayNode Array�ڵ�ָ��
*/
pJsonArrayNode JSONCreateArrayNode(char* key /* in */);

/*
* ���� Object �ն���
* @param	key		char* ������
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreateObjectNode(char* key /* in */);

/*
* ���� null �ڵ�
* @param	key		char*	������
* @return	pJsonNullNode null�ڵ�ָ��
*/
pJsonNullNode JSONCreateNullNode(char* key /* in */);

/*
* ���� Boolean �ڵ�
* @param	key		char*	������
* @param	value	BOOLEAN	��ֵ
* @return	pJsonBooleanNode Boolean�ڵ�ָ��
*/
pJsonBooleanNode JSONCreateBooleanNode(char* key /* in */, BOOLEAN value /* in */);

/*
* ��ӡ Number
* @param	pNode pJsonNumberNode
* @return	void
*/
void JSONPrintNumberNode(pJsonNumberNode pNode /* in */);

/*
* ��ӡ String
* @param	pNode pJsonStringNode
* @return	void
*/
void JSONPrintStringNode(pJsonStringNode pNode /* in */);

/*
* ��ӡ Array
* @param	pNode pJsonArrayNode
* @return	void
*/
void JSONPrintArrayNode(pJsonArrayNode pNode /* in */);

/*
* ��ӡ json ����
* @param	pObject		json ����
* @return	void
*/
void JSONPrintObjectNode(pJsonObjectNode pObject /* in */);

/*
* ��ӡ null
* @param	pNode pJsonNullNode
* @return	void
*/
void JSONPrintNullNode(pJsonNullNode pNode /* in */);

/*
* ��ӡ Boolean
* @param	pNode pJsonBooleanNode
* @return	void
*/
void JSONPrintBooleanNode(pJsonBooleanNode pNode /* in */);

/*
* ���� Number �������ͽڵ�
* @param	pNode Number���ͽڵ�
* @return void
*/
void JSONDestroyNumberNode(pJsonNumberNode pNode /* in */);

/*
* ���� String �������ͽڵ�
* @param	pNode String���ͽڵ�
* @return void
*/
void JSONDestroyStringNode(pJsonStringNode pNode /* in */);

/*
* ���� Array �������ͽڵ�
* @param	pNode Array���ͽڵ�
* @return void
*/
void JSONDestroyArrayNode(pJsonArrayNode pNode /* in */);

/*
* ���� Object �������ͽڵ�
* @param	pNode Object���ͽڵ�
* @return void
*/
void JSONDestroyObjectNode(pJsonObjectNode pNode /* in */);

/*
* ���� null �������ͽڵ�
* @param	pNode null���ͽڵ�
* @return void
*/
void JSONDestroyNullNode(pJsonNullNode pNode /* in */);

/*
* ���� Boolean �������ͽڵ�
* @param	pNode Boolean���ͽڵ�
* @return void
*/
void JSONDestroyBooleanNode(pJsonBooleanNode pNode /* in */);

/*
* json ���ֶ������
* @param	pNumber jsonNumber
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonNumberNode	�´�����json Number
*/
pJsonNumberNode JSONNumberDeepClone(pJsonNumberNode pNumber /* in */, BOOLEAN isCopyKey /* in */);

/*
* json �ַ����������
* @param	pString jsonString
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonNumberNode	�´�����json Number
*/
pJsonStringNode JSONStringDeepClone(pJsonStringNode pString /* in */, BOOLEAN isCopyKey /* in */);

/*
* json null �������
* @param	pNull pJsonNullNode
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonNullNode	�´�����json null
*/
pJsonNullNode JSONNullDeepClone(pJsonNullNode pNull /* in */, BOOLEAN isCopyKey /* in */);

/*
* json Boolean �������
* @param	pNull pJsonBooleanNode
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonBooleanNode	�´�����json Boolean
*/
pJsonBooleanNode JSONBooleanDeepClone(pJsonBooleanNode pBoolean /* in */, BOOLEAN isCopyKey /* in */);

/*
* �� json ����ڵ�������β��׷��Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pNode pJsonNode	��Ҫ��ӵĽڵ�
* @return	void
*/
void JSONArrayPush(pJsonArrayNode pArrayNode /* in */, pJsonNode pNode /* in */);

/*
* �� json ����ڵ�������ͷ��׷��Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pNode pJsonNode	��Ҫ��ӵĽڵ�
* @return	void
*/
void JSONArrayUnshift(pJsonArrayNode pArrayNode /* in */, pJsonNode pNode /* in */);

/*
* ���ֽڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonNumberNode ���ֽڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyNumberNode(pJsonNumberNode pNode, BOOLEAN isContainsKey);

/*
* �ַ����ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonStringNode �ַ����ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyStringNode(pJsonStringNode pNode, BOOLEAN isContainsKey);

/*
* ����ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonArrayNode ����ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyArrayNode(pJsonArrayNode pNode, BOOLEAN isContainsKey);

/*
* ����ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonObjectNode ����ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyObjectNode(pJsonObjectNode pNode, BOOLEAN isContainsKey);

/*
* null �ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonNullNode null�ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyNullNode(pJsonNullNode pNode, BOOLEAN isContainsKey);

/*
* Boolean �ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonBooleanNode Boolean�ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyBooleanNode(pJsonBooleanNode pNode, BOOLEAN isContainsKey);

/*
* ȥ���ַ����ж���Ķ���
* @param	input	char* ��Ҫȥ���ŵ��ַ���
* @return	char*	ȥ���ź���ַ���
*/
char* JSONStringRemoveComma(char* input /* in */);

/*
* �ж� ���Ƿ���Ч
* @param	input	char* ����ļ�
* @param	len		int	  ����
* @return	BOOLEAN		�������Ƿ�Ϸ�
*/
BOOLEAN JSONKeyIsOk(char* input /* in */, int len /* in */);

/*
* json �ַ���ȥ�ո�Ȳ��ɼ��ַ�
* @param	input	char*	��Ҫȥ�ո���ַ���
* @return	char*	ȥ�ո����ַ���
*/
char* JSONStringTrim(char* input /* in */);

/*
* null ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringNullIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* Boolean ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringBooleanIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* String ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringStringIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* �������ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringNumberIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* Array ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringArrayIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* Object ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringObjectIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* �ж� json �ַ����Ƿ�Ϸ�
* @param	input	char*	��Ҫ�������ַ���
* @return	BOOLEAN			���ϸ�ʽҪ�󣬷��� BTRUE ���򷵻� BFALSE
*/
BOOLEAN JSONStringIsFormat(char* input /* in */);

/*
* �ַ����Ƿ�������
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsArray(char* input /* in */, int len /* in */);

/*
* �ַ����Ƿ��Ƕ���
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsObject(char* input /* in */, int len /* in */);

/*
* ��ʽ�� json ����
* @param	input	char* ��Ҫ��ʽ�����ַ���
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONParseArray(char* input /* in */);

/*
* ��ʽ�� json ����
* @param	input	char* ��Ҫ��ʽ�����ַ���
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONParseObject(char* input /* in */);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// ��ʽ����ʱ����Բ�ͬ�Ľṹ���з����ʽ��

/*
* �ַ����Ƿ�������
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsNumber(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (len <= 0 || !input) {
			break;
		}
		char* buf = malloc(len + 1);
		if (!buf) {
			break;
		}
		memset(buf, 0, len + 1);
		memcpy(buf, input, len);
		char ch = 0;
		BOOLEAN badChar = BFALSE; // ���Ϸ��ַ�
		// ���ʱΪ������
		for (int j = 0; j < len; j++) {
			ch = buf[j] & 0xFF;
			if ((ch < '0' && (ch != '.' && ch != '+')) || (ch > '9' && (ch != 'e' && ch != 'E'))) {
				badChar = BTRUE;
				break;
			}
		}
		if (badChar) {
			free(buf);
			break;
		}
		char* p = NULL;
		// ��ѧ������
		if ((p = strstr(buf, "e+")) || (p = strstr(buf, "E+"))) {
			if (strlen(p) == 2) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			// �жϿ�ѧ������ָ���Ƿ�Ϸ�
			if (strstr(p + 2, "e") || strstr(p + 2, "E") || strstr(p + 2, "+") || strstr(p + 2, ".")) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			// �жϿ�ѧ�����������Ƿ�Ϸ�
			p[0] = 0;
			if (strstr(buf, "e") || strstr(buf, "E") || strstr(buf, "+")) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			if (strlen(buf) == 0) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			if ((buf[strlen(buf) - 1] == '.') || (buf[0] == '.')) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			if (p = strstr(buf, ".")) {
				if (strstr(p + 1, ".")) {
					badChar = BTRUE;
					goto STR_IS_NUMBER_LABLE;
				}
			}
			if (strlen(buf) > 1) {
				if (buf[0] == '0' && buf[1] != '.') {
					badChar = BTRUE;
					goto STR_IS_NUMBER_LABLE;
				}
			}
		}
		else {
			// ʮ���Ʊ�ʾ��
			char* p = NULL;
			if (strstr(buf, "e") || strstr(buf, "E") || strstr(buf, "+")) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			if (p = strstr(buf, ".")) {
				if (strstr(p + 1, ".")) {
					badChar = BTRUE;
					goto STR_IS_NUMBER_LABLE;
				}
			}
			if ((buf[strlen(buf) - 1] == '.') || (buf[0] == '.')) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			if (strlen(buf) > 1) {
				if (buf[0] == '0' && buf[1] != '.') {
					badChar = BTRUE;
					goto STR_IS_NUMBER_LABLE;
				}
			}
		}
	STR_IS_NUMBER_LABLE:
		free(buf);
		if (badChar) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* �ַ����Ƿ����ַ���
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsString(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (len <= 1 || !input) {
			break;
		}
		char* buf = malloc(len + 1);
		if (!buf) {
			break;
		}
		memset(buf, 0, len + 1);
		memcpy(buf, input, len);
		char ch = 0;
		int len = strlen(buf);
		BOOLEAN badChar = BFALSE; // ���Ϸ��ַ�
		if (len < 2) {
			free(buf);
			break;
		}
		if (buf[0] != '"' || buf[len - 1] != '"') {
			free(buf);
			break;
		}
		if (strstr(buf+1, "\"") != (buf + (len - 1))) {
			free(buf);
			break;
		}
		free(buf);
		res = BTRUE;
	} while (0);
	return res;
}

/*
* �ַ����Ƿ��� null
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsNull(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (len <= 3 || !input) {
			break;
		}
		char* buf = malloc(len + 1);
		if (!buf) {
			break;
		}
		memset(buf, 0, len + 1);
		memcpy(buf, input, len);
		if (strcmp(buf, "null") != 0) {
			free(buf);
			break;
		}
		free(buf);
		res = BTRUE;
	} while (0);
	return res;
}

/*
* �ַ����Ƿ��� Boolean
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsBoolean(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (len <= 3 || !input) {
			break;
		}
		char* buf = malloc(len + 1);
		if (!buf) {
			break;
		}
		memset(buf, 0, len + 1);
		memcpy(buf, input, len);
		if ((strcmp(buf, "true") != 0 && strcmp(buf, "false") != 0)) {
			free(buf);
			break;
		}
		free(buf);
		res = BTRUE;
	} while (0);
	return res;
}

/*
* �ַ����Ƿ�������
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsArray(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (len <= 1 || !input) {
			break;
		}
		char* buf = malloc(len + 1);
		if (!buf) {
			break;
		}
		memset(buf, 0, len + 1);
		memcpy(buf, input, len);
		if ((buf[0] != '[') || (buf[len - 1] != ']')) {
			free(buf);
			break;
		}
		if (len == 2) {
			res = BTRUE;
			free(buf);
			break;
		}
		BOOLEAN badChar = BFALSE;
		for (int i = 1; i < len - 1; i++) {
			int idx = 0;
			if (buf[i] == '\"') {
				// ��־��������Ԫ�����ַ���
				idx = i + 1;
				while (idx <= len - 2) {
					if (buf[idx] == '\"') {
						break;
					}
					idx++;
				}
				if (idx == len - 1) {
					idx--;
				}
				if (buf[idx] == '\"') {
					// �Ѿ�ƥ�䵽���������
					if (idx == len - 2) {
						// ��ʱ�ַ��������һ��Ԫ�أ��ж��ַ����Ƿ�Ϸ�
						badChar = !strIsString(buf+i, idx + 1 - i);
						break;
					}
					else {
						badChar = !strIsString(buf + i, idx + 1 - i);
						if (badChar) {
							break;
						}
						// �����βֻ��һ���ַ��ˣ������Դ������
						if (idx == len - 3) {
							badChar = BTRUE;
							break;
						}
						// ��һ���ַ���������ָ��
						if (buf[idx+1] != ',') {
							badChar = BTRUE;
							break;
						}
						i = idx + 1;
					}
				}
				else {
					// û��ƥ�䵽
					badChar = BTRUE;
					break;
				}
			}
			else if (buf[i] == '[') {
				// ��־������������������
				// ��Ҫ������ƥ����������
				int markCount = 1;
				idx = i + 1;
				int quotCount = 0;
				while (idx <= len - 2) {
					if (buf[idx] == '\"') {
						quotCount++;
					}
					if (quotCount % 2 == 0) {
						if (buf[idx] == ']') {
							markCount--;
						}
						else if (buf[idx] == '[') {
							markCount++;
						}
					}
					if (markCount == 0) {
						break;
					}
					idx++;
				}
				if (idx == len - 1) {
					idx--;
				}
				if (markCount != 0) {
					// ���鲻ƥ��
					badChar = BTRUE;
					break;
				}
				badChar = !strIsArray(buf + i, idx + 1 - i);
			}
			else if (buf[i] == '{') {
				// ��־�������Ƕ���
				// ��־������������������
				// ��Ҫ������ƥ����������
				int markCount = 1;
				idx = i + 1;
				int quotCount = 0;
				while (idx <= len - 2) {
					if (buf[idx] == '\"') {
						quotCount++;
					}
					if (quotCount % 2 == 0) {
						if (buf[idx] == '}') {
							markCount--;
						}
						else if (buf[idx] == '{') {
							markCount++;
						}
					}
					if (markCount == 0) {
						break;
					}
					idx++;
				}
				if (idx == len - 1) {
					idx--;
				}
				if (markCount != 0) {
					// ���鲻ƥ��
					badChar = BTRUE;
					break;
				}
				badChar = !strIsObject(buf + i, idx + 1 - i);
			}
			else if (buf[i] == 'f' || buf[i] == 't') {
				// ��־�������� true �� false
				idx = i + 1;
				while (idx <= len - 2) {
					if (buf[idx] == ',') {
						break;
					}
					idx++;
				}
				if (idx == len - 1 || buf[idx] == ',') {
					idx--;
				}
				badChar = !strIsBoolean(buf + i, idx + 1 - i);
			}
			else if (buf[i] == 'n') {
				// ��־�������� null
				// ��־�������� true �� false
				idx = i + 1;
				while (idx <= len - 2) {
					if (buf[idx] == ',') {
						break;
					}
					idx++;
				}

				if (idx == len - 1 || buf[idx] == ',') {
					idx--;
				}
				badChar = !strIsNull(buf + i, idx + 1 - i);
			}
			else if ('0' <= buf[i] && buf[i] <= '9') {
				// ������������
				idx = i + 1;
				while (idx <= len - 2) {
					if (buf[idx] == ',') {
						break;
					}
					idx++;
				}

				if (idx == len - 1 || buf[idx] == ',') {
					idx--;
				}
				badChar = !strIsNumber(buf + i, idx + 1 - i);
			}
			else {
				badChar = BTRUE;
				break;
			}

			if (badChar) {
				break;
			}
			// �Ѿ�����β
			if (idx == len - 2) {
				break;
			}
			if (idx == len - 3) {
				badChar = BTRUE;
				break;
			}
			// ��һ���ַ���������ָ��
			if (buf[idx + 1] != ',') {
				badChar = BTRUE;
				break;
			}
			i = idx + 1;
		}
		free(buf);
		if (badChar) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* �ַ����Ƿ��Ƕ���
* @param	input char* ������ַ���
* @param	len		int	  ����
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN strIsObject(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (len <= 1 || !input) {
			break;
		}
		char* buf = malloc(len + 1);
		if (!buf) {
			break;
		}
		memset(buf, 0, len + 1);
		memcpy(buf, input, len);
		if ((buf[0] != '{') || (buf[len - 1] != '}')) {
			free(buf);
			break;
		}
		if (len == 2) {
			free(buf);
			res = BTRUE;
			break;
		}
		BOOLEAN badChar = BFALSE;
		int idx = 0;
		for (int i = 1; i < len - 1; i++) {
			if (buf[i] == '\"') {
				int idx = i + 1;
				while (idx <= len - 2) {
					if (buf[idx] == '\"') {
						break;
					}
					idx++;
				}

				// ��������β��δ���ҵ���β
				if (idx == len - 1) {
					badChar = BTRUE;
					break;
				}
				else if (idx == len - 3) {
					badChar = BTRUE;
					break;
				} else {
					if (buf[idx+1] != ':') {
						badChar = BTRUE;
						break;
					}
					else {
						// �˴���Ҫ�����ж�����������
						int curIdx = idx + 2;
						idx = curIdx + 1;
						if (buf[curIdx] == '\"') {
							// ֵΪ�ַ���
							while (idx <= len - 2) {
								if (buf[idx] == '\"') {
									break;
								}
								idx++;
							}
							// �Ѿ�����β�ˣ�����ûƥ�䵽�ַ���
							badChar = !JSONStringStringIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == '[') {
							// ֵΪ����
							int markCount = 1;
							int quotCount = 0;
							while (idx <= len - 2) {
								if (buf[idx] == '\"') {
									quotCount++;
								}
								if (quotCount % 2 == 0) {
									if (buf[idx] == ']') {
										markCount--;
									}
									else if (buf[idx] == '[') {
										markCount++;
									}
								}
								if (markCount == 0) {
									break;
								}
								idx++;
							}
							if (markCount != 0) {
								// ���鲻ƥ��
								badChar = BTRUE;
								break;
							}
							badChar = !JSONStringArrayIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == '{') {
							// ֵΪ����
							int markCount = 1;
							int quotCount = 0;
							while (idx <= len - 2) {
								if (buf[idx] == '\"') {
									quotCount++;
								}
								if (quotCount % 2 == 0) {
									if (buf[idx] == '}') {
										markCount--;
									}
									else if (buf[idx] == '{') {
										markCount++;
									}
								}
								if (markCount == 0) {
									break;
								}
								idx++;
							}
							if (markCount != 0) {
								// ���鲻ƥ��
								badChar = BTRUE;
								break;
							}
							badChar = !JSONStringObjectIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == 'n') {
							// ֵΪ null
							while (idx <= len - 2) {
								if (buf[idx] == ',') {
									break;
								}
								idx++;
							}

							if (idx == len - 1 || buf[idx] == ',') {
								idx--;
							}
							badChar = !JSONStringNullIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == 't' || buf[curIdx] == 'f') {
							// ֵΪ Boolean
							while (idx <= len - 2) {
								if (buf[idx] == ',') {
									break;
								}
								idx++;
							}

							if (idx == len - 1 || buf[idx] == ',') {
								idx--;
							}
							badChar = !JSONStringBooleanIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] >= '0' && buf[curIdx] <= '9') {
							// ֵΪ Number
							while (idx <= len - 2) {
								if (buf[idx] == ',') {
									break;
								}
								idx++;
							}

							if (idx == len - 1 || buf[idx] == ',') {
								idx--;
							}
							badChar = !JSONStringNumberIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else {
							badChar = BTRUE;
							break;
						}


						if (idx == len - 1) {
							badChar = BTRUE;
							break;
						}
						else {
							// �ַ���Ϊ���һ��Ԫ��
							if (idx == len - 2) {
								break;
							}
							else if (idx >= len - 6) {
								badChar = BTRUE;
								break;
							}
							else {
								if (buf[idx + 1] != ',') {
									badChar = BTRUE;
									break;
								}
							}
						}
					}
				}
				if (badChar) {
					break;
				}
				i = idx + 1;
			}
			else {
				badChar = BTRUE;
				break;
			}
		}
		free(buf);
		if (badChar) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* �������ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringNumberIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 0) {
			break;
		}
		int quotationMarks		= 0; // ���ż���
		char ch					= 0;
		int quotPosLeft			= 0; // ������λ��
		int quotPosRight		= 0; // ������λ��
		BOOLEAN badKey			= BFALSE; // ���Ϸ�������
		BOOLEAN colonCount		= 0;//����
		if (!isHasKey) {
			badKey = !strIsNumber(input, len);
			if (badKey) {
				break;
			}
			res = BTRUE;
			break;
		}
		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (ch == '"') {
				quotationMarks++;
				if (quotationMarks % 2) {
					quotPosLeft = i;
				}
				else {
					quotPosRight = i;
				}
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ':') {
					colonCount++;
					if (input[i - 1] != '"') {
						badKey = BTRUE;
						break;
					}
					badKey = !JSONKeyIsOk(input + (quotPosLeft + 1), (quotPosRight - quotPosLeft - 1));
					if (badKey) {
						break;
					}
					if (i + 1 == len) {
						badKey = BTRUE;
						break;
					}
					badKey = !strIsNumber(input + (i + 1), len - i - 1);
					break;
				}
			}
		}
		if (badKey) {
			break;
		}
		if (colonCount != 1) {
			break;
		}
		if (quotationMarks != 2) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* null ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringNullIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 3) {
			break;
		}
		int quotationMarks = 0; // ���ż���
		char ch = 0;
		int quotPosLeft = 0; // ������λ��
		int quotPosRight = 0; // ������λ��
		BOOLEAN badKey = BFALSE; // ���Ϸ�������
		BOOLEAN colonCount = 0;//����

		if (!isHasKey) {
			badKey = !strIsNull(input, len);
			if (badKey) {
				break;
			}
			res = BTRUE;
			break;
		}

		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (ch == '"') {
				quotationMarks++;
				if (quotationMarks % 2) {
					quotPosLeft = i;
				}
				else {
					quotPosRight = i;
				}
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ':') {
					colonCount++;
					if (input[i - 1] != '"') {
						badKey = BTRUE;
						break;
					}
					badKey = !JSONKeyIsOk(input + (quotPosLeft + 1), (quotPosRight - quotPosLeft - 1));
					if (badKey) {
						break;
					}
					if (i + 1 == len) {
						badKey = BTRUE;
						break;
					}
					badKey = !strIsNull(input + (i + 1), len - i - 1);
					break;
				}
			}
		}
		if (badKey) {
			break;
		}
		if (colonCount != 1) {
			break;
		}
		if (quotationMarks != 2) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* Boolean ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringBooleanIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 3) {
			break;
		}
		int quotationMarks = 0; // ���ż���
		char ch = 0;
		int quotPosLeft = 0; // ������λ��
		int quotPosRight = 0; // ������λ��
		BOOLEAN badKey = BFALSE; // ���Ϸ�������
		BOOLEAN colonCount = 0;//����

		if (!isHasKey) {
			badKey = !strIsBoolean(input, len);
			if (badKey) {
				break;
			}
			res = BTRUE;
			break;
		}

		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (ch == '"') {
				quotationMarks++;
				if (quotationMarks % 2) {
					quotPosLeft = i;
				}
				else {
					quotPosRight = i;
				}
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ':') {
					colonCount++;
					if (input[i - 1] != '"') {
						badKey = BTRUE;
						break;
					}
					badKey = !JSONKeyIsOk(input + (quotPosLeft + 1), (quotPosRight - quotPosLeft - 1));
					if (badKey) {
						break;
					}
					if (i + 1 == len) {
						badKey = BTRUE;
						break;
					}
					badKey = !strIsBoolean(input + (i + 1), len - i - 1);
					break;
				}
			}
		}
		if (badKey) {
			break;
		}
		if (colonCount != 1) {
			break;
		}
		if (quotationMarks != 2) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* String ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringStringIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 1) {
			break;
		}
		int quotationMarks = 0; // ���ż���
		char ch = 0;
		int quotPosLeft = 0; // ������λ��
		int quotPosRight = 0; // ������λ��
		BOOLEAN badKey = BFALSE; // ���Ϸ�������
		BOOLEAN colonCount = 0;//����

		if (!isHasKey) {
			badKey = !strIsString(input, len);
			if (badKey) {
				break;
			}
			res = BTRUE;
			break;
		}

		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (ch == '"') {
				quotationMarks++;
				if (quotationMarks % 2) {
					quotPosLeft = i;
				}
				else {
					quotPosRight = i;
				}
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ':') {
					colonCount++;
					if (input[i - 1] != '"') {
						badKey = BTRUE;
						break;
					}
					badKey = !JSONKeyIsOk(input + (quotPosLeft + 1), (quotPosRight - quotPosLeft - 1));
					if (badKey) {
						break;
					}
					if (i + 1 == len) {
						badKey = BTRUE;
						break;
					}
					badKey = !strIsString(input + (i + 1), len - i - 1);
					if (badKey) {
						break;
					}
				}
			}
		}
		if (badKey) {
			break;
		}
		if (colonCount != 1) {
			break;
		}
		if (quotationMarks != 4) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* Array ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringArrayIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 1) {
			break;
		}
		int quotationMarks = 0; // ���ż���
		char ch = 0;
		int quotPosLeft = 0; // ������λ��
		int quotPosRight = 0; // ������λ��
		BOOLEAN badKey = BFALSE; // ���Ϸ�������
		BOOLEAN colonCount = 0;//����
		if (!isHasKey) {
			badKey = !strIsArray(input, len);
			if (badKey) {
				break;
			}
			res = BTRUE;
			break;
		}

		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (ch == '"') {
				quotationMarks++;
				if (quotationMarks % 2) {
					quotPosLeft = i;
				}
				else {
					quotPosRight = i;
				}
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ':') {
					colonCount++;
					if (input[i - 1] != '"') {
						badKey = BTRUE;
						break;
					}
					badKey = !JSONKeyIsOk(input + (quotPosLeft + 1), (quotPosRight - quotPosLeft - 1));
					if (badKey) {
						break;
					}
					if (i + 1 == len) {
						badKey = BTRUE;
						break;
					}

					badKey = !strIsArray(input + (i + 1), len - i - 1);
					break;
				}
			}
		}

		if (badKey) {
			break;
		}
		if (colonCount != 1) {
			break;
		}
		if (quotationMarks != 2) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* Object ���ͼ�ֵ���ַ�����ʽ�Ƿ�Ϸ�
* @param	input char* ������ַ���
* @param	len		int	  ����
* @param	isHasKey	BOOLEAN �Ƿ������
* @return	BOOLEAN		�ַ����Ϸ�
*/
BOOLEAN JSONStringObjectIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 1) {
			break;
		}
		int quotationMarks = 0; // ���ż���
		char ch = 0;
		int quotPosLeft = 0; // ������λ��
		int quotPosRight = 0; // ������λ��
		BOOLEAN badKey = BFALSE; // ���Ϸ�������
		BOOLEAN colonCount = 0;//����
		if (!isHasKey) {
			badKey = !strIsObject(input, len);
			if (badKey) {
				break;
			}
			res = BTRUE;
			break;
		}

		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (ch == '"') {
				quotationMarks++;
				if (quotationMarks % 2) {
					quotPosLeft = i;
				}
				else {
					quotPosRight = i;
				}
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ':') {
					colonCount++;
					if (input[i - 1] != '"') {
						badKey = BTRUE;
						break;
					}
					badKey = !JSONKeyIsOk(input + (quotPosLeft + 1), (quotPosRight - quotPosLeft - 1));
					if (badKey) {
						break;
					}
					if (i + 1 == len) {
						badKey = BTRUE;
						break;
					}

					badKey = !strIsObject(input + (i + 1), len - i - 1);
					break;
				}
			}
		}

		if (badKey) {
			break;
		}
		if (colonCount != 1) {
			break;
		}
		if (quotationMarks != 2) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* ȥ���ַ����ж���Ķ���
* @param	input	char* ��Ҫȥ���ŵ��ַ���
* @return	char*	ȥ���ź���ַ���
*/
char* JSONStringRemoveComma(char* input /* in */) {
	char* output = NULL;
	do {
		if (!input || !strlen(input)) {
			break;
		}
		output = (char*)malloc(strlen(input) + 1);
		if (!output) {
			break;
		}
		memset(output, 0, strlen(input) + 1);
		// ���ż���
		int quotationMarks = 0;
		char ch = 0;
		int j = 0;
		int len = strlen(input);
		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (input[i] == '"') {
				quotationMarks++;
			}
			if (quotationMarks % 2 == 0) {
				if (ch == ',') {
					if (i + 1 < len) {
						if (((input[i+1] & 0xFF) == ']') || ((input[i+1] & 0xFF) == '}')) {
							continue;
						}
					}
				}
				output[j] = input[i];
				j++;
			}
			else {
				output[j] = input[i];
				j++;
			}
		}
	} while (0);
	return output;
}

/*
* �ж� ���Ƿ���Ч
* @param	input	char* ����ļ�
* @param	len		int	  ����
*/
BOOLEAN JSONKeyIsOk(char* input /* in */, int len /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 0) {
			break;
		}
		BOOLEAN isBad = BFALSE;
		char ch = 0;
		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (0 <= ch && ch < 0x20) {
				isBad = BTRUE;
			}
		}
		if (isBad) {
			break;
		}
		res = BTRUE;
	} while (0);
	return res;
}

/*
* json �ַ���ȥ�ո�Ȳ��ɼ��ַ�
* @param	input	char*	��Ҫȥ�ո���ַ���
* @return	char*	ȥ�ո����ַ���
*/
char* JSONStringTrim(char* input /* in */) {
	char* output = NULL;
	do {
		if (!input || !strlen(input)) {
			break;
		}
		output = (char*)malloc(strlen(input) + 1);
		if (!output) {
			break;
		}
		memset(output, 0, strlen(input) + 1);
		// ���ż���
		int quotationMarks = 0;
		char ch = 0;
		int j = 0;
		int len = strlen(input);
		for (int i = 0; i < len; i++) {
			ch = input[i] & 0xFF;
			if (input[i] == '"') {
				quotationMarks++;
			}
			if (quotationMarks % 2 == 0) {
				if (ch >= 0x21 && ch <= 0x7D || ch < 0) {
					output[j] = input[i];
					j++;
				}
			}
			else {
				output[j] = input[i];
				j++;
			}
		}
		/*char* tmp = JSONStringRemoveComma(output);
		free(output);
		output = tmp;*/
	} while (0);
	return output;
}

/*
* �ж� json �ַ����Ƿ�Ϸ�
* @param	input	char*	��Ҫ�������ַ���
* @return	BOOLEAN			���ϸ�ʽҪ�󣬷��� BTRUE ���򷵻� BFALSE
*/
BOOLEAN JSONStringIsFormat(char* input /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input) {
			break;
		}
		res = JSONStringObjectIsFormat(input, strlen(input), BFALSE);
	} while (0);
	return res;
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
/*
* ���� md5 ���ܺ���ַ���
* @param input ��Ҫ���ܵ��ַ���
* @param output ���ܺ���ַ������ڴ��С������33���ֽ�
* @return void
*/
void encryptionStr(char *input /* in */, char *output /* out */) {
	MD5_CTX md5;
	int i = 0;
	char decrypt[16] = { 0 };
	char tmp[3] = { 0 };
	do {
		if (!input || !output) {
			break;
		}
		MD5Init(&md5);
		MD5Update(&md5, input, strlen((char *)input));
		MD5Final(&md5, decrypt);
		for (i = 0; i<16; i++)
		{
			memset(tmp, 0, 3);
			sprintf(tmp, "%02x", decrypt[i] & 0xFF);
			strcat(output, tmp);
		}
	} while (0);
}

/*
* �����ַ���������hashֵ
* @param input ��Ҫ������ַ���
* @return unsigned long int ������
*/
unsigned long int getHashVal(char *input /* in */) {
	unsigned long int seed = 7;
	unsigned  long int hash = 0;
	while (*input != '\0')
	{
		hash += hash * seed + (*input) & 0xFF;
		input++;
	}
	return hash % HASH_MAX;
}

/* 
* ���� json key ֵ��ת���� int ֵ
* @param	key json ��
* @return	int
*/
int JSONGetHashIndex(char *key /* in */) {
	int idx = -1;
	char buf[33] = { 0 };
	do {
		if (!key) {
			break;
		}
		encryptionStr(key, buf);
		idx = getHashVal(buf);
	} while (0);
	//printf("����: %s, ����: %d\n", key, idx);
	return idx;
}

/*
* ����ַ���
* @param	input	������ַ���
* @return	char*	������ַ����ڴ�
*/
char* deepCloneString(char* input /* in */) {
	char* pRes = NULL;
	do {
		if (!input) {
			break;
		}
		pRes = (char*)malloc(strlen(input) + 1);
		if (!pRes) {
			break;
		}
		memset(pRes, 0, strlen(input) + 1);
		strcat(pRes, input);
	} while (0);
	return pRes;
}

/*
* ���� Object �ն���
* @param	key		char* ������
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreateObjectNode(char* key /* in */) {
	pJsonObjectNode pObject = NULL;
	do {
		pObject = (pJsonObjectNode)malloc(sizeof(JsonObjectNode));
		if (!pObject) {
			// json�����ڴ����ʧ��
			break;
		}
		memset(pObject, 0, sizeof(JsonObjectNode));
		if (key) {
			pObject->node.keyName = deepCloneString(key);
			if (!pObject->node.keyName) {
				// ��������ʧ�ܣ���ڵ��������
				JSONDestroyObjectNode(pObject);
				break;
			}
		}
		pObject->node.type = JSONTYPEOBJECT;
	} while (0);
	return pObject;
}

/*
* ���� Number �ڵ�
* @param	key		char*	������
* @param	value	double	��ֵ
* @return	pJsonNumberNode Number�ڵ�ָ��
*/
pJsonNumberNode JSONCreateNumberNode(char* key /* in */, double value /* in */) {
	pJsonNumberNode pNode = NULL;

	do {
		pNode = (pJsonNumberNode)malloc(sizeof(JsonNumberNode));
		if (!pNode) {
			break;
		}
		memset(pNode, 0, sizeof(JsonNumberNode));
		if (key) {
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				// ��������ʧ�ܣ���ڵ��������
				JSONDestroyNumberNode(pNode);
				break;
			}
		}
		pNode->node.type = JSONTYPENUMBER;
		pNode->value = value;
	} while (0);

	return pNode;
}

/*
* ���� String �ڵ�
* @param	key		char* ������
* @param	value	char* ��ֵ
* @return	pJsonStringNode String�ڵ�ָ��
*/
pJsonStringNode JSONCreateStringNode(char* key /* in */, char* value /* in */) {
	pJsonStringNode pNode = NULL;

	do {
		pNode = (pJsonStringNode)malloc(sizeof(JsonStringNode));
		if (!pNode) {
			break;
		}
		memset(pNode, 0, sizeof(JsonStringNode));
		if (key) {
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				// ��������ʧ�ܣ���ڵ��������
				JSONDestroyStringNode(pNode);
				break;
			}
		}
		pNode->node.type = JSONTYPESTRING;
		pNode->value = deepCloneString(value);
	} while (0);

	return pNode;
}

/*
* ���� Array ���������
* @param	key		char* ������
* @return	pJsonArrayNode Array�ڵ�ָ��
*/
pJsonArrayNode JSONCreateArrayNode(char* key /* in */) {
	pJsonArrayNode pNode = NULL;

	do {
		pNode = (pJsonArrayNode)malloc(sizeof(JsonArrayNode));
		if (!pNode) {
			break;
		}
		memset(pNode, 0, sizeof(JsonArrayNode));
		if (key) {
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				// ��������ʧ�ܣ���ڵ��������
				JSONDestroyArrayNode(pNode);
				break;
			}
		}
		pNode->node.type = JSONTYPEARRAY;
	} while (0);
	return pNode;
}

/*
* ���� null �ڵ�
* @param	key		char*	������
* @return	pJsonNullNode null�ڵ�ָ��
*/
pJsonNullNode JSONCreateNullNode(char* key /* in */) {
	pJsonNullNode pNode = NULL;

	do {
		pNode = (pJsonNullNode)malloc(sizeof(JsonNullNode));
		if (!pNode) {
			break;
		}
		memset(pNode, 0, sizeof(JsonNullNode));
		if (key) {
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				// ��������ʧ�ܣ���ڵ��������
				JSONDestroyNullNode(pNode);
				break;
			}
		}
		pNode->node.type = JSONTYPENULL;
		pNode->value = (int)null;
	} while (0);

	return pNode;
}

/*
* ���� Boolean �ڵ�
* @param	key		char*	������
* @param	value	BOOLEAN	��ֵ
* @return	pJsonBooleanNode Boolean�ڵ�ָ��
*/
pJsonBooleanNode JSONCreateBooleanNode(char* key /* in */, BOOLEAN value /* in */) {
	pJsonBooleanNode pNode = NULL;

	do {
		pNode = (pJsonBooleanNode)malloc(sizeof(JsonBooleanNode));
		if (!pNode) {
			break;
		}
		memset(pNode, 0, sizeof(JsonBooleanNode));
		if (key) {
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				// ��������ʧ�ܣ���ڵ��������
				JSONDestroyBooleanNode(pNode);
				break;
			}
		}
		pNode->node.type = JSONTYPEBOOLEAN;
		pNode->value = value && 0x01;
	} while (0);

	return pNode;
}

/*
* ���� Object �ն���
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreate() {
	return JSONCreateObjectNode(NULL);
}

/*
* ���� Array ������
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONCreateArray() {
	return JSONCreateArrayNode(NULL);
}

/*
* ��ʽ�� json ����
* @param	input	char* ��Ҫ��ʽ�����ַ���
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONParseArray(char* input /* in */) {
	pJsonArrayNode pArray = NULL;
	do {
		if (!input || strlen(input) < 2) {
			break;
		}
		int len = strlen(input);
		// �ַ�����ʽ�Ѿ�����У�飬�������迼�Ǹ�ʽ����
		pArray = JSONCreateArray();
		if (!pArray || len == 2) {
			break;
		}
		int idx = 0;
		char* element = NULL;
		for (int i = 1; i < len - 1; i++) {
			if (input[i] == '\"') {
				// Ԫ�����ַ���
				idx = i + 1;
				while (idx <= len - 2) {
					if (input[idx] == '\"') {
						break;
					}
					idx++;
				}
				element = (char*)malloc(idx - i);
				if (!element) {
					break;
				}
				memset(element, 0, idx - i);
				memcpy(element, input + i + 1, idx - i - 1);
				JSONArrayPushString(pArray, element);
				free(element);
			}
			else if (input[i] == 'n') {
				JSONArrayPushNull(pArray);
				idx = i + 3;
			}
			else if (input[i] == 't' || input[i] == 'f') {
				if (input[i] == 't') {
					JSONArrayPushBoolean(pArray, BTRUE);
					idx = i + 3;
				}
				else {
					JSONArrayPushBoolean(pArray, BFALSE);
					idx = i + 4;
				}
			}
			else if (input[i] >= '0' && input[i] <= '9') {
				double num = 0;
				idx = i + 1;
				while (idx <= len - 2) {
					if (input[idx] == ',') {
						break;
					}
					idx++;
				}
				idx--;
				sscanf(input + i, "%lf", &num);
				JSONArrayPushNumber(pArray, num);
			}
			else if (input[i] == '[') {
				idx = i + 1;
				int markCount = 1;
				int quotCount = 0;
				while (idx <= len - 2) {
					if (input[idx] == '\"') {
						quotCount++;
					}
					if (quotCount % 2 == 0) {
						if (input[idx] == '[') {
							markCount++;
						}
						else if (input[idx] == ']') {
							markCount--;
						}
					}
					if (markCount == 0) {
						break;
					}
					idx++;
				}
				element = (char*)malloc(idx - i + 2);
				if (!element) {
					break;
				}
				memset(element, 0, idx - i + 2);
				memcpy(element, input + i, idx - i + 1);
				pJsonArrayNode pNode = JSONParseArray(element);
				free(element);
				if (pNode) {
					JSONArrayPushArray(pArray, pNode);
				}
			}
			else if (input[i] == '{') {
				idx = i + 1;
				int markCount = 1;
				int quotCount = 0;
				while (idx <= len - 2) {
					if (input[idx] == '\"') {
						quotCount++;
					}
					if (quotCount % 2 == 0) {
						if (input[idx] == '{') {
							markCount++;
						}
						else if (input[idx] == '}') {
							markCount--;
						}
					}
					if (markCount == 0) {
						break;
					}
					idx++;
				}
				element = (char*)malloc(idx - i + 2);
				if (!element) {
					break;
				}
				memset(element, 0, idx - i + 2);
				memcpy(element, input + i, idx - i + 1);
				pJsonObjectNode pNode = JSONParseObject(element);
				free(element);
				if (pNode) {
					JSONArrayPushObject(pArray, pNode);
				}
			}
			else {
				break;
			}
			i = idx + 1;
		}
	} while (0);
	return pArray;
}

/*
* ��ʽ�� json ����
* @param	input	char* ��Ҫ��ʽ�����ַ���
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONParseObject(char* input /* in */) {
	pJsonObjectNode pObject = NULL;
	do {
		if (!input || strlen(input) < 2) {
			break;
		}
		int len = strlen(input);
		// �ַ�����ʽ�Ѿ�����У�飬�������迼�Ǹ�ʽ����
		pObject = JSONCreate();
		if (!pObject || len == 2) {
			break;
		}
		int idx = 0;
		for (int i = 1; i < len - 1; i++) {
			if (input[i] == '\"') {
				idx = i + 1;
				while (idx <= len - 2) {
					if (input[idx] == '\"') {
						break;
					}
					idx++;
				}
				char* key = (char*)malloc(idx - i);
				if (!key) {
					break;
				}
				memset(key, 0, idx - i);
				memcpy(key, input + i + 1, idx - i - 1);
				///////////////////////// �ǵ����� key //////////////////////////
				idx += 2;
				int valIdx = 0;
				char* value = NULL;
				if (input[idx] == '\"') {
					// ֵ���ַ���
					valIdx = idx + 1;
					while (valIdx <= len - 2) {
						if (input[valIdx] == '\"') {
							break;
						}
						valIdx++;
					}
					if (valIdx - idx == 2) {
						// ���ַ���
						JSONSetStringAttr(pObject, key, "");
					}
					else {
						value = malloc(valIdx - idx);
						if (!value) {
							free(key);
							break;
						}
						memset(value, 0, valIdx - idx);
						memcpy(value, input + (idx + 1), valIdx - idx - 1);
						JSONSetStringAttr(pObject, key, value);
						free(value);
					}
				}
				else if (input[idx] == 'n') {
					// ֵ�� null
					JSONSetNullAttr(pObject, key);
					valIdx = idx + 3;
				}
				else if (input[idx] == 't' || input[idx] == 'f') {
					// ֵ�� boolean
					if (input[idx] == 't') {
						JSONSetBooleanAttr(pObject, key, BTRUE);
						valIdx = idx + 3;
					}
					else {
						JSONSetBooleanAttr(pObject, key, BFALSE);
						valIdx = idx + 4;
					}
				}
				else if (input[idx] >= '0' && input[idx] <= '9') {
					// ֵ�� number
					valIdx = idx + 1;
					while (valIdx <= len - 2) {
						if (input[valIdx] == ',') {
							break;
						}
						valIdx++;
					}
					valIdx--;
					double num = 0;
					sscanf(input + idx, "%lf", &num);
					JSONSetNumberAttr(pObject, key, num);
				}
				else if (input[idx] == '[') {
					// ֵ�� array
					valIdx = idx + 1;
					int markCount = 1;
					int quotCount = 0;
					while (valIdx <= len - 2) {
						if (input[valIdx] == '\"') {
							quotCount++;
						}
						if (quotCount % 2 == 0) {
							if (input[valIdx] == '[') {
								markCount++;
							}
							else if(input[valIdx] == ']'){
								markCount--;
							}
						}
						if (markCount == 0) {
							break;
						}
						valIdx++;
					}
					value = (char*)malloc(valIdx - idx + 2);
					if (!value) {
						free(key);
						break;
					}
					memset(value, 0, valIdx - idx + 2);
					memcpy(value, input + idx, valIdx - idx + 1);
					pJsonArrayNode pNode = JSONParseArray(value);
					free(value);
					if (pNode) {
						JSONSetArrayAttr(pObject, key, pNode, BFALSE);
					}
				}
				else if (input[idx] == '{') {
					// ֵ�� object
					valIdx = idx + 1;
					int markCount = 1;
					int quotCount = 0;
					while (valIdx <= len - 2) {
						if (input[valIdx] == '\"') {
							quotCount++;
						}
						if (quotCount % 2 == 0) {
							if (input[valIdx] == '{') {
								markCount++;
							}
							else if (input[valIdx] == '}') {
								markCount--;
							}
						}
						if (markCount == 0) {
							break;
						}
						valIdx++;
					}
					value = (char*)malloc(valIdx - idx + 2);
					if (!value) {
						free(key);
						break;
					}
					memset(value, 0, valIdx - idx + 2);
					memcpy(value, input + idx, valIdx - idx + 1);
					pJsonObjectNode pNode = JSONParseObject(value);
					free(value);
					if (pNode) {
						JSONSetObjectAttr(pObject, key, pNode, BFALSE);
					}
				}
				else {
					// ����������ͷż�
					free(key);
					break;
				}
				free(key);
				i = valIdx + 1;
			}
			else {
				break;
			}
		}
	} while (0);
	return pObject;
}

/*
* json ��ʽ���������� json �ַ���ת���� json ����
* @param	input		json �ַ���
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONParse(char* input /* in */) {
	pJsonObjectNode pObject = NULL;
	do {
		if (!input) {
			break;
		}
		char* str = JSONStringTrim(input);
		if (!str) {
			break;
		}
		if (!JSONStringIsFormat(str)) {
			free(str);
			break;
		}
		
		pObject = JSONParseObject(str);
		free(str);
	} while (0);
	return pObject;
}

/*
* json ���л����� json ����ת���� json �ַ���
* @param	pNode pJsonNode			json �ڵ�
* @param	output	char**			�����ַ�����ָ��
* @return	void
*/
void JSONStringify(pJsonNode pNode /* in */, char** output /* out */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->type == JSONTYPENUMBER) {
			*output = JSONStringifyNumberNode((pJsonNumberNode)pNode, BFALSE);
		}
		else if (pNode->type == JSONTYPESTRING) {
			*output = JSONStringifyStringNode((pJsonStringNode)pNode, BFALSE);
		}
		else if (pNode->type == JSONTYPEARRAY) {
			*output = JSONStringifyArrayNode((pJsonArrayNode)pNode, BFALSE);
		}
		else if (pNode->type == JSONTYPEOBJECT) {
			*output = JSONStringifyObjectNode((pJsonObjectNode)pNode, BFALSE);
		}
		else if (pNode->type == JSONTYPENULL) {
			*output = JSONStringifyNullNode((pJsonNullNode)pNode, BFALSE);
		}
		else if (pNode->type == JSONTYPEBOOLEAN) {
			*output = JSONStringifyBooleanNode((pJsonBooleanNode)pNode, BFALSE);
		}
	} while (0);
}

/*
* ���ֽڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonNumberNode ���ֽڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyNumberNode(pJsonNumberNode pNode, BOOLEAN isContainsKey) {
	char* pStr = NULL;
	char buf[64] = { 0 };
	int num = 0;
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENUMBER) {
			break;
		}
		num = (int)pNode->value;
		if (num == pNode->value) {
			sprintf(buf, "%d", num);
		}
		else {
			sprintf(buf, "%f", pNode->value);
			for (int i = strlen(buf); i > 0; i--) {
				if (buf[i] == 0 || (buf[i] & 0xFF) == '0') {
					buf[i] = 0;
				}
				else {
					break;
				}
			}
			if (buf[strlen(buf) - 1] == '.') {
				buf[strlen(buf) - 1] = 0;
			}
		}
		if (isContainsKey) {
			if (pNode->node.keyName && strlen(pNode->node.keyName)) {
				pStr = (char*)malloc(strlen(pNode->node.keyName) + strlen(buf) + 4);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, strlen(pNode->node.keyName) + strlen(buf) + 4);
				sprintf(pStr, "\"%s\":", pNode->node.keyName);
			}
			else {
				pStr = (char*)malloc(strlen(buf) + 1);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, strlen(buf) + 1);
			}
		}
		else {
			pStr = (char*)malloc(strlen(buf) + 1);
			if (!pStr) {
				break;
			}
			memset(pStr, 0, strlen(buf) + 1);
		}
		strcat(pStr, buf);
	} while (0);
	return pStr;
}

/*
* �ַ����ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonStringNode �ַ����ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyStringNode(pJsonStringNode pNode, BOOLEAN isContainsKey) {
	char* pStr = NULL;
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPESTRING) {
			break;
		}
		if (isContainsKey) {
			if (pNode->node.keyName && strlen(pNode->node.keyName)) {
				if (pNode->value) {
					int len = strlen(pNode->node.keyName) + strlen(pNode->value) + 6;
					pStr = (char*)malloc(len);
					if (!pStr) {
						break;
					}
					memset(pStr, 0, len);
					sprintf(pStr, "\"%s\":\"%s\"", pNode->node.keyName, pNode->value);
				}
				else {
					int len = strlen(pNode->node.keyName) + 8;
					pStr = (char*)malloc(len);
					if (!pStr) {
						break;
					}
					memset(pStr, 0, len);
					sprintf(pStr, "\"%s\":null", pNode->node.keyName);
				}
			}
			else {
				if (pNode->value) {
					int len = strlen(pNode->value) + 3;
					pStr = (char*)malloc(len);
					if (!pStr) {
						break;
					}
					memset(pStr, 0, len);
					sprintf(pStr, "\"%s\"", pNode->value);
				}
				else {
					int len = 5;
					pStr = (char*)malloc(len);
					if (!pStr) {
						break;
					}
					memset(pStr, 0, len);
					sprintf(pStr, "null");
				}
			}
		}
		else {
			if (pNode->value) {
				int len = strlen(pNode->value) + 3;
				pStr = (char*)malloc(len);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, len);
				sprintf(pStr, "\"%s\"", pNode->value);
			}
			else {
				int len = 5;
				pStr = (char*)malloc(len);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, len);
				sprintf(pStr, "null");
			}
		}
	} while (0);
	return pStr;
}

/*
* ����ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonArrayNode ����ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyArrayNode(pJsonArrayNode pNode, BOOLEAN isContainsKey) {
	char* pStr = NULL;
	char tmpBuf[TMP_BUF_SIZE] = { 0 };
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEARRAY) {
			break;
		}
		if (isContainsKey) {
			if (pNode->node.keyName && strlen(pNode->node.keyName)) {
				int len = strlen(pNode->node.keyName) + 5;	// ��Ҫ�������ð�ŵ�
				if (len > TMP_BUF_SIZE) {
					// ���Ƴ��ȹ�����Ҫ�����ڴ������
					pStr = (char*)malloc(len);
					if (!pStr) {
						break;
					}
					memset(pStr, 0, len);
					sprintf(pStr, "\"%s\":[", pNode->node.keyName);
				}
				else {
					sprintf(tmpBuf, "\"%s\":[", pNode->node.keyName);
				}
			}
			else {
				sprintf(tmpBuf, "[");
			}
		}
		else {
			sprintf(tmpBuf, "[");
		}
		// �������л�����Ԫ��
		if (pNode->size && pNode->array) {
			for (int i = 0; i < pNode->size; i++) {
				pJsonNode pCur = pNode->array[i];
				if (pCur) {
					char* pTmpStringify = NULL;
					int tmpLen = 0;
					if (pCur->type == JSONTYPENUMBER) {
						pTmpStringify = JSONStringifyNumberNode((pJsonNumberNode)pCur, BFALSE);
					}
					else if (pCur->type == JSONTYPESTRING) {
						pTmpStringify = JSONStringifyStringNode((pJsonStringNode)pCur, BFALSE);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						pTmpStringify = JSONStringifyArrayNode((pJsonArrayNode)pCur, BFALSE);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						pTmpStringify = JSONStringifyObjectNode((pJsonObjectNode)pCur, BFALSE);
					}
					else if (pCur->type == JSONTYPENULL) {
						pTmpStringify = JSONStringifyNullNode((pJsonNullNode)pCur, BFALSE);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						pTmpStringify = JSONStringifyBooleanNode((pJsonBooleanNode)pCur, BFALSE);
					}
					if (pTmpStringify) {
						tmpLen = strlen(pTmpStringify);
						tmpLen += strlen(tmpBuf) + 1;
						if (tmpLen >= TMP_BUF_SIZE) {
							// ���������ݷ���������������ʱ���������
							// ���·����ڴ�������
							char* _pTmp = pStr;
							int _tmpLen = 0;
							if (_pTmp) {
								_tmpLen = strlen(_pTmp);
							}
							_tmpLen += strlen(tmpBuf) + strlen(pTmpStringify) + 2;
							pStr = (char*)malloc(_tmpLen);
							if (!pStr) {
								free(_pTmp);
								break;
							}
							memset(pStr, 0, _tmpLen);
							if (_pTmp) {
								strcat(pStr, _pTmp);
								free(_pTmp);
								_pTmp = NULL;
							}
							strcat(pStr, tmpBuf);
							strcat(pStr, pTmpStringify);
							strcat(pStr, ",");
							memset(tmpBuf, 0, TMP_BUF_SIZE);
						}
						else {
							// �����ݴ��뻺����
							strcat(tmpBuf, pTmpStringify);
							strcat(tmpBuf, ",");
						}
						free(pTmpStringify);
						pTmpStringify = NULL;
					}
				}
			}
		}
		// ׷�ӽ�β
		if (strlen(tmpBuf)) {
			char* p = pStr;
			int tLen = 0;
			if (p) {
				tLen = strlen(p);
			}
			tLen += strlen(tmpBuf) + 2;
			pStr = malloc(tLen);
			if (!pStr) {
				free(p);
				break;
			}
			memset(pStr, 0, tLen);
			if (p) {
				strcat(pStr, p);
				free(p);
			}
			strcat(pStr, tmpBuf);
			if (pStr[strlen(pStr) - 1] == ',') {
				pStr[strlen(pStr) - 1] = ']';
			}
			else {
				pStr[strlen(pStr)] = ']';
			}
			
			memset(tmpBuf, 0, TMP_BUF_SIZE);
		}
		else {
			if (strlen(pStr)) {
				
				if (pStr[strlen(pStr) - 1] == ',') {
					pStr[strlen(pStr) - 1] = ']';
				}
				else {
					char* p = pStr;
					int tLen = 0;
					tLen += strlen(p) + 2;
					pStr = malloc(tLen);
					if (!pStr) {
						free(p);
						break;
					}
					memset(pStr, 0, tLen);
					strcat(pStr, p);
					free(p);
					pStr[strlen(pStr)] = ']';
					memset(tmpBuf, 0, TMP_BUF_SIZE);
				}
			}
		}

	} while (0);
	return pStr;
}

/*
* ����ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonObjectNode ����ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyObjectNode(pJsonObjectNode pNode, BOOLEAN isContainsKey) {
	char* pStr = NULL;
	char tmpBuf[TMP_BUF_SIZE] = { 0 };
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (isContainsKey) {
			if (pNode->node.keyName && strlen(pNode->node.keyName)) {
				int len = strlen(pNode->node.keyName) + 5;	// ��Ҫ�������ð�ŵ�
				if (len > TMP_BUF_SIZE) {
					// ���Ƴ��ȹ�����Ҫ�����ڴ������
					pStr = (char*)malloc(len);
					if (!pStr) {
						break;
					}
					memset(pStr, 0, len);
					sprintf(pStr, "\"%s\":{", pNode->node.keyName);
				}
				else {
					sprintf(tmpBuf, "\"%s\":{", pNode->node.keyName);
				}
			}
			else {
				sprintf(tmpBuf, "{");
			}
		}
		else {
			sprintf(tmpBuf, "{");
		}
		// �������л����Խڵ�
		for (int i = 0; i < HASH_MAX; i++) {
			if (pNode->table[i]) {
				pJsonNode pCur = pNode->table[i];
				while (pCur) {
					char* pTmpStringify = NULL;
					int tmpLen = 0;
					if (pCur->type == JSONTYPENUMBER) {
						pTmpStringify = JSONStringifyNumberNode((pJsonNumberNode)pCur, BTRUE);
					}
					else if (pCur->type == JSONTYPESTRING) {
						pTmpStringify = JSONStringifyStringNode((pJsonStringNode)pCur, BTRUE);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						pTmpStringify = JSONStringifyArrayNode((pJsonArrayNode)pCur, BTRUE);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						pTmpStringify = JSONStringifyObjectNode((pJsonObjectNode)pCur, BTRUE);
					}
					else if (pCur->type == JSONTYPENULL) {
						pTmpStringify = JSONStringifyNullNode((pJsonNullNode)pCur, BTRUE);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						pTmpStringify = JSONStringifyBooleanNode((pJsonBooleanNode)pCur, BTRUE);
					}
					if (pTmpStringify) {
						tmpLen = strlen(pTmpStringify);
						tmpLen += strlen(tmpBuf) + 1;
						if (tmpLen >= TMP_BUF_SIZE) {
							// ���������ݷ���������������ʱ���������
							// ���·����ڴ�������
							char* _pTmp = pStr;
							int _tmpLen = 0;
							if (_pTmp) {
								_tmpLen = strlen(_pTmp);
							}
							_tmpLen += strlen(tmpBuf) + strlen(pTmpStringify) + 2;
							pStr = (char*)malloc(_tmpLen);
							if (!pStr) {
								free(_pTmp);
								break;
							}
							memset(pStr, 0, _tmpLen);
							if (_pTmp) {
								strcat(pStr, _pTmp);
								free(_pTmp);
								_pTmp = NULL;
							}
							strcat(pStr, tmpBuf);
							strcat(pStr, pTmpStringify);
							strcat(pStr, ",");
							memset(tmpBuf, 0, TMP_BUF_SIZE);
						}
						else {
							// �����ݴ��뻺����
							strcat(tmpBuf, pTmpStringify);
							strcat(tmpBuf, ",");
						}
						free(pTmpStringify);
						pTmpStringify = NULL;
					}
					pCur = pCur->next;
				}
			}
		}
		// ׷�ӽ�β
		if (strlen(tmpBuf)) {
			char* p = pStr;
			int tLen = 0;
			if (p) {
				tLen = strlen(p);
			}
			tLen += strlen(tmpBuf) + 2;
			pStr = malloc(tLen);
			if (!pStr) {
				free(p);
				break;
			}
			memset(pStr, 0, tLen);
			if (p) {
				strcat(pStr, p);
				free(p);
			}
			strcat(pStr, tmpBuf);
			if (pStr[strlen(pStr) - 1] == ',') {
				pStr[strlen(pStr) - 1] = '}';
			}
			else {
				pStr[strlen(pStr)] = '}';
			}

			memset(tmpBuf, 0, TMP_BUF_SIZE);
		}
		else {
			if (strlen(pStr)) {

				if (pStr[strlen(pStr) - 1] == ',') {
					pStr[strlen(pStr) - 1] = '}';
				}
				else {
					char* p = pStr;
					int tLen = 0;
					tLen += strlen(p) + 2;
					pStr = malloc(tLen);
					if (!pStr) {
						free(p);
						break;
					}
					memset(pStr, 0, tLen);
					strcat(pStr, p);
					free(p);
					pStr[strlen(pStr)] = '}';
					memset(tmpBuf, 0, TMP_BUF_SIZE);
				}
			}
		}

	} while (0);
	return pStr;
}

/*
* null �ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonNullNode null�ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyNullNode(pJsonNullNode pNode, BOOLEAN isContainsKey) {
	char* pStr = NULL;
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENULL) {
			break;
		}
		if (isContainsKey) {
			if (pNode->node.keyName && strlen(pNode->node.keyName)) {
				int len = strlen(pNode->node.keyName) + 8;
				pStr = (char*)malloc(len);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, len);
				sprintf(pStr, "\"%s\":", pNode->node.keyName);
			}
			else {
				pStr = (char*)malloc(5);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, 5);
			}
		}
		else {
			pStr = (char*)malloc(5);
			if (!pStr) {
				break;
			}
			memset(pStr, 0, 5);
		}
		strcat(pStr, "null");
	} while (0);
	return pStr;
}

/*
* Boolean �ڵ����л���������Ԫ�أ�����Ҫ������
* @param	pNode	pJsonBooleanNode Boolean�ڵ�
* @param	isContainsKey	BOOLEAN	�Ƿ������
* @return	char*	���л��ַ���
*/
char* JSONStringifyBooleanNode(pJsonBooleanNode pNode, BOOLEAN isContainsKey) {
	char* pStr = NULL;
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEBOOLEAN) {
			break;
		}
		if (isContainsKey) {
			if (pNode->node.keyName && strlen(pNode->node.keyName)) {
				int len = strlen(pNode->node.keyName) + 9;
				pStr = (char*)malloc(len);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, len);
				sprintf(pStr, "\"%s\":", pNode->node.keyName);
			}
			else {
				pStr = (char*)malloc(6);
				if (!pStr) {
					break;
				}
				memset(pStr, 0, 6);
			}
		}
		else {
			pStr = (char*)malloc(6);
			if (!pStr) {
				break;
			}
			memset(pStr, 0, 6);
		}

		if (pNode->value) {
			strcat(pStr, "true");
		}
		else {
			strcat(pStr, "false");
		}
	} while (0);
	return pStr;
}

/*
* �ж� json �Ƿ��������
* @param	pObject		json ����
* @param	key			��������
* @return	BOOLEAN		�Ƿ��������
*/
BOOLEAN JSONIsContainsAttr(pJsonObjectNode pObject /* in */, char* key /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key || !strlen(key)) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					res = BTRUE;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
	return res;
}

/*
* �� json ��������� Number���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @param	value		����ֵ
*/
void JSONSetNumberAttr(pJsonObjectNode pObject /* in */, char* key /* in */, double value /* in */) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonNumberNode pNode = JSONCreateNumberNode(key, value);
			if (!pNode) {
				// Number�ڵ��ڴ����ʧ��
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						((pJsonNumberNode)pCur)->value = value;
						break;
					}
					else if (pCur->type == JSONTYPESTRING) {
						JSONDestroyStringNode((pJsonStringNode)pCur);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pCur);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
					}
					else {
						break;
					}
					pJsonNumberNode pNode = JSONCreateNumberNode(key, value);
					if (!pNode) {
						// Number�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonNumberNode pNode = JSONCreateNumberNode(key, value);
					if (!pNode) {
						// Number�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �� json ��������� String���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @param	value		����ֵ
*/
void JSONSetStringAttr(pJsonObjectNode pObject /* in */, char* key /* in */, char* value /* in */) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		if (!value) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonStringNode pNode = JSONCreateStringNode(key, value);
			if (!pNode) {
				// String�ڵ��ڴ����ʧ��
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						JSONDestroyNumberNode((pJsonNumberNode)pCur);
					}
					else if (pCur->type == JSONTYPESTRING) {
						if (((pJsonStringNode)pCur)->value) {
							free(((pJsonStringNode)pCur)->value);
						}
						((pJsonStringNode)pCur)->value = deepCloneString(value);
						if (!((pJsonStringNode)pCur)->value) {
							// String�ڵ�ֵ�ڴ����ʧ��
							break;
						}
						break;
					}
					else if (pCur->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pCur);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
					}
					else {
						break;
					}
					pJsonStringNode pNode = JSONCreateStringNode(key, value);
					if (!pNode) {
						// String�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonStringNode pNode = JSONCreateStringNode(key, value);
					if (!pNode) {
						// String�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �� json ��������� Array���� ��ֵ������ӵ�����Ϊ������
* @param	pObject		json ����
* @param	key			��������
*/
void JSONSetEmptyArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonArrayNode pNode = JSONCreateArrayNode(key);
			if (!pNode) {
				// Array�ڵ��ڴ����ʧ��
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						JSONDestroyNumberNode((pJsonNumberNode)pCur);
					}
					else if (pCur->type == JSONTYPESTRING) {
						JSONDestroyStringNode((pJsonStringNode)pCur);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pCur);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
					}
					else {
						break;
					}
					pJsonArrayNode pNode = JSONCreateArrayNode(key);
					if (!pNode) {
						// Array�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonArrayNode pNode = JSONCreateArrayNode(key);
					if (!pNode) {
						// Array�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �� json ��������� Array���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @param	value		pJsonArrayNode	����ڵ�
* @param	isDeepClone	BOOLEAN �Ƿ������ȿ���
* @return	void
*/
void JSONSetArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonArrayNode pArray, BOOLEAN isDeepClone) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		if (!pArray) {
			break;
		}
		if (pArray->node.type != JSONTYPEARRAY) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonArrayNode pNode = NULL;
			if (isDeepClone) {
				pNode = JSONArrayDeepClone(pArray);
			}
			else {
				pNode = pArray;
			}
			if (!pNode) {
				// Array�ڵ��ڴ����ʧ��
				break;
			}
			// ���¶�����������Ƹ�ֵ
			if (pNode->node.keyName) {
				free(pNode->node.keyName);
			}
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				JSONDestroyArrayNode(pNode);
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						JSONDestroyNumberNode((pJsonNumberNode)pCur);
					}
					else if (pCur->type == JSONTYPESTRING) {
						JSONDestroyStringNode((pJsonStringNode)pCur);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						if (pCur == (pJsonNode)pArray) {
							break;
						}
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pCur);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
					}
					else {
						break;
					}
					pJsonArrayNode pNode = NULL;
					if (isDeepClone) {
						pNode = JSONArrayDeepClone(pArray);
					}
					else {
						pNode = pArray;
					}
					if (!pNode) {
						// Array�ڵ��ڴ����ʧ��
						break;
					}
					// ���¶�����������Ƹ�ֵ
					if (pNode->node.keyName) {
						free(pNode->node.keyName);
					}
					pNode->node.keyName = deepCloneString(key);
					if (!pNode->node.keyName) {
						JSONDestroyArrayNode(pNode);
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonArrayNode pNode = NULL;
					if (isDeepClone) {
						pNode = JSONArrayDeepClone(pArray);
					}
					else {
						pNode = pArray;
					}
					if (!pNode) {
						// Array�ڵ��ڴ����ʧ��
						break;
					}
					// ���¶�����������Ƹ�ֵ
					if (pNode->node.keyName) {
						free(pNode->node.keyName);
					}
					pNode->node.keyName = deepCloneString(key);
					if (!pNode->node.keyName) {
						JSONDestroyArrayNode(pNode);
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �� json ��������� Object���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @param	value		����ֵ
* @param	isDeepClone	BOOLEAN �Ƿ������ȿ���
* @return	void
*/
void JSONSetObjectAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonObjectNode value /* in */, BOOLEAN isDeepClone) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		// �Լ�������Ϊ�Լ����ӽڵ�
		if (pObject == value) {
			break;
		}
		if (value->node.type != JSONTYPEOBJECT) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonObjectNode pNode = NULL;
			if (isDeepClone) {
				pNode = JSONObjectDeepClone(value);
			}
			else {
				pNode = value;
			}
			if (!pNode) {
				break;
			}
			pNode->node.keyName = deepCloneString(key);
			if (!pNode->node.keyName) {
				JSONDestroyObjectNode(pNode);
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						JSONDestroyNumberNode((pJsonNumberNode)pCur);
					}
					else if (pCur->type == JSONTYPESTRING) {
						JSONDestroyStringNode((pJsonStringNode)pCur);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						// �ڵ��Ѵ��ڣ�����Ҫ�ظ����
						if (pCur == (pJsonNode)value) {
							break;
						}
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pCur);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
					}
					else {
						break;
					}
					pJsonObjectNode pNode = NULL;
					if (isDeepClone) {
						pNode = JSONObjectDeepClone((pJsonObjectNode)value);
					}
					else {
						pNode = value;
					}
					if (!pNode) {
						// Object�ڵ��ڴ����ʧ��
						break;
					}
					// ���¶�Object�������Ƹ�ֵ
					if (pNode->node.keyName) {
						free(pNode->node.keyName);
					}
					pNode->node.keyName = deepCloneString(key);
					if (!pNode->node.keyName) {
						JSONDestroyObjectNode(pNode);
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonObjectNode pNode = NULL;
					if (isDeepClone) {
						pNode = JSONObjectDeepClone(value);
					}
					else {
						pNode = value;
					}
					if (!pNode) {
						// Object�ڵ��ڴ����ʧ��
						break;
					}
					// ���¶�����������Ƹ�ֵ
					if (pNode->node.keyName) {
						free(pNode->node.keyName);
					}
					pNode->node.keyName = deepCloneString(key);
					if (!pNode->node.keyName) {
						JSONDestroyObjectNode(pNode);
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �� json ��������� null���� ��ֵ����
* @param	pObject		json ����
* @param	key			��������
* @return	void
*/
void JSONSetNullAttr(pJsonObjectNode pObject /* in */, char* key /* in */) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonNullNode pNode = JSONCreateNullNode(key);
			if (!pNode) {
				// Null�ڵ��ڴ����ʧ��
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						JSONDestroyNumberNode((pJsonNumberNode)pCur);
					}
					else if (pCur->type == JSONTYPESTRING) {
						JSONDestroyStringNode((pJsonStringNode)pCur);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						break;
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
					}
					else {
						break;
					}
					pJsonNullNode pNode = JSONCreateNullNode(key);
					if (!pNode) {
						// Null�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonNullNode pNode = JSONCreateNullNode(key);
					if (!pNode) {
						// null�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �� json ��������� Boolean���� ��ֵ����
* @param	pObject				json ����
* @param	key char*			��������
* @param	value Boolean		����ֵ
* @return	void
*/
void JSONSetBooleanAttr(pJsonObjectNode pObject /* in */, char* key /* in */, BOOLEAN value /* in */) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			pJsonBooleanNode pNode = JSONCreateBooleanNode(key, value);
			if (!pNode) {
				// Boolean�ڵ��ڴ����ʧ��
				break;
			}
			pObject->table[idx] = (pJsonNode)pNode;
		}
		else {
			pJsonNode pPre = NULL;
			pJsonNode pCur = pObject->table[idx];
			pJsonNode pNext = pObject->table[idx]->next;
			do {
				if (strcmp(key, pCur->keyName) == 0) {
					if (pCur->type == JSONTYPENUMBER) {
						JSONDestroyNumberNode((pJsonNumberNode)pCur);
					}
					else if (pCur->type == JSONTYPESTRING) {
						JSONDestroyStringNode((pJsonStringNode)pCur);
					}
					else if (pCur->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pCur);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						((pJsonBooleanNode)pCur)->value = value && 0x01;
						break;
					}
					else {
						break;
					}
					pJsonBooleanNode pNode = JSONCreateBooleanNode(key, value);
					if (!pNode) {
						// Number�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					if (!pPre) {
						pObject->table[idx] = (pJsonNode)pNode;
					}
					else {
						pPre->next = (pJsonNode)pNode;
					}
					break;
				}
				if (pCur && !pCur->next) {
					pJsonBooleanNode pNode = JSONCreateBooleanNode(key, value);
					if (!pNode) {
						// Number�ڵ��ڴ����ʧ��
						break;
					}
					pNode->node.next = pNext;
					pCur->next = (pJsonNode)pNode;
					break;
				}
				pPre = pCur;
				pCur = pNext;
				pNext = pNext->next;
			} while (pCur);
		}
	} while (0);
}

/*
* �Ƴ� json �����е�����
* @param	pObject		json ����
* @param	key			��������
* @return	void
*/
void JSONRemoveAttr(pJsonObjectNode pObject /* in */, char* key /* in */) {
	int idx = -1;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (!key) {
			break;
		}
		idx = JSONGetHashIndex(key);
		if (idx == -1) {
			break;
		}
		if (!pObject->table[idx]) {
			break;
		}

		pJsonNode pPre = NULL;
		pJsonNode pCur = pObject->table[idx];
		pJsonNode pNext = pObject->table[idx]->next;
		do {
			if (strcmp(key, pCur->keyName) == 0) {
				if (pCur->type == JSONTYPENUMBER) {
					JSONDestroyNumberNode((pJsonNumberNode)pCur);
				}
				else if (pCur->type == JSONTYPESTRING) {
					JSONDestroyStringNode((pJsonStringNode)pCur);
				}
				else if (pCur->type == JSONTYPEARRAY) {
					JSONDestroyArrayNode((pJsonArrayNode)pCur);
				}
				else if (pCur->type == JSONTYPEOBJECT) {
					JSONDestroyObjectNode((pJsonObjectNode)pCur);
				}
				else if (pCur->type == JSONTYPENULL) {
					JSONDestroyNullNode((pJsonNullNode)pCur);
				}
				else if (pCur->type == JSONTYPEBOOLEAN) {
					JSONDestroyBooleanNode((pJsonBooleanNode)pCur);
				}
				if (!pPre) {
					pObject->table[idx] = pNext;
				}
				else {
					pPre->next = pNext;
				}
				break;
			}
		} while (pNext);
	} while (0);
}

/*
* ���� json �ڵ�
* @param	pObject		json �ڵ�
* @return	void
*/
void JSONDestroy(pJsonNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->type == JSONTYPENUMBER) {
			JSONDestroyNumberNode((pJsonNumberNode)pNode);
		}
		else if (pNode->type == JSONTYPESTRING) {
			JSONDestroyStringNode((pJsonStringNode)pNode);
		}
		else if (pNode->type == JSONTYPEARRAY) {
			JSONDestroyArrayNode((pJsonArrayNode)pNode);
		}
		else if (pNode->type == JSONTYPEOBJECT) {
			JSONDestroyObjectNode((pJsonObjectNode)pNode);
		}
		else if (pNode->type == JSONTYPENULL) {
			JSONDestroyNullNode((pJsonNullNode)pNode);
		}
		else if (pNode->type == JSONTYPEBOOLEAN) {
			JSONDestroyBooleanNode((pJsonBooleanNode)pNode);
		}
	} while (0);
}

/*
* json �������
* @param	pObject json����
* @return	pJsonObjectNode	�´�����json����
*/
pJsonObjectNode JSONObjectDeepClone(pJsonObjectNode pObject /* in */) {
	pJsonObjectNode pJson = NULL;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		pJson = JSONCreateObjectNode(pObject->node.keyName);
		if (!pJson) {
			// ���ʱ��json����ڵ��ڴ����ʧ��
			break;
		}
		
		// ����hash��
		for (int i = 0; i < HASH_MAX; i++) {
			if (pObject->table[i]) {
				// ��Ҫ������ʽ����
				pJsonNode pPre = NULL;
				pJsonNode pCur = pObject->table[i];
				pJsonNode pNext = pObject->table[i]->next;
				int num = 0;
				while (pCur) {
					// ����ʱ������������󣬻���������ô��
					if (pCur == (pJsonNode)pObject || (num != 0 && pCur == pObject->table[i])) {
						break;
					}
					num++;
					pJsonNode pTmpNode = NULL;
					if (pCur->type == JSONTYPENUMBER) {
						pTmpNode = (pJsonNode)JSONCreateNumberNode(pCur->keyName, ((pJsonNumberNode)pCur)->value);
						if (!pTmpNode) {
							// ���ʱ��json����Number���Խڵ��ڴ����ʧ��
							break;
						}
					}
					else if (pCur->type == JSONTYPESTRING) {
						pTmpNode = (pJsonNode)JSONCreateStringNode(pCur->keyName, ((pJsonStringNode)pCur)->value);
						if (!pTmpNode) {
							// ���ʱ��json����String���Խڵ��ڴ����ʧ��;
							break;
						}
					}
					else if (pCur->type == JSONTYPEARRAY) {
						// ����ڵ�
						pTmpNode = (pJsonNode)JSONArrayDeepClone((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						// Object����ֱ�ӵݹ�
						pTmpNode = (pJsonNode)JSONObjectDeepClone((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						// null �ڵ�
						pTmpNode = (pJsonNode)JSONCreateNullNode(pCur->keyName);
					}
					else if (pCur->type == JSONTYPEBOOLEAN) {
						// Boolean
						pTmpNode = (pJsonNode)JSONCreateBooleanNode(pCur->keyName, ((pJsonBooleanNode)pCur)->value);
					}
					if (pPre == NULL) {
						pJson->table[i] = pTmpNode;
					}
					else {
						if (pPre) {
							pPre->next = pTmpNode;
						}
						else {
							// ������ѣ��޷�����������ȥ����Ҫ�жϵ�ǰѭ�����������ͷŵ�ǰ�����Ľڵ�
							if (pTmpNode) {
								if (pTmpNode->type == JSONTYPENUMBER) {
									JSONDestroyNumberNode((pJsonNumberNode)pTmpNode);
								}
								else if (pTmpNode->type == JSONTYPESTRING) {
									JSONDestroyStringNode((pJsonStringNode)pTmpNode);
								}
								else if (pTmpNode->type == JSONTYPEARRAY) {
									JSONDestroyArrayNode((pJsonArrayNode)pTmpNode);
								}
								else if (pTmpNode->type == JSONTYPEOBJECT) {
									JSONDestroyObjectNode((pJsonObjectNode)pTmpNode);
								}
								else if (pTmpNode->type == JSONTYPENULL) {
									JSONDestroyNullNode((pJsonNullNode)pTmpNode);
								}
								else if (pTmpNode->type == JSONTYPEBOOLEAN) {
									JSONDestroyBooleanNode((pJsonBooleanNode)pTmpNode);
								}
							}
						}
					}
					pPre = pTmpNode;
					pCur = pNext;
					if (pNext) {
						pNext = pNext->next;
					}
					
				}
			}
		}

	} while (0);
	return pJson;
}

/*
* json �������
* @param	pArray json����
* @return	pJsonArrayNode	�´�����json Array
*/
pJsonArrayNode JSONArrayDeepClone(pJsonArrayNode pArray /* in */) {
	pJsonArrayNode pArrayNode = NULL;
	do {
		if (!pArray) {
			break;
		}
		if (pArray->node.type != JSONTYPEARRAY) {
			break;
		}
		pArrayNode = JSONCreateArrayNode(pArray->node.keyName);
		if (!pArrayNode) {
			break;
		}
		pArrayNode->size = pArray->size;
		// ���Ԫ�ص�����
		pArrayNode->type = pArray->type;
		// ��������Ԫ��
		if (pArray->size && pArray->array) {
			// ������������ڴ�ռ䣬����ڵ��Ԫ������ռ�Ĭ�ϲ����䣬ֻ�����Ԫ�زŽ��з���
			// �����ڴ���俼�ǣ�ÿ�η��� ARRAY_MIN_SIZE ��С����������Խ���ʱ�����·��䣬�Խ�Լ�ڴ�
			int size = (pArray->size / ARRAY_MIN_SIZE + (pArray->size % ARRAY_MIN_SIZE == 0 ? 0 : 1)) * ARRAY_MIN_SIZE;
			pArrayNode->array = (pJsonNode*)malloc(size * sizeof(pJsonNode));
			if (!pArrayNode->array) {
				// ����ռ����ʧ��
				pArrayNode->size = 0;
				pArrayNode->type = JSONTYPEUNDEFINED;
				break;
			}
			memset(pArrayNode->array, 0, size * sizeof(pJsonNode));
			// ��������Ԫ�����
			for (int i = 0; i < pArray->size; i++) {
				if (pArray->array[i]) {
					if (pArray->array[i]->type != pArray->type) {
						continue;
					}
					if (pArray->array[i]->type == JSONTYPENUMBER) {
						pArrayNode->array[i] = (pJsonNode)JSONCreateNumberNode(pArray->array[i]->keyName, ((pJsonNumberNode)pArray->array[i])->value);
					}
					else if (pArray->array[i]->type == JSONTYPESTRING) {
						pArrayNode->array[i] = (pJsonNode)JSONCreateStringNode(pArray->array[i]->keyName, ((pJsonStringNode)pArray->array[i])->value);
					}
					else if (pArray->array[i]->type == JSONTYPEARRAY) {
						pArrayNode->array[i] = (pJsonNode)JSONArrayDeepClone((pJsonArrayNode)pArray->array[i]);
					}
					else if (pArray->array[i]->type == JSONTYPEOBJECT) {
						pArrayNode->array[i] = (pJsonNode)JSONObjectDeepClone((pJsonObjectNode)pArray->array[i]);
					}
					else if (pArray->array[i]->type == JSONTYPENULL) {
						pArrayNode->array[i] = (pJsonNode)JSONCreateNullNode(pArray->array[i]->keyName);
					}
					else if (pArray->array[i]->type == JSONTYPEBOOLEAN) {
						pArrayNode->array[i] = (pJsonNode)JSONCreateBooleanNode(pArray->array[i]->keyName, ((pJsonBooleanNode)pArray->array[i])->value);
					}
				}
			}
		}
	} while (0);
	return pArrayNode;
}

/*
* json ���ֶ������
* @param	pNumber jsonNumber
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonNumberNode	�´�����json Number
*/
pJsonNumberNode JSONNumberDeepClone(pJsonNumberNode pNumber /* in */, BOOLEAN isCopyKey /* in */) {
	pJsonNumberNode pNumberNode = NULL;
	do {
		if (!pNumber) {
			break;
		}
		if (pNumber->node.type != JSONTYPENUMBER) {
			break;
		}
		pNumberNode = (pJsonNumberNode)malloc(sizeof(JsonNumberNode));
		if (!pNumberNode) {
			break;
		}
		memset(pNumberNode, 0, sizeof(JsonNumberNode));
		// ���Կ�����ʱ����Ҫ�Լ����ƽ��п�������Ϊ����Ԫ�ص�ʱ������Ҫ������
		if (isCopyKey) {
			if (pNumber->node.keyName) {
				pNumberNode->node.keyName = deepCloneString(pNumber->node.keyName);
				if (!pNumberNode->node.keyName) {
					// ���������Ƶ�ʱ���ڴ��޷����䣬��ڵ�û�д��ڵ�����
					JSONDestroyNumberNode(pNumberNode);
					break;
				}
			}
		}
		pNumberNode->node.type = JSONTYPENUMBER;
		pNumberNode->value = pNumber->value;
	} while (0);
	return pNumberNode;
}

/*
* json �ַ����������
* @param	pString jsonString
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonNumberNode	�´�����json Number
*/
pJsonStringNode JSONStringDeepClone(pJsonStringNode pString /* in */, BOOLEAN isCopyKey /* in */) {
	pJsonStringNode pStringNode = NULL;
	do {
		if (!pString) {
			break;
		}
		if (pString->node.type != JSONTYPESTRING) {
			break;
		}
		pStringNode = (pJsonStringNode)malloc(sizeof(JsonStringNode));
		if (!pStringNode) {
			break;
		}
		memset(pStringNode, 0, sizeof(JsonStringNode));
		// ���Կ�����ʱ����Ҫ�Լ����ƽ��п�������Ϊ����Ԫ�ص�ʱ������Ҫ������
		if (isCopyKey) {
			if (pString->node.keyName) {
				pStringNode->node.keyName = deepCloneString(pString->node.keyName);
				if (!pStringNode->node.keyName) {
					// ���������Ƶ�ʱ���ڴ��޷����䣬��ڵ�û�д��ڵ�����
					JSONDestroyStringNode(pStringNode);
					break;
				}
			}
		}
		pStringNode->node.type = JSONTYPESTRING;
		pStringNode->value = deepCloneString(pString->value);
	} while (0);
	return pStringNode;
}

/*
* json null �������
* @param	pNull pJsonNullNode
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonNullNode	�´�����json null
*/
pJsonNullNode JSONNullDeepClone(pJsonNullNode pNull /* in */, BOOLEAN isCopyKey /* in */) {
	pJsonNullNode pNode = NULL;
	do {
		if (!pNull) {
			break;
		}
		if (pNull->node.type != JSONTYPENULL) {
			break;
		}
		pNode = (pJsonNullNode)malloc(sizeof(JsonNullNode));
		if (!pNull) {
			break;
		}
		memset(pNode, 0, sizeof(JsonNullNode));
		// ���Կ�����ʱ����Ҫ�Լ����ƽ��п�������Ϊ����Ԫ�ص�ʱ������Ҫ������
		if (isCopyKey) {
			if (pNull->node.keyName) {
				pNode->node.keyName = deepCloneString(pNull->node.keyName);
				if (!pNode->node.keyName) {
					// ���������Ƶ�ʱ���ڴ��޷����䣬��ڵ�û�д��ڵ�����
					JSONDestroyNullNode(pNode);
					break;
				}
			}
		}
		pNode->node.type = JSONTYPENULL;
		pNode->value = (int)null;
	} while (0);
	return pNode;
}

/*
* json Boolean �������
* @param	pNull pJsonBooleanNode
* @param	isCopyKey char* �Ƿ���м����ƿ���
* @return	pJsonBooleanNode	�´�����json Boolean
*/
pJsonBooleanNode JSONBooleanDeepClone(pJsonBooleanNode pBoolean /* in */, BOOLEAN isCopyKey /* in */) {
	pJsonBooleanNode pNode = NULL;
	do {
		if (!pBoolean) {
			break;
		}
		if (pBoolean->node.type != JSONTYPEBOOLEAN) {
			break;
		}
		pNode = (pJsonBooleanNode)malloc(sizeof(JsonBooleanNode));
		if (!pBoolean) {
			break;
		}
		memset(pNode, 0, sizeof(JsonBooleanNode));
		// ���Կ�����ʱ����Ҫ�Լ����ƽ��п�������Ϊ����Ԫ�ص�ʱ������Ҫ������
		if (isCopyKey) {
			if (pBoolean->node.keyName) {
				pNode->node.keyName = deepCloneString(pBoolean->node.keyName);
				if (!pNode->node.keyName) {
					// ���������Ƶ�ʱ���ڴ��޷����䣬��ڵ�û�д��ڵ�����
					JSONDestroyBooleanNode(pNode);
					break;
				}
			}
		}
		pNode->node.type = JSONTYPEBOOLEAN;
		pNode->value = pBoolean->value && 0x01;
	} while (0);
	return pNode;
}

/*
* ���� Number �������ͽڵ�
* @param	pNode Number���ͽڵ�
* @return void
*/
void JSONDestroyNumberNode(pJsonNumberNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENUMBER) {
			break;
		}
		pNode->node.type = 0;
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
			pNode->node.keyName = NULL;
		}
		free(pNode);
		pNode = NULL;
	} while (0);
}

/*
* ���� String �������ͽڵ�
* @param	pNode String���ͽڵ�
* @return void
*/
void JSONDestroyStringNode(pJsonStringNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPESTRING) {
			break;
		}
		pNode->node.type = 0;
		if (pNode->value) {
			free(pNode->value);
		}
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
			pNode->node.keyName = NULL;
		}
		free(pNode);
		pNode = NULL;
	} while (0);
}

/*
* ���� Array �������ͽڵ�
* @param	pNode Array���ͽڵ�
* @return void
*/
void JSONDestroyArrayNode(pJsonArrayNode pNode /* in */) {
	int i = 0;
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pNode->node.type = 0;
		if (pNode->size && pNode->array) {
			for (i = 0; i < pNode->size; i++) {
				if (pNode->array[i]->type == JSONTYPENUMBER) {
					JSONDestroyNumberNode((pJsonNumberNode)pNode->array[i]);
				}
				else if (pNode->array[i]->type == JSONTYPESTRING) {
					JSONDestroyStringNode((pJsonStringNode)pNode->array[i]);
				}
				else if (pNode->array[i]->type == JSONTYPEARRAY) {
					JSONDestroyArrayNode((pJsonArrayNode)pNode->array[i]);
				}
				else if (pNode->array[i]->type == JSONTYPEOBJECT) {
					JSONDestroyObjectNode((pJsonObjectNode)pNode->array[i]);
				}
				else if (pNode->array[i]->type == JSONTYPENULL) {
					JSONDestroyNullNode((pJsonNullNode)pNode->array[i]);
				}
				else if (pNode->array[i]->type == JSONTYPEBOOLEAN) {
					JSONDestroyBooleanNode((pJsonBooleanNode)pNode->array[i]);
				}
				pNode->array[i] = NULL;
			}
		}
		if (pNode->array) {
			free(pNode->array);
			pNode->array = NULL;
		}
		//printf("���� Array �ڵ㣬��������: %s\n", pNode->node.keyName);
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
			pNode->node.keyName = NULL;
		}
		free(pNode);
		pNode = NULL;
	} while (0);
}

/*
* ���� Object �������ͽڵ�
* @param	pNode Object���ͽڵ�
* @return void
*/
void JSONDestroyObjectNode(pJsonObjectNode pNode /* in */) {
	int i = 0;
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEOBJECT) {
			break;
		}
		pNode->node.type = 0;
		for (i = 0; i < HASH_MAX; i++) {
			// �жϵ�ǰ�����Ƿ���ڣ�����������
			if (pNode->table[i]) {
				// �Ե�ǰ���ԣ���������ʽ����
				pJsonNode pNext = NULL;
				do {
					if (!pNode->table[i]) {
						break;
					}
					pNext = pNode->table[i]->next;
					if (pNode->table[i]->type == JSONTYPENUMBER) {
						// �������ͣ�ֱ�����ٽڵ�
						JSONDestroyNumberNode((pJsonNumberNode)pNode->table[i]);
					}
					else if (pNode->table[i]->type == JSONTYPESTRING) {
						// �ַ������ͣ��Ƚ��������ַ����ռ�
						JSONDestroyStringNode((pJsonStringNode)pNode->table[i]);
					}
					else if (pNode->table[i]->type == JSONTYPEARRAY) {
						JSONDestroyArrayNode((pJsonArrayNode)pNode->table[i]);
					}
					else if (pNode->table[i]->type == JSONTYPEOBJECT) {
						JSONDestroyObjectNode((pJsonObjectNode)pNode->table[i]);
					}
					else if (pNode->table[i]->type == JSONTYPENULL) {
						JSONDestroyNullNode((pJsonNullNode)pNode->table[i]);
					}
					else if (pNode->table[i]->type == JSONTYPEBOOLEAN) {
						JSONDestroyBooleanNode((pJsonBooleanNode)pNode->table[i]);
					}
					pNode->table[i] = pNext;
				} while (pNext);
			}
			pNode->table[i] = NULL;
		}
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
			pNode->node.keyName = NULL;
		}

		free(pNode);
		pNode = NULL;
	} while (0);
}

/*
* ���� null �������ͽڵ�
* @param	pNode null���ͽڵ�
* @return void
*/
void JSONDestroyNullNode(pJsonNullNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENULL) {
			break;
		}
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
		}
		free(pNode);
	} while (0);
}

/*
* ���� Boolean �������ͽڵ�
* @param	pNode Boolean���ͽڵ�
* @return void
*/
void JSONDestroyBooleanNode(pJsonBooleanNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEBOOLEAN) {
			break;
		}
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
		}
		free(pNode);
	} while (0);
}

/*
* �� json ����ڵ�������β��׷��Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pNode pJsonNode	��Ҫ��ӵĽڵ�
* @return	void
*/
void JSONArrayPush(pJsonArrayNode pArrayNode /* in */, pJsonNode pNode /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		if (!pNode) {
			break;
		}
		//// �������ͣ�����Ҫ��������������Ƿ�ƥ��
		//if (pArrayNode->type != JSONTYPEUNDEFINED && (pArrayNode->type != pNode->type)) {
		//	break;
		//}
		if (pNode->type == JSONTYPEUNDEFINED) {
			break;
		}
		// �ж������Ƿ���Ҫ����
		int minSize = (pArrayNode->size / ARRAY_MIN_SIZE) * ARRAY_MIN_SIZE;
		if (minSize >= pArrayNode->size) {
			// ������
			pJsonNode* tmpArr = (pJsonNode*)malloc((minSize + ARRAY_MIN_SIZE) * sizeof(pJsonNode));
			if (!tmpArr) {
				JSONDestroy(pNode);
				break;
			}
			memset(tmpArr, 0, (minSize + ARRAY_MIN_SIZE) * sizeof(pJsonNode));
			memcpy(tmpArr, pArrayNode->array, pArrayNode->size * sizeof(pJsonNode));
			free(pArrayNode->array);
			pArrayNode->array = tmpArr;
		}
		// ��һ�β���Ԫ��ʱ
		if (!pArrayNode->array) {
			pArrayNode->array = (pJsonNode*)malloc(ARRAY_MIN_SIZE);
			if (!pArrayNode->array) {
				memset(pArrayNode->array, 0, ARRAY_MIN_SIZE);
			}
		}
		pArrayNode->array[pArrayNode->size] = pNode;
		pArrayNode->size++;
		pArrayNode->type = pNode->type;
	} while (0);
}

/*
* �� json ����ڵ�������ͷ��׷��Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pNode pJsonNode	��Ҫ��ӵĽڵ�
* @return	void
*/
void JSONArrayUnshift(pJsonArrayNode pArrayNode /* in */, pJsonNode pNode /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		if (!pNode) {
			break;
		}
		// �������ͣ�����Ҫ��������������Ƿ�ƥ��
		if (pArrayNode->type != JSONTYPEUNDEFINED && (pArrayNode->type != pNode->type)) {
			break;
		}
		if (pNode->type == JSONTYPEUNDEFINED) {
			break;
		}
		// �ж������Ƿ���Ҫ����
		int minSize = (pArrayNode->size / ARRAY_MIN_SIZE) * ARRAY_MIN_SIZE;
		if (minSize >= pArrayNode->size) {
			// ������
			pJsonNode* tmpArr = (pJsonNode*)malloc((minSize + ARRAY_MIN_SIZE) * sizeof(pJsonNode));
			if (!tmpArr) {
				break;
			}
			memset(tmpArr, 0, (minSize + ARRAY_MIN_SIZE) * sizeof(pJsonNode));
			memcpy(tmpArr + 1, pArrayNode->array, pArrayNode->size * sizeof(pJsonNode));
			pArrayNode->array = tmpArr;
		}
		else {
			for (int i = pArrayNode->size; i > 0; i--) {
				pArrayNode->array[i] = pArrayNode->array[i - 1];
			}
			pArrayNode->array[0] = NULL;
		}
		// ��һ�β���Ԫ��ʱ
		if (!pArrayNode->array) {
			pArrayNode->array = (pJsonNode*)malloc(ARRAY_MIN_SIZE);
			if (!pArrayNode->array) {
				memset(pArrayNode->array, 0, ARRAY_MIN_SIZE);
			}
		}
		pArrayNode->array[0] = pNode;
		pArrayNode->size++;
		pArrayNode->type = pNode->type;
	} while (0);
}

/*
* �� json ����ڵ�������β��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	number double	��Ҫ��ӵ�����
* @return	void
*/
void JSONArrayPushNumber(pJsonArrayNode pArrayNode /* in */, double number /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonNumberNode pNode = JSONCreateNumberNode(NULL, number);
		JSONArrayPush(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������β��׷���ַ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pString char*	��Ҫ��ӵ��ַ���
* @return	void
*/
void JSONArrayPushString(pJsonArrayNode pArrayNode /* in */, char* pString /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonStringNode pNode = JSONCreateStringNode(NULL, pString);
		JSONArrayPush(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������β��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pArr pJsonArrayNode	��Ҫ��ӵ�����ڵ�
* @return	void
*/
void JSONArrayPushArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */) {
	JSONArrayPush(pArrayNode, (pJsonNode)pArr);
}

/*
* �� json ����ڵ�������β��׷�Ӷ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pObject pJsonObjectNode	��Ҫ��ӵĶ���ڵ�
* @return	void
*/
void JSONArrayPushObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */) {
	JSONArrayPush(pArrayNode, (pJsonNode)pObject);
}

/*
* �� json ����ڵ�������β��׷�� null
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayPushNull(pJsonArrayNode pArrayNode /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonNullNode pNode = JSONCreateNullNode(NULL);
		JSONArrayPush(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������β��׷�� Boolean
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	value BOOLEAN	��Ҫ��ӵ� Boolean
* @return	void
*/
void JSONArrayPushBoolean(pJsonArrayNode pArrayNode /* in */, BOOLEAN value /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonBooleanNode pNode = JSONCreateBooleanNode(NULL, value);
		JSONArrayPush(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������ͷ��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	number double	��Ҫ��ӵ�����
* @return	void
*/
void JSONArrayUnshiftNumber(pJsonArrayNode pArrayNode /* in */, double number /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonNumberNode pNode = JSONCreateNumberNode(NULL, number);
		JSONArrayUnshift(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������ͷ��׷���ַ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pString char*	��Ҫ��ӵ��ַ���
* @return	void
*/
void JSONArrayUnshiftString(pJsonArrayNode pArrayNode /* in */, char* pString /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonStringNode pNode = JSONCreateStringNode(NULL, pString);
		JSONArrayUnshift(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������ͷ��׷������
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pArr pJsonArrayNode	��Ҫ��ӵ�����
* @return	void
*/
void JSONArrayUnshiftArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */) {
	JSONArrayUnshift(pArrayNode, (pJsonNode)pArr);
}

/*
* �� json ����ڵ�������ͷ��׷�Ӷ���
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	pObject pJsonObjectNode	��Ҫ��ӵĶ���
* @return	void
*/
void JSONArrayUnshiftObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */) {
	JSONArrayUnshift(pArrayNode, (pJsonNode)pObject);
}

/*
* �� json ����ڵ�������ͷ��׷�� null
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayUnshiftNull(pJsonArrayNode pArrayNode /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonNullNode pNode = JSONCreateNullNode(NULL);
		JSONArrayUnshift(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������ͷ��׷�� Boolean
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @param	value BOOLEAN	��Ҫ��ӵ� Boolean
* @return	void
*/
void JSONArrayUnshiftBoolean(pJsonArrayNode pArrayNode /* in */, BOOLEAN value /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		pJsonBooleanNode pNode = JSONCreateBooleanNode(NULL, value);
		JSONArrayUnshift(pArrayNode, (pJsonNode)pNode);
	} while (0);
}

/*
* �� json ����ڵ�������β��ɾ��Ԫ�أ������ٸ�Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayPop(pJsonArrayNode pArrayNode /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		if (pArrayNode->size <= 0) {
			break;
		}
		pJsonNode pTmp = pArrayNode->array[pArrayNode->size - 1];
		pArrayNode->array[pArrayNode->size - 1] = NULL;
		if (pTmp) {
			if (pTmp->type == JSONTYPENUMBER) {
				JSONDestroyNumberNode((pJsonNumberNode)pTmp);
			}
			else if (pTmp->type == JSONTYPESTRING) {
				JSONDestroyStringNode((pJsonStringNode)pTmp);
			}
			else if (pTmp->type == JSONTYPEARRAY) {
				JSONDestroyArrayNode((pJsonArrayNode)pTmp);
			}
			else if (pTmp->type == JSONTYPEOBJECT) {
				JSONDestroyObjectNode((pJsonObjectNode)pTmp);
			}
			else if (pTmp->type == JSONTYPENULL) {
				JSONDestroyNullNode((pJsonNullNode)pTmp);
			}
			else if (pTmp->type == JSONTYPEBOOLEAN) {
				JSONDestroyBooleanNode((pJsonBooleanNode)pTmp);
			}
		}
		pArrayNode->size--;
		if (pArrayNode->size == 0) {
			// �ͷ�����ռ�
			free(pArrayNode->array);
			pArrayNode->array = NULL;
		}
	} while (0);
}

/*
* �� json ����ڵ�������ͷ��ɾ��Ԫ�أ������ٸ�Ԫ��
* @param	pArrayNode pJsonArrayNode ����ڵ�
* @return	void
*/
void JSONArrayShift(pJsonArrayNode pArrayNode /* in */) {
	do {
		if (!pArrayNode) {
			break;
		}
		if (pArrayNode->node.type != JSONTYPEARRAY) {
			break;
		}
		if (pArrayNode->size <= 0) {
			break;
		}
		pJsonNode pTmp = pArrayNode->array[pArrayNode->size - 1];
		pArrayNode->array[pArrayNode->size - 1] = NULL;
		if (pTmp) {
			if (pTmp->type == JSONTYPENUMBER) {
				JSONDestroyNumberNode((pJsonNumberNode)pTmp);
			}
			else if (pTmp->type == JSONTYPESTRING) {
				JSONDestroyStringNode((pJsonStringNode)pTmp);
			}
			else if (pTmp->type == JSONTYPEARRAY) {
				JSONDestroyArrayNode((pJsonArrayNode)pTmp);
			}
			else if (pTmp->type == JSONTYPEOBJECT) {
				JSONDestroyObjectNode((pJsonObjectNode)pTmp);
			}
			else if (pTmp->type == JSONTYPENULL) {
				JSONDestroyNullNode((pJsonNullNode)pTmp);
			}
			else if (pTmp->type == JSONTYPEBOOLEAN) {
				JSONDestroyBooleanNode((pJsonBooleanNode)pTmp);
			}
		}
		pArrayNode->size--;
		if (pArrayNode->size == 0) {
			// �ͷ�����ռ�
			free(pArrayNode->array);
			pArrayNode->array = NULL;
			break;
		}
		for (int i = 0; i < pArrayNode->size; i++) {
			pArrayNode->array[i] = pArrayNode->array[i + 1];
		}
		pArrayNode->array[pArrayNode->size] = NULL;
	} while (0);
}

/*
* ��ȡ�������͵����ݳ���
* @param	pArray	pJsonArrayNode ����ڵ�
* @return	unsigned int	���鳤��
*/
unsigned int JSONArrayGetLength(pJsonArrayNode pArray /* in */) {
	unsigned int len = 0;

	do {
		if (!pArray) {
			break;
		}
		if (pArray->node.type != JSONTYPEARRAY) {
			break;
		}
		len = pArray->size;
	} while (0);

	return len;
}

/*
* ��ȡ����ָ��λ��Ԫ��
* @param	pArray	pJsonArrayNode ����ڵ�
* @param	pos		int
* @return	pJsonNode	����Ԫ��
*/
pJsonNode JSONArrayGetNode(pJsonArrayNode pArray /* in */, int pos /* in */) {
	pJsonNode pNode = NULL;

	do {
		if (!pArray) {
			break;
		}
		if (pArray->node.type != JSONTYPEARRAY) {
			break;
		}
		if (pos < 0 || pos >= pArray->size) {
			break;
		}
		if (pArray->array) {
			pNode = pArray->array[pos];
		}
		
	} while (0);

	return pNode;
}

/*
* ��ȡ �ڵ� ��������
* @param	pNode	pJsonNode	�ڵ�
* @return	JSON_DATA_TYPE		json �ڵ����������
*/
JSON_DATA_TYPE JSONNodeGetType(pJsonNode pNode /* in */) {
	JSON_DATA_TYPE type = JSONTYPEUNDEFINED;
	do {
		if (!pNode) {
			break;
		}
		type = pNode->type;
	} while (0);
	return type;
}

/*
* ��ȡ Object ������������
* @param	pObject	pJsonObjectNode	json ����
* @param	key char*		��ֵ
* @return	JSON_DATA_TYPE		json �ڵ����������
*/
JSON_DATA_TYPE JSONObjectGetAttrType(pJsonObjectNode pObject /* in */, char* key /* in */) {
	JSON_DATA_TYPE type = JSONTYPEUNDEFINED;
	do {
		if (!pObject) {
			break;
		}
		if (!key || !strlen(key)) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					type = pNode->type;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
	return type;
}

/*
* ��ȡ���ֽڵ����ֵ
* @param	pNode	pJsonNumberNode	���ֽڵ�
* @param	pValue	double*
* @return	void
*/
void JSONNodeGetNumberValue(pJsonNumberNode pNode /* in */, double* pValue /* out */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENUMBER) {
			break;
		}
		*pValue = pNode->value;
	} while (0);
}

/*
* ��ȡ�ַ����ڵ�ĵ��ַ���
* @param	pNode	pJsonStringNode	�ַ����ڵ�
* @param	ppValue	char**
* @return	void
*/
void JSONNodeGetStringValue(pJsonStringNode pNode /* in */, char** ppValue /* out */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPESTRING) {
			break;
		}
		if (!pNode->value) {
			break;
		}
		*ppValue = (char*)malloc(strlen(pNode->value) +1);
		if (!*ppValue) {
			break;
		}
		memset(*ppValue, 0, strlen(pNode->value) + 1);
		strcat(*ppValue, pNode->value);
	} while (0);
}

/*
* ��ȡ Boolean �ڵ��ֵ
* @param	pNode	pJsonBooleanNode	���ֽڵ�
* @param	pValue	double*
* @return	void
*/
void JSONNodeGetBooleanValue(pJsonBooleanNode pNode /* in */, BOOLEAN* pValue /* out */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEBOOLEAN) {
			break;
		}
		*pValue = pNode->value && 0x01;
	} while (0);
}

/*
* ��ȡ json �������Խڵ����ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*			��
* @param	pValue		double*			ֵ
* @return	void
*/
void JSONObjectGetNumberAttr(pJsonObjectNode pObject /* in */, char* key /* in */, double* pValue /* out */) {
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					if (pNode->type != JSONTYPENUMBER) {
						break;
					}
					*pValue = ((pJsonNumberNode)pNode)->value;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
}

/*
* ��ȡ json �ַ������Խڵ���ַ���
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*			��
* @param	ppValue		char**			ֵ
* @return	void
*/
void JSONObjectGetStringAttr(pJsonObjectNode pObject /* in */, char* key /* in */, char** ppValue /* out */) {
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					if (pNode->type != JSONTYPESTRING) {
						break;
					}
					*ppValue = (char*)malloc(strlen(((pJsonStringNode)pNode)->value) + 1);
					if (!*ppValue) {
						break;
					}
					memset(*ppValue, 0, strlen(((pJsonStringNode)pNode)->value) + 1);
					strcat(*ppValue, ((pJsonStringNode)pNode)->value);
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
}

/*
* ��ȡ json �������Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*			��
* @param	ppValue		pJsonArrayNode*	ֵ
* @return	void
*/
void JSONObjectGetArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonArrayNode* ppValue /* out */) {
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					if (pNode->type != JSONTYPEARRAY) {
						break;
					}
					*ppValue = (pJsonArrayNode)pNode;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
}

/*
* ��ȡ json �������Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*				��
* @param	ppValue		pJsonObjectNode*	ֵ
* @return	void
*/
void JSONObjectGetObjectAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonObjectNode* ppValue /* out */) {
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					if (pNode->type != JSONTYPEOBJECT) {
						break;
					}
					*ppValue = (pJsonObjectNode)pNode;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
}

/*
* ��ȡ json  null ���Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*				��
* @param	pValue		pJsonNullNode*
* @return	void
*/
void JSONObjectGetNullAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonNullNode* ppValue /* out */) {
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					if (pNode->type != JSONTYPENULL) {
						break;
					}
					*ppValue = (pJsonNullNode)pNode;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
}

/*
* ��ȡ json  Boolean ���Խڵ��ֵ
* @param	pObject		pJsonObjectNode json ����
* @param	key			char*				��
* @param	pValue		BOOLEAN*
* @return	void
*/
void JSONObjectGetBooleanAttr(pJsonObjectNode pObject /* in */, char* key /* in */, BOOLEAN* pValue /* out */) {
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		int idx = JSONGetHashIndex(key);
		if (idx < 0 || idx >= HASH_MAX) {
			break;
		}
		if (pObject->table[idx]) {
			// ������ʽ����
			pJsonNode pNode = pObject->table[idx];
			do {
				if (strcmp(key, pNode->keyName) == 0) {
					if (pNode->type != JSONTYPEBOOLEAN) {
						break;
					}
					*pValue = ((pJsonBooleanNode)pNode)->value && 0x01;
					break;
				}
				pNode = pNode->next;
			} while (pNode);
		}
	} while (0);
}

int tabCount = 0;
/*
* ��ӡ Number
* @param	pNumber pJsonNumberNode
* @return	void
*/
void JSONPrintNumberNode(pJsonNumberNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENUMBER) {
			break;
		}
		if (pNode->node.keyName) {
			printf("\"%s\": %f,\n", pNode->node.keyName, pNode->value);
		}
		else {
			printf("%f,", pNode->value);
		}
	} while (0);
}

/*
* ��ӡ String
* @param	pNode pJsonStringNode
* @return	void
*/
void JSONPrintStringNode(pJsonStringNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPESTRING) {
			break;
		}
		if (pNode->node.keyName) {
			printf("\"%s\": \"%s\",\n", pNode->node.keyName, pNode->value);
		}
		else {
			printf("\"%s\",", pNode->value);
		}
	} while (0);
}

/*
* ��ӡ Array
* @param	pNode pJsonArrayNode
* @return	void
*/
void JSONPrintArrayNode(pJsonArrayNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEARRAY) {
			break;
		}
		if (pNode->node.keyName) {
			printf("\"%s\": [\n", pNode->node.keyName);
			tabCount++;
		}
		else {
			printf("Array: [\n");
			tabCount = 1;
		}
		for (int i = 0; i < tabCount; i++) {
			printf("\t");
		}
		for (int i = 0; i < pNode->size; i++) {
			if (pNode->array[i]->type == JSONTYPENUMBER) {
				JSONPrintNumberNode((pJsonNumberNode)pNode->array[i]);
			}
			else if (pNode->array[i]->type == JSONTYPESTRING) {
				JSONPrintStringNode((pJsonStringNode)pNode->array[i]);
			}
			else if (pNode->array[i]->type == JSONTYPEARRAY) {
				JSONPrintArrayNode((pJsonArrayNode)pNode->array[i]);
			}
			else if (pNode->array[i]->type == JSONTYPEOBJECT) {
				JSONPrintObjectNode((pJsonObjectNode)pNode->array[i]);
			}
			else if (pNode->array[i]->type == JSONTYPENULL) {
				JSONPrintNullNode((pJsonNullNode)pNode->array[i]);
			}
			else if (pNode->array[i]->type == JSONTYPEBOOLEAN) {
				JSONPrintBooleanNode((pJsonBooleanNode)pNode->array[i]);
			}
		}
		printf("\n");
		for (int i = 0; i < tabCount - 1; i++) {
			printf("\t");
		}
		if (pNode->node.keyName) {
			printf("],\n,");
		}
		else {
			printf("]\n");
		}
		if (tabCount > 0) {
			tabCount--;
		}
	} while (0);
}

/*
* ��ӡ json ����
* @param	pObject		json ����
* @return	void
*/
void JSONPrintObjectNode(pJsonObjectNode pObject /* in */) {
	int i = 0;
	do {
		if (!pObject) {
			break;
		}
		if (pObject->node.type != JSONTYPEOBJECT) {
			break;
		}
		if (pObject->node.keyName) {
			printf("\"%s\": {\n", pObject->node.keyName);
			tabCount++;
		}
		else {
			printf("Object: {\n");
			tabCount = 1;
		}
		
		for (i = 0; i < HASH_MAX; i++) {
			if (pObject->table[i]) {
				pJsonNode pNode = pObject->table[i];
				do {
					if (!pNode) {
						break;
					}
					for (int i = 0; i < tabCount; i++) {
						printf("\t");
					}
					if (pNode->type == JSONTYPENUMBER) {
						JSONPrintNumberNode((pJsonNumberNode)pNode);
					}
					else if (pNode->type == JSONTYPESTRING) {
						JSONPrintStringNode((pJsonStringNode)pNode);
					}
					else if (pNode->type == JSONTYPEARRAY) {
						JSONPrintArrayNode((pJsonArrayNode)pNode);
					}
					else if (pNode->type == JSONTYPEOBJECT) {
						JSONPrintObjectNode((pJsonObjectNode)pNode);
					}
					else if (pNode->type == JSONTYPENULL) {
						JSONPrintNullNode((pJsonNullNode)pNode);
					}
					else if (pNode->type == JSONTYPEBOOLEAN) {
						JSONPrintBooleanNode((pJsonBooleanNode)pNode);
					}
					for (int i = 0; i < tabCount; i++) {
						printf("\b");
					}
					pNode = pNode->next;
				} while (pNode);
			}
		}
		for (int i = 0; i < tabCount - 1; i++) {
			printf("\t");
		}
		if (pObject->node.keyName) {
			printf("},\n");
		}
		else {
			printf("}\n");
		}
		if (tabCount > 0) {
			tabCount--;
		}
	} while (0);
}


/*
* ��ӡ null
* @param	pNode pJsonNullNode
* @return	void
*/
void JSONPrintNullNode(pJsonNullNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPENULL) {
			break;
		}
		if (pNode->node.keyName) {
			printf("\"%s\": null,\n", pNode->node.keyName);
		}
		else {
			printf("null,");
		}
	} while (0);
}

/*
* ��ӡ Boolean
* @param	pNode pJsonBooleanNode
* @return	void
*/
void JSONPrintBooleanNode(pJsonBooleanNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (pNode->node.type != JSONTYPEBOOLEAN) {
			break;
		}
		if (pNode->node.keyName) {
			printf("\"%s\": ", pNode->node.keyName);
			if (pNode->value) {
				printf("true,\n");
			}
			else {
				printf("false,\n");
			}
		}
		else {

			if (pNode->value) {
				printf("true,");
			}
			else {
				printf("false,");
			}
		}
	} while (0);
}

/*
* ��ӡ json �ڵ�
* @param	pNode pJsonNode		json �ڵ�
* @return	void
*/
void JSONPrint(pJsonNode pNode /* in */) {
	do {
		if (!pNode) {
			break;
		}
		if (!pNode) {
			break;
		}
		if (pNode->type == JSONTYPENUMBER) {
			JSONPrintNumberNode((pJsonNumberNode)pNode);
		}
		else if (pNode->type == JSONTYPESTRING) {
			JSONPrintStringNode((pJsonStringNode)pNode);
		}
		else if (pNode->type == JSONTYPEARRAY) {
			JSONPrintArrayNode((pJsonArrayNode)pNode);
		}
		else if (pNode->type == JSONTYPEOBJECT) {
			JSONPrintObjectNode((pJsonObjectNode)pNode);
		}
		else if (pNode->type == JSONTYPENULL) {
			JSONPrintNullNode((pJsonNullNode)pNode);
		}
		else if (pNode->type == JSONTYPEBOOLEAN) {
			JSONPrintBooleanNode((pJsonBooleanNode)pNode);
		}
	} while (0);
}