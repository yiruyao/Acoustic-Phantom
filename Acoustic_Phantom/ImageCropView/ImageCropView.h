//
//  Created by Ming Yang on 7/7/12.
//

#import <UIKit/UIKit.h>
#import "FXBlurView.h"
#pragma mark ControlPointView interface

@interface ControlPointView : UIView {
    CGFloat red, green, blue, alpha;
}

@property (nonatomic, retain) UIColor* color;

@end


#pragma mark ShadeView interface

@interface ShadeView : UIView {
    CGFloat cropBorderRed, cropBorderGreen, cropBorderBlue, cropBorderAlpha;
    CGRect cropArea1;
    CGRect cropArea2;
    CGFloat shadeAlpha;
}

@property (nonatomic, retain) UIColor* cropBorderColor;
@property (nonatomic) CGRect cropArea1;
@property (nonatomic) CGRect cropArea2;
@property (nonatomic) CGFloat shadeAlpha;
@property (nonatomic, strong) UIImageView *blurredImageView;

@end

CGRect SquareCGRectAtCenter(CGFloat centerX, CGFloat centerY, CGFloat size);

UIView* dragView;
typedef struct {
    
    CGPoint dragStart;
    CGPoint topLeftCenter;
    CGPoint bottomLeftCenter;
    CGPoint bottomRightCenter;
    CGPoint topRightCenter;
    CGPoint cropAreaCenter;
} DragPoint;

// Used when working with multiple dragPoints
typedef struct {
    DragPoint mainPoint;
    DragPoint optionalPoint;
    NSUInteger lastCount;
} MultiDragPoint;

#pragma mark ImageCropView interface

@interface ImageCropView : UIView {
    UIImageView* imageView;
    CGRect imageFrameInView;
    CGFloat imageScale;
    
    CGFloat controlPointSize;
    ControlPointView* topLeftPoint1;
    ControlPointView* bottomLeftPoint1;
    ControlPointView* bottomRightPoint1;
    ControlPointView* topRightPoint1;
    ControlPointView* topLeftPoint2;
    ControlPointView* bottomLeftPoint2;
    ControlPointView* bottomRightPoint2;
    ControlPointView* topRightPoint2;
    NSArray *PointsArray;
    UIColor* controlColor;

    UIView* cropAreaView1;
    UIView* cropAreaView2;
    DragPoint dragPoint1;
    DragPoint dragPoint2;
    MultiDragPoint multiDragPoint;
    
    UIView* dragViewOne;
    // UIView* dragViewTwo;
}
- (id)initWithFrame:(CGRect)frame blurOn:(BOOL)blurOn;
- (void)setImage:(UIImage*)image;

@property (nonatomic) CGFloat controlPointSize;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic) CGRect cropAreaInView;
@property (nonatomic) CGRect cropAreaInImage;
@property (nonatomic, readonly) CGFloat imageScale;
@property (nonatomic) CGFloat maskAlpha;
@property (nonatomic, retain) UIColor* controlColor;
@property (nonatomic, strong) ShadeView* shadeView;
@property (nonatomic) BOOL blurred;

@end

#pragma mark ImageCropViewController interface
@protocol ImageCropViewControllerDelegate <NSObject>

- (void)ImageCropViewControllerSuccess:(UIViewController* )controller didFinishCroppingImage:(UIImage *)croppedImage;
- (void)ImageCropViewControllerDidCancel:(UIViewController *)controller;

@end

@interface ImageCropViewController : UIViewController  <UIActionSheetDelegate > {
    ImageCropView * cropView1;
    ImageCropView * cropView2;
    UIActionSheet * actionSheet;
}
@property (nonatomic, weak) id<ImageCropViewControllerDelegate> delegate;
@property (nonatomic) BOOL blurredBackground;
@property (nonatomic, retain) UIImage* image;
@property (nonatomic, retain) ImageCropView* cropView1;
@property (nonatomic, retain) ImageCropView* cropView2;
/**
 *  the crop area in the image
 */
@property (nonatomic) CGRect cropArea1;
@property (nonatomic) CGRect cropArea2;

- (id)initWithImage:(UIImage*)image;
- (IBAction)cancel:(id)sender;
- (IBAction)done:(id)sender;

@end

@interface UIImage (fixOrientation)

- (UIImage *)fixOrientation;

@end

