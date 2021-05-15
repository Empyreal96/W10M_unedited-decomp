// _PnpOpenObjectRegKey 
 
int __fastcall PnpOpenObjectRegKey(int a1, int a2, int a3, int a4, char a5, int a6, _DWORD *a7, int a8)
{
  int (__fastcall *v11)(int, int, int, int, int, int *); // r5
  char v12; // r3
  int v13; // r6
  int v14; // r7
  int v16; // r4
  int v18; // [sp+18h] [bp-48h] BYREF
  int v19[17]; // [sp+1Ch] [bp-44h] BYREF

  v18 = 0;
  memset(v19, 0, 36);
  v11 = *(int (__fastcall **)(int, int, int, int, int, int *))(a1 + 152);
  v12 = a5;
  v13 = a6;
  v14 = a8;
  LOBYTE(v19[2]) = a5;
  v19[3] = a6;
  v19[5] = a8;
  v19[1] = a4;
  if ( v11 )
  {
    if ( v11(a1, a2, a3, 2, 1, &v18) != -1073741822 )
      return sub_7C5FE8();
    a4 = v19[1];
    v12 = v19[2];
    v13 = v19[3];
    v14 = v19[5];
  }
  v16 = PnpOpenObjectRegKeyDispatch(a1, a2, a3, a4, v12, v13, &v19[4], v14);
  if ( v16 >= 0 )
  {
    if ( a7 )
      *a7 = v19[4];
  }
  return v16;
}
