// IoReleaseRemoveLockAndWaitEx 
 
int __fastcall IoReleaseRemoveLockAndWaitEx(int result, int a2, int a3)
{
  int v3; // r6
  unsigned int *v4; // r5
  unsigned int v5; // r4
  unsigned int v6; // r4
  signed int v7; // r4
  unsigned int *v8; // r4
  unsigned int v9; // r2
  signed int v10; // r2
  unsigned int v11; // r2

  v3 = result;
  *(_BYTE *)result = 1;
  __dmb(0xBu);
  v4 = (unsigned int *)(result + 4);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 - 1, v4) );
  __dmb(0xBu);
  do
  {
    v6 = __ldrex(v4);
    v7 = v6 - 1;
  }
  while ( __strex(v7, v4) );
  __dmb(0xBu);
  if ( v7 > 0 )
    return sub_528D78();
  if ( a3 == 88 )
  {
    __dmb(0xBu);
    v8 = (unsigned int *)(result + 56);
    do
    {
      v9 = __ldrex(v8);
      v10 = v9 - 1;
    }
    while ( __strex(v10, v8) );
    __dmb(0xBu);
    if ( v10 < 0 )
    {
      if ( a2 != *(_DWORD *)(*(_DWORD *)(result + 80) + 4)
        && ((MmVerifierData & 0x800) == 0 || !VfRemLockReportBadReleaseAndWaitTag(result, a2)) )
      {
        __dmb(0xBu);
        do
          v11 = __ldrex(v8);
        while ( __strex(v11 + 1, v8) );
        __dmb(0xBu);
      }
      result = ExFreePoolWithTag(*(_DWORD *)(v3 + 80), 0);
      *(_DWORD *)(v3 + 80) = MmBadPointer;
    }
  }
  return result;
}
