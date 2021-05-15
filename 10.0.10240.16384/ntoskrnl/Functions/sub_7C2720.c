// sub_7C2720 
 
void sub_7C2720()
{
  unsigned __int8 *v0; // r4
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r2
  int v4; // r3
  unsigned int v5; // r1
  _DWORD *v6; // r7
  int v7; // r9

  if ( (PerfGlobalGroupMask[0] & 1) != 0 )
    EtwTraceProcessTerminate((int)v6);
  KeSetProcessSchedulingGroup((int)v6, 0);
  v0 = (unsigned __int8 *)(v6 + 42);
  v1 = KeAbPreAcquire((unsigned int)(v6 + 42), 0, 0);
  v2 = v1;
  do
    v3 = __ldrex(v0);
  while ( __strex(v3 | 1, v0) );
  __dmb(0xBu);
  if ( (v3 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(v6 + 42, v1, (unsigned int)(v6 + 42));
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  v4 = v6[101];
  __dmb(0xBu);
  if ( v4 && (v6[158] == 259 || v7 != -1073741749) )
    v6[158] = v7;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)v0);
  while ( __strex(v5 - 1, (unsigned int *)v0) );
  if ( (v5 & 2) != 0 && (v5 & 4) == 0 )
    ExfTryToWakePushLock(v6 + 42);
  KeAbPostRelease((unsigned int)(v6 + 42));
  JUMPOUT(0x6AD550);
}
