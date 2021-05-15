// MiExtendSection 
 
int __fastcall MiExtendSection(int *a1, __int64 *a2, int a3, int a4, __int64 a5)
{
  int v5; // r9
  unsigned __int64 *v6; // r4
  unsigned __int64 v7; // kr00_8
  unsigned int v8; // r4
  unsigned int v9; // r6
  unsigned int v10; // r5
  unsigned int v11; // r8
  int v12; // r0
  _DWORD *v13; // r7
  unsigned int v15; // r9
  unsigned int v16; // r10
  unsigned int v17; // r5
  _BYTE *v18; // r0
  _BYTE *v19; // r4
  unsigned int v20; // r1
  int v21; // r2
  __int16 v22; // r3
  unsigned int v23; // kr18_4
  int v24; // r6
  int v25; // r0
  __int16 v26; // r1
  unsigned __int64 v27; // kr20_8
  int v28; // r5
  _DWORD *v29; // r4
  unsigned int v30; // r7
  unsigned int v31; // r1
  unsigned int v32; // r3
  unsigned int v33; // r10
  unsigned int v34; // r9
  unsigned int v35; // r8
  unsigned int v36; // kr28_4
  _DWORD *v37; // r6
  _DWORD *v38; // r6
  unsigned int v39; // r0
  int v40; // r1
  int v41; // r2
  int v42; // r2
  unsigned int v43; // [sp+0h] [bp-88h]
  int v44; // [sp+4h] [bp-84h]
  unsigned int v46; // [sp+Ch] [bp-7Ch]
  _DWORD *v48; // [sp+14h] [bp-74h]
  int v49; // [sp+18h] [bp-70h]
  int v50; // [sp+1Ch] [bp-6Ch]
  _DWORD v52[2]; // [sp+28h] [bp-60h] BYREF
  _DWORD *v53; // [sp+30h] [bp-58h]

  v5 = a3;
  v48 = (_DWORD *)*a1;
  v50 = *(_DWORD *)*a1;
  __dmb(0xBu);
  v6 = (unsigned __int64 *)(v50 + 16);
  do
    v7 = __ldrexd(v6);
  while ( v7 == -1i64 && __strexd(0xFFFFFFFFFFFFFFFFui64, v6) );
  __dmb(0xBu);
  v8 = (unsigned __int64)(4 * a5 + 4095) >> 32;
  v9 = 0;
  v10 = (4 * a5 + 4095) & 0xFFFFF000;
  v11 = 0;
  v46 = v8;
  v43 = v10;
  v12 = memmove((int)v52, (int)a1, 0x44u);
  v13 = v52;
  v49 = 0;
  v44 = 0;
  if ( v5 )
    return sub_7D52E8(v12);
  v15 = 0;
  v16 = 0;
  do
  {
    if ( __PAIR64__(v8, v10) - __PAIR64__(v11, v9) > 0x2000 )
      v17 = 0x2000;
    else
      v17 = v10 - v9;
    v18 = (_BYTE *)ExAllocatePoolWithTag(512, 68, 1683189069);
    v19 = v18;
    if ( !v18 )
    {
      v28 = -1073741670;
      v29 = v53;
      goto LABEL_45;
    }
    memset(v18, 0, 68);
    *((_DWORD *)v19 + 13) = v19 + 52;
    *((_DWORD *)v19 + 14) = v19 + 52;
    v20 = v17 >> 2;
    v11 = (__PAIR64__(v11, v9) + v17) >> 32;
    v9 += v17;
    v13[2] = v19;
    *(_DWORD *)v19 = v48;
    *((_DWORD *)v19 + 7) = v17 >> 2;
    if ( __PAIR64__(v11, v9) > 4 * a5 )
    {
      v21 = (__SPAIR64__(v11, v9) >> 2) - a5;
      *((_DWORD *)v19 + 7) = v20 - v21;
      *((_DWORD *)v19 + 9) = v21;
    }
    *((_WORD *)v19 + 8) ^= (*(_BYTE *)(v50 + 10) ^ (unsigned __int8)*((_WORD *)v19 + 8)) & 0x3E;
    if ( v13 == v52 )
    {
      v15 = v13[5];
      v13[6] = v13[7];
      *((_WORD *)v13 + 9) &= 0xFu;
      v16 = *((unsigned __int16 *)v13 + 8) >> 6;
    }
    v10 = (4 * a5 + 4095) & 0xFFFFF000;
    v22 = *((_WORD *)v19 + 8);
    v23 = v15 + v13[6];
    v16 = (__PAIR64__(v16, v15) + (unsigned int)v13[6]) >> 32;
    v15 = v23;
    *((_DWORD *)v19 + 5) = v23;
    *((_WORD *)v19 + 8) = v22 & 0x3F | ((_WORD)v16 << 6);
    if ( v11 <= v46 && (v11 < v46 || v9 < v43) )
    {
      *((_DWORD *)v19 + 6) = v20;
    }
    else
    {
      *((_DWORD *)v19 + 6) = (*a2 >> 12) - v23;
      *((_WORD *)v19 + 9) = *((_WORD *)v19 + 9) & 0xF | (16 * *(_WORD *)a2);
    }
    v13 = v19;
    v8 = (unsigned __int64)(4 * a5 + 4095) >> 32;
  }
  while ( v11 <= v46 && (v11 < v46 || v9 < v43) );
  v24 = a3;
  if ( a3 && (v48[7] & 0x40000000) != 0 )
  {
    v28 = MiGetAdditionalExtents(a1);
    if ( v28 < 0 )
    {
      v29 = v53;
      goto LABEL_45;
    }
    v49 = a3;
  }
  v25 = MiAppendSubsectionChain((int)a1, v52, 0);
  if ( !v25 )
  {
LABEL_23:
    v26 = *(_WORD *)(v50 + 8);
    v27 = __PAIR64__(v26 & 0x3FF, *(_DWORD *)(v50 + 4)) + (unsigned int)v24;
    *(_DWORD *)(v50 + 4) = v27 + a5;
    *(_WORD *)(v50 + 8) = ((WORD2(a5) + __CFADD__((_DWORD)v27, (_DWORD)a5) + WORD2(v27)) ^ v26) & 0x3FF ^ v26;
    return 0;
  }
  v29 = v53;
LABEL_26:
  if ( (v25 & 1) != 0 )
  {
    v30 = 0;
    v31 = (4 * a5 + 4095) & 0xFFFFF000;
    v44 |= 1u;
    v32 = (unsigned __int64)(4 * a5 + 4095) >> 32;
    v33 = 0;
    v34 = (unsigned int)v29;
    while ( 1 )
    {
      v35 = __PAIR64__(v32, v31) - __PAIR64__(v33, v30) > 0x2000 ? 0x2000 : v31 - v30;
      v36 = v30 + v35;
      v33 = (__PAIR64__(v33, v30) + v35) >> 32;
      v30 += v35;
      v37 = (_DWORD *)ExAllocatePoolWithTag(-2147483647, v35, 1951624525);
      if ( !v37 )
        break;
      if ( (v48[7] & 0x40000000) != 0 )
      {
        v28 = MiExtendExtentSubsection((_DWORD *)v34);
        if ( v28 < 0 )
        {
          ExFreePoolWithTag((unsigned int)v37);
          goto LABEL_64;
        }
      }
      *(_WORD *)(v34 + 18) |= 1u;
      *(_DWORD *)(v34 + 4) = v37;
      MiInitializePrototypePtes(v37, v35 >> 2, v34);
      v32 = (unsigned __int64)(4 * a5 + 4095) >> 32;
      v34 = *(_DWORD *)(v34 + 8);
      v31 = (4 * a5 + 4095) & 0xFFFFF000;
      if ( v33 >= v46 && (v33 > v46 || v36 >= v43) )
      {
        v24 = a3;
        goto LABEL_36;
      }
    }
    v28 = -1073741670;
  }
  else
  {
    v44 |= 2u;
    v40 = xHalTimerWatchdogStop();
    v28 = v40;
    while ( v40 >= 0 && MiIncrementSubsectionViewCount(v41) )
    {
      v41 = *(_DWORD *)(v42 + 8);
      if ( !v41 )
      {
        if ( v24 )
        {
          v28 = v40;
          if ( v40 < 0 )
            break;
        }
LABEL_36:
        v25 = MiAppendSubsectionChain((int)a1, v52, v44);
        if ( !v25 )
          goto LABEL_23;
        goto LABEL_26;
      }
    }
  }
LABEL_64:
  if ( v49 )
    MiDeleteFileExtents(a1[3], a1[7], v49, 0);
LABEL_45:
  if ( v29 )
  {
    do
    {
      v38 = (_DWORD *)v29[2];
      if ( (v44 & 2) != 0 && v29[8] )
        MiDecrementSubsectionViewCount((int)v29);
      v39 = v29[1];
      if ( v39 )
        ExFreePoolWithTag(v39);
      MiDeleteSubsection((int)v29);
      v29 = v38;
    }
    while ( v38 );
  }
  return v28;
}
