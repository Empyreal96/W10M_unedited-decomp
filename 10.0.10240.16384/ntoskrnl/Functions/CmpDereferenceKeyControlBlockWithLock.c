// CmpDereferenceKeyControlBlockWithLock 
 
int __fastcall CmpDereferenceKeyControlBlockWithLock(int a1, int a2)
{
  unsigned int v3; // r2
  unsigned int v4; // r6
  int result; // r0
  int v6; // r3
  int v7; // r3
  _DWORD *v8; // r4
  int v9; // r3
  int v10; // r1
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1

  v3 = *(_DWORD *)a1;
  v4 = *(_DWORD *)a1 - 1;
  __dmb(0xBu);
  do
    result = __ldrex((unsigned int *)a1);
  while ( result == v3 && __strex(v4, (unsigned int *)a1) );
  __dmb(0xBu);
  if ( result != v3 )
    return sub_804D34();
  if ( !v4 )
  {
    if ( (*(_WORD *)(a1 + 106) & 4) != 0 )
    {
      v8 = *(_DWORD **)(a1 + 20);
      CmpCleanUpKcbCacheWithLock(a1, a2);
      v9 = __mrc(15, 0, 13, 0, 3);
      v10 = v8[23];
      v8[818] = v9 & 0xFFFFFFC0;
      v8[23] = v10 | 0x80;
      __dmb(0xBu);
      v11 = v8 + 831;
      do
      {
        v12 = __ldrex(v11);
        v13 = v12 + 1;
      }
      while ( __strex(v13, v11) );
      __dmb(0xBu);
      result = 31;
      v8[(((_BYTE)v13 - 1) & 0x7F) + 832] = 31;
      if ( (v8[23] & 0x20) == 0 )
        result = (int)CmpDereferenceHive(v8);
    }
    else
    {
      v6 = CmpHoldLazyFlush;
      __dmb(0xBu);
      if ( (v6 <= 0 || (*(_DWORD *)(a1 + 4) & 8) != 0 || (*(_WORD *)(a1 + 106) & 0x10) != 0)
        && (v7 = *(_DWORD *)(a1 + 4), (v7 & 0x20) == 0) )
      {
        if ( (v7 & 0x20000) == 0 )
          return CmpAddToDelayedClose(a1);
        result = CmpCleanUpKcbCacheWithLock(a1, a2);
        if ( *(_DWORD *)(a1 + 32) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
          return CmpDecommisssionKcb(a1);
      }
      else
      {
        result = CmpCleanUpKcbCacheWithLock(a1, a2);
        if ( *(_DWORD *)(a1 + 32) != (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
          return CmpDecommisssionKcb(a1);
      }
    }
  }
  return result;
}
