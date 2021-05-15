// MiCheckPageFileMapping 
 
int __fastcall MiCheckPageFileMapping(int a1)
{
  int v2; // r10
  unsigned int v4; // r1
  int v5; // r7
  _DWORD *v6; // r2
  int v7; // r1
  unsigned int v8; // r0

  if ( !*(_DWORD *)(a1 + 20) )
    return 0;
  v2 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_54E2B8();
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
      v7 = dword_632E00 | 0x40000000;
      do
        v8 = __ldrex((unsigned int *)&dword_632E00);
      while ( v8 == v5 && __strex(v7, (unsigned int *)&dword_632E00) );
      __dmb(0xBu);
    }
    __dmb(0xAu);
    __yield();
  }
  v6 = *(_DWORD **)(a1 + 20);
  if ( !v6 || !*v6 && !v6[2] )
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
    KfLowerIrql(v2);
    return 0;
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
  KfLowerIrql(v2);
  return -1073741747;
}
