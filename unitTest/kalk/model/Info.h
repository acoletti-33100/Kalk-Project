#ifndef INFO_H
#define INFO_H

template<typename T>
class Info {
	private:
		T value;
	public:
		Info(const T& v = 0);
		Info(const Info&);
		Info& operator=(const Info&);
		~Info();
		T operator+(const Info&) const;
        Info& operator+=(const Info&);
		T getValue() const;
        void setValue(const T& val = 0);
};

template<typename T>
Info<T>::Info(const T& v) : value(v) {}

template<typename T>
Info<T>::~Info() {}

template<typename T>
T Info<T>::operator+(const Info& t) const { return (value + t.value); }

template<typename T>
Info<T>& Info<T>::operator+=(const Info& t) {
    if(this != &t) {
        value += t.value;
    }
    return *this;
}

template<typename T>
T Info<T>::getValue() const { return value; }

template<typename T>
void Info<T>::setValue(const T& val) { value = val; }

template<typename T>
Info<T>::Info(const Info& t) {
    value = t.value;
}

template<typename T>
Info<T>& Info<T>::operator=(const Info& t) {
    if(this != &t) {
        value = t.value;
    }
    return *this;
}

#endif
