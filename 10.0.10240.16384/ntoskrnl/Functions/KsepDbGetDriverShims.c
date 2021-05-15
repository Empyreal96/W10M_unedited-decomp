// KsepDbGetDriverShims 
 
int __fastcall KsepDbGetDriverShims(int a1, int a2, int a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // r4
  int v7; // r8
  int v9[19]; // [sp+14h] [bp-4Ch] BYREF

  v9[3] = 0;
  v9[4] = 0;
  v9[5] = 0;
  v9[6] = 0;
  v9[0] = 0;
  v9[1] = (int)a4;
  if ( !a1 || !a4 )
    return -1073741811;
  *a4 = 0;
  *a5 = 0;
  v6 = KseShimDatabaseOpen(v9);
  v7 = v9[0];
  if ( v6 >= 0 )
  {
    if ( SdbGetDatabaseMatchEx(v9[0], 0, *(_DWORD *)(a1 + 4)) )
      return sub_7CC6E4();
    v6 = -1073741275;
  }
  KsepDbFreeDriverShims(0, *a5);
  if ( v7 )
    KseShimDatabaseClose(v7);
  return v6;
}
