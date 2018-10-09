//结束条件: ite != end
namespace detail_range {

template <typename T>
class iterator
{
public:
	using value_type = T;
	using size_type = size_t;

private:
	size_type        cursor_;
	const value_type step_;
	value_type       value_;

public:
	//起始位置，起始值，步长
	iterator(size_type cur_start, value_type begin_val, value_type step_val) : cursor_(cur_start), step_(step_val), value_(begin_val)
	{
		value_ += (step_ * cursor_);
	}
	value_type operator*() const { return value_ };//const表明调用函数对象不会被修改，取迭代器中的值
	bool operator != (const iterator& rhs) const {//用于和另一个迭代器比较
		return (cursor_ != rhs.cursor_);
	}

	iterator& operator++(void) {//prefix ++ operator only，用于迭代器的正向迭代
		value_ += step_;
		++ cursor_;
		return (*this);
	}
};

} //namespace detail_range
