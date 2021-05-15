// sub_7F0E38 
 
void __fastcall sub_7F0E38(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, __int16 a13, int a14, int a15, int a16, int a17, int a18, __int16 *a19, int a20, int a21, int a22, int a23, int a24, int a25, int a26)
{
  int v26; // r5
  __int64 v27; // r6
  __int64 *v28; // r9
  int v29; // r4
  int v30; // r3
  int v31; // r1
  int v32; // r3

  if ( EtwEventEnabled(v27, SHIDWORD(v27), (int)KMPnPEvt_DriverDatabaseLoad_Start) )
  {
    v29 = *(unsigned __int16 *)(v26 + 8);
    a13 = *(_WORD *)(v26 + 8) >> 1;
    a19 = &a13;
    a20 = 0;
    a21 = 2;
    a22 = 0;
    v30 = *(_DWORD *)(v26 + 12);
    a25 = v29;
    a23 = v30;
    a24 = 0;
    a26 = 0;
    EtwWrite(v27, SHIDWORD(v27), (int)KMPnPEvt_DriverDatabaseLoad_Start, 0);
    v27 = *v28;
  }
  if ( v27 )
  {
    if ( EtwEventEnabled(v27, SHIDWORD(v27), (int)KMPnPEvt_DriverDatabaseLoaded_Start) )
    {
      v31 = *(unsigned __int16 *)(v26 + 8);
      a13 = *(_WORD *)(v26 + 8) >> 1;
      a19 = &a13;
      a20 = 0;
      a21 = 2;
      a22 = 0;
      v32 = *(_DWORD *)(v26 + 12);
      a25 = v31;
      a23 = v32;
      a24 = 0;
      a26 = 0;
      EtwWrite(v27, SHIDWORD(v27), (int)KMPnPEvt_DriverDatabaseLoaded_Start, 0);
    }
  }
  JUMPOUT(0x786842);
}
