// CmpLockTableConvertSharedToExclusive 
 
int __fastcall CmpLockTableConvertSharedToExclusive(int result, int a2)
{
  int v2; // r7
  int v3; // r4
  int v4; // r6
  unsigned int v5; // r2
  int v6; // r1
  int v7; // r1
  int v8; // r3
  int v9; // r5

  v2 = result;
  v3 = result | 1;
  v4 = *(_DWORD *)(CmpLockTable + 12);
  v5 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v6 = CmpLockTable + 8 * a2;
  if ( *(_DWORD *)(v6 + 16) == v5 && *(_DWORD *)(v6 + 20) == result )
  {
    *(_DWORD *)(v6 + 20) = v3;
  }
  else
  {
    v7 = 0;
    if ( v4 >= 0 )
    {
      while ( 1 )
      {
        v8 = __mrc(15, 0, 13, 0, 3);
        result = CmpLockTable;
        v9 = CmpLockTable + 8 * v7;
        if ( *(_DWORD *)(v9 + 16) == (v8 & 0xFFFFFFC0) && *(_DWORD *)(v9 + 20) == v2 )
          break;
        if ( ++v7 > v4 )
          return result;
      }
      *(_DWORD *)(CmpLockTable + 8 * v7 + 20) = v3;
    }
  }
  return result;
}
