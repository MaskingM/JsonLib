/*
 * json 数据类型可以分为 4 种基本类型：
 * Number Array String Object
 * json 自身可以看作一个 Object
 * 键值对采用hashMap的方式进行存放
 * 通过 数组链表 方式解决 hash 冲突
 * 添加属性时，如果属性值已经存在，则替换
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
* 创建 Object 空对象
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreate();

/*
* 创建 Array 空数组
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONCreateArray();

/*
 * json 格式化函数，将 json 字符串转换成 json 对象
 * @param	input		json 字符串
 * @return	pJsonObjectNode
*/
pJsonObjectNode JSONParse(char* input);

/*
* json 序列化，将 json 对象转换成 json 字符串
* @param	pNode pJsonNode			json 节点
* @param	output	char**			接收字符串的指针
* @return	void
*/
void JSONStringify(pJsonNode pNode /* in */, char** output /* out */);

/*
* 打印 json 节点
* @param	pNode pJsonNode		json 节点
* @return	void
*/
void JSONPrint(pJsonNode pNode /* in */);

/*
* 销毁 json 节点
* @param	pObject		json 节点
* @return	void
*/
void JSONDestroy(pJsonNode pNode /* in */);

/*
 * 判断 json 是否包含属性
 * @param	pObject		json 对象
 * @param	key			属性名称
 * @return	BOOLEAN		是否包含属性
*/
BOOLEAN JSONIsContainsAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
 * 向 json 对象中添加 Number类型 键值对象
 * @param	pObject		json 对象
 * @param	key			属性名称
 * @param	value		属性值
 * @return	void
*/
void JSONSetNumberAttr(pJsonObjectNode pObject /* in */, char* key /* in */, double value /* in */);

/*
 * 向 json 对象中添加 String类型 键值对象
 * @param	pObject		json 对象
 * @param	key			属性名称
 * @param	value		属性值
 * @return	void
*/
void JSONSetStringAttr(pJsonObjectNode pObject /* in */, char* key /* in */, char* value /* in */);

/*
 * 向 json 对象中添加 Array类型 键值对象，添加的数组为空数组
 * @param	pObject		json 对象
 * @param	key			属性名称
 * @return	void
*/
void JSONSetEmptyArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* 向 json 对象中添加 Array类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
* @param	value		pJsonArrayNode	数组节点
* @param	isDeepClone	BOOLEAN 是否进行深度拷贝
 * @return	void
*/
void JSONSetArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonArrayNode pArray, BOOLEAN isDeepClone);

/*
 * 向 json 对象中添加 Object类型 键值对象
 * @param	pObject		json 对象
 * @param	key			属性名称
 * @param	value		属性值
* @param	isDeepClone	BOOLEAN 是否进行深度拷贝
 * @return	void
*/
void JSONSetObjectAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonObjectNode value /* in */, BOOLEAN isDeepClone);

/*
* 向 json 对象中添加 null类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
* @return	void
*/
void JSONSetNullAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* 向 json 对象中添加 Boolean类型 键值对象
* @param	pObject				json 对象
* @param	key char*			属性名称
* @param	value Boolean		属性值
* @return	void
*/
void JSONSetBooleanAttr(pJsonObjectNode pObject /* in */, char* key /* in */, BOOLEAN value /* in */);

/*
 * 移除 json 对象中的属性
 * @param	pObject		json 对象
 * @param	key			属性名称
 * @return	void
*/
void JSONRemoveAttr(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* json 对象深拷贝
* @param	pObject json对象
* @return	pJsonObjectNode	新创建的json对象
*/
pJsonObjectNode JSONObjectDeepClone(pJsonObjectNode pObject /* in */);

/*
* json 数组深拷贝
* @param	pArray json数组
* @return	pJsonArrayNode	新创建的json Array
*/
pJsonArrayNode JSONArrayDeepClone(pJsonArrayNode pArray /* in */);

/*
* 向 json 数组节点中数组尾部追加数字
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	number double	需要添加的数字
* @return	void
*/
void JSONArrayPushNumber(pJsonArrayNode pArrayNode /* in */, double number /* in */);

/*
* 向 json 数组节点中数组尾部追加字符串
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pString char*	需要添加的字符串
* @return	void
*/
void JSONArrayPushString(pJsonArrayNode pArrayNode /* in */, char* pString /* in */);

/*
* 向 json 数组节点中数组尾部追加数组
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pArr pJsonArrayNode	需要添加的数组节点
* @return	void
*/
void JSONArrayPushArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */);

/*
* 向 json 数组节点中数组尾部追加对象
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pObject pJsonObjectNode	需要添加的对象节点
* @return	void
*/
void JSONArrayPushObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */);

/*
* 向 json 数组节点中数组尾部追加 null
* @param	pArrayNode pJsonArrayNode 数组节点
* @return	void
*/
void JSONArrayPushNull(pJsonArrayNode pArrayNode /* in */);

/*
* 向 json 数组节点中数组尾部追加 Boolean
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	value BOOLEAN	需要添加的 Boolean
* @return	void
*/
void JSONArrayPushBoolean(pJsonArrayNode pArrayNode /* in */, BOOLEAN value /* in */);

/*
* 向 json 数组节点中数组头部追加数字
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	number double	需要添加的数字
* @return	void
*/
void JSONArrayUnshiftNumber(pJsonArrayNode pArrayNode /* in */, double number /* in */);

/*
* 向 json 数组节点中数组头部追加字符串
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pString char*	需要添加的字符串
* @return	void
*/
void JSONArrayUnshiftString(pJsonArrayNode pArrayNode /* in */, char* pString /* in */);

/*
* 向 json 数组节点中数组头部追加数组
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pArr pJsonArrayNode	需要添加的数组
* @return	void
*/
void JSONArrayUnshiftArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */);

/*
* 向 json 数组节点中数组头部追加对象
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pObject pJsonObjectNode	需要添加的对象
* @return	void
*/
void JSONArrayUnshiftObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */);

/*
* 向 json 数组节点中数组头部追加 null
* @param	pArrayNode pJsonArrayNode 数组节点
* @return	void
*/
void JSONArrayUnshiftNull(pJsonArrayNode pArrayNode /* in */);

/*
* 向 json 数组节点中数组头部追加 Boolean
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	value BOOLEAN	需要添加的 Boolean
* @return	void
*/
void JSONArrayUnshiftBoolean(pJsonArrayNode pArrayNode /* in */, BOOLEAN value /* in */);

/*
* 获取数组类型的数据长度
* @param	pArray	pJsonArrayNode 数组节点
* @return	unsigned int	数组长度
*/
unsigned int JSONArrayGetLength(pJsonArrayNode pArray /* in */);

/*
* 获取数组指定位置元素
* @param	pArray	pJsonArrayNode 数组节点
* @param	pos		int
* @return	pJsonNode	数组元素
*/
pJsonNode JSONArrayGetNode(pJsonArrayNode pArray /* in */, int pos /* in */);

/*
* 向 json 数组节点中数组尾部删除元素，并销毁该元素
* @param	pArrayNode pJsonArrayNode 数组节点
* @return	void
*/
void JSONArrayPop(pJsonArrayNode pArrayNode /* in */);

/*
* 向 json 数组节点中数组头部删除元素，并销毁该元素
* @param	pArrayNode pJsonArrayNode 数组节点
* @return	void
*/
void JSONArrayShift(pJsonArrayNode pArrayNode /* in */);

/*
* 获取 Object 属性数据类型
* @param	pObject	pJsonObjectNode	json 对象
* @param	key char*		键值
* @return	JSON_DATA_TYPE		json 节点的数据类型
*/
JSON_DATA_TYPE JSONObjectGetAttrType(pJsonObjectNode pObject /* in */, char* key /* in */);

/*
* 获取 节点 数据类型
* @param	pNode	pJsonNode	节点
* @return	JSON_DATA_TYPE		json 节点的数据类型
*/
JSON_DATA_TYPE JSONNodeGetType(pJsonNode pNode /* in */);

/*
* 获取数字节点的数值
* @param	pNode	pJsonNumberNode	数字节点
* @param	pValue	double*
* @return	void
*/
void JSONNodeGetNumberValue(pJsonNumberNode pNode /* in */, double* pValue /* out */);

/*
* 获取字符串节点的的字符串
* @param	pNode	pJsonStringNode	字符串节点
* @param	ppValue	char**
* @return	void
*/
void JSONNodeGetStringValue(pJsonStringNode pNode /* in */, char** ppValue /* out */);

/*
* 获取 Boolean 节点的值
* @param	pNode	pJsonBooleanNode	Boolean节点
* @param	pValue	BOOLEAN*
* @return	void
*/
void JSONNodeGetBooleanValue(pJsonBooleanNode pNode /* in */, BOOLEAN* pValue /* out */);

/*
* 获取 json 数字属性节点的数值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*			键
* @param	pValue		double*			值
* @return	void
*/
void JSONObjectGetNumberAttr(pJsonObjectNode pObject /* in */, char* key /* in */, double* pValue /* out */);

/*
* 获取 json 字符串属性节点的字符串
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*			键
* @param	ppValue		char**			值
* @return	void
*/
void JSONObjectGetStringAttr(pJsonObjectNode pObject /* in */, char* key /* in */, char** ppValue /* out */);

/*
* 获取 json 数组属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*			键
* @param	ppValue		pJsonArrayNode*	值
* @return	void
*/
void JSONObjectGetArrayAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonArrayNode* ppValue /* out */);

/*
* 获取 json 对象属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*				键
* @param	ppValue		pJsonObjectNode*	值
* @return	void
*/
void JSONObjectGetObjectAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonObjectNode* ppValue /* out */);

/*
* 获取 json  null 属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*				键
* @param	pValue		pJsonNullNode*
* @return	void
*/
void JSONObjectGetNullAttr(pJsonObjectNode pObject /* in */, char* key /* in */, pJsonNullNode* ppValue /* out */);

/*
* 获取 json  Boolean 属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*				键
* @param	pValue		BOOLEAN*
* @return	void
*/
void JSONObjectGetBooleanAttr(pJsonObjectNode pObject /* in */, char* key /* in */, BOOLEAN* pValue /* out */);

#endif
