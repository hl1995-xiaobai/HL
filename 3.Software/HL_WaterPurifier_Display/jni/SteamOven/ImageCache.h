

/*
 * ImageCache.h
 *
 *	Created on: 2023年7月1日
 *		Author: lzs2180
 */
#ifndef JNI_STEAMOVEN_IMAGECACHE_H_
#define JNI_STEAMOVEN_IMAGECACHE_H_

#define CACHE_SIZE				32		// 缓存区大小


class ImageCache {

public:

	ImageCache();
	virtual ~ImageCache();

	void releaseAll();

	void cache(const char * path);

private:

	typedef struct {
		char				path[256];
		struct _bitmap_t*	bmp;
		int 				weight;
	} SCacheInfo;


	SCacheInfo		mCacheInfoList[CACHE_SIZE];

};


#endif /* JNI_STEAMOVEN_IMAGECACHE_H_ */

