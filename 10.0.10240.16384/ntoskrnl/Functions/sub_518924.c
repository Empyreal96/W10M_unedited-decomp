// sub_518924 
 
void __fastcall sub_518924(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, __int16 *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r7
  int v17; // r8
  int v18; // r9
  int v19; // r4
  int v20; // r3

  v19 = *(unsigned __int16 *)(v18 + 20);
  a7 = *(_WORD *)(v18 + 20) >> 1;
  a9 = &a7;
  a10 = 0;
  a11 = 2;
  a12 = 0;
  v20 = *(_DWORD *)(v18 + 24);
  a15 = v19;
  a13 = v20;
  a14 = 0;
  a16 = 0;
  EtwWrite(v16, v17, (int)KMPnPEvt_DeviceEnum_Stop, 0);
  JUMPOUT(0x4D9340);
}
