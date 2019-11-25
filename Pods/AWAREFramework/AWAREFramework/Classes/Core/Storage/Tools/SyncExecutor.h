//
//  SyncExecutor.h
//  AWAREFramework
//
//  Created by Yuuki Nishiyama on 2018/03/30.
//

#import <Foundation/Foundation.h>
#import "AWAREStudy.h"

@interface SyncExecutor : NSObject <NSURLSessionDataDelegate, NSURLSessionTaskDelegate>

@property int timeoutIntervalForRequest;
@property int HTTPMaximumConnectionsPerHost;
@property int timeoutIntervalForResource;

//@property (readonly, atomic, weak) NSURLSession* _Nullable session;
@property (readonly) NSURLSession* _Nullable session;
@property (readonly) NSURLSessionDataTask* _Nullable dataTask;

@property BOOL debug;

typedef void (^SyncExecutorCallBack)(NSDictionary * _Nullable result);

// - (NSURLSession *)getSessionWithSensorName:(NSString * )name;

- (instancetype _Nonnull ) initWithAwareStudy:(AWAREStudy * _Nonnull)study sensorName:(NSString * _Nonnull)name;
- (void)syncWithData:(NSData * _Nonnull)data callback:(SyncExecutorCallBack _Nullable)callback;

- (BOOL) isSyncing;

@end


//@interface AWAREBackgroundURLSessionManager : NSObject
//+ (AWAREBackgroundURLSessionManager * _Nonnull)shared;
//@property (nonnull) NSMutableArray<NSURLSession *> * sessions;
//- (NSURLSession * _Nullable) getBackgroundURLSessionWithIdentifier:(NSString * _Nonnull)identifier;
//- (void) removeBackgroundURLSessionWithIdentifier:(NSString * _Nonnull)identifier;
//@end
