#ifndef ELEMENTDEF
  #define ELEMENTDEF
      typedef struct
      {
        int id;
        char desc[2048];
        char type;
        int avaible;
        float cost;
      } Element;
      typedef enum { false, true } boolean;
  #endif