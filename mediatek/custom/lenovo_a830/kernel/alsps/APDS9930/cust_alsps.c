#include <linux/types.h>
#include <mach/mt_pm_ldo.h>
#include <cust_alsps.h>

static struct alsps_hw cust_alsps_hw = {
    .i2c_num    = 3,
	.polling_mode_ps =0,
	.polling_mode_als =1,
    .power_id   = MT65XX_POWER_NONE,    /*LDO is not used*/
    .power_vol  = VOL_DEFAULT,          /*LDO is not used*/
    .i2c_addr   = {0x72, 0x48, 0x78, 0x00},
    /*Lenovo-sw chenlj2 add 2011-06-03,modify parameter below two lines*/
    //.als_level  = { 4, 40,  80,   120,   160, 250,  400, 800, 1200,  1600, 2000, 3000, 5000, 10000, 65535},
    //.als_value  = {10, 20,20,  120, 120, 280,  280,  280, 1600,  1600,  1600,  6000,  6000, 9000,  10240, 10240},
    //.als_level  = { 5, 10,  25,   50,  100, 150,  200, 400, 1000,  1500, 2000, 3000, 5000, 8000, 10000},
    //.als_value  = {10, 50,  100,  150, 200, 250,  280,  280, 1600,  1600,  1600,  6000,  6000, 9000,  10240, 10240},
    /* MTK: modified to support AAL */
    //.als_level  = { 6, 	9, 	 17,  38,  56,   74,   116,  342,  778,  1082, 1386, 1914,  3000,  5000,  8000 },
    //.als_value  = {136, 218, 312, 730, 1065, 1400, 2250, 4286, 5745, 7390, 9034, 11000, 10240, 10240, 10240, 10240},
    /* LENOVO.SW begin chenyb1 2013.2.27 add new value */
    .als_level  = {2*100, 16*100, 42*100, 69*100, 124*100, 172*100, 302*100, 409*100, 500*100, 655*100, 863*100, 1056*100, 1312*100, 1824*100, 3235*100, 5211*100, 6144*100, 7840*100},
    .als_value  = {5*100, 30*100, 60*100, 90*100, 150*100, 200*100, 350*100,  450*100, 550*100, 720*100, 950*100, 1100*100, 1500*100, 2000*100, 3500*100, 5600*100, 6700*100, 8700*100},
    /* LENOVO.SW end chenyb1 2013.2.27 add new value */
    .ps_threshold_high = 310,
    .ps_threshold_low = 210,
    .ps_threshold = 900,
};
struct alsps_hw *get_cust_alsps_hw(void) {
    return &cust_alsps_hw;
}
int APDS9930_CMM_PPCOUNT_VALUE = 0x06;//0x06;
int APDS9930_CMM_CONTROL_VALUE = 0x68;//0xE4;
int ZOOM_TIME = 4;
