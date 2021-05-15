// PnpQueryDeviceRelations 
 
int __fastcall PnpQueryDeviceRelations(int a1, int a2, int a3, _DWORD *a4)
{
  _BYTE *v8; // r0
  int v9; // r1
  int v10; // r2
  int v12[10]; // [sp+18h] [bp-48h] BYREF

  v8 = memset(v12, 0, sizeof(v12));
  LOWORD(v12[0]) = 1819;
  v12[2] = a2;
  if ( a1 )
    v9 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v9 = 0;
  if ( v9 )
  {
    v10 = *(_DWORD *)(v9 + 420);
    if ( v10 != -1 && v10 != -2 )
      return sub_7CA590(v8);
  }
  if ( a3 )
    return PnpAsynchronousCall(a1, v12, a3, a4);
  return IopSynchronousCall(a1, (int)v12, -1073741637, 0, a4);
}
