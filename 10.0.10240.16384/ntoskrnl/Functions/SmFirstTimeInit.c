// SmFirstTimeInit 
 
int SmFirstTimeInit()
{
  unsigned int v0; // r2
  int v1; // r0
  unsigned int v2; // r1

  v0 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v0 + 308);
  v1 = KeAbPreAcquire((unsigned int)byte_636CB0, 0, 0);
  do
    v2 = __ldrex(byte_636CB0);
  while ( __strex(v2 | 1, byte_636CB0) );
  __dmb(0xBu);
  if ( (v2 & 1) == 0 )
    JUMPOUT(0x7BF678);
  return sub_7BF66C(v1);
}
