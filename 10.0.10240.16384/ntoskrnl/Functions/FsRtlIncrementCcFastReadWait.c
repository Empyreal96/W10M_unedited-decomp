// FsRtlIncrementCcFastReadWait 
 
void FsRtlIncrementCcFastReadWait()
{
  unsigned int *v0; // r2
  unsigned int v1; // r1

  v0 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3004);
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 + 1, v0) );
}
