// MiMarkBootGuardPage 
 
unsigned int *__fastcall MiMarkBootGuardPage(unsigned int *result)
{
  int v1; // r6
  int v2; // r5
  int v3; // r7
  int v4; // r5
  unsigned int v5; // r4
  int v6; // r3

  if ( (*result & 2) != 0 )
  {
    v1 = MmPfnDatabase;
    v2 = MmPfnDatabase + 24 * (*result >> 12);
    v3 = 3 * (*(_DWORD *)(v2 + 20) & 0xFFFFF);
    if ( (unsigned int)(result + 0x10000000) > 0x3FFFFF )
    {
      *result = 0;
    }
    else
    {
      __dmb(0xBu);
      *result = 0;
      if ( (unsigned int)result >= 0xC0300000 )
        return (unsigned int *)sub_7D0984();
    }
    KeFlushSingleTb((_DWORD)result << 10, 1);
    v4 = MiLockAndDecrementShareCount(v2, 1);
    MiLockAndDecrementShareCount(v1 + 8 * v3, 0);
    result = MiReturnResidentAvailable(1);
    do
      v5 = __ldrex(&dword_634A2C[55]);
    while ( __strex(v5 + 1, &dword_634A2C[55]) );
    if ( v4 != 3 )
    {
      result = (unsigned int *)MiReturnCommit((int)MiSystemPartition, 1);
      v6 = dword_634D90 - 1;
      __dmb(0xBu);
      dword_634D90 = v6;
    }
  }
  return result;
}
