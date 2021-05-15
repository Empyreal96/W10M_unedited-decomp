// CmpDeleteTree 
 
int __fastcall CmpDeleteTree(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v4; // r9
  unsigned int i; // r8
  _DWORD *v7; // r0
  unsigned int v8; // r4
  int v9; // r4
  unsigned int v10; // r7
  int v11; // r0
  __int64 v12; // r4
  int v14; // [sp+0h] [bp-28h] BYREF
  int v15[9]; // [sp+4h] [bp-24h] BYREF

  v15[0] = a3;
  v15[1] = a4;
  v14 = -1;
  v4 = a2;
  for ( i = a2; ; i = v8 )
  {
    while ( 1 )
    {
      v7 = (_DWORD *)(*(int (__fastcall **)(int, unsigned int, int *))(a1 + 4))(a1, i, &v14);
      if ( !v7 )
        return 0;
      v8 = v7[4];
      if ( !(v7[5] + v7[6]) )
        break;
      v9 = CmpFindSubKeyByNumber(a1, v7, 0, v15);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
      if ( v9 < 0 )
        return 0;
      v10 = v15[0];
      if ( v15[0] == -1 )
        return 0;
      v11 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v15[0], &v14);
      if ( !v11 )
        return 0;
      v12 = *(_QWORD *)(v11 + 20);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
      if ( HIDWORD(v12) + (_DWORD)v12 )
      {
        i = v10;
      }
      else if ( CmpFreeKeyByCell(a1, v10, 1) < 0 )
      {
        return 0;
      }
    }
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v14);
    if ( i == v4 )
      break;
  }
  return 1;
}
