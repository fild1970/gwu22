#ifndef LIBPAS_GPIO_PINOUT_H
#define LIBPAS_GPIO_PINOUT_H

//e.g. Orange Pi Zero
#ifdef PINOUT1
#define PIN_NUM  27
char *physToGpio[PIN_NUM] = {
    "-", // 0
    "-", "-", // 1, 2
    "PA12", "-", // 3, 4
    "PA11", "-", // 5, 6
    "PA6", "PG6", // 7, 8
    "-", "PG7", // 9, 10
    "PA1", "PA7", //11, 12
    "PA0", "-", //13, 14
    "PA3", "PA19", //15, 16
    "-", "PA18", //17, 18
    "PA15", "-", //19, 20
    "PA16", "PA2", //21, 22
    "PA14", "PA13", //23, 24
    "-", "PA10" //25, 26
};
#else
#ifdef PINOUT2
#define PIN_NUM  1
char *physToGpio[PIN_NUM] = {
"-"
};
#else
//orange pi
#ifdef PINOUT3
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", // 0
    "-", "-", // 1, 2
    "PA12", "-", // 3, 4
    "PA11", "-", // 5, 6
    "PA6", "PA13", // 7, 8
    "-", "PA14", // 9, 10
    "PA1", "PD14", //11, 12
    "PA0", "-", //13, 14
    "PA3", "PC4", //15, 16
    "-", "PC7", //17, 18
    "PC0", "-", //19, 20
    "PC1", "PA2", //21, 22
    "PC2", "PC3", //23, 24
    "-", "PA21", //25, 26

    "PA19", "PA18", //27, 28
    "PA7", "-", //29, 30
    "PA8", "PG8", //31, 32
    "PA9", "-", //33, 34
    "PA10", "PG9", //35, 36
    "PA20", "PG6", //37, 38
    "-", "PG7" //39, 40
};
#else
//banana pi m1, banana pi m1+
#ifdef PINOUT4
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", //0
    "-", "-", //1, 2
    "PB21", "-", //3, 4
    "PB20", "-", //5, 6
    "PI3", "PH0", //7, 8
    "-", "PH1", //9, 10
    "PI19", "PH2", //11, 12
    "PI18", "-", //13, 14
    "PI17", "PH20", //15, 16
    "-", "PH21", //17, 18
    "PI12", "-", //19, 20
    "PI13", "PI16", //21, 22
    "PI11", "PI10", //23, 24
    "-", "PI14", //25, 26
    "PI1", "PI0", //27, 28
    "PB5", "-", //29, 30
    "PB6", "PB12", //31, 32      
    "PB7", "-", //33, 34
    "PB8", "PI21", //35, 36
    "PB3", "PI20", //37, 38
    "-", "PB13" //39, 40
};
#else
//banana pi m2
#ifdef PINOUT5
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", //0
    "-", "-", //1, 2
    "PH19", "-", //3, 4
    "PH18", "-", //5, 6
    "PH9", "PE4", //7, 8
    "-", "PE5", //9, 10
    "PG7", "PH10", //11, 12
    "PG6", "-", //13, 14
    "PG9", "PH11", //15, 16
    "-", "PH12", //17, 18
    "PG15", "-", //19, 20
    "PG16", "PG8", //21, 22
    "PG14", "PG13", //23, 24
    "-", "PG12", //25, 26
    "PB6", "PB5", //27, 28
    "PB0", "-", //29, 30
    "PB1", "PB7", //31, 32      
    "PB2", "-", //33, 34
    "PB3", "PE6", //35, 36
    "PB4", "PE7", //37, 38
    "-", "PM2" //39, 40
};
#else
//banana pi m2m V1.2 20171023
#ifdef PINOUT6
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", // 0
    "-", "-", // 1, 2
    "PH5", "-", // 3, 4
    "PH4", "-", // 5, 6
    "PH1", "PB0", // 7, 8
    "-", "PB1", // 9, 10
    "PH6", "PG11", //11, 12
    "PH7", "-", //13, 14
    "PD21", "PB2", //15, 16
    "-", "PB3", //17, 18
    "PC0", "-", //19, 20
    "PC1", "PD20", //21, 22
    "PC2", "PC3", //23, 24
    "-", "PD25", //25, 26

    "PD19", "PD24", //27, 28
    "PD18", "-", //29, 30
    "PD23", "PD22", //31, 32
    "PD27", "-", //33, 34
    "PG10", "PD26", //35, 36
    "PL11", "PG13", //37, 38
    "-", "PG12" //39, 40
};
#else
//banana pi m2m V1.1
#ifdef PINOUT7
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", // 0
    "-", "-", // 1, 2
    "PH5", "-", // 3, 4
    "PH4", "-", // 5, 6
    "PH1", "PB0", // 7, 8
    "-", "PB1", // 9, 10
    "PH6", "PB3", //11, 12
    "PH7", "-", //13, 14
    "PG12", "PB2", //15, 16
    "-", "PG11", //17, 18
    "PC0", "-", //19, 20
    "PC1", "PG10", //21, 22
    "PC2", "PC3", //23, 24
    "-", "PG13", //25, 26

    "PD19", "PL11", //27, 28
    "PD18", "-", //29, 30
    "PD21", "PD23", //31, 32
    "PD20", "-", //33, 34
    "PD25", "PD22", //35, 36
    "PD24", "PD27", //37, 38
    "-", "PD26" //39, 40
};
#else
//banana pi m2+
#ifdef PINOUT8
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", // 0
    "-", "-", // 1, 2
    "PA12", "-", // 3, 4
    "PA11", "-", // 5, 6
    "PA6", "PA13", // 7, 8
    "-", "PA14", // 9, 10
    "PA1", "PA16", //11, 12
    "PA0", "-", //13, 14
    "PA3", "PA15", //15, 16
    "-", "PC4", //17, 18
    "PC0", "-", //19, 20
    "PC1", "PA2", //21, 22
    "PC2", "PC3", //23, 24
    "-", "PC7", //25, 26

    "PA19", "PL2", //27, 28
    "PA7", "-", //29, 30
    "PA8", "PG8", //31, 32
    "PA9", "-", //33, 34
    "PA10", "PL4", //35, 36
    "PA17", "PA21", //37, 38
    "-", "PA20" //39, 40
};
#else
//banana pi m2u
#ifdef PINOUT9
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", // 0
    "-", "-", // 1, 2
    "PB21", "-", // 3, 4
    "PB20", "-", // 5, 6
    "PB3", "PI18", // 7, 8
    "-", "PI19", // 9, 10
    "PI20", "PI17", //11, 12
    "PI21", "-", //13, 14
    "PH25", "PI16", //15, 16
    "-", "PH26", //17, 18
    "PC0", "-", //19, 20
    "PC1", "PH27", //21, 22
    "PC2", "PC23", //23, 24
    "-", "PH24", //25, 26

    "PI1", "PI0", //27, 28
    "PH0", "-", //29, 30
    "PH1", "PD20", //31, 32
    "PH2", "-", //33, 34
    "PH3", "PH7", //35, 36
    "PH4", "PH6", //37, 38
    "-", "PH5" //39, 40
};
#else
//banana pi m3
#ifdef PINOUT10
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", //0
    "-", "-", //1, 2
    "PH05", "-", //3, 4
    "PH04", "-", //5, 6
    "PL10", "PB00", //7, 8
    "-", "PB01", //9, 10
    "PC04", "PB03", //11, 12
    "PC07", "-", //13, 14
    "PC17", "PB02", //15, 16
    "-", "PL08", //17, 18
    "PC00", "-", //19, 20
    "PC01", "PL09", //21, 22
    "PC02", "PC03", //23, 24
    "-", "PH10", //25, 26
    "PH03", "PH02", //27, 28
    "PC18", "-", //29, 30
    "PG10", "PG13", //31, 32      
    "PG11", "-", //33, 34
    "PG12", "PE05", //35, 36
    "PE04", "PE18", //37, 38
    "-", "PE19", //39, 40
};
#else
//banana pi m64
#ifdef PINOUT11
#define PIN_NUM  41
char *physToGpio[PIN_NUM] = {
    "-", //0
    "-", "-", //1, 2
    "PH03", "-", //3, 4
    "PH02", "-", //5, 6
    "PH06", "PB00", //7, 8
    "-", "PB01", //9, 10
    "PH07", "PB03", //11, 12
    "PH10", "-", //13, 14
    "PH11", "PB02", //15, 16
    "-", "PD04", //17, 18
    "PD02", "-", //19, 20
    "PD03", "PC00", //21, 22
    "PD01", "PD00", //23, 24
    "-", "PC02", //25, 26
    "PC04", "PC03", //27, 28
    "PC07", "-", //29, 30
    "PB05", "PB07", //31, 32      
    "PB04", "-", //33, 34
    "PB06", "PL09", //35, 36
    "PL12", "PL07", //37, 38
    "-", "PL08", //39, 40
};

#else
#define PIN_NUM  1
char *physToGpio[PIN_NUM] = {"-"};
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif


#endif

