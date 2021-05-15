// _PnpValidateObjectNameDispatch 
 
int __fastcall PnpValidateObjectNameDispatch(int a1, int a2, int a3, int a4)
{
  int result; // r0
  int (__fastcall *v9[2])(int, _DWORD, int, int, int *); // [sp+8h] [bp-40h] BYREF
  int v10; // [sp+10h] [bp-38h] BYREF
  char v11[28]; // [sp+14h] [bp-34h] BYREF

  v9[0] = 0;
  v10 = 0;
  memset(v11, 0, sizeof(v11));
  if ( (_WORD)a4 )
    return -1073741811;
  result = PnpCtxGetObjectDispatchCallback(a1, a3, v9);
  if ( result >= 0 )
  {
    if ( v9[0] )
    {
      v10 = a4;
      result = v9[0](a1, a2, a3, 1, &v10);
    }
    else
    {
      result = -1073741822;
    }
  }
  return result;
}
