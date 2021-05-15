// PopRequestPowerIrp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopRequestPowerIrp(int a1, int a2, int a3, int a4, int a5, unsigned __int8 a6, unsigned int *a7)
{
  int v7; // r4
  int v11; // r3
  int result; // r0
  int v13; // r5
  int v14; // r2
  int (*v15)(); // r3
  int v16; // r4 OVERLAPPED
  int v17; // r7
  unsigned int v18; // r4
  unsigned int v19; // r2
  unsigned int *v20; // r2
  unsigned int v21; // r0
  int v22; // r1
  unsigned int *v23; // r2
  unsigned int v24; // r0
  unsigned int v25; // r0
  int v26; // [sp+20h] [bp-28h] BYREF
  int var24[13]; // [sp+24h] [bp-24h] BYREF
  int varg_r2; // [sp+58h] [bp+10h]
  int varg_r3; // [sp+5Ch] [bp+14h]

  var24[11] = a1;
  var24[12] = a2;
  varg_r3 = a4;
  v7 = a3;
  varg_r2 = a3;
  if ( a7 )
  {
    __dmb(0xBu);
    do
      v18 = __ldrex(a7);
    while ( __strex(0, a7) );
    __dmb(0xBu);
    v7 = varg_r2;
  }
  v26 = 0;
  if ( a2 == 2 )
  {
    if ( PopCurrentBroadcast )
    {
      v11 = 1;
      goto LABEL_5;
    }
  }
  else if ( a2 )
  {
    return sub_52A108();
  }
  v11 = 0;
LABEL_5:
  result = PopAllocateIrp(a1, v11, a2, a2 != 0, v7, v11, a6, a4, a5, &v26, var24);
  if ( result >= 0 && result != 259 )
  {
    v13 = v26;
    if ( v26 )
    {
      v14 = *(_DWORD *)(v26 + 96);
      v15 = PopRequestCompletion;
      v16 = var24[0];
      *(_QWORD *)(v14 - 8) = *(_QWORD *)(&v16 - 1);
      *(_BYTE *)(v14 - 37) = -32;
      if ( a7 )
      {
        __dmb(0xBu);
        do
          v19 = __ldrex(a7);
        while ( __strex(v13, a7) );
        __dmb(0xBu);
      }
      v17 = *(_DWORD *)(v13 + 96);
      if ( a2 )
      {
        *(_DWORD *)(v17 - 28) = 1;
        *(_DWORD *)(v17 - 24) = varg_r2;
        *(_DWORD *)(v17 - 32) = dword_61E844;
        if ( PopCurrentBroadcast )
          *(_DWORD *)(v17 - 20) = PopMapInternalActionToIrpAction(dword_61E848, (unsigned __int16)dword_61E844 >> 12, 1);
        if ( (dword_682610 & 0x8000) != 0 )
          PopLogNotifyDevice(a1, 0, v13);
        PopQueueQuerySetIrp(v13);
      }
      else
      {
        if ( *(_DWORD *)(v16 + 128) )
        {
          __dmb(0xBu);
          v20 = (unsigned int *)(*(_DWORD *)(v16 + 128) + 16);
          do
            v21 = __ldrex(v20);
          while ( __strex(v21, v20) );
          __dmb(0xBu);
          *(_BYTE *)(v16 + 132) = (v21 & 1) != 0;
          *(_BYTE *)(v16 + 133) = (v21 & 1) == 0;
          if ( (v21 & 1) != 0 )
          {
            v22 = *(_DWORD *)(v16 + 128);
            __dmb(0xBu);
            v23 = (unsigned int *)(v22 + 112);
            do
            {
              v24 = __ldrex(v23);
              v25 = v24 - 1;
            }
            while ( __strex(v25, v23) );
            __dmb(0xBu);
            if ( !v25 )
              KeSetEvent(v22 + 116, 0, 0);
            *(_DWORD *)(v16 + 128) = 0;
          }
          else
          {
            PopPepDeviceWaitWake(*(_DWORD *)(*(_DWORD *)(v16 + 128) + 32), 0);
          }
        }
        *(_DWORD *)(v17 - 32) = varg_r2;
        PopDiagTraceIrpStart();
        IofCallDriverSpecifyReturn(*(_DWORD *)(v17 - 16), v13);
      }
      result = 259;
    }
    else
    {
      result = -1073741670;
    }
  }
  return result;
}
