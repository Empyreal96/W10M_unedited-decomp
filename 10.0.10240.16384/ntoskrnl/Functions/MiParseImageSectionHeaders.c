// MiParseImageSectionHeaders 
 
int __fastcall MiParseImageSectionHeaders(unsigned int a1, _DWORD *a2, _DWORD *a3, int a4, _DWORD *a5, unsigned int a6)
{
  int v6; // r6
  _DWORD *v7; // lr
  int v8; // r2
  unsigned int v9; // r7
  _BYTE *v10; // r5
  int result; // r0
  _DWORD *v12; // r0
  int v13; // r9
  int v14; // r4
  unsigned int v15; // r1
  unsigned int i; // r6
  unsigned int v17; // r0
  int v18; // r3
  unsigned int v19; // r8
  unsigned int v20; // r1
  unsigned int v21; // r3
  int v22; // r6
  unsigned int v23; // r4
  unsigned int v24; // r0
  __int16 v25; // r2
  char v26; // r0
  int v27; // r1
  unsigned int v28; // lr
  unsigned int v29; // r2
  unsigned int v30; // r4
  unsigned int v31; // r2
  unsigned int v32; // r6
  char v33; // r3
  bool v34; // zf
  unsigned int v35; // r2
  unsigned int v36; // [sp+0h] [bp-50h]
  int v37; // [sp+4h] [bp-4Ch]
  unsigned int v38; // [sp+8h] [bp-48h]
  _DWORD *v39; // [sp+Ch] [bp-44h]
  _DWORD *v40; // [sp+10h] [bp-40h]
  unsigned int v42; // [sp+18h] [bp-38h]
  int v43; // [sp+1Ch] [bp-34h]
  int v44; // [sp+20h] [bp-30h]
  unsigned int v45; // [sp+24h] [bp-2Ch]
  int v46; // [sp+28h] [bp-28h]
  unsigned int v47; // [sp+2Ch] [bp-24h]
  int v48; // [sp+30h] [bp-20h]
  unsigned int varg_r0; // [sp+58h] [bp+8h]
  _DWORD *varg_r1; // [sp+5Ch] [bp+Ch]
  _DWORD *varg_r2; // [sp+60h] [bp+10h]
  int varg_r3; // [sp+64h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v44 = a4;
  v6 = a2[27];
  v7 = a3;
  v39 = a3;
  v40 = a2 + 20;
  v8 = *a2;
  v9 = a1;
  v10 = (_BYTE *)(a2[21] + 4 * v6);
  varg_r0 = a1;
  v37 = *a2;
  if ( (a1 & 8) != 0 )
    return sub_7D498C();
  v12 = a5;
  v13 = *(_DWORD *)(v8 + 24) + (v6 << 12);
  v14 = a5[2];
  v46 = *(_DWORD *)(v8 + 36);
  v48 = v14;
  v15 = *(_DWORD *)(v46 + 40) + 1;
  if ( a4 )
  {
    for ( i = a6; ; i = v45 )
    {
      v17 = v7[2];
      v42 = v17;
      if ( !v17 )
      {
        v17 = v7[4];
        v42 = v17;
      }
      v18 = v7[4];
      if ( !v18 )
        v7[5] = 0;
      if ( (unsigned int)(v18 + v7[5]) < v7[5] )
        break;
      v19 = (unsigned int)(v40 + 10);
      v40[2] = v40 + 10;
      v40 = (_DWORD *)v19;
      *(_DWORD *)(v19 + 8) = 0;
      *(_DWORD *)(v19 + 12) = 0;
      *(_DWORD *)v19 = a2;
      *(_DWORD *)(v19 + 36) = 0;
      if ( v13 != *a5 + v7[3] || !v17 )
      {
        result = -1073741701;
        dword_632EE4 = 26;
        return result;
      }
      v20 = v14 + v17 - 1;
      if ( v20 <= v17 )
      {
        result = -1073741701;
        dword_632EE4 = 43;
        return result;
      }
      v21 = (v20 >> 12) & ((unsigned int)~(v14 - 1) >> 12);
      *(_DWORD *)(v19 + 28) = v21;
      if ( v21 > i )
      {
        result = -1073741701;
        dword_632EE4 = 27;
        return result;
      }
      *(_DWORD *)(v19 + 16) = 0;
      v45 = i - v21;
      v22 = v7[5] >> 9;
      *(_DWORD *)(v19 + 20) = v22;
      v23 = v7[5];
      v24 = (a5[1] + v23 + v7[4] - 1) & ~(a5[1] - 1);
      if ( v24 < v23 )
      {
        result = -1073741701;
        dword_632EE4 = 54;
        return result;
      }
      v25 = *(_WORD *)(v19 + 18);
      *(_DWORD *)(v19 + 24) = (v24 >> 9) - v22;
      *(_WORD *)(v19 + 18) = v25 & 0xF | (16 * (v24 & 0x1FF));
      *(_DWORD *)(v19 + 4) = v10;
      v26 = MiGetImageProtection(v7[9]);
      if ( (v26 & 2) != 0 )
      {
        *(_BYTE *)(v46 + 34) = 1;
        v9 = varg_r0;
      }
      *(_WORD *)(v19 + 16) = *(_WORD *)(v19 + 16) & 0xFFC1 | (2 * (v26 & 0x1F));
      v27 = v39[5];
      v28 = v19 & 0xFFFFFC00 | ((v19 & 0x7F8 | 0x800) >> 1);
      v36 = v28;
      v43 = 32 * (v26 & 0x1F);
      if ( !v27 )
      {
        v28 = 32 * (v26 & 0x1F);
        v36 = v28;
      }
      v29 = v9 & 0xFFFFFFF9;
      v15 = v27 + v39[4];
      v47 = v15;
      varg_r0 = v9 & 0xFFFFFFF9;
      if ( (v26 & 4) != 0 )
      {
        if ( (v26 & 5) == 5 )
        {
          varg_r0 = v29 | 4;
        }
        else
        {
          varg_r0 = v29 | 2;
          *(_WORD *)(v19 + 18) |= 2u;
          a2[7] |= 0x20000u;
        }
      }
      v30 = 0;
      *(_BYTE *)(v37 + 10) = *(_BYTE *)(v37 + 10) & 0xC1 | (2 * (v26 & 0x1F));
      v31 = v39[4];
      v32 = 0;
      v38 = v31;
      if ( *(_DWORD *)(v19 + 28) )
      {
        do
        {
          if ( v30 >= v42 )
          {
            if ( (unsigned int)v10 < 0xC0000000 || (unsigned int)v10 > 0xC03FFFFF )
            {
              *(_DWORD *)v10 = 0;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v10 = 0;
              if ( (unsigned int)(v10 + 1070596096) <= 0xFFF )
              {
                MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v10);
                v28 = v36;
                v31 = v38;
              }
            }
            ++*(_DWORD *)(v19 + 36);
          }
          else
          {
            v33 = varg_r0;
            if ( (varg_r0 & 2) != 0 )
            {
              ++*(_DWORD *)(v37 + 12);
              v33 = varg_r0;
            }
            if ( (v33 & 4) != 0 )
              ++*(_DWORD *)(v37 + 32);
            if ( v30 >= v31 )
            {
              if ( (unsigned int)v10 < 0xC0000000 || (unsigned int)v10 > 0xC03FFFFF )
              {
                *(_DWORD *)v10 = v43;
              }
              else
              {
                __dmb(0xBu);
                *(_DWORD *)v10 = v43;
                if ( (unsigned int)(v10 + 1070596096) <= 0xFFF )
                {
                  MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v43, (__int16)v10);
                  v28 = v36;
                  v31 = v38;
                }
              }
            }
            else if ( (unsigned int)v10 < 0xC0000000 || (unsigned int)v10 > 0xC03FFFFF )
            {
              *(_DWORD *)v10 = v28;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v10 = v28;
              if ( (unsigned int)(v10 + 1070596096) <= 0xFFF )
              {
                MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v28, (__int16)v10);
                v28 = v36;
                v31 = v38;
              }
            }
          }
          ++v32;
          v10 += 4;
          v30 += 4096;
          v13 += 4096;
        }
        while ( v32 < *(_DWORD *)(v19 + 28) );
        v15 = v47;
      }
      v7 = v39 + 10;
      v34 = v44 == 1;
      v39 += 10;
      --v44;
      if ( v34 )
      {
        v35 = v45;
        v12 = a5;
        goto LABEL_36;
      }
      v9 = varg_r0;
      v14 = v48;
    }
    result = -1073741701;
    dword_632EE4 = 25;
  }
  else
  {
    v35 = a6;
LABEL_36:
    if ( v15 > *(_DWORD *)(v46 + 40) )
    {
      result = -1073741701;
      dword_632EE4 = 33;
    }
    else if ( v35 >= v12[2] >> 12 )
    {
      result = -1073741701;
      dword_632EE4 = 34;
    }
    else
    {
      if ( v35 )
        memset(v10, 0, 4 * v35);
      result = 0;
    }
  }
  return result;
}
