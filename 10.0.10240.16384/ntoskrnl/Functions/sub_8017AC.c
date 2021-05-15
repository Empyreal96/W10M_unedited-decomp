// sub_8017AC 
 
void __fastcall sub_8017AC(int a1, int a2, _DWORD *a3)
{
  unsigned int v3; // r8
  int v4; // r0

  if ( (a3[4] & 0x40000) == 0 )
  {
    v4 = *a3 + 24 * (*(_DWORD *)(((v3 >> 10) & 0x3FFFFC) - 0x40000000) >> 12);
    if ( (*(_BYTE *)(v4 + 23) & 7) == 3 )
      MiMarkPfnVerified(v4, 1);
  }
  JUMPOUT(0x73F39A);
}
