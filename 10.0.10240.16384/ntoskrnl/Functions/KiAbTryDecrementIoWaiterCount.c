// KiAbTryDecrementIoWaiterCount 
 
int __fastcall KiAbTryDecrementIoWaiterCount(int result, int a2)
{
  if ( (*(_BYTE *)(result + 15) & 2) != 0 )
  {
    --*(_WORD *)(a2 + 46);
    *(_BYTE *)(result + 15) &= 0xFDu;
  }
  return result;
}
