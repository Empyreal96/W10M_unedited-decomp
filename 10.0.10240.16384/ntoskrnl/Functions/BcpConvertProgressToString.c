// BcpConvertProgressToString 
 
int __fastcall BcpConvertProgressToString(unsigned int a1, int a2)
{
  int v2; // r6
  unsigned int v3; // r4
  unsigned int i; // r9
  unsigned int v5; // r7
  _WORD *v7; // [sp+0h] [bp-20h]

  v2 = *(_DWORD *)(a2 + 4);
  v3 = 1000;
  for ( i = *(unsigned __int16 *)(a2 + 2) >> 1; v3 > a1; v3 /= 0xAu )
  {
    if ( v3 <= 1 )
      break;
  }
  v5 = 0;
  if ( i )
  {
    v7 = *(_WORD **)(a2 + 4);
    do
    {
      if ( !v3 )
        break;
      *v7++ = a1 / v3 % 0xA + 48;
      ++v5;
      v3 /= 0xAu;
    }
    while ( v5 < i );
  }
  *(_WORD *)(2 * v5 + v2) = 0;
  *(_WORD *)a2 = 2 * v5;
  return 0;
}
