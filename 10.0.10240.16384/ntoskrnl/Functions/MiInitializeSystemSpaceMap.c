// MiInitializeSystemSpaceMap 
 
int __fastcall MiInitializeSystemSpaceMap(int a1)
{
  *(_DWORD *)a1 = 0;
  *(_DWORD *)(a1 + 4) = a1;
  *(_DWORD *)(a1 + 8) = 0;
  if ( (char *)a1 == algn_632F64 )
    MiInitializePteInfo(algn_63480C, 7564, dword_63389C, MiLowHalVa - dword_63389C);
  return 1;
}
