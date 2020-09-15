#pragma once
// MESSAGE NODE_DETECTED PACKING

#define MAVLINK_MSG_ID_NODE_DETECTED 203

MAVPACKED(
typedef struct __mavlink_node_detected_t {
 int32_t lps_time; /*< [ms] LPS_TIME*/
 int32_t target_id; /*<  Target ID of drone*/
 int16_t x; /*< [m] Relative X Position*10000*/
 int16_t y; /*< [m] Relative Y Position*10000*/
 int16_t z; /*< [m] Relative Z Position*10000*/
 int16_t prob; /*< [1] Relative Z Position*10000*/
 uint16_t inv_dep; /*< [1/m] inverse depth*10000;0 then unavailable*/
}) mavlink_node_detected_t;

#define MAVLINK_MSG_ID_NODE_DETECTED_LEN 18
#define MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN 18
#define MAVLINK_MSG_ID_203_LEN 18
#define MAVLINK_MSG_ID_203_MIN_LEN 18

#define MAVLINK_MSG_ID_NODE_DETECTED_CRC 75
#define MAVLINK_MSG_ID_203_CRC 75



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_NODE_DETECTED { \
    203, \
    "NODE_DETECTED", \
    7, \
    {  { "lps_time", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_node_detected_t, lps_time) }, \
         { "target_id", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_node_detected_t, target_id) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_node_detected_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_node_detected_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_node_detected_t, z) }, \
         { "prob", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_node_detected_t, prob) }, \
         { "inv_dep", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_node_detected_t, inv_dep) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_NODE_DETECTED { \
    "NODE_DETECTED", \
    7, \
    {  { "lps_time", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_node_detected_t, lps_time) }, \
         { "target_id", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_node_detected_t, target_id) }, \
         { "x", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_node_detected_t, x) }, \
         { "y", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_node_detected_t, y) }, \
         { "z", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_node_detected_t, z) }, \
         { "prob", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_node_detected_t, prob) }, \
         { "inv_dep", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_node_detected_t, inv_dep) }, \
         } \
}
#endif

/**
 * @brief Pack a node_detected message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param lps_time [ms] LPS_TIME
 * @param target_id  Target ID of drone
 * @param x [m] Relative X Position*10000
 * @param y [m] Relative Y Position*10000
 * @param z [m] Relative Z Position*10000
 * @param prob [1] Relative Z Position*10000
 * @param inv_dep [1/m] inverse depth*10000;0 then unavailable
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_node_detected_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t lps_time, int32_t target_id, int16_t x, int16_t y, int16_t z, int16_t prob, uint16_t inv_dep)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NODE_DETECTED_LEN];
    _mav_put_int32_t(buf, 0, lps_time);
    _mav_put_int32_t(buf, 4, target_id);
    _mav_put_int16_t(buf, 8, x);
    _mav_put_int16_t(buf, 10, y);
    _mav_put_int16_t(buf, 12, z);
    _mav_put_int16_t(buf, 14, prob);
    _mav_put_uint16_t(buf, 16, inv_dep);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NODE_DETECTED_LEN);
#else
    mavlink_node_detected_t packet;
    packet.lps_time = lps_time;
    packet.target_id = target_id;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.prob = prob;
    packet.inv_dep = inv_dep;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NODE_DETECTED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NODE_DETECTED;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
}

/**
 * @brief Pack a node_detected message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param lps_time [ms] LPS_TIME
 * @param target_id  Target ID of drone
 * @param x [m] Relative X Position*10000
 * @param y [m] Relative Y Position*10000
 * @param z [m] Relative Z Position*10000
 * @param prob [1] Relative Z Position*10000
 * @param inv_dep [1/m] inverse depth*10000;0 then unavailable
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_node_detected_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t lps_time,int32_t target_id,int16_t x,int16_t y,int16_t z,int16_t prob,uint16_t inv_dep)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NODE_DETECTED_LEN];
    _mav_put_int32_t(buf, 0, lps_time);
    _mav_put_int32_t(buf, 4, target_id);
    _mav_put_int16_t(buf, 8, x);
    _mav_put_int16_t(buf, 10, y);
    _mav_put_int16_t(buf, 12, z);
    _mav_put_int16_t(buf, 14, prob);
    _mav_put_uint16_t(buf, 16, inv_dep);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_NODE_DETECTED_LEN);
#else
    mavlink_node_detected_t packet;
    packet.lps_time = lps_time;
    packet.target_id = target_id;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.prob = prob;
    packet.inv_dep = inv_dep;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_NODE_DETECTED_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_NODE_DETECTED;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
}

/**
 * @brief Encode a node_detected struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param node_detected C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_node_detected_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_node_detected_t* node_detected)
{
    return mavlink_msg_node_detected_pack(system_id, component_id, msg, node_detected->lps_time, node_detected->target_id, node_detected->x, node_detected->y, node_detected->z, node_detected->prob, node_detected->inv_dep);
}

/**
 * @brief Encode a node_detected struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param node_detected C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_node_detected_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_node_detected_t* node_detected)
{
    return mavlink_msg_node_detected_pack_chan(system_id, component_id, chan, msg, node_detected->lps_time, node_detected->target_id, node_detected->x, node_detected->y, node_detected->z, node_detected->prob, node_detected->inv_dep);
}

/**
 * @brief Send a node_detected message
 * @param chan MAVLink channel to send the message
 *
 * @param lps_time [ms] LPS_TIME
 * @param target_id  Target ID of drone
 * @param x [m] Relative X Position*10000
 * @param y [m] Relative Y Position*10000
 * @param z [m] Relative Z Position*10000
 * @param prob [1] Relative Z Position*10000
 * @param inv_dep [1/m] inverse depth*10000;0 then unavailable
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_node_detected_send(mavlink_channel_t chan, int32_t lps_time, int32_t target_id, int16_t x, int16_t y, int16_t z, int16_t prob, uint16_t inv_dep)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_NODE_DETECTED_LEN];
    _mav_put_int32_t(buf, 0, lps_time);
    _mav_put_int32_t(buf, 4, target_id);
    _mav_put_int16_t(buf, 8, x);
    _mav_put_int16_t(buf, 10, y);
    _mav_put_int16_t(buf, 12, z);
    _mav_put_int16_t(buf, 14, prob);
    _mav_put_uint16_t(buf, 16, inv_dep);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NODE_DETECTED, buf, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
#else
    mavlink_node_detected_t packet;
    packet.lps_time = lps_time;
    packet.target_id = target_id;
    packet.x = x;
    packet.y = y;
    packet.z = z;
    packet.prob = prob;
    packet.inv_dep = inv_dep;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NODE_DETECTED, (const char *)&packet, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
#endif
}

/**
 * @brief Send a node_detected message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_node_detected_send_struct(mavlink_channel_t chan, const mavlink_node_detected_t* node_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_node_detected_send(chan, node_detected->lps_time, node_detected->target_id, node_detected->x, node_detected->y, node_detected->z, node_detected->prob, node_detected->inv_dep);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NODE_DETECTED, (const char *)node_detected, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
#endif
}

#if MAVLINK_MSG_ID_NODE_DETECTED_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_node_detected_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t lps_time, int32_t target_id, int16_t x, int16_t y, int16_t z, int16_t prob, uint16_t inv_dep)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, lps_time);
    _mav_put_int32_t(buf, 4, target_id);
    _mav_put_int16_t(buf, 8, x);
    _mav_put_int16_t(buf, 10, y);
    _mav_put_int16_t(buf, 12, z);
    _mav_put_int16_t(buf, 14, prob);
    _mav_put_uint16_t(buf, 16, inv_dep);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NODE_DETECTED, buf, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
#else
    mavlink_node_detected_t *packet = (mavlink_node_detected_t *)msgbuf;
    packet->lps_time = lps_time;
    packet->target_id = target_id;
    packet->x = x;
    packet->y = y;
    packet->z = z;
    packet->prob = prob;
    packet->inv_dep = inv_dep;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_NODE_DETECTED, (const char *)packet, MAVLINK_MSG_ID_NODE_DETECTED_MIN_LEN, MAVLINK_MSG_ID_NODE_DETECTED_LEN, MAVLINK_MSG_ID_NODE_DETECTED_CRC);
#endif
}
#endif

#endif

// MESSAGE NODE_DETECTED UNPACKING


/**
 * @brief Get field lps_time from node_detected message
 *
 * @return [ms] LPS_TIME
 */
static inline int32_t mavlink_msg_node_detected_get_lps_time(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field target_id from node_detected message
 *
 * @return  Target ID of drone
 */
static inline int32_t mavlink_msg_node_detected_get_target_id(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field x from node_detected message
 *
 * @return [m] Relative X Position*10000
 */
static inline int16_t mavlink_msg_node_detected_get_x(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field y from node_detected message
 *
 * @return [m] Relative Y Position*10000
 */
static inline int16_t mavlink_msg_node_detected_get_y(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field z from node_detected message
 *
 * @return [m] Relative Z Position*10000
 */
static inline int16_t mavlink_msg_node_detected_get_z(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field prob from node_detected message
 *
 * @return [1] Relative Z Position*10000
 */
static inline int16_t mavlink_msg_node_detected_get_prob(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field inv_dep from node_detected message
 *
 * @return [1/m] inverse depth*10000;0 then unavailable
 */
static inline uint16_t mavlink_msg_node_detected_get_inv_dep(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Decode a node_detected message into a struct
 *
 * @param msg The message to decode
 * @param node_detected C-struct to decode the message contents into
 */
static inline void mavlink_msg_node_detected_decode(const mavlink_message_t* msg, mavlink_node_detected_t* node_detected)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    node_detected->lps_time = mavlink_msg_node_detected_get_lps_time(msg);
    node_detected->target_id = mavlink_msg_node_detected_get_target_id(msg);
    node_detected->x = mavlink_msg_node_detected_get_x(msg);
    node_detected->y = mavlink_msg_node_detected_get_y(msg);
    node_detected->z = mavlink_msg_node_detected_get_z(msg);
    node_detected->prob = mavlink_msg_node_detected_get_prob(msg);
    node_detected->inv_dep = mavlink_msg_node_detected_get_inv_dep(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_NODE_DETECTED_LEN? msg->len : MAVLINK_MSG_ID_NODE_DETECTED_LEN;
        memset(node_detected, 0, MAVLINK_MSG_ID_NODE_DETECTED_LEN);
    memcpy(node_detected, _MAV_PAYLOAD(msg), len);
#endif
}
