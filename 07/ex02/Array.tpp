/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nandreev <nandreev@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:28:03 by nandreev          #+#    #+#             */
/*   Updated: 2025/11/20 23:12:41 by nandreev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Using include guards in .tpp	
//Not needed: it’s always included once through the header

template <typename T>
Array<T>::Array() : _data(NULL), _size(0){}

// " new T[n]() " - initializes array with null values (0 or "")
template <typename T>
Array<T>::Array(unsigned int n) : _data(new T[n]()), _size(n){}

template <typename T>
Array<T>::Array(const Array<T> &other) : _data(NULL), _size(other._size){
	if (_size > 0){
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (&other == this) return *this;
	if (_data != NULL) delete[] _data;
	_size = other._size;
	if (_size > 0){
		_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
    return *this;
}

template <typename T>
Array<T>::~Array() {
   if (_data != NULL) delete[] _data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index >= _size) throw OutOfBoundException();
	return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= _size) throw OutOfBoundException();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const{
	return _size;
}

template <typename T>
const char* Array<T>::OutOfBoundException::what() const throw(){
	return "Index out of bound";
}