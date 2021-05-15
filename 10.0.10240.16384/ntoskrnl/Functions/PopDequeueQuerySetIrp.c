// PopDequeueQuerySetIrp 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall PopDequeueQuerySetIrp(int a1)
{
  int v2; // r5
  int v3; // r6
  int v4; // r3
  int v5; // r2
  _DWORD *v6; // r5
  int v7; // r3
  int v8; // r7
  bool v9; // zf
  _DWORD *v10; // r2
  int result; // r0
  int *v12; // r5
  unsigned int v13; // r1
  _DWORD *v14; // r1
  _DWORD *v15; // r3
  int v16; // r4
  _DWORD *v17; // r3
  _DWORD *v18; // r0
  int **v19; // r0
  int *v20; // r1 OVERLAPPED
  int v21; // r4
  __int64 v22; // r0
  int *v23; // [sp+0h] [bp-38h] BYREF
  int **v24; // [sp+4h] [bp-34h]
  char v25[48]; // [sp+8h] [bp-30h] BYREF

  PopDiagTraceIrpFinish(a1);
  v2 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  if ( *(_BYTE *)(v2 + 124) && !KeCancelTimer(v2 + 32) )
    sub_54AD4C();
  v24 = &v23;
  v23 = (int *)&v23;
  v3 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  v4 = *(_DWORD *)(v3 + 12);
  if ( v4 )
    v5 = *(_DWORD *)(*(_DWORD *)(v4 + 176) + 20);
  else
    v5 = 0;
  if ( *(_DWORD *)(v3 + 116) == 1 )
    v6 = (_DWORD *)(v5 + 144);
  else
    v6 = (_DWORD *)(v5 + 152);
  KeAcquireInStackQueuedSpinLock((unsigned int *)&PopIrpLock, (unsigned int)v25);
  v7 = __mrc(15, 0, 13, 0, 3);
  v8 = PopInrushIrp;
  PopIrpLockThread = v7 & 0xFFFFFFC0;
  v9 = a1 == PopInrushIrp;
  *v6 = 0;
  if ( v9 )
    JUMPOUT(0x54AD66);
  v10 = (_DWORD *)v6[1];
  if ( v10 )
  {
    v14 = v10 + 22;
    v15 = (_DWORD *)v10[22];
    if ( v15 != v10 + 22 )
    {
      if ( v8 )
      {
        v10 = 0;
      }
      else
      {
        v16 = v10[22];
        v17 = (_DWORD *)v15[1];
        v18 = (_DWORD *)v10[23];
        PopInrushIrp = v6[1];
        if ( v17 != v14 || (_DWORD *)*v18 != v14 )
          __fastfail(3u);
        *v18 = v16;
        *(_DWORD *)(v16 + 4) = v18;
      }
    }
    if ( v10 )
    {
      *v6 = v10;
      v6[1] = v10[16];
      v19 = v24;
      v10[16] = &v23;
      v10[17] = v19;
      if ( *v19 != (int *)&v23 )
        __fastfail(3u);
      *v19 = v10 + 16;
      v24 = (int **)(v10 + 16);
    }
  }
  PopIrpLockThread = 0;
  for ( result = KeReleaseInStackQueuedSpinLock((int)v25); ; result = IofCallDriver(v21, (int)(v12 - 16)) )
  {
    v12 = v23;
    if ( v23 == (int *)&v23 )
      break;
    *(_QWORD *)&v20 = *(_QWORD *)v23;
    if ( (int **)v23[1] != &v23 || (int *)v20[1] != v23 )
      __fastfail(3u);
    v23 = v20;
    v20[1] = (int)&v23;
    v21 = *(_DWORD *)(v12[8] - 16);
    PopDiagTraceIrpStart(result, (int)(v12 - 16));
    LODWORD(v22) = v12 - 16;
    PopEnableIrpWatchdog(v22);
  }
  if ( *(_BYTE *)(v3 + 112) == 2 && *(_DWORD *)(v3 + 116) == 1 )
  {
    __dmb(0xBu);
    do
      v13 = __ldrex((unsigned int *)&PopPendingSetPowerDeviceIrps);
    while ( __strex(v13 - 1, (unsigned int *)&PopPendingSetPowerDeviceIrps) );
    __dmb(0xBu);
  }
  return result;
}
