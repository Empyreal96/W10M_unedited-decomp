// PopQueueQuerySetIrp 
 
int __fastcall PopQueueQuerySetIrp(int a1, int a2, int a3, int a4)
{
  _DWORD *v4; // r4
  int v5; // r6
  int v6; // r0
  int v7; // r7
  int v8; // r3
  int v10; // r5
  int v11; // r8
  unsigned int v12; // r1
  int v13; // r2
  int *v14; // r5
  int v15; // r2
  int v16; // r3
  int v17; // r0
  int v18; // r0
  int v19; // r2
  int **v20; // r0
  int v21; // r1
  _DWORD *v22; // r2
  _DWORD v23[10]; // [sp+0h] [bp-28h] BYREF

  v23[0] = a1;
  v23[1] = a2;
  v23[2] = a3;
  v23[3] = a4;
  v4 = (_DWORD *)a1;
  v5 = *(_DWORD *)(a1 + 96);
  v6 = *(_DWORD *)(a1 + 40 * *(char *)(a1 + 34) + 108);
  v7 = 0;
  v8 = *(_DWORD *)(v6 + 12);
  if ( !v8 )
    return sub_52A5C0();
  v10 = *(_DWORD *)(*(_DWORD *)(v8 + 176) + 20);
  v11 = *(_DWORD *)(v6 + 16);
  if ( *(_BYTE *)(v6 + 112) == 2 && *(_DWORD *)(v6 + 116) == 1 )
  {
    __dmb(0xBu);
    do
      v12 = __ldrex((unsigned int *)&PopPendingSetPowerDeviceIrps);
    while ( __strex(v12 + 1, (unsigned int *)&PopPendingSetPowerDeviceIrps) );
    __dmb(0xBu);
  }
  v13 = *(_DWORD *)(v6 + 116);
  if ( v13 == 1 )
    v14 = (int *)(v10 + 144);
  else
    v14 = (int *)(v10 + 152);
  if ( *(_BYTE *)(v6 + 112) == 2 && v13 == 1 && *(_DWORD *)(v5 - 24) == 1 )
  {
    v18 = KeAcquireQueuedSpinLock(10);
    v19 = v11;
    if ( v11 )
    {
      while ( (*(_DWORD *)(v19 + 28) & 0x4000) == 0 )
      {
        v19 = *(_DWORD *)(*(_DWORD *)(v19 + 176) + 24);
        if ( !v19 )
          goto LABEL_24;
      }
      v7 = 1;
    }
LABEL_24:
    KeReleaseQueuedSpinLock(10, v18);
  }
  v4[16] = 0;
  KeAcquireInStackQueuedSpinLock(&PopIrpLock, v23);
  PopIrpLockThread = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  if ( v7 )
  {
    v20 = (int **)dword_61E88C;
    v4[22] = &PopInrushIrpList;
    v4[23] = v20;
    if ( *v20 != &PopInrushIrpList )
      __fastfail(3u);
    *v20 = v4 + 22;
    dword_61E88C = (int)(v4 + 22);
  }
  v15 = v14[1];
  if ( v15 )
  {
    while ( *(_DWORD *)(v15 + 64) )
      v15 = *(_DWORD *)(v15 + 64);
    *(_DWORD *)(v15 + 64) = v4;
    goto LABEL_27;
  }
  v16 = *v14;
  v14[1] = (int)v4;
  if ( v16 )
  {
LABEL_27:
    v4 = 0;
    goto LABEL_18;
  }
  if ( v7 )
  {
    if ( !PopInrushIrp )
    {
      v21 = v4[22];
      PopInrushIrp = (int)v4;
      v22 = (_DWORD *)v4[23];
      if ( *(_DWORD **)(v21 + 4) != v4 + 22 || (_DWORD *)*v22 != v4 + 22 )
        __fastfail(3u);
      *v22 = v21;
      *(_DWORD *)(v21 + 4) = v22;
      goto LABEL_17;
    }
    goto LABEL_27;
  }
LABEL_17:
  *v14 = (int)v4;
  v14[1] = 0;
LABEL_18:
  PopIrpLockThread = 0;
  v17 = KeReleaseInStackQueuedSpinLock(v23);
  if ( v4 )
  {
    PopDiagTraceIrpStart(v17, v4);
    PopEnableIrpWatchdog(v4);
    IofCallDriver(v11, v4);
  }
  return v23[0];
}
