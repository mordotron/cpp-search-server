#pragma once

#include <vector>


template <typename Iterator>
class IteratorRange
{
    public : IteratorRange ( Iterator page_begin,  Iterator page_end) : page_begin_ (page_begin) , page_end_ (page_end)
    {}

    Iterator page_begin() const
    {
        return page_begin_ ;
    }

     Iterator page_end() const
    {
        return page_end_ ;
    }

    private :
    Iterator page_begin_, page_end_ ;

};

template <typename Iterator>
class Paginator
{
public:
    Paginator(const Iterator &begin, const Iterator &end, size_t page_size)
    {
        for (Iterator i = begin; i < end; advance(i, page_size))
        {
            if (distance(i, end) >= page_size)
            {
                pages_.push_back({i, i + page_size});
            }
            else
            {
                pages_.push_back({i, end});
                break;
            }
        }
    }

    auto begin() const
    {
        return pages_.begin();
    }
    auto end() const
    {
        return pages_.end();
    }

private:

    std::vector<IteratorRange<Iterator>> pages_ ;
};

template <typename Container>
auto Paginate(const Container &c, size_t page_size)
{
    return Paginator(begin(c), end(c), page_size);
}

template <typename Iterator>
std::ostream &operator<<(std::ostream &out, const IteratorRange<Iterator> &page)
{
    for (Iterator i = page.page_begin(); i != page.page_end(); ++i)
        out << *i;
    return out;
}
