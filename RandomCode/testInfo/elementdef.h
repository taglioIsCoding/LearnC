#ifndef ELEMENTDEF
  #define ELEMENTDEF
      typedef struct
      {
        int id;
        char in[255];
        char out[255];
      } Element;
      typedef enum { false, true } boolean;
  #endif