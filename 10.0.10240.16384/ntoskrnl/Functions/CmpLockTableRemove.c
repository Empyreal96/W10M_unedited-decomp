// CmpLockTableRemove 
 
int __fastcall CmpLockTableRemove(int a1, int a2)
{
  int v3; // r7
  int v4; // r4
  int v5; // r6
  int v6; // r3
  unsigned __int64 *v7; // r0
  int v8; // r5
  int v9; // r3
  int v10; // r1
  int v11; // r3
  int v12; // r5
  int v13; // r3
  unsigned __int64 *v14; // r3

  v3 = a1 | 1;
  v4 = -1;
  v5 = *(_DWORD *)(CmpLockTable + 12);
  v6 = __mrc(15, 0, 13, 0, 3);
  v7 = (unsigned __int64 *)CmpLockTable;
  v8 = CmpLockTable + 8 * a2;
  if ( *(_DWORD *)(v8 + 16) != (v6 & 0xFFFFFFC0)
    || (v9 = *(_DWORD *)(v8 + 20), v9 != a1) && v9 != v3
    || (v4 = a2, a2 == -1) )
  {
    v10 = 0;
    if ( v5 >= 0 )
    {
      while ( 1 )
      {
        v11 = __mrc(15, 0, 13, 0, 3);
        v7 = (unsigned __int64 *)CmpLockTable;
        v12 = CmpLockTable + 8 * v10;
        if ( *(_DWORD *)(v12 + 16) == (v11 & 0xFFFFFFC0) )
        {
          v13 = *(_DWORD *)(v12 + 20);
          if ( v13 == a1 || v13 == v3 )
            break;
        }
        if ( ++v10 > v5 )
          goto LABEL_12;
      }
      v4 = v10;
    }
  }
LABEL_12:
  v14 = &v7[v4];
  *((_DWORD *)v14 + 4) = 0;
  *((_DWORD *)v14 + 5) = 0;
  return RtlpInterlockedPushEntrySList(v7, &v7[v4 + 2]);
}
