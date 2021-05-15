// MiReleaseWriteInProgressCharges 
 
int __fastcall MiReleaseWriteInProgressCharges(__int16 *a1, int a2, int a3)
{
  int v5; // r0
  int result; // r0
  unsigned int *v7; // r2
  unsigned int v8; // r4

  if ( a3 )
  {
    v5 = MiReturnCommit(a1, a2);
    if ( a1 != MiSystemPartition )
      return sub_543520(v5);
    MiReturnResidentAvailable(a2);
    v7 = &dword_634A2C[125];
    goto LABEL_5;
  }
  if ( a1 != MiSystemPartition )
  {
    v7 = (unsigned int *)(a1 + 1920);
    do
LABEL_5:
      result = __ldrex(v7);
    while ( __strex(result + a2, v7) );
    return result;
  }
  MiReturnResidentAvailable(a2);
  do
  {
    v8 = __ldrex(&dword_634A2C[123]);
    result = v8 + a2;
  }
  while ( __strex(v8 + a2, &dword_634A2C[123]) );
  return result;
}
