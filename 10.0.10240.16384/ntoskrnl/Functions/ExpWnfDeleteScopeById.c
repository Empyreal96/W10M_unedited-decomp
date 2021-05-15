// ExpWnfDeleteScopeById 
 
int __fastcall ExpWnfDeleteScopeById(int a1, int a2, int a3, int a4)
{
  int v6; // r4
  int result; // r0
  int v8; // r6
  unsigned __int8 *v9; // r5
  int v10; // r0
  unsigned int v11; // r2
  int v12; // r0
  _DWORD *v13; // r4
  unsigned int v14; // r1
  int v15; // r2
  __int64 v16; // r0
  int v17[6]; // [sp+0h] [bp-18h] BYREF

  v17[0] = a3;
  v17[1] = a4;
  PsGetMonitorContextServerSilo(ExpWnfSiloMonitor, -1, v17);
  v6 = *(_DWORD *)v17[0];
  result = PsDereferenceMonitorContextServerSilo(v17[0]);
  if ( v6 )
  {
    v8 = v6 + 12 * a1;
    v9 = (unsigned __int8 *)(v8 + 8);
    v10 = KeAbPreAcquire(v8 + 8, 0, 0);
    do
      v11 = __ldrex(v9);
    while ( __strex(v11 | 1, v9) );
    __dmb(0xBu);
    if ( (v11 & 1) != 0 )
    {
      result = sub_7C0578(v10);
    }
    else
    {
      if ( v10 )
        *(_BYTE *)(v10 + 14) |= 1u;
      v12 = ExpWnfFindScopeInstance(v8 + 12, a2, 4);
      v13 = (_DWORD *)v12;
      if ( v12 )
      {
        v15 = v12 + 20;
        v16 = *(_QWORD *)(v12 + 20);
        if ( *(_DWORD **)(v16 + 4) != v13 + 5 || *(_DWORD *)HIDWORD(v16) != v15 )
          __fastfail(3u);
        *(_DWORD *)HIDWORD(v16) = v16;
        *(_DWORD *)(v16 + 4) = HIDWORD(v16);
        v13[5] = 0;
      }
      __dmb(0xBu);
      do
        v14 = __ldrex((unsigned int *)v9);
      while ( __strex(v14 - 1, (unsigned int *)v9) );
      if ( (v14 & 2) != 0 && (v14 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)(v8 + 8));
      result = KeAbPostRelease(v8 + 8);
      if ( v13 )
        result = ExpWnfFreeScopeInstance(v13, 1);
    }
  }
  return result;
}
