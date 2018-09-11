#ifndef API_COMMON
#define API_COMMON
#include <QString>
//#define TEST

typedef class TASK_INFO
{
    public:
    QString from_store;
    QString to_store;
    int priority;
    int strategy;
}TASK_INFO;

typedef class STATION_INFO
{
    public:
    int map_id;
    int pos_x;
    int pos_y;
    int map_readyid;
    int times;
}STATION_INFO;
extern  QMap<QString, STATION_INFO> mapping_table;

//返回码
typedef enum RET_CODE
{
    RET_OK = 0,
    RET_RECORD_ALREADY_EXIST = 1,
    RET_PRERECORD_NOT_FOUND = 2,
    RET_DB_ERROR = 3,
    RET_PARAMS_NUM_ERROR = 4,
    RET_PARAMS_ERROR = 5,
    RET_MSG_ERROR = 6,
    RET_NOT_AVAILABLE = 7
}RET_CODE;

//出入库类型
typedef enum STORE_TYPE
{
    IN_STOCK = 0,
    OUT_STOCK = 1
}STORE_TYPE;


enum
{
    EMPTY = 0,
    RAW = 1,
    PACK = 2,
    TRAY = 3,
    TRASH = 4,
    PRODUCT = 5,
    FORKLIFT = 6
};
#define STR(ret) QString::number(ret)
#endif // API_COMMON

