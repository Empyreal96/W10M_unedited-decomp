// MiDereferencePerSessionProtos 
 
int __fastcall MiDereferencePerSessionProtos(_DWORD *a1, int a2)
{
  _DWORD *v2; // r5
  unsigned int v3; // r8
  int v4; // r2
  _DWORD *v5; // r9
  unsigned __int8 *v6; // r6
  int v7; // r0
  int v8; // r4
  unsigned int v9; // r2
  _DWORD *v10; // r5
  _DWORD *v11; // r6
  unsigned int *v12; // r4
  _DWORD *v13; // r7
  int v14; // r3
  unsigned __int8 *v15; // r3
  unsigned int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  unsigned int v20; // r1
  int result; // r0
  int v22; // r1
  unsigned int v23; // r2
  int v24; // r3
  int v25; // r4
  int v26; // r0
  int v28; // [sp+0h] [bp-30h]
  unsigned __int8 *v30; // [sp+8h] [bp-28h]
  int vars4; // [sp+34h] [bp+4h]

  v2 = a1;
  v3 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v4 = *a1;
  --*(_WORD *)(v3 + 310);
  v5 = 0;
  v6 = (unsigned __int8 *)(v4 + 28);
  v30 = (unsigned __int8 *)(v4 + 28);
  v7 = KeAbPreAcquire(v4 + 28, 0, 0);
  v8 = v7;
  do
    v9 = __ldrex(v6);
  while ( __strex(v9 | 1, v6) );
  __dmb(0xBu);
  if ( (v9 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v6, v7, (unsigned int)v6);
  if ( v8 )
    *(_BYTE *)(v8 + 14) |= 1u;
  v10 = v2 + 20;
  if ( v10 )
  {
    v11 = a1;
    do
    {
      if ( (*((_WORD *)v10 + 9) & 2) != 0 )
      {
        v12 = v11 + 9;
        v28 = KfRaiseIrql(2);
        if ( (dword_682604 & 0x210000) != 0 )
        {
          ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v11 + 9);
        }
        else
        {
          v15 = (unsigned __int8 *)v11 + 39;
          do
            v16 = __ldrex(v15);
          while ( __strex(v16 | 0x80, v15) );
          __dmb(0xBu);
          if ( v16 >> 7 )
            ExpWaitForSpinLockExclusiveAndAcquire(v11 + 9);
          while ( 1 )
          {
            v17 = *v12;
            if ( (*v12 & 0xBFFFFFFF) == 0x80000000 )
              break;
            if ( (v17 & 0x40000000) == 0 )
            {
              do
                v18 = __ldrex(v12);
              while ( v18 == v17 && __strex(v17 | 0x40000000, v12) );
              __dmb(0xBu);
            }
            __dmb(0xAu);
            __yield();
          }
        }
        v13 = (_DWORD *)MiLocateSessionProtosInSubsection(v10, a2);
        v14 = v13[5] - 1;
        v13[5] = v14;
        if ( v14 )
        {
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v11 + 9, vars4);
          }
          else
          {
            __dmb(0xBu);
            *v12 = 0;
          }
          KfLowerIrql(v28);
        }
        else
        {
          RtlAvlRemoveNode((int)(v10 + 3), (int)v13);
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v11 + 9, vars4);
          }
          else
          {
            __dmb(0xBu);
            *v12 = 0;
          }
          KfLowerIrql(v28);
          v19 = v10[7];
          v13[3] = v10;
          v13[5] = v19;
          *v13 = v5;
          v5 = v13;
        }
      }
      v10 = (_DWORD *)v10[2];
    }
    while ( v10 );
    v6 = v30;
  }
  __dmb(0xBu);
  do
    v20 = __ldrex((unsigned int *)v6);
  while ( __strex(v20 - 1, (unsigned int *)v6) );
  if ( (v20 & 2) != 0 && (v20 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)v6);
  result = KeAbPostRelease((unsigned int)v6);
  v24 = (__int16)(*(_WORD *)(v3 + 310) + 1);
  *(_WORD *)(v3 + 310) = v24;
  if ( !(_WORD)v24 )
  {
    v24 = *(_DWORD *)(v3 + 100);
    v23 = v3 + 100;
    if ( v24 != v3 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  while ( 1 )
  {
    v25 = (int)v5;
    if ( !v5 )
      break;
    v5 = (_DWORD *)*v5;
    v26 = MiDeletePerSessionProtos(v25, v22, v23, v24);
    MiReturnCommit((int)MiSystemPartition, v26);
    ExFreePoolWithTag(*(_DWORD *)(v25 + 16));
    result = ExFreePoolWithTag(v25);
  }
  return result;
}
