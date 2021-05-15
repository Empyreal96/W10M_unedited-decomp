// MiCanFileBeTruncatedInternal 
 
int __fastcall MiCanFileBeTruncatedInternal(int *a1, unsigned int *a2, int a3, int a4, _BYTE *a5)
{
  int *i; // r2
  int v6; // r5
  unsigned int v8; // r2
  int v9; // r4
  int *v10; // r2
  int v11; // r4
  int v12; // r2
  int v13; // r0
  int j; // r3
  unsigned __int64 v15; // r0
  int v16; // r1
  unsigned int v17; // r0
  unsigned int v18; // r1
  int v19; // r4
  int v20; // r1
  unsigned int v21; // r0
  unsigned int v22; // r3

  for ( i = a1; ; i = a1 )
  {
    *a5 = 17;
    if ( !i[2] )
    {
      v6 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_51AE58();
      do
        v8 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
      while ( __strex(v8 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
      __dmb(0xBu);
      if ( v8 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
      while ( 1 )
      {
        v9 = dword_632E00;
        if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632E00 & 0x40000000) == 0 )
        {
          v16 = dword_632E00 | 0x40000000;
          do
            v17 = __ldrex((unsigned int *)&dword_632E00);
          while ( v17 == v9 && __strex(v16, (unsigned int *)&dword_632E00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
      v10 = a1;
      if ( !a1[2] )
        goto LABEL_10;
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      }
      else
      {
        __dmb(0xBu);
        dword_632E00 = 0;
      }
      KfLowerIrql(v6);
      i = a1;
    }
    if ( !MmFlushImageSection(i, 1) )
      return 0;
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      ExpAcquireSpinLockExclusiveAtDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      do
        v18 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
      while ( __strex(v18 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
      __dmb(0xBu);
      if ( v18 >> 7 )
        ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
      while ( 1 )
      {
        v19 = dword_632E00;
        if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
          break;
        if ( (dword_632E00 & 0x40000000) == 0 )
        {
          v20 = dword_632E00 | 0x40000000;
          do
            v21 = __ldrex((unsigned int *)&dword_632E00);
          while ( v21 == v19 && __strex(v20, (unsigned int *)&dword_632E00) );
          __dmb(0xBu);
        }
        __dmb(0xAu);
        __yield();
      }
    }
    v10 = a1;
LABEL_10:
    v11 = *v10;
    if ( !*v10 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
      {
        ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
      }
      else
      {
        __dmb(0xBu);
        dword_632E00 = 0;
      }
      KfLowerIrql(v6);
      *a5 = 0;
      return 0;
    }
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel(v11 + 36) )
      break;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    KfLowerIrql(v6);
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
  }
  else
  {
    __dmb(0xBu);
    dword_632E00 = 0;
  }
  if ( ((*(_DWORD *)(v11 + 28) | (*(_DWORD *)(v11 + 28) >> 1)) & 1) != 0 )
    goto LABEL_24;
  if ( *(_QWORD *)(v11 + 64) <= 1ui64 )
  {
    v12 = a4;
    goto LABEL_17;
  }
  v12 = a4;
  if ( (*(_DWORD *)(v11 + 28) & 8) == 0 && !a4 )
  {
LABEL_24:
    if ( (dword_682604 & 0x10000) == 0 )
      goto LABEL_25;
LABEL_71:
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v11 + 36);
    goto LABEL_26;
  }
LABEL_17:
  if ( !*(_DWORD *)(v11 + 24) || a3 == 1 && (!*(_DWORD *)(v11 + 20) || v12 == 1) )
  {
LABEL_18:
    *a5 = v6;
    return v11;
  }
  if ( !a2 )
    goto LABEL_24;
  v13 = v11 + 80;
  if ( *(_DWORD *)(v11 + 32) )
    v13 = MiFindLastSubsection(v11, 1);
  for ( j = *(_DWORD *)(v13 + 8); j; j = *(_DWORD *)(j + 8) )
    ;
  LODWORD(v15) = MiEndingOffset();
  if ( *(_QWORD *)a2 >= v15 )
  {
    v22 = (v15 + 4095) & 0xFFFFF000;
    if ( *(_QWORD *)a2 < __PAIR64__((v15 + 4095) >> 32, v22) )
    {
      *a2 = v22;
      a2[1] = (v15 + 4095) >> 32;
    }
    goto LABEL_18;
  }
  if ( (dword_682604 & 0x10000) != 0 )
    goto LABEL_71;
LABEL_25:
  __dmb(0xBu);
  *(_DWORD *)(v11 + 36) = 0;
LABEL_26:
  KfLowerIrql(v6);
  return 0;
}
