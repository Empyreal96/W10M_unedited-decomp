// PnpStartDevice 
 
int __fastcall PnpStartDevice(int a1, int a2, int a3)
{
  _DWORD *v6; // r5
  _BYTE *v7; // r0
  int v8; // r3
  int v9; // r2
  int v11[10]; // [sp+18h] [bp-48h] BYREF

  if ( a1 )
    v6 = *(_DWORD **)(*(_DWORD *)(a1 + 176) + 20);
  else
    v6 = 0;
  PoFxPrepareDevice(v6, 1);
  v6[20] = 1;
  v7 = memset(v11, 0, sizeof(v11));
  LOWORD(v11[0]) = 27;
  v11[2] = v6[71];
  v11[3] = v6[72];
  if ( a1 )
    v8 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  else
    v8 = 0;
  if ( v8 )
  {
    v9 = *(_DWORD *)(v8 + 420);
    if ( v9 != -1 && v9 != -2 )
      return sub_520094(v7);
  }
  if ( a2 )
    return PnpAsynchronousCall(a1, v11, a2, a3);
  return IopSynchronousCall(a1, v11, -1073741637, 0, a3);
}
