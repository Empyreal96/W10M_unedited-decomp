// KiGetInterruptObjectFromVector 
 
int __fastcall KiGetInterruptObjectFromVector(unsigned int a1)
{
  int v1; // r1
  unsigned int v2; // r4
  int *v4; // r3
  int v5; // r3

  v1 = 0;
  v2 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( a1 <= 0xFFF )
  {
    if ( (a1 & 0xF0) != 0 )
      return sub_553BEC();
    v4 = (int *)(v2 + 4 * ((a1 & 0xF | (a1 >> 4) & 0xF0) + 75));
    if ( v4 )
      v5 = *v4;
    else
      v5 = 0;
    if ( v5 )
      v1 = v5;
  }
  return v1;
}
