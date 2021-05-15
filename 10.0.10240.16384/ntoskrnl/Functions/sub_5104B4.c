// sub_5104B4 
 
void sub_5104B4()
{
  int v0; // r8
  unsigned int *v1; // r2
  unsigned int v2; // r0

  MiReturnResidentAvailable(1);
  v1 = (unsigned int *)(v0 + 8128);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 + 1, v1) );
  MiReturnCommit((int)MiSystemPartition, 1);
  JUMPOUT(0x42759E);
}
