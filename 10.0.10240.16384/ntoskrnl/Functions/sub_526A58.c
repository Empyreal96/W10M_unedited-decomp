// sub_526A58 
 
void __fastcall sub_526A58(int a1)
{
  __int16 v1; // r3

  v1 = *(_WORD *)(a1 + 2);
  if ( (v1 & 1) == 0 && (v1 & 2) == 0 )
    JUMPOUT(0x461E24);
  JUMPOUT(0x461E26);
}
