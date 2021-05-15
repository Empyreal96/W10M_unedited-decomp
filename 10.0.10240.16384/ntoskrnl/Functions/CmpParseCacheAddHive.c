// CmpParseCacheAddHive 
 
int __fastcall CmpParseCacheAddHive(int a1, int a2)
{
  unsigned int v2; // r7
  int v3; // r5
  _WORD *v5; // r4
  int v6; // r3
  int v7; // r1
  int v8; // r9
  int v10; // r0
  int v11; // r5
  unsigned int v12; // r2
  int v13; // r1
  unsigned int v14; // r0
  unsigned int v15; // r2
  _DWORD **v16; // r4
  _DWORD *v17; // r1
  __int64 v18; // r2
  char v20[4]; // [sp+4h] [bp-3Ch] BYREF
  _WORD *v21; // [sp+8h] [bp-38h]
  __int16 v22[2]; // [sp+10h] [bp-30h] BYREF
  _WORD *v23; // [sp+14h] [bp-2Ch]
  int v24; // [sp+18h] [bp-28h]

  v2 = *(_DWORD *)(a1 + 1988);
  v3 = a2;
  v24 = *(_DWORD *)(a1 + 1984);
  CmpLockKcbShared(a2);
  v5 = (_WORD *)(v2 + 2 * (((unsigned int)(unsigned __int16)v24 - 1) >> 1));
  v21 = v5;
  while ( v2 < (unsigned int)v5 && *v5 != 92 )
    --v5;
  v23 = v5 + 1;
  v22[0] = 2 * ((int)(v2 + 2 * (((unsigned int)(unsigned __int16)v24 - 1) >> 1) - (_DWORD)v5) >> 1);
  v6 = *(_DWORD *)(v3 + 40);
  v22[1] = v24;
  if ( v6 )
    v7 = *(_DWORD *)(v6 + 24);
  else
    v7 = -1;
  v8 = CmpParseCacheAllocEntry(v22, v7, v3, v20);
  if ( v8 >= 0 )
    return sub_7D29C0();
  v10 = KeAbPreAcquire((unsigned int)&CmpParseCacheLock, 0, 0);
  v11 = v10;
  do
    v12 = __ldrex((unsigned __int8 *)&CmpParseCacheLock);
  while ( __strex(v12 | 1, (unsigned __int8 *)&CmpParseCacheLock) );
  __dmb(0xBu);
  if ( (v12 & 1) != 0 )
    ExfAcquirePushLockExclusiveEx(&CmpParseCacheLock, v10, (unsigned int)&CmpParseCacheLock);
  if ( v11 )
    *(_BYTE *)(v11 + 14) |= 1u;
  __pld(&CmpParseCacheLock);
  v13 = CmpParseCacheLock;
  if ( (CmpParseCacheLock & 0xFFFFFFF0) <= 0x10 )
    v14 = 0;
  else
    v14 = CmpParseCacheLock - 16;
  if ( (CmpParseCacheLock & 2) != 0 )
    goto LABEL_24;
  __dmb(0xBu);
  do
    v15 = __ldrex((unsigned int *)&CmpParseCacheLock);
  while ( v15 == v13 && __strex(v14, (unsigned int *)&CmpParseCacheLock) );
  if ( v15 != v13 )
LABEL_24:
    ExfReleasePushLock(&CmpParseCacheLock, v13);
  KeAbPostRelease((unsigned int)&CmpParseCacheLock);
  v16 = (_DWORD **)(a1 + 1836);
  while ( *v16 != v16 )
  {
    LODWORD(v18) = *v16;
    HIDWORD(v18) = (*v16)[1];
    v17 = (_DWORD *)**v16;
    if ( v18 != __PAIR64__((unsigned int)v16, v17[1]) )
      __fastfail(3u);
    *v16 = v17;
    v17[1] = v16;
    ExFreePoolWithTag(v18 - 4);
  }
  CmpUnlockKcb(a2);
  return v8;
}
