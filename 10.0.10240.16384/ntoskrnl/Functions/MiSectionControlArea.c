// MiSectionControlArea 
 
int __fastcall MiSectionControlArea(int a1)
{
  int v1; // r3

  v1 = *(_DWORD *)(a1 + 20);
  if ( (v1 & 1) != 0 )
    return sub_546990();
  if ( (v1 & 2) != 0 )
    return **(_DWORD **)((v1 & 0xFFFFFFFC) + 20);
  return *(_DWORD *)(a1 + 20);
}
