#import <Foundation/Foundation.h>
#import <React/RCTBridgeModule.h>

#import <Branch/Branch.h>

extern NSString * _Nonnull const RNBranchLinkOpenedNotification;
extern NSString * _Nonnull const RNBranchLinkOpenedNotificationErrorKey;
extern NSString * _Nonnull const RNBranchLinkOpenedNotificationParamsKey;
extern NSString * _Nonnull const RNBranchLinkOpenedNotificationUriKey;
extern NSString * _Nonnull const RNBranchLinkOpenedNotificationBranchUniversalObjectKey;
extern NSString * _Nonnull const RNBranchLinkOpenedNotificationLinkPropertiesKey;


@interface RNBranch : NSObject <RCTBridgeModule>

@property (class, readonly, nonnull) Branch *branch;

+ (void)initSessionWithLaunchOptions:(NSDictionary * _Nullable)launchOptions isReferrable:(BOOL)isReferrable;
/*
For Bunch, the deeplink param is not a critical dependency, but missing any critical deeplink info would create a critical bug. When posting multiple notifications, some key notifications may be suppressed by the react native framework. To fix the issue, we will simply ignore empty messages.
*/
+ (BOOL)shouldIgnoreResult:(NSDictionary *)result;
+ (BOOL)handleDeepLink:(NSURL * _Nonnull)url __deprecated_msg("Please use [RNBranch.branch application:openURL:options] or [RNBranch.branch application:openURL:sourceApplication:annotation:] instead.");
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpartial-availability"
+ (BOOL)continueUserActivity:(NSUserActivity * _Nonnull)userActivity;
#pragma clang diagnostic pop

// Must be called before any other static method below
+ (void)useTestInstance;
+ (void)deferInitializationForJSLoad;

+ (void)setDebug;
+ (void)delayInitToCheckForSearchAds;
+ (void)setAppleSearchAdsDebugMode;
+ (void)setRequestMetadataKey:(NSString * _Nonnull)key value:(NSObject * _Nonnull)value;

@end
