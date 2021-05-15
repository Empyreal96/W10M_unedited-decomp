// MiCreatePagingFileMap 
 
int __fastcall MiCreatePagingFileMap(unsigned int *a1, unsigned __int64 *a2, int a3, int a4, int a5)
{
  unsigned __int64 v5; // r4
  int v6; // r7
  unsigned int *v8; // r10
  unsigned int *v9; // r8
  unsigned int v10; // r7
  _BYTE *v11; // r0
  int v12; // r0
  unsigned int v13; // r6
  int v14; // r3
  __int16 v15; // r3
  __int16 v16; // r2
  __int16 v17; // r3
  unsigned int v18; // r0
  int v19; // lr
  int v20; // r0
  int v21; // r1
  int v22; // r0
  unsigned int v23; // r0
  int v24; // r4
  unsigned int v26; // r5
  unsigned int v27; // r7
  __int64 v28; // r2
  int v29; // r9
  _DWORD *v30; // r4
  int v31; // r3
  int v32; // r3
  int v33; // r9
  int v34; // r8
  unsigned int j; // r9
  unsigned int v36; // r0
  int v37; // [sp+8h] [bp-58h]
  __int64 v38; // [sp+Ch] [bp-54h]
  unsigned int v39; // [sp+14h] [bp-4Ch]
  unsigned int v40; // [sp+18h] [bp-48h]
  int v41; // [sp+1Ch] [bp-44h]
  unsigned int i; // [sp+20h] [bp-40h]
  unsigned int v43; // [sp+20h] [bp-40h]
  int v45; // [sp+24h] [bp-3Ch]
  int v46; // [sp+28h] [bp-38h]
  _BYTE *v47; // [sp+2Ch] [bp-34h]
  unsigned int *v48; // [sp+30h] [bp-30h]
  int v49; // [sp+34h] [bp-2Ch]
  unsigned int *v50; // [sp+34h] [bp-2Ch]
  int v51; // [sp+38h] [bp-28h]

  v5 = *a2;
  v6 = a3;
  *a1 = 0;
  if ( v5 )
  {
    if ( v5 > 0x3FFFFFFF000i64 )
      return -1073741760;
    v8 = 0;
    v37 = a4 & 0x8000000;
    v48 = 0;
    HIDWORD(v5) = (__int64)(v5 + 4095) >> 12;
    if ( (a4 & 0x8000000) == 0 )
      goto LABEL_6;
    if ( !MiChargeCommit((int)MiSystemPartition, HIDWORD(v5), 0) )
      return -1073741523;
    if ( a4 >= 0 )
    {
LABEL_6:
      v9 = 0;
      if ( (a4 & 0x8000000) != 0 )
      {
        v39 = HIDWORD(v5);
        v10 = 1;
      }
      else
      {
        v39 = 2048;
        v10 = HIDWORD(v5) >> 11;
        if ( (v5 & 0x7FF00000000i64) != 0 )
          ++v10;
      }
      v11 = (_BYTE *)ExAllocatePoolWithTag(512, 56 * v10 + 80, 1631808845);
      LODWORD(v5) = v11;
      v47 = v11;
      if ( v11 )
      {
        memset(v11, 0, 56 * v10 + 80);
        v12 = ExAllocatePoolWithTag(1, 52, 1734693709);
        v13 = v12;
        v51 = v12;
        if ( v12 )
        {
          *(_DWORD *)(v12 + 48) = 0;
          *(_DWORD *)(v5 + 56) = v10;
          *(_DWORD *)v5 = v12;
          *(_DWORD *)(v5 + 4) = v5 + 4;
          *(_DWORD *)(v5 + 8) = v5 + 4;
          *(_DWORD *)(v5 + 64) = 1;
          *(_DWORD *)(v5 + 68) = 0;
          *(_DWORD *)(v5 + 12) = 1;
          *(_DWORD *)(v5 + 24) = 1;
          if ( (a4 & 0x200000) != 0 )
            *(_DWORD *)(v5 + 28) |= 0x40u;
          if ( (a4 & 0x4000000) != 0 )
            *(_DWORD *)(v5 + 28) |= 0x1000u;
          if ( v37 )
            *(_DWORD *)(v5 + 28) |= 0x2000u;
          v14 = *(_DWORD *)(v5 + 28);
          *(_DWORD *)(v5 + 72) = 0;
          *(_DWORD *)(v5 + 28) ^= (v14 ^ (a5 << 20)) & 0x3F00000;
          memset((_BYTE *)v12, 0, 48);
          *(_DWORD *)(v13 + 28) = 0;
          *(_DWORD *)(v13 + 16) = HIDWORD(v5) << 12;
          *(_DWORD *)(v13 + 20) = HIDWORD(v5) >> 20;
          *(_QWORD *)v13 = v5;
          if ( (a4 & 0x10000000) != 0 )
          {
            v15 = *(_WORD *)(v13 + 8) | 0x8000;
          }
          else
          {
            if ( (a4 & 0x40000000) == 0 )
              goto LABEL_54;
            v15 = *(_WORD *)(v13 + 8) | 0x4000;
          }
          *(_WORD *)(v13 + 8) = v15;
LABEL_54:
          v22 = a3 & 0x1F;
          v46 = v22;
          *(_BYTE *)(v13 + 10) = *(_BYTE *)(v13 + 10) & 0xC1 | (2 * v22);
          v21 = v5 + 80;
          v40 = HIDWORD(v5);
          v41 = v5 + 80;
          *(_DWORD *)(v13 + 32) = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
          v38 = 0i64;
          v19 = 0;
          for ( i = 0; i < v10; *(_DWORD *)(v19 + 8) = v21 )
          {
            v16 = *(_WORD *)(v21 + 16);
            *(_DWORD *)v21 = v5;
            v17 = v16 & 0xFFC1 | (2 * v22);
            v18 = v39;
            *(_DWORD *)(v21 + 20) = v38;
            *(_WORD *)(v21 + 16) = v17;
            *(_WORD *)(v21 + 16) = v17 & 0x3F | (WORD2(v38) << 6);
            if ( v40 <= v39 )
              v18 = v40;
            LODWORD(v5) = v47;
            v19 = v21;
            v49 = v21;
            *(_DWORD *)(v21 + 28) = v18;
            v40 -= v18;
            if ( v37 )
            {
              v20 = ExAllocatePoolWithTag(-2147483647, 4 * v18, 1951624525);
              v9 = (unsigned int *)v20;
              if ( !v20 )
                goto LABEL_75;
              v21 = v41;
              v19 = v49;
              *(_DWORD *)(v41 + 4) = v20;
            }
            v38 += *(unsigned int *)(v21 + 28);
            v21 += 56;
            v41 = v21;
            ++i;
            LOWORD(v22) = v46;
          }
          *(_DWORD *)(v19 + 8) = 0;
          *(_DWORD *)(v13 + 40) = v9;
          if ( v37 )
          {
            *(_DWORD *)(v13 + 12) = HIDWORD(v5);
            do
              v23 = __ldrex((unsigned int *)&dword_634DAC);
            while ( __strex(v23 + HIDWORD(v5), (unsigned int *)&dword_634DAC) );
            if ( a4 < 0 )
            {
              *(_WORD *)(v13 + 8) |= 0x1000u;
              v26 = MmProtectToPteMask[a3] | MiDetermineUserGlobalPteMask(0) | 0xFFFFF012;
              if ( (a3 & 4) != 0 )
                LOWORD(v26) = v26 & 0xFDFF;
              while ( 1 )
              {
                v27 = *v8;
                v43 = *v8;
                if ( (unsigned int *)*v8 == v8 )
                  break;
                v28 = *(_QWORD *)v27;
                if ( *(unsigned int **)(v27 + 4) != v8 || *(_DWORD *)(v28 + 4) != v27 )
                  __fastfail(3u);
                *v8 = v28;
                *(_DWORD *)(v28 + 4) = v8;
                v29 = *(_DWORD *)(v27 + 8);
                v30 = (_DWORD *)(MmPfnDatabase + 24 * v29);
                v31 = *(_DWORD *)(v27 + 12);
                v50 = &v9[v31];
                RtlFillMemoryUlong(v9, 4 * v31, 0);
                do
                {
                  v26 = v26 & 0xFFF | (v29 << 12);
                  v32 = 0x3FFFFF;
                  v45 = ++v29;
                  if ( (unsigned int)(v9 + 0x10000000) > 0x3FFFFF )
                  {
                    *v9 = v26;
                  }
                  else
                  {
                    v32 = *v9;
                    v33 = 0;
                    __dmb(0xBu);
                    *v9 = v26;
                    if ( (v32 & 2) == 0 && (v26 & 2) != 0 )
                      v33 = 1;
                    if ( (unsigned int)(v9 + 267649024) <= 0xFFF )
                      MiArmWriteHardwarePde(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74), v26, (__int16)v9);
                    if ( v33 == 1 )
                    {
                      __dsb(0xFu);
                      __isb(0xFu);
                    }
                    v29 = v45;
                  }
                  MiUpdateLargePageSectionPfn(v30, (int)v9++, 32 * v46, v32);
                  v30 += 6;
                }
                while ( v9 < v50 );
                ExFreePoolWithTag(v43);
                LODWORD(v5) = v47;
                v8 = v48;
                v13 = v51;
              }
            }
            else
            {
              MiInitializePrototypePtes(*(_DWORD *)(v5 + 84), HIDWORD(v5), v5 + 80);
            }
            MiUpdatePageFileSectionList(v5 + 80, 1);
          }
          v24 = 0;
          *a1 = v13;
          return v24;
        }
LABEL_75:
        v34 = v5 + 80;
        for ( j = 0; j < v10; v34 += 56 )
        {
          v36 = *(_DWORD *)(v34 + 4);
          if ( !v36 )
            break;
          ExFreePoolWithTag(v36);
          ++j;
        }
        ExFreePoolWithTag(v5);
        if ( v13 )
          ExFreePoolWithTag(v13);
      }
      if ( v37 )
      {
        if ( v8 )
        {
          HIDWORD(v5) = MiReturnLargePages(v8);
          ExFreePoolWithTag((unsigned int)v8);
        }
        MiReturnCommit((int)MiSystemPartition, SHIDWORD(v5));
      }
      return -1073741670;
    }
    if ( (v5 & 0x3FF00000000i64) != 0 )
    {
      v24 = -1073741582;
    }
    else
    {
      v8 = (unsigned int *)MiAllocateLargeZeroPages(MiSystemPartition, HIDWORD(v5), a5, v6);
      v48 = v8;
      if ( v8 )
        goto LABEL_6;
      v24 = -1073741670;
    }
    MiReturnCommit((int)MiSystemPartition, SHIDWORD(v5));
    return v24;
  }
  return sub_7BF968();
}
