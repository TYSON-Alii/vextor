
template <typename T>
class vextor : public std::vector<T> {
public:
    using std::vector<T>::vector;
    using std::vector<T>::at;
    using std::vector<T>::clear;
    using std::vector<T>::iterator;
    using std::vector<T>::const_iterator;
    using std::vector<T>::begin;
    using std::vector<T>::end;
    using std::vector<T>::cbegin;
    using std::vector<T>::cend;
    using std::vector<T>::crbegin;
    using std::vector<T>::crend;
    using std::vector<T>::rbegin;
    using std::vector<T>::rend;
    using std::vector<T>::empty;
    using std::vector<T>::size;
    using std::vector<T>::reserve;
    using std::vector<T>::assign;
    using std::vector<T>::insert;
    using std::vector<T>::erase;
    using std::vector<T>::front;
    using std::vector<T>::back;
    using std::vector<T>::pop_back;
    using std::vector<T>::resize;
    operator std::string() const {
        std::string t;
        t += '[';
        const auto& e = end()-1;
        for (auto b = begin(); b != e; b++) {
            t += std::to_string(*b);
            t += ", ";
        };
        t += std::to_string(*rbegin());
        t += ']';
        return t;
    };
    T& first() { return front(); };
    T& last() { return back(); };
    T first() const { return front(); };
    T last() const { return back(); };
    inline T& push_back(const T& value) { std::vector<T>::push_back(value); return back(); };
    inline T& operator+=(const T& value) { std::vector<T>::push_back(value); return back(); };
    inline vextor<T> operator+(const T& value) const { auto t = *this; return t += value; };
    inline vextor<T>& operator--() { pop_back(); return *this; };
    using std::vector<T>::operator[];
    vextor<T> operator[](std::initializer_list<size_t> v) {
        vextor<T> t;
        for (const auto& i : v)
            t.push_back(*(begin()+i));
        return t;
    };
    inline vextor<T> operator()() const { return *this; };
    template <typename _T>
    inline vextor<T>& operator()(_T _for_each) {
        auto b = begin();
        const auto& e = end();
        while (b != e) {
            _for_each(*b);
            b++;
        };
        return *this;
    };
};

template <typename T>
ostream& operator<<(ostream& os, const vextor<T>& v) {
    os << '[';
    const auto& e = v.end()-1;
    for (auto b = v.begin(); b != e; b++)
        os << *b << ',' << ' ';
    os << *v.rbegin() << ']';
    return os;
};
