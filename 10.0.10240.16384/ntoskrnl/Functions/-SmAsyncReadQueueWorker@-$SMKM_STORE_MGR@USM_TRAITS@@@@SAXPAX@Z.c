// -SmAsyncReadQueueWorker@-$SMKM_STORE_MGR@USM_TRAITS@@@@SAXPAX@Z 
 
// local variable allocation has failed, the output may be wrong!
__int64 __fastcall SMKM_STORE_MGR<SM_TRAITS>::SmAsyncReadQueueWorker(_DWORD *a1)
{
  _DWORD *v1; // r6
  int v2; // r9
  unsigned int *v3; // r5
  unsigned int v4; // r4 OVERLAPPED
  int v5; // r8
  unsigned int v6; // r2
  unsigned __int64 v7; // r0
  unsigned int v8; // r6
  int v9; // r9
  int v10; // r8
  unsigned int v11; // r2
  unsigned int v12; // r8
  int v13; // r6
  unsigned __int64 v14; // r0
  _DWORD *v15; // r2
  int v16; // r3
  unsigned int v18; // [sp+0h] [bp-58h]
  unsigned int v19; // [sp+4h] [bp-54h]
  int v20; // [sp+8h] [bp-50h]
  __int64 v21; // [sp+10h] [bp-48h] BYREF
  __int64 v22; // [sp+18h] [bp-40h] BYREF
  __int64 v23; // [sp+20h] [bp-38h] BYREF
  _DWORD v24[2]; // [sp+28h] [bp-30h] BYREF
  __int64 v25[5]; // [sp+30h] [bp-28h] BYREF
  int vars4; // [sp+5Ch] [bp+4h]

  v1 = a1;
  v2 = 100;
  v20 = 100;
  v3 = (unsigned int *)((a1[5] & 0xFFFFFFFC) + 512);
  v4 = (a1[5] & 0xFFFFFFFC) + 16 * (a1[4] & 7 | (8 * (a1[5] & 3)));
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v6 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  --*(_DWORD *)(v4 + 8);
  ++*(_DWORD *)(v4 + 12);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  KfLowerIrql(v5);
LABEL_10:
  KeQueryPerformanceCounter(&v22, &v21);
  SMKM_STORE<SM_TRAITS>::SmStWorkItemQueue(v1[4] & 0xFFFFFFF8, v1 - 8, 0);
  KeQueryPerformanceCounter(&v23, 0);
  if ( !v21 )
    __brkdiv0();
  LODWORD(v7) = _rt_sdiv64(v21, 1000000 * (v23 - v22));
  if ( v7 < (unsigned int)v2 )
    v20 = v7;
  v8 = 0;
  v18 = 0;
  v19 = 0;
  v9 = 0;
  while ( 1 )
  {
    v10 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v3);
    }
    else
    {
      do
        v11 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
      if ( v11 )
        KxWaitForSpinLockAndAcquire(v3);
    }
    if ( **(_DWORD **)(v4 + 4) )
    {
      if ( *(_DWORD *)(v4 + 4) == v4 )
      {
        v1 = 0;
      }
      else
      {
        v15 = *(_DWORD **)(v4 + 4);
        v1 = *(_DWORD **)v4;
        *(_DWORD *)v4 = **(_DWORD **)v4;
        if ( v1 == v15 )
        {
          v16 = 0;
          *(_QWORD *)v4 = *(_QWORD *)(&v4 - 1);
        }
        else
        {
          --*v15;
        }
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v3, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v3 = 0;
      }
      KfLowerIrql(v10);
      v2 = v20;
      goto LABEL_10;
    }
    if ( v9 )
      break;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v3, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v3 = 0;
    }
    KfLowerIrql(v10);
    if ( v8 | v19 )
    {
      v12 = v18;
    }
    else
    {
      KeQueryPerformanceCounter(v24, 0);
      v12 = v24[0];
      v18 = v24[0];
      v19 = v24[1];
    }
    v13 = 0;
    while ( *(_DWORD *)(v4 + 8) <= *(_DWORD *)(v4 + 12) )
    {
      if ( **(_DWORD **)(v4 + 4) )
        goto LABEL_15;
      if ( (++v13 & 0x7F) == 0 )
      {
        KeQueryPerformanceCounter(v25, 0);
        if ( !v21 )
          __brkdiv0();
        LODWORD(v14) = _rt_sdiv64(v21, 1000000 * (v25[0] - __PAIR64__(v19, v12)));
        if ( v14 >= (unsigned int)v20 )
          break;
      }
      __dmb(0xAu);
      __yield();
    }
    v9 = 1;
LABEL_15:
    v8 = v18;
  }
  --*(_DWORD *)(v4 + 12);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v3, vars4);
  }
  else
  {
    __dmb(0xBu);
    *v3 = 0;
  }
  return KfLowerIrql(v10);
}
