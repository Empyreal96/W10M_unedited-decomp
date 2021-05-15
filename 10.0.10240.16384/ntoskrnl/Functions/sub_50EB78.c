// sub_50EB78 
 
void __fastcall sub_50EB78(int a1, unsigned int a2)
{
  int v2; // r4
  int v3; // r2

  while ( 1 )
  {
    v3 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 16 + 4 * (31 - __clz(a2))) + 2360) + 260);
    if ( (v3 & a2) != v3 )
      break;
    a2 &= ~v3;
    if ( !a2 )
      JUMPOUT(0x4C47CA);
  }
  JUMPOUT(0x4C47F6);
}
