// CmpAdjustRequestedFileSize 
 
int __fastcall CmpAdjustRequestedFileSize(int a1, int a2, unsigned int a3, int a4, unsigned __int64 a5)
{
  int v5; // r7
  unsigned int v7; // r0
  unsigned __int64 v8; // r4
  int v9; // r10
  int v11; // r8
  unsigned int v13; // kr00_4

  v5 = a5;
  HIDWORD(v8) = a4;
  v7 = 0;
  LODWORD(v8) = a3;
  v9 = 0;
  v11 = 0;
  if ( __PAIR64__(HIDWORD(v8), a3) == a5 )
    return v5;
  if ( a2 )
  {
    if ( a2 == 4 || a2 == 5 || a2 == 1 )
      v7 = HvGetEffectiveLogSizeCapForHive(a1);
LABEL_5:
    if ( !v8 )
      goto LABEL_6;
    goto LABEL_13;
  }
  v11 = 0x40000;
  v7 = 0x40000;
  if ( (*(_DWORD *)(a1 + 3228) & 0x80) != 0 )
  {
LABEL_27:
    v9 = 1;
    v11 = 4096;
    goto LABEL_5;
  }
  if ( !v8 )
  {
    if ( a5 > 0x40000 )
      goto LABEL_5;
    goto LABEL_27;
  }
LABEL_13:
  if ( v8 < a5 && a5 <= v7 && !v9 )
  {
    if ( !a2 )
      v11 = 4096;
    while ( 1 )
    {
      v13 = v8;
      v8 *= 2i64;
      if ( !is_mul_ok(2u, v13) || (unsigned int)v8 > v7 )
        break;
      if ( v8 >= (unsigned int)a5 )
        goto LABEL_7;
    }
    LODWORD(v8) = v7;
    goto LABEL_7;
  }
LABEL_6:
  LODWORD(v8) = a5;
LABEL_7:
  if ( v11 )
    LODWORD(v8) = (v8 + v11 - 1) & ~(v11 - 1);
  return v8;
}
