// AlpcpInitializePort 
 
int __fastcall AlpcpInitializePort(int *a1, char a2, int a3)
{
  int v4; // r0
  int v5; // r6
  unsigned int v6; // r2
  int **v7; // r1
  unsigned int v8; // r1
  int v10; // r0

  a1[52] = 0;
  a1[49] = 0;
  a1[50] = (int)(a1 + 50);
  a1[51] = (int)(a1 + 50);
  a1[24] = (int)(a1 + 24);
  a1[25] = (int)(a1 + 24);
  a1[29] = (int)(a1 + 29);
  a1[30] = (int)(a1 + 29);
  a1[26] = (int)(a1 + 26);
  a1[27] = (int)(a1 + 26);
  a1[56] = (int)(a1 + 56);
  a1[57] = (int)(a1 + 56);
  a1[32] = (int)(a1 + 32);
  a1[33] = (int)(a1 + 32);
  a1[23] = 0;
  a1[28] = 0;
  a1[31] = 0;
  a1[35] = (int)(a1 + 35);
  a1[36] = (int)(a1 + 35);
  a1[34] = 0;
  a1[61] = a1[61] & 0xFFFFFDF9 | (2 * (a2 & 3 | ((a3 & 1) << 8)));
  if ( a3 )
  {
    a1[38] |= 0x40000u;
    v10 = ExAllocateFromNPagedLookasideList((int)&AlpcpNPLookasides);
    a1[37] = v10;
    if ( !v10 )
      return -1073741670;
    KeInitializeSemaphore(v10, 0, 0x7FFFFFFF);
  }
  else
  {
    a1[37] = AlpcpDummyEvent;
  }
  a1[61] |= 1u;
  v4 = KeAbPreAcquire((unsigned int)&AlpcpPortListLock, 0, 0);
  v5 = v4;
  do
    v6 = __ldrex((unsigned __int8 *)&AlpcpPortListLock);
  while ( __strex(v6 | 1, (unsigned __int8 *)&AlpcpPortListLock) );
  __dmb(0xBu);
  if ( (v6 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&AlpcpPortListLock, v4, (unsigned int)&AlpcpPortListLock);
  if ( v5 )
    *(_BYTE *)(v5 + 14) |= 1u;
  v7 = (int **)dword_621294;
  *a1 = (int)&AlpcpPortList;
  a1[1] = (int)v7;
  if ( *v7 != &AlpcpPortList )
    sub_7F45DC();
  *v7 = a1;
  dword_621294 = (int)a1;
  __dmb(0xBu);
  do
    v8 = __ldrex((unsigned int *)&AlpcpPortListLock);
  while ( __strex(v8 - 1, (unsigned int *)&AlpcpPortListLock) );
  if ( (v8 & 2) != 0 && (v8 & 4) == 0 )
    ExfTryToWakePushLock((unsigned int *)&AlpcpPortListLock);
  KeAbPostRelease((unsigned int)&AlpcpPortListLock);
  return 0;
}
