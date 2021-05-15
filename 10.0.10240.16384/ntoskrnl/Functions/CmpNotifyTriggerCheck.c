// CmpNotifyTriggerCheck 
 
int __fastcall CmpNotifyTriggerCheck(int a1, int a2, int a3)
{
  unsigned int v6; // r8
  int v7; // r0
  unsigned int v8; // r4
  int result; // r0
  unsigned int v10; // r1
  unsigned int v11; // r1

  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v7 = KeAbPreAcquire((unsigned int)&CmpPostLock, 0, 0);
  do
    v8 = __ldrex((unsigned __int8 *)&CmpPostLock);
  while ( __strex(v8 & 0xFE, (unsigned __int8 *)&CmpPostLock) );
  __dmb(0xBu);
  if ( (v8 & 1) == 0 )
    return sub_7E7F70(v7);
  if ( v7 )
    *(_BYTE *)(v7 + 14) |= 1u;
  dword_632444 = v6;
  if ( *(_DWORD *)(a1 + 8) != a1 + 8 && *(_WORD *)(*(_DWORD *)(a1 + 8) + 28) == 3 )
  {
    dword_632444 = 0;
    __dmb(0xBu);
    do
      v11 = __ldrex((unsigned int *)&CmpPostLock);
    while ( !v11 && __strex(1u, (unsigned int *)&CmpPostLock) );
    if ( v11 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v11);
    KeAbPostRelease((unsigned int)&CmpPostLock);
    result = 1;
  }
  else
  {
    dword_632444 = 0;
    __dmb(0xBu);
    do
      v10 = __ldrex((unsigned int *)&CmpPostLock);
    while ( !v10 && __strex(1u, (unsigned int *)&CmpPostLock) );
    if ( v10 )
      ExpReleaseFastMutexContended((unsigned int *)&CmpPostLock, v10);
    KeAbPostRelease((unsigned int)&CmpPostLock);
    result = CmpCheckNotifyAccess(a1, a2, a3);
  }
  return result;
}
