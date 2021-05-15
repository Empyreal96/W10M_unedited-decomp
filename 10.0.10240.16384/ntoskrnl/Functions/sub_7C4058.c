// sub_7C4058 
 
void sub_7C4058()
{
  int v0; // r4
  unsigned int *v1; // r4
  int v2; // r0
  unsigned int v3; // r2

  v1 = (unsigned int *)(v0 + 40);
  v2 = KeAbPreAcquire((unsigned int)v1, 0, 0);
  do
    v3 = __ldrex(v1);
  while ( !v3 && __strex(0x11u, v1) );
  __dmb(0xBu);
  if ( v3 )
    ExfAcquirePushLockSharedEx(v1, v2, (unsigned int)v1);
  JUMPOUT(0x6B8ADC);
}
