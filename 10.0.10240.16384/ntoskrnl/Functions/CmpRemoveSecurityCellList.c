// CmpRemoveSecurityCellList 
 
int __fastcall CmpRemoveSecurityCellList(int a1, int a2)
{
  int v4; // r6
  int result; // r0
  int v6; // r5
  int v7; // r7
  int v8; // [sp+0h] [bp-20h] BYREF
  int v9; // [sp+4h] [bp-1Ch] BYREF
  _DWORD v10[6]; // [sp+8h] [bp-18h] BYREF

  v9 = -1;
  v10[0] = -1;
  v8 = -1;
  v4 = 0;
  result = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, a2, &v8);
  v6 = result;
  if ( result )
  {
    result = (*(int (__fastcall **)(int, _DWORD, int *))(a1 + 4))(a1, *(_DWORD *)(result + 4), &v9);
    v7 = result;
    if ( result )
    {
      result = (*(int (__fastcall **)(int, _DWORD, _DWORD *))(a1 + 4))(a1, *(_DWORD *)(v6 + 8), v10);
      v4 = result;
      if ( result )
      {
        *(_DWORD *)(v7 + 8) = *(_DWORD *)(v6 + 8);
        *(_DWORD *)(result + 4) = *(_DWORD *)(v6 + 4);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v9);
        (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v10);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v8);
        v7 = 0;
        v4 = 0;
        v6 = 0;
        result = CmpRemoveFromSecurityCache(a1, a2);
      }
    }
    if ( v6 )
    {
      result = sub_528024(result);
    }
    else
    {
      if ( v7 )
        result = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v9);
      if ( v4 )
        result = (*(int (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v10);
    }
  }
  return result;
}
