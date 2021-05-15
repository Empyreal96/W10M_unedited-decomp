// MiPfnCanBecomeDemandZero 
 
int __fastcall MiPfnCanBecomeDemandZero(int a1, int *a2)
{
  if ( (a2[5] & 0x8000000) != 0 )
  {
    if ( a2[1] < 0 && (a2[2] & 0x400) == 0 )
      return 1;
  }
  else if ( (*(_BYTE *)(a1 + 112) & 7u) < 2 )
  {
    if ( (*(_BYTE *)(a1 + 112) & 7) == 0 )
      __mrc(15, 0, 13, 0, 3);
    return 1;
  }
  return 0;
}
