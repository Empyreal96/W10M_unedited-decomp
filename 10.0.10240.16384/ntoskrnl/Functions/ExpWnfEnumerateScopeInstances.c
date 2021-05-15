// ExpWnfEnumerateScopeInstances 
 
int __fastcall ExpWnfEnumerateScopeInstances(int a1, int a2, int a3, _DWORD *a4)
{
  int v6; // r4
  int v7; // r0
  int v8; // r3
  unsigned int *v9; // r6
  _DWORD *v10; // r8
  _DWORD *v11; // r5
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r2
  _DWORD *v15; // r3
  unsigned int *v16; // r0
  unsigned int v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r2
  unsigned int *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  int v24[6]; // [sp+0h] [bp-18h] BYREF

  v24[0] = (int)a4;
  PsGetMonitorContextServerSilo(ExpWnfSiloMonitor, -1, v24);
  v6 = *(_DWORD *)v24[0];
  v7 = PsDereferenceMonitorContextServerSilo(v24[0]);
  if ( !v6 )
    return sub_7BFF00(v7);
  v8 = v6 + 12 * a1;
  v9 = (unsigned int *)(v8 + 8);
  v10 = (_DWORD *)(v8 + 12);
  v11 = 0;
  v12 = KeAbPreAcquire(v8 + 8, 0, 0);
  v13 = v12;
  do
    v14 = __ldrex(v9);
  while ( !v14 && __strex(0x11u, v9) );
  __dmb(0xBu);
  if ( v14 )
    ExfAcquirePushLockSharedEx(v9, v12, (unsigned int)v9);
  if ( v13 )
    *(_BYTE *)(v13 + 14) |= 1u;
  if ( a2 )
    v15 = *(_DWORD **)(a2 + 20);
  else
    v15 = 0;
  if ( !v15 )
    v15 = (_DWORD *)*v10;
  while ( v15 != v10 )
  {
    v11 = v15 - 5;
    v16 = v15 - 4;
    __pld(v15 - 4);
    v17 = *(v15 - 4) & 0xFFFFFFFE;
    do
      v18 = __ldrex(v16);
    while ( v18 == v17 && __strex(v17 + 2, v16) );
    __dmb(0xBu);
    if ( v18 == v17 || ExfAcquireRundownProtection(v16) )
      break;
    v15 = (_DWORD *)v11[5];
    v11 = 0;
  }
  __dmb(0xBu);
  do
    v19 = __ldrex(v9);
  while ( v19 == 17 && __strex(0, v9) );
  if ( v19 != 17 )
    ExfReleasePushLockShared(v9);
  KeAbPostRelease((unsigned int)v9);
  if ( a2 )
  {
    v20 = (unsigned int *)(a2 + 4);
    __pld((void *)(a2 + 4));
    v21 = *(_DWORD *)(a2 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v22 = __ldrex(v20);
    while ( v22 == v21 && __strex(v21 - 2, v20) );
    if ( v22 != v21 )
      ExfReleaseRundownProtection((unsigned __int8 *)v20);
  }
  return (int)v11;
}
