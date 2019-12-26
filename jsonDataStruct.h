#ifndef __JSON_DATA_STRUCT
#define __JSON_DATA_STRUCT

#define HASH_MAX		128		// hash table ��С
#define ARRAY_MIN_SIZE	128		// ����ڵ���Сֵ�����׷��Ԫ�ص�ʱ�򳬳���Χ������������ڴ�
#define TMP_BUF_SIZE	32		// ��ʱ��������С�����ڴ����ʱ���ݣ�����Ƶ������С�ڴ�

#define BFALSE	0
#define BTRUE	1
typedef int BOOLEAN;
#define null	NULL

// JSON �Ļ�����������
typedef enum  {
	JSONTYPEUNDEFINED = 0,
	JSONTYPENUMBER = 1,
	JSONTYPESTRING,
	JSONTYPEARRAY,
	JSONTYPEOBJECT,
	JSONTYPEBOOLEAN,
	JSONTYPENULL
} JSON_DATA_TYPE;

// JSON �����ڵ㣬��� hash ��ͻ����ͨ����ͨ������ʽ׷������
typedef struct __json_data_node{
	JSON_DATA_TYPE type;			// JSON �ڵ����������
	char* keyName;
	struct __json_data_node* next;
} JsonNode, *pJsonNode;

// JSON Number ����
typedef struct {
	JsonNode node;
	double value;
} JsonNumberNode, *pJsonNumberNode;

// JSON String ����
typedef struct {
	JsonNode node;
	char* value;
} JsonStringNode, *pJsonStringNode;

// JSON Arrary ���� 
typedef struct {
	JsonNode node;
	// �������ͣ���Ҫ��������С������ָ�룬�Լ���ŵ���������
	int size;
	JSON_DATA_TYPE type;
	pJsonNode *array;
} JsonArrayNode, *pJsonArrayNode;

// JSON Object ���� 
typedef struct {
	JsonNode node;
	pJsonNode table[HASH_MAX];
} JsonObjectNode, *pJsonObjectNode;

// JSON null ���� 
typedef struct {
	JsonNode node;
	int value;
} JsonNullNode, *pJsonNullNode;

// JSON Boolean ���� 
typedef struct {
	JsonNode node;
	BOOLEAN value;
} JsonBooleanNode, *pJsonBooleanNode;

#endif