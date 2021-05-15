// PL011GetByte 
 
int __fastcall PL011GetByte(__int16 **a1, _BYTE *a2, int a3, int a4)
{
  int v6; // r2
  __int16 *v7; // r3
  __int16 *v8; // r3
  __int16 v9; // r3

  if ( !*a1 )
    return 1;
  if ( a3 )
    v6 = 204800;
  else
    v6 = 1;
  while ( 1 )
  {
    v7 = *a1;
    --v6;
    __dsb(0xFu);
    if ( (v7[12] & 0x10) == 0 )
      break;
    if ( !v6 )
      return 1;
  }
  if ( !a4 )
  {
    v8 = *a1;
    __dsb(0xFu);
    v9 = *v8;
    if ( (v9 & 0x700) != 0 )
    {
      *a2 = 0;
      return 2;
    }
    *a2 = v9;
  }
  return 0;
}
