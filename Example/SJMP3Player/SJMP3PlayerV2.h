//
//  SJMP3PlayerV2.h
//  SJMP3Player_Example
//
//  Created by 畅三江 on 2018/5/26.
//  Copyright © 2018年 changsanjiang. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@protocol SJMP3PlayerV2Delegate;

@interface SJMP3PlayerV2 : NSObject
@property (nonatomic) BOOL enableDBUG;

+ (instancetype)player;
- (void)playWithURL:(NSURL *)URL minDuration:(double)minDuration;

@property (nonatomic, weak, nullable) id <SJMP3PlayerV2Delegate> delegate;
@property (nonatomic, strong, readonly, nullable) NSURL *currentURL;
@property (nonatomic, readonly) NSTimeInterval currentTime;
@property (nonatomic, readonly) NSTimeInterval duration;
@property (nonatomic, readonly) BOOL isPlaying;
@property (nonatomic) double minDuration;
@property (nonatomic) float rate;

/*!
 *  跳转 */
- (BOOL)seekToTime:(NSTimeInterval)sec;

/*!
 *  暂停 */
- (void)pause;

/*!
 *  恢复播放 */
- (void)resume;

/*!
 *  停止播放, 停止缓存 */
- (void)stop;

/*!
 *  清除本地缓存 */
- (void)clearDiskAudioCache;

/*!
 *  已缓存的audios的大小 */
- (NSInteger)diskAudioCacheSize;

/*!
 *  查看音乐是否已缓存 */
- (BOOL)isCached:(NSURL *)URL;
@end


//@interface SJMP3Info : NSObject
//@property (nonatomic, strong) NSString *title;
//@property (nonatomic, strong) NSString *artist;
//@property (nonatomic, strong) UIImage *cover;
//
//- (instancetype)initWithTitle:(NSString *)title artist:(NSString *)artist cover:(UIImage *)cover;
//
//@end


@protocol SJMP3PlayerV2Delegate <NSObject>

@required

///// 用于显示在锁屏界面 Control Center 的信息
//- (SJMP3Info *)playInfo;
///// 点击了锁屏界面 Control Center 下一首按钮
//- (void)remoteEvent_NextWithAudioPlayer:(SJMP3PlayerV2 *)player;
///// 点击了锁屏界面 Control Center 上一首按钮
//- (void)remoteEvent_PreWithAudioPlayer:(SJMP3PlayerV2 *)player;

@optional

- (void)audioPlayer:(SJMP3PlayerV2 *)player audioDownloadProgress:(CGFloat)progress;

- (void)audioPlayer:(SJMP3PlayerV2 *)player currentTime:(NSTimeInterval)currentTime reachableTime:(NSTimeInterval)reachableTime totalTime:(NSTimeInterval)totalTime;

- (void)audioPlayerDidFinishPlaying:(SJMP3PlayerV2 *)player;

@end
NS_ASSUME_NONNULL_END