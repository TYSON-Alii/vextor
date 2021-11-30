template <typename _t>
class vextor {
private:
	size_t _size = 0;
	_t* elem = new _t[0];
public:
	vextor(size_t _v) {
		_size = _v;
		elem = new _t[_v];
	};
	vextor() { };
	size_t size() { return _size; };
	_t& front() { return elem[0]; };
	_t& back() { return elem[_size - 1]; };
	_t& operator[](size_t _n) { return elem[_n]; };
	void resize(size_t _n, _t _s) {
		size_t i;
		if (_n < _size) {
			_t* _copy = elem;
			elem = new _t[_n];
			for (i = 0; i < _n; i++) {
				elem[i] = _copy[i];
			};
			_size = _n;
			delete _copy;
		}
		else {
			_t* _copy = elem;
			elem = new _t[_n];
			for (i = 0; i < _size; i++) {
				elem[i] = _copy[i];
			};
			for (i = _size; i < _n; i++) {
				elem[i] = _s;
			};
			_size = _n;
			delete _copy;
		};
	};
	void resize(size_t _n) {
		size_t i;
		_t* _copy = elem;
		elem = new _t[_n];
		for (i = 0; i < _n; i++) {
			elem[i] = _copy[i];
		};
		_size = _n;
		delete _copy;
	};
	void erase(size_t _v) {
		size_t i;
		_size--;
		_t* _copy = elem;
		elem = new _t[_size];
		for (i = 0; i < _v; i++)
			elem[i] = _copy[i];
		for (i = _v; i < _size; i++)
			elem[i] = _copy[i + 1];
		delete _copy;
	};
	void insert(size_t _v, _t _c) {
		size_t i;
		_size++;
		_t* _copy = elem;
		elem = new _t[_size];
		for (i = 0; i < _v; i++)
			elem[i] = _copy[i];
		elem[_v] = _c;
		for (i = _v + 1; i < _size; i++)
			elem[i] = _copy[i - 1];
		delete _copy;
	};
	void push_back(_t _v) {
		_t* _copy = elem;
		_size++;
		elem = new _t[_size];
		elem[_size - 1] = _v;
		for (size_t i = 0; i < _size - 1; i++)
			elem[i] = _copy[i];
		delete _copy;
	};
	void pop_back() {
		size_t i;
		_t* _copy = elem;
		_size--;
		elem = new _t[_size];
		for (i = 0; i < _size; i++)
			elem[i] = _copy[i];
		delete _copy;
	};
	void push_front(_t _v) {
		size_t i;
		_size++;
		_t* _copy = elem;
		elem = new _t[_size];
		elem[0] = _v;
		for (i = 1; i < _size; i++)
			elem[i] = _copy[i - 1];
		delete _copy;
	};
	void pop_front() {
		size_t i;
		_t* _copy = elem;
		_size--;
		elem = new _t[_size];
		for (i = 0; i < _size; i++)
			elem[i] = _copy[i + 1];
		delete _copy;
	};
	void reverse() {
		size_t i;
		_t* _copy = elem;
		for (i = 0; i < _size; i++)
			elem[i] = _copy[_size - i - 1];
		delete _copy;
	};
	void fill(_t _v) {
		size_t i;
		for (i = 0; i < _size; i++)
			elem[i] = _v;
	};
	void fill(vextor<_t> _v) {
		size_t i;
		if (_v < _size)
			for (i = 0; i < _v; i++)
				elem[i] = _v[i];
		else
			for (i = 0; i < _size; i++)
				elem[i] = _v[i];
	};
	void clear() {
		_size = 0;
		elem = new _t[0];
	};
};
