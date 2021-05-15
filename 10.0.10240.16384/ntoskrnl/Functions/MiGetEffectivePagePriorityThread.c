// MiGetEffectivePagePriorityThread 
 
unsigned int __fastcall MiGetEffectivePagePriorityThread(_DWORD *a1)
{
  unsigned int v1; // r3
  unsigned int result; // r0

  v1 = a1[242];
  if ( (v1 & 0x100) != 0 )
    return (v1 >> 9) & 7;
  result = (a1[240] >> 12) & 7;
  if ( (*(_DWORD *)(a1[84] + 192) & 0x100000) != 0 && result >= 2 )
    result = 2;
  return result;
}
