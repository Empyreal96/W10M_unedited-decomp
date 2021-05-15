// CcAllocateInitializeBcb 
 
int __fastcall CcAllocateInitializeBcb(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _BYTE *v8; // r0
  _BYTE *v9; // r5
  __int64 v11; // kr00_8
  __int64 v12; // kr08_8
  unsigned __int8 *v13; // r4
  int v14; // r0
  int v15; // r7
  unsigned int v16; // r2
  _DWORD *v17; // r0
  _BYTE *v18; // r2
  int v19; // r1
  unsigned int v20; // r0
  unsigned int v21; // r2

  v8 = (_BYTE *)ExAllocatePoolWithTag(512, 136, 1665295171);
  v9 = v8;
  if ( !v8 )
    return sub_54A648();
  memset(v8, 0, 136);
  *(_WORD *)v9 = 765;
  *((_DWORD *)v9 + 2) = *a3;
  *((_DWORD *)v9 + 3) = a3[1];
  *((_DWORD *)v9 + 1) = *a4;
  v11 = *(_QWORD *)a3;
  v12 = *(_QWORD *)a4;
  *((_DWORD *)v9 + 28) = a1;
  *((_DWORD *)v9 + 6) = v12 + v11;
  ++*((_DWORD *)v9 + 13);
  *((_DWORD *)v9 + 7) = (unsigned __int64)(v12 + v11) >> 32;
  ExInitializeResourceLite((int)(v9 + 56));
  v13 = (unsigned __int8 *)(a1 + 72);
  v14 = KeAbPreAcquire(a1 + 72, 0, 0);
  v15 = v14;
  do
    v16 = __ldrex(v13);
  while ( __strex(v16 | 1, v13) );
  __dmb(0xBu);
  if ( (v16 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 72), v14, a1 + 72);
  if ( v15 )
    *(_BYTE *)(v15 + 14) |= 1u;
  v17 = *(_DWORD **)(a2 + 20);
  v18 = v9 + 16;
  *((_DWORD *)v9 + 4) = a2 + 16;
  *((_DWORD *)v9 + 5) = v17;
  if ( *v17 != a2 + 16 )
    __fastfail(3u);
  *v17 = v18;
  *(_DWORD *)(a2 + 20) = v18;
  if ( *(__int64 *)(a1 + 24) > 0x2000000 && (*(_DWORD *)(a1 + 96) & 0x200) != 0 )
    CcAdjustVacbLevelLockCount(a1, a2 + 16, *a3, a3[1]);
  __pld(v13);
  v19 = *(_DWORD *)v13;
  if ( (*(_DWORD *)v13 & 0xFFFFFFF0) > 0x10 )
    v20 = v19 - 16;
  else
    v20 = 0;
  if ( (v19 & 2) != 0 )
    goto LABEL_22;
  __dmb(0xBu);
  do
    v21 = __ldrex((unsigned int *)v13);
  while ( v21 == v19 && __strex(v20, (unsigned int *)v13) );
  if ( v21 != v19 )
LABEL_22:
    ExfReleasePushLock((_DWORD *)(a1 + 72), v19);
  KeAbPostRelease(a1 + 72);
  if ( (*(_DWORD *)(a1 + 96) & 2) != 0 )
    ExDisableResourceBoostLite(v9 + 56);
  return (int)v9;
}
