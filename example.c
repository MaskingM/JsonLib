
#include "jsonLib.h"


int main() {
	char* str = "{\"string\":\"hello\",\"����\":[888,{\"obj\":99,\"array\":[null,true,false,99,{\"88\":88},null]}],\"����\":{},\"nu\":null,\"num\":0.93,\"bool\":true}";
	// ��ʽ�� json �ַ���
	pJsonObjectNode pJson = JSONParse(str);
	// ���û�����ַ�������
	JSONSetStringAttr(pJson, "nu", "hehehe");
	// ���û������������
	JSONSetNumberAttr(pJson, "num1", 1234);
	// ���û���� null ����
	JSONSetNullAttr(pJson, "null");
	// ���û������������
	JSONSetNumberAttr(pJson, "num1", 1234);
	// ȡ�� json ��������
	pJsonArrayNode pArr = NULL;
	JSONObjectGetArrayAttr(pJson, "����", &pArr);
	// ɾ������β����Ԫ��
	JSONArrayPop(pArr);

	JSONPrint(pJson);
	JSONStringify(pJson, &str);
	JSONDestroy(pJson);
	printf("%s\n", str);
	free(str);
	getchar();
	return 0;
}