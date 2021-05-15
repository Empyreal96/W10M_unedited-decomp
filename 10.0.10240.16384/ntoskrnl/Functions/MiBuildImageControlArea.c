// MiBuildImageControlArea 
 
int __fastcall MiBuildImageControlArea(int a1, int a2, int a3, int *a4, _WORD *a5, char a6, unsigned int *a7, unsigned int *a8)
{
  unsigned int v8; // r5
  unsigned int v10; // r8
  int v11; // r2
  int v12; // r4
  int v13; // r1
  _BYTE *v14; // r0
  unsigned int v15; // r6
  unsigned int v16; // r5
  unsigned int *v17; // r4
  int v18; // r2
  unsigned int v19; // r0
  unsigned int v20; // r3
  unsigned int v21; // r1
  __int16 v22; // r2
  unsigned int v23; // r10
  unsigned int v24; // r0
  int v25; // r3
  unsigned int v26; // r8
  unsigned int v27; // r1
  unsigned int v28; // r7
  int v29; // r4
  int v30; // r3
  unsigned int v31; // r2
  __int64 v32; // r8
  int v33; // r2
  bool v34; // r3
  _BYTE *v35; // r0
  int v36; // r3
  int *v37; // lr
  int v38; // r3
  unsigned int v39; // r2
  unsigned int v40; // r8
  unsigned int v41; // r3
  int v42; // r2
  unsigned int v44; // [sp+Ch] [bp-44h]
  unsigned int v45; // [sp+Ch] [bp-44h]
  _BYTE *v46; // [sp+10h] [bp-40h]
  unsigned int v47; // [sp+10h] [bp-40h]
  unsigned int v48; // [sp+10h] [bp-40h]
  int v49; // [sp+14h] [bp-3Ch]
  unsigned int v50; // [sp+14h] [bp-3Ch]
  unsigned int v51; // [sp+14h] [bp-3Ch]
  _BYTE *v52; // [sp+18h] [bp-38h]
  _BYTE *v53; // [sp+1Ch] [bp-34h]
  int v55; // [sp+24h] [bp-2Ch]
  unsigned int v56; // [sp+24h] [bp-2Ch]
  int v57; // [sp+28h] [bp-28h]
  int varg_r1; // [sp+5Ch] [bp+Ch]
  int varg_r2; // [sp+60h] [bp+10h]
  int *varg_r3; // [sp+64h] [bp+14h]

  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v8 = a4[3];
  v57 = (unsigned __int16)a5[1];
  if ( (v8 & 0xFFF) != 0 )
    return sub_7D46D4();
  v10 = v8 >> 12;
  v44 = v8 >> 12;
  if ( !(v8 >> 12) )
    return -1073741701;
  v11 = 1766026573;
  v12 = (unsigned __int16)a5[1] + 1;
  if ( (a1 & 8) != 0 )
  {
    v11 = 1631808845;
    v12 = 1;
  }
  if ( (MiFlags & 0x8000) != 0 )
    v13 = 12;
  else
    v13 = 8;
  v49 = v13;
  v14 = (_BYTE *)ExAllocatePoolWithTag(512, v13 + 40 * (v12 + 2), v11);
  v15 = (unsigned int)v14;
  v52 = v14;
  if ( !v14 )
  {
    dword_632EE4 = 12;
    return -1073741670;
  }
  memset(v14, 0, 120);
  v16 = v15 + 80;
  v46 = (_BYTE *)(v15 + 80 + 40 * v12);
  v17 = (unsigned int *)ExAllocatePoolWithTag(-2147483647, 4 * v10, 1951624525);
  if ( !v17 )
  {
    dword_632EE4 = 13;
    ExFreePoolWithTag(v15);
    return -1073741670;
  }
  v35 = (_BYTE *)ExAllocatePoolWithTag(1, 104, 1734693709);
  v28 = (unsigned int)v35;
  v53 = v35;
  if ( !v35 )
  {
    dword_632EE4 = 13;
    ExFreePoolWithTag((unsigned int)v17);
    v29 = -1073741670;
LABEL_71:
    ExFreePoolWithTag(v15);
    return v29;
  }
  memset(v35, 0, 104);
  v30 = v10 << 12;
  *(_DWORD *)v28 = v15;
  *(_DWORD *)(v28 + 4) = v10;
  HIDWORD(v32) = a4[3];
  v31 = v10 >> 20;
  LODWORD(v32) = a4[5];
  *(_DWORD *)(v28 + 16) = v30;
  *(_DWORD *)(v28 + 20) = v31;
  *(_DWORD *)(v28 + 28) = 0;
  *(_DWORD *)(v28 + 36) = v28 + 48;
  *(_DWORD *)(v28 + 40) = v17;
  *(_QWORD *)(v28 + 96) = v32;
  v33 = a4[6];
  *(_DWORD *)(v28 + 88) = *a7;
  v55 = *a4;
  *(_DWORD *)(v28 + 48) = *a4 + v33;
  *(_DWORD *)(v28 + 56) = a4[7];
  *(_DWORD *)(v28 + 60) = a4[8];
  *(_DWORD *)(v28 + 64) = *((unsigned __int16 *)a4 + 19);
  *(_WORD *)(v28 + 70) = *((_WORD *)a4 + 20);
  *(_WORD *)(v28 + 68) = *((_WORD *)a4 + 21);
  *(_WORD *)(v28 + 72) = *((_WORD *)a4 + 22);
  *(_WORD *)(v28 + 74) = *((_WORD *)a4 + 23);
  *(_WORD *)(v28 + 78) = *((_WORD *)a4 + 24);
  *(_DWORD *)(v28 + 92) = a4[13];
  v34 = a4[14] || v33;
  *(_BYTE *)(v28 + 82) = v34;
  *(_WORD *)(v28 + 76) = a5[9];
  *(_WORD *)(v28 + 80) = *a5;
  *(_DWORD *)(v28 + 84) = a4[4];
  *(_DWORD *)v15 = v28;
  *(_DWORD *)(v15 + 4) = v15 + 4;
  *(_DWORD *)(v15 + 8) = v15 + 4;
  *(_DWORD *)(v15 + 64) = 1;
  *(_DWORD *)(v15 + 68) = 0;
  *(_DWORD *)(v15 + 12) = 1;
  if ( (a6 & 1) == 0 )
    *(_DWORD *)(v15 + 24) = 1;
  *(_DWORD *)(v15 + 48) = -1;
  v36 = *(_DWORD *)(v15 + 28);
  *(_DWORD *)(v15 + 72) = 0;
  *(_DWORD *)(v15 + 28) = *(_DWORD *)(v15 + 28) ^ (v36 ^ (a2 << 20)) & 0x3F00000 | 0xA2;
  memset(v46, 0, v49);
  v37 = a4;
  *(_DWORD *)(v15 + 56) = v46;
  *(_BYTE *)(v28 + 10) = *(_BYTE *)(v28 + 10) & 0x7F | (*((_BYTE *)a4 + 92) << 7);
  *(_DWORD *)v16 = v15;
  *(_DWORD *)(v28 + 24) = v55;
  v50 = 0;
  *(_DWORD *)(v15 + 84) = v17;
  if ( (a1 & 8) == 0 )
  {
    if ( (_DWORD)v32 )
    {
      v18 = a4[2];
      v19 = v32 + v18 - 1;
      if ( v19 <= (unsigned int)v32 )
      {
        v42 = 50;
      }
      else
      {
        v20 = ((v19 >> 12) & ((unsigned int)~(v18 - 1) >> 12))
            + ((((unsigned __int16)~(v18 - 1) & (unsigned __int16)v19 & 0xFFFu) + 4095) >> 12);
        *(_DWORD *)(v15 + 108) = v20;
        if ( v20 <= v44 )
        {
          v21 = v44 - v20;
          *(_DWORD *)(v15 + 104) = (unsigned int)v32 >> 9;
          v22 = *(_WORD *)(v15 + 96);
          *(_WORD *)(v15 + 98) = *(_WORD *)(v15 + 98) & 0xF | (16 * (v32 & 0x1FF));
          *(_WORD *)(v15 + 96) = v22 & 0xFFC1 | 2;
          v23 = v16 & 0xFFFFFC00 | ((v16 & 0x7F8 | 0x800) >> 1);
          v24 = 0;
          *(_BYTE *)(v28 + 10) = *(_BYTE *)(v28 + 10) & 0xC1 | 2;
          v25 = *(_DWORD *)(v15 + 108);
          v45 = v21;
          v47 = 0;
          *(_DWORD *)(v15 + 116) = 0;
          if ( v25 )
          {
            v26 = (unsigned int)(v17 + 267649024);
            v27 = 0;
            do
            {
              if ( v27 >= v37[5] )
              {
                if ( (unsigned int)v17 < 0xC0000000 || (unsigned int)v17 > 0xC03FFFFF )
                {
                  *v17 = 0;
                }
                else
                {
                  __dmb(0xBu);
                  *v17 = 0;
                  if ( v26 <= 0xFFF )
                  {
                    MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 0, (__int16)v17);
                    v37 = a4;
                    v24 = v47;
                    v27 = v50;
                  }
                }
                ++*(_DWORD *)(v15 + 116);
              }
              else if ( (unsigned int)v17 < 0xC0000000 || (unsigned int)v17 > 0xC03FFFFF )
              {
                *v17 = v23;
              }
              else
              {
                __dmb(0xBu);
                *v17 = v23;
                if ( v26 <= 0xFFF )
                {
                  MiArmWriteHardwarePde(
                    *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74),
                    v16 & 0xFC00 | ((v16 & 0x7F8 | 0x800) >> 1),
                    (__int16)v17);
                  v37 = a4;
                  v24 = v47;
                  v27 = v50;
                }
              }
              ++v24;
              v27 += 4096;
              ++v17;
              v47 = v24;
              v50 = v27;
              v26 += 4;
            }
            while ( v24 < *(_DWORD *)(v15 + 108) );
            v15 = (unsigned int)v52;
            v28 = (unsigned int)v53;
            v21 = v45;
          }
          goto LABEL_21;
        }
        v42 = 17;
      }
    }
    else
    {
      v42 = 49;
    }
    dword_632EE4 = v42;
    ExFreePoolWithTag(v28);
    v29 = -1073741701;
    goto LABEL_71;
  }
  v21 = v44;
  *(_DWORD *)(v15 + 108) = v44;
  if ( (unsigned __int64)HIDWORD(v32) >= *(_QWORD *)a7 )
  {
    *(_DWORD *)(v15 + 104) = *(__int64 *)a7 >> 9;
    v38 = *(_WORD *)(v15 + 98) & 0xF | (16 * (*a7 & 0x1FF));
  }
  else
  {
    *(_DWORD *)(v15 + 104) = HIDWORD(v32) >> 9;
    LOWORD(v38) = *(_WORD *)(v15 + 98) & 0xF | (16 * (WORD2(v32) & 0x1FF));
  }
  *(_WORD *)(v15 + 98) = v38;
  *(_BYTE *)(v28 + 83) |= 8u;
  *(_BYTE *)(v28 + 82) = 1;
  *(_WORD *)(v15 + 96) = *(_WORD *)(v15 + 96) & 0xFFC1 | 0xE;
  v56 = v16 & 0xFFFFFC00 | ((v16 & 0x7F8 | 0x800) >> 1);
  v39 = 0;
  v48 = 0;
  *(_BYTE *)(v28 + 10) = *(_BYTE *)(v28 + 10) & 0xC1 | 0xE;
  if ( v44 )
  {
    v40 = (unsigned int)(v17 + 267649024);
    v51 = v44;
    do
    {
      v41 = v40 + 3145728;
      if ( v39 >= *a7 )
      {
        if ( v41 > 0x3FFFFF )
        {
          *v17 = 224;
        }
        else
        {
          __dmb(0xBu);
          *v17 = 224;
          if ( v40 <= 0xFFF )
          {
            MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), 224, (__int16)v17);
            v39 = v48;
            v21 = v51;
          }
        }
      }
      else if ( v41 > 0x3FFFFF )
      {
        *v17 = v56;
      }
      else
      {
        __dmb(0xBu);
        *v17 = v56;
        if ( v40 <= 0xFFF )
        {
          MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v56, (__int16)v17);
          v39 = v48;
          v21 = v51;
        }
      }
      ++v17;
      --v21;
      v39 += 4096;
      v48 = v39;
      v51 = v21;
      v40 += 4;
    }
    while ( v21 );
    v15 = (unsigned int)v52;
    v28 = (unsigned int)v53;
    v37 = a4;
    v21 = v44;
    v16 = (unsigned int)(v52 + 80);
  }
  *(_DWORD *)(v28 + 32) = v21;
  *(_DWORD *)(v16 + 36) = 0;
LABEL_21:
  v29 = MiParseImageSectionHeaders(a1, v15, a3, v57, v37, v21);
  if ( v29 < 0 )
  {
    ExFreePoolWithTag(v28);
    goto LABEL_71;
  }
  v29 = 0;
  *a8 = v15;
  return v29;
}
