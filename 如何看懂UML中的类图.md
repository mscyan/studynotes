
### 类图
#### 1.类的表示
+ 接口：正体，但需要在类名上方加&lt;&lt;interface&gt;&gt;字样
+ 抽象类：斜体
+ 具体类：正体

#### 2.类成员的可见性
_成员包括属性和方法_
+ +：表示public
+ -：表示private
+ #：表示protected/friendly

#### 3.类图中的几种类与类之间的关系的表示
+ __泛化(Generalization)__
表示继承，比如Class A继承Class B，在UML图中用**实线+空心三角箭头**表示，方向为**子类**指向**父类**，即
![]()

+ __实现(Realization)__
表示实现关系，如Class A实现了Interface B，在UML图中用**虚线+空心三角箭头**表示，方向为类指向抽象，即
![]()

+ __依赖(Dependency)__
依赖是类与类之间比较弱的一种关系，典型的有Class A的MethodB(..)临时需要使用Class B的实例去运作，比如Person类的go(Car car)方法必须要依赖一个Car类的实例才可以运作，强调一种临时性的，用即拿的思想，一般被引用类是引用类的方法参数。UML图中用**虚线+V形箭头**表示，方向为引用类指向被引用类，即
![]()

+ __关联(Association)__
表示一种拥有关系，即Class A持有TypeB类型的变量若干，比如Person类拥有若干个Address变量(可能有0个，可能有1~n个)，再举个例子，比如学生与课程之间会建立关联关系，n个学生与m门课程之间会分别建立x - y的联系，在UML图中用**实线+V形箭头** 或者**实线直接相连**表示，如果有方向，则为单向关联，比如人与地址之间，是人指向地址，表示人关联了若干个地址；如果没有方向或者互相指向，则为双向关联，另外还有一种自关联，如链表的节点Node的实现Node{ Node next}，用关联表示即自身指向自身，表示一种递归关系
![]()


+ __聚合(Aggregation)__
表示整体与部分的关系，在基本的聚合关系中，*部分*的生命周期是独立于*整体*的生命周期的；但重点是聚合关系中，被拥有者脱离整体还是单独存在的，比如车和轮胎的关系，或者是人与自己的手机的关系，公司与员工之间的关系，在UML图中用**空心菱形+实线+V形箭头**表示，方向为整体指向部分，即
![]()

+ __组合(Composition)__
也表示整体和部分的关系，但是部分的存活周期受到整体的影响，整体消亡则部分也消亡，比如生命个人与其身体组织之间的关系，或者公司与部门之间的关系，强调的是一种个人无法独立于整体的概念，在UML图中用**实心菱形+实线+V形箭头**表示，方向为整体指向部分，即
![]()

***需要注意的几点：***
##### 1.组合和聚合的区别
聚合关系中，整体消亡但个体仍然存在，比如国家消亡，但人仍然存在，而在组合关系中，整体消亡则个人随之消亡，比如公司破产，部门自然也随之不存在，在代码层面则是：
聚合
```java
Class Group{
    Item item;
    //即使整体消亡，个体仍然是存活的
    public Group(Item item){
        this.item = item;
    }
}
```
组合
```java
Class Person{
    Finger finger;
    Hair hair;
    //一旦整体消亡，部分则立即消亡
    public Person(){
        this.finger = new Finger();
        this.hair = new Hair();
    }
}
```
另外，可以从信息的安全性上考量，聚合关系中，外界能发现部分的存在，而在组合关系中，外界无法发现部分的存在；
从建立关系的方式上来看，聚合隐含着一种“召集”的含义，比如Group召集了Item对象为其服务。而组合更像是一种“产生出xx”的形式，比如Company一旦构建完成，就会立即构建部门来为其服务。

##### 2.组合/聚合和关联的区别
*合关系着重强调一种整体和局部/个体的关系，而关联则表示平级，平等的关系，并且关联可以有方向，也可以双向关联。
