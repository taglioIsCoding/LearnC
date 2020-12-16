#ifndef ELEMENTDEF
  #define ELEMENTDEF
      typedef struct
      {
        int id;
        char name[30];
        char type;
        int num;
        float rate;
      } Element;
      typedef enum { false, true } boolean;
  #endif