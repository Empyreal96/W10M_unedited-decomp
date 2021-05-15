// CmpFreeSecurityDescriptor 
 
int __fastcall CmpFreeSecurityDescriptor(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int, _DWORD *); // r3
  int result; // r0
  int v7; // r6
  int v8; // r7
  int v9; // r0
  int v10; // r5
  int v11; // r3
  int v12; // [sp+0h] [bp-20h] BYREF
  _DWORD v13[7]; // [sp+4h] [bp-1Ch] BYREF

  v12 = a2;
  v13[0] = a3;
  v13[1] = a4;
  v5 = *(int (__fastcall **)(int, int, _DWORD *))(a1 + 4);
  v12 = -1;
  v13[0] = -1;
  result = v5(a1, a2, v13);
  v7 = result;
  if ( result )
  {
    v8 = *(_DWORD *)(result + 44);
    v9 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v8, &v12);
    v10 = v9;
    if ( v9 )
    {
      v11 = *(_DWORD *)(v9 + 12);
      if ( v11 == 1 )
      {
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v12);
        v10 = 0;
        CmpRemoveSecurityCellList(a1, v8);
        HvFreeCell(a1, v8);
      }
      else
      {
        *(_DWORD *)(v9 + 12) = v11 - 1;
      }
      *(_DWORD *)(v7 + 44) = -1;
    }
    result = (*(int (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v13);
    if ( v10 )
      result = (*(int (__fastcall **)(int, int *))(a1 + 8))(a1, &v12);
  }
  return result;
}
