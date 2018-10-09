template <typename T>
detail_range::impl<T> range(T end) {
	return { {}, end, 1 };//impl(value_type begin_val, value_type end_val, value_type step_val) 
}

template <typename T>
detail_range::impl<T> range(T begin, T end) {
	return { begin, end, 1};
}

template <typename T, typename U>
auto range(T begin, T end, U step) -> detail_range::impl<decltype(begin + step)> {
	using r_t = detail_range::impl<decltype(begin + step)>;
	return r_t(begin, end, step);
}
