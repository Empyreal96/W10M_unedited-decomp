// SepRmDispatchDataToLsa 
 
int __fastcall SepRmDispatchDataToLsa(_DWORD *a1)
{
  int v2; // r0
  int v3; // r6
  unsigned int v4; // r2
  int v6; // r0
  int v7; // r3
  int v8; // r4
  int v9; // r0
  int v10; // [sp+8h] [bp-218h] BYREF
  __int16 v11; // [sp+10h] [bp-210h]
  int v12; // [sp+12h] [bp-20Eh]
  __int16 v13; // [sp+16h] [bp-20Ah]
  int v14; // [sp+28h] [bp-1F8h]
  int v15; // [sp+2Ch] [bp-1F4h]
  char v16[224]; // [sp+30h] [bp-1F0h] BYREF
  __int16 v17; // [sp+110h] [bp-110h]
  _DWORD v18[5]; // [sp+112h] [bp-10Eh]
  int v19; // [sp+128h] [bp-F8h]
  char v20[244]; // [sp+12Ch] [bp-F4h] BYREF

  v2 = PsGetMonitorContextServerSilo(SeRmSiloMonitor, a1[11], &v10);
  v3 = v10;
  if ( !v10 )
    return 0;
  if ( !*(_DWORD *)(v10 + 4) )
  {
    PspDereferenceMonitorContextServerSilo(v10 - 48);
    return 0;
  }
  v4 = a1[7];
  v13 = 0;
  v12 = (unsigned __int16)(v4 + 32);
  v11 = v4 + 8;
  *(_DWORD *)((char *)v18 + 2) = 0;
  v17 = a1[9];
  v18[0] = (unsigned __int16)(v17 + 24);
  v14 = a1[6];
  v19 = 0;
  if ( a1[2] != 1 )
    return sub_54D2B8(v2);
  v15 = 1;
  if ( v4 > 0xE0 )
  {
    v8 = -1073741811;
  }
  else
  {
    memmove((int)v16, (int)(a1 + 4), v4);
    if ( a1[6] != 3 || a1[8] )
    {
      v6 = ZwRequestWaitReplyPort();
      v7 = v19;
    }
    else
    {
      v6 = ZwRequestPort();
      v7 = 0;
      v19 = 0;
    }
    v8 = v6;
    if ( v6 >= 0 )
    {
      v9 = a1[8];
      if ( v9 )
      {
        memmove(v9, (int)v20, a1[9]);
        v7 = v19;
      }
      v8 = v7;
    }
    if ( v15 == 3 )
      v8 = ZwFreeVirtualMemory();
  }
  PspDereferenceMonitorContextServerSilo(v3 - 48);
  return v8;
}
