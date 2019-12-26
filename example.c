
#include "jsonLib.h"


int main() {
	char* str = "{\"string\":\"hello\",\"数组\":[888,{\"obj\":99,\"array\":[null,true,false,99,{\"88\":88},null]}],\"对象\":{},\"nu\":null,\"num\":0.93,\"bool\":true}";
	// 格式化 json 字符串
	pJsonObjectNode pJson = JSONParse(str);
	// 设置或添加字符串属性
	JSONSetStringAttr(pJson, "nu", "hehehe");
	// 设置或添加数字属性
	JSONSetNumberAttr(pJson, "num1", 1234);
	// 设置或添加 null 属性
	JSONSetNullAttr(pJson, "null");
	// 设置或添加数字属性
	JSONSetNumberAttr(pJson, "num1", 1234);
	// 取出 json 数组属性
	pJsonArrayNode pArr = NULL;
	JSONObjectGetArrayAttr(pJson, "数组", &pArr);
	// 删除数组尾部的元素
	JSONArrayPop(pArr);

	JSONPrint(pJson);
	JSONStringify(pJson, &str);
	JSONDestroy(pJson);
	printf("%s\n", str);
	free(str);
	getchar();
	return 0;
}