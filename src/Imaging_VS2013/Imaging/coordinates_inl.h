#if !defined(COORDINATES_INL_H)
#define COORDINATES_INL_H

namespace Imaging
{
	////////////////////////////////////////////////////////////////////////////////////
	// Point2D<T>

	/*
	This ctor is called only when T and U are different.
	*/
	template <typename T> template <typename U>
	Point2D<T>::Point2D(const Point2D<U> &src) : Point2D<T>()
	{
		this->x = Cast<T>(src.x);
		this->y = Cast<T>(src.y);
	}

	template <typename T>
	Point2D<T>::Point2D(T x, T y) : Point2D<T>()
	{
		this->x = x;
		this->y = y;
	}

	template <typename T>
	Point2D<T>::Point2D(const Array<T, 2> &srcData) : Array<T, 2>(srcData) {}

	// Point2D<T>
	////////////////////////////////////////////////////////////////////////////////////

	////////////////////////////////////////////////////////////////////////////////////
	// Size2D<T>

	/*
	This ctor is called only when T and U are different.
	*/
	template <typename T> template <typename U>
	Size2D<T>::Size2D(const Size2D<U> &src) : Point2D<T>()
	{
		this->width = Cast<T>(src.width);
		this->height = Cast<T>(src.height);
	}

	template <typename T>
	Size2D<T>::Size2D(T width, T height) : Size2D<T>()
	{
		this->width = width;
		this->height = height;
	}

	template <typename T>
	Size2D<T>::Size2D(const Array<T, 2> &srcData) : Array<T, 2>(srcData) {}

	// Size2D<T>
	////////////////////////////////////////////////////////////////////////////////////
}

#endif
