// sub_804284 
 
void sub_804284()
{
  int v0; // r5
  unsigned int *v1; // r4
  unsigned int v2; // r1

  v1 = *(unsigned int **)(v0 + 1868);
  v1[1] = 0;
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( !v2 && __strex(1u, v1) );
  if ( v2 )
    ExpReleaseFastMutexContended(v1, v2);
  KeAbPostRelease((unsigned int)v1);
  JUMPOUT(0x749C64);
}
