// KiAbTryIncrementIoWaiterCount 
 
BOOL __fastcall KiAbTryIncrementIoWaiterCount(unsigned __int8 *a1, int a2)
{
  unsigned __int8 v3; // r3
  BOOL result; // r0
  unsigned __int8 *v5; // r5
  int v6; // r2

  v3 = a1[15];
  result = 0;
  if ( (v3 & 2) == 0 && (a1[13] & 1) != 0 )
  {
    v5 = &a1[-8 * a1[12]];
    v6 = (*((_DWORD *)v5 + 240) >> 9) & 7;
    if ( (*(_DWORD *)(*((_DWORD *)v5 + 84) + 192) & 0x100000) != 0 )
      v6 = 0;
    if ( v6 >= 2 )
      goto LABEL_6;
    if ( v5 == (unsigned __int8 *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && *((_DWORD *)v5 + 250) )
      v6 = 2;
    if ( v6 >= 2 )
      goto LABEL_6;
    if ( *((_DWORD *)v5 + 250) )
      v6 = 2;
    if ( v6 >= 2 )
    {
LABEL_6:
      ++*(_WORD *)(a2 + 46);
      a1[15] |= 2u;
      result = *(unsigned __int16 *)(a2 + 46) == 1;
    }
  }
  return result;
}
