// sub_51A2A8 
 
void __fastcall sub_51A2A8(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r6

  v4 = *(_DWORD *)(a3 + 128);
  *(_DWORD *)(a2 + 4) = 0xFFFFF;
  *(_DWORD *)(a2 + 8) = v4;
  if ( v4 == 0xFFFFF )
    *(_DWORD *)(a3 + 124) = v3;
  else
    *(_DWORD *)(*(_DWORD *)(a1 + 252) + 16 * v4 + 4) = v3;
  *(_DWORD *)(a3 + 128) = v3;
  JUMPOUT(0x43FB58);
}
