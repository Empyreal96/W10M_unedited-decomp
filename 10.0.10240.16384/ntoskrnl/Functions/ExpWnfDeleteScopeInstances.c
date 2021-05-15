// ExpWnfDeleteScopeInstances 
 
unsigned int __fastcall ExpWnfDeleteScopeInstances(int a1, int a2, int a3, _DWORD *a4)
{
  int v5; // r7
  unsigned int result; // r0
  int v7; // r3
  unsigned __int8 *v8; // r5
  _DWORD **v9; // r4
  int v10; // r0
  int v11; // r6
  unsigned int v12; // r2
  _DWORD *v13; // r1
  __int64 v14; // r2
  _DWORD *v15; // r1
  unsigned int v16; // r1
  int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = (int)a4;
  PsGetMonitorContextServerSilo(ExpWnfSiloMonitor, -1, v17);
  v5 = *(_DWORD *)v17[0];
  result = PsDereferenceMonitorContextServerSilo(v17[0]);
  if ( v5 )
  {
    v7 = v5 + 12 * a1;
    v8 = (unsigned __int8 *)(v7 + 8);
    v9 = (_DWORD **)(v7 + 12);
    v10 = KeAbPreAcquire(v7 + 8, 0, 0);
    v11 = v10;
    do
      v12 = __ldrex(v8);
    while ( __strex(v12 | 1, v8) );
    __dmb(0xBu);
    if ( (v12 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx(v8, v10, (unsigned int)v8);
    if ( v11 )
      *(_BYTE *)(v11 + 14) |= 1u;
    LODWORD(v14) = *v9;
    HIDWORD(v14) = (*v9)[1];
    v13 = (_DWORD *)**v9;
    if ( v14 != __PAIR64__((unsigned int)v9, v13[1]) )
      __fastfail(3u);
    *v9 = v13;
    for ( v13[1] = v9; (_DWORD **)v14 != v9; v15[1] = v9 )
    {
      *(_DWORD *)v14 = 0;
      if ( !a1 )
        *(_DWORD *)(v5 + 4) = 0;
      ExpWnfFreeScopeInstance((_DWORD *)(v14 - 20), 1);
      LODWORD(v14) = *v9;
      HIDWORD(v14) = (*v9)[1];
      v15 = (_DWORD *)**v9;
      if ( v14 != __PAIR64__((unsigned int)v9, v15[1]) )
        __fastfail(3u);
      *v9 = v15;
    }
    __dmb(0xBu);
    do
      v16 = __ldrex((unsigned int *)v8);
    while ( __strex(v16 - 1, (unsigned int *)v8) );
    if ( (v16 & 2) != 0 && (v16 & 4) == 0 )
      ExfTryToWakePushLock((unsigned int *)v8);
    result = KeAbPostRelease((unsigned int)v8);
  }
  return result;
}
