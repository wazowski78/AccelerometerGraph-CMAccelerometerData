
#import <UIKit/UIKit.h>
#import <CoreMotion/CoreMotion.h>

// Basic filter object. 
@interface AccelerometerFilter : NSObject
{
	BOOL adaptive;
	UIAccelerationValue x, y, z;
    CMAcceleration acel2;
    
}

// Add a UIAcceleration to the filter.
-(void)addAcceleration:(UIAcceleration*)accel;
// Add a CMAccelerometerData to the filter.
-(void)addAccelerationFilterCM:(CMAccelerometerData*)accel;
@property(nonatomic, readonly) UIAccelerationValue x;
@property(nonatomic, readonly) UIAccelerationValue y;
@property(nonatomic, readonly) UIAccelerationValue z;

@property(nonatomic, readonly) CMAcceleration acel2;

@property(nonatomic, getter=isAdaptive) BOOL adaptive;
@property(nonatomic, readonly) NSString *name;

@end

// A filter class to represent a lowpass filter
@interface LowpassFilter : AccelerometerFilter
{
	double filterConstant;
	UIAccelerationValue lastX, lastY, lastZ;
}

-(id)initWithSampleRate:(double)rate cutoffFrequency:(double)freq;

@end

// A filter class to represent a highpass filter.
@interface HighpassFilter : AccelerometerFilter
{
	double filterConstant;
	UIAccelerationValue lastX, lastY, lastZ;
}

-(id)initWithSampleRate:(double)rate cutoffFrequency:(double)freq;

@end