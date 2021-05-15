// MiDeleteCachedSegment 
 
_DWORD *__fastcall MiDeleteCachedSegment(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r5
  int v6; // r9
  _DWORD *v7; // r7
  _DWORD *v8; // r8
  unsigned int v9; // r1
  int v10; // r7
  int v11; // r1
  unsigned int v12; // r0
  int *v13; // r0
  _DWORD *result; // r0
  _DWORD *v15; // r2
  __int64 v16; // r0
  int v17; // r2
  _DWORD *v18; // r4
  int v19[8]; // [sp+0h] [bp-20h] BYREF
  int vars4; // [sp+24h] [bp+4h]

  v19[0] = a4;
  v5 = 0;
  v6 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented((unsigned int *)&dword_632D80);
  }
  else
  {
    do
      v9 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
    while ( __strex(v9 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
    __dmb(0xBu);
    if ( v9 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
    while ( 1 )
    {
      v10 = dword_632D80;
      if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632D80 & 0x40000000) == 0 )
      {
        v11 = dword_632D80 | 0x40000000;
        do
          v12 = __ldrex((unsigned int *)&dword_632D80);
        while ( v12 == v10 && __strex(v11, (unsigned int *)&dword_632D80) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
  }
  v7 = *(_DWORD **)(a1 + 872);
  v8 = (_DWORD *)(a1 + 872);
  while ( v7 != v8 )
  {
    v5 = v7 - 1;
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v7 + 8) )
      break;
    v7 = (_DWORD *)*v7;
  }
  if ( v7 == v8 )
  {
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      dword_632D80 = 0;
      return (_DWORD *)KfLowerIrql(v6);
    }
    v13 = &dword_632D80;
LABEL_20:
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v13, vars4);
    return (_DWORD *)KfLowerIrql(v6);
  }
  v15 = v5 + 1;
  v16 = *(_QWORD *)(v5 + 1);
  if ( *(_DWORD **)(v16 + 4) != v5 + 1 || *(_DWORD **)HIDWORD(v16) != v15 )
    __fastfail(3u);
  *(_DWORD *)HIDWORD(v16) = v16;
  *(_DWORD *)(v16 + 4) = HIDWORD(v16);
  v5[7] &= 0xF7FFFFFF;
  *v15 = v15;
  v5[2] = v5 + 1;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80, vars4);
  }
  else
  {
    __dmb(0xBu);
    dword_632D80 = 0;
  }
  v17 = (v5[7] >> 5) & 1;
  if ( !v17 && v5[10] )
  {
    MiInsertUnusedSegment(v5, SHIDWORD(v16));
    if ( (dword_682604 & 0x10000) == 0 )
    {
      __dmb(0xBu);
      v5[9] = 0;
      return (_DWORD *)KfLowerIrql(v6);
    }
    v13 = v5 + 9;
    goto LABEL_20;
  }
  v18 = 0;
  v19[0] = 0;
  if ( v17 || (result = (_DWORD *)MiFlushControlArea(v5, v6, v19), v18 = (_DWORD *)v19[0], result == (_DWORD *)1) )
    result = (_DWORD *)MiDestroySection(v5, v6);
  if ( v18 )
    result = MiReleaseControlAreaWaiters(v18);
  return result;
}
