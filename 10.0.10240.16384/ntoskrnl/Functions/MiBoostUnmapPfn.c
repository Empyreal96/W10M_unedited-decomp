// MiBoostUnmapPfn 
 
BOOL __fastcall MiBoostUnmapPfn(int a1)
{
  return (*(_DWORD *)(a1 + 20) & 0x8000000) != 0
      && (*(_BYTE *)(a1 + 18) & 0x10) == 0
      && (*(_BYTE *)(a1 + 19) & 8) == 0
      && (*(_BYTE *)(a1 + 19) & 7u) < 5;
}
