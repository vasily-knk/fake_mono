#pragma once

namespace stl_helpers
{

template<typename Map>
typename Map::mapped_type *map_item(Map &m, typename Map::key_type const &key)
{
    auto it = m.find(key);
    return it != m.end() ? &(it->second) : nullptr;
}

template<typename Map>
typename Map::mapped_type const *map_item(Map const &m, typename Map::key_type const &key)
{
    return const_cast<typename Map::mapped_type const *>(map_item(const_cast<Map &>(m), key));
}

template<size_t Index>
struct index_getter
{
    template<typename T>
    auto operator()(T const &t) -> decltype(std::get<Index>(t))
    {
        return std::get<Index>(t);
    }
};

template<typename Container>
typename Container::value_type const *iter_value(Container const &container, typename Container::const_iterator const &it)
{
    return it == end(container) ? nullptr : &(*it);
}

template<typename Container>
typename Container::value_type *iter_value(Container &container, typename Container::iterator const &it)
{
    return it == end(container) ? nullptr : &(*it);
}

template<typename Dst, typename Src>
optional<Dst> map_optional(optional<Src> const &src, std::function<Dst(Src const&)> f)
{
    if (!src)
        return none;

    return boost::in_place(f(*src));
}

template<typename It>
vector<std::pair<typename std::iterator_traits<It>::value_type const &, typename std::iterator_traits<It>::value_type const &>>
make_pairs_vector(It begin, It end)
{
    typedef typename std::iterator_traits<It>::value_type value_type;
    typedef pair<value_type const &, value_type const &> pair_type;

    if (begin == end || next(begin) == end)
        return {};

    vector<pair_type> pairs;
    pairs.reserve(std::distance(begin, end) - 1);

    auto prev = begin;
    for (auto it = next(begin); it != end; ++it, ++prev)
        pairs.emplace_back(*prev, *it);

    return pairs;
}

template<typename Container>
vector<std::pair<typename Container::value_type const &, typename Container::value_type const &>>
make_pairs_vector(Container const &container)
{
    return make_pairs_vector(std::begin(container), std::end(container));
}

template<typename Range>
struct range_wrapper_t
{
    typedef typename Range::const_iterator it_t;
    typedef typename Range::value_type value_type;

    range_wrapper_t(Range const &range)
        : begin_(std::begin(range))
        , end_(std::end(range))
    {}

    template<typename Container>
    operator Container() const
    {
        return convert<Container>();
    }

private:
    template<typename Container>
    Container convert() const
    {
        return Container(begin_, end_);
    }
private:
    it_t begin_, end_;
};

template<typename Range>
range_wrapper_t<Range> container_from_range(Range const &range)
{
    return range_wrapper_t<Range>(range);
}

template<typename Container, typename F>
auto transformed_container(Container const &container, F const &f) -> decltype(container_from_range(container | boost::adaptors::transformed(f)))
{
    return container_from_range(container | boost::adaptors::transformed(f));
}

template<typename Container1, typename Container2>
auto joined_containers(Container1 const &container1, Container2 const &container2)
    -> decltype(container_from_range(boost::range::join(container1, container2)))
{
    return container_from_range(boost::range::join(container1, container2));
}

template<typename Container1, typename Container2, typename Container3>
auto joined_containers(Container1 const &container1, Container2 const &container2, Container2 const &container3)
    -> decltype(container_from_range(boost::range::join(boost::range::join(container1, container2), container3)))
{
    return container_from_range(boost::range::join(boost::range::join(container1, container2), container3));
}

template<typename T>
optional<T> opt_from_ptr(T const *ptr)
{
    if (!ptr)
        return none;

    return *ptr;
}

#define SIMPLE_LAMBDA(arg, expr) [](arg) { return expr; }

} // namespace stl_helpers