// _PnpCreateObjectDispatch 
 
int __fastcall PnpCreateObjectDispatch(int a1, int a2, int a3, int a4, int *a5, _BYTE *a6, int a7)
{
  int v11; // r4
  int v12; // r2
  void (__fastcall *v13)(int, int, int, int, int *); // r5
  _DWORD v15[2]; // [sp+8h] [bp-50h] BYREF
  int v16[4]; // [sp+10h] [bp-48h] BYREF
  int v17; // [sp+20h] [bp-38h] BYREF
  int v18[7]; // [sp+24h] [bp-34h] BYREF

  v15[0] = 0;
  v17 = 0;
  memset(v18, 0, sizeof(v18));
  if ( (_WORD)a7 )
    return -1073741811;
  v11 = PnpCtxGetObjectDispatchCallback(a1, a3, v15);
  if ( v11 >= 0 )
  {
    if ( v15[0] )
    {
      v17 = a4;
      v18[2] = a7;
      v11 = ((int (__fastcall *)(int, int, int, int, int *))v15[0])(a1, a2, a3, 3, &v17);
      if ( v11 >= 0 )
      {
        v12 = LOBYTE(v18[1]);
        *a5 = v18[0];
        *a6 = v12;
        if ( v12 )
        {
          if ( a3 >= 6 )
          {
            v13 = *(void (__fastcall **)(int, int, int, int, int *))(a1 + 156);
            if ( v13 )
            {
              v16[0] = *a5;
              v13(a1, a2, a3, 2, v16);
            }
          }
        }
      }
    }
    else
    {
      v11 = -1073741822;
    }
  }
  return v11;
}
