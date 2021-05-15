// MiReferencePfBackedSection 
 
int __fastcall MiReferencePfBackedSection(int a1)
{
  int v2; // r9
  int v4; // r4
  unsigned int v5; // r1
  unsigned int v6; // r0
  _DWORD *v7; // r4
  int v8; // r0
  int v9; // r8
  unsigned int *v10; // r5
  int v11; // r9
  unsigned __int8 *v12; // r3
  unsigned int v13; // r1
  unsigned int v14; // r0
  _DWORD *v15; // r5
  unsigned int v16; // r4
  unsigned int v17; // r1
  unsigned int v18; // r1
  int v19; // [sp+0h] [bp-28h]
  int v20; // [sp+4h] [bp-24h]

  v2 = 0;
  v20 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_51084C();
  v4 = dword_632EBC & 0x7FFFFFFF;
  v5 = (dword_632EBC & 0x7FFFFFFF) + 1;
  do
    v6 = __ldrex((unsigned int *)&dword_632EBC);
  while ( v6 == v4 && __strex(v5, (unsigned int *)&dword_632EBC) );
  __dmb(0xBu);
  if ( v6 != v4 )
    ExpWaitForSpinLockSharedAndAcquire(&dword_632EBC, v5);
  v7 = (_DWORD *)dword_632EB8;
  if ( dword_632EB8 )
  {
    do
    {
      v8 = MiPagefileSectionCompare(a1, v7);
      if ( v8 < 0 )
      {
        v7 = (_DWORD *)*v7;
      }
      else
      {
        if ( v8 <= 0 )
          break;
        v7 = (_DWORD *)v7[1];
      }
    }
    while ( v7 );
    if ( v7 )
    {
      v9 = *(v7 - 10);
      v10 = (unsigned int *)(v9 + 36);
      v11 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(v9 + 36);
      }
      else
      {
        v12 = (unsigned __int8 *)(v9 + 39);
        do
          v13 = __ldrex(v12);
        while ( __strex(v13 | 0x80, v12) );
        __dmb(0xBu);
        if ( v13 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire(v9 + 36);
        while ( 1 )
        {
          v14 = *v10;
          if ( (*v10 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (v14 & 0x40000000) == 0 )
          {
            do
              v18 = __ldrex(v10);
            while ( v18 == v14 && __strex(v14 | 0x40000000, v10) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      if ( ((*(_DWORD *)(v9 + 28) | (*(_DWORD *)(v9 + 28) >> 1)) & 1) == 0 )
      {
        v19 = MiBuildWakeList(v9, 4);
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
        KfLowerIrql(v11);
        v2 = v19;
        v15 = v7 - 10;
        goto LABEL_25;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v10);
      }
      else
      {
        __dmb(0xBu);
        *v10 = 0;
      }
      KfLowerIrql(v11);
      v2 = 0;
    }
  }
  v15 = 0;
LABEL_25:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ((void (__fastcall *)(int *))ExpReleaseSpinLockSharedFromDpcLevelInstrumented)(&dword_632EBC);
  }
  else
  {
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)&dword_632EBC);
    while ( __strex(v16 & 0xBFFFFFFF, (unsigned int *)&dword_632EBC) );
    __dmb(0xBu);
    do
      v17 = __ldrex((unsigned int *)&dword_632EBC);
    while ( __strex(v17 - 1, (unsigned int *)&dword_632EBC) );
  }
  KfLowerIrql(v20);
  if ( v2 )
    MiReleaseControlAreaWaiters(v2);
  return (int)v15;
}
