// MiLogWsAging 
 
int __fastcall MiLogWsAging(int result)
{
  if ( dword_634CA0 )
  {
    if ( (*(_BYTE *)(result + 112) & 7) == 0 )
      result -= 492;
    if ( *(_DWORD *)dword_634CA0 > 5u && (*(_DWORD *)(dword_634CA0 + 8) & 1) != 0 )
      result = sub_543210();
  }
  return result;
}
