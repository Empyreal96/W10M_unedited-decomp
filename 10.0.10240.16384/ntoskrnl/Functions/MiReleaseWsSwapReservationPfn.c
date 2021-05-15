// MiReleaseWsSwapReservationPfn 
 
int __fastcall MiReleaseWsSwapReservationPfn(int a1)
{
  int v2; // r3
  int result; // r0
  int v4; // r3

  v2 = *(_DWORD *)(a1 + 20);
  result = 0;
  if ( (v2 & 0x8000000) == 0 )
  {
    v4 = *(_DWORD *)(a1 + 8);
    if ( (v4 & 8) != 0 || (v4 & 0x10) != 0 )
    {
      if ( (*(_BYTE *)(a1 + 18) & 8) != 0 )
        *(_BYTE *)(a1 + 18) |= 0x10u;
      else
        result = sub_521020(0, 16);
    }
  }
  return result;
}
