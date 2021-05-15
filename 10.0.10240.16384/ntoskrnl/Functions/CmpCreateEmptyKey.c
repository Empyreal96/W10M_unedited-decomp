// CmpCreateEmptyKey 
 
int __fastcall CmpCreateEmptyKey(int a1, unsigned __int16 *a2, int a3)
{
  int v4; // r8
  unsigned int v7; // r0
  int v8; // r9
  int v9; // r5
  unsigned int v10; // r0
  unsigned __int8 *v11; // r4
  int v12; // r0
  int v13; // r7
  unsigned int v14; // r2
  int v15; // r0
  int v16; // r5
  int v17; // r1
  unsigned int v18; // r0
  unsigned int v19; // r2
  int v21; // [sp+8h] [bp-30h] BYREF
  int v22; // [sp+Ch] [bp-2Ch] BYREF
  int v23[10]; // [sp+10h] [bp-28h] BYREF

  v4 = -1;
  v21 = -1;
  v22 = -1;
  v7 = CmpNameSize(a2);
  v8 = HvAllocateCell(a1, v7 + 76);
  if ( v8 != -1 )
  {
    v9 = v23[0];
    *(_WORD *)v23[0] = 27502;
    *(_WORD *)(v9 + 2) = 512;
    KeQuerySystemTime(v23);
    *(_DWORD *)(v9 + 4) = v23[0];
    *(_DWORD *)(v9 + 8) = v23[1];
    *(_DWORD *)(v9 + 16) = a3;
    *(_DWORD *)(v9 + 20) = 0;
    *(_DWORD *)(v9 + 24) = 0;
    *(_DWORD *)(v9 + 28) = -1;
    *(_DWORD *)(v9 + 32) = -1;
    *(_DWORD *)(v9 + 36) = 0;
    *(_DWORD *)(v9 + 40) = -1;
    *(_DWORD *)(v9 + 44) = -1;
    *(_DWORD *)(v9 + 48) = -1;
    *(_WORD *)(v9 + 74) = 0;
    *(_DWORD *)(v9 + 56) = 0;
    *(_DWORD *)(v9 + 64) = 0;
    *(_WORD *)(v9 + 52) = 0;
    *(_DWORD *)(v9 + 52) &= 0xFF00FFFF;
    *(_BYTE *)(v9 + 55) = 0;
    *(_DWORD *)(v9 + 60) = 0;
    v10 = CmpCopyName(v9 + 76, a2);
    *(_WORD *)(v9 + 72) = v10;
    if ( v10 < *a2 )
      *(_WORD *)(v9 + 2) |= 0x20u;
    if ( a3 == -1 )
      *(_WORD *)(v9 + 2) |= 0xCu;
    v11 = (unsigned __int8 *)(a1 + 1928);
    v12 = KeAbPreAcquire(a1 + 1928, 0, 0);
    v13 = v12;
    do
      v14 = __ldrex(v11);
    while ( __strex(v14 | 1, v11) );
    __dmb(0xBu);
    if ( (v14 & 1) != 0 )
      ExfAcquirePushLockExclusiveEx((_DWORD *)(a1 + 1928), v12, a1 + 1928);
    if ( v13 )
      *(_BYTE *)(v13 + 14) |= 1u;
    v15 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a3, &v21);
    if ( v15 && CmpFindSecurityCellCacheIndex((_DWORD *)a1, *(_DWORD *)(v15 + 44), v23) )
      v16 = CmpAssignSecurityDescriptor(
              a1,
              v8,
              v9,
              (_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 2004) + 8 * v23[0] + 4) + 24),
              0);
    else
      v16 = -1073741670;
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v21);
    __pld(v11);
    v17 = *(_DWORD *)v11;
    v18 = *(_DWORD *)v11 - 16;
    if ( (*(_DWORD *)v11 & 0xFFFFFFF0) <= 0x10 )
      v18 = 0;
    if ( (v17 & 2) != 0 )
      goto LABEL_23;
    __dmb(0xBu);
    do
      v19 = __ldrex((unsigned int *)v11);
    while ( v19 == v17 && __strex(v18, (unsigned int *)v11) );
    if ( v19 != v17 )
LABEL_23:
      ExfReleasePushLock((_DWORD *)(a1 + 1928), v17);
    KeAbPostRelease(a1 + 1928);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v22);
    if ( v16 < 0 )
    {
      HvFreeCell(a1, v8);
      v8 = -1;
    }
    v4 = v8;
  }
  return v4;
}
