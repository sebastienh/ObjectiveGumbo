//
//  OGParseError.h
//  ObjectiveGumbo
//
//  Copyright (c) 2017 Richard Warrender. All rights reserved.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const OGErrorDomain;

typedef NS_ENUM(NSInteger, OGError) {
    OGErrorNoContent = 1,               /* No content handed to parser */
    OGErrorParser = 2,                  /* General error for parsing failures */
    OGErrorNotUTF8Compatible = 3        /* Gumbo lib is only UTF-8 compatible */
};

/**
 Struct for storing parse error location in string
 */
struct OGErrorPosition {
    unsigned int line;
    unsigned int column;
    unsigned int offset;
};
typedef struct OGErrorPosition OGErrorPosition;


/**
 Specific class for parse errors including line position
 */
@interface OGParseError : NSError
@property (nonatomic, assign, readonly) OGErrorPosition position;
- (instancetype)initWithDomain:(NSErrorDomain)domain code:(NSInteger)code position:(OGErrorPosition)position userInfo:(NSDictionary *)dict;
+ (instancetype)errorWithDomain:(NSErrorDomain)domain code:(NSInteger)code position:(OGErrorPosition)position userInfo:(nullable NSDictionary *)dict;
@end

NS_ASSUME_NONNULL_END
