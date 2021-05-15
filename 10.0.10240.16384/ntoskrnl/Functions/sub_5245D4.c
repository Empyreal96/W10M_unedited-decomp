// sub_5245D4 
 
void __fastcall sub_5245D4(int a1, int a2, int a3, int a4, int a5, int a6, char a7, int a8, char a9, int a10, char *a11, int a12, int a13, int a14, char *a15, int a16, int a17, int a18, int *a19, int a20, int a21, int a22)
{
  int v22; // r7
  int v23; // r8

  a11 = &a9;
  a12 = 0;
  a13 = 4;
  a14 = 0;
  a15 = &a7;
  a16 = 0;
  a17 = 4;
  a18 = 0;
  a19 = &a8;
  a20 = 0;
  a21 = 4;
  a22 = 0;
  EtwWrite(v23, v22, (int)POP_ETW_EVENT_COMPONENT_WAKE, 0);
  JUMPOUT(0x45CF5E);
}
