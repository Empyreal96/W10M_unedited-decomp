// sub_81C940 
 
void __fastcall sub_81C940(int a1, int a2, int a3, int a4, int a5, int a6, BOOL a7, int a8, BOOL *a9, int a10, int a11, int a12)
{
  int v12; // r4
  int v13; // r5
  int v14; // r6

  a7 = v12 == 0;
  a9 = &a7;
  a10 = 0;
  a11 = 4;
  a12 = 0;
  EtwWrite(v14, v13, (int)POP_ETW_EVENT_ACDC_STATE_CHANGE, 0);
  JUMPOUT(0x7BCE64);
}
