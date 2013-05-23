

#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>
@class GraphView;
@class AccelerometerFilter;

@interface MainViewController : UIViewController<UIAccelerometerDelegate>
{
	GraphView *unfiltered;
	GraphView *filtered;
	UIBarButtonItem *pause;
	UILabel *filterLabel;
	AccelerometerFilter *filter;
	BOOL isPaused, useAdaptive;
    CMMotionManager *motionManager;
}

@property(nonatomic, retain) IBOutlet GraphView *unfiltered;
@property(nonatomic, retain) IBOutlet GraphView *filtered;
@property(nonatomic, retain) IBOutlet UIBarButtonItem *pause;
@property(nonatomic, retain) IBOutlet UILabel *filterLabel;
@property (strong, nonatomic)  CMMotionManager *motionManager;
-(IBAction)pauseOrResume:(id)sender;
-(IBAction)filterSelect:(id)sender;
-(IBAction)adaptiveSelect:(id)sender;

@end