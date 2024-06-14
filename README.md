# 记录一下做Leetcode题目的过程

## STL常用容器方法
<table>
    <thead>
        <tr>
            <th></th>
            <th>string</th>
            <th>vector</th>
            <th>set</th>
            <th>map</th>
            <th>duque</th>
            <th>stack</th>
            <th>list</th>
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
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>赋值</td>
            <td>
            string& operator=(const char* s)<br>
            string& operator=(const string& s)<br>
            string& operator=(const char ch)<br>
            string& assign(const char* s)<br>
            string& assign(const char* s,int n)<br>
            string& assign(const string& s)<br>
            string& assign(int n,char ch)
            </td>
            <td>
            vector& operator=(const vector& vec)<br>
            assign(v.begin(),v.end())<br>
            assign(int n,int elem)
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>拼接</td>
            <td>
            string& operator+=(const char* s)<br>
            string& operator+=(const string& s)<br>
            string& operator+=(const char ch)<br>
            string& append(const char* s)<br>
            string& append(const char* s,int n)<br>
            string& append(const string& s)<br>
            string& append(const string& s,int pos,int n)
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>查找</td>
            <td>
            int find(const string& str,int pos=0) const<br>
            int find(const char* s,int pos=0) const<br>
            int find(const char* s,int pos,int n) const<br>
            int find(const char c,int pos=0) const<br>
            int rfind(const string& str,int pos=npos) const<br>
            int rfind(const char* s,int pos=npos) const<br>
            int rfind(const char* s,int pos,int n) const<br>
            int rfind(const char c,int pos=0) const
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>替换</td>
            <td>
            string& replace(int pos,int n,const string& str)<br>
            string& replace(int pos,int n,const char* s)
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>比较</td>
            <td>28
            int compare(const string& s) const<br>
            int compare(const char* s) const
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>存取元素</td>
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
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>互换容器</td>
            <td></td>
            <td>swap(vector& vec)</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>预留空间</td>
            <td></td>
            <td>reserve(int len)</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
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
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
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
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>清空</td>
            <td></td>
            <td>clear()</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>子串获取</td>
            <td>string substr(int pos=0,int n=npos) const</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>是否允许重复</td>
            <td>28</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>大小</td>
            <td>28</td>
            <td>size()</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>容量</td>
            <td>28</td>
            <td>capacity()</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>重新指定大小</td>
            <td>28</td>
            <td>
            resize(int n)<br>
            resize(int n,int elem)
            </td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
        <tr>
            <td>判空</td>
            <td>28</td>
            <td>empty()</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
            <td>New York</td>
        </tr>
    </tbody>
</table>
