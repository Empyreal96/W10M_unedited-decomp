// sub_5109AC 
 
void __fastcall sub_5109AC(int a1, __int16 a2, unsigned int a3)
{
  int v3; // r4
  int v4; // r6
  unsigned int v5; // r0
  _DWORD *v6; // r3

  v5 = *(_DWORD *)(v4 + 16);
  if ( v5 )
  {
    if ( ((v5 - 1) & v5) == 0 && v5 <= a3 )
    {
      v6 = *(_DWORD **)(v4 + 36);
      if ( v6 )
      {
        if ( *v6 == v3 && (a2 & 0x100) == 0 )
          JUMPOUT(0x42875E);
      }
    }
  }
  JUMPOUT(0x428986);
}
