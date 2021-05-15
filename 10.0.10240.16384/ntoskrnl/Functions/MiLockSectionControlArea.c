// MiLockSectionControlArea 
 
int __fastcall MiLockSectionControlArea(_DWORD *a1, int a2, _BYTE *a3)
{
  int v5; // r7
  unsigned int v7; // r2
  int v8; // r4
  int v9; // r4
  int v10; // r4
  int v11; // r1
  unsigned int v12; // r0

  while ( 1 )
  {
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
      return sub_53D1C8();
    do
      v7 = __ldrex((unsigned __int8 *)&dword_632E00 + 3);
    while ( __strex(v7 | 0x80, (unsigned __int8 *)&dword_632E00 + 3) );
    __dmb(0xBu);
    if ( v7 >> 7 )
      ExpWaitForSpinLockExclusiveAndAcquire((unsigned int *)&dword_632E00);
    while ( 1 )
    {
      v8 = dword_632E00;
      if ( (dword_632E00 & 0xBFFFFFFF) == 0x80000000 )
        break;
      if ( (dword_632E00 & 0x40000000) == 0 )
      {
        v11 = dword_632E00 | 0x40000000;
        do
          v12 = __ldrex((unsigned int *)&dword_632E00);
        while ( v12 == v8 && __strex(v11, (unsigned int *)&dword_632E00) );
        __dmb(0xBu);
      }
      __dmb(0xAu);
      __yield();
    }
    *a3 = v5;
    v9 = a2 == 1 ? *a1 : a1[2];
    if ( !v9 )
      break;
    if ( ExTryAcquireSpinLockExclusiveAtDpcLevel((unsigned int *)(v9 + 36)) )
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
      return v9;
    }
    v10 = (unsigned __int8)*a3;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented(&dword_632E00);
    }
    else
    {
      __dmb(0xBu);
      dword_632E00 = 0;
    }
    KfLowerIrql(v10);
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
  KfLowerIrql(v5);
  return 0;
}
