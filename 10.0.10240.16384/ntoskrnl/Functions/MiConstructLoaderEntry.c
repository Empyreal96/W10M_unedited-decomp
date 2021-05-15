// MiConstructLoaderEntry 
 
int __fastcall MiConstructLoaderEntry(int a1, unsigned __int16 *a2, unsigned __int16 *a3, char a4, int a5, int *a6)
{
  int v7; // r4
  char v8; // r9
  int v9; // r8
  int v10; // r7
  int v11; // r5
  int v12; // r0
  int v13; // r4
  int v15; // r4
  int v16; // r0
  int v17; // r6
  int v18; // r8
  unsigned int v19; // r9
  BOOL v20; // r3
  unsigned int v21; // r7
  unsigned int v22; // r2
  unsigned int v23; // r3
  unsigned int v24; // r6
  int v25; // r10
  unsigned int v26; // r2
  unsigned int v27; // r4
  _DWORD *v28; // r4
  unsigned int v29; // r6
  unsigned int v30; // r7
  int v31; // r2
  int v32; // r7
  int v33; // r2
  int v34; // r6
  int v35; // r3
  unsigned int v36; // r3
  int v37; // r2
  int v38; // r3
  int v39; // r4
  unsigned int v40; // r2
  unsigned int v41; // r1
  unsigned int v42; // r0
  unsigned int v43; // r6
  unsigned int v44; // r4
  unsigned int v45; // r3
  unsigned int v46; // r2
  int v47; // r1
  int v48; // r3
  int v49; // r3
  unsigned int v50; // r9
  unsigned int v51; // r10
  int v52; // r5
  __int64 v53; // kr00_8
  unsigned int v54; // r1
  unsigned int v55; // r10
  unsigned int v56; // r0
  unsigned int v57; // [sp+0h] [bp-A0h]
  int v58; // [sp+4h] [bp-9Ch]
  int v60; // [sp+Ch] [bp-94h]
  int v61; // [sp+10h] [bp-90h]
  unsigned int v62; // [sp+14h] [bp-8Ch]
  unsigned int v63; // [sp+14h] [bp-8Ch]
  int v64; // [sp+18h] [bp-88h]
  unsigned int v66; // [sp+20h] [bp-80h]
  int v67; // [sp+24h] [bp-7Ch]
  unsigned int v68; // [sp+28h] [bp-78h]
  int v69; // [sp+2Ch] [bp-74h]
  int v71; // [sp+38h] [bp-68h]
  int v72[24]; // [sp+40h] [bp-60h] BYREF

  v7 = *a3;
  v8 = a4;
  v9 = a1;
  v10 = 0;
  *a6 = 0;
  v11 = 0;
  v57 = 0;
  v12 = ExAllocatePoolWithTag(257, v7 + 2, 1413770573);
  v13 = v12;
  v66 = v12;
  if ( !v12 )
    return sub_7CDC4C();
  LOWORD(v71) = *a3;
  HIWORD(v71) = *a3;
  memmove(v12, *((_DWORD *)a3 + 1), *a3);
  *(_WORD *)(v13 + 2 * (*a3 >> 1)) = 0;
  v15 = *(_DWORD *)(v9 + 24);
  v58 = v15;
  v16 = RtlImageNtHeader(v15);
  v17 = v8 & 1;
  v67 = v17;
  v18 = v16;
  if ( (v8 & 1) != 0 )
  {
    v55 = 0;
    v68 = 0;
    goto LABEL_8;
  }
  v55 = *(unsigned __int16 *)(v16 + 6);
  v68 = v55;
  if ( !*(_WORD *)(v16 + 6) )
    __brkdiv0();
  if ( 0xFFFFFFFF / v55 >= 4 )
  {
LABEL_8:
    v60 = 0;
    v61 = 0;
    v19 = 0;
    if ( v17 )
    {
      v19 = 32;
      if ( *(_DWORD *)(v16 + 116) > 6u )
      {
        v40 = *(_DWORD *)(v16 + 168);
        v60 = v16 + 168;
        if ( v40 )
        {
          v41 = *(_DWORD *)(v16 + 172);
          if ( v41 )
          {
            if ( v41 + v40 > v40 && v41 + v40 < *(_DWORD *)(v16 + 80) )
            {
              v42 = v40 + v15;
              v43 = 0;
              v19 = v41 + 32;
              v44 = v41 / 0x1C;
              if ( v41 / 0x1C )
              {
                v43 = v41 / 0x1C;
                do
                {
                  v45 = *(_DWORD *)(v42 + 20);
                  if ( v45 )
                  {
                    v46 = *(_DWORD *)(v18 + 80);
                    if ( v45 < v46 )
                    {
                      v47 = *(_DWORD *)(v42 + 16);
                      if ( v45 + v47 < v46 )
                        v19 += v47;
                    }
                  }
                  v42 += 28;
                  --v44;
                }
                while ( v44 );
              }
              v61 = v42 - 28 * v43;
            }
          }
        }
        v19 = (v19 + 3) & 0xFFFFFFFC;
      }
    }
    v20 = (*(_DWORD *)(v18 + 80) & 0xFFF) != 0;
    v21 = 4
        * ((((v20 + (*(_DWORD *)(v18 + 80) >> 12)) & 0x1F) != 0)
         + ((unsigned int)(v20 + (*(_DWORD *)(v18 + 80) >> 12)) >> 5)
         + 2);
    v22 = v21 + 142;
    if ( v21 == 0 || v21 >= 0xFFFFFF72 )
      goto LABEL_73;
    if ( v19 )
    {
      if ( v22 + v19 <= v22 )
        goto LABEL_73;
      v22 += v19;
    }
    v23 = (*a2 + 3) & 0xFFFFFFFC;
    v24 = v23 + v22;
    v62 = v23;
    if ( v23 + v22 > v22 )
    {
      if ( !v55 )
        goto LABEL_16;
      if ( v24 + 4 * v55 > v24 )
      {
        v24 += 4 * v55;
LABEL_16:
        v11 = ExAllocatePoolWithTag(512, v24, 1682730317);
        v69 = v11;
        if ( v11 )
        {
          v25 = *(_DWORD *)(a1 + 60);
          v64 = v25;
          if ( !v25 )
          {
LABEL_20:
            memset((_BYTE *)v11, 0, v24);
            v28 = (_DWORD *)(v11 + 92);
            *(_DWORD *)(v11 + 136) = v11 + 140;
            v29 = v11 + 140 + v21;
            *(_DWORD *)(v11 + 132) = v29;
            v30 = v29 + v19;
            *(_DWORD *)(v11 + 124) = v57;
            if ( v68 )
              *(_DWORD *)(v11 + 128) = v62 + v30;
            memmove(v11, a1, 0x5Cu);
            v31 = *(_DWORD *)(v11 + 52) | 0x8000000;
            *(_DWORD *)(v11 + 52) = v31;
            if ( (*(_WORD *)(v18 + 94) & 0x80) != 0 )
              *(_DWORD *)(v11 + 52) = v31 | 0x20;
            *(_DWORD *)(v11 + 48) = v30;
            *(_WORD *)(v11 + 44) = *a2;
            *(_WORD *)(v11 + 46) = *a2;
            memmove(v29 + v19, *((_DWORD *)a2 + 1), *a2);
            *(_WORD *)(*(_DWORD *)(v11 + 48) + 2 * (*a2 >> 1)) = 0;
            *(_DWORD *)(v11 + 20) = 0;
            *(_DWORD *)(v11 + 36) = v71;
            *(_DWORD *)(v11 + 40) = v66;
            if ( v67 )
            {
              v48 = *(_DWORD *)(v11 + 52);
              *(_DWORD *)(v11 + 20) = v29;
              *(_DWORD *)(v11 + 52) = v48 | 0x20000000;
              *(_WORD *)v29 = 18766;
              *(_WORD *)(v29 + 2) = 1;
              *(_DWORD *)(v29 + 4) = v19;
              *(_WORD *)(v29 + 8) = *(_WORD *)(v18 + 4);
              *(_WORD *)(v29 + 10) = *(_WORD *)(v18 + 22);
              *(_DWORD *)(v29 + 12) = *(_DWORD *)(v18 + 8);
              *(_DWORD *)(v29 + 16) = *(_DWORD *)(v18 + 88);
              v49 = *(_DWORD *)(v18 + 80);
              *(_DWORD *)(v29 + 28) = 0;
              *(_DWORD *)(v29 + 20) = v49;
              *(_DWORD *)(v29 + 24) = v58;
              if ( v61 )
              {
                v63 = v29 + 32;
                memmove(v29 + 32, v61, *(_DWORD *)(v60 + 4));
                v50 = *(_DWORD *)(v60 + 4);
                v51 = 0;
                if ( v50 / 0x1C )
                {
                  v52 = v61;
                  do
                  {
                    v53 = *(_QWORD *)(v52 + 16);
                    if ( HIDWORD(v53)
                      && (v54 = *(_DWORD *)(v18 + 80), HIDWORD(v53) < v54)
                      && (unsigned int)(v53 + HIDWORD(v53)) > HIDWORD(v53)
                      && (int)v53 + HIDWORD(v53) < v54 )
                    {
                      memmove(v63 + v50, HIDWORD(v53) + v58, v53);
                      *(_DWORD *)(v29 + 52) = v50;
                      v50 += v53;
                    }
                    else
                    {
                      *(_DWORD *)(v29 + 52) = 0;
                    }
                    v52 += 28;
                    ++v51;
                    v29 += 28;
                  }
                  while ( v51 < *(_DWORD *)(v60 + 4) / 0x1Cu );
                  v11 = v69;
                  v28 = (_DWORD *)(v69 + 92);
                }
                v25 = v64;
              }
            }
            *(_DWORD *)(v11 + 28) = *(_DWORD *)(v18 + 40) + v58;
            *(_DWORD *)(v11 + 64) = *(_DWORD *)(v18 + 88);
            if ( v25 )
            {
              v32 = MiSectionControlArea(v25);
              v33 = *(_WORD *)(v11 + 58) & 0xFFF0 | (*(unsigned __int8 *)(*(_DWORD *)v32 + 11) >> 4);
              *(_WORD *)(v11 + 58) = v33;
              *(_WORD *)(v11 + 58) = ((unsigned __int8)v33 ^ (unsigned __int8)(8 * *(_BYTE *)(*(_DWORD *)v32 + 11))) & 0x70 ^ v33;
            }
            else
            {
              v32 = 0;
            }
            *(_DWORD *)(v11 + 84) = *(_DWORD *)(v18 + 80);
            *(_DWORD *)(v11 + 88) = *(_DWORD *)(v18 + 8);
            MiCaptureImageExceptionValues(v11);
            MiLockdownSections(v11);
            if ( v25 )
              v34 = *(_DWORD *)(*(_DWORD *)v32 + 4);
            else
              v34 = *(_DWORD *)(v11 + 32) >> 12;
            if ( v67 )
              goto LABEL_32;
            if ( MiChargeWsles((int)dword_634F00, v34, 0) )
            {
              v28[6] = v34;
              v28[7] = v34;
LABEL_32:
              v35 = v28[5];
              if ( a5 == 1 )
                v36 = v35 & 0xFFFFFFFC;
              else
                v36 = v35 & 0xFFFFFFFC | 1;
              v28[5] = v36;
              if ( (dword_681250 & 1) != 0 || (a4 & 2) != 0 )
                v28[5] |= 4u;
              ExCovAddInfoToLoaderEntry(v11);
              MiProcessLoaderEntry((int *)v11, 1, v37, v38);
              if ( v25 && !v67 )
              {
                v28[4] = -2;
                v28[2] = v58 | 3;
                v28[3] = v58 + (v34 << 12) - 1;
                v72[0] = v32;
                MiManageSubsectionView(v72, (int)v28, 3);
              }
              v39 = 0;
              *a6 = v11;
              return v39;
            }
            v10 = v57;
LABEL_76:
            v39 = -1073741670;
            goto LABEL_77;
          }
          v26 = *(_DWORD *)(*(_DWORD *)MiSectionControlArea(v25) + 4);
          v57 = ((v26 & 0xFFF) != 0) + (v26 >> 12);
          if ( MiChargeResident(MiSystemPartition, v57, 0) )
          {
            do
              v27 = __ldrex(&dword_634A2C[120]);
            while ( __strex(v27 + v57, &dword_634A2C[120]) );
            goto LABEL_20;
          }
        }
        v10 = 0;
        goto LABEL_76;
      }
    }
LABEL_73:
    v39 = -1073741701;
    v10 = 0;
    goto LABEL_77;
  }
  v39 = -1073741520;
LABEL_77:
  ExFreePoolWithTag(v66);
  if ( v11 )
    ExFreePoolWithTag(v11);
  if ( v10 )
  {
    MiReturnResidentAvailable(v10);
    do
      v56 = __ldrex(&dword_634A2C[121]);
    while ( __strex(v56 + v10, &dword_634A2C[121]) );
  }
  return v39;
}
