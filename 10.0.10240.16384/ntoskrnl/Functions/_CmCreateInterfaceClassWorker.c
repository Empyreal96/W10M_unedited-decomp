// _CmCreateInterfaceClassWorker 
 
int __fastcall CmCreateInterfaceClassWorker(int *a1, unsigned __int16 *a2, int a3, int a4, _BYTE *a5, __int16 a6)
{
  int v6; // r4
  BOOL v7; // r2
  int v9[6]; // [sp+10h] [bp-18h] BYREF

  v9[0] = 0;
  if ( a6 )
    return -1073741811;
  v6 = CmOpenInterfaceClassRegKey(a1, a2, a3, 1, a3, 1, a4, v9);
  if ( v6 >= 0 )
  {
    v7 = v9[0] == 1;
    *a5 = v7;
    if ( v7 )
      return sub_7EF370();
  }
  return v6;
}
