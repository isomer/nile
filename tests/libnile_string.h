struct nilep_string : public nile_t {
	std::wstring value;
	nilep_string(const wchar_t *str) : value(str) {};
	std::wstring toString() { return value; };
	int cmp(const nile_t *rhs) const {
		if (dynamic_cast<const nilep_string*>(rhs)==NULL)
			return nile_t::cmp(rhs);
		return value.compare(
			dynamic_cast<const nilep_string*>(rhs)->value);
	}
};

