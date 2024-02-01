 #include "stratglobals.h"
 #include "bistrelated.h"

 #define GREEN "\033[32m"
#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"
#define YELLOW "\033[33m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define printborder cout <<BOLDRED << "\t------------------------------------------" << RESET << endl;
static TPrice prospectBidPrice[QOUTEBIDORDERS] = {0};
 static uint8_t firstfoundinprospectindex = 0xff;
  static uint8_t firstNOTfoundinprospectindex = 0xff;
  static uint8_t lastNOTfoundinprospectindex = 0xff;
static uint8_t lastfoundinprospectindex = 0xff;
static uint8_t foundInBidProspect[QOUTEBIDORDERS] = {0xff, 0xff, 0xff, 0xff};
static uint8_t prospectfoundInQuote[QOUTEBIDORDERS] = {0xff, 0xff, 0xff, 0xff};
static TOrderItem quoteBidorders[QOUTEBIDORDERS];
static TOrderItem allQuoteOrders[QOUTEORDERS];
static int32_t persymbolrw_params_tmp[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
static TOrderItem quoteOrdersMap[QUOTE_SYMBOLS_COUNT][QOUTEORDERS];
static TOrderItem hedgeOrdersMap[HEDGE_SYMBOLS_COUNT][HEDGEORDERS];
static TToB prevTob[5]={0};
static TToB currTob[5]={0};
 
 void ItchdAlgo(char ch);
 void initializeMAPS();
 TPrice getDeltaTick(TPrice prospectBidPrice) ;
 void loadbidmemorymap();
 void loadbmemoryBack();
 void processFoundlings();
 void   loadQordersfromMap();
  void   loadQordersToMap();

