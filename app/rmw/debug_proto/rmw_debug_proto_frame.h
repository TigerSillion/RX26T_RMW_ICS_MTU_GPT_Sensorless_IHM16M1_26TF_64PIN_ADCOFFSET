#ifndef RMW_DEBUG_PROTO_FRAME_H
#define RMW_DEBUG_PROTO_FRAME_H

#include <stdint.h>
#include <stddef.h>

#define RMW_DEBUG_PROTO_SOF0            (0x55u)
#define RMW_DEBUG_PROTO_SOF1            (0xAAu)
#define RMW_DEBUG_PROTO_VERSION_V1      (0x01u)
#define RMW_DEBUG_PROTO_MAX_PAYLOAD     (128u)

typedef enum e_rmw_debug_proto_err
{
    RMW_DEBUG_PROTO_ERR_OK             = 0x00u,
    RMW_DEBUG_PROTO_ERR_BAD_CMD        = 0x01u,
    RMW_DEBUG_PROTO_ERR_BAD_LENGTH     = 0x02u,
    RMW_DEBUG_PROTO_ERR_BAD_CRC        = 0x03u,
    RMW_DEBUG_PROTO_ERR_BAD_VAR        = 0x04u,
    RMW_DEBUG_PROTO_ERR_RO_VAR         = 0x05u,
    RMW_DEBUG_PROTO_ERR_INTERNAL       = 0x7Fu
} rmw_debug_proto_err_t;

typedef struct st_rmw_debug_proto_frame
{
    uint8_t  u1_version;
    uint8_t  u1_seq;
    uint8_t  u1_cmd;
    uint8_t  u1_err;
    uint16_t u2_payload_length;
    uint8_t  au1_payload[RMW_DEBUG_PROTO_MAX_PAYLOAD];
} rmw_debug_proto_frame_t;

typedef void (*rmw_debug_proto_frame_handler_t)(const rmw_debug_proto_frame_t *p_st_frame);

void rmw_debug_proto_frame_init(rmw_debug_proto_frame_handler_t pfn_handler);
void rmw_debug_proto_frame_reset(void);
void rmw_debug_proto_frame_feed_byte(uint8_t u1_byte);
uint16_t rmw_debug_proto_frame_crc16(const uint8_t *p_u1_data, uint16_t u2_size);
uint16_t rmw_debug_proto_frame_encode(const rmw_debug_proto_frame_t *p_st_frame, uint8_t *p_u1_buffer, uint16_t u2_buffer_size);

#endif
