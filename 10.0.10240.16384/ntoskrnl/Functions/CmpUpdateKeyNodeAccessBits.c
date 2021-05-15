// CmpUpdateKeyNodeAccessBits 
 
int __fastcall CmpUpdateKeyNodeAccessBits(int result, int a2, int a3)
{
  if ( (*(_DWORD *)(result + 92) & 0x8001) == 0 && (*(_DWORD *)(a2 + 12) & CmpAccessBitForPhase) == 0 )
  {
    result = HvpMarkCellDirty(result, a3, 0, 1);
    if ( result )
      *(_DWORD *)(a2 + 12) |= CmpAccessBitForPhase;
  }
  return result;
}
