// sub_52E354 
 
void sub_52E354()
{
  int v0; // r4
  int v1; // r7
  unsigned __int8 *v2; // r10
  int v3; // r1
  unsigned int v4; // r2
  int v5; // r0
  unsigned int v6; // r1
  int v7; // [sp+8h] [bp+8h]

  v2 = (unsigned __int8 *)(v0 + 208);
  v3 = KeAbPreAcquire(v0 + 208, 0, 0);
  v7 = v3;
  do
    v4 = __ldrex(v2);
  while ( __strex(v4 | 1, v2) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
  {
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v0 + 208), v3, v0 + 208);
    v3 = v7;
  }
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = *(_DWORD *)(v0 + 240);
  if ( v5 && v1 == *(_DWORD *)(v5 + 16) )
    KeSetEvent(v5, 0, 0);
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)v2);
  while ( __strex(v6 - 1, (unsigned int *)v2) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)(v0 + 208));
  KeAbPostRelease(v0 + 208);
  JUMPOUT(0x47BBBC);
}
