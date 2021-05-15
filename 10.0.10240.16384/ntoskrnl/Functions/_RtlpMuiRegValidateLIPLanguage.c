// _RtlpMuiRegValidateLIPLanguage 
 
int __fastcall RtlpMuiRegValidateLIPLanguage(int a1, int a2, int a3, int a4)
{
  int v5; // r3
  int v6; // r8
  _WORD *v7; // r4
  int v8; // r5
  unsigned int v9; // r6
  int v10; // r1
  _WORD *v11; // r7
  int v12; // r2
  int v13; // r1
  _WORD *v14; // r1
  __int16 v15; // r3
  int v16; // r9
  __int16 v17; // r1
  __int16 v18; // r3
  int result; // r0
  int v20; // [sp+0h] [bp-28h] BYREF
  int v21; // [sp+4h] [bp-24h]
  int v22; // [sp+8h] [bp-20h]

  v20 = a2;
  v21 = a3;
  v22 = a4;
  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 20) + 12);
  v21 = a1;
  v6 = 0;
  v7 = (_WORD *)(v5 + 28 * a2);
  v8 = 0;
  while ( 1 )
  {
    v9 = (unsigned __int16)v7[4];
    v10 = (v9 >> v8) & 3;
    if ( v10 )
      break;
LABEL_25:
    v8 += 2;
    if ( v8 >= 8 )
      goto LABEL_28;
  }
  v11 = &v7[v8 / 2u];
  v12 = (__int16)v7[v8 / 2u + 6];
  if ( v10 != 2 )
  {
    v16 = *(_DWORD *)(a1 + 20);
    LOWORD(v20) = -1;
    if ( RtlpMuiRegGetInstalledLangInfoIndex(v16, v10, v12, &v20) < 0
      || (v17 = v20, (v20 & 0x8000u) != 0)
      || (__int16)v20 >= (int)*(unsigned __int16 *)(v16 + 6)
      || (__int16)v20 == a2
      || (v18 = *(_WORD *)(*(_DWORD *)(v16 + 12) + 28 * (__int16)v20), (v18 & 4) != 0) )
    {
      a1 = v21;
LABEL_24:
      v7[4] = v9 & ~(3 << v8);
      goto LABEL_25;
    }
    a1 = v21;
    if ( (v18 & 0x1820) != 2080 )
      goto LABEL_24;
    v7[4] = (2 << v8) | v9 & ~(3 << v8);
    v11[6] = v17;
LABEL_22:
    ++v6;
    goto LABEL_25;
  }
  if ( v12 < 0 )
    goto LABEL_13;
  v13 = *(_DWORD *)(a1 + 20);
  if ( v12 >= *(unsigned __int16 *)(v13 + 6) || v12 == a2 )
    goto LABEL_13;
  v14 = (_WORD *)(*(_DWORD *)(v13 + 12) + 28 * v12);
  if ( (*v14 & 4) == 0 )
  {
    if ( (*v14 & 0x1820) == 2080 )
      goto LABEL_22;
    if ( v14[2] )
    {
      v7[4] = (1 << v8) | v9 & ~(3 << v8);
      v15 = v14[2];
LABEL_14:
      v11[6] = v15;
      goto LABEL_25;
    }
    if ( (__int16)v14[3] > 0 )
    {
      v7[4] = v9 & ~(3 << v8) | (3 << v8);
      v15 = v14[3];
      goto LABEL_14;
    }
LABEL_13:
    v7[4] = v9 & ~(unsigned __int16)(3 << v8);
    v15 = 0;
    goto LABEL_14;
  }
  *v7 |= 0x1000u;
LABEL_28:
  if ( v6 >= 1 )
    return 0;
  result = -1073741823;
  *v7 |= 0x1000u;
  return result;
}
