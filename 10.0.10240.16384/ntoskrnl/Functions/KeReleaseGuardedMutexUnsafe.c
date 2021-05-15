// KeReleaseGuardedMutexUnsafe 
 
int __fastcall KeReleaseGuardedMutexUnsafe(unsigned int *a1)
{
  unsigned int v1; // r1

  a1[1] = 0;
  __dmb(0xBu);
  do
    v1 = __ldrex(a1);
  while ( !v1 && __strex(1u, a1) );
  if ( !v1 )
    JUMPOUT(0x50AAF2);
  return sub_50AAEC(a1, v1, 1);
}
