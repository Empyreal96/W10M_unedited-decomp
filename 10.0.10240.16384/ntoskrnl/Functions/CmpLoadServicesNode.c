// CmpLoadServicesNode 
 
BOOL __fastcall CmpLoadServicesNode(int a1, int a2, int *a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r4
  int v8; // r0
  int v9; // r3
  int v10; // r4
  int v11; // r0
  BOOL result; // r0
  int v13[6]; // [sp+0h] [bp-18h] BYREF

  v13[0] = a4;
  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v13[0] = -1;
  v8 = v5(a1, a2, v13);
  result = 0;
  if ( v8 )
  {
    v10 = CmpFindSubKeyByName(a1, v8, (int)&CmpServicesString, v9);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, v13);
    if ( v10 != -1 )
    {
      v11 = (*(int (__fastcall **)(int, int, int))(a1 + 4))(a1, v10, a4);
      *a3 = v11;
      if ( v11 )
        result = 1;
    }
  }
  return result;
}
