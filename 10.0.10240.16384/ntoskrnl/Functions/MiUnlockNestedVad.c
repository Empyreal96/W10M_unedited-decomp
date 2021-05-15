// MiUnlockNestedVad 
 
unsigned int __fastcall MiUnlockNestedVad(int a1)
{
  unsigned int *v1; // r4
  unsigned int v2; // r1

  v1 = (unsigned int *)(a1 + 24);
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 - 1, v1) );
  if ( (v2 & 2) != 0 && (v2 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(a1 + 24));
  return KeAbPostRelease((unsigned int)v1);
}
