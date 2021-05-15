// _PnpGetObjectListDispatch 
 
int __fastcall PnpGetObjectListDispatch(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int result; // r0
  int (__fastcall *v13[2])(int, _DWORD, int, int, int *); // [sp+8h] [bp-40h] BYREF
  int v14; // [sp+10h] [bp-38h] BYREF
  _DWORD v15[7]; // [sp+14h] [bp-34h] BYREF

  v13[0] = 0;
  v14 = 0;
  memset(v15, 0, sizeof(v15));
  if ( (_WORD)a8 )
    return -1073741811;
  result = PnpCtxGetObjectDispatchCallback(a1, a2, v13);
  if ( result >= 0 )
  {
    if ( v13[0] )
    {
      v15[0] = a4;
      v15[1] = a5;
      v14 = a3;
      v15[4] = a8;
      v15[2] = a6;
      v15[3] = a7;
      result = v13[0](a1, 0, a2, 5, &v14);
    }
    else
    {
      result = -1073741822;
    }
  }
  return result;
}
