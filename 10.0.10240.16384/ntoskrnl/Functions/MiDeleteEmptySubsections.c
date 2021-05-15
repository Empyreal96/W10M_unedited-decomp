// MiDeleteEmptySubsections 
 
int __fastcall MiDeleteEmptySubsections(int a1)
{
  int v1; // r9
  int v2; // r10
  unsigned int v4; // r1
  int v5; // r6
  int v6; // r3
  int v7; // r6
  int v8; // r9
  int v9; // r7
  int v10; // r10
  _DWORD *v11; // r2
  __int64 v12; // kr00_8
  int v13; // r7
  unsigned int v14; // r2
  int v15; // r6
  unsigned int v16; // r0
  int v17; // r1
  unsigned int v18; // r0
  int v19; // [sp+0h] [bp-30h]
  int v20; // [sp+4h] [bp-2Ch]
  int v21; // [sp+8h] [bp-28h]

  v1 = a1;
  v2 = KfRaiseIrql(2);
  v21 = v2;
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5206E4(0x80000000);
  do
    v4 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
  while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
  __dmb(0xBu);
  if ( v4 >> 7 )
    ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
  while ( 1 )
  {
    v5 = dword_632D80;
    if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
      break;
    if ( (dword_632D80 & 0x40000000) == 0 )
    {
      do
        v16 = __ldrex((unsigned int *)&dword_632D80);
      while ( v16 == v5 && __strex(v5 | 0x40000000, (unsigned int *)&dword_632D80) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v6 = *(_DWORD *)(v1 + 888);
  if ( v6 != v1 + 888 )
  {
    do
    {
      v7 = v6 - 52;
      v8 = *(_DWORD *)(v6 - 52);
      if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v8 + 36) )
      {
        v9 = 0;
        v19 = 0;
        v20 = 0;
        if ( (*(_WORD *)(v7 + 18) & 8) != 0 )
        {
          v10 = *(_DWORD *)(v7 + 4);
          if ( (*(_DWORD *)(v8 + 28) & 0x40000000) != 0 )
          {
            v19 = MiMarkFileExtentsDeleted(v7);
            v20 = *(_DWORD *)(v7 + 28);
          }
          v11 = (_DWORD *)(v7 + 52);
          *(_DWORD *)(v7 + 4) = 0;
          v12 = *(_QWORD *)(v7 + 52);
          if ( *(_DWORD *)(v12 + 4) != v7 + 52 || *(_DWORD **)HIDWORD(v12) != v11 )
            __fastfail(3u);
          *(_DWORD *)HIDWORD(v12) = v12;
          *(_DWORD *)(v12 + 4) = HIDWORD(v12);
          *(_WORD *)(v7 + 18) &= 0xFFF7u;
          *v11 = v11;
          *(_DWORD *)(v7 + 56) = v7 + 52;
          MI_UNUSED_SUBSECTIONS_COUNT_REMOVE(v7);
          v9 = v19;
        }
        else
        {
          v10 = 0;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
        }
        else
        {
          __dmb(0xBu);
          dword_632D80 = 0;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v8 + 36);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)(v8 + 36) = 0;
        }
        KfLowerIrql(v21);
        if ( v9 )
          MiDeleteFileExtents(v9, 0, v20, 2);
        if ( v10 )
          ExFreePoolWithTag(v10, 0);
      }
      else
      {
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
        }
        else
        {
          __dmb(0xBu);
          dword_632D80 = 0;
        }
        KfLowerIrql(v2);
      }
      v13 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632D80);
      }
      else
      {
        do
          v14 = __ldrex((unsigned __int8 *)&dword_632D80 + 3);
        while ( __strex(v14 | 0x80, (unsigned __int8 *)&dword_632D80 + 3) );
        __dmb(0xBu);
        if ( v14 >> 7 )
          ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632D80);
        while ( 1 )
        {
          v15 = dword_632D80;
          if ( (dword_632D80 & 0xBFFFFFFF) == 0x80000000 )
            break;
          if ( (dword_632D80 & 0x40000000) == 0 )
          {
            v17 = dword_632D80 | 0x40000000;
            do
              v18 = __ldrex((unsigned int *)&dword_632D80);
            while ( v18 == v15 && __strex(v17, (unsigned int *)&dword_632D80) );
            __dmb(0xBu);
          }
          __dmb(0xAu);
          __yield();
        }
      }
      v1 = a1;
      v2 = v13;
      v21 = v13;
      v6 = *(_DWORD *)(a1 + 888);
    }
    while ( v6 != a1 + 888 );
  }
  *(_DWORD *)(v1 + 776) = 0;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632D80);
  }
  else
  {
    __dmb(0xBu);
    dword_632D80 = 0;
  }
  return KfLowerIrql(v2);
}
