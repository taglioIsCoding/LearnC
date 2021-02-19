#ifndef ELEMENTDEF
  #define ELEMENTDEF
      typedef struct
      {
        int id;
        char surname[2048];
        char name[2048];
        float amount;
      } Element;
      typedef enum { false, true } boolean;
  #endif