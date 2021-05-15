// CmpFindGroupOrderList 
 
int __fastcall CmpFindGroupOrderList(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r3
  int v6; // r4
  int v7; // r0
  int v8; // r3
  int v9; // r6
  int v10; // r0
  int v11; // r3
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a3;
  v13[1] = a4;
  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v6 = -1;
  v13[0] = -1;
  v7 = v5(a1, a2, v13);
  if ( v7 )
  {
    v9 = CmpFindSubKeyByName(a1, v7, (int)&CmpControlString, v8);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v13);
    if ( v9 != -1 )
    {
      v10 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v9, v13);
      if ( v10 )
      {
        v6 = CmpFindSubKeyByName(a1, v10, (int)&CmpGroupOrderListString, v11);
        (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v13);
      }
    }
  }
  return v6;
}
