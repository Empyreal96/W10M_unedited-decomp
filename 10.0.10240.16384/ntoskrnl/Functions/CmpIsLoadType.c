// CmpIsLoadType 
 
int __fastcall CmpIsLoadType(int a1, int a2, int a3, int a4, int a5)
{
  int (__fastcall *v6)(int, int, _DWORD *); // r3
  int v7; // r0
  int v8; // r3
  int v10; // r0
  int v11; // r5
  int v12; // r0
  _DWORD *v13; // r5
  void (__fastcall *v14)(int, _DWORD *); // r3
  int v15; // r5
  unsigned int v16[2]; // [sp+8h] [bp-48h] BYREF
  _DWORD v17[3]; // [sp+10h] [bp-40h] BYREF
  int v18; // [sp+1Ch] [bp-34h] BYREF
  _DWORD v19[12]; // [sp+20h] [bp-30h] BYREF

  LOWORD(v16[0]) = 0;
  v6 = *(int (__fastcall **)(int, int, _DWORD *))(a1 + 4);
  v16[1] = -1;
  v17[0] = -1;
  v18 = -1;
  v19[0] = -1;
  v17[1] = -1;
  v17[2] = -1;
  v7 = v6(a1, a2, v19);
  if ( !v7 )
    return 0;
  if ( a5 )
    return sub_96822C();
  v10 = CmpFindValueByName(a1, v7, (int)&CmpStartString, v8);
  v11 = v10;
  if ( v10 != -1 )
  {
    v12 = (*(int (__fastcall **)(int, int, int *))(a1 + 4))(a1, v10, &v18);
    if ( v12 )
    {
      v13 = (_DWORD *)CmpValueToData(a1, v11, v12, v16, (int)v17);
      (*(void (__fastcall **)(int, int *))(a1 + 8))(a1, &v18);
      if ( v13 )
      {
        v14 = *(void (__fastcall **)(int, _DWORD *))(a1 + 8);
        if ( *v13 == 1 )
        {
          v14(a1, v17);
          v15 = 1;
          goto LABEL_10;
        }
        v14(a1, v17);
      }
    }
  }
  v15 = 0;
LABEL_10:
  (*(void (__fastcall **)(int, _DWORD *))(a1 + 8))(a1, v19);
  return v15;
}
