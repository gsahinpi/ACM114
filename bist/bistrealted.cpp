#include "bistrelated.h"
#include  "colors.h"
std::string TMessageTypeToString(TMessageType messageType)
{
   switch (messageType)
   {
      case MSG_NEW_ORDER:
         return "New order message";
      case MSG_REPLACE_ORDER:
         return "Replace order message";
      case MSG_CANCEL_ORDER:
         return "Cancel order message";
      case MSG_NEW_LEG_ORDER:
         return "New multi-leg order";
      case MSG_CANCEL_LEG_ORDER:
         return "Cancel multi-leg order";
      case MSG_MASS_CANCEL:
         return "Mass quote cancel";
      case MSG_SPREAD_ORDER:
         return "Spread order";
      case MSG_2_LEG_ORDER:
         return "New order with 2 legs";
      case MSG_3_LEG_ORDER:
         return "New order with 3 legs";
      case MSG_RESET_RISK:
         return "Risk reset request";
      default:
         return "Unknown message type";
   }
};

std::string TOrderSideToString(TOrderSide orderSide)
{
   switch (orderSide)
   {
      case SIDE_UNSET:
         return "Not set";
      case SIDE_BUY:
         return "Buy";
      case SIDE_SELL:
         return "Sell";
      case SIDE_SELL_SHORT:
         return "Sell short";
      case SIDE_SELL_SHORTEX:
         return "Sell Short Exempt (SSR 201)";
      case SIDE_SELL_SHORTCCL:
         return "Sell Short and Cancel (When SSR 201 is in effect)";
      case SIDE_CROSS:
         return "Cross";
      case SIDE_CROSS_SHORT:
         return "Cross Short";
      default:
         return "Unknown";
   }
};
std::string TOrderItemStatusToString(TOrderItemStatus status) {
   switch (status) {
      case STATUSNOTSENT:
         return "STATUSNOTSENT";
      case STATUSSENT:
         return "STATUSSENT";
      case STATUSACCEPTED:
         return "STATUSACCEPTED";
      case STATUSREJECTED:
         return "STATUSREJECTED";
      case TOBECANCELED:
         return "TOBECANCELED";
      case TOBEREPLACED:
         return "TOBEREPLACED";
      case STATUSEXECUTEDPARTIAL:
         return "STATUSEXECUTEDPARTIAL";
      case STATUSEXECUTEDFULL:
         return "STATUSEXECUTEDFULL";
      default:
         return "Unknown";
   }
};

std::string INFOCHANVALIDSTATESToString(INFOCHANVALIDSTATES state)
{
   switch (state)
   {
      case INFOCHANVALIDMACHINE_start:
         return "INFOCHANVALIDMACHINE_start";
      case ITCH_TRIGbyHEDGE:
         return "ITCH_TRIGbyHEDGE";
      case OUCH_TRIGbyQOUTE:
         return "OUCH_TRIGbyQOUTE";
      case ITCH_TRIGbyQOUTE:
         return "ITCH_TRIGbyQOUTE";
      case OUCH_TRIGbyHEDGE:
         return "OUCH_TRIGbyHEDGE";
      case INFOCHANVALIDMACHINE_stop:
         return "INFOCHANVALIDMACHINE_stop";
      default:
         return "Unknown state";
   }
};
std::string TOrderItemToString(const TOrderItem& orderItem) {
   std::string result = "id: " + std::to_string(orderItem.orderId) + ", ";
   result += "price: " + std::to_string(orderItem.price) + ", ";
  // result += "threshold: " + std::to_string(orderItem.threshold) + "\n";
   result += "size: " + std::to_string(orderItem.size) + ",";
  // result += "priceseeninMarket: " + std::to_string(orderItem.priceseeninMarket) + "\n";
   result += "executed_qty: " + std::to_string(orderItem.executed_qty) + ", ";
   result += "side: " + std::to_string(orderItem.side) + ", ";
   result += "status: " + TOrderItemStatusToString(orderItem.status) + ", ";
   result += "order_Message_type: " + TMessageTypeToString(orderItem.order_Message_type) + ", ";
   result += "user_tag: " + std::to_string(orderItem.user_tag) + "\n";
   return result;
}


