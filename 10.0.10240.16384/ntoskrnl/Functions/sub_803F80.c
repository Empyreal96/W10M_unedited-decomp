// sub_803F80 
 
void __fastcall sub_803F80(int a1, _BYTE *a2, _DWORD *a3)
{
  int v3; // r5
  int v4; // r7
  int v5; // r8
  int v6; // r9
  int v7; // lr
  int v8; // r3

  if ( *a2 || (*a3 & v7) != 0 )
  {
    v8 = v4 - v3 + v6;
    *(_DWORD *)v3 = v8;
    memset((_BYTE *)(v3 + 4), 0, v8 - 4);
    *(_DWORD *)(*(_DWORD *)(v5 + 32) + 4088) |= 4u;
    JUMPOUT(0x7495EE);
  }
  JUMPOUT(0x7495CE);
}
