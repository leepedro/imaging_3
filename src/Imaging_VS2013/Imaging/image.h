#if !defined(IMAGE_H)
#define IMAGE_H

#include <vector>

#include "coordinates.h"

namespace Imaging
{
	template <typename T>
	class ImageFrame
	{
		static_assert(std::is_arithmetic<T>::value,
		"Only arithmetic data types are supported for this class template.");

	public:
		////////////////////////////////////////////////////////////////////////////////////
		// Types and constants.
		typedef typename std::vector<T>::size_type SizeType;

		////////////////////////////////////////////////////////////////////////////////////
		// Default constructors.
		ImageFrame(void);
		ImageFrame(const ImageFrame<T> &src);
		ImageFrame(ImageFrame<T> &&src);
		ImageFrame<T> &operator=(const ImageFrame<T> &src);
		ImageFrame<T> &operator=(ImageFrame<T> &&src);

		////////////////////////////////////////////////////////////////////////////////////
		// Custom constructors.
		ImageFrame(const Size2D<SizeType> &sz, SizeType d = 1);
		ImageFrame(SizeType width, SizeType height, SizeType d = 1);
		ImageFrame(const std::vector<T> &srcData, const Size2D<SizeType> &sz, SizeType d = 1);
		ImageFrame(std::vector<T> &&srcData, const Size2D<SizeType> &sz, SizeType d = 1);

		////////////////////////////////////////////////////////////////////////////////////
		// Accessors.
		const std::vector<T> &data;
		const SizeType &depth;
		const Size2D<SizeType> &size;

		////////////////////////////////////////////////////////////////////////////////////
		// Methods.
		//void CopyFrom()
		void Clear(void);
		void Reset(const Size2D<SizeType> &sz, SizeType d);

	protected:
		////////////////////////////////////////////////////////////////////////////////////
		// Methods.
		static void EvaluateSize(SizeType length, SizeType w, SizeType h, SizeType d);

		////////////////////////////////////////////////////////////////////////////////////
		// Data.
		std::vector<T> data_;
		SizeType depth_;
		Size2D<SizeType> size_;
	};

	template <typename T>
	using SizeType = typename ImageFrame<T>::SizeType;

	template <typename T>
	using TestType = typename RectWith2Corner<typename SizeType<T>>;

	//template <typename T>
	//using ROI = typename RectWith1Corner<typename SizeType<T>, typename signed SizeType<T>>;
}

#include "image_inl.h"

#endif
