#ifndef __JSON_DATA_STRUCT
#define __JSON_DATA_STRUCT

#define HASH_MAX		128		// hash table 大小
#define ARRAY_MIN_SIZE	128		// 数组节点最小值，如果追加元素的时候超出范围，则继续分配内存
#define TMP_BUF_SIZE	32		// 临时缓冲区大小，用于存放临时数据，避免频繁开辟小内存

#define BFALSE	0
#define BTRUE	1
typedef int BOOLEAN;
#define null	NULL

// JSON 的基本数据类型
typedef enum  {
	JSONTYPEUNDEFINED = 0,
	JSONTYPENUMBER = 1,
	JSONTYPESTRING,
	JSONTYPEARRAY,
	JSONTYPEOBJECT,
	JSONTYPEBOOLEAN,
	JSONTYPENULL
} JSON_DATA_TYPE;

// JSON 基本节点，如果 hash 冲突，则通过则通过链表方式追加属性
typedef struct __json_data_node{
	JSON_DATA_TYPE type;			// JSON 节点的数据类型
	char* keyName;
	struct __json_data_node* next;
} JsonNode, *pJsonNode;

// JSON Number 数据
typedef struct {
	JsonNode node;
	double value;
} JsonNumberNode, *pJsonNumberNode;

// JSON String 数据
typedef struct {
	JsonNode node;
	char* value;
} JsonStringNode, *pJsonStringNode;

// JSON Arrary 数据 
typedef struct {
	JsonNode node;
	// 数组类型，需要存放数组大小，数组指针，以及存放的数据类型
	int size;
	JSON_DATA_TYPE type;
	pJsonNode *array;
} JsonArrayNode, *pJsonArrayNode;

// JSON Object 数据 
typedef struct {
	JsonNode node;
	pJsonNode table[HASH_MAX];
} JsonObjectNode, *pJsonObjectNode;

// JSON null 数据 
typedef struct {
	JsonNode node;
	int value;
} JsonNullNode, *pJsonNullNode;

// JSON Boolean 数据 
typedef struct {
	JsonNode node;
	BOOLEAN value;
} JsonBooleanNode, *pJsonBooleanNode;

#endif