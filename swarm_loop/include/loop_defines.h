#pragma once

#define LOOP_BOW_THRES 0.015
#define MATCH_INDEX_DIST 5
// #define MATCH_INDEX_DIST 1
#define FAST_THRES (20.0f)
#define ORB_FEATURE_SIZE (32) // For ORB
#define LOOP_FEATURE_NUM (200)
// #define USE_CUDA

// #define MIN_MOVEMENT_KEYFRAME 0.1
#define MIN_MOVEMENT_KEYFRAME 0.4
#define MIN_KEYFEATURES 10

#define LOOP_IMAGE_DOWNSAMPLE 2
#define JPG_QUALITY 50

#define MIN_LOOP_NUM 25

#define ACCEPT_LOOP_YAW (30)
#define MAX_LOOP_DIS 20

#define DEG2RAD (0.01745277777777778)

#define ACCEPT_LOOP_YAW_RAD ACCEPT_LOOP_YAW*DEG2RAD