// MiConvertPrivateToDemandZero 
 
BOOL __fastcall MiConvertPrivateToDemandZero(int a1, int *a2, unsigned int a3)
{
  BOOL result; // r0
  unsigned int v7[38]; // [sp+0h] [bp-98h] BYREF

  result = 0;
  if ( RtlCompareMemoryUlong(a2, (char *)0x1000, 0) == (char *)4096 )
  {
    if ( MiPfnCanBecomeDemandZero(
           a1,
           (int *)(MmPfnDatabase + 24 * (*(_DWORD *)((((unsigned int)a2 >> 10) & 0x3FFFFC) - 0x40000000) >> 12))) )
    {
      v7[0] = 1;
      v7[1] = a3;
      if ( !MiFreeWsleList(a1, v7, 2) )
        result = 1;
    }
  }
  return result;
}
