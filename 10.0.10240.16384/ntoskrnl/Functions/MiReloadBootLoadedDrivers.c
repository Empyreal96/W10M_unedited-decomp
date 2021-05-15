// MiReloadBootLoadedDrivers 
 
int __fastcall MiReloadBootLoadedDrivers(__int64 a1)
{
  int v1; // r5
  unsigned int v2; // r9
  int v3; // r6
  int v4; // r2
  unsigned int v6; // r8
  unsigned int v7; // r7
  int v8; // r10
  unsigned int v9; // r4
  unsigned int v10; // r6
  int v11; // r2
  unsigned int v12; // r4
  int v13; // r6
  int v14; // r0
  int v15; // r10
  int v16; // r8
  int v17; // r6
  int v18; // r6
  int v19; // r6
  int v20; // r2
  int v21; // r6
  int v22; // r4
  int v23; // r2
  unsigned int *v24; // r2
  unsigned int v25; // r0
  int v26; // r1
  int v27; // r2
  unsigned int *v28; // r2
  unsigned int v29; // r0
  unsigned __int8 *v30; // r3
  unsigned int v31; // r1
  unsigned __int8 *v32; // r1
  int v33; // r3
  unsigned int v34; // r2
  unsigned __int8 *v35; // r3
  unsigned int v36; // r1
  unsigned __int8 *v37; // r0
  int v38; // r3
  unsigned int v39; // r2
  int v40; // r3
  int v41; // r8
  int v42; // r0
  int v43; // r3
  int v44; // r8
  int v45; // r0
  int v46; // r0
  unsigned int v47; // r0
  int v48; // [sp+Ch] [bp-FCh]
  int v49; // [sp+18h] [bp-F0h]
  unsigned int v50; // [sp+1Ch] [bp-ECh]
  int v51; // [sp+20h] [bp-E8h]
  int v52; // [sp+24h] [bp-E4h]
  unsigned int v53; // [sp+28h] [bp-E0h]
  int v54; // [sp+30h] [bp-D8h]
  unsigned int v55; // [sp+34h] [bp-D4h]
  int v56; // [sp+38h] [bp-D0h]
  unsigned int v57; // [sp+3Ch] [bp-CCh]
  int v58; // [sp+40h] [bp-C8h]
  int v59; // [sp+44h] [bp-C4h]
  int v60; // [sp+48h] [bp-C0h]
  int v61; // [sp+4Ch] [bp-BCh]
  int v62; // [sp+50h] [bp-B8h] BYREF
  char v63; // [sp+54h] [bp-B4h]
  char v64; // [sp+55h] [bp-B3h]
  int v65; // [sp+58h] [bp-B0h]
  int v66; // [sp+5Ch] [bp-ACh]
  int v67; // [sp+60h] [bp-A8h]
  int v68; // [sp+64h] [bp-A4h]

  v66 = 0;
  v67 = 0;
  v62 = 0;
  v63 = 0;
  v64 = 0;
  v58 = a1;
  v1 = *(_DWORD *)(a1 + 16);
  v65 = 33;
  v68 = 0;
  v2 = 0;
  v49 = v1;
  v60 = a1 + 16;
  if ( v1 != (_DWORD)a1 + 16 )
  {
    while ( 1 )
    {
      LODWORD(a1) = RtlImageNtHeader(*(_DWORD *)(v1 + 24));
      HIDWORD(a1) = PsNtosImageBase;
      v3 = a1;
      v56 = a1;
      if ( PsNtosImageBase != *(_DWORD *)(v1 + 24) )
      {
        LODWORD(a1) = MiProcessLoadConfigForDriver(v1);
        HIDWORD(a1) = PsNtosImageBase;
      }
      if ( (*(_WORD *)(v3 + 22) & 1) != 0 || *(_DWORD *)(v3 + 116) <= 5u )
        goto LABEL_38;
      v4 = *(_DWORD *)(v3 + 160);
      if ( !v4 )
        return sub_9699AC(a1, HIDWORD(a1));
      if ( (unsigned int)(v4 + *(_DWORD *)(v3 + 164)) > *(_DWORD *)(v1 + 32) )
        goto LABEL_38;
      v2 |= 2u;
      v6 = *(_DWORD *)(v1 + 24);
      v7 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
      v55 = v6;
      v8 = (unsigned int)(*(_DWORD *)(v1 + 32) + 4095) >> 12;
      v52 = v8;
      v53 = v7 + 4 * v8;
      if ( v6 == HIDWORD(a1) || v6 == PsHalImageBase )
        goto LABEL_38;
      *(_DWORD *)(v3 + 52) = v6;
      v9 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
      if ( (*(_DWORD *)(v1 + 52) & 0x800000) != 0 )
        break;
      v10 = v2 | 4;
      DbgUnLoadImageSymbolsUnicode((unsigned __int16 *)(v1 + 44), v6, -1);
      v11 = MiUseLargeDriverPage();
      v48 = v11;
      if ( !v11 )
        goto LABEL_13;
      v2 |= 5u;
      v50 = v10 | 1;
LABEL_23:
      if ( (v2 & 4) == 0 )
        goto LABEL_37;
      v19 = v11 - v6 + v56;
      if ( (v2 & 2) == 0 || (v2 & 1) != 0 )
        goto LABEL_28;
      if ( LdrRelocateImage(v11) >= 0 )
      {
        v11 = v48;
LABEL_28:
        *(_DWORD *)(v1 + 24) = v11;
        MiUpdateThunks(v58, v6);
        *(_DWORD *)(v1 + 52) |= 0x1000000u;
        *(_DWORD *)(v1 + 28) = *(_DWORD *)(v19 + 40) + v48;
        *(_DWORD *)(v1 + 32) = v8 << 12;
        if ( DbgLoadImageSymbolsUnicode(v1 + 44, v48, v20, v8 << 12) == 1 )
          *(_DWORD *)(v1 + 52) |= 0x100000u;
        if ( v7 < v53 )
        {
          do
          {
            MiInsertTbFlushEntry((int)&v62, v7 << 10, 1, 0);
            v21 = MmPfnDatabase + 24 * (*(_DWORD *)v7 >> 12);
            v22 = MmPfnDatabase + 24 * (*(_DWORD *)(v21 + 20) & 0xFFFFF);
            if ( v7 < 0xC0000000 || v7 > 0xC03FFFFF )
            {
              *(_DWORD *)v7 = 0;
            }
            else
            {
              __dmb(0xBu);
              *(_DWORD *)v7 = 0;
              if ( v7 + 1070596096 <= 0xFFF )
              {
                v46 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
                MiArmWriteConvertedHardwarePde(v46, (_DWORD *)(v46 + 4 * (v7 & 0xFFF)), 0);
              }
            }
            MiLockAndDecrementShareCount(v21, 1);
            MiLockAndDecrementShareCount(v22, 0);
            if ( (*(_DWORD *)(v22 + 12) & 0x3FFFFFFF) == 1 )
              MiReturnSystemVa(
                *(_DWORD *)(v22 + 4) << 20,
                (*(_DWORD *)(v22 + 4) << 20) + 0x400000,
                3,
                (unsigned int)&v62);
            v7 += 4;
          }
          while ( v7 < v53 );
          v1 = v49;
          v2 = v50;
          v8 = v52;
        }
LABEL_37:
        if ( (v2 & 1) != 0 )
        {
          MiReturnResidentAvailable(v8);
          do
            v47 = __ldrex(&dword_634A2C[54]);
          while ( __strex(v47 + v8, &dword_634A2C[54]) );
          MiReturnCommit((int)MiSystemPartition, v8);
        }
        goto LABEL_38;
      }
      MiReturnDriverLoadPages(v9, v9 + 4 * v8 - 4);
      MiReleaseDriverPtes(0, v9, v8);
LABEL_38:
      v1 = *(_DWORD *)v1;
      v49 = v1;
      if ( v1 == v60 )
        return MiFlushTbList((unsigned int)&v62, SHIDWORD(a1));
    }
    v10 = v2 & 0xFFFFFFFB;
LABEL_13:
    v2 = v10 & 0xFFFFFFFE;
    v50 = v10 & 0xFFFFFFFE;
    if ( (((v10 & 0xFFFFFFFE) >> 2) & 1) != 0 )
    {
      LODWORD(a1) = MiReserveDriverPtes(0, v8);
      v12 = a1;
      if ( !(_DWORD)a1 )
        goto LABEL_38;
      HIDWORD(a1) = (_DWORD)a1 << 10;
      v48 = (_DWORD)a1 << 10;
    }
    else
    {
      v12 = ((v6 >> 10) & 0x3FFFFC) - 0x40000000;
      v48 = v6;
    }
    v57 = v12 + 4 * v8;
    if ( v12 < v57 )
    {
      v13 = ((v6 >> 10) & 0x3FFFFC) - v12 - 0x40000000;
      v61 = v13;
      do
      {
        v14 = MiAllocateDriverPage();
        v15 = v14;
        v16 = *(_DWORD *)(v13 + v12) >> 12;
        v59 = *(_DWORD *)(v13 + v12);
        v17 = MmPfnDatabase + 24 * v16;
        if ( ((v2 >> 2) & 1) != 0 )
        {
          v18 = MiInitializeSystemImagePage(v14, v12, (*(_DWORD *)(v17 + 8) >> 5) & 0x1F);
          MiCopyPage(v15, v16, 0, 1);
          if ( v12 < 0xC0000000 || v12 > 0xC03FFFFF )
          {
            *(_DWORD *)v12 = v18;
          }
          else
          {
            v43 = *(_DWORD *)v12;
            v44 = 0;
            __dmb(0xBu);
            *(_DWORD *)v12 = v18;
            if ( (v43 & 2) == 0 && (v18 & 2) != 0 )
              v44 = 1;
            if ( v12 + 1070596096 <= 0xFFF )
            {
              v45 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v45, (_DWORD *)(v45 + 4 * (v12 & 0xFFF)), v18);
            }
            if ( v44 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
        }
        else
        {
          v51 = MmPfnDatabase + 24 * v14;
          v54 = KfRaiseIrql(2);
          v30 = (unsigned __int8 *)(v17 + 15);
          do
            v31 = __ldrex(v30);
          while ( __strex(v31 | 0x80, v30) );
          __dmb(0xBu);
          if ( v31 >> 7 )
          {
            v32 = (unsigned __int8 *)(v17 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v33 = *(_DWORD *)(v17 + 12);
                __dmb(0xBu);
              }
              while ( (v33 & 0x80000000) != 0 );
              do
                v34 = __ldrex(v32);
              while ( __strex(v34 | 0x80, v32) );
              __dmb(0xBu);
            }
            while ( v34 >> 7 );
          }
          v35 = (unsigned __int8 *)(v51 + 15);
          do
            v36 = __ldrex(v35);
          while ( __strex(v36 | 0x80, v35) );
          __dmb(0xBu);
          if ( v36 >> 7 )
          {
            v37 = (unsigned __int8 *)(v51 + 15);
            do
            {
              do
              {
                __dmb(0xAu);
                __yield();
                v38 = *(_DWORD *)(v51 + 12);
                __dmb(0xBu);
              }
              while ( (v38 & 0x80000000) != 0 );
              do
                v39 = __ldrex(v37);
              while ( __strex(v39 | 0x80, v37) );
              __dmb(0xBu);
            }
            while ( v39 >> 7 );
          }
          MiCopyPfnEntry(v51, (int *)v17);
          MiCopyPage(v15, v16, 0, 6);
          v23 = v59 & 0xFFF | (v15 << 12);
          if ( v12 < 0xC0000000 || v12 > 0xC03FFFFF )
          {
            *(_DWORD *)v12 = v23;
          }
          else
          {
            v40 = *(_DWORD *)v12;
            v41 = 0;
            __dmb(0xBu);
            *(_DWORD *)v12 = v23;
            if ( (v40 & 2) == 0 && (v59 & 2) != 0 )
              v41 = 1;
            if ( v12 + 1070596096 <= 0xFFF )
            {
              v42 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
              MiArmWriteConvertedHardwarePde(v42, (_DWORD *)(v42 + 4 * (v12 & 0xFFF)), v23);
            }
            if ( v41 == 1 )
            {
              __dsb(0xFu);
              __isb(0xFu);
            }
          }
          __dmb(0xBu);
          v24 = (unsigned int *)(v51 + 12);
          do
            v25 = __ldrex(v24);
          while ( __strex(v25 & 0x7FFFFFFF, v24) );
          *(_DWORD *)(v17 + 12) |= 0x40000000u;
          MiInsertTbFlushEntry((int)&v62, v12 << 10, 1, 0);
          MiFlushTbList((unsigned int)&v62, v26);
          if ( (*(_BYTE *)(v17 + 18) & 7) != 6 )
            KeBugCheckEx(
              78,
              153,
              (v17 - MmPfnDatabase) / 24,
              *(_BYTE *)(v17 + 18) & 7,
              *(_DWORD *)(v17 + 12) & 0x3FFFFFFF);
          v27 = *(_DWORD *)(v17 + 12);
          *(_DWORD *)(v17 + 12) = v27 & 0xC0000000 | ((v27 & 0x3FFFFFFF) - 1) & 0x3FFFFFFF;
          if ( (v27 & 0x3FFFFFFF) == 1 )
            MiPfnShareCountIsZero(v17, 0);
          __dmb(0xBu);
          v28 = (unsigned int *)(v17 + 12);
          do
            v29 = __ldrex(v28);
          while ( __strex(v29 & 0x7FFFFFFF, v28) );
          a1 = KfLowerIrql(v54);
        }
        v12 += 4;
        v13 = v61;
      }
      while ( v12 < v57 );
      v6 = v55;
      v8 = v52;
    }
    v11 = v48;
    v9 = v12 - 4 * v8;
    goto LABEL_23;
  }
  return MiFlushTbList((unsigned int)&v62, SHIDWORD(a1));
}
