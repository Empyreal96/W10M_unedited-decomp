// MiReturnFaultCharges 
 
int __fastcall MiReturnFaultCharges(__int16 *a1, int a2, char a3)
{
  int result; // r0
  unsigned int v7; // r6

  if ( a1 != MiSystemPartition )
    return sub_526354();
  result = MiReturnResidentAvailable(a2);
  do
    v7 = __ldrex(&dword_634A2C[77]);
  while ( __strex(v7 + a2, &dword_634A2C[77]) );
  if ( (a3 & 1) != 0 )
    result = MiReturnCommit(a1, a2);
  return result;
}
