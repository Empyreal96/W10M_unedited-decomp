// sub_81B4FC 
 
void __fastcall sub_81B4FC(int a1, int a2, int a3, int a4, int a5, int a6, __int16 a7, int a8, __int16 *a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16)
{
  int v16; // r5
  int v17; // r6
  int v18; // r7
  int v19; // r4
  int v20; // r3

  if ( EtwEventEnabled(v17, v18, (int)KMPnPEvt_DriverDatabaseUnload_Start) )
  {
    v19 = *(unsigned __int16 *)(v16 + 8);
    a7 = *(_WORD *)(v16 + 8) >> 1;
    a9 = &a7;
    a10 = 0;
    a11 = 2;
    a12 = 0;
    v20 = *(_DWORD *)(v16 + 12);
    a15 = v19;
    a13 = v20;
    a14 = 0;
    a16 = 0;
    EtwWrite(v17, v18, (int)KMPnPEvt_DriverDatabaseUnload_Start, 0);
  }
  JUMPOUT(0x7B9F1E);
}
