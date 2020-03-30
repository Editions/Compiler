# 编译原理课程项目

* 实现 Mini C 语言编译程序
  * 实现一个 Mini C 扫描器(词法分析器),或者像 DFA 用手工进行,或者使用 Lex. 
  * 设计一个 Mini C 语法树结构,适合于用分析器产生,语法树的结果可以在屏幕上显示或以 文件的形式保存.
  * 实现一个 Mini C 语法分析器(这首先要完成ー个 Mini C 扫描器,见设计功能 2),或者使 用递归下降用手工进行,或者使用 Yacc.分析器要产生合适的语法树(见设计功能 3). 
  * 实现 Mini C 的语义分析器.分析器的主要要求是,除了在符号表中收集信息外,在使用变 量和函数时完成类型检查.因为没有指针或结构,并且仅有的基本类型是整型,类型检查器需 要处理的类型是空类型,整型,数组和函数. 
  * 实现 Mini C 的代码产生器,其代码指令与参考资料中的虚拟机一致.代码生产结果可以 在屏幕上显示或以文件的形式保存. 
  * 配套修改参考资料中虚拟机程序以实现代码指令的解释执行,并执行得出相应的结果. 
  * 书写实验报告以及系统的使用说明书.