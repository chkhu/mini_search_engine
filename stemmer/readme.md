将porter2_stemmer.h以及util文件下的两个.h文件声明
#include <vector> 和 #include <string>无需在main中声明（porter2_stemmer.h已经声明了）
使用方式：Porter2Stemmer::trim(word);  Porter2Stemmer::stem(word);
