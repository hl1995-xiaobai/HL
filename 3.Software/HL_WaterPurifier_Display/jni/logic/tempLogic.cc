#pragma once
#include "uart/ProtocolSender.h"
#include "json/json.h"
#include <string>

#include "storage/StoragePreferences.h"

int menuId = 0;
int locked = 0;

static bool isWaited = false;	// 是否注册了定时器

#define WaitHandle 6
unsigned int WaitTime = 60000;

// 开水排水时间和标记位
#define CLK_Water2_Count  2
bool is_Click_Water1;
bool is_PushWater_Finished;

// 温水排水时间标记位
#define CLK_Water3_Count  3
bool is_Click_Water3;

// 冰水排水时间标记位
#define CLK_Water4_Count  4
bool is_Click_Water4;

// 收藏排水时间标记位
#define CLK_Water5_Count  5
bool is_Click_Water5;

// 收藏按钮点击
bool is_CollectBtnClicked;

// 是否童锁按钮点击
bool isChiledBtnClick;

// 类型 开水  温水 冰水
int WaterType;
// 水量
int WaterCounterType;


// 开水
const int HotWater[1] = {100};
// 温水
const int TempWater[] = {25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,
						51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,
						77,78,79,80,81,82,83,84,85};
// 冰水
const int CodeWater[] = {2,3,4,5,6,7};

// 水量
const int Water_Counter[3] = {150,300,500};

// json String

string jsonStr = "";

void registerUserTimer(int id, int time);	// 注册定时器
void unregisterUserTimer(int id);			// 取消定时器
void resetUserTimer(int id, int time);		// 重置定时器

// 排水完成
void pushWaterFinished(int type);

/*
*此文件由GUI工具生成
*文件功能：用于处理用户的逻辑相应代码
*功能说明：
*========================onButtonClick_XXXX
当页面中的按键按下后系统会调用对应的函数，XXX代表GUI工具里面的[ID值]名称，
如Button1,当返回值为false的时候系统将不再处理这个按键，返回true的时候系统将会继续处理此按键。比如SYS_BACK.
*========================onSlideWindowItemClick_XXXX(int index) 
当页面中存在滑动窗口并且用户点击了滑动窗口的图标后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如slideWindow1;index 代表按下图标的偏移值
*========================onSeekBarChange_XXXX(int progress) 
当页面中存在滑动条并且用户改变了进度后系统会调用此函数,XXX代表GUI工具里面的[ID值]名称，
如SeekBar1;progress 代表当前的进度值
*========================ogetListItemCount_XXXX() 
当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表的总数目,XXX代表GUI工具里面的[ID值]名称，
如List1;返回值为当前列表的总条数
*========================oobtainListItemData_XXXX(ZKListView::ZKListItem *pListItem, int index)
 当页面中存在滑动列表的时候，更新的时候系统会调用此接口获取列表当前条目下的内容信息,XXX代表GUI工具里面的[ID值]名称，
如List1;pListItem 是贴图中的单条目对象，index是列表总目的偏移量。具体见函数说明
*========================常用接口===============
*LOGD(...)  打印调试信息的接口
*mTextXXXPtr->setText("****") 在控件TextXXX上显示文字****
*mButton1Ptr->setSelected(true); 将控件mButton1设置为选中模式，图片会切换成选中图片，按钮文字会切换为选中后的颜色
*mSeekBarPtr->setProgress(12) 在控件mSeekBar上将进度调整到12
*mListView1Ptr->refreshListView() 让mListView1 重新刷新，当列表数据变化后调用
*mDashbroadView1Ptr->setTargetAngle(120) 在控件mDashbroadView1上指针显示角度调整到120度
*
* 在Eclipse编辑器中  使用 “alt + /”  快捷键可以打开智能提示
*/

static int t_Count = 0;

// step 1: 长按
namespace {  // 加个匿名作用域，防止多个源文件定义相同类名，运行时冲突
	//实现长按监听接口
	class LongClickListener : public ZKBase::ILongClickListener {

			 virtual void onLongClick(ZKBase *pBase) {
				 int btnId = pBase->getID();
				 if (btnId == ID_TEMP_Button1)
				 {
				    EASYUICONTEXT->openActivity("offActivity");
				 }
				 else if (btnId == ID_TEMP_Button10 || btnId == ID_TEMP_Button6)
				 {
					locked = !locked;

					mButton2Ptr->setBackgroundPic("temper_mini/2_2.png");
					mButton3Ptr->setBackgroundPic("temper_mini/3_2.png");
					mButton4Ptr->setBackgroundPic("temper_mini/4_2.png");
					mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
					mButton6Ptr->setBackgroundPic("temper_mini/6.png");
					mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
					mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

					if (locked)
						mWindow4Ptr->setBackgroundPic("temper/6_2.png");
					else
						mWindow4Ptr->setBackgroundPic("temper/6.png");

					mTextView2Ptr->setVisible(false);
					mTextView3Ptr->setVisible(false);
					mListView1Ptr->setVisible(false);
				 }

			 }
	};

}
// step 2: 声明位静态类型
static LongClickListener longButtonClickListener;
/**
 * 注册定时器
 * 填充数组用于注册定时器
 * 注意：id不能重复
 */
static S_ACTIVITY_TIMEER REGISTER_ACTIVITY_TIMER_TAB[] = {
	//{0,  6000}, //定时器id=0, 时间间隔6秒
	//{1,  1000},
	{CLK_Water2_Count,  100},
	{CLK_Water3_Count,  100},
	{CLK_Water4_Count,  100},
	{CLK_Water5_Count,  100}
};

/**
 * 当界面构造时触发
 */
static void onUI_init(){
    //Tips :添加 UI初始化的显示代码到这里,如:mText1Ptr->setText("123");
	// step 3: 注册按键长按监听
//	mButton1Ptr->setLongClickListener(&longButtonClickListener);
	mButton10Ptr->setLongClickListener(&longButtonClickListener);
	mButton6Ptr->setLongClickListener(&longButtonClickListener);
	mWindow10Ptr->setTouchPass(true);
    if (!isWaited) {
        mActivityPtr->registerUserTimer(WaitHandle, WaitTime);
        isWaited = true;
    }
    jsonStr = StoragePreferences::getString("jsonStr", "");
//    StoragePreferences::clear();
}


// json解析 返回收藏数
int getCollectCount(void) {

	Json::Reader reader;
	Json::Value root2;
	//这里为了方便，使用构造的json字符串作为解析json的输入
	std::string test_json_string = StoragePreferences::getString("jsonStr", "");
	if (reader.parse(test_json_string, root2, false)) {
	    //解析json时，一定要多多检查输入的合法性，避免非法输入造成程序崩溃。
	    if (root2.isMember("array")) {
	    	Json::Value obj = root2["array"];
	    	return obj.size();
	      }
	    } else {

	    	LOGD("解析失败");
	    }
	return 0;
}


/**
 * 当切换到该界面时触发
 */
static void onUI_intent(const Intent *intentPtr)
{
	// 界面参数传递
    if (intentPtr != NULL) {
		mButton2Ptr->setBackgroundPic("temper_mini/2_2.png");
		mButton3Ptr->setBackgroundPic("temper_mini/3_2.png");
		mButton4Ptr->setBackgroundPic("temper_mini/4_2.png");
		mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
		mButton6Ptr->setBackgroundPic("temper_mini/6.png");
		mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
		mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

		mWindow4Ptr->setBackgroundPic("temper/6.png");
		mTextView2Ptr->setVisible(false);
		mTextView3Ptr->setVisible(false);
//		mListView1Ptr->setVisible(false);
    }
}


/*
 * 当界面显示时触发
 */
static void onUI_show() {

}

/*
 * 当界面隐藏时触发
 */
static void onUI_hide() {
}

/*
 * 当界面完全退出时触发
 */
static void onUI_quit() {
	// step 4: 取消按键长按监听
	mButton1Ptr->setLongClickListener(NULL);
	mButton10Ptr->setLongClickListener(NULL);
	mButton6Ptr->setLongClickListener(NULL);
	if (isWaited) {
		mActivityPtr->unregisterUserTimer(WaitHandle);
		isWaited = false;
	}
}

/**
 * 串口数据回调接口
 */
static void onProtocolDataUpdate(const SProtocolData &data) {

}

/**
 * 定时器触发函数
 * 不建议在此函数中写耗时操作，否则将影响UI刷新
 * 参数： id
 *         当前所触发定时器的id，与注册时的id相同
 * 返回值: true
 *             继续运行当前定时器
 *         false
 *             停止运行当前定时器
 */
static bool onUI_Timer(int id){
	switch (id)
	{
		case WaitHandle:
		    EASYUICONTEXT->openActivity("clockActivity");
		break;
		case CLK_Water2_Count:
			// 开水计时
			if (is_Click_Water1) {
				mCircleBar2Ptr->setProgress(t_Count);
				++t_Count;
				if (mCircleBar2Ptr->getProgress() == 100) {
					pushWaterFinished(2);
					is_Click_Water1 = false;
				}
			}
		break;
		case CLK_Water3_Count:
			// 温水计时
			if (is_Click_Water3) {
				mCircleBar3Ptr->setProgress(t_Count);
				++t_Count;
				if (mCircleBar3Ptr->getProgress() == 100) {
					pushWaterFinished(3);
					is_Click_Water3 = false;
				}
			}
		break;
		case CLK_Water4_Count:
			// 冰水计时
			if (is_Click_Water4) {
				mCircleBar4Ptr->setProgress(t_Count);
				++t_Count;
				if (mCircleBar4Ptr->getProgress() == 100) {
					pushWaterFinished(4);
					is_Click_Water4 = false;
				}
			}
		break;
		case CLK_Water5_Count:
			// 收藏
			if (is_Click_Water5) {
				mCircleBar5Ptr->setProgress(t_Count);
				++t_Count;
				if (mCircleBar5Ptr->getProgress() == 100) {
					pushWaterFinished(5);
					is_Click_Water5 = false;
				}
			}
		break;
		default:
			break;
	}
    return true;
}

// 排水完成
void pushWaterFinished(int type)
{
	mEditText3Ptr->setVisible(true);
	mEditText2Ptr->setVisible(true);
	switch (type)
	{
		case 2:
		{
			mWindow4Ptr->setBackgroundPic("temper/2_4.png");
			mCircleBar2Ptr->setVisible(false);
//			EASYUICONTEXT->showIME()
		}
		break;

		case 3:
		{
			mWindow4Ptr->setBackgroundPic("temper/3_4.png");
			mCircleBar3Ptr->setVisible(false);
		}
		break;

		case 4:
		{
			mWindow4Ptr->setBackgroundPic("temper/4_4.png");
			mCircleBar4Ptr->setVisible(false);
		}
		break;

		case 5:
		{
			mWindow4Ptr->setBackgroundPic("temper/5_4.png");
			mCircleBar5Ptr->setVisible(false);
		}
		break;

	}
}

/**
 * 有新的触摸事件时触发
 * 参数：ev
 *         新的触摸事件
 * 返回值：true
 *            表示该触摸事件在此被拦截，系统不再将此触摸事件传递到控件上
 *         false
 *            触摸事件将继续传递到控件上
 */
static bool ontempActivityTouchEvent(const MotionEvent &ev) {
    switch (ev.mActionStatus) {
		case MotionEvent::E_ACTION_DOWN://触摸按下
			//LOGD("时刻 = %ld 坐标  x = %d, y = %d", ev.mEventTime, ev.mX, ev.mY);
			if (isWaited) {
		        mActivityPtr->resetUserTimer(WaitHandle, WaitTime);
			}
			break;
		case MotionEvent::E_ACTION_MOVE://触摸滑动
			break;
		case MotionEvent::E_ACTION_UP:  //触摸抬起
			break;
		default:
			break;
	}
	return false;
}

static bool onButtonClick_Button1(ZKButton *pButton) {
	mWindow4Ptr->setVisible(false);
	mWindow5Ptr->setVisible(true);
	mWindow6Ptr->setVisible(true);
	mWindow7Ptr->setVisible(true);
	mWindow8Ptr->setVisible(false);
	isChiledBtnClick = false;
    return false;
}


//bool isLockedChiled() {
//
//	return true;
//}


static bool onButtonClick_Button2(ZKButton *pButton) {
	if (locked) {
		return false;
	}
	is_CollectBtnClicked = false;
	WaterType = 2;
    menuId = pButton->getID();
    mButton2Ptr->setBackgroundPic("temper_mini/2.png");
    mButton3Ptr->setBackgroundPic("temper_mini/3_2.png");
    mButton4Ptr->setBackgroundPic("temper_mini/4_2.png");
    mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
    mButton6Ptr->setBackgroundPic("temper_mini/6_2.png");
    mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
    mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

//    mWindow10Ptr->setBackgroundPic("temper/SettingTemperBack2.png");
    mWindow4Ptr->setBackgroundPic("temper/2.png");
    mTextView3Ptr->setVisible(false);
    mButton10Ptr->setVisible(false);
    mTextView2Ptr->setVisible(true);
    mListView1Ptr->setVisible(true);
    mListView1Ptr->setTouchable(false);
    mListView1Ptr->refreshListView();

    mListView2Ptr->setVisible(false);

    mCircleBar2Ptr->setVisible(false);
    mCircleBar3Ptr->setVisible(false);
    mCircleBar4Ptr->setVisible(false);
    mCircleBar5Ptr->setVisible(false);

	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
//	mWindow10Ptr->setVisible(true);

	mEditText2Ptr->setVisible(false);
	mTextView11Ptr->setVisible(false);
	mEditText2Ptr->setText("");
	mEditText3Ptr->setVisible(false);
	mEditText3Ptr->setText("");
    mTextView1Ptr->setText("温度");

    // 开水动画标记位
    t_Count = 0;
    mCircleBar2Ptr->setProgress(t_Count);
    is_Click_Water1 = false;
    is_Click_Water3 = false;
    is_Click_Water4 = false;
    is_Click_Water5 = false;
    is_PushWater_Finished = false;
    return false;
}

static bool onButtonClick_Button3(ZKButton *pButton) {
	if (locked) {
		return false;
	}
	is_CollectBtnClicked = false;
    menuId = pButton->getID();
    WaterType = 3;
    mButton2Ptr->setBackgroundPic("temper_mini/2_2.png");
    mButton3Ptr->setBackgroundPic("temper_mini/3.png");
    mButton4Ptr->setBackgroundPic("temper_mini/4_2.png");
    mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
    mButton6Ptr->setBackgroundPic("temper_mini/6_2.png");
    mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
    mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

//    mWindow10Ptr->setBackgroundPic("temper/SettingTemperBack3.png");
    mWindow4Ptr->setBackgroundPic("temper/3.png");
    mTextView2Ptr->setVisible(true);
    mTextView3Ptr->setVisible(false);
    mListView1Ptr->setVisible(true);
    mListView1Ptr->setTouchable(true);
    mListView1Ptr->refreshListView();


    mListView2Ptr->setVisible(false);
    mButton10Ptr->setVisible(false);

    mCircleBar2Ptr->setVisible(false);
    mCircleBar3Ptr->setVisible(false);
    mCircleBar4Ptr->setVisible(false);
    mCircleBar5Ptr->setVisible(false);

	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
//	mWindow10Ptr->setVisible(true);
	mEditText2Ptr->setVisible(false);
	mTextView11Ptr->setVisible(false);
	mEditText2Ptr->setText("");
	mEditText3Ptr->setVisible(false);
	mEditText3Ptr->setText("");
    mTextView1Ptr->setText("温度");

    is_Click_Water1 = false;
    is_Click_Water3 = false;
    is_Click_Water4 = false;
    is_Click_Water5 = false;

    return false;
}

static bool onButtonClick_Button4(ZKButton *pButton) {
	if (locked) {
		return false;
	}
	is_CollectBtnClicked = false;
    menuId = 4;
    WaterType = pButton->getID();
    mButton2Ptr->setBackgroundPic("temper_mini/2_2.png");
    mButton3Ptr->setBackgroundPic("temper_mini/3_2.png");
    mButton4Ptr->setBackgroundPic("temper_mini/4.png");
    mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
    mButton6Ptr->setBackgroundPic("temper_mini/6_2.png");
    mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
    mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

//    mWindow10Ptr->setBackgroundPic("temper/SettingTemperBack4.png");
    mWindow4Ptr->setBackgroundPic("temper/4.png");
    mTextView2Ptr->setVisible(true);
    mTextView3Ptr->setVisible(false);
    mListView1Ptr->setVisible(true);
    mListView1Ptr->setTouchable(true);
    mListView1Ptr->refreshListView();
    mListView2Ptr->setVisible(false);
    mButton10Ptr->setVisible(false);

    mCircleBar2Ptr->setVisible(false);
    mCircleBar3Ptr->setVisible(false);
    mCircleBar4Ptr->setVisible(false);
    mCircleBar5Ptr->setVisible(false);

	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
//	mWindow10Ptr->setVisible(true);
	mEditText2Ptr->setVisible(false);
	mTextView11Ptr->setVisible(false);
	mEditText2Ptr->setText("");
	mEditText3Ptr->setVisible(false);
	mEditText3Ptr->setText("");
    mTextView1Ptr->setText("温度");
    is_Click_Water1 = false;
    is_Click_Water3 = false;
    is_Click_Water4 = false;
    is_Click_Water5 = false;
    return false;
}

static bool onButtonClick_Button5(ZKButton *pButton) {
	if (locked) {
		return false;
	}
	is_CollectBtnClicked = true;
    menuId = pButton->getID();
    mButton2Ptr->setBackgroundPic("temper_mini/2_2.png");
    mButton3Ptr->setBackgroundPic("temper_mini/3_2.png");
    mButton4Ptr->setBackgroundPic("temper_mini/4_2.png");
    mButton5Ptr->setBackgroundPic("temper_mini/5.png");
    mButton6Ptr->setBackgroundPic("temper_mini/6_2.png");
    mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
    mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

//    mWindow10Ptr->setBackgroundPic("temper/SettingTemperBack5.png");
    mWindow4Ptr->setBackgroundPic("finished/5.png");
    mListView1Ptr->setVisible(false);
    mListView2Ptr->setVisible(true);
    mTextView2Ptr->setVisible(false);
    mTextView3Ptr->setVisible(false);
    mButton10Ptr->setVisible(false);

    mCircleBar2Ptr->setVisible(false);
    mCircleBar3Ptr->setVisible(false);
    mCircleBar4Ptr->setVisible(false);
    mCircleBar5Ptr->setVisible(false);

    mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
//	mWindow10Ptr->setVisible(true);
	mEditText2Ptr->setVisible(false);
	mTextView11Ptr->setVisible(false);
	mEditText2Ptr->setText("");
	mEditText3Ptr->setVisible(false);
	mEditText3Ptr->setText("");
    mTextView1Ptr->setText("收藏");
    is_Click_Water1 = false;
    is_Click_Water3 = false;
    is_Click_Water4 = false;
    is_Click_Water5 = false;
    return false;
}

static bool onButtonClick_Button6(ZKButton *pButton) {
	is_CollectBtnClicked = false;
    menuId = pButton->getID();
    mButton2Ptr->setBackgroundPic("temper_mini/2_2.png");
    mButton3Ptr->setBackgroundPic("temper_mini/3_2.png");
    mButton4Ptr->setBackgroundPic("temper_mini/4_2.png");
    mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
    mButton6Ptr->setBackgroundPic("temper_mini/6.png");
    mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");
    mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");


	if (locked)
		mWindow4Ptr->setBackgroundPic("temper/6_2.png");
	else
		mWindow4Ptr->setBackgroundPic("temper/6.png");

    mTextView2Ptr->setVisible(false);
    mTextView3Ptr->setVisible(false);
    mListView1Ptr->setVisible(false);
    mListView2Ptr->setVisible(false);
    mButton10Ptr->setVisible(true);

    mCircleBar2Ptr->setVisible(false);
    mCircleBar3Ptr->setVisible(false);
    mCircleBar4Ptr->setVisible(false);
    mCircleBar5Ptr->setVisible(false);

	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
	mEditText2Ptr->setVisible(false);
	mTextView11Ptr->setVisible(false);
	mEditText2Ptr->setText("");
	mEditText3Ptr->setVisible(false);
	mEditText3Ptr->setText("");
	//	mWindow10Ptr->setVisible(false);

	isChiledBtnClick = true;

    mTextView1Ptr->setText("童锁");
    is_Click_Water1 = false;
    is_Click_Water3 = false;
    is_Click_Water4 = false;
    is_Click_Water5 = false;
    return false;
}

static bool onButtonClick_Button7(ZKButton *pButton)
{
	if (locked) {
		return false;
	}
	is_CollectBtnClicked = false;
	if (menuId == ID_TEMP_Button5) {
		return false;
	}

    switch (menuId)
    {
    	case ID_TEMP_Button2:
        	pButton->setBackgroundPic("temper_mini/2_7.png");
        	mButton2Ptr->setBackgroundPic("temper_mini/2_1.png");
        	mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

            mWindow4Ptr->setBackgroundPic("temper/2.png");
            mTextView3Ptr->setVisible(true);
            mListView1Ptr->setVisible(true);
    	break;

    	case ID_TEMP_Button3:
        	pButton->setBackgroundPic("temper_mini/3_7.png");
        	mButton3Ptr->setBackgroundPic("temper_mini/3_1.png");
        	mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

            mWindow4Ptr->setBackgroundPic("temper/3.png");
            mTextView3Ptr->setVisible(true);
            mListView1Ptr->setVisible(true);
    	break;

    	case ID_TEMP_Button4:
        	pButton->setBackgroundPic("temper_mini/4_7.png");
        	mButton4Ptr->setBackgroundPic("temper_mini/4_1.png");
        	mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

            mWindow4Ptr->setBackgroundPic("temper/4.png");
            mTextView3Ptr->setVisible(true);
            mListView1Ptr->setVisible(true);
    	break;

    	case ID_TEMP_Button5:
        	pButton->setBackgroundPic("temper_mini/5_7.png");
        	mButton5Ptr->setBackgroundPic("temper_mini/5_2.png");
        	mButton8Ptr->setBackgroundPic("temper_mini/8_2.png");

            mWindow4Ptr->setBackgroundPic("temper/5.png");
            mTextView3Ptr->setVisible(true);
            mListView1Ptr->setVisible(true);
    	break;
    	default:
    		pButton->setBackgroundPic("temper_mini/7_2.png");
    	break;
    }

    // 童锁
//    if (menuId == ID_TEMP_Button6)
//    {
//	    mTextView2Ptr->setVisible(false);
//	    mTextView3Ptr->setVisible(false);
//    }
//    else
//    {
//	    mTextView2Ptr->setVisible(false);
//	    mTextView3Ptr->setVisible(true);
//	    mTextView1Ptr->setText("水量");
//    }

    mTextView2Ptr->setVisible(false);

	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
//	mWindow10Ptr->setVisible(true);

	mCircleBar2Ptr->setVisible(false);
	mCircleBar3Ptr->setVisible(false);
	mCircleBar4Ptr->setVisible(false);
	mCircleBar5Ptr->setVisible(false);
	mListView2Ptr->setVisible(false);
	mEditText2Ptr->setVisible(false);
	mTextView11Ptr->setVisible(false);
	mEditText2Ptr->setText("");
	mEditText3Ptr->setVisible(false);
	mEditText3Ptr->setText("");
	menuId = ID_TEMP_Button7;
	mListView1Ptr->setTouchable(true);
	mListView1Ptr->refreshListView();
	is_Click_Water1 = false;
	is_Click_Water3 = false;
	is_Click_Water4 = false;
	is_Click_Water5 = false;
    return false;
}

static bool onButtonClick_Button8(ZKButton *pButton)
{
	if (locked) {
		return false;
	}

	if (is_CollectBtnClicked) {
		return false;
	}

	if (WaterType == 0) {
		return false;
	}

    switch (WaterType)
    {
    	case 2:
        	pButton->setBackgroundPic("temper_mini/2_8.png");
        	mButton2Ptr->setBackgroundPic("temper_mini/2_1.png");
    		mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");

    		mCircleBar2Ptr->setVisible(true);
    		mCircleBar3Ptr->setVisible(false);
    		mCircleBar4Ptr->setVisible(false);
    		mCircleBar5Ptr->setVisible(false);

    		mWindow4Ptr->setBackgroundPic("temper/2_2.png");
    	    mTextView2Ptr->setVisible(false);
    	    mTextView3Ptr->setVisible(false);
    	    mListView1Ptr->setVisible(false);

    	    t_Count = 0;
    	    mCircleBar2Ptr->setProgress(t_Count);
    	    is_Click_Water1 = true;

    	break;

    	case 3:
        	pButton->setBackgroundPic("temper_mini/3_8.png");
        	mButton3Ptr->setBackgroundPic("temper_mini/3_1.png");
    		mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");

    	    mWindow4Ptr->setBackgroundPic("temper/3_2.png");

    	    mCircleBar2Ptr->setVisible(false);
    	    mCircleBar3Ptr->setVisible(true);
    	    mCircleBar4Ptr->setVisible(false);
    	    mCircleBar5Ptr->setVisible(false);

    	    mTextView2Ptr->setVisible(false);
    	    mTextView3Ptr->setVisible(false);
    	    mListView1Ptr->setVisible(false);

    	    t_Count = 0;
    	    mCircleBar3Ptr->setProgress(t_Count);
    	    is_Click_Water3 = true;

    	break;

    	case 4:
        	pButton->setBackgroundPic("temper_mini/4_8.png");
        	mButton4Ptr->setBackgroundPic("temper_mini/4_1.png");
    		mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");

    	    mWindow4Ptr->setBackgroundPic("temper/4_2.png");

    	    mCircleBar2Ptr->setVisible(false);
    	    mCircleBar3Ptr->setVisible(false);
    	    mCircleBar4Ptr->setVisible(true);
    	    mCircleBar5Ptr->setVisible(false);

    	    mTextView2Ptr->setVisible(false);
    	    mTextView3Ptr->setVisible(false);
    	    mListView1Ptr->setVisible(false);

    	    t_Count = 0;
    	    mCircleBar4Ptr->setProgress(t_Count);
    	    is_Click_Water4 = true;

    	break;

    	case ID_TEMP_Button5:
        	pButton->setBackgroundPic("temper_mini/5_8.png");
        	mButton5Ptr->setBackgroundPic("temper_mini/5_1.png");
    		mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");

    	    mWindow4Ptr->setBackgroundPic("temper/5_2.png");

    	    mCircleBar2Ptr->setVisible(false);
    	    mCircleBar3Ptr->setVisible(false);
    	    mCircleBar4Ptr->setVisible(false);
    	    mCircleBar5Ptr->setVisible(true);

    	    mTextView2Ptr->setVisible(false);
    	    mTextView3Ptr->setVisible(false);
    	    mListView1Ptr->setVisible(false);

    	    t_Count = 0;
    	    mCircleBar5Ptr->setProgress(t_Count);
    	    is_Click_Water5 = true;
    	break;

    	default:
    		pButton->setBackgroundPic("temper_mini/8_2.png");
    	    mTextView2Ptr->setVisible(false);
    	    mTextView3Ptr->setVisible(false);
    	    mListView1Ptr->setVisible(false);
    	break;
    }


	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
//	mWindow10Ptr->setVisible(false);
    mButton10Ptr->setVisible(false);
    mListView2Ptr->setVisible(false);
    mEditText2Ptr->setVisible(false);
    mTextView11Ptr->setVisible(false);
    mEditText3Ptr->setVisible(false);
    mEditText3Ptr->setText("");
    // 童锁
    if (menuId != ID_TEMP_Button6)
    {
        mTextView1Ptr->setText("工作中");
    }
    return false;
}

static int getListItemCount_ListView1(const ZKListView *pListView) {
	if (menuId == ID_TEMP_Button2) {
		return 1;
	} else if (menuId == ID_TEMP_Button3) {
		return sizeof (TempWater) / sizeof (TempWater[0]);
	} else if (menuId == ID_TEMP_Button4) {
		return sizeof (CodeWater) / sizeof (CodeWater[0]);
	} else if (menuId == ID_TEMP_Button7) {
		return sizeof (Water_Counter) / sizeof (Water_Counter[0]);
	}
	return 1;
}


static void obtainListItemData_ListView1(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
	if (menuId == ID_TEMP_Button2) {
		pListItem->setText(HotWater[index]);
	} else if (menuId == ID_TEMP_Button3) {
		pListItem->setText(TempWater[index]);
	} else if (menuId == ID_TEMP_Button4) {
		pListItem->setText(CodeWater[index]);
	} else if (menuId == ID_TEMP_Button7) {
		pListItem->setText(Water_Counter[index]);
	}

	int firstr = pListView->getFirstVisibleItemIndex();
	if((firstr+1)%(pListView->getListItemCount()) == index){
		// 选中
		StoragePreferences::putInt("CType", menuId);
		if (menuId == ID_TEMP_Button2) {
			// 开水
			StoragePreferences::putInt("CTemp", HotWater[index-1]);
		} else if (menuId == ID_TEMP_Button3) {
			StoragePreferences::putInt("CTemp", TempWater[index-1]);
		} else if (menuId == ID_TEMP_Button4) {
			StoragePreferences::putInt("CTemp", CodeWater[index-1]);
		} else if (menuId == ID_TEMP_Button7) {
			StoragePreferences::putInt("CWaterCounter", Water_Counter[index-1]);
		}
		pListItem->setTextSize(130);
	}else{
		pListItem->setTextSize(100);
	}

	pListItem->setTextColor(0xffffff);
}

static void onListItemClick_ListView1(ZKListView *pListView, int index, int id) {
}

static bool onButtonClick_Button10(ZKButton *pButton) {
    return false;
}

static void onEditTextChanged_EditText1(const std::string &text) {
}

static bool onButtonClick_Button11(ZKButton *pButton) {
	mWindow4Ptr->setVisible(true);
	mWindow5Ptr->setVisible(false);
	mWindow6Ptr->setVisible(false);
	mWindow7Ptr->setVisible(false);
	mWindow8Ptr->setVisible(true);
	pButton->setBackgroundPic("sys/back.png");
    return false;
}

static bool onButtonClick_Button12(ZKButton *pButton) {
	mWindow4Ptr->setVisible(false);
	mWindow5Ptr->setVisible(true);
	mWindow6Ptr->setVisible(true);
	mWindow7Ptr->setVisible(true);
	mWindow8Ptr->setVisible(false);
	isChiledBtnClick = false;
	pButton->setBackgroundPic("sys/next.png");
    // mTextView1Ptr->setText("首页");
    return false;
}
static bool onButtonClick_Button9(ZKButton *pButton) {
	mWindow9Ptr->setVisible(true);

    return false;
}

static bool onButtonClick_Button13(ZKButton *pButton) {
	mWindow9Ptr->setVisible(false);
    return false;
}

static bool onButtonClick_Button14(ZKButton *pButton) {
	mWindow9Ptr->setVisible(false);
	if (isChiledBtnClick) {
		locked = 0;
		mWindow4Ptr->setBackgroundPic("temper/6.png");
	}
    return false;
}

static bool onButtonClick_Button15(ZKButton *pButton) {
//	EASYUICONTEXT->openActivity("UserImeActivity");
	mWindow4Ptr->setBackgroundPic("temper/finished.png");
	mEditText2Ptr->setVisible(true);
	mTextView11Ptr->setVisible(true);
	mEditText3Ptr->setVisible(true);
	return false;
}

static int getListItemCount_ListView2(const ZKListView *pListView) {
    return getCollectCount();
}

static void obtainListItemData_ListView2(ZKListView *pListView,ZKListView::ZKListItem *pListItem, int index) {
	Json::Reader reader;
	Json::Value root;
	//这里为了方便，使用构造的json字符串作为解析json的输入
	std::string test_json_string = StoragePreferences::getString("jsonStr", "");
	if (reader.parse(test_json_string, root, false)) {
		//解析json时，一定要多多检查输入的合法性，避免非法输入造成程序崩溃。
		if (root.isMember("array")) {
			Json::Value array = root["array"];
			Json::Value obj = array[index];
			pListItem->setText(obj["CName"].toStyledString());
		}
	} else {
		LOGD("解析失败");
	}
}

static void onListItemClick_ListView2(ZKListView *pListView, int index, int id) {
    //LOGD(" onListItemClick_ ListView2  !!!\n");
	WaterType = 5;
	mButton8Ptr->setBackgroundPic("temper_mini/5_8.png");
	mButton5Ptr->setBackgroundPic("temper_mini/5_1.png");
	mButton7Ptr->setBackgroundPic("temper_mini/7_2.png");

	mWindow4Ptr->setBackgroundPic("temper/5_2.png");

	mCircleBar2Ptr->setVisible(false);
	mCircleBar3Ptr->setVisible(false);
	mCircleBar4Ptr->setVisible(false);
	mCircleBar5Ptr->setVisible(true);

	mTextView2Ptr->setVisible(false);
	mTextView3Ptr->setVisible(false);
	mListView1Ptr->setVisible(false);
	mListView2Ptr->setVisible(false);
	t_Count = 0;
	mCircleBar5Ptr->setProgress(t_Count);
	is_Click_Water5 = true;
}

static void onEditTextChanged_EditText2(const std::string &text) {
    //LOGD(" onEditTextChanged_ EditText2 %s !!!\n", text.c_str());
	StoragePreferences::putString("CName", mEditText2Ptr->getText());
}

static void onEditTextChanged_EditText3(const std::string &text) {
	mEditText3Ptr->setVisible(false);
	std::string jsonStr = StoragePreferences::getString("jsonStr", "");
		if (jsonStr.empty()) {
			Json::Value root;
		    Json::Value array;
		    Json::Value collect1;
		    collect1["CName"] = text;
		    collect1["CType"] = StoragePreferences::getString("CType", "1");
		    collect1["CTemp"] = StoragePreferences::getString("CTemp", "100");
		    collect1["CWaterCounter"] = StoragePreferences::getString("CWaterCounter", "150");
		    array.append(collect1);
		    root["array"] = array;
		    StoragePreferences::putString("jsonStr", root.toStyledString().c_str());
		} else {
			Json::Reader reader;
			Json::Value root2;
		    Json::Value array;

		    //这里为了方便，使用构造的json字符串作为解析json的输入
		    std::string test_json_string = StoragePreferences::getString("jsonStr", "");
		    if (reader.parse(test_json_string, root2, false)) {
		    	LOGD("解析成功");
		    	//解析json时，一定要多多检查输入的合法性，避免非法输入造成程序崩溃。
		    	if (root2.isMember("array")) {
		    		array = root2["array"];
		    		Json::Value collected;
		    		if (!text.empty()) {
		    			collected["CName"] = text;
		    			collected["CType"] = StoragePreferences::getString("CType", "1");
		    			collected["CTemp"] = StoragePreferences::getString("CTemp", "100");
		    			collected["CWaterCounter"] = StoragePreferences::getString("CWaterCounter", "150");
		    			array.append(collected);
		    			root2["array"] = array;
		    			StoragePreferences::putString("jsonStr", root2.toStyledString().c_str());
		    		}
		    	} else {
		    		LOGD("333333333333333333333333解析失败");
		    	}
		    } else {
		    	LOGD("解析失败");
		    }
		 }



}
