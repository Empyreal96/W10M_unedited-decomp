// MmReleaseResourceCharge 
 
unsigned int *__fastcall MmReleaseResourceCharge(unsigned int *result, char a2, int a3)
{
  int v4; // r6
  unsigned int v5; // r5

  v4 = (int)result;
  if ( (a2 & 2) != 0 )
  {
    if ( !a3 )
      return (unsigned int *)sub_549D1C();
    if ( a3 == 1 )
    {
      result = MiReturnResidentAvailable((int)result);
      do
        v5 = __ldrex(&dword_634A2C[127]);
      while ( __strex(v5 + v4, &dword_634A2C[127]) );
    }
  }
  if ( (a2 & 1) != 0 )
    result = (unsigned int *)MiReturnCommit((int)MiSystemPartition, v4);
  return result;
}
