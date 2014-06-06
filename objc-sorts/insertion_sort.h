//
//  Jesse Squires
//  http://www.hexedbits.com
//
//  GitHub
//  https://github.com/jessesquires/objc-sorts
//
//  Copyright (c) Jesse Squires
//

#import "sort_utils.h"

#ifndef objc_sorts_insertion_sort_h
#define objc_sorts_insertion_sort_h

void insertion_sort(NSMutableArray *arr)
{
    for (NSUInteger i = 1; i < arr.count; i++) {
        NSUInteger j = i;
        NSNumber *target = [arr objectAtIndex:i];
        
        while (j > 0 && (target.integerValue < [[arr objectAtIndex:j - 1] integerValue])) {
            [arr replaceObjectAtIndex:j withObject:[arr objectAtIndex:j - 1]];
            j--;
        }
        [arr replaceObjectAtIndex:j withObject:target];
    }
}

void test_insertion_sort(NSMutableArray *arr)
{
    NSLog(@"Running insertion sort...");
    NSDate *start = [NSDate date];
    insertion_sort(arr);
    NSTimeInterval end = [start timeIntervalSinceNow] * -1;
    verfiySorted(arr);
    NSLog(@"Insertion sort finished in %lf sec\n\n", end);
}

#endif
