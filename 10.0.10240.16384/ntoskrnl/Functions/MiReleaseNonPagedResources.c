// MiReleaseNonPagedResources 
 
int __fastcall MiReleaseNonPagedResources(__int16 *a1, int a2)
{
  unsigned int v4; // r0
  int result; // r0
  unsigned int v6; // r4

  v4 = MiReturnCommit((int)a1, a2);
  if ( a1 != MiSystemPartition )
    return sub_54E5D8(v4);
  MiReturnResidentAvailable(a2);
  do
  {
    v6 = __ldrex(&dword_634A2C[70]);
    result = v6 + a2;
  }
  while ( __strex(v6 + a2, &dword_634A2C[70]) );
  return result;
}
