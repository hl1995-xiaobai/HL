/***********************************************
/gen auto by zuitools
***********************************************/
#ifndef __TEMPACTIVITY_H__
#define __TEMPACTIVITY_H__


#include "app/Activity.h"
#include "entry/EasyUIContext.h"

#include "uart/ProtocolData.h"
#include "uart/ProtocolParser.h"

#include "utils/Log.h"
#include "control/ZKDigitalClock.h"
#include "control/ZKButton.h"
#include "control/ZKCircleBar.h"
#include "control/ZKDiagram.h"
#include "control/ZKListView.h"
#include "control/ZKPointer.h"
#include "control/ZKQRCode.h"
#include "control/ZKTextView.h"
#include "control/ZKSeekBar.h"
#include "control/ZKEditText.h"
#include "control/ZKVideoView.h"
#include "control/ZKRadioGroup.h"
#include "window/ZKSlideWindow.h"

/*TAG:Macro宏ID*/
#define ID_TEMP_ListView2    80002
#define ID_TEMP_EditText3    51003
#define ID_TEMP_EditText2    51002
#define ID_TEMP_TextView11    50011
#define ID_TEMP_Button15    20015
#define ID_TEMP_TextView10    50010
#define ID_TEMP_CircleBar5    130004
#define ID_TEMP_CircleBar4    130003
#define ID_TEMP_CircleBar3    130001
#define ID_TEMP_CircleBar2    130002
#define ID_TEMP_Window10    110010
#define ID_TEMP_Button14    20014
#define ID_TEMP_Button13    20013
#define ID_TEMP_Window9    110009
#define ID_TEMP_Button12    20012
#define ID_TEMP_Window8    110008
#define ID_TEMP_TextView9    50009
#define ID_TEMP_TextView8    50008
#define ID_TEMP_TextView7    50007
#define ID_TEMP_Button11    20011
#define ID_TEMP_Window7    110007
#define ID_TEMP_TextView6    50006
#define ID_TEMP_TextView5    50005
#define ID_TEMP_TextView4    50004
#define ID_TEMP_Window6    110006
#define ID_TEMP_Window5    110005
#define ID_TEMP_EditText1    51001
#define ID_TEMP_Button9    20009
#define ID_TEMP_Button10    20010
#define ID_TEMP_TextView3    50003
#define ID_TEMP_ListView1    80001
#define ID_TEMP_TextView2    50002
#define ID_TEMP_Window1    110001
#define ID_TEMP_Button8    20008
#define ID_TEMP_Button7    20007
#define ID_TEMP_Button6    20006
#define ID_TEMP_Button5    20005
#define ID_TEMP_DigitalClock1    93001
#define ID_TEMP_TextView1    50001
#define ID_TEMP_Button4    20004
#define ID_TEMP_Button3    20003
#define ID_TEMP_Button2    20002
#define ID_TEMP_Window4    110004
#define ID_TEMP_Window3    110003
#define ID_TEMP_Window2    110002
#define ID_TEMP_Button1    20001
/*TAG:Macro宏ID END*/

class tempActivity : public Activity, 
                     public ZKSeekBar::ISeekBarChangeListener, 
                     public ZKListView::IItemClickListener,
                     public ZKListView::AbsListAdapter,
                     public ZKSlideWindow::ISlideItemClickListener,
                     public EasyUIContext::ITouchListener,
                     public ZKRadioGroup::ICheckedChangeListener,
                     public ZKEditText::ITextChangeListener,
                     public ZKVideoView::IVideoPlayerMessageListener
{
public:
    tempActivity();
    virtual ~tempActivity();

    /**
     * 注册定时器
     */
	void registerUserTimer(int id, int time);
	/**
	 * 取消定时器
	 */
	void unregisterUserTimer(int id);
	/**
	 * 重置定时器
	 */
	void resetUserTimer(int id, int time);

protected:
    /*TAG:PROTECTED_FUNCTION*/
    virtual const char* getAppName() const;
    virtual void onCreate();
    virtual void onClick(ZKBase *pBase);
    virtual void onResume();
    virtual void onPause();
    virtual void onIntent(const Intent *intentPtr);
    virtual bool onTimer(int id);

    virtual void onProgressChanged(ZKSeekBar *pSeekBar, int progress);

    virtual int getListItemCount(const ZKListView *pListView) const;
    virtual void obtainListItemData(ZKListView *pListView, ZKListView::ZKListItem *pListItem, int index);
    virtual void onItemClick(ZKListView *pListView, int index, int subItemIndex);

    virtual void onSlideItemClick(ZKSlideWindow *pSlideWindow, int index);

    virtual bool onTouchEvent(const MotionEvent &ev);
    virtual void onCheckedChanged(ZKRadioGroup* pRadioGroup, int checkedID);

    virtual void onTextChanged(ZKTextView *pTextView, const string &text);

    void rigesterActivityTimer();

    virtual void onVideoPlayerMessage(ZKVideoView *pVideoView, int msg);
    void videoLoopPlayback(ZKVideoView *pVideoView, int msg, size_t callbackTabIndex);
    void startVideoLoopPlayback();
    void stopVideoLoopPlayback();
    bool parseVideoFileList(const char *pFileListPath, std::vector<string>& mediaFileList);
    int removeCharFromString(string& nString, char c);


private:
    /*TAG:PRIVATE_VARIABLE*/
    int mVideoLoopIndex;
    int mVideoLoopErrorCount;

};

#endif