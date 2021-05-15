// sub_80AE10 
 
void sub_80AE10()
{
  unsigned int *v0; // r8
  unsigned int v1; // r1

  __dmb(0xBu);
  do
    v1 = __ldrex(v0);
  while ( __strex(v1 - 1, v0) );
  if ( (v1 & 2) != 0 && (v1 & 4) == 0 )
    ExfTryToWakePushLock(v0);
  KeAbPostRelease((unsigned int)v0);
  JUMPOUT(0x76177E);
}
