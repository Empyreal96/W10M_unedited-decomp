// _PnpSetMappedPropertyDispatch 
 
int __fastcall PnpSetMappedPropertyDispatch(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int result; // r0
  int (__fastcall *v15[2])(int, _DWORD, int, int, int *); // [sp+8h] [bp-40h] BYREF
  int v16; // [sp+10h] [bp-38h] BYREF
  _DWORD v17[7]; // [sp+14h] [bp-34h] BYREF

  v15[0] = 0;
  v16 = 0;
  memset(v17, 0, sizeof(v17));
  result = PnpCtxGetObjectDispatchCallback(a1, a3, v15);
  if ( result >= 0 )
  {
    if ( v15[0] )
    {
      v16 = a4;
      v17[0] = a5;
      v17[1] = a6;
      v17[2] = a7;
      v17[3] = a8;
      v17[4] = a9;
      v17[5] = a10;
      result = v15[0](a1, a2, a3, 9, &v16);
    }
    else
    {
      result = -1073741822;
    }
  }
  return result;
}
