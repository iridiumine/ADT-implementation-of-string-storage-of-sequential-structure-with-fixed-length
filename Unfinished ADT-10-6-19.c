//定长顺序结构存储，利用静态数组实现，在定义数组的同时定义数组长度，固定长度MAX_STRLEN（第一个元素不为字符串长度）
//函数Assign()，生成一个值为chars的串T，返回状态值
//函数Initialize()，初始化字符串，返回状态值
//函数Destroy()，销毁，操作同清空，返回状态值
//函数Clear()，将所有的字符重新赋值为'\0'，返回状态值
//函数Length()，返回字符串长度
//函数Copy()，由串S复制得串T，返回状态值
//函数Copy_part()，将S的第pos个字符之后的len个字符复制到Sub中
//函数Compare()，若S>T，则返回值>0；若S=T，则返回值=0；若S<T，则返回值<0
//函数Insert()，在串S的第pos个字符之前插入串T，完全插入返回TRUE，部分插入返回FALSE
//函数Delete()，删除串S第pos个字符之后的len个字符，返回状态值
//函数SubString()，用Sub返回串S的第pos个字符起长度为len的子串
//函数Concat()，用T返回S1和S2联接而成的新串
//函数Traversal()，遍历字符串，打印各字符的数量
//函数Index()，普通模式匹配算法，若串S中存在和串T值相同的子串，则返回T在主串S中第pos个字符之后第一次出现的位置，返回匹配值，时间复杂度Ｏ(n*m)
//函数
//函数KMP()，KMP模式匹配算法，若串S中存在和串T值相同的子串，则返回T在主串S中第pos个字符之后第一次出现的位置，返回匹配值，时间复杂度Ｏ(m+n)
//函数Replace()，用V替换主串S中出现的所有与T相等的不重叠的子串
