# 泛型和STL-STL

## STL

标准模板库

容器：序列式容器、关联式容器

算法：质变算法、非质变算法

迭代器

仿函数

适配器

空间配置器
### 算法
#### 查找算法
1. find
2. find_if
3. adjacent_find
4. binary_search
#### 排序算法
1. sort
2. radom_shuffle:无序，可以用srand((unsigned int )time(NULL))实现真无序
3. merge:合并，记得先分配空间resize
4. reverse:反转
#### 拷贝和替换
1. copy
2. replace
3. replace_if
4. swap
