1.InnoDB中一条记录的存储结构
行格式：compact，Redundant，compress，dynamic等等
记录额外信息：
    变长字段长度列表：在compact和Redundant中分别为变长字段长度列表和字段长度偏移量
    空值列表：在compact中记录空值列，用二进制位表示
    记录头信息：5个字节（40bit），分别记录记录的类型（普通记录，目录页记录，最小记录，最大记录等），
        是否删除列，堆中的位置，下一条记录的位置等信息
真实记录信息：
    row_id（有主键和唯一非空二级索引的列，则此项不存在）：行标志ID
    tx_id：事务ID
    roll_pointer：回滚指针
注意在InnoDB中，每页最少存储两个记录，每个记录所有列的长度之和有一定限制，varchar，char，txt等格式会产生溢出页

2.InnoDB中数据页的结构
fileheader
pageheader
ifmum + sumum
userrecord
freespace
pagedirectory
pagetailer

3.InnoDB中，B+树索引
B+树索引，以及目录结构的建立

4.InnoDB中，如何使用到索引
查询的访问方法：
    const：根据主键 或者 唯一二级索引 与常数 进行等值比较的类型
    ref：普通二级索引 与常数进行进行等值比较
        普通二级索引不必唯一，所以可能会有若干条记录，比const会慢一些
    ref_or_null：普通二级索引 与null值比较查找
        因为null值对应的记录可能会有很多条
    range：索引列进行 范围匹配
    index：无需回表，直接遍历 将二级索引中的结果添加到结果集
    all：全表扫描
    eq_ref：对于连接查询中，被驱动表使用主键 或者 唯一二级索引 于常数进行等值比较
什么时候会使用到索引，索引的代价

5.InnoDB的表空间
略

6.Mysql InnoDB单表的访问方法
如何使用到索引，什么情况下回使用索引

7.连接查询

8.基于成本的优化

9.explain的使用
explain中，各项代表的含义

10.MySQL的事务

11.Mysql的锁
行级索，表级锁等