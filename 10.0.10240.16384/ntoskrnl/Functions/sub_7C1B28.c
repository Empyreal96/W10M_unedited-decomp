// sub_7C1B28 
 
void sub_7C1B28()
{
  int v0; // r7
  unsigned int *v1; // r4
  unsigned int v2; // r1

  v1 = (unsigned int *)(v0 + 168);
  __dmb(0xBu);
  do
    v2 = __ldrex(v1);
  while ( __strex(v2 - 1, v1) );
  if ( (v2 & 2) != 0 && (v2 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v0 + 168));
  KeAbPostRelease(v0 + 168);
  JUMPOUT(0x6AA40A);
}
