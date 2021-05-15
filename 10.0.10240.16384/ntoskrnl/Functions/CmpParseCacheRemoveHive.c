// CmpParseCacheRemoveHive 
 
int __fastcall CmpParseCacheRemoveHive(int a1)
{
  int v2; // r6
  int v3; // r0
  unsigned int v4; // r2
  _DWORD *v5; // r1
  _DWORD **i; // r4
  _DWORD *v7; // r0
  unsigned int v8; // r3
  _DWORD **v9; // r2
  _DWORD *j; // r3
  int v11; // r1
  unsigned int v12; // r0
  unsigned int v13; // r2
  _DWORD *v15; // r1
  __int64 v16; // r2

  v2 = 0;
  v3 = KeAbPreAcquire((unsigned int)&CmpParseCacheLock, 0, 0);
  do
    v4 = __ldrex((unsigned __int8 *)&CmpParseCacheLock);
  while ( __strex(v4 | 1, (unsigned __int8 *)&CmpParseCacheLock) );
  __dmb(0xBu);
  if ( (v4 & 1) != 0 )
    return sub_7D1FC8(v3);
  if ( v3 )
    *(_BYTE *)(v3 + 14) |= 1u;
  v5 = *(_DWORD **)(a1 + 1836);
  for ( i = (_DWORD **)(a1 + 1836); v5 != i; v5 = (_DWORD *)*v5 )
  {
    v7 = v5 - 1;
    v8 = 101027 * (v5[4] ^ (v5[4] >> 9));
    v9 = (_DWORD **)(CmpParseCacheTable + 4 * (((unsigned __int8)v8 ^ (unsigned __int8)(v8 >> 9)) & 0x1F) + 4);
    for ( j = *v9; j; j = (_DWORD *)*j )
    {
      if ( j == v7 )
      {
        *v9 = (_DWORD *)*v7;
        break;
      }
      v9 = (_DWORD **)j;
    }
  }
  __pld(&CmpParseCacheLock);
  v11 = CmpParseCacheLock;
  if ( (CmpParseCacheLock & 0xFFFFFFF0) > 0x10 )
    v12 = CmpParseCacheLock - 16;
  else
    v12 = 0;
  if ( (CmpParseCacheLock & 2) != 0 )
    goto LABEL_27;
  __dmb(0xBu);
  do
    v13 = __ldrex((unsigned int *)&CmpParseCacheLock);
  while ( v13 == v11 && __strex(v12, (unsigned int *)&CmpParseCacheLock) );
  if ( v13 != v11 )
LABEL_27:
    ExfReleasePushLock(&CmpParseCacheLock, v11);
  KeAbPostRelease((unsigned int)&CmpParseCacheLock);
  while ( *i != i )
  {
    LODWORD(v16) = *i;
    HIDWORD(v16) = (*i)[1];
    v15 = (_DWORD *)**i;
    if ( v16 != __PAIR64__((unsigned int)i, v15[1]) )
      __fastfail(3u);
    *i = v15;
    v15[1] = i;
    if ( !v2 )
      v2 = *(_DWORD *)(v16 + 24);
    ExFreePoolWithTag(v16 - 4);
  }
  if ( v2 )
    CmpDereferenceKeyControlBlock(v2);
  return 0;
}
