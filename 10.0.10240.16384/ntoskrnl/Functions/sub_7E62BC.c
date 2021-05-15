// sub_7E62BC 
 
void __fastcall sub_7E62BC(int a1, int a2, int a3)
{
  int v3; // r9
  unsigned int v4; // r1
  int v5; // r1

  v4 = *(_DWORD *)(v3 + 8);
  if ( (v4 & 0x400) != 0 )
    v5 = (*(unsigned __int16 *)((*(_DWORD *)(v3 + 8) & 0xFFFFF800 | (2 * (*(_DWORD *)(v3 + 8) & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v5 = (v4 >> 5) & 0x1F;
  if ( (v5 & a3) == 0 && MiCanPageMove(v3) )
    JUMPOUT(0x6F18BE);
  JUMPOUT(0x6F17F8);
}
