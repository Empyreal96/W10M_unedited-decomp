// sub_7F3078 
 
void __fastcall sub_7F3078(unsigned int a1)
{
  unsigned __int8 *v1; // r5
  int v2; // r0
  int v3; // r4
  unsigned int v4; // r2

  v2 = KeAbPreAcquire(a1, 0, 0);
  v3 = v2;
  do
    v4 = __ldrex(v1);
  while ( __strex(v4 | 1, v1) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v1, v2, (unsigned int)v1);
  if ( !v3 )
    JUMPOUT(0x70BA0C);
  JUMPOUT(0x70BA0A);
}
