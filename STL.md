# STL-常用容器

## string容器
string是C++风格的字符串，而string本质上是一个类
string是一个类，类内部封装了char\*，管理这个字符串，是一个char*型的容器。
string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

### string构造函数
构造函数原型：
* `string();`          		    //创建一个空的字符串 例如: string str;
  `string(const char* s);`	    //使用字符串s初始化
* `string(const string& str);`  //使用一个string对象初始化另一个string对象
* `string(int n, char c);`      //使用n个字符c初始化 

### string赋值操作
赋值的函数原型：
* `string& operator=(const char* s);`      //char*类型字符串 赋值给当前的字符串
* `string& operator=(const string &s);`    //把字符串s赋给当前的字符串
* `string& operator=(char c);`             //字符赋值给当前的字符串
* `string& assign(const char *s);`         //把字符串s赋给当前的字符串
* `string& assign(const char *s, int n);`  //把字符串s的前n个字符赋给当前的字符串
* `string& assign(const string &s);`       //把字符串s赋给当前字符串
* `string& assign(int n, char c);`         //用n个字符c赋给当前字符串

### string字符串拼接
函数原型：
* `string& operator+=(const char* str);`              //重载+=操作符
* `string& operator+=(const char c);`                 //重载+=操作符
* `string& operator+=(const string& str);`            //重载+=操作符
* `string& append(const char *s); `                   //把字符串s连接到当前字符串结尾
* `string& append(const char *s, int n);`             //把字符串s的前n个字符连接到当前字符串结尾
* `string& append(const string &s);`                  //同operator+=(const string& str)
* `string& append(const string &s, int pos, int n);`  //字符串s中从pos开始的n个字符连接到字符串结尾

### string查找和替换
函数原型：
* `int find(const string& str, int pos = 0) const;`       //查找str第一次出现位置,从pos开始查找
* `int find(const char* s, int pos = 0) const; `          //查找s第一次出现位置,从pos开始查找
* `int find(const char* s, int pos, int n) const; `       //从pos位置查找s的前n个字符第一次位置
* `int find(const char c, int pos = 0) const; `           //查找字符c第一次出现位置
* `int rfind(const string& str, int pos = npos) const;`   //查找str最后一次位置,从pos开始查找
* `int rfind(const char* s, int pos = npos) const;`       //查找s最后一次出现位置,从pos开始查找
* `int rfind(const char* s, int pos, int n) const;`       //从pos查找s的前n个字符最后一次位置
* `int rfind(const char c, int pos = 0) const;  `         //查找字符c最后一次出现位置
* `string& replace(int pos, int n, const string& str); `  //替换从pos开始n个字符为字符串str
* `string& replace(int pos, int n,const char* s); `       //替换从pos开始的n个字符为字符串s
find查找是从左往后，rfind从右往左
find找到字符串后返回查找的第一个字符位置，找不到返回-1
replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

### string字符串比较
**比较方式：**
字符串比较是按字符的ASCII码进行对比
=  返回   0
\> 返回   1 
<  返回  -1
函数原型：
* `int compare(const string &s) const; `  //与字符串s比较
* `int compare(const char *s) const;`     //与字符串s比较

### string字符存取
* `char& operator[](int n); `  //通过[]方式取字符
* `char& at(int n);   `        //通过at方法获取字符

### string插入和删除
函数原型：
* `string& insert(int pos, const char* s);  `     //插入字符串
* `string& insert(int pos, const string& str); `  //插入字符串
* `string& insert(int pos, int n, char c);`       //在指定位置插入n个字符c
* `string& erase(int pos, int n = npos);`         //删除从Pos开始的n个字符 
**总结：**插入和删除的起始下标都是从0开始

### string子串**
从字符串中获取想要的子串
函数原型：
* `string substr(int pos = 0, int n = npos) const;`  //返回由pos开始的n个字符组成的字符串

## vector容器
vector数据结构和数组非常相似，也称为单端数组
不同之处在于数组是静态空间，而vector可以动态扩展（并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间）
vector容器的迭代器是支持随机访问的迭代器

### vector构造函数
函数原型：
* `vector<T> v; `                 //采用模板实现类实现，默认构造函数
* `vector(v.begin(), v.end()); `  //将v[begin(), end())区间中的元素拷贝给本身。
* `vector(n, elem);`              //构造函数将n个elem拷贝给本身。
* `vector(const vector &vec);`    //拷贝构造函数。

### vector赋值操作
函数原型：
* `vector& operator=(const vector &vec);`  //重载等号操作符
* `assign(beg, end);`                      //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`                       //将n个elem拷贝赋值给本身。

### vector容量和大小
函数原型：
* `empty(); `               //判断容器是否为空
* `capacity();`             //容器的容量
* `size();`                 //返回容器中元素的个数
* `resize(int num);`        //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
* `resize(int num, elem);`  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
判断是否为空  --- empty
返回元素个数  --- size
返回容器容量  --- capacity
重新指定大小  ---  resize

### vector插入和删除
函数原型：
* `push_back(ele);`                                   //尾部插入元素ele
* `pop_back();`                                        //删除最后一个元素
* `insert(const_iterator pos, ele);`                  //迭代器指向位置pos插入元素ele
* `insert(const_iterator pos, int count,ele);`        //迭代器指向位置pos插入count个元素ele
* `erase(const_iterator pos);`                        //删除迭代器指向的元素
* `erase(const_iterator start, const_iterator end);`  //删除迭代器从start到end之间的元素
* `clear();`                                          //删除容器中所有元素
尾插  --- push_back
尾删  --- pop_back
插入  --- insert    (位置迭代器)
删除  --- erase  （位置迭代器）
清空  ---  clear  

### vector数据存取
函数原型：
* `at(int idx); `  //返回索引idx所指的数据
* `operator[]; `   //返回索引idx所指的数据
* `front(); `      //返回容器中第一个数据元素
* `back();`        //返回容器中最后一个数据元素
除了用迭代器获取vector容器中元素，[ ]和at也可以
front返回容器第一个元素
back返回容器最后一个元素

### vector互换容器
函数原型：
* `swap(vec);`  // 将vec与本身的元素互换

### vector预留空间
函数原型：
* `reserve(int len);`  //容器预留len个元素长度，预留位置不初始化，元素不可访问。

## deque容器
双端数组，可以对头端进行插入删除操作
**deque与vector区别：**
* vector对于头部的插入删除效率低，数据量越大，效率越低
* deque相对而言，对头部的插入删除速度回比vector快
* vector访问元素时的速度会比deque快,这和两者内部实现有关
deque内部工作原理:
deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据
中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间

### deque构造函数
函数原型：
* `deque<T>` deqT;            //默认构造形式
* `deque(beg, end);`          //构造函数将[beg, end)区间中的元素拷贝给本身。
* `deque(n, elem);`           //构造函数将n个elem拷贝给本身。
* `deque(const deque &deq);`  //拷贝构造函数

### deque赋值操作
函数原型：
* `deque& operator=(const deque &deq); `  //重载等号操作符
* `assign(beg, end);`                     //将[beg, end)区间中的数据拷贝赋值给本身。
* `assign(n, elem);`                      //将n个elem拷贝赋值给本身。

### deque大小操作
函数原型：
* `deque.empty();`            //判断容器是否为空
* `deque.size();`             //返回容器中元素的个数
* `deque.resize(num);`        //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
* `deque.resize(num, elem);`  //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。

deque没有容量的概念
* 判断是否为空   --- empty
* 返回元素个数   --- size
* 重新指定个数   --- resize

### deque插入和删除
函数原型：
两端插入操作：
- `push_back(elem);`   //在容器尾部添加一个数据
- `push_front(elem);`  //在容器头部插入一个数据
- `pop_back();`        //删除容器最后一个数据
- `pop_front();`       //删除容器第一个数据

指定位置操作：
* `insert(pos,elem);`     //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
* `insert(pos,n,elem);`   //在pos位置插入n个elem数据，无返回值。
* `insert(pos,beg,end);`  //在pos位置插入[beg,end)区间的数据，无返回值。
* `clear();`              //清空容器的所有数据
* `erase(beg,end);`       //删除[beg,end)区间的数据，返回下一个数据的位置。
* `erase(pos);`           //删除pos位置的数据，返回下一个数据的位置。

插入和删除提供的位置是迭代器！
* 尾插   ---  push_back
* 尾删   ---  pop_back
* 头插   ---  push_front
* 头删   ---  pop_front

### deque数据存取
函数原型：
- `at(int idx); `  //返回索引idx所指的数据
- `operator[]; `   //返回索引idx所指的数据
- `front(); `      //返回容器中第一个数据元素
- `back();`        //返回容器中最后一个数据元素

除了用迭代器获取deque容器中元素，[ ]和at也可以
front返回容器第一个元素
back返回容器最后一个元素

### deque排序

`sort(iterator beg, iterator end)`  //对beg和end区间内元素进行排序
sort算法非常实用，使用时包含头文件 algorithm即可

## stack容器

## queue容器

## list容器

## set/multiset容器

## map/multimap容器