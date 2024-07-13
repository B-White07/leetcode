# 记录一下做Leetcode题目的过程

## 使用说明
为了简化目录结构，每个专题目录下边不分子目录，使用`X---子专题名---.cpp`的文件用来划分不同类型的题目，文件中并无实际内容。其中：  
***X***表示子专题的序号；<br>
***子专题名***表示是什么子专题。

每个题目名称的第一位数字代表其所属分区，后边的几位表示对应leetcode的题号。<br>
每个题目名称的最后一个字母代表对应leetcode的难度。E表示easy、M表示middle、H表示hard.<br>
如"1844BackspaceStringCompareE.cpp"表示1区中的题目，对应leetcode的844题，难度为Easy.<br>


## STL常用容器方法
完整PDF链接:[C++STL](https://bwhite.top/diy/file/Cpp.pdf)

### vector
题目：146

```cpp
//初始化
    vector<int> vec;//这样初始化的vec是空的，不能直接用vec[]的方式访问和赋值，需要用push_back赋值
    vector<int> vec(size,default);//这样初始化了一个大小为size的全为default的vec
    
//容量相关
    resize(size_type count)// 改变 vector 的大小为 count，如果新大小大于当前大小，则用默认值或给定值填充新的元素。
    size()//当前元素数量。
	capacity()//当前分配的内存可以容纳的最大元素数量。由于vector会自动分配内存，如果vec中原来只分配了5个单位内存，且都有数据了，此时size()==capacity().
	                                         //若现在又向vec中添加了一个元素，size()==6而capacity()应该是大于6的，因为内存的分配往往不是一次只分配一个。

//元素访问
    front()// 访问第一个元素。
	back()// 访问最后一个元素。

//修改
    push_back(const T& value)// 在末尾添加一个元素。
	pop_back()//删除最后一个元素。
	insert(iterator pos, const T& value)//在指定位置插入元素。
	erase(iterator pos)//移除指定位置的元素。
	clear()//清除所有元素，容器大小变为 0。
```



### map
题目：904

共同操作：

```Cpp
//插入
    myMap.insert({1, "one"});
    myMap[2] = "two";//仅map和unordered_map可以使用，因为键唯一
    myMap.emplace(3, "three");
    
    
//查找
    auto it = myMap.find(2); //返回指向指定键的元素的迭代器，如果未找到，则返回 end 迭代器。
    myMap.count(2); //返回指定键的元素个数，对于 std::map 和 std::unordered_map，返回值为 0 或 1。
    
    // 使用 find 查找键为 2 的元素.map和unordered_map只会返回第一个找到的元素
    auto it = myMultimap.find(2);
    if (it != myMultimap.end()) {
        std::cout << "Found: " << it->first << " -> " << it->second << std::endl;
    } else {
        std::cout << "Not Found" << std::endl;
    }

    // 使用 equal_range 查找所有键为 2 的元素
    auto range = myMultimap.equal_range(2);
    std::cout << "All elements with key 2:" << std::endl;
    for (auto iter = range.first; iter != range.second; ++iter) {
        std::cout << iter->first << " -> " << iter->second << std::endl;
    }
    
    
//删除
    myMap.erase(1); //删除指定键的元素，返回被删除元素的个数。
    
    
//访问
    myMap.begin(); //返回相应的迭代器，用于遍历容器。
    myMap.end(); //返回相应的迭代器，用于遍历容器。
    myMap.size(); //返回容器中的元素个数。
    myMap.empty(); //检查容器是否为空。
    myMap.clear(); //清空容器。
	
```

各自特点：
- map

按键的大小排序、不允许重复的键、底层为红黑树

- multimap

按键的大小排序、允许重复的键、底层为红黑树

- unordered_map

无序、不允许重复的键、底层为哈希表

- unordered_multimap

无序、允许重复的键、底层为哈希表

