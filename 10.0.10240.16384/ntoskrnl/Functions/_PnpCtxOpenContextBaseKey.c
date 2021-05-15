// _PnpCtxOpenContextBaseKey 
 
int __fastcall PnpCtxOpenContextBaseKey(int *a1, int a2, int a3, int a4)
{
  int v6; // r4
  int v7; // r0
  int v8; // r0
  int v10[4]; // [sp+8h] [bp-10h] BYREF

  v10[0] = 0;
  v6 = PnpCtxGetCachedContextBaseKey(a1, a2, v10);
  if ( v6 >= 0 )
  {
    if ( a1 )
      v7 = *a1;
    else
      v7 = 0;
    v8 = SysCtxRegOpenKey(v7, v10[0], (int)&dword_8CE900, 0, a4);
    if ( v8 == -1073741444 )
    {
      v6 = -1073741595;
    }
    else if ( v8 < 0 )
    {
      v6 = v8;
    }
  }
  return v6;
}
