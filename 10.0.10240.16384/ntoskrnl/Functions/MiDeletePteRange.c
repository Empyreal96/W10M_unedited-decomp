// MiDeletePteRange 
 
int __fastcall MiDeletePteRange(int a1, unsigned int a2, int a3, int a4)
{
  char v4; // r9
  int v6; // r7
  int v8; // r0
  int v9; // r2
  int v10; // r4
  unsigned int v11; // r8
  int v12; // r10
  int v13; // r0
  int v14; // r3
  unsigned int v15; // r6
  unsigned int v16; // r4
  int result; // r0
  unsigned int v18; // r1
  int v19; // r7
  int v20; // r8
  int v21; // r9
  unsigned int v22; // r4
  unsigned int i; // r6
  int v24; // r2
  int v25; // r5
  unsigned int v26; // r4
  int v27; // r4
  int v28; // r3
  unsigned int v29; // r2
  __int64 v30; // kr00_8
  unsigned int v31; // r0
  int v32; // r0
  int v33; // [sp+8h] [bp-E8h] BYREF
  int v34; // [sp+Ch] [bp-E4h] BYREF
  int v35; // [sp+10h] [bp-E0h]
  int v36; // [sp+14h] [bp-DCh]
  unsigned int v37; // [sp+18h] [bp-D8h]
  int v38; // [sp+1Ch] [bp-D4h]
  int v39; // [sp+20h] [bp-D0h]
  unsigned int v40; // [sp+24h] [bp-CCh]
  int v41; // [sp+28h] [bp-C8h] BYREF
  int v42; // [sp+2Ch] [bp-C4h]
  int v43; // [sp+30h] [bp-C0h]
  int v44; // [sp+34h] [bp-BCh]
  int v45; // [sp+38h] [bp-B8h] BYREF
  char v46; // [sp+3Ch] [bp-B4h]
  char v47; // [sp+3Dh] [bp-B3h]
  int v48; // [sp+40h] [bp-B0h]
  int v49; // [sp+44h] [bp-ACh]
  int v50; // [sp+48h] [bp-A8h]
  int v51; // [sp+4Ch] [bp-A4h]

  v4 = a4;
  v38 = a4;
  v6 = a1;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v36 = a1;
  v8 = MiTbFlushType(a1);
  v46 = 0;
  v48 = 33;
  v49 = v9;
  v33 = 0;
  v47 = v9;
  v50 = 0;
  v51 = v9;
  v10 = 0;
  v11 = a3 - 4;
  v45 = v8;
  v12 = 0;
  v34 = 0;
  v35 = 0;
  v40 = v11;
  if ( a2 <= v11 )
  {
    v37 = 0x3FFFFF;
    v39 = 4194300;
    do
    {
      v13 = MiGetNextPageTable(a2, v11, 1, 17, 1, &v34);
      a2 = v13;
      if ( !v13 )
        break;
      v15 = v13 + 1070596096;
      do
      {
        v16 = *(_DWORD *)a2;
        if ( (*(_DWORD *)a2 & 2) != 0 )
        {
          if ( (v4 & 0x20) != 0 )
            *(_DWORD *)(MmPfnDatabase + 24 * (v16 >> 12) + 8) &= 0x1FFFu;
          MiDeleteValidSystemPte(a2, a2 << 10, v36, &v45, &v33);
          ++v12;
        }
        else if ( (v16 & 0x400) == 0 )
        {
          if ( (v16 & 0x800) != 0 )
            return sub_53D2DC();
          if ( (v16 & 0x400) == 0 )
          {
            if ( (v16 & 0x10) != 0 )
              v18 = *(_DWORD *)a2;
            else
              v18 = (v16 & 8) != 0 ? *(_DWORD *)a2 : 0;
            if ( v18 )
              MiReleasePageFileInfo((int)MiSystemPartition, v18, 0, v14);
          }
          if ( v16 )
          {
            ++v12;
            if ( v15 + 3145728 > v37 )
            {
              *(_DWORD *)a2 = 0;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)a2 = 0;
              if ( v15 <= 0xFFF )
              {
                v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v32, (_DWORD *)(v32 + 4 * (a2 & 0xFFF)), 0);
              }
            }
          }
        }
        a2 += 4;
        v15 += 4;
        if ( a2 > v11 )
          break;
        v14 = a2 & 0xFFF;
      }
      while ( (a2 & 0xFFF) != 0 );
      v34 = v12;
      MiFlushTbList(&v45);
      MiFreeUnmappedPageTables(v33, &v41);
      v19 = v39;
      v33 = 0;
      v21 = v35;
      v20 = v36;
      v22 = (v39 & ((a2 - 4) >> 10)) - 0x40000000;
      for ( i = 1; i < 2; ++i )
      {
        v24 = MmPfnDatabase + 24 * (*(_DWORD *)v22 >> 12);
        if ( (*(_DWORD *)(v24 + 12) & 0x3FFFFFFF) != 1 )
          break;
        v28 = *(unsigned __int16 *)(v24 + 16);
        if ( v28 != 1 && (v28 != 2 || (*(_BYTE *)(v24 + 18) & 8) == 0) )
          break;
        MiDeleteValidSystemPte(v22, v22 << 10, v20, &v45, &v33);
        if ( i == 1 && *(_DWORD *)(v20 + 92) != -1069539328 )
          MiReplicatePteChange(a2 - 4, a2 - 4);
        MiFlushTbList(&v45);
        MiFreeUnmappedPageTables(v33, &v41);
        v33 = 0;
        v22 = (v19 & (v22 >> 10)) - 0x40000000;
        ++v21;
      }
      v11 = v40;
      v12 = v34;
      v35 = v21;
      v4 = v38;
    }
    while ( a2 <= v40 );
    v10 = v35;
    v6 = v36;
  }
  v25 = v10 + v12;
  if ( (v4 & 0x10) != 0 )
  {
    v29 = *(_BYTE *)(v6 + 112) & 7;
    if ( v29 != 1 )
    {
      v30 = *(_QWORD *)(v6 + 72);
      *(_DWORD *)(v6 + 76) = HIDWORD(v30) - v25;
      if ( (_DWORD)v30 )
      {
        if ( v29 >= 2 || HIDWORD(v30) <= (unsigned int)v30 )
        {
          v25 = 0;
        }
        else if ( HIDWORD(v30) - v25 < (unsigned int)v30 )
        {
          v25 = HIDWORD(v30) - v30;
        }
      }
    }
  }
  else if ( (v4 & 0x20) != 0 )
  {
    if ( !v25 )
      return 0;
    *(_DWORD *)(v6 + 80) -= v25;
    if ( (*(_BYTE *)(v6 + 112) & 7) != 1 )
    {
      do
        v31 = __ldrex(&dword_634DA0);
      while ( __strex(v31 - v25, &dword_634DA0) );
    }
  }
  result = v25;
  if ( v25 )
  {
    MiReturnResidentAvailable(v25);
    do
      v26 = __ldrex(&dword_634A2C[6]);
    while ( __strex(v26 + v25, &dword_634A2C[6]) );
    v27 = v42;
    MiReturnCommit(MiSystemPartition, v25 - v42);
    result = v25 - v27;
  }
  return result;
}
