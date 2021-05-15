// sub_80F79C 
 
void sub_80F79C()
{
  int v0; // r9
  unsigned int *v1; // r2
  unsigned int v2; // r0

  MiReturnCommit((int)MiSystemPartition, 1);
  MiReturnResidentAvailable(1);
  v1 = (unsigned int *)(v0 + 8288);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  JUMPOUT(0x79A4B4);
}
