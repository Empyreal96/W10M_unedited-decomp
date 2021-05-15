// AslpFileHasArmadilloWrapper 
 
BOOL __fastcall AslpFileHasArmadilloWrapper(int a1)
{
  return *(_DWORD *)a1 == 17744 && *(_BYTE *)(a1 + 26) == 83 && *(_BYTE *)(a1 + 27) == 82;
}
