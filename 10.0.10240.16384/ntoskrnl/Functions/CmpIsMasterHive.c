// CmpIsMasterHive 
 
BOOL __fastcall CmpIsMasterHive(int a1)
{
  _DWORD *v1; // r2

  v1 = *(_DWORD **)(a1 + 20);
  return v1 == CmpMasterHive
      || (*(_DWORD *)(a1 + 4) & 0x20000) == 0 && (v1[807] & 0x10) == 0 && (*(_WORD *)(a1 + 106) & 0x200) == 0;
}
