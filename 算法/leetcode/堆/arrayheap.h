#include <iostream>
//数组实现堆，大根堆
class arrayheap
{
public:
    arrayheap(int _capcity);
    ~arrayheap();
    void insert(int num);
    int top();
    int pop();
    void adjustHeap();
private:
    int *root;
    int size;
    int capcity;
};
arrayheap::arrayheap(int _capcity)
{
    //构造函数，如果最大容量赋值不正确，则初始化为5
    if(_capcity < 0)
        capcity = 5;

    capcity = _capcity;
    size = 0;
    root = new int[capcity];
}
arrayheap::~arrayheap()
{
    //析构函数
    delete(root);
    std::cout<<"析构函数被执行，清除内存空间"<<std::endl;
}
void arrayheap::insert(int num)
{
    if(size == 0)
    {
        root[0] = num;
        return;
    }
    if(size == capcity)
    {
        //需要扩容
        //todo 扩容
    }
    root[size] = num;
    size++;
    // adjustHeap();
}
int arrayheap::top()
{
    if(size > 0)
        return root[0];
    return -1;
}
int arrayheap::pop()
{
    return -1;
}
void arrayheap::adjustHeap()
{
    //每次新加入一个元素，默认放在堆尾，然后通过调整数据的位置使堆符合最大堆的性质
    std::cout<<size<<" "<<std::endl;
    int temp = root[size - 1];
    int maxIndex = (size - 2) / 2;
    for(int i=maxIndex; i >= 0; i--)
    {
        if(i*2 + 1 <= size-1)
        {
            if(root[i] < root[i*2 + 1])
            {
                int t = root[i];
                root[i] = root[i*2 + 1];
                root[i*2 + 1] = t;
            }
        }
        if(i*2 + 2 <= size-1)
        {
            if(root[i] < root[i*2 + 2])
            {
                int t = root[i];
                root[i] = root[i*2 + 2];
                root[i*2 + 2] = t;
            }
        }
    }

}
