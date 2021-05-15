// _RtlpMuiRegValidatePartialLanguage 
 
int __fastcall RtlpMuiRegValidatePartialLanguage(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int v5; // r3
  _WORD *v7; // r6
  int i; // r5
  unsigned int v9; // r8
  int v10; // r1
  int v11; // r2
  int v12; // r10
  __int16 v13; // r1
  int result; // r0
  int v15; // [sp+0h] [bp-28h] BYREF
  int v16; // [sp+4h] [bp-24h]
  int v17; // [sp+8h] [bp-20h]

  v15 = a2;
  v16 = a3;
  v17 = a4;
  v4 = 0;
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 12);
  v16 = a1;
  v7 = (_WORD *)(v5 + 28 * a2);
  for ( i = 0; i < 4; ++i )
  {
    v9 = (unsigned __int16)v7[4];
    v10 = (v9 >> (i * 2)) & 3;
    if ( !v10 )
      continue;
    v11 = (__int16)v7[i + 6];
    if ( v10 == 2 )
    {
      if ( v11 == a2 )
      {
        v7[4] = v9 & ~(3 << (i * 2));
        continue;
      }
      goto LABEL_12;
    }
    v12 = *(_DWORD *)(a1 + 20);
    LOWORD(v15) = -1;
    if ( RtlpMuiRegGetInstalledLangInfoIndex(v12, v10, v11, &v15) < 0 )
    {
      ++v4;
    }
    else
    {
      v13 = v15;
      if ( (v15 & 0x8000u) == 0 && (__int16)v15 < (int)*(unsigned __int16 *)(v12 + 6) && (__int16)v15 != a2 )
      {
        a1 = v16;
        if ( (*(_WORD *)(*(_DWORD *)(v12 + 12) + 28 * (__int16)v15) & 1) != 0 )
        {
          v7[4] = (2 << (i * 2)) | v9 & ~(3 << (i * 2));
          v7[i + 6] = v13;
        }
LABEL_12:
        ++v4;
        continue;
      }
    }
    a1 = v16;
  }
  if ( v4 >= 1 )
    return 0;
  result = -1073741823;
  *v7 |= 0x1000u;
  return result;
}
