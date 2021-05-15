// ExpSaAllocatorFree 
 
// local variable allocation has failed, the output may be wrong!
unsigned int __fastcall ExpSaAllocatorFree(unsigned int a1, _DWORD *a2, int a3, int a4)
{
  BOOL v7; // r7
  int v8; // r0
  int v9; // r8
  unsigned int v10; // r4
  int v11; // r1 OVERLAPPED
  _DWORD *v12; // r2 OVERLAPPED
  _DWORD *v13; // r1
  int v14; // r0
  int v15; // r4
  unsigned int v16; // r2
  unsigned int *v17; // r2
  unsigned int v18; // r0
  int v19; // r3
  unsigned int v20; // r2
  unsigned int v21; // r1
  unsigned int v22; // r2
  unsigned int varg_r0; // [sp+28h] [bp+8h]
  _DWORD *varg_r1; // [sp+2Ch] [bp+Ch]
  int varg_r3; // [sp+34h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  if ( a2[6] == 1 )
  {
    v7 = 1;
    v8 = KeAbPreAcquire(a1, 0, 0);
    v9 = v8;
    do
      v10 = __ldrex((unsigned __int8 *)a1);
    while ( __strex(v10 | 1, (unsigned __int8 *)a1) );
    __dmb(0xBu);
    if ( (v10 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)a1, v8, a1);
    if ( v9 )
      *(_BYTE *)(v9 + 14) |= 1u;
    a2[6] = 0;
    *(_QWORD *)&v11 = *(_QWORD *)a2;
    if ( *(_DWORD **)(*a2 + 4) != a2 || (_DWORD *)*v12 != a2 )
      __fastfail(3u);
    *v12 = v11;
    *(_DWORD *)(v11 + 4) = v12;
    v13 = *(_DWORD **)(a1 + 8);
    *a2 = a1 + 4;
    a2[1] = v13;
    if ( *v13 != a1 + 4 )
      __fastfail(3u);
    *v13 = a2;
    *(_DWORD *)(a1 + 8) = a2;
  }
  else
  {
    v7 = 0;
    v14 = KeAbPreAcquire(a1, 0, 0);
    v15 = v14;
    do
      v16 = __ldrex((unsigned int *)a1);
    while ( !v16 && __strex(0x11u, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v16 )
      ExfAcquirePushLockSharedEx((_DWORD *)a1, v14, a1);
    if ( v15 )
      *(_BYTE *)(v15 + 14) |= 1u;
  }
  if ( ExpSaPageGroupFreeMemory(a2, a3, a4) )
  {
    __dmb(0xBu);
    v17 = (unsigned int *)(a1 + 36);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 | 2, v17) );
    __dmb(0xBu);
    LOBYTE(v19) = v18 | 2;
  }
  else
  {
    v19 = *(_DWORD *)(a1 + 36);
  }
  if ( (v19 & 2) != 0 )
  {
    if ( v7 )
    {
LABEL_33:
      ExpSaAllocatorOptimizeList(a1);
      __dmb(0xBu);
      do
        v21 = __ldrex((unsigned int *)a1);
      while ( __strex(v21 - 1, (unsigned int *)a1) );
      if ( (v21 & 2) != 0 && (v21 & 4) == 0 )
        ExfTryToWakePushLock((unsigned int *)a1);
      return KeAbPostRelease(a1);
    }
    __dmb(0xBu);
    do
      v20 = __ldrex((unsigned int *)a1);
    while ( v20 == 17 && __strex(1u, (unsigned int *)a1) );
    __dmb(0xBu);
    v7 = v20 == 17;
  }
  if ( v7 )
    goto LABEL_33;
  __dmb(0xBu);
  do
    v22 = __ldrex((unsigned int *)a1);
  while ( v22 == 17 && __strex(0, (unsigned int *)a1) );
  if ( v22 != 17 )
    ExfReleasePushLockShared((_DWORD *)a1);
  return KeAbPostRelease(a1);
}
