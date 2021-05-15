// MiNodeFreeZeroPages 
 
int __fastcall MiNodeFreeZeroPages(int a1, int a2, __int16 a3)
{
  int result; // r0
  int i; // r4

  result = 0;
  for ( i = 0; ; i = 1 )
  {
    result += *(_DWORD *)(a1 + 4 * i + 56);
    if ( (a3 & 0x400) != 0 )
      break;
    if ( (a3 & 2) != 0 )
      return result;
    a3 |= 2u;
  }
  return sub_525AFC(result);
}
