// sub_514C44 
 
void __fastcall sub_514C44(int a1)
{
  __int16 v1; // r8
  __int16 v2; // r2
  int v3; // r1

  v2 = *(_WORD *)(a1 + 14);
  if ( (v2 & 4) == 0 )
  {
    v3 = *(unsigned __int16 *)(a1 + 12);
    if ( v3 == 0xFFFF )
      *(_WORD *)(a1 + 14) = v2 | v1;
    else
      *(_WORD *)(a1 + 12) = v3 + 1;
    *(_WORD *)(a1 + 14) |= 4u;
  }
  JUMPOUT(0x431ED2);
}
