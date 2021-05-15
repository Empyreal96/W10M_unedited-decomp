// sub_50A884 
 
void __fastcall sub_50A884(unsigned int a1)
{
  int v1; // r8
  unsigned int v2; // r10
  int i; // lr
  unsigned int v4; // r2

  if ( (a1 & v2) == 0 )
    a1 = v2;
  if ( (*(_DWORD *)(v1 + 580) & a1) != 0 )
    a1 &= *(_DWORD *)(v1 + 580);
  for ( i = 0; a1; a1 &= ~(1 << v4) )
  {
    v4 = __clz(__rbit(a1));
    i |= *(_DWORD *)(*(_DWORD *)(v1 + 600) + 4 * v4);
  }
  JUMPOUT(0x446180);
}
