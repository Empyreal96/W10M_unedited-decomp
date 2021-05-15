// _PnpOpenObjectRegKeyDispatch 
 
int __fastcall PnpOpenObjectRegKeyDispatch(int a1, int a2, int a3, int a4, char a5, int a6, _DWORD *a7, int a8)
{
  int result; // r0
  int (__fastcall *v13[2])(_DWORD, _DWORD, _DWORD, int, int *); // [sp+8h] [bp-40h] BYREF
  int v14; // [sp+10h] [bp-38h] BYREF
  int v15[7]; // [sp+14h] [bp-34h] BYREF

  v13[0] = 0;
  v14 = 0;
  memset(v15, 0, sizeof(v15));
  if ( (_WORD)a8 )
    return -1073741811;
  result = PnpCtxGetObjectDispatchCallback(a1, a3, v13);
  if ( result >= 0 )
  {
    if ( v13[0] )
    {
      LOBYTE(v15[0]) = a5;
      v14 = a4;
      v15[1] = a6;
      v15[3] = a8;
      result = v13[0](a1, a2, a3, 2, &v14);
      if ( result >= 0 )
        *a7 = v15[2];
    }
    else
    {
      result = -1073741822;
    }
  }
  return result;
}
