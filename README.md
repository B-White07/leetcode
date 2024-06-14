# 记录一下做Leetcode题目的过程

## STL常用容器方法（极简版）
较为完整的PDF链接:[C++STL](https://bwhite.top/diy/file/Cpp.pdf)

<table>
    <thead>
        <tr>
            <th></th>
            <th>string</th>
            <th>vector</th>
            <th>duque</th>
            <th>stack</th>
            <th>queue</th>
            <th>list</th>
            <th>set</th>
            <th>map</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>构造函数（省略无参构造）</td>
            <td>
            string(const char* ch)<br>
            string(const string & str)<br>
            string(int n,char c)
            </td>
            <td>
            vector(v.begin(),v.end())<br>
            vector(int n,int elem)<br>
            vector(const vector& vec)
            </td>
            <td>
            deque(d.begin(),d.end())<br>
            deque(int n,int elem)<br>
            deque(const deque& deq)
            </td>
            <td>stack(const stack& stk)</td>
            <td>stack(const queue& que)</td>
            <td>
            list(l.begin(),l.end())<br>
            list(int n,int elem)<br>
            list(const list& l)
            </td>
            <td>New York</td>
        </tr>
        <tr>
            <td>查找</td>
            <td>
            int find(const string& str,int pos=0) const<br>
            int find(const char* s,int pos=0) const<br>
            int find(const char* s,int pos,int n) const<br>
            int find(const char c,int pos=0) const<br>
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>访问数据</td>
            <td>
            char& operator[](int pos)<br>
            char& at(int pos)
            </td>
            <td>
            at(int idx)<br>
            operator[]<br>
            front()<br>
            back()
            </td>
            <td>
            at(int idx)<br>
            operator[]<br>
            front()<br>
            back()
            </td>
            <td>top()</td>
            <td>
            back()<br>
            front()
            </td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>插入</td>
            <td>
            string& insert(int pos,const char* s)<br>
            string& insert(int pos,const string& str)<br>
            string& insert(int pos,int n,char c)
            </td>
            <td>
            push_back(int elem)<br>
            insert(const _iterator pos,int elem)<br>
            insert(const _iterator pos,int n,int elem)
            </td>
            <td>
            push_back(int elem)<br>
            push_front(int elem)<br>
            insert(const _iterator pos,int elem)<br>
            insert(const _iterator pos,int n,int elem)<br>
            insert(const _iterator pos,d.begin(),d.end())
            </td>
            <td>push(int elem)</td>
            <td>push(int elem)</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>删除</td>
            <td>string& erase(int pos,int n = npos)</td>
            <td>
            pop_back()<br>
            erase(const _iterator pos)<br>
            erase(const _iterator start,const _iterator end)
            </td>
            <td>
            pop_back()<br>
            pop_front()<br>
            erase(const _iterator pos)<br>
            erase(const _iterator start,const _iterator end)
            </td>
            <td>pop()</td>
            <td>pop()</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>清空</td>
            <td>clear()</td>
            <td>clear()</td>
            <td>clear()</td>
            <td>NO</td>
            <td>NO</td>
            <td>clear()</td>
            <td>clear()</td>
            <td>clear()</td>
        </tr>
        <tr>
            <td>是否允许重复</td>
            <td>OK</td>
            <td>OK</td>
            <td>OK</td>
            <td>OK</td>
            <td>OK</td>
            <td>OK</td>
            <td>NO<br>multiset OK</td>
            <td>NO<br>multimap OK</td>
        </tr>
        <tr>
            <td>大小</td>
            <td>size()</td>
            <td>size()</td>
            <td>size()</td>
            <td>size()</td>
            <td>size()</td>
            <td>size()</td>
            <td>size()</td>
            <td>size()</td>
        </tr>
        <tr>
            <td>判空</td>
            <td>empty()</td>
            <td>empty()</td>
            <td>empty()</td>
            <td>empty()</td>
            <td>empty()</td>
            <td>empty()</td>
            <td>empty()</td>
            <td>empty()</td>
        </tr>
    </tbody>
</table>
