#include "jsonLib.h"

/*定义一些不需要暴露的功能*/
/*
* 计算 md5 加密后的字符串
* @param input 需要加密的字符串
* @param output 加密后的字符串，内存大小必须在33个字节
* @return void
*/
void encryptionStr(char *input /* in */, char *output /* out */);

/*
* 根据字符串，计算hash值
* @param	input 需要计算的字符串
* @return	unsigned long int 计算结果
*/
unsigned long int getHashVal(char *input /* in */);

/*
* 创建 Number 节点
* @param	key		char*	键名称
* @param	value	double	键值
* @return	pJsonNumberNode Number节点指针
*/
pJsonNumberNode JSONCreateNumberNode(char* key /* in */, double value /* in */);

/*
* 创建 String 节点
* @param	key		char* 键名称
* @param	value	char* 键值
* @return	pJsonStringNode String节点指针
*/
pJsonStringNode JSONCreateStringNode(char* key /* in */, char* value /* in */);

/*
* 创建 Array 空数组对象
* @param	key		char* 键名称
* @return	pJsonArrayNode Array节点指针
*/
pJsonArrayNode JSONCreateArrayNode(char* key /* in */);

/*
* 创建 Object 空对象
* @param	key		char* 键名称
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreateObjectNode(char* key /* in */);

/*
* 创建 null 节点
* @param	key		char*	键名称
* @return	pJsonNullNode null节点指针
*/
pJsonNullNode JSONCreateNullNode(char* key /* in */);

/*
* 创建 Boolean 节点
* @param	key		char*	键名称
* @param	value	BOOLEAN	键值
* @return	pJsonBooleanNode Boolean节点指针
*/
pJsonBooleanNode JSONCreateBooleanNode(char* key /* in */, BOOLEAN value /* in */);

/*
* 打印 Number
* @param	pNode pJsonNumberNode
* @return	void
*/
void JSONPrintNumberNode(pJsonNumberNode pNode /* in */);

/*
* 打印 String
* @param	pNode pJsonStringNode
* @return	void
*/
void JSONPrintStringNode(pJsonStringNode pNode /* in */);

/*
* 打印 Array
* @param	pNode pJsonArrayNode
* @return	void
*/
void JSONPrintArrayNode(pJsonArrayNode pNode /* in */);

/*
* 打印 json 对象
* @param	pObject		json 对象
* @return	void
*/
void JSONPrintObjectNode(pJsonObjectNode pObject /* in */);

/*
* 打印 null
* @param	pNode pJsonNullNode
* @return	void
*/
void JSONPrintNullNode(pJsonNullNode pNode /* in */);

/*
* 打印 Boolean
* @param	pNode pJsonBooleanNode
* @return	void
*/
void JSONPrintBooleanNode(pJsonBooleanNode pNode /* in */);

/*
* 销毁 Number 类型类型节点
* @param	pNode Number类型节点
* @return void
*/
void JSONDestroyNumberNode(pJsonNumberNode pNode /* in */);

/*
* 销毁 String 类型类型节点
* @param	pNode String类型节点
* @return void
*/
void JSONDestroyStringNode(pJsonStringNode pNode /* in */);

/*
* 销毁 Array 类型类型节点
* @param	pNode Array类型节点
* @return void
*/
void JSONDestroyArrayNode(pJsonArrayNode pNode /* in */);

/*
* 销毁 Object 类型类型节点
* @param	pNode Object类型节点
* @return void
*/
void JSONDestroyObjectNode(pJsonObjectNode pNode /* in */);

/*
* 销毁 null 类型类型节点
* @param	pNode null类型节点
* @return void
*/
void JSONDestroyNullNode(pJsonNullNode pNode /* in */);

/*
* 销毁 Boolean 类型类型节点
* @param	pNode Boolean类型节点
* @return void
*/
void JSONDestroyBooleanNode(pJsonBooleanNode pNode /* in */);

/*
* json 数字对象深拷贝
* @param	pNumber jsonNumber
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonNumberNode	新创建的json Number
*/
pJsonNumberNode JSONNumberDeepClone(pJsonNumberNode pNumber /* in */, BOOLEAN isCopyKey /* in */);

/*
* json 字符串对象深拷贝
* @param	pString jsonString
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonNumberNode	新创建的json Number
*/
pJsonStringNode JSONStringDeepClone(pJsonStringNode pString /* in */, BOOLEAN isCopyKey /* in */);

/*
* json null 对象深拷贝
* @param	pNull pJsonNullNode
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonNullNode	新创建的json null
*/
pJsonNullNode JSONNullDeepClone(pJsonNullNode pNull /* in */, BOOLEAN isCopyKey /* in */);

/*
* json Boolean 对象深拷贝
* @param	pNull pJsonBooleanNode
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonBooleanNode	新创建的json Boolean
*/
pJsonBooleanNode JSONBooleanDeepClone(pJsonBooleanNode pBoolean /* in */, BOOLEAN isCopyKey /* in */);

/*
* 向 json 数组节点中数组尾部追加元素
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pNode pJsonNode	需要添加的节点
* @return	void
*/
void JSONArrayPush(pJsonArrayNode pArrayNode /* in */, pJsonNode pNode /* in */);

/*
* 向 json 数组节点中数组头部追加元素
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pNode pJsonNode	需要添加的节点
* @return	void
*/
void JSONArrayUnshift(pJsonArrayNode pArrayNode /* in */, pJsonNode pNode /* in */);

/*
* 数字节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonNumberNode 数字节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
*/
char* JSONStringifyNumberNode(pJsonNumberNode pNode, BOOLEAN isContainsKey);

/*
* 字符串节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonStringNode 字符串节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
*/
char* JSONStringifyStringNode(pJsonStringNode pNode, BOOLEAN isContainsKey);

/*
* 数组节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonArrayNode 数组节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
*/
char* JSONStringifyArrayNode(pJsonArrayNode pNode, BOOLEAN isContainsKey);

/*
* 对象节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonObjectNode 数组节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
*/
char* JSONStringifyObjectNode(pJsonObjectNode pNode, BOOLEAN isContainsKey);

/*
* null 节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonNullNode null节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
*/
char* JSONStringifyNullNode(pJsonNullNode pNode, BOOLEAN isContainsKey);

/*
* Boolean 节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonBooleanNode Boolean节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
*/
char* JSONStringifyBooleanNode(pJsonBooleanNode pNode, BOOLEAN isContainsKey);

/*
* 去掉字符串中多余的逗号
* @param	input	char* 需要去逗号的字符串
* @return	char*	去逗号后的字符串
*/
char* JSONStringRemoveComma(char* input /* in */);

/*
* 判断 键是否有效
* @param	input	char* 输入的键
* @param	len		int	  长度
* @return	BOOLEAN		键名称是否合法
*/
BOOLEAN JSONKeyIsOk(char* input /* in */, int len /* in */);

/*
* json 字符串去空格等不可见字符
* @param	input	char*	需要去空格的字符串
* @return	char*	去空格后的字符串
*/
char* JSONStringTrim(char* input /* in */);

/*
* null 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringNullIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* Boolean 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringBooleanIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* String 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringStringIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* 数字类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringNumberIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* Array 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringArrayIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* Object 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringObjectIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */);

/*
* 判断 json 字符串是否合法
* @param	input	char*	需要解析的字符串
* @return	BOOLEAN			符合格式要求，返回 BTRUE 否则返回 BFALSE
*/
BOOLEAN JSONStringIsFormat(char* input /* in */);

/*
* 字符串是否是数组
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
*/
BOOLEAN strIsArray(char* input /* in */, int len /* in */);

/*
* 字符串是否是对象
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
*/
BOOLEAN strIsObject(char* input /* in */, int len /* in */);

/*
* 格式化 json 数组
* @param	input	char* 需要格式化的字符串
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONParseArray(char* input /* in */);

/*
* 格式化 json 对象
* @param	input	char* 需要格式化的字符串
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONParseObject(char* input /* in */);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
// 格式化的时候，针对不同的结构进行分类格式化

/*
* 字符串是否是数字
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
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
		BOOLEAN badChar = BFALSE; // 不合法字符
		// 则此时为纯数字
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
		// 科学记数法
		if ((p = strstr(buf, "e+")) || (p = strstr(buf, "E+"))) {
			if (strlen(p) == 2) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			// 判断科学记数法指数是否合法
			if (strstr(p + 2, "e") || strstr(p + 2, "E") || strstr(p + 2, "+") || strstr(p + 2, ".")) {
				badChar = BTRUE;
				goto STR_IS_NUMBER_LABLE;
			}
			// 判断科学记数法倍数是否合法
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
			// 十进制表示法
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
* 字符串是否是字符串
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
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
		BOOLEAN badChar = BFALSE; // 不合法字符
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
* 字符串是否是 null
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
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
* 字符串是否是 Boolean
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
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
* 字符串是否是数组
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
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
				// 标志接下来的元素是字符串
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
					// 已经匹配到最近的引号
					if (idx == len - 2) {
						// 此时字符串是最后一个元素，判断字符串是否合法
						badChar = !strIsString(buf+i, idx + 1 - i);
						break;
					}
					else {
						badChar = !strIsString(buf + i, idx + 1 - i);
						if (badChar) {
							break;
						}
						// 距离结尾只有一个字符了，不足以存放数据
						if (idx == len - 3) {
							badChar = BTRUE;
							break;
						}
						// 下一个字符不是数组分割符
						if (buf[idx+1] != ',') {
							badChar = BTRUE;
							break;
						}
						i = idx + 1;
					}
				}
				else {
					// 没有匹配到
					badChar = BTRUE;
					break;
				}
			}
			else if (buf[i] == '[') {
				// 标志接下来的属性是数组
				// 需要索引到匹配的数组符号
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
					// 数组不匹配
					badChar = BTRUE;
					break;
				}
				badChar = !strIsArray(buf + i, idx + 1 - i);
			}
			else if (buf[i] == '{') {
				// 标志接下来是对象
				// 标志接下来的属性是数组
				// 需要索引到匹配的数组符号
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
					// 数组不匹配
					badChar = BTRUE;
					break;
				}
				badChar = !strIsObject(buf + i, idx + 1 - i);
			}
			else if (buf[i] == 'f' || buf[i] == 't') {
				// 标志接下来是 true 或 false
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
				// 标志接下来是 null
				// 标志接下来是 true 或 false
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
				// 接下来是数字
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
			// 已经到结尾
			if (idx == len - 2) {
				break;
			}
			if (idx == len - 3) {
				badChar = BTRUE;
				break;
			}
			// 下一个字符不是数组分割符
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
* 字符串是否是对象
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @return	BOOLEAN		字符串合法
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

				// 遍历到结尾，未曾找到结尾
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
						// 此处需要进行判断数据类型了
						int curIdx = idx + 2;
						idx = curIdx + 1;
						if (buf[curIdx] == '\"') {
							// 值为字符串
							while (idx <= len - 2) {
								if (buf[idx] == '\"') {
									break;
								}
								idx++;
							}
							// 已经到结尾了，但是没匹配到字符串
							badChar = !JSONStringStringIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == '[') {
							// 值为数组
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
								// 数组不匹配
								badChar = BTRUE;
								break;
							}
							badChar = !JSONStringArrayIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == '{') {
							// 值为对象
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
								// 数组不匹配
								badChar = BTRUE;
								break;
							}
							badChar = !JSONStringObjectIsFormat(buf + i, idx - i + 1, BTRUE);
						}
						else if (buf[curIdx] == 'n') {
							// 值为 null
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
							// 值为 Boolean
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
							// 值为 Number
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
							// 字符串为最后一个元素
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
* 数字类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringNumberIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 0) {
			break;
		}
		int quotationMarks		= 0; // 引号计数
		char ch					= 0;
		int quotPosLeft			= 0; // 左引号位置
		int quotPosRight		= 0; // 右引号位置
		BOOLEAN badKey			= BFALSE; // 不合法键名称
		BOOLEAN colonCount		= 0;//计数
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
* null 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringNullIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 3) {
			break;
		}
		int quotationMarks = 0; // 引号计数
		char ch = 0;
		int quotPosLeft = 0; // 左引号位置
		int quotPosRight = 0; // 右引号位置
		BOOLEAN badKey = BFALSE; // 不合法键名称
		BOOLEAN colonCount = 0;//计数

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
* Boolean 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringBooleanIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 3) {
			break;
		}
		int quotationMarks = 0; // 引号计数
		char ch = 0;
		int quotPosLeft = 0; // 左引号位置
		int quotPosRight = 0; // 右引号位置
		BOOLEAN badKey = BFALSE; // 不合法键名称
		BOOLEAN colonCount = 0;//计数

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
* String 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringStringIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 1) {
			break;
		}
		int quotationMarks = 0; // 引号计数
		char ch = 0;
		int quotPosLeft = 0; // 左引号位置
		int quotPosRight = 0; // 右引号位置
		BOOLEAN badKey = BFALSE; // 不合法键名称
		BOOLEAN colonCount = 0;//计数

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
* Array 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringArrayIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 1) {
			break;
		}
		int quotationMarks = 0; // 引号计数
		char ch = 0;
		int quotPosLeft = 0; // 左引号位置
		int quotPosRight = 0; // 右引号位置
		BOOLEAN badKey = BFALSE; // 不合法键名称
		BOOLEAN colonCount = 0;//计数
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
* Object 类型键值对字符串格式是否合法
* @param	input char* 输入的字符串
* @param	len		int	  长度
* @param	isHasKey	BOOLEAN 是否包含键
* @return	BOOLEAN		字符串合法
*/
BOOLEAN JSONStringObjectIsFormat(char* input /* in */, int len /* in */, BOOLEAN isHasKey /* in */) {
	BOOLEAN res = BFALSE;
	do {
		if (!input || len <= 1) {
			break;
		}
		int quotationMarks = 0; // 引号计数
		char ch = 0;
		int quotPosLeft = 0; // 左引号位置
		int quotPosRight = 0; // 右引号位置
		BOOLEAN badKey = BFALSE; // 不合法键名称
		BOOLEAN colonCount = 0;//计数
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
* 去掉字符串中多余的逗号
* @param	input	char* 需要去逗号的字符串
* @return	char*	去逗号后的字符串
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
		// 引号计数
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
* 判断 键是否有效
* @param	input	char* 输入的键
* @param	len		int	  长度
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
* json 字符串去空格等不可见字符
* @param	input	char*	需要去空格的字符串
* @return	char*	去空格后的字符串
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
		// 引号计数
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
* 判断 json 字符串是否合法
* @param	input	char*	需要解析的字符串
* @return	BOOLEAN			符合格式要求，返回 BTRUE 否则返回 BFALSE
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
* 计算 md5 加密后的字符串
* @param input 需要加密的字符串
* @param output 加密后的字符串，内存大小必须在33个字节
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
* 根据字符串，计算hash值
* @param input 需要计算的字符串
* @return unsigned long int 计算结果
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
* 根据 json key 值，转换成 int 值
* @param	key json 键
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
	//printf("属性: %s, 索引: %d\n", key, idx);
	return idx;
}

/*
* 深拷贝字符串
* @param	input	输入的字符串
* @return	char*	分配的字符串内存
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
* 创建 Object 空对象
* @param	key		char* 键名称
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreateObjectNode(char* key /* in */) {
	pJsonObjectNode pObject = NULL;
	do {
		pObject = (pJsonObjectNode)malloc(sizeof(JsonObjectNode));
		if (!pObject) {
			// json对象内存分配失败
			break;
		}
		memset(pObject, 0, sizeof(JsonObjectNode));
		if (key) {
			pObject->node.keyName = deepCloneString(key);
			if (!pObject->node.keyName) {
				// 拷贝名称失败，则节点毫无意义
				JSONDestroyObjectNode(pObject);
				break;
			}
		}
		pObject->node.type = JSONTYPEOBJECT;
	} while (0);
	return pObject;
}

/*
* 创建 Number 节点
* @param	key		char*	键名称
* @param	value	double	键值
* @return	pJsonNumberNode Number节点指针
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
				// 拷贝名称失败，则节点毫无意义
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
* 创建 String 节点
* @param	key		char* 键名称
* @param	value	char* 键值
* @return	pJsonStringNode String节点指针
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
				// 拷贝名称失败，则节点毫无意义
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
* 创建 Array 空数组对象
* @param	key		char* 键名称
* @return	pJsonArrayNode Array节点指针
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
				// 拷贝名称失败，则节点毫无意义
				JSONDestroyArrayNode(pNode);
				break;
			}
		}
		pNode->node.type = JSONTYPEARRAY;
	} while (0);
	return pNode;
}

/*
* 创建 null 节点
* @param	key		char*	键名称
* @return	pJsonNullNode null节点指针
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
				// 拷贝名称失败，则节点毫无意义
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
* 创建 Boolean 节点
* @param	key		char*	键名称
* @param	value	BOOLEAN	键值
* @return	pJsonBooleanNode Boolean节点指针
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
				// 拷贝名称失败，则节点毫无意义
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
* 创建 Object 空对象
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONCreate() {
	return JSONCreateObjectNode(NULL);
}

/*
* 创建 Array 空数组
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONCreateArray() {
	return JSONCreateArrayNode(NULL);
}

/*
* 格式化 json 数组
* @param	input	char* 需要格式化的字符串
* @return	pJsonArrayNode
*/
pJsonArrayNode JSONParseArray(char* input /* in */) {
	pJsonArrayNode pArray = NULL;
	do {
		if (!input || strlen(input) < 2) {
			break;
		}
		int len = strlen(input);
		// 字符串格式已经做了校验，所以无需考虑格式问题
		pArray = JSONCreateArray();
		if (!pArray || len == 2) {
			break;
		}
		int idx = 0;
		char* element = NULL;
		for (int i = 1; i < len - 1; i++) {
			if (input[i] == '\"') {
				// 元素是字符串
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
* 格式化 json 对象
* @param	input	char* 需要格式化的字符串
* @return	pJsonObjectNode
*/
pJsonObjectNode JSONParseObject(char* input /* in */) {
	pJsonObjectNode pObject = NULL;
	do {
		if (!input || strlen(input) < 2) {
			break;
		}
		int len = strlen(input);
		// 字符串格式已经做了校验，所以无需考虑格式问题
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
				///////////////////////// 记得销毁 key //////////////////////////
				idx += 2;
				int valIdx = 0;
				char* value = NULL;
				if (input[idx] == '\"') {
					// 值是字符串
					valIdx = idx + 1;
					while (valIdx <= len - 2) {
						if (input[valIdx] == '\"') {
							break;
						}
						valIdx++;
					}
					if (valIdx - idx == 2) {
						// 空字符串
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
					// 值是 null
					JSONSetNullAttr(pObject, key);
					valIdx = idx + 3;
				}
				else if (input[idx] == 't' || input[idx] == 'f') {
					// 值是 boolean
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
					// 值是 number
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
					// 值是 array
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
					// 值是 object
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
					// 其他情况，释放键
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
* json 格式化函数，将 json 字符串转换成 json 对象
* @param	input		json 字符串
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
* json 序列化，将 json 对象转换成 json 字符串
* @param	pNode pJsonNode			json 节点
* @param	output	char**			接收字符串的指针
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
* 数字节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonNumberNode 数字节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
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
* 字符串节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonStringNode 字符串节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
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
* 数组节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonArrayNode 数组节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
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
				int len = strlen(pNode->node.keyName) + 5;	// 需要存放引号冒号等
				if (len > TMP_BUF_SIZE) {
					// 名称长度过大，需要开辟内存来存放
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
		// 进行序列化数组元素
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
							// 将序列数据放入结果区，并把临时缓冲区清空
							// 重新分配内存存放数据
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
							// 将数据存入缓冲区
							strcat(tmpBuf, pTmpStringify);
							strcat(tmpBuf, ",");
						}
						free(pTmpStringify);
						pTmpStringify = NULL;
					}
				}
			}
		}
		// 追加结尾
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
* 对象节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonObjectNode 对象节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
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
				int len = strlen(pNode->node.keyName) + 5;	// 需要存放引号冒号等
				if (len > TMP_BUF_SIZE) {
					// 名称长度过大，需要开辟内存来存放
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
		// 进行序列化属性节点
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
							// 将序列数据放入结果区，并把临时缓冲区清空
							// 重新分配内存存放数据
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
							// 将数据存入缓冲区
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
		// 追加结尾
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
* null 节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonNullNode null节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
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
* Boolean 节点序列化，做数组元素，不需要键名称
* @param	pNode	pJsonBooleanNode Boolean节点
* @param	isContainsKey	BOOLEAN	是否包含键
* @return	char*	序列化字符串
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
* 判断 json 是否包含属性
* @param	pObject		json 对象
* @param	key			属性名称
* @return	BOOLEAN		是否包含属性
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
			// 进行链式遍历
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
* 向 json 对象中添加 Number类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
* @param	value		属性值
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
				// Number节点内存分配失败
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
						// Number节点内存分配失败
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
						// Number节点内存分配失败
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
* 向 json 对象中添加 String类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
* @param	value		属性值
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
				// String节点内存分配失败
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
							// String节点值内存分配失败
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
						// String节点内存分配失败
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
						// String节点内存分配失败
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
* 向 json 对象中添加 Array类型 键值对象，添加的数组为空数组
* @param	pObject		json 对象
* @param	key			属性名称
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
				// Array节点内存分配失败
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
						// Array节点内存分配失败
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
						// Array节点内存分配失败
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
* 向 json 对象中添加 Array类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
* @param	value		pJsonArrayNode	数组节点
* @param	isDeepClone	BOOLEAN 是否进行深度拷贝
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
				// Array节点内存分配失败
				break;
			}
			// 重新对数组进行名称赋值
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
						// Array节点内存分配失败
						break;
					}
					// 重新对数组进行名称赋值
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
						// Array节点内存分配失败
						break;
					}
					// 重新对数组进行名称赋值
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
* 向 json 对象中添加 Object类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
* @param	value		属性值
* @param	isDeepClone	BOOLEAN 是否进行深度拷贝
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
		// 自己不能作为自己的子节点
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
						// 节点已存在，不需要重复添加
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
						// Object节点内存分配失败
						break;
					}
					// 重新对Object进行名称赋值
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
						// Object节点内存分配失败
						break;
					}
					// 重新对数组进行名称赋值
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
* 向 json 对象中添加 null类型 键值对象
* @param	pObject		json 对象
* @param	key			属性名称
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
				// Null节点内存分配失败
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
						// Null节点内存分配失败
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
						// null节点内存分配失败
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
* 向 json 对象中添加 Boolean类型 键值对象
* @param	pObject				json 对象
* @param	key char*			属性名称
* @param	value Boolean		属性值
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
				// Boolean节点内存分配失败
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
						// Number节点内存分配失败
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
						// Number节点内存分配失败
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
* 移除 json 对象中的属性
* @param	pObject		json 对象
* @param	key			属性名称
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
* 销毁 json 节点
* @param	pObject		json 节点
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
* json 对象深拷贝
* @param	pObject json对象
* @return	pJsonObjectNode	新创建的json对象
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
			// 深拷贝时，json对象节点内存分配失败
			break;
		}
		
		// 拷贝hash表
		for (int i = 0; i < HASH_MAX; i++) {
			if (pObject->table[i]) {
				// 需要进行链式拷贝
				pJsonNode pPre = NULL;
				pJsonNode pCur = pObject->table[i];
				pJsonNode pNext = pObject->table[i]->next;
				int num = 0;
				while (pCur) {
					// 拷贝时如果拷贝到对象，或者自身怎么办
					if (pCur == (pJsonNode)pObject || (num != 0 && pCur == pObject->table[i])) {
						break;
					}
					num++;
					pJsonNode pTmpNode = NULL;
					if (pCur->type == JSONTYPENUMBER) {
						pTmpNode = (pJsonNode)JSONCreateNumberNode(pCur->keyName, ((pJsonNumberNode)pCur)->value);
						if (!pTmpNode) {
							// 深拷贝时，json对象Number属性节点内存分配失败
							break;
						}
					}
					else if (pCur->type == JSONTYPESTRING) {
						pTmpNode = (pJsonNode)JSONCreateStringNode(pCur->keyName, ((pJsonStringNode)pCur)->value);
						if (!pTmpNode) {
							// 深拷贝时，json对象String属性节点内存分配失败;
							break;
						}
					}
					else if (pCur->type == JSONTYPEARRAY) {
						// 数组节点
						pTmpNode = (pJsonNode)JSONArrayDeepClone((pJsonArrayNode)pCur);
					}
					else if (pCur->type == JSONTYPEOBJECT) {
						// Object几点直接递归
						pTmpNode = (pJsonNode)JSONObjectDeepClone((pJsonObjectNode)pCur);
					}
					else if (pCur->type == JSONTYPENULL) {
						// null 节点
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
							// 链表断裂，无法继续链接下去，需要中断当前循环，并进行释放当前创建的节点
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
* json 数组深拷贝
* @param	pArray json数组
* @return	pJsonArrayNode	新创建的json Array
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
		// 存放元素的类型
		pArrayNode->type = pArray->type;
		// 拷贝数组元素
		if (pArray->size && pArray->array) {
			// 计算数组分配内存空间，数组节点的元素数组空间默认不分配，只有添加元素才进行分配
			// 介于内存分配考虑，每次分配 ARRAY_MIN_SIZE 大小，当缓冲区越界的时候，重新分配，以节约内存
			int size = (pArray->size / ARRAY_MIN_SIZE + (pArray->size % ARRAY_MIN_SIZE == 0 ? 0 : 1)) * ARRAY_MIN_SIZE;
			pArrayNode->array = (pJsonNode*)malloc(size * sizeof(pJsonNode));
			if (!pArrayNode->array) {
				// 数组空间分配失败
				pArrayNode->size = 0;
				pArrayNode->type = JSONTYPEUNDEFINED;
				break;
			}
			memset(pArrayNode->array, 0, size * sizeof(pJsonNode));
			// 进行数组元素深拷贝
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
* json 数字对象深拷贝
* @param	pNumber jsonNumber
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonNumberNode	新创建的json Number
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
		// 属性拷贝的时候，需要对键名称进行拷贝，做为数组元素的时候则不需要键名称
		if (isCopyKey) {
			if (pNumber->node.keyName) {
				pNumberNode->node.keyName = deepCloneString(pNumber->node.keyName);
				if (!pNumberNode->node.keyName) {
					// 拷贝键名称的时候，内存无法分配，则节点没有存在的意义
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
* json 字符串对象深拷贝
* @param	pString jsonString
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonNumberNode	新创建的json Number
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
		// 属性拷贝的时候，需要对键名称进行拷贝，做为数组元素的时候则不需要键名称
		if (isCopyKey) {
			if (pString->node.keyName) {
				pStringNode->node.keyName = deepCloneString(pString->node.keyName);
				if (!pStringNode->node.keyName) {
					// 拷贝键名称的时候，内存无法分配，则节点没有存在的意义
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
* json null 对象深拷贝
* @param	pNull pJsonNullNode
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonNullNode	新创建的json null
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
		// 属性拷贝的时候，需要对键名称进行拷贝，做为数组元素的时候则不需要键名称
		if (isCopyKey) {
			if (pNull->node.keyName) {
				pNode->node.keyName = deepCloneString(pNull->node.keyName);
				if (!pNode->node.keyName) {
					// 拷贝键名称的时候，内存无法分配，则节点没有存在的意义
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
* json Boolean 对象深拷贝
* @param	pNull pJsonBooleanNode
* @param	isCopyKey char* 是否进行键名称拷贝
* @return	pJsonBooleanNode	新创建的json Boolean
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
		// 属性拷贝的时候，需要对键名称进行拷贝，做为数组元素的时候则不需要键名称
		if (isCopyKey) {
			if (pBoolean->node.keyName) {
				pNode->node.keyName = deepCloneString(pBoolean->node.keyName);
				if (!pNode->node.keyName) {
					// 拷贝键名称的时候，内存无法分配，则节点没有存在的意义
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
* 销毁 Number 类型类型节点
* @param	pNode Number类型节点
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
* 销毁 String 类型类型节点
* @param	pNode String类型节点
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
* 销毁 Array 类型类型节点
* @param	pNode Array类型节点
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
		//printf("销毁 Array 节点，属性名称: %s\n", pNode->node.keyName);
		if (pNode->node.keyName) {
			free(pNode->node.keyName);
			pNode->node.keyName = NULL;
		}
		free(pNode);
		pNode = NULL;
	} while (0);
}

/*
* 销毁 Object 类型类型节点
* @param	pNode Object类型节点
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
			// 判断当前属性是否存在，存在则销毁
			if (pNode->table[i]) {
				// 对当前属性，进行链表式销毁
				pJsonNode pNext = NULL;
				do {
					if (!pNode->table[i]) {
						break;
					}
					pNext = pNode->table[i]->next;
					if (pNode->table[i]->type == JSONTYPENUMBER) {
						// 数字类型，直接销毁节点
						JSONDestroyNumberNode((pJsonNumberNode)pNode->table[i]);
					}
					else if (pNode->table[i]->type == JSONTYPESTRING) {
						// 字符串类型，先进行销毁字符串空间
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
* 销毁 null 类型类型节点
* @param	pNode null类型节点
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
* 销毁 Boolean 类型类型节点
* @param	pNode Boolean类型节点
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
* 向 json 数组节点中数组尾部追加元素
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pNode pJsonNode	需要添加的节点
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
		//// 数组类型，和需要插入的数据类型是否匹配
		//if (pArrayNode->type != JSONTYPEUNDEFINED && (pArrayNode->type != pNode->type)) {
		//	break;
		//}
		if (pNode->type == JSONTYPEUNDEFINED) {
			break;
		}
		// 判断数组是否需要扩容
		int minSize = (pArrayNode->size / ARRAY_MIN_SIZE) * ARRAY_MIN_SIZE;
		if (minSize >= pArrayNode->size) {
			// 需扩容
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
		// 第一次插入元素时
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
* 向 json 数组节点中数组头部追加元素
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pNode pJsonNode	需要添加的节点
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
		// 数组类型，和需要插入的数据类型是否匹配
		if (pArrayNode->type != JSONTYPEUNDEFINED && (pArrayNode->type != pNode->type)) {
			break;
		}
		if (pNode->type == JSONTYPEUNDEFINED) {
			break;
		}
		// 判断数组是否需要扩容
		int minSize = (pArrayNode->size / ARRAY_MIN_SIZE) * ARRAY_MIN_SIZE;
		if (minSize >= pArrayNode->size) {
			// 需扩容
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
		// 第一次插入元素时
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
* 向 json 数组节点中数组尾部追加数字
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	number double	需要添加的数字
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
* 向 json 数组节点中数组尾部追加字符串
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pString char*	需要添加的字符串
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
* 向 json 数组节点中数组尾部追加数组
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pArr pJsonArrayNode	需要添加的数组节点
* @return	void
*/
void JSONArrayPushArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */) {
	JSONArrayPush(pArrayNode, (pJsonNode)pArr);
}

/*
* 向 json 数组节点中数组尾部追加对象
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pObject pJsonObjectNode	需要添加的对象节点
* @return	void
*/
void JSONArrayPushObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */) {
	JSONArrayPush(pArrayNode, (pJsonNode)pObject);
}

/*
* 向 json 数组节点中数组尾部追加 null
* @param	pArrayNode pJsonArrayNode 数组节点
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
* 向 json 数组节点中数组尾部追加 Boolean
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	value BOOLEAN	需要添加的 Boolean
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
* 向 json 数组节点中数组头部追加数字
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	number double	需要添加的数字
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
* 向 json 数组节点中数组头部追加字符串
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pString char*	需要添加的字符串
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
* 向 json 数组节点中数组头部追加数组
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pArr pJsonArrayNode	需要添加的数组
* @return	void
*/
void JSONArrayUnshiftArray(pJsonArrayNode pArrayNode /* in */, pJsonArrayNode pArr /* in */) {
	JSONArrayUnshift(pArrayNode, (pJsonNode)pArr);
}

/*
* 向 json 数组节点中数组头部追加对象
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	pObject pJsonObjectNode	需要添加的对象
* @return	void
*/
void JSONArrayUnshiftObject(pJsonArrayNode pArrayNode /* in */, pJsonObjectNode pObject /* in */) {
	JSONArrayUnshift(pArrayNode, (pJsonNode)pObject);
}

/*
* 向 json 数组节点中数组头部追加 null
* @param	pArrayNode pJsonArrayNode 数组节点
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
* 向 json 数组节点中数组头部追加 Boolean
* @param	pArrayNode pJsonArrayNode 数组节点
* @param	value BOOLEAN	需要添加的 Boolean
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
* 向 json 数组节点中数组尾部删除元素，并销毁该元素
* @param	pArrayNode pJsonArrayNode 数组节点
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
			// 释放数组空间
			free(pArrayNode->array);
			pArrayNode->array = NULL;
		}
	} while (0);
}

/*
* 向 json 数组节点中数组头部删除元素，并销毁该元素
* @param	pArrayNode pJsonArrayNode 数组节点
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
			// 释放数组空间
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
* 获取数组类型的数据长度
* @param	pArray	pJsonArrayNode 数组节点
* @return	unsigned int	数组长度
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
* 获取数组指定位置元素
* @param	pArray	pJsonArrayNode 数组节点
* @param	pos		int
* @return	pJsonNode	数组元素
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
* 获取 节点 数据类型
* @param	pNode	pJsonNode	节点
* @return	JSON_DATA_TYPE		json 节点的数据类型
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
* 获取 Object 属性数据类型
* @param	pObject	pJsonObjectNode	json 对象
* @param	key char*		键值
* @return	JSON_DATA_TYPE		json 节点的数据类型
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
			// 进行链式遍历
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
* 获取数字节点的数值
* @param	pNode	pJsonNumberNode	数字节点
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
* 获取字符串节点的的字符串
* @param	pNode	pJsonStringNode	字符串节点
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
* 获取 Boolean 节点的值
* @param	pNode	pJsonBooleanNode	数字节点
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
* 获取 json 数字属性节点的数值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*			键
* @param	pValue		double*			值
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
			// 进行链式遍历
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
* 获取 json 字符串属性节点的字符串
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*			键
* @param	ppValue		char**			值
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
			// 进行链式遍历
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
* 获取 json 数组属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*			键
* @param	ppValue		pJsonArrayNode*	值
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
			// 进行链式遍历
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
* 获取 json 对象属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*				键
* @param	ppValue		pJsonObjectNode*	值
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
			// 进行链式遍历
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
* 获取 json  null 属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*				键
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
			// 进行链式遍历
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
* 获取 json  Boolean 属性节点的值
* @param	pObject		pJsonObjectNode json 对象
* @param	key			char*				键
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
			// 进行链式遍历
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
* 打印 Number
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
* 打印 String
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
* 打印 Array
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
* 打印 json 对象
* @param	pObject		json 对象
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
* 打印 null
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
* 打印 Boolean
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
* 打印 json 节点
* @param	pNode pJsonNode		json 节点
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