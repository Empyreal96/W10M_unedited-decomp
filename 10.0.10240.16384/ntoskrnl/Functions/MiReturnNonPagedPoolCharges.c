// MiReturnNonPagedPoolCharges 
 
int *__fastcall MiReturnNonPagedPoolCharges(int *result)
{
  int *v1; // r8
  int v2; // r2
  unsigned int v3; // r5
  int v4; // r4

  v1 = result;
  if ( dword_640714 )
  {
    MiReturnResidentAvailable(*result);
    v2 = *v1;
    do
      v3 = __ldrex(&dword_634A2C[33]);
    while ( __strex(v3 + v2, &dword_634A2C[33]) );
    MiReturnCommit((int)MiSystemPartition, v1[3] - v1[1]);
    v4 = -v1[3];
    do
      result = (int *)__ldrex((unsigned int *)algn_634D8C);
    while ( __strex((unsigned int)result + v4, (unsigned int *)algn_634D8C) );
  }
  return result;
}
