// _PnpGetGenericObjectList 
 
int __fastcall PnpGetGenericObjectList(int a1, int a2, int a3, int a4, _WORD *a5, unsigned int a6, unsigned int *a7)
{
  int result; // r0
  int v8; // r3
  unsigned int v9; // r3
  _DWORD v10[4]; // [sp+0h] [bp-28h] BYREF
  unsigned int v11; // [sp+10h] [bp-18h]

  *a7 = 0;
  if ( a6 )
    *a5 = 0;
  v10[3] = a6;
  v11 = 0;
  v10[0] = CmContainerListGenericObjectCallback;
  v10[1] = a4;
  v10[2] = a5;
  result = PnpCtxRegEnumKeyWithCallback(a1, a2, PnpObjectListCallback, v10);
  if ( result >= 0 )
  {
    v8 = v11;
    *a7 = v11;
    if ( v8 )
    {
      v9 = v8 + 1;
      *a7 = v9;
      if ( a5 && a6 >= v9 )
        a5[v9 - 1] = 0;
      else
        result = -1073741789;
    }
  }
  return result;
}
