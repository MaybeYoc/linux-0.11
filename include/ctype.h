/*
 * 字符测试和处理的头文件
 */
#ifndef _CTYPE_H
#define _CTYPE_H

#define _U    0x01       //该比特位用于大写字符A-Z
#define _L    0x02       //小写字符a-z
#define _D    0x04       //数字0-9
#define _C    0x08       //控制字符
#define _P    0x10       //标点字符
#define _S    0x20       //空白字符  空格 \t \n
#define _X    0x40       //用于16进制数字
#define _SP   0x80       //用于空格字符 0x20

extern unsigned char _ctype[];   //字符特性数组(表)，定义各个字符对应上面的属性
extern char _ctmp;               //一个临时字符变量

//确定字符类型
#define isalnum(c) ((_ctype+1)[c]&(_U|_L|_D))         //是字符或数字A-Z a-z 0-9
#define isalpha(c) ((_ctype+1)[c]&(_U|_L))            //是字符
#define iscntrl(c) ((_ctype+1)[c]&(_C))               //是控制字符
#define isdigit(c) ((_ctype+1)[c]&(_D))               //是数字
#define isgraph(c) ((_ctype+1)[c]&(_P|_U|_L|_D))      //是图形字符
#define islower(c) ((_ctype+1)[c]&(_L))               //是小写字符
#define isprint(c) ((_ctype+1)[c]&(_P|_U|_L|_D|_SP))  //是可打印字符
#define ispunct(c) ((_ctype+1)[c]&(_P))               //是标点字符
#define isspace(c) ((_ctype+1)[c]&(_S))               //是空白字符 如空格 \f \n \r \t \v
#define isupper(c) ((_ctype+1)[c]&(_U))               //是大写字符
#define isxdigit(c) ((_ctype+1)[c]&(_D|_X))           //是16进制数字


#define isascii(c) (((unsigned) c)<=0x7f)              //是ASCII字符
#define toascii(c) (((unsigned) c)&0x7f)               //转换成ASCII字符

#define tolower(c) (_ctmp=c,(char)isupper((unsigned char)_ctmp)?_ctmp-('A'-'a'):_ctmp)  //转换成小写字符
#define toupper(c) (_ctmp=c,(char)islower((unsigned char)_ctmp)?_ctmp-('a'-'A'):_ctmp)  //转换成大写字符

#endif





