// IovpCompleteRequest5 
 
int *__fastcall IovpCompleteRequest5(int *result)
{
  int v1; // r5
  int v2; // r6
  unsigned int *v3; // r4
  char v4; // r7
  unsigned int v5; // r2
  unsigned int *v6; // r2
  unsigned int v7; // r1

  v1 = *result;
  if ( *result )
  {
    v2 = result[1];
    v3 = (unsigned int *)(v2 + 4);
    v4 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v2 + 4);
    }
    else
    {
      do
        v5 = __ldrex(v3);
      while ( __strex(1u, v3) );
      __dmb(0xBu);
      if ( v5 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v2 + 4));
    }
    *(_BYTE *)(v2 + 8) = v4;
    IovpSessionDataDereference(v1);
    __dmb(0xBu);
    v6 = (unsigned int *)(v2 + 12);
    do
      v7 = __ldrex(v6);
    while ( __strex(v7 - 1, v6) );
    __dmb(0xBu);
    result = (int *)VfIrpDatabaseEntryReleaseLock(v2);
  }
  return result;
}
