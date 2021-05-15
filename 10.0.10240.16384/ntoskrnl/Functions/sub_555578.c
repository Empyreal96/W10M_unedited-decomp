// sub_555578 
 
void __fastcall sub_555578(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, char a8, __int16 *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, char *a17, int a18, int a19, int a20)
{
  int v20; // r5
  int v21; // r6
  int v22; // r7
  int v23; // r4
  int v24; // r3

  v23 = *(unsigned __int16 *)(v20 + 8);
  a7 = *(_WORD *)(v20 + 8) >> 1;
  a9 = &a7;
  a10 = 0;
  a11 = 2;
  a12 = 0;
  v24 = *(_DWORD *)(v20 + 12);
  a15 = v23;
  a13 = v24;
  a14 = 0;
  a16 = 0;
  a17 = &a8;
  a18 = 0;
  a19 = 4;
  a20 = 0;
  EtwWrite(v21, v22, (int)KMPnPEvt_DriverDatabaseUnload_Stop, 0);
  JUMPOUT(0x4F7F04);
}
