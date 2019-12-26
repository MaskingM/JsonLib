# JsonLib
纯C语言编写的json库，可以进行json序列化和反序列化

该库主要用于 **json** 字符串的反序列化，以及将 **json** 对象进行序列化。通过修改 **hash** 表，及数组最小尺寸大小，可以适用于嵌入式设备进行 **json** 处理。例如：
#define HASH_MAX		32
ARRAY_MIN_SIZE	32

**主要功能函数介绍：**
**1.JSONCreate**：创建一个 **json** 对象，函数的返回值是一个 **json** 对象指针；
**2.JSONStringify**：将 **json** 对象序列化为 **json** 字符串；
**3.JSONParse**：将 **json** 字符串反序列化成 **json** 对象；
**4.JSONPrint**：以结构化的方式进行打印 **json** 对象，方便查看；
**5.JSONDestroy**：销毁 **json** 对象，进行内存回收；
**6.JSONIsContainsAttr**：检测 **json**对象是否包含某个属性；
**7.JSONSetNumberAttr**：为 **json** 对象添加一个数字属性节点，如果该属性节点已存在，则进行设置成数字类型；
**8.JSONSetStringAttr**：为 **json** 对象添加一个字符串属性节点，如果该属性节点已存在，则进行设置成字符串类型；
**9.JSONSetEmptyArrayAttr**：为 **json** 对象添加一个空数组属性节点，如果该属性节点已存在，则进行设置成数组类型；
**10.JSONSetArrayAttr**：为 **json** 对象添加一个数组属性节点，如果该属性节点已存在，则进行设置成数组类型；
**11.JSONSetObjectAttr**：为 **json** 对象添加一个数字属性节点，如果该属性节点已存在，则进行设置成数字类型；
**12.JSONSetNullAttr**：为 **json** 对象添加一个null属性节点，如果该属性节点已存在，则进行设置成null类型；
**13.JSONSetBooleanAttr**：为 **json** 对象添加一个布尔属性节点，如果该属性节点已存在，则进行设置成布尔类型；
**13.JSONRemoveAttr**：将 **json** 对象某个属性进行移除；
**14.JSONObjectDeepClone**：对 **json** 对象进行一次深拷贝；
**15.JSONArrayDeepClone**：对 **json** 数组进行一次深拷贝；
**16.JSONObjectGetAttrType**：获取 **json** 对象某个属性的数据类型；
**17.JSONNodeGetType**：获取 **json** 节点的数值类型；
**18.JSONNodeGetNumberValue**：从 **json** 数据节点中取出具体的数值；
**19.JSONNodeGetStringValue**：从 **json** 字符串节点中取出具体的字符串；
**20.JSONNodeGetBooleanValue**：从 **json** 布尔节点中取出具体的布尔值；
**21.JSONObjectGetNumberAttr**：从 **json** 对象中取出数字属性节点具体的数值；
**22.JSONObjectGetStringAttr**：从 **json** 对象中取出数字属性节点具体的字符串；
**23.JSONObjectGetArrayAttr**：从 **json** 对象中取出某个数组属性节点；
**24.JSONObjectGetObjectAttr**：从 **json** 对象中取出某个对象属性节点；
**25.JSONObjectGetNullAttr**：从 **json** 对象中取出某个null属性节点；
**26.JSONObjectGetBooleanAttr**：从 **json** 对象中取出某个boolean属性节点的布尔值；
**27.JSONArrayPushNumber**：向 **json** 数组中尾部添加数字元素；
**28.JSONArrayPushString**：向 **json** 数组中尾部添加字符串元素；
**29.JSONArrayPushArray**：向 **json** 数组中尾部添加数组元素；
**30.JSONArrayPushObject**：向 **json** 数组中尾部添加对象元素；
**31.JSONArrayPushNull**：向 **json** 数组中尾部添加null元素；
**32.JSONArrayPushBoolean**：向 **json** 数组中尾部添加Boolean元素；
**33.JSONArrayUnshiftNumber**：向 **json** 数组中头部添加数字元素；
**34.JSONArrayUnshiftString**：向 **json** 数组中头部添加字符串元素；
**35.JSONArrayUnshiftArray**：向 **json** 数组中头部添加数组元素；
**36.JSONArrayUnshiftObject**：向 **json** 数组中头部添加对象元素；
**37.JSONArrayUnshiftNull**：向 **json** 数组中头部添加null元素；
**38.JSONArrayUnshiftBoolean**：向 **json** 数组中头部添加Boolean元素；
**39.JSONArrayGetLength**：获取 **json** 数组长度；
**40.JSONArrayGetNode**：获取 **json** 数组长某个元素；
**41.JSONArrayPop**：移除 **json** 数组尾部元素；
**42.JSONArrayShift**：移除 **json** 数组头部元素；
