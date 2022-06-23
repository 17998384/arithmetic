//
// Created by 我叫城北徐公° on 2022/3/7.
//

//  284. 顶端迭代器
//
//          请你在设计一个迭代器，在集成现有迭代器拥有的 hasNext 和 next 操作的基础上，还额外支持 peek 操作。
//
//  实现 PeekingIterator 类：
//
//  PeekingIterator(Iterator<int> nums) 使用指定整数迭代器 nums 初始化迭代器。
//  int next() 返回数组中的下一个元素，并将指针移动到下个元素处。
//  bool hasNext() 如果数组中存在下一个元素，返回 true ；否则，返回 false 。
//  int peek() 返回数组中的下一个元素，但 不 移动指针。
//
//  注意：每种语言可能有不同的构造函数和迭代器 Iterator，但均支持 int next() 和 boolean hasNext() 函数。
//
//
//
//  示例 1：
//
//  输入：
//  ["PeekingIterator", "next", "peek", "next", "next", "hasNext"]
//  [[[1, 2, 3]], [], [], [], [], []]
//  输出：
//  [null, 1, 2, 2, 3, false]
//
//  解释：
//  PeekingIterator peekingIterator = new PeekingIterator([1, 2, 3]); // [1,2,3]
//  peekingIterator.next();    // 返回 1 ，指针移动到下一个元素 [1,2,3]
//  peekingIterator.peek();    // 返回 2 ，指针未发生移动 [1,2,3]
//  peekingIterator.next();    // 返回 2 ，指针移动到下一个元素 [1,2,3]
//  peekingIterator.next();    // 返回 3 ，指针移动到下一个元素 [1,2,3]
//  peekingIterator.hasNext(); // 返回 False
//
//
//
//  提示：
//
//  1 <= nums.length <= 1000
//  1 <= nums[i] <= 1000
//  对 next 和 peek 的调用均有效
//          next、hasNext 和 peek 最多调用  1000 次
//
//
//
//          进阶：你将如何拓展你的设计？使之变得通用化，从而适应所有的类型，而不只是整数型？


/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

#include <vector>
#include <iostream>

using namespace std;


class Iterator
{
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums)
    {

    }

    Iterator(const Iterator& iter)
    {

    }

    // Returns the next element in the iteration.
    int next()
    {

    }

    // Returns true if the iteration has more elements.
    bool hasNext() const
    {

    }
};

class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums)
    {

    }

    int peek()
    {
        Iterator copy = *this;
        return copy.next();
    }

    int next()
    {
        return Iterator::next();
    }

    bool hasNext() const
    {
        return Iterator::hasNext();
    }
};

//int main(void)
//{
//    PeekingIterator* p = new PeekingIterator({1, 2, 3});
//    cout << p->hasNext() << endl;
//    cout << p->peek() << endl;
//    cout << p->next() << endl;
//    cout << p->next() << endl;
//    cout << p->next() << endl;
//    cout << p->hasNext() << endl;
//    delete p;
//    return 0;
//}