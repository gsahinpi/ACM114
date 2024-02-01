 #include "stratglobals.h"
 #include "bistrelated.h"
 #include  "colors.h"


static TPrice prospectBidPrice[QOUTEBIDORDERS] = {0};
 static TPrice prospectAskPrice[QOUTEBIDORDERS]={0}; 
 static uint8_t firstfoundinprospectindex = 0xff;
  static uint8_t firstNOTfoundinprospectindex = 0xff;
  static uint8_t lastNOTfoundinprospectindex = 0xff;
static uint8_t lastfoundinprospectindex = 0xff;
static uint8_t foundInBidProspect[QOUTEBIDORDERS] = {0xff, 0xff, 0xff, 0xff};
static uint8_t foundInAskProspect[QOUTEASKORDERS] = {0xff, 0xff, 0xff, 0xff};
static uint8_t prospectfoundInQuote[QOUTEBIDORDERS] = {0xff, 0xff, 0xff, 0xff};
static uint8_t prospectfoundInQuoteAsk[QOUTEASKORDERS] = {0xff, 0xff, 0xff, 0xff};
static TOrderItem quoteBidorders[QOUTEBIDORDERS];
static TOrderItem quoteAskorders[QOUTEASKORDERS];
static TOrderItem allQuoteOrders[QOUTEORDERS];
static int32_t persymbolrw_params_tmp[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static TOrderItem quoteOrdersMap[QUOTE_SYMBOLS_COUNT][QOUTEORDERS];
static TOrderItem hedgeOrdersMap[HEDGE_SYMBOLS_COUNT][HEDGEORDERS];
static TToB prevTob[5]={0};
static TToB currTob[5]={0};
 
 void ItchdAlgo(char ch);
 void initializeMAPS();
 TPrice getDeltaTick(TPrice prospectBidPrice) ;
 TPrice getDeltaTickAsk(TPrice prospectAskPrice) ;  
 void loadbidmemorymap();
 void loadaskmemorymap();
 void loadbmemoryBack();
 void loadamemoryBack();
 void processFoundlings();
  void processAskFoundlings();
 bool isQuoteOrderAvailable (TOrderItem quoteOrder);
 void   loadQordersfromMap();
 void   loadQordersToMap();
 void orderMAchine();
 void orderMAchineAsk();
bool isqouteORDERable(TOrderItem quoteOrder);
void hedgeouch();
void acceptOrder( uint64_t quoteOrderid);
void executedOrder(uint64_t quoteOrderid, TSize executedsize);    
void rejectedOrder(uint64_t quoteOrderid);
void printqouteorders();
void printMAps();

void  calculateaskprospects(TPrice baseAskPrice);





