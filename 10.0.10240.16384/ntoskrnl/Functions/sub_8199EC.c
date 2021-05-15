// sub_8199EC 
 
void __fastcall sub_8199EC(int a1)
{
  _DWORD *v1; // r3
  _DWORD *v2; // r5
  _DWORD *v3; // r4

  *(_DWORD *)(a1 + 32) = 0;
  *(_WORD *)(a1 + 44) = 0;
  v1 = *(_DWORD **)(a1 + 36);
  v2 = (_DWORD *)(a1 + 36);
  if ( v1 != (_DWORD *)(a1 + 36) )
  {
    do
    {
      v3 = (_DWORD *)*v1;
      FsRtlFreeTunnelNode((unsigned int)(v1 - 3));
      v1 = v3;
    }
    while ( v3 != v2 );
  }
  *v2 = v2;
  v2[1] = v2;
  JUMPOUT(0x7B5B32);
}
