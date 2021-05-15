// PnpTraceStartDevice 
 
int __fastcall PnpTraceStartDevice(int a1, int a2, int a3)
{
  unsigned int v4; // r2
  int v5; // r3
  __int64 v6; // r4
  __int16 v7; // [sp+8h] [bp-80h] BYREF
  __int16 v8; // [sp+Ah] [bp-7Eh] BYREF
  int v9; // [sp+Ch] [bp-7Ch] BYREF
  _DWORD v10[30]; // [sp+10h] [bp-78h] BYREF

  if ( a3 )
    return sub_528330(a1, a2, a3, 0);
  v4 = *(unsigned __int16 *)(a1 + 20);
  v9 = a2;
  v10[0] = 0;
  v7 = v4 >> 1;
  v10[2] = &v7;
  v10[3] = 0;
  v10[4] = 2;
  v10[5] = 0;
  v5 = *(_DWORD *)(a1 + 24);
  v10[8] = v4;
  v10[6] = v5;
  v10[7] = 0;
  v10[9] = 0;
  v10[10] = &v9;
  v10[11] = 0;
  v10[12] = 4;
  v10[13] = 0;
  v8 = 0;
  v10[14] = &v8;
  v10[15] = 0;
  v10[16] = 2;
  v10[17] = 0;
  v10[18] = 0;
  v10[19] = 0;
  v10[20] = 0;
  v10[21] = 0;
  v10[22] = v10;
  v10[23] = 0;
  v10[24] = 4;
  v10[25] = 0;
  v6 = PnpEtwHandle;
  if ( PnpEtwHandle )
  {
    if ( EtwEventEnabled(PnpEtwHandle, SHIDWORD(PnpEtwHandle), (int)KMPnPEvt_DeviceStart_Stop) )
      EtwWrite(v6, SHIDWORD(v6), (int)KMPnPEvt_DeviceStart_Stop, 0);
  }
  return 0;
}
