// CmpMarkCurrentValueDirty 
 
int __fastcall CmpMarkCurrentValueDirty(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r3
  int result; // r0
  int v7; // r3
  int v8; // r5
  int v9; // [sp+0h] [bp-18h] BYREF
  int v10[5]; // [sp+4h] [bp-14h] BYREF

  v9 = a2;
  v10[0] = a3;
  v10[1] = a4;
  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v9 = -1;
  result = v5(a1, a2, &v9);
  if ( result )
  {
    CmpFindSubKeyByNameWithStatus(a1, result, (int)&CmpSelectString, v10);
    result = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v9);
    if ( v10[0] != -1 )
    {
      result = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v10[0], &v9);
      if ( result )
      {
        v8 = CmpFindValueByName(a1, result, (int)&CmpCurrentString, v7);
        result = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v9);
        if ( v8 != -1 )
          result = HvpMarkCellDirty(a1, v8, 0, 0);
      }
    }
  }
  return result;
}
