// KiFindNextTimerDueTime 
 
int __fastcall KiFindNextTimerDueTime(int a1, int a2, unsigned int a3, unsigned int a4, char a5)
{
  int v6; // r8
  unsigned int v7; // r4
  unsigned int v8; // r7
  int v9; // lr
  int v11; // r3
  unsigned int v12; // r1
  unsigned int v13; // r8
  unsigned int v14; // r10
  int v15; // r1
  unsigned int v16; // r9
  _DWORD *v17; // r4
  int v18; // r2
  unsigned int v19; // r0
  unsigned __int64 v20; // kr08_8
  int v21; // r3
  int v22; // r9
  int v23; // r2
  unsigned __int16 v24; // r6
  unsigned int v25; // r9
  unsigned int v26; // r10
  int *v27; // r3
  unsigned int v28; // r2
  unsigned int v29; // r0
  unsigned int v30; // r1
  _DWORD *v31; // r9
  int i; // r3
  unsigned int v33; // r3
  unsigned int v34; // r3
  unsigned int v35; // r1
  int v36; // r1
  unsigned int v37; // r10
  int *v38; // r3
  unsigned int v39; // r9
  int v40; // r2
  unsigned int v41; // r0
  int v42; // r5
  unsigned int v43; // r1
  _DWORD *v44; // r5
  int v45; // r3
  unsigned int v46; // r3
  unsigned int v47; // r2
  unsigned int v48; // r1
  int v49; // [sp+0h] [bp-38h]
  int v50; // [sp+0h] [bp-38h]
  unsigned int v51; // [sp+4h] [bp-34h]
  int v52; // [sp+4h] [bp-34h]
  int *v53; // [sp+4h] [bp-34h]
  int v54; // [sp+8h] [bp-30h]
  unsigned int v56; // [sp+Ch] [bp-2Ch]
  int v57; // [sp+Ch] [bp-2Ch]
  unsigned int v58; // [sp+10h] [bp-28h]
  unsigned int v59; // [sp+10h] [bp-28h]

  v6 = (unsigned __int8)(a3 >> 18);
  v7 = a3;
  v8 = -1;
  v9 = -1;
  if ( !KiSerializeTimerExpiration )
  {
    if ( v6 != *(unsigned __int8 *)(a1 + 1760) )
      return sub_54208C();
    if ( a5 )
    {
      v23 = 0;
      v24 = 0;
      v25 = v6 << 10;
      v26 = -1;
      while ( 1 )
      {
        v27 = &KiPendingTimerBitmaps[2 * v23];
        v28 = *v27;
        v49 = *v27;
        if ( v25 < *v27 )
          v29 = v25;
        else
          v29 = 0;
        v30 = v28 - 1;
        v52 = v27[1];
        while ( 1 )
        {
          if ( v30 - v29 == -1 )
            goto LABEL_52;
          v31 = (_DWORD *)(v52 + 4 * (v29 >> 5));
          for ( i = ~*v31; !*v31; i = ~*v31 )
          {
            if ( (unsigned int)++v31 > v52 + 4 * (v30 >> 5) )
              goto LABEL_51;
          }
          v33 = __clz(__rbit(~i)) + 32 * (((int)v31 - v52) >> 2);
          if ( v33 <= v30 && v33 != -1 )
            break;
          v28 = v49;
LABEL_51:
          v25 = v6 << 10;
LABEL_52:
          if ( !v29 )
            goto LABEL_47;
          v35 = v25 + 1;
          if ( v25 + 1 > v28 )
            v35 = v28;
          v30 = v35 - 1;
          v29 = 0;
        }
        v34 = (unsigned __int8)((v33 >> 10) - v6);
        v25 = v6 << 10;
        if ( v34 < v26 )
          v26 = v34;
LABEL_47:
        v23 = ++v24;
        if ( v24 >= (unsigned int)(unsigned __int16)KiActiveGroups )
        {
          if ( v26 != -1 )
            v8 = (a3 & 0xFFFC0000) + (v26 << 18) + KeTimeIncrement;
          return v8;
        }
      }
    }
    v36 = *(unsigned __int8 *)(a1 + 1052);
    v54 = *(_DWORD *)(a1 + 1048);
    v37 = 0;
    v57 = KiPendingTimerBitmaps[2 * v36 + 1];
    v38 = &KiPendingTimerBitmaps[2 * v36];
    v53 = v38;
LABEL_57:
    v39 = *v38;
    v40 = v6 << 10;
    if ( v6 << 10 < (unsigned int)*v38 )
      v41 = v6 << 10;
    else
      v41 = 0;
    v42 = v38[1];
    v43 = v39 - 1;
    v50 = v42;
    while ( 1 )
    {
      if ( v43 - v41 != -1 )
      {
        v59 = v42 + 4 * (v43 >> 5);
        v44 = (_DWORD *)(v42 + 4 * (v41 >> 5));
        v45 = ~*v44;
        if ( *v44 )
        {
LABEL_65:
          v46 = __clz(__rbit(~v45)) + 32 * (((int)v44 - v50) >> 2);
          if ( v46 <= v43 && v46 != -1 )
          {
            v47 = v46 >> 10;
            v37 += (unsigned __int8)((v46 >> 10) - v6) + 1;
            if ( v37 > 0x100 )
              return v8;
            if ( (*(_DWORD *)((v47 << 7) + v57) & v54) != 0 )
              return v7 + (v37 << 18);
            v6 = (unsigned __int8)(v47 + 1);
            v38 = v53;
            goto LABEL_57;
          }
          v40 = v6 << 10;
        }
        else
        {
          while ( (unsigned int)++v44 <= v59 )
          {
            v45 = ~*v44;
            if ( *v44 )
              goto LABEL_65;
          }
        }
        v42 = v50;
      }
      if ( !v41 )
        return v8;
      v48 = v40 + 1;
      if ( v40 + 1 > v39 )
        v48 = v39;
      v43 = v48 - 1;
      v41 = 0;
    }
  }
  if ( !a5 )
    return v8;
  v11 = *(_DWORD *)(a1 + 1760);
  v12 = (unsigned __int8)(v6 - v11);
  if ( v12 > 1 )
    return sub_54208C();
  v13 = (unsigned __int8)v11;
  v51 = 0;
  v58 = (a3 & 0xFFFC0000) - (v12 << 18) + 0x4000000;
  v56 = (__PAIR64__(a4, a3 & 0xFFFC0000) - (v12 << 18) + 0x4000000) >> 32;
  while ( 2 )
  {
    if ( v13 >= KiPendingTimerBitmaps[0] )
      v14 = 0;
    else
      v14 = v13;
    v15 = dword_681F84;
    v16 = KiPendingTimerBitmaps[0] - 1;
    while ( 1 )
    {
      if ( v16 - v14 == -1 )
        goto LABEL_23;
      v17 = (_DWORD *)(v15 + 4 * (v14 >> 5));
      v18 = ~*v17 | ((1 << (v14 & 0x1F)) - 1);
      if ( v18 != -1 )
        break;
      while ( (unsigned int)++v17 <= v15 + 4 * (v16 >> 5) )
      {
        v18 = ~*v17;
        if ( *v17 )
          goto LABEL_12;
      }
      v15 = dword_681F84;
LABEL_23:
      if ( !v14 )
        return v8;
      v22 = v13 + 1;
      if ( v13 + 1 > KiPendingTimerBitmaps[0] )
        v22 = KiPendingTimerBitmaps[0];
      v16 = v22 - 1;
      v14 = 0;
    }
LABEL_12:
    v15 = dword_681F84;
    v19 = __clz(__rbit(~v18)) + 32 * (((int)v17 - dword_681F84) >> 2);
    if ( v19 > v16 || v19 == -1 )
      goto LABEL_23;
    v51 += (unsigned __int8)(v19 - v13 + 1);
    if ( v51 > 0x100 )
      return v8;
    v20 = *((_QWORD *)KiProcessorBlock + 3 * v19 + 546);
    if ( v20 >= __PAIR64__(v9, v8) )
      goto LABEL_28;
    if ( v20 >= __PAIR64__(v56, v58) )
    {
      v9 = HIDWORD(v20);
      v8 = v20;
      goto LABEL_28;
    }
    v21 = (unsigned __int8)((unsigned int)v20 >> 18);
    if ( v21 != v19 )
    {
      if ( __PAIR64__(HIDWORD(v20), ((v19 - v21) << 18) & 0x3FC0000) + ((unsigned int)v20 & 0xFFFC0000) < __PAIR64__(v9, v8) )
      {
        v8 = (((v19 - v21) << 18) & 0x3FC0000) + (v20 & 0xFFFC0000);
        v13 = (unsigned __int8)(v19 + 1);
        v9 = (__PAIR64__(HIDWORD(v20), ((v19 - v21) << 18) & 0x3FC0000) + ((unsigned int)v20 & 0xFFFC0000)) >> 32;
        continue;
      }
LABEL_28:
      v13 = (unsigned __int8)(v19 + 1);
      continue;
    }
    return v20;
  }
}
