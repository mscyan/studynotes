---
title: 'LeetCode 20 有效的括号'
output: pdf_document
---

# LeetCode 20 有效的括号
**题目要求：判断一个串是否是有效的括号串，比如`()`，`{}([])`这种都属于合法的括号串，即成对并且符合规则**

一看到这个题目，第一想到的是动态规划，因为之前做那题最长回文串跟这个有点相似，但后来推了一会儿没推出来状态转移方程，这时候，突然看到下面的标签处标明`栈`，瞬间感觉自己傻了，这题用栈会很方便。但想了会还是没成功用代码实现。之后突然想到了函数的调用，即在二叉树三种非递归遍历算法中的思路，其实这种括号的排列比较类似函数之间的调用，左括号代表函数入口，右括号代表函数执行结束跳出，这样如果一个串最后可以执行完成的话，那么就是一个合法的串。

比如`( ) [ ] { [ ] }`这个串，可以看做是方法A`( )`先执行，执行完之后，执行方法B`[ ]`，之后再执行方法C`{ }`，不过这里要注意，进入C方法之后，里面嵌套了一个A`( )`方法，需要执行完成A方法才可以完成C方法，这样最后所有代码都执行完成后，没有字符剩余，表示是合法的。

想到这里，代码实现就比较容易了，用一个栈模拟CPU的运行，每次来一个字符，就看一下是否可以结束一个方法，即判断栈里是否有等待结束的方法，具体操作即判断栈顶字符是否可以和该字符组成配对的结构，如果可以，表示可以结束一个方法，如果不可以就将字符入栈（否管这个字符是左开还是右闭，只要不能结束一个函数，就入栈），如果可以的话，就将栈顶字符出栈，表示方法执行完毕。简单代码如下：
```java
for(int i=0;i<s.length();i++){
    if(charStack.isEmpty()){
        charStack.push(s.charAt(i));
        continue;
    }
    if(isPair(charStack.peek(), s.charAt(i))){
        charStack.pop();
    }
    else{
        charStack.push(s.charAt(i));
    }

}

boolean isPair(char a, char b){
    if(a == '(' && b == ')')
        return true;
    if(a == '[' && b == ']')
        return true;
    if(a == '{' && b == '}')
        return true;
    return false;
}
```
`isPair()`是判断字符是否符合规则的方法，单独抽取出来，简化主体部分的代码。
最后需要判断函数是否执行完毕，即`charStack`中是否有剩余字符，比如`))()`这个串，执行完该算法之后，栈中剩余`))`，这个串肯定是不合法的，这验证了该思路是正确的。完整代码如下：

```java
public class lc_20_isValid {

    public boolean isValid(String s){
        if(s.equals(""))
            return true;
        Stack<Character> charStack = new Stack<>();
        for(int i=0;i<s.length();i++){
            if(charStack.isEmpty()){
                charStack.push(s.charAt(i));
                continue;
            }
            if(isPair(charStack.peek(), s.charAt(i))){
                charStack.pop();
            }
            else{
                charStack.push(s.charAt(i));
            }

        }
        return charStack.isEmpty();
    }

    private boolean isPair(char a, char b){
        if(a == '(' && b == ')')
            return true;
        if(a == '[' && b == ']')
            return true;
        if(a == '{' && b == '}')
            return true;
        return false;
    }

    public static void main(String[] args){

        String s = "([)]";
        System.out.println(new lc_20_isValid().isValid(s));
    }
}
```