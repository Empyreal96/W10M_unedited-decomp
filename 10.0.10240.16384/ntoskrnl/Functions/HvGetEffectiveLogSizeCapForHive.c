// HvGetEffectiveLogSizeCapForHive 
 
int __fastcall HvGetEffectiveLogSizeCapForHive(int a1)
{
  unsigned int v1; // r2
  unsigned int v2; // r0
  int v3; // r1
  unsigned int v4; // r3
  int v5; // r4
  unsigned int v6; // r1
  int v7; // off

  v1 = *(_DWORD *)(a1 + 116);
  v2 = *(_DWORD *)(a1 + 952);
  v3 = 0x2000;
  if ( v2 < 0x2000 )
    v3 = v2;
  v4 = 8 * v3;
  v5 = 0;
  v6 = v2 - v3;
  if ( v6 )
  {
    v7 = (v4 + (unsigned __int64)(v6 >> 2)) >> 32;
    v4 += v6 >> 2;
    v5 = v7;
  }
  if ( !v5 && v4 < v1 )
    v1 = v4;
  if ( CmpLogFileSizeCap < v1 )
    return sub_7D4098();
  if ( v1 < 0x8000 )
    v1 = 0x8000;
  return v1;
}
