// ExReleaseFastMutexUnsafe 
 
int __fastcall ExReleaseFastMutexUnsafe(unsigned int *a1)
{
  unsigned int v2; // r1

  a1[1] = 0;
  __dmb(0xBu);
  do
    v2 = __ldrex(a1);
  while ( !v2 && __strex(1u, a1) );
  if ( v2 )
    ExpReleaseFastMutexContended(a1, v2, 1);
  return KeAbPostRelease(a1);
}
