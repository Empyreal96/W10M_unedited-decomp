// HvpGetBinMemAlloc 
 
int __fastcall HvpGetBinMemAlloc(int a1, int a2, int a3)
{
  int v3; // r0

  v3 = HvpGetCellMap(a1, *(_DWORD *)(a2 + 4) + (a3 << 31));
  if ( !v3 )
    sub_81B180();
  return *(_DWORD *)(v3 + 16);
}
