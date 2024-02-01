#ifndef BISTRELATED_H
#define BISTRELATED_H

#include <stdint.h>
#include <string.h>
#include <iostream>
using namespace std;

typedef int64_t TPrice;
typedef uint32_t TSize; // Quantity
static uint8_t mapID = 1;

#define HEDGE_SYMBOLS_COUNT 64
#define QUOTE_SYMBOLS_COUNT 64
#define QOUTEORDERS 8
#define QOUTEBIDORDERS 4
#define QOUTEASKORDERS 4
#define HEDGEORDERS 16
#define HEDGEBIDORDERS 8
#define HEDGEASKORDERS 8
//ugly
#define BIST_OUCH_Order_Accepted 65 // 65
#define BIST_OUCH_Order_Rejected 74 // 74
#define BIST_OUCH_Order_Replaced 85 // 85
#define BIST_OUCH_Order_Canceled 67 // 67
#define BIST_OUCH_Order_Executed 69 // 69
//ugly

enum ITCH_TRIGbyHEDGESTATES
{
   HEDGE_START,
   HDbPOSITIVE,
   HDbNEGATIVE,
   HDaPOSITIVE,
   HDaNEGATIVE,
   HEDGE_DONE
};
typedef struct tob
{
   int64_t ask;          // Ask price
   int64_t bid;          // Bid price
   uint64_t ask_size;    // Ask quantity
   uint64_t bid_size;    // Bid quantity
   uint32_t ask_cussize; // Ask customer quantity (used only for specific protocols)
   uint32_t bid_cussize; // Bid customer quantity (used only for specific protocols)
   uint32_t ask_prosize; // Ask professional quantity (used only for specific protocols)
   uint32_t bid_prosize; // Bid professional quantity (used only for specific protocols)
   uint64_t ask_lvl_ts;  // Ask book level timestamp
   uint64_t bid_lvl_ts;  // Bid book level timestamp
   bool ask_empty;       // Ask book level empty
   bool bid_empty;       // Bid book level empty
   bool ask_valid;       // Ask book level valid
   bool bid_valid;       // Bid book level valid
} TToB;

enum TMessageType
{
   MSG_NEW_ORDER = 0x00,        // New order message
   MSG_REPLACE_ORDER = 0x01,    // Replace order message
   MSG_CANCEL_ORDER = 0x02,     // Cancel order message
   MSG_NEW_LEG_ORDER = 0x03,    // New multi-leg order
   MSG_CANCEL_LEG_ORDER = 0x04, // Cancel multi-leg order
   MSG_MASS_CANCEL = 0x05,      // Mass quote cancel
   MSG_SPREAD_ORDER = 0x06,     // Spread order
   MSG_2_LEG_ORDER = 0x07,      // New order with 2 legs
   MSG_3_LEG_ORDER = 0x08,      // New order with 3 legs
   MSG_RESET_RISK = 0x09,       // Risk reset request

};
// orderenums.h
std::string TMessageTypeToString(TMessageType messageType);

enum TOrderSide
{
   SIDE_UNSET = 0x00,         //!< Not set
   SIDE_BUY = 0x01,           //!< Buy
   SIDE_SELL = 0x02,          //!< Sell
   SIDE_SELL_SHORT = 0x03,    //!< Sell short
   SIDE_SELL_SHORTEX = 0x04,  //!< Sell Short Exempt (SSR 201)
   SIDE_SELL_SHORTCCL = 0x05, //!< Sell Short and Cancel (When SSR 201 is in effect)
   SIDE_CROSS = 0x06,         //!< Cross
   SIDE_CROSS_SHORT = 0x07    //!< Cross Short
};
std::string TOrderSideToString(TOrderSide orderSide);




enum TOrderItemStatus
{
   STATUSNOTSENT = 19,
   STATUSSENT,
   STATUSACCEPTED,
   STATUSREJECTED,
   TOBECANCELED,
   TOBEREPLACED,
   STATUSEXECUTEDPARTIAL,
   STATUSEXECUTEDFULL // should not be set
};
std::string TOrderItemStatusToString(TOrderItemStatus status);
enum INFOCHANVALIDSTATES
{
   INFOCHANVALIDMACHINE_start,
   ITCH_TRIGbyHEDGE, // db,da quoteask quotebid access

   OUCH_TRIGbyQOUTE, // quoteask quotebid access
   ITCH_TRIGbyQOUTE,

   OUCH_TRIGbyHEDGE,
   INFOCHANVALIDMACHINE_stop

}; //
std::string INFOCHANVALIDSTATESToString(INFOCHANVALIDSTATES state);

struct TOrderItem
{
   // Zero orderId = invalid order
   uint64_t orderId; // orderId;
   TPrice price;
   TPrice threshold; // Needed for the hedge orders
   uint64_t size;
   TPrice priceseeninMarket;/// only for debug not present in fpga
   int32_t executed_qty;    // To be taken into account in replacement qty
   uint8_t side;            // see order_enums.h line 93
   TOrderItemStatus status; //  0 not acked 1 , 19 set but not send
   TMessageType order_Message_type;
   uint8_t user_tag;

   void copy(const TOrderItem &in)
   {
#pragma HLS inline
      // orderId       = in. orderId;
      orderId = in.orderId;
      price = in.price;
      priceseeninMarket = in.priceseeninMarket;// for debug non existent in fpga
      size = in.size;
      side = in.side;
      status = in.status;
      threshold = in.threshold;
      executed_qty = in.executed_qty;
      order_Message_type = in.order_Message_type;
      user_tag = in.user_tag;
   }
};

std::string TOrderItemToString(const TOrderItem& orderItem) ;
#endif // BISTRELATED_H
