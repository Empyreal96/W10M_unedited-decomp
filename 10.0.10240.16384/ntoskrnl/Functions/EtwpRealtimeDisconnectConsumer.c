// EtwpRealtimeDisconnectConsumer 
 
int __fastcall EtwpRealtimeDisconnectConsumer(int a1)
{
  int v2; // r0
  _DWORD *v3; // r7
  unsigned __int8 *v5; // r4
  int v6; // r0
  int v7; // r5
  unsigned int v8; // r2
  int v9; // r1
  unsigned int v10; // r0
  unsigned int v11; // r2
  int v12; // r4

  if ( (*(_BYTE *)(a1 + 50) & 4) != 0 || (*(_BYTE *)(a1 + 50) & 1) != 0 )
    return -2147483611;
  v2 = EtwpAcquireLoggerContextByLoggerId(*(unsigned __int16 *)(a1 + 48), 1);
  v3 = (_DWORD *)v2;
  if ( !v2 )
    return sub_7EB470();
  v5 = (unsigned __int8 *)(v2 + 504);
  v6 = KeAbPreAcquire(v2 + 504, 0, 0);
  v7 = v6;
  do
    v8 = __ldrex(v5);
  while ( __strex(v8 | 1, v5) );
  __dmb(0xBu);
  if ( (v8 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v5, v6, (unsigned int)v5);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  v3[67] = a1;
  __pld(v5);
  v9 = *(_DWORD *)v5;
  if ( (*(_DWORD *)v5 & 0xFFFFFFF0) > 0x10 )
    v10 = v9 - 16;
  else
    v10 = 0;
  if ( (v9 & 2) != 0 )
    goto LABEL_22;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)v5);
  while ( v11 == v9 && __strex(v10, (unsigned int *)v5) );
  if ( v11 != v9 )
LABEL_22:
    ExfReleasePushLock(v5, v9);
  KeAbPostRelease((unsigned int)v5);
  v12 = EtwpSynchronizeWithLogger(v3, 16);
  EtwpSynchronizeWithLogger(v3, 4);
  EtwpReleaseLoggerContext(v3, 1);
  return v12;
}
