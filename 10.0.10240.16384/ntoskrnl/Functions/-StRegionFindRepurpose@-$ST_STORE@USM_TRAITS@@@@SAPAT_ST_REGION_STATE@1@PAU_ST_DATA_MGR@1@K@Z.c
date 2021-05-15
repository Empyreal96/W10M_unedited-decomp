// -StRegionFindRepurpose@-$ST_STORE@USM_TRAITS@@@@SAPAT_ST_REGION_STATE@1@PAU_ST_DATA_MGR@1@K@Z 
 
__int16 *__fastcall ST_STORE<SM_TRAITS>::StRegionFindRepurpose(_DWORD *a1, int a2)
{
  int v2; // r5
  unsigned int v3; // r8
  int v4; // r6
  int v5; // lr
  char *v6; // r0
  __int16 *v7; // r4
  int v8; // r1
  unsigned int i; // r7
  __int64 v10; // kr00_8
  unsigned int v11; // r6
  unsigned int v12; // r0
  int v13; // r3
  _DWORD *v14; // lr
  int j; // r3
  unsigned int v16; // r2
  int v17; // r0
  unsigned __int64 v18; // r2
  char v20[2]; // [sp+0h] [bp-40h] BYREF
  __int16 v21; // [sp+2h] [bp-3Eh] BYREF
  char *v22; // [sp+4h] [bp-3Ch]
  int v23; // [sp+8h] [bp-38h]
  int v24; // [sp+Ch] [bp-34h]
  int v25; // [sp+10h] [bp-30h]
  int v26; // [sp+14h] [bp-2Ch]
  unsigned int v27; // [sp+18h] [bp-28h]
  unsigned int v28; // [sp+1Ch] [bp-24h]

  v2 = (int)a1;
  v3 = a1[32];
  v4 = a1[76];
  v5 = a1[78];
  v21 ^= (a1[26] ^ v21) & 0x1FFF;
  v6 = v20;
  v7 = &v21;
  v8 = a2 - 1;
  v20[0] = -1;
  v24 = v2;
  v25 = v4;
  v26 = v5;
  v27 = v3;
  v22 = v20;
  for ( i = 0; i < v3; ++i )
  {
    if ( *(_BYTE *)(v2 + 72) )
    {
      v10 = *(_QWORD *)(v2 + 120);
      if ( v8 + 1 < (unsigned int)v10 )
        v11 = v8 + 1;
      else
        v11 = 0;
      v12 = v10 - 1;
      v23 = *(_DWORD *)(v2 + 124);
      while ( 1 )
      {
        if ( v12 - v11 == -1 )
          goto LABEL_10;
        v14 = (_DWORD *)(HIDWORD(v10) + 4 * (v11 >> 5));
        for ( j = ~*v14 | ((1 << (v11 & 0x1F)) - 1); j == -1; j = ~*v14 )
        {
          if ( (unsigned int)++v14 > HIDWORD(v10) + 4 * (v12 >> 5) )
            goto LABEL_10;
        }
        v16 = __clz(__rbit(~j));
        v13 = v16 + 32 * (((int)v14 - HIDWORD(v10)) >> 2);
        v28 = v16;
        if ( v13 > v12 )
        {
LABEL_10:
          v13 = -1;
        }
        else if ( v13 != -1 )
        {
          break;
        }
        if ( !v11 )
          break;
        v17 = v8 + 2;
        if ( v8 + 2 > (unsigned int)v10 )
          v17 = v10;
        v12 = v17 - 1;
        v11 = 0;
      }
      v2 = v24;
      if ( v13 <= v8 )
        v13 = *(_DWORD *)(v24 + 84);
      v4 = v25;
      v5 = v26;
      v6 = v22;
      v3 = v27;
      v8 = v13;
    }
    else
    {
      ++v8;
    }
    if ( v8 == *(_DWORD *)(v2 + 84) )
    {
      v8 = -1;
      --i;
    }
    else if ( (*(_WORD *)(v4 + 2 * v8) & 0xC000) == 0 )
    {
      if ( (*(_WORD *)(v4 + 2 * v8) & 0x1FFF) == 0 )
      {
        v7 = (__int16 *)(v4 + 2 * v8);
        break;
      }
      HIDWORD(v18) = *(unsigned __int8 *)(v8 + v5);
      LODWORD(v18) = *(_WORD *)(v4 + 2 * v8) & 0x1FFF;
      if ( v18 > __PAIR64__((unsigned __int8)*v6, *v7 & 0x1FFF) )
      {
        v6 = v22;
      }
      else
      {
        v6 = (char *)(v8 + v5);
        v22 = (char *)(v8 + v5);
        v7 = (__int16 *)(v4 + 2 * v8);
      }
    }
  }
  if ( v7 == &v21 )
    v7 = 0;
  return v7;
}
