// MiBuildMdlForMappedFileFault 
 
int __fastcall MiBuildMdlForMappedFileFault(_DWORD *a1, int *a2, unsigned int a3, int a4, int a5, int a6, unsigned int a7, _DWORD *a8, int a9)
{
  unsigned int v10; // r8
  int *v12; // r9
  unsigned int v13; // r0
  int v14; // r2
  int *v15; // r5
  char *v16; // lr
  int v17; // r1
  int *v18; // r6
  int *v19; // r4
  __int16 v22; // r0
  int v23; // r0
  int v24; // r4
  int v25; // r10
  unsigned int v26; // r1
  int v27; // r6
  _DWORD *v28; // lr
  int *v29; // r0
  int v30; // r7
  int v31; // r2
  int v32; // r4
  int v33; // r3
  unsigned __int8 *v34; // r3
  unsigned int v35; // r1
  char v36; // r2
  int v37; // r3
  unsigned int v38; // r3
  unsigned int *v39; // r1
  unsigned int v40; // r2
  int v41; // r2
  unsigned __int8 *v42; // r1
  int v43; // r3
  unsigned int v44; // r2
  int v45; // r0
  unsigned int v46; // [sp+0h] [bp-40h]
  int v47; // [sp+4h] [bp-3Ch]
  char *v48; // [sp+8h] [bp-38h]
  int v49; // [sp+8h] [bp-38h]
  _DWORD *v50; // [sp+Ch] [bp-34h]
  int v51; // [sp+10h] [bp-30h]
  int v52; // [sp+14h] [bp-2Ch]
  int v54; // [sp+18h] [bp-28h]

  v10 = a3;
  v12 = (int *)a1[33];
  v13 = a1[24];
  v52 = ((int)(a3 - (_DWORD)a2) >> 2) + 1;
  v14 = a1[23];
  v15 = a2;
  v16 = (char *)(a1 + 45);
  v17 = 0;
  v50 = a1;
  v51 = v14;
  v46 = v13;
  v47 = 0;
  v48 = (char *)(a1 + 45);
  v18 = a1 + 45;
  v19 = v15;
  if ( (unsigned int)v15 <= v10 )
  {
    do
    {
      if ( *v19 == v13 )
      {
        if ( a6 == -1 )
        {
          if ( v17 == a5 )
            JUMPOUT(0x544ECA);
          if ( a8 )
            return sub_544EA4();
          v22 = **(_WORD **)a9 + 1;
          **(_WORD **)a9 = v22;
          v23 = MiGetPage(a4, (unsigned __int16)(v22 & *(_WORD *)(a9 + 4)) | *(unsigned __int16 *)(a9 + 6), 0);
          v17 = v47;
          *v18 = v23;
          v13 = v46;
        }
        else
        {
          *v18 = a6;
          a6 = -1;
        }
        if ( *v18 == -1 )
          JUMPOUT(0x544ECC);
        v47 = ++v17;
      }
      else
      {
        *v18 = dword_6348FC;
      }
      ++v19;
      ++v18;
    }
    while ( (unsigned int)v19 <= a3 );
    v10 = a3;
    v16 = v48;
    v14 = v51;
  }
  v24 = 0;
  v49 = 0;
  v25 = 1;
  if ( a7 >> 3 == 3 && (a7 & 7) != 0 )
  {
    v25 = 2;
  }
  else if ( a7 >> 3 == 1 )
  {
    v25 = 0;
  }
  v54 = (v14 - MmPfnDatabase) / 24;
  if ( (unsigned int)v15 <= v10 )
  {
    v26 = v46;
    v27 = v16 - (char *)v15;
    v28 = v50;
    v29 = MiState;
    v30 = (v46 >> 10) & 1;
    do
    {
      v31 = *(int *)((char *)v15 + v27);
      if ( v31 == v29[1951] )
      {
        v24 = 1;
        v49 = 1;
      }
      else
      {
        v32 = MmPfnDatabase + 24 * v31;
        v33 = *v15;
        *(_DWORD *)v32 = v50 + 4;
        if ( !v30 )
          v33 = *(_DWORD *)(MmPfnDatabase + 24 * (v26 >> 12) + 8);
        *(_DWORD *)(v32 + 8) = v33;
        *(_DWORD *)(v32 + 20) |= 0x8000000u;
        *(_WORD *)(v32 + 16) = 1;
        *(_BYTE *)(v32 + 18) |= 0x20u;
        if ( a8 )
        {
          MiAdvanceFaultList(a8);
          v28 = v50;
        }
        v34 = (unsigned __int8 *)(v32 + 15);
        do
          v35 = __ldrex(v34);
        while ( __strex(v35 | 0x80, v34) );
        __dmb(0xBu);
        if ( v35 >> 7 )
        {
          v42 = (unsigned __int8 *)(v32 + 15);
          do
          {
            do
            {
              __dmb(0xAu);
              __yield();
              v43 = *(_DWORD *)(v32 + 12);
              __dmb(0xBu);
            }
            while ( v43 < 0 );
            do
              v44 = __ldrex(v42);
            while ( __strex(v44 | 0x80, v42) );
            __dmb(0xBu);
          }
          while ( v44 >> 7 );
        }
        v36 = *(_BYTE *)(v32 + 19);
        if ( v15 == v12 )
          *(_BYTE *)(v32 + 19) ^= (*((_BYTE *)v28 + 114) ^ v36) & 7;
        else
          *(_BYTE *)(v32 + 19) = v36 & 0xF8 | (*((_BYTE *)v28 + 114) >> 4) & 7;
        v37 = *(_DWORD *)(v32 + 20);
        *(_DWORD *)(v32 + 4) = v15;
        *(_DWORD *)(v32 + 20) = v37 & 0xFFF00000 | v54 & 0xFFFFF;
        v38 = *(_BYTE *)(v32 + 18) & 0xF8 | 2;
        *(_BYTE *)(v32 + 18) = v38;
        if ( v38 >> 6 != v25 )
        {
          MiChangePageAttribute(v32, v25, 1);
          v28 = v50;
        }
        *(_DWORD *)(v32 + 12) &= 0xC0000000;
        __dmb(0xBu);
        v39 = (unsigned int *)(v32 + 12);
        do
          v40 = __ldrex(v39);
        while ( __strex(v40 & 0x7FFFFFFF, v39) );
        if ( v30 )
        {
          v41 = 32 * (a7 & 0x1F | (*(int *)((char *)v15 + v27) << 7) | 0x40);
          if ( (unsigned int)(v15 + 0x10000000) <= 0x3FFFFF )
          {
            __dmb(0xBu);
            *v15 = v41;
            if ( (unsigned int)(v15 + 267649024) <= 0xFFF )
            {
              v45 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v45, (_DWORD *)(v45 + 4 * ((unsigned __int16)v15 & 0xFFF)), v41);
              v28 = v50;
            }
          }
          else
          {
            *v15 = v41;
          }
        }
        v29 = MiState;
        v26 = v46;
        v24 = v49;
      }
      ++v15;
    }
    while ( (unsigned int)v15 <= v10 );
  }
  v50[26] = v52 << 12;
  if ( v24 == 1 )
    *((_BYTE *)v50 + 115) |= 1u;
  return v47;
}
