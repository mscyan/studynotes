---
title: 'java中的异常机制'
output: pdf_document
---

###Throwable
Throwable是java中所有异常的祖先

####Exception
######平时用的最多的异常类，指程序本身可以处理的异常
Exception类有一个重要的子类RuntimeException，RuntimeException类及其子类表示“JVM常用操作”引发的错误。例如试图使用空值对象引用，除数为0或者数组越界等

####Error
######程序无法处理的错误
Error一般指程序中较严重的问题，大多数Error表示代码运行时JVM出现的错误，比如Virtual Machine Error，比如内存不足时出现的OutOfMemoryError或者StackOverflowError，这些异常发生时，JVM一般会选择终止线程。

***异常和错误的区别：Exception可以被处理，Error无法处理***

**Java的异常分为可查异常和不可查异常**
可查异常：程序运行过程中很容易出现的异常状况，可预计，并且出现后必须采取对应措施。编译器要求必须处置的异常
不可查异常：运行时Exception和Error，编译器不要求强制处置的异常

*Exception又分为运行时异常和非运行时异常*
**运行时异常**：RuntimeException类及其子类，如NullPointException，IndexOutOfBoundsException等，这些异常是**不检查异常**，程序可以选择捕获，也可以不处理，一般由程序逻辑错误引起。
**非运行时异常**：除RuntimeException家族异常以外的异常，类型上都属于Exception类，是必须处理的异常，不处理则不允许编译通过，如IOException，SQLException等