// sub_969C5C 
 
void __fastcall sub_969C5C(int a1)
{
  _DWORD *v1; // r4
  int v2; // r5
  int v3; // r0
  __int16 v4; // r7

  if ( v1 < &v1[a1] )
  {
    v3 = *(_DWORD *)v2 + 24 * (*v1 >> 12);
    if ( (*v1 & 1) == 0 )
    {
      v4 = 6;
      if ( (*(_WORD *)(v2 + 18) & 3) != 0 )
        v4 = 3;
      *(_DWORD *)(v3 + 8) ^= ((unsigned __int16)*(_DWORD *)(v3 + 8) ^ (unsigned __int16)(32 * v4)) & 0x3E0;
      if ( (*(_WORD *)(v2 + 18) & 3) != 0 )
        MiMarkPfnVerified(v3, 0);
      JUMPOUT(0x953460);
    }
    JUMPOUT(0x95346A);
  }
  JUMPOUT(0x95347E);
}
