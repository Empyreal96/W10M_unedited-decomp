// MiParseComImage 
 
int __fastcall MiParseComImage(int a1, _DWORD *a2, _BYTE *a3)
{
  _BYTE *v3; // r8
  int v5; // r6
  unsigned int v6; // r4
  unsigned int v7; // r3
  int v8; // r4
  int v9; // r4
  int v10; // r1
  int v11; // r2
  int v12; // r2
  char v13; // r3
  char v14; // r3
  int v18[10]; // [sp+8h] [bp-88h] BYREF
  int v19; // [sp+30h] [bp-60h] BYREF
  unsigned __int16 v20; // [sp+34h] [bp-5Ch]
  unsigned __int16 v21; // [sp+36h] [bp-5Ah]
  int v22; // [sp+40h] [bp-50h]

  v3 = a3;
  v5 = a1;
  *a3 = 0;
  v6 = a2[17];
  if ( !v6 )
    return 0;
  if ( (v6 & 3) != 0 )
    return 0;
  v7 = a2[18];
  if ( !v7 || v7 < 0x48 || v7 + v6 <= v6 || v6 + 72 > a2[3] )
    return 0;
  v8 = MiMapImageInSystemSpace(a1, 3, v18);
  if ( v8 >= 0 )
  {
    v9 = MI_REFERENCE_CONTROL_AREA_FILE(v5);
    MiLogRelocationRva(a2[17], 72, v9, v5, a3, a1);
    MI_DEREFERENCE_CONTROL_AREA_FILE(v5, v9);
    v8 = 0;
    memmove((int)&v19, v18[0] + a2[17], 0x48u);
    MiUnmapImageInSystemSpace(v18);
    v10 = v22;
    if ( (v22 & 1) != 0 )
    {
      *v3 = 1;
      v11 = *(_DWORD *)v5;
      *(_BYTE *)(*(_DWORD *)v5 + 11) |= 1u;
      if ( v20 > 2u || v20 == 2 && v21 >= 5u )
      {
        v12 = *(_DWORD *)(v11 + 36);
        v13 = *(_BYTE *)(v12 + 35) | 2;
        *(_BYTE *)(v12 + 35) = v13;
        if ( (v10 & 2) == 0 || (v10 & 0x20000) != 0 )
        {
          v14 = v13 | 1;
          *(_BYTE *)(v12 + 35) = v14;
          if ( (v10 & 0x20000) != 0 )
            *(_BYTE *)(v12 + 35) = v14 | 0x20;
        }
      }
    }
  }
  return v8;
}
