// AlpcpDisconnectPort 
 
int __fastcall AlpcpDisconnectPort(int a1)
{
  int v1; // r7
  unsigned __int8 *v2; // r5
  int v3; // r0
  int v4; // r4
  unsigned int v5; // r2

  v1 = *(_DWORD *)(a1 + 8);
  v2 = (unsigned __int8 *)(v1 - 4);
  v3 = KeAbPreAcquire(v1 - 4, 0, 0);
  v4 = v3;
  do
    v5 = __ldrex(v2);
  while ( __strex(v5 | 1, v2) );
  __dmb(0xBu);
  if ( (v5 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(v1 - 4), v3, v1 - 4);
  if ( v4 )
    *(_BYTE *)(v4 + 14) |= 1u;
  return sub_80711C();
}
