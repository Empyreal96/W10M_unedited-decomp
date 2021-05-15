// sub_7F8158 
 
void sub_7F8158()
{
  int v0; // r4
  int v1; // r10
  int v2; // r1
  unsigned __int8 *v3; // r0
  unsigned int v4; // r2
  int v5; // lr
  unsigned int v6; // r1
  int v7; // [sp+18h] [bp+18h]

  v2 = KeAbPreAcquire(v0 + 208, 0, 0);
  v7 = v2;
  v3 = (unsigned __int8 *)(v0 + 208);
  do
    v4 = __ldrex(v3);
  while ( __strex(v4 | 1, v3) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
  {
    ExfAcquirePushLockExclusiveEx(v3, v2, v0 + 208);
    v2 = v7;
    v3 = (unsigned __int8 *)(v0 + 208);
  }
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v5 = *(_DWORD *)(v0 + 240);
  if ( v5 && v1 == *(_DWORD *)(v5 + 16) )
  {
    KeSetEvent(*(_DWORD *)(v0 + 240), 0, 0);
    v3 = (unsigned __int8 *)(v0 + 208);
  }
  __dmb(0xBu);
  do
    v6 = __ldrex((unsigned int *)v3);
  while ( __strex(v6 - 1, (unsigned int *)v3) );
  if ( (v6 & 2) != 0 && (v6 & 4) == 0 )
  {
    ExfTryToWakePushLock((unsigned int *)v3);
    v3 = (unsigned __int8 *)(v0 + 208);
  }
  KeAbPostRelease((unsigned int)v3);
  JUMPOUT(0x721B72);
}
