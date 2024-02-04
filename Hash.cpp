template <class Ty>
class Hash
{
private:
    Ty val;
public:
    Hash(const Ty& v = NULL) : val(v) {}
    size_t operator()(const Hash<Ty>& s) const noexcept
    {
        size_t h = hash<Ty>{}(s.val);
        return h;
    }
    bool operator != (const Hash& right) const
    {
        return val != right.val;
    }
    bool operator == (const Hash& right) const
    {
        return val == right.val;
    }
    Hash& operator = (const Hash& right)
    {
        if (this != &right)
            val = right.val;
        return *this;
    }
};