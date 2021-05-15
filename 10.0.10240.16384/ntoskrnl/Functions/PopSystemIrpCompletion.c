// PopSystemIrpCompletion 
 
int __fastcall PopSystemIrpCompletion(int a1, int a2, int a3)
{
  int v5; // r3
  int v6; // r9
  int *v7; // r4
  int v8; // r1
  int v9; // r2
  int v10; // r3
  int v11; // r5
  int v12; // r10
  int v13; // r7
  int v14; // r2
  int v15; // r8
  int v16; // r6
  int v17; // r3
  _DWORD *v18; // r8
  int v19; // r3
  int v20; // r1
  int **v21; // r2
  int **v22; // r1
  int *i; // r5
  int **v24; // r1
  int *v25; // r8
  int *j; // r5
  int v28; // [sp+8h] [bp-58h]
  int v29; // [sp+Ch] [bp-54h]
  int v30; // [sp+10h] [bp-50h]
  int v31[2]; // [sp+18h] [bp-48h] BYREF
  char v32[16]; // [sp+20h] [bp-40h] BYREF
  int v33[12]; // [sp+30h] [bp-30h] BYREF

  if ( (dword_682610 & 0x8000) != 0 )
  {
    v5 = *(_DWORD *)(a2 + 24);
    v31[0] = a2;
    v31[1] = v5;
    v33[0] = (int)v31;
    v33[1] = 0;
    v33[2] = 8;
    v33[3] = 0;
    EtwTraceKernelEvent(v33, 1, 0x80008000, 4647, 4200450);
  }
  v6 = *(_DWORD *)(a2 + 24);
  v7 = *(int **)(a3 + 136);
  if ( v6 >= 0 )
    v30 = 0;
  else
    v30 = IoFindDeviceThatFailedIrp(a2);
  PopDequeueQuerySetIrp(a2);
  PopFreeIrp(a2, v8, v9, v10);
  v12 = *(v7 - 19);
  v11 = *(v7 - 20);
  v13 = 0;
  v14 = dword_61E84C;
  v29 = 0;
  v15 = dword_61E84C + 28;
  v16 = dword_61E84C;
  v28 = dword_61E84C + 28;
  v31[0] = v11;
  v17 = *(unsigned __int8 *)dword_61E84C;
  if ( v12 == IopRootDeviceNode )
    v12 = 0;
  if ( (v17 == 2 || v17 == 3) && *(int *)(dword_61E84C + 4) > 1 )
  {
    PopFxIncrementDeviceSleepCount(*(v7 - 17));
    ObfDereferenceObject(*(v7 - 17));
    v14 = dword_61E84C;
  }
  v18 = (_DWORD *)(v15 + 40 * *((unsigned __int8 *)v7 + 28));
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v14 + 8), (unsigned int)v32);
  v19 = __mrc(15, 0, 13, 0, 3);
  v20 = *v7;
  PopDevStateLockThread = v19 & 0xFFFFFFC0;
  v21 = (int **)v7[1];
  if ( *(int **)(v20 + 4) != v7 || *v21 != v7 )
    __fastfail(3u);
  *v21 = (int *)v20;
  *(_DWORD *)(v20 + 4) = v21;
  if ( *(_BYTE *)(v16 + 252) )
  {
    v22 = (int **)v18[5];
    *v7 = (int)(v18 + 4);
    v7[1] = (int)v22;
    if ( *v22 != v18 + 4 )
      __fastfail(3u);
    *v22 = v7;
    v18[5] = v7;
    ++v18[3];
    while ( v11 )
    {
      if ( PopReadyChildWake((__int64 *)(v11 + 84), v28, *((unsigned __int8 *)v7 + 28)) )
        ++v13;
      v11 = *(_DWORD *)v11;
    }
    for ( i = (int *)v7[2]; i != v7 + 2; i = (int *)*i )
    {
      if ( PopReadyChildWake((__int64 *)*(i - 1), v28, *((unsigned __int8 *)v7 + 28)) )
        ++v13;
    }
  }
  else
  {
    v24 = (int **)v18[9];
    *v7 = (int)(v18 + 8);
    v7[1] = (int)v24;
    if ( *v24 != v18 + 8 )
      __fastfail(3u);
    *v24 = v7;
    v18[9] = v7;
    --v18[3];
    if ( v12 && PopReadyParentSleep((__int64 *)(v12 + 84), v28, *((unsigned __int8 *)v7 + 28)) )
      v13 = 1;
    v25 = (int *)v7[4];
    if ( v25 != v7 + 4 )
    {
      do
      {
        if ( PopReadyParentSleep((__int64 *)v25[5], v28, *((unsigned __int8 *)v7 + 28)) )
          ++v13;
        v25 = (int *)*v25;
      }
      while ( v25 != v7 + 4 );
      v11 = v31[0];
    }
    if ( v6 < 0 && v30 && *(_BYTE *)v16 == 3 )
      PopDiagTraceDriverVeto();
    while ( v11 )
    {
      PopPrepChildWake((__int64 *)(v11 + 84), v28);
      v11 = *(_DWORD *)v11;
    }
    for ( j = (int *)v7[2]; j != v7 + 2; j = (int *)*j )
      PopPrepChildWake((__int64 *)*(j - 1), v28);
    if ( v6 < 0 && !*(_BYTE *)(v16 + 254) && (v6 != -1073741637 || !*(_BYTE *)(v16 + 255)) && *(int *)(v16 + 244) >= 0 )
    {
      *(_DWORD *)(v16 + 244) = v6;
      *(_DWORD *)(v16 + 248) = v7[8];
      v29 = 1;
    }
  }
  PopDevStateLockThread = 0;
  KeReleaseInStackQueuedSpinLock((int)v32);
  if ( v29 )
  {
    KeSetEvent(*(_DWORD *)(v16 + 16), 0, 0);
  }
  else if ( v13 > 0 )
  {
    KeReleaseSemaphore(*(_DWORD *)(v16 + 20), 0, v13);
  }
  KeReleaseSemaphore(*(_DWORD *)(v16 + 24), 0, 1);
  return -1073741802;
}
