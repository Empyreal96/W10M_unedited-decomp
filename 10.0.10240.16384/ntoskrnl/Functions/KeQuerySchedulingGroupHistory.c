// KeQuerySchedulingGroupHistory 
 
int __fastcall KeQuerySchedulingGroupHistory(int a1, _DWORD *a2, _DWORD *a3, int *a4)
{
  int v8; // r1
  __int64 *v9; // lr
  __int64 v10; // t1
  int v11; // r4
  __int64 v12; // kr08_8
  unsigned __int64 v13; // r0
  __int64 v15; // [sp+0h] [bp-38h] BYREF
  __int64 v16; // [sp+8h] [bp-30h] BYREF
  char v17[40]; // [sp+10h] [bp-28h] BYREF

  KeAcquireInStackQueuedSpinLock(&KiSchedulingGroupLock, v17);
  *a2 = 0;
  a2[1] = 0;
  v8 = KeNumberProcessors_0;
  if ( KeNumberProcessors_0 )
  {
    v9 = (__int64 *)(a1 + 176);
    do
    {
      v10 = *v9;
      v9 += 31;
      v11 = a2[1];
      *a2 |= v10;
      --v8;
      a2[1] = v11 | HIDWORD(v10);
    }
    while ( v8 );
  }
  *a3 = PsDfssGenerationLengthMS;
  KeQueryPerformanceCounter(&v15, &v16);
  v12 = v15;
  if ( !v16 )
    __brkdiv0();
  LODWORD(v13) = _rt_udiv64(v16, 1000 * (v15 - *(_QWORD *)(a1 + 24)));
  if ( !*a3 )
    __brkdiv0();
  *a4 = _rt_udiv64((unsigned int)*a3, v13);
  *(_QWORD *)(a1 + 24) = v12;
  return KeReleaseInStackQueuedSpinLock(v17);
}
