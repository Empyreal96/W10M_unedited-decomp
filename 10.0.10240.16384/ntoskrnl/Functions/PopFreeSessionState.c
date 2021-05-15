// PopFreeSessionState 
 
unsigned int __fastcall PopFreeSessionState(int a1)
{
  int v2; // r5
  int v3; // r6
  unsigned int v4; // r2
  char *v5; // r5
  int v6; // r6
  unsigned __int8 v7; // r5
  unsigned int v8; // r1

  v2 = KeAbPreAcquire((unsigned int)&PopSettingLock, 0, 0);
  v3 = KfRaiseIrql(1);
  do
    v4 = __ldrex((unsigned __int8 *)&PopSettingLock);
  while ( __strex(v4 & 0xFE, (unsigned __int8 *)&PopSettingLock) );
  __dmb(0xBu);
  if ( (v4 & 1) == 0 )
    ExpAcquireFastMutexContended((int)&PopSettingLock, v2);
  if ( v2 )
    *(_BYTE *)(v2 + 14) |= 1u;
  dword_61F324 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v5 = (char *)&PopSessionSpecificLists;
  dword_61F33C = v3;
  v6 = 2;
  do
  {
    PopFreeSessionStateInList(v5, a1);
    v5 += 8;
    --v6;
  }
  while ( v6 );
  dword_61F324 = 0;
  v7 = dword_61F33C;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&PopSettingLock);
  while ( !v8 && __strex(1u, (unsigned int *)&PopSettingLock) );
  if ( v8 )
    ExpReleaseFastMutexContended((unsigned int *)&PopSettingLock, v8);
  KfLowerIrql(v7);
  return KeAbPostRelease((unsigned int)&PopSettingLock);
}
