

typedef void(^UnityAdsWebRequestProgress)(NSString *url, long long bytes, long long totalBytes);
typedef void(^UnityAdsWebRequestStart)(NSString *url, long long totalBytes);

@interface UADSWebRequest : NSObject <NSURLConnectionDelegate>

@property (nonatomic, strong) NSString *url;
@property (nonatomic, strong) NSString *requestType;
@property (nonatomic, strong) NSString *body;
@property (nonatomic, strong) NSDictionary<NSString*,NSArray*> *headers;
@property (nonatomic, strong) NSDictionary<NSString*,NSString*> *responseHeaders;
@property (nonatomic, strong) NSMutableData *receivedData;
@property (nonatomic, strong) NSError *error;
@property (nonatomic, assign) long long expectedContentLength;
@property (nonatomic, assign) long responseCode;
@property (nonatomic, assign) BOOL canceled;
@property (nonatomic, assign) BOOL finished;
@property (nonatomic, strong) NSCondition *blockCondition;
@property (nonatomic, strong) UnityAdsWebRequestProgress progressBlock;
@property (nonatomic, strong) UnityAdsWebRequestStart startBlock;

@property (nonatomic, strong) NSMutableURLRequest *request;
@property (nonatomic, strong) NSURLConnection *connection;
@property (nonatomic, assign) int connectTimeout;


- (instancetype)initWithUrl:(NSString *)url requestType:(NSString *)requestType headers:(NSDictionary<NSString*,NSArray<NSString*>*> *)headers connectTimeout:(int)connectTimeout;
- (NSData *)makeRequest;
- (void)cancel;

@end