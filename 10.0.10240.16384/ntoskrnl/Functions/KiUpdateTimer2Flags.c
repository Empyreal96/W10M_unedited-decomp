// KiUpdateTimer2Flags 
 
int __fastcall KiUpdateTimer2Flags(unsigned int *a1, int a2, char a3)
{
  int v3; // r6
  unsigned int v4; // r4
  int v5; // r8
  unsigned int v6; // r7

  v3 = 3968;
  if ( (a3 & 1) != 0 )
    v3 = 3840;
  if ( (a3 & 2) != 0 )
    v3 &= 0xFFFFF0FF;
  v4 = *a1;
  v5 = *a1 & ~v3 | (a2 << 8);
  __dmb(0xBu);
  do
    v6 = __ldrex(a1);
  while ( v6 == v4 && __strex(v5, a1) );
  __dmb(0xBu);
  if ( v4 != v6 )
    return sub_52C510();
  if ( (a3 & 4) == 0 )
    return 0;
  if ( (v5 & 0x3F00) != 0x2000 )
    return 0;
  KiFinalizeTimer2Disablement((int)a1);
  return 1;
}
