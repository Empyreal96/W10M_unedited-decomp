// MiProcessDeleteOnClose 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiProcessDeleteOnClose(int a1)
{
  int v2; // r8
  unsigned int *v3; // r6
  unsigned int v4; // r1
  unsigned int v5; // r1
  int v6; // r6
  int v7; // r1
  unsigned int v8; // r0
  int v9; // r1 OVERLAPPED
  int *v10; // r2 OVERLAPPED
  int v11; // r6
  unsigned int v12; // r0
  int v14; // [sp+10h] [bp-28h]
  int v15[9]; // [sp+14h] [bp-24h] BYREF
  int vars4; // [sp+3Ch] [bp+4h]

  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v5 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v5 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    if ( v5 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v6 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        v7 = dword_632D80 | 0x40000000;
        do
          v8 = __ldrex((unsigned int *)&dword_632D80);
        while ( v8 == v6 && __strex(v7, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v3 = *(unsigned int **)(a1 + 808);
  v14 = *(_DWORD *)(a1 + 868);
  if ( v3 == (unsigned int *)(a1 + 808) )
  {
LABEL_36:
    *(_BYTE *)(a1 + 864) = 0;
    if ( (dword_682604 & 0x10000) != 0 )
      goto LABEL_37;
    goto LABEL_52;
  }
  while ( !ExTryAcquireSpinLockExclusiveAtDpcLevel(v3 + 8) )
  {
    if ( !--v14 )
      goto LABEL_49;
    v3 = (unsigned int *)*v3;
LABEL_35:
    if ( v3 == (unsigned int *)(a1 + 808) )
      goto LABEL_36;
  }
  --*(_DWORD *)(a1 + 868);
  *(_QWORD *)&v9 = *(_QWORD *)v3;
  if ( *(unsigned int **)(*v3 + 4) != v3 || (unsigned int *)*v10 != v3 )
    __fastfail(3u);
  *v10 = v9;
  *(_DWORD *)(v9 + 4) = v10;
  v3[6] &= 0xF7FFFFFF;
  *v3 = (unsigned int)v3;
  v3[1] = (unsigned int)v3;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_632D80 = 0;
  }
  if ( v3[9] )
  {
    MiInsertUnusedSegment(v3 - 1, v9);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v3 + 8, vars4);
    }
    else
    {
      __dmb(0xBu);
      v3[8] = 0;
    }
    KfLowerIrql(v2);
  }
  else
  {
    if ( MiFlushControlArea(v3 - 1, v2, v15) == 1 )
      MiDestroySection((int)(v3 - 1), v2);
    if ( v15[0] )
      MiReleaseControlAreaWaiters((_DWORD *)v15[0]);
  }
  KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v4 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    if ( v4 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v11 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        v4 = dword_632D80 | 0x40000000;
        do
          v12 = __ldrex((unsigned int *)&dword_632D80);
        while ( v12 == v11 && __strex(v4, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v3 = *(unsigned int **)(a1 + 808);
  if ( v3 == (unsigned int *)(a1 + 808) )
    goto LABEL_36;
  if ( --v14 )
    goto LABEL_35;
LABEL_49:
  KiSetTimerEx(a1 + 816, v4, *(__int64 *)Mi10Milliseconds, 0, 0, 0);
  if ( (dword_682604 & 0x10000) == 0 )
  {
LABEL_52:
    __dmb(0xBu);
    dword_632D80 = 0;
    return KfLowerIrql(v2);
  }
LABEL_37:
  ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
  return KfLowerIrql(v2);
}
