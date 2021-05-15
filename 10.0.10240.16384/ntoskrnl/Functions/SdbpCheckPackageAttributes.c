// SdbpCheckPackageAttributes 
 
int __fastcall SdbpCheckPackageAttributes(BOOL *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // r4
  __int16 *v7; // r3
  BOOL v8; // r9
  unsigned int v9; // r2
  unsigned int v10; // r7
  unsigned int v11; // r6
  int v12; // r4
  unsigned __int16 *v13; // r5
  unsigned __int64 v14; // r0
  __int64 v15; // r0
  int v16; // r0
  int v17; // r0
  __int64 v18; // r0
  _WORD *v19; // r0
  __int64 v20; // r0
  int result; // r0
  int v22; // [sp+0h] [bp-38h]
  int v23; // [sp+4h] [bp-34h]
  __int16 *i; // [sp+8h] [bp-30h]
  int v25; // [sp+Ch] [bp-2Ch]
  int v26; // [sp+10h] [bp-28h] BYREF
  int v27; // [sp+14h] [bp-24h]
  BOOL *v28; // [sp+18h] [bp-20h]

  v22 = a2;
  v28 = a1;
  v6 = *(_DWORD *)(a6 + 44);
  *a1 = 0;
  v25 = 0;
  v7 = &word_41D4E0;
  v8 = 1;
  v23 = v6;
  for ( i = &word_41D4E0; ; ++i )
  {
    v27 = SdbFindFirstTag(*(_DWORD *)(a2 + 4), a5, (unsigned __int16)*v7);
    if ( v27 )
      break;
LABEL_36:
    a2 = v22;
    v7 = i + 1;
    if ( (unsigned int)++v25 >= 0xA )
    {
      result = 1;
      *v28 = v8;
      return result;
    }
  }
  v10 = *(_DWORD *)(v6 + 8);
  v11 = 0;
  if ( !v10 )
    return 0;
  v12 = (unsigned __int16)*i;
  do
  {
    v13 = 0;
    if ( v11 < v10 )
    {
      v14 = *(unsigned int *)(v23 + 4) * (unsigned __int64)v11;
      if ( ULongLongToULong(v14, SHIDWORD(v14), &v26) < 0
        || (v9 = *(_DWORD *)(v23 + 20), v13 = (unsigned __int16 *)(v9 + v26), v9 + v26 < v9) )
      {
        v13 = 0;
      }
    }
    if ( *v13 == v12 )
      break;
    ++v11;
  }
  while ( v11 < v10 );
  if ( v12 <= 20503 )
  {
    switch ( v12 )
    {
      case 20503:
        goto LABEL_21;
      case 16453:
        v17 = SdbReadDWORDTag(*(_DWORD *)(v22 + 4), v27, -1);
        if ( v17 == -1 )
          return 0;
        v16 = v17 == *((_DWORD *)v13 + 2);
        goto LABEL_31;
      case 20500:
LABEL_21:
        v18 = SdbReadQWORDTag(*(_DWORD *)(v22 + 4), v27, -1, -1);
        if ( ((unsigned int)v18 & HIDWORD(v18)) == -1 )
          return 0;
        v16 = SdbpCheckVersion();
        goto LABEL_31;
    }
    if ( v12 != 20501 )
    {
      if ( v12 != 20502 )
        return 0;
      goto LABEL_17;
    }
LABEL_29:
    v20 = SdbReadQWORDTag(*(_DWORD *)(v22 + 4), v27, -1, -1);
    if ( ((unsigned int)v20 & HIDWORD(v20)) == -1 )
      return 0;
    v16 = SdbpCheckFromVersion();
    goto LABEL_31;
  }
  if ( v12 == 20504 )
    goto LABEL_29;
  if ( v12 == 20505 )
  {
LABEL_17:
    v15 = SdbReadQWORDTag(*(_DWORD *)(v22 + 4), v27, -1, -1);
    if ( ((unsigned int)v15 & HIDWORD(v15)) == -1 )
      return 0;
    v16 = SdbpCheckUptoVersion();
    goto LABEL_31;
  }
  if ( v12 > 24616 && v12 <= 24619 )
  {
    v19 = (_WORD *)SdbGetStringTagPtr(*(_DWORD *)(v22 + 4), v27, v9, v22);
    if ( v19 )
    {
      v16 = AslStringPatternMatchW(v19, *((_WORD **)v13 + 2));
LABEL_31:
      v8 = v8 && v16;
      v6 = v23;
      goto LABEL_36;
    }
  }
  return 0;
}
