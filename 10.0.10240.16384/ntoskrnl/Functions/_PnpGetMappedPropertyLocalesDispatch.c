// _PnpGetMappedPropertyLocalesDispatch 
 
int __fastcall PnpGetMappedPropertyLocalesDispatch(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  int result; // r0
  int (__fastcall *v14[2])(int, _DWORD, int, int, int *); // [sp+8h] [bp-40h] BYREF
  int v15; // [sp+10h] [bp-38h] BYREF
  _DWORD v16[7]; // [sp+14h] [bp-34h] BYREF

  v14[0] = 0;
  v15 = 0;
  memset(v16, 0, sizeof(v16));
  result = PnpCtxGetObjectDispatchCallback(a1, a3, v14);
  if ( result >= 0 )
  {
    if ( v14[0] )
    {
      v15 = a4;
      v16[0] = a5;
      v16[1] = a6;
      v16[2] = a7;
      v16[3] = a8;
      v16[4] = a9;
      result = v14[0](a1, a2, a3, 7, &v15);
    }
    else
    {
      result = -1073741822;
    }
  }
  return result;
}
