// MmFlushImageSection 
 
int __fastcall MmFlushImageSection(int *a1, int a2)
{
  int v2; // r9
  unsigned int v4; // r2
  int v5; // r6
  int v6; // r6
  int v7; // r6
  int v8; // r4
  int v9; // r1
  unsigned int v10; // r0

  while ( 1 )
  {
    v2 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_524840();
    do
      v4 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v4 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v4 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
    while ( 1 )
    {
      v5 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        v9 = dword_632E00 | 0x40000000;
        do
          v10 = __ldrex((unsigned int *)&dword_632E00);
        while ( v10 == v5 && __strex(v9, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    if ( !a2 )
    {
      v6 = *a1;
      if ( *a1 )
      {
        if ( !ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)(v6 + 36)) )
          goto LABEL_29;
        if ( *(_DWORD *)(v6 + 24) || (*(_DWORD *)(v6 + 28) & 2) != 0 )
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
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6 + 36);
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)(v6 + 36) = 0;
          }
          KfLowerIrql(v2);
          return 0;
        }
        if ( *(_QWORD *)(v6 + 64) > 1ui64 )
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
          if ( (dword_682604 & 0x10000) != 0 )
          {
            ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6 + 36);
          }
          else
          {
            __dmb(0xBu);
            *(_DWORD *)(v6 + 36) = 0;
          }
          v8 = 0;
          goto LABEL_19;
        }
        if ( (dword_682604 & 0x10000) != 0 )
        {
          ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(v6 + 36);
        }
        else
        {
          __dmb(0xBu);
          *(_DWORD *)(v6 + 36) = 0;
        }
      }
    }
    v7 = a1[2];
    if ( !v7 )
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
      v8 = 1;
LABEL_19:
      KfLowerIrql(v2);
      return v8;
    }
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)(v7 + 36)) )
      break;
LABEL_29:
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    KfLowerIrql(v2);
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
  return MiAttemptSectionDelete(v7, v2, 0);
}
