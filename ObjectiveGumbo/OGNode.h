//
//  OGNode.h
//  ObjectiveGumbo
//
//  Copyright (c) 2013 Programming Thomas, 2017 Richard Warrender. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NSString+OGString.h"

NS_ASSUME_NONNULL_BEGIN

typedef BOOL(^SelectorBlock)(id node);

@class OGDocument;


/**
 Super class the DOM tree nodes are built from. This is an abstract class that doesn't get implemented directly but sets up the relationships between the other nodes.
 */
@interface OGNode : NSObject

/**
 The OGDocument that owns the tree this node is part of.
 @warning If the ObjectiveGumbo node-prefixed class methods were used instead of the document-prefixed class methods then the tree does not have a document and therefore will be nil.
 */
@property (nonatomic, weak, readonly, nullable) OGDocument *ownerDocument;

/** The parent node that this child node belongs to */
@property (nonatomic, weak, readonly, nullable) OGNode *parent;

/** If this node has any child nodes, they will be in this array */
@property (nonatomic, strong, readonly) NSArray<OGNode *> *children;

/** Any text content contained by this node and all it's sub-nodes */
@property (nonatomic, copy, readonly) NSString *text;

/** Any HTML and text contained by this node and all it's sub-nodes */
@property (nonatomic, copy, readonly) NSString *html;

/** The first child node */
@property (nonatomic, readonly, nullable) OGNode *first;

/** The last child node */
@property (nonatomic, readonly, nullable) OGNode *last;

/** If this is a child node and there are other children then it is the next node in the sequence */
@property (nonatomic, weak, readonly, nullable) OGNode *nextSibling;

/** If this is a child node and there are other children then it is the previous node in the sequence or nil */
@property (nonatomic, weak, readonly, nullable) OGNode *previousSibling;

/** Returns YES if node is a descendant of the receiver i.e. the receiver underneath node in the tree  */
- (BOOL)isDescendantOfNode:(OGNode *)node;

/** Returns YES if node is a ancestor of the receiver i.e. one of the receiver's children equals or contains node */
- (BOOL)isAncestorOfNode:(OGNode *)node;

- (NSString *)htmlWithIndentation:(int)indentationLevel;

@end

NS_ASSUME_NONNULL_END
