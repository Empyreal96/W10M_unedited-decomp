// CmpIsKcbLockAllowed 
 
int __fastcall CmpIsKcbLockAllowed(unsigned int a1, unsigned int a2, _BYTE *a3)
{
  unsigned int v3; // r4
  unsigned int v4; // r3

  *a3 = 0;
  v3 = (*(_DWORD *)(a1 + 4) >> 21) & 0x3FF;
  v4 = (*(_DWORD *)(a2 + 4) >> 21) & 0x3FF;
  if ( v3 > v4 )
    return 0;
  if ( v3 >= v4 && a1 >= a2 )
  {
    if ( a1 <= a2 )
      return sub_8047F0();
    return 0;
  }
  return 1;
}
