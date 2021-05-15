// MiTrimSharedPage 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall MiTrimSharedPage(int a1, int a2, int a3)
{
  int v4; // r4 OVERLAPPED
  int v5; // r3
  int v6; // r5
  unsigned int v8; // r5
  int v9; // r7
  unsigned int *v10; // r4
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  unsigned int *v16; // r10
  unsigned int v17; // r1
  int v18; // r0
  unsigned __int8 *v19; // r1
  unsigned int v20; // r2
  unsigned int *v21; // r4
  int v22; // r5
  unsigned __int8 *v23; // r3
  unsigned int v24; // r1
  unsigned int v25; // r0
  unsigned int v26; // r1
  int *v27; // r0
  unsigned int v28; // r1
  unsigned __int8 *v29; // r1
  unsigned int v30; // r2
  unsigned int v31; // r3
  unsigned int v32; // r1
  unsigned int v33; // r3
  unsigned int v34; // [sp+0h] [bp-50h]
  int v35; // [sp+4h] [bp-4Ch]
  int v36; // [sp+8h] [bp-48h]
  unsigned int v37; // [sp+Ch] [bp-44h]
  int var38[15]; // [sp+18h] [bp-38h] BYREF

  *(_QWORD *)(&v4 - 1) = *(_QWORD *)(a1 + 4);
  v6 = v5 | 0x80000000;
  v34 = 0;
  v35 = a2;
  v37 = v5 | 0x80000000;
  if ( (v4 & 0x400) == 0 )
  {
    __dmb(0xBu);
    v16 = (unsigned int *)(a1 + 12);
    do
      v26 = __ldrex(v16);
    while ( __strex(v26 & 0x7FFFFFFF, v16) );
    KfLowerIrql(a2);
    v27 = (int *)MiReferencePfBackedSection(v6);
    v8 = (unsigned int)v27;
    if ( !v27 )
    {
      KfRaiseIrql(2);
      v29 = (unsigned __int8 *)(a1 + 15);
      do
        v30 = __ldrex(v29);
      while ( __strex(v30 | 0x80, v29) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v30 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v31 = *v16;
          __dmb(0xBu);
        }
        while ( (v31 & 0x80000000) != 0 );
        do
          v30 = __ldrex(v29);
        while ( __strex(v30 | 0x80, v29) );
      }
      return 0;
    }
    v9 = *v27;
    goto LABEL_17;
  }
  v8 = v4 & 0xFFFFF800 | (2 * (v4 & 0x3FC));
  if ( (*(_WORD *)(v8 + 0x12) & 2) != 0 )
    return 0;
  v9 = *(_DWORD *)v8;
  v10 = (unsigned int *)(*(_DWORD *)v8 + 36);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_511EA0();
  v12 = (unsigned __int8 *)(*(_DWORD *)v8 + 39);
  do
    v13 = __ldrex(v12);
  while ( __strex(v13 | 0x80, v12) );
  __dmb(0xBu);
  if ( v13 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire(v10);
  while ( 1 )
  {
    v14 = *v10;
    if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (v14 & 0x40000000) == 0 )
    {
      do
        v28 = __ldrex(v10);
      while ( v28 == v14 && __strex(v14 | 0x40000000, v10) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v15 = *(_DWORD *)(v9 + 28);
  if ( ((v15 | (v15 >> 1)) & 1) != 0 )
    goto LABEL_49;
  if ( (v15 & 0x20) == 0 )
  {
    if ( (*(_WORD *)(v8 + 18) & 1) == 0 )
    {
      v34 = v8;
      MiReferenceSubsection(v8);
      goto LABEL_12;
    }
LABEL_49:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10);
    }
    else
    {
      __dmb(0xBu);
      *v10 = 0;
    }
    return 0;
  }
LABEL_12:
  v36 = MiBuildWakeList(v9, 4);
  ++*(_DWORD *)(v9 + 40);
  MiRemoveUnusedSegment(v9);
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10);
  }
  else
  {
    __dmb(0xBu);
    *v10 = 0;
  }
  __dmb(0xBu);
  v16 = (unsigned int *)(a1 + 12);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 & 0x7FFFFFFF, v16) );
  KfLowerIrql(v35);
  MiReleaseControlAreaWaiters(v36);
LABEL_17:
  var38[1] = v37;
  var38[2] = v37;
  var38[4] = v8;
  var38[5] = 0;
  var38[0] = v9;
  var38[3] = v8;
  if ( MiTrimSection(var38, 1, a3) || (*(_BYTE *)(a1 + 18) & 7) == 6 )
    MiTrimSection(var38, 1, a3);
  if ( v34 )
  {
    v21 = (unsigned int *)(v9 + 36);
    v22 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9 + 36);
    }
    else
    {
      v23 = (unsigned __int8 *)(v9 + 39);
      do
        v24 = __ldrex(v23);
      while ( __strex(v24 | 0x80, v23) );
      __dmb(0xBu);
      if ( v24 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire(v9 + 36);
      while ( 1 )
      {
        v25 = *v21;
        if ( (*v21 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (v25 & 0x40000000) == 0 )
        {
          do
            v32 = __ldrex(v21);
          while ( v32 == v25 && __strex(v25 | 0x40000000, v21) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    MiDecrementSubsections(v34);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v9 + 36);
    }
    else
    {
      __dmb(0xBu);
      *v21 = 0;
    }
    KfLowerIrql(v22);
  }
  v18 = MiDecrementModifiedWriteCount(v9, 0);
  if ( v18 )
    MiReleaseControlAreaWaiters(v18);
  KfRaiseIrql(2);
  v19 = (unsigned __int8 *)(a1 + 15);
  do
    v20 = __ldrex(v19);
  while ( __strex(v20 | 0x80, v19) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v20 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v33 = *v16;
      __dmb(0xBu);
    }
    while ( (v33 & 0x80000000) != 0 );
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 | 0x80, v19) );
  }
  if ( (*(_BYTE *)(a1 + 18) & 7) != 6 )
    return 2;
  return 0;
}
