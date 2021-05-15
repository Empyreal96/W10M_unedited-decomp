// PoQueryWatchdogTime 
 
int __fastcall PoQueryWatchdogTime(int a1, int *a2, int a3, int a4)
{
  unsigned __int64 v5; // r4
  int v6; // r8
  int v7; // r6
  int v8; // r0
  int v9; // r3
  int v10; // r2
  int v11; // r7
  __int64 v12; // r0
  unsigned int v13; // kr00_4
  unsigned __int64 v14; // kr08_8
  int v16; // r0
  unsigned __int64 v17; // r0
  _DWORD v18[10]; // [sp+0h] [bp-28h] BYREF

  v18[0] = a2;
  v18[1] = a3;
  v18[2] = a4;
  v5 = -1i64;
  v6 = 0;
  if ( a1 )
    v7 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v7 = 0;
  v8 = KeAcquireInStackQueuedSpinLock(&PopIrpLock, v18);
  v9 = __mrc(15, 0, 13, 0, 3);
  v10 = *(_DWORD *)(v7 + 144);
  PopIrpLockThread = v9 & 0xFFFFFFC0;
  if ( v10 )
  {
    v11 = *(_DWORD *)(v10 + 40 * *(char *)(v10 + 34) + 108);
    if ( *(_BYTE *)(v11 + 124) )
    {
      v12 = PopComputeWatchdogTimeout(*(_DWORD *)(v10 + 40 * *(char *)(v10 + 34) + 108), dword_989680);
      v13 = v12 * HIDWORD(v12);
      v8 = ((unsigned int)v12 * (unsigned __int64)HIDWORD(v12)) >> 32;
      v14 = *(_QWORD *)(v11 + 24) + __PAIR64__(v8, v13);
      if ( v14 != -1i64 )
        v5 = v14;
    }
  }
  if ( *(_DWORD *)(v7 + 152) )
    return sub_52A0BC(v8, dword_989680);
  PopIrpLockThread = 0;
  v16 = KeReleaseInStackQueuedSpinLock(v18);
  if ( ((unsigned int)v5 & HIDWORD(v5)) != -1 )
  {
    v6 = 1;
    v17 = KeQueryInterruptTime(v16);
    if ( v17 > v5 )
      *a2 = 0;
    else
      *a2 = _rt_udiv64((unsigned int)dword_989680, v5 - v17);
  }
  return v6;
}
