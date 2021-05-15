// KeReleaseGuardedMutex 
 
unsigned int __fastcall KeReleaseGuardedMutex(unsigned int *a1)
{
  unsigned int v2; // r5
  unsigned int v3; // r1

  v2 = a1[7];
  a1[1] = 0;
  __dmb(0xBu);
  do
    v3 = __ldrex(a1);
  while ( !v3 && __strex(1u, a1) );
  if ( v3 )
    ExpReleaseFastMutexContended(a1, v3);
  KfLowerIrql((unsigned __int8)v2);
  return KeAbPostRelease((unsigned int)a1);
}
