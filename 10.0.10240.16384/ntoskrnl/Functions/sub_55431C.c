// sub_55431C 
 
void __fastcall sub_55431C(int a1, int a2, int a3, int a4, int a5, int a6, char a7, char a8, char a9, int a10, char *a11, int a12, int a13, int a14, char *a15, int a16, int a17, int a18, char *a19, int a20, int a21, int a22)
{
  int v22; // r4
  int v23; // r9

  a11 = &a8;
  a12 = 0;
  a13 = 4;
  a14 = 0;
  a15 = &a7;
  a16 = 0;
  a17 = 4;
  a18 = 0;
  a19 = &a9;
  a20 = 0;
  a21 = 8;
  a22 = 0;
  EtwWrite(v22, v23, (int)POP_ETW_EVENT_COMPONENT_RESIDENCY, 0);
  JUMPOUT(0x4F5274);
}
