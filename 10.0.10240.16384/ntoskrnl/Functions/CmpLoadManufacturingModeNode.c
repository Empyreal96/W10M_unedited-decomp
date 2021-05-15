// CmpLoadManufacturingModeNode 
 
BOOL __fastcall CmpLoadManufacturingModeNode(int a1, int a2, int *a3, int a4)
{
  int (__fastcall *v5)(int, int, int *); // r4
  int v8; // r0
  int v9; // r3
  BOOL result; // r0
  int v11; // r4
  int v12; // r0
  int v13; // r3
  int v14; // r4
  int v15; // r0
  int v16; // [sp+0h] [bp-20h] BYREF
  _DWORD v17[7]; // [sp+4h] [bp-1Ch] BYREF

  v16 = (int)a3;
  v17[0] = a4;
  v5 = *(int (__fastcall **)(int, int, int *))(a1 + 4);
  v16 = -1;
  v17[0] = -1;
  v8 = v5(a1, a2, &v16);
  result = 0;
  if ( v8 )
  {
    v11 = CmpFindSubKeyByName(a1, v8, (int)&CmpControlString, v9);
    (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v16);
    if ( v11 != -1 )
    {
      v12 = (*(int (__fastcall **)(int, int, _DWORD *))(a1 + 4))(a1, v11, v17);
      if ( v12 )
      {
        v14 = CmpFindSubKeyByName(a1, v12, (int)&CmpManufacturingModeString, v13);
        (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v17);
        if ( v14 != -1 )
        {
          v15 = (*(int (__fastcall **)(int, int, int))(a1 + 4))(a1, v14, a4);
          *a3 = v15;
          if ( v15 )
            result = 1;
        }
      }
    }
  }
  return result;
}
