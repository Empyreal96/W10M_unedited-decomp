// RaspScanConvert 
 
int __fastcall RaspScanConvert(int a1, int a2, int a3, int a4, char a5, int *a6, int *a7, int a8)
{
  int result; // r0
  int v11; // r6
  int v12; // r4
  int v13; // r3
  int v14; // r9
  int v15; // r10
  int v16; // r0
  int v17; // r2
  int v18; // r6
  int v19; // r4
  _DWORD *v20; // r1
  int v21; // r5
  int v22; // r8
  int v23; // r6
  int v24; // r0
  int v25; // r5
  int *v26; // r10
  unsigned int v27; // r9
  int v28; // r5
  int v29; // r1
  int v30; // r5
  _DWORD *v31; // r6
  int v32; // r7
  _BYTE *v33; // r4
  unsigned int v34; // r2
  int *v35; // r0
  int v36; // r1
  int v38; // r3
  int v39; // r0
  int v40; // r4
  int v41; // r3
  int v42; // r9
  unsigned int v43; // r4
  int *v44; // r5
  int v45; // r10
  int v46; // r2
  int v47; // [sp+8h] [bp-60h] BYREF
  _DWORD *v48; // [sp+Ch] [bp-5Ch] BYREF
  int v49; // [sp+10h] [bp-58h] BYREF
  int v50; // [sp+14h] [bp-54h]
  int *v51; // [sp+18h] [bp-50h]
  int v52; // [sp+1Ch] [bp-4Ch]
  unsigned int v53; // [sp+20h] [bp-48h]
  int v54; // [sp+24h] [bp-44h]
  int v55; // [sp+28h] [bp-40h] BYREF
  int v56; // [sp+2Ch] [bp-3Ch] BYREF
  int v57; // [sp+30h] [bp-38h]
  int v58; // [sp+34h] [bp-34h]
  int v59; // [sp+38h] [bp-30h]
  _DWORD v60[10]; // [sp+40h] [bp-28h] BYREF

  v48 = 0;
  v49 = 0;
  if ( (a5 & 1) != 0 )
    return sub_54D9C8();
  v11 = a8;
  v12 = RaspCreateSegmentList(a1, a2, *(unsigned __int16 *)(a1 + 24), &v48, &v47, a8);
  v13 = v47;
  v14 = (int)v48;
  if ( v12 >= 0 )
  {
    v15 = BgpFmRoundUp(*(_DWORD *)(a1 + 14));
    v50 = v15;
    v16 = BgpFmRoundUp(*(_DWORD *)(a1 + 6));
    v18 = v15 - v16 + 1;
    if ( v15 == v16 )
    {
      v18 = BgpFmRoundDefault(*(_DWORD *)(17 * v17 + a2 + 21));
      v15 = v18;
      v50 = v18;
    }
    v19 = *(_DWORD *)(17 * v17 + a2);
    v20 = (_DWORD *)(17 * v17 + a2);
    v21 = v20[2];
    v22 = 4 * BgpFmRoundDefault(*(_DWORD *)((char *)v20 + 25) - v19 - v21 + *(_DWORD *)((char *)v20 + 17));
    v23 = 4 * v18;
    v60[0] = v22;
    v60[1] = v23;
    v60[2] = v22;
    v59 = v23;
    v57 = v19 + v21;
    v24 = RaspRectangleCreate(v60, 1, &v49, a8);
    v25 = v49;
    v12 = v24;
    if ( v24 >= 0 )
    {
      memset(*(_BYTE **)(v49 + 20), 0, *(_DWORD *)(v49 + 12));
      if ( !v14 )
      {
        result = 0;
        *a6 = v25;
        *a7 = v15;
        return result;
      }
      v26 = (int *)RaspAllocateMemory(4 * v22);
      v51 = v26;
      if ( v26 )
      {
        v27 = 0;
        v28 = 0;
        v53 = 0;
        v54 = 0;
        if ( v23 <= 0 )
          goto LABEL_23;
        while ( 1 )
        {
          memset(v26, 0, 4 * v22);
          v29 = 4 * (v50 - ((unsigned int)v28 >> 2)) - (v28 & 3);
          v58 = v29;
          if ( !v47 )
            goto LABEL_15;
          v30 = v47;
          v31 = v48;
          v52 = v47;
          do
          {
            RaspTestIntersection(v31, 16 * v29, &v55, &v56);
            v32 = v55;
            if ( v55 == 0x7FFFFFFF )
              goto LABEL_13;
            v38 = v31[2];
            v39 = *(_DWORD *)(v38 + 12);
            v40 = *(_DWORD *)(v38 + 4);
            v41 = v40 - *(_DWORD *)(*v31 + 12) - *(_DWORD *)(*v31 + 4) + v39;
            if ( !v41 )
            {
              if ( *((_BYTE *)v31 + 12) == 1 )
              {
LABEL_50:
                v42 = 0;
                goto LABEL_33;
              }
              v41 = v40 - *(_DWORD *)(v31[1] + 12) - *(_DWORD *)(v31[1] + 4) + v39;
            }
            if ( v41 <= 0 )
            {
              if ( v41 >= 0 )
                goto LABEL_50;
              v42 = -1;
            }
            else
            {
              v42 = 1;
            }
LABEL_33:
            v43 = 0;
            if ( v22 <= 0 )
              goto LABEL_13;
            v44 = v26;
            v45 = v56;
            do
            {
              v46 = v57 + 16 * (v43 % 4 + 4 * (v43 / 4));
              if ( *((_BYTE *)v31 + 12) == 1 )
              {
                if ( v46 > v32 )
                  goto LABEL_38;
LABEL_37:
                *v44 += v42;
                goto LABEL_38;
              }
              if ( v45 == 0x7FFFFFFF )
              {
                if ( v46 <= v32 )
                  goto LABEL_37;
              }
              else if ( v46 >= v32 && v46 <= v45 )
              {
                goto LABEL_37;
              }
LABEL_38:
              ++v43;
              ++v44;
            }
            while ( (int)v43 < v22 );
            v26 = v51;
            v30 = v52;
LABEL_13:
            v31 = (_DWORD *)((char *)v31 + 13);
            --v30;
            v29 = v58;
            v52 = v30;
          }
          while ( v30 );
          v27 = v53;
          v28 = v54;
          v23 = v59;
LABEL_15:
          v33 = (_BYTE *)(*(_DWORD *)(v49 + 20) + (v27 >> 3));
          v34 = 128 >> (v27 & 7);
          if ( v22 > 0 )
          {
            v35 = v26;
            v36 = v22;
            do
            {
              if ( *v35++ )
                *v33 |= v34;
              v34 >>= 1;
              if ( !v34 )
              {
                v34 = 128;
                ++v33;
              }
              --v36;
            }
            while ( v36 );
          }
          v27 += v22;
          ++v28;
          v53 = v27;
          v54 = v28;
          if ( v28 >= v23 )
          {
LABEL_23:
            v12 = 0;
            *a6 = v49;
            *a7 = v50;
            v11 = a8;
            if ( v26 != &dword_996130 )
              RaspFreeMemory(v26, a8);
            v14 = (int)v48;
            goto LABEL_26;
          }
        }
      }
      v12 = -1073741670;
    }
    v11 = a8;
    if ( v25 )
      RaspFreeMemory(v25, a8);
LABEL_26:
    v13 = v47;
  }
  if ( v14 )
    RaspDestroySegmentList(v14, v13, v11);
  return v12;
}
