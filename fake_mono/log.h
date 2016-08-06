#pragma once

namespace logger
{

    inline void print_impl(std::ostream &s, char const *str)
    {
        if (str)
            s << "'" << str << "'";
        else
            s << "NULL";
    }

    template<typename T>
    void print_impl(std::ostream &s, T const &t)
    {
        s << t;
    }

}


template<typename Tuple>
struct tuple_printer
{
    tuple_printer(std::ostream &s)
        : s_(s)
    {}

    void operator()(Tuple const &t)
    {
        process<0>(t);
    }

private:
    static const  size_t tuple_size = std::tuple_size<Tuple>::value;

    template<size_t N>
    void process(Tuple const &t)
    {
        print(std::get<N>(t), N != tuple_size - 1);
        process<N + 1>(t);
    }

    template<>
    void process<tuple_size>(Tuple const &t)
    {
    }

private:
    template<typename T>
    void print(T const &t, bool sep)
    {
        logger::print_impl(s_, t);
        if (sep)
            s_ << ", ";
    }

private:
    std::ostream &s_;
};

std::ostream &log_stream();

template<typename... Args>
void log_function(char const *name, Args&&... args)
{
    if (false)
    {
        auto &s = log_stream();

        s << name << ": ";

        typedef std::tuple<Args...> tuple_t;
        tuple_t t(args...);
        tuple_printer<tuple_t> p(s);
        p(t);

        s << "\n";
    }
}

