#ifndef LAB6_BIN_HEAP_H
#define LAB6_BIN_HEAP_H

#include <vector>


template<class T, class Container = std::vector<T>,
         class Compare = std::less<typename Container::value_type>>
class Bin_heap
{
public:
    using container_type = Container;
    using value_compare = Compare;
    using value_type = typename Container::value_type;
    using size_type = Container::size_type;
    using reference = Container::reference;
    using const_reference = Container::const_reference;

    explicit Bin_heap(Compare comp = Compare(),
                      const std::vector<T>& rhs = Container())
        : _cmp{comp}, _cont{rhs}
    {
        for (int i{static_cast<int>(size() / 2 - 1)}; i >= 0; --i)
            max_heapify(i);
    }

    const_reference top() const { return _cont.front(); }
    bool empty() const { return !_cont.size(); }
    size_type size() const { return _cont.size(); }

    Compare comparator() const { return _cmp; }
    Container container() const { return _cont; }

    void push(const value_type& value)
    {
        _cont.push_back(value);
        sift();
    }
    // it's an error to pop empty queue
    void pop()
    {
        std::swap(_cont[0], _cont[_cont.size() - 1]);
        _cont.pop_back();
        max_heapify(0);
    }


private:
    Compare _cmp;
    Container _cont;

    std::size_t left(std::size_t i) const { return 2 * i + 1; }
    std::size_t right(std::size_t i) const { return 2 * i + 2; }
    std::size_t parent(std::size_t i) const { return (i - 1) / 2; };

    bool is_leaf(std::size_t i) const
    {
        return left(i) >= _cont.size() && right(i) >= _cont.size();
    }

    void sift()
    {
        if (_cont.size() < 2) return;
        auto i = _cont.size() - 1;
        auto par = parent(i);

        while (par < _cont.size() && _cmp(_cont[parent(i)], _cont[i]))
        {
            std::swap(_cont[i], _cont[parent(i)]);
            i = parent(i);
            par = parent(i);
        }
    }

    void max_heapify(std::size_t i)
    {
        if (_cont.size() < 2) return;

        while (!is_leaf(i))
        {
            if (left(i) < _cont.size() && right(i) < _cont.size())
            {
                auto max_child_inx =
                    _cmp(_cont[right(i)], _cont[left(i)]) ? left(i) : right(i);

                if (!_cmp(_cont[i], _cont[max_child_inx])) return;

                if (_cmp(_cont[right(i)], _cont[left(i)]))
                {
                    std::swap(_cont[left(i)], _cont[i]);
                    i = left(i);
                }
                else
                {
                    std::swap(_cont[right(i)], _cont[i]);
                    i = right(i);
                }
            }
            else if (left(i) < _cont.size())
            {
                if (_cmp(_cont[i], _cont[left(i)]))
                {
                    std::swap(_cont[left(i)], _cont[i]);
                    i = left(i);
                }
                else return;
            }
            else if (right(i) < _cont.size())
            {
                if (_cmp(_cont[i], _cont[right(i)]))
                {
                    std::swap(_cont[right(i)], _cont[i]);
                    i = right(i);
                }
                else return;
            }
        }
    }
};



#endif // LAB6_BIN_HEAP_H
