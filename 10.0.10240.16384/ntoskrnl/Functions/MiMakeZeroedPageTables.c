// MiMakeZeroedPageTables 
 
void __fastcall MiMakeZeroedPageTables(unsigned int a1, int a2, int a3)
{
  unsigned int v5; // r2
  __int64 v6; // r0
  unsigned int v7; // r6
  unsigned int i; // r4
  int v9; // r3
  int v10; // r5
  int v11; // r4
  unsigned int v12; // r0
  unsigned int v13; // r0
  int v14; // r4
  int v15; // r0
  int v16; // r1
  _WORD *v17; // r2
  int v18; // r3
  int v19; // r3
  int v20; // r0
  int *v21; // r2
  int *v22; // r4
  int v23; // r5
  __int64 v24; // r0
  unsigned int v25; // r0
  int v26; // r0
  int v27; // r6
  unsigned int v28; // r4
  unsigned int v29; // r5
  int v30; // [sp+8h] [bp-60h]
  int v31; // [sp+8h] [bp-60h]
  unsigned int v32; // [sp+Ch] [bp-5Ch]
  int v33; // [sp+14h] [bp-54h]
  int v34; // [sp+18h] [bp-50h]
  unsigned int v35; // [sp+1Ch] [bp-4Ch]
  _WORD *v37; // [sp+28h] [bp-40h] BYREF
  unsigned __int16 v38; // [sp+2Ch] [bp-3Ch]
  unsigned __int16 v39; // [sp+2Eh] [bp-3Ah]
  int v40; // [sp+38h] [bp-30h] BYREF
  int v41; // [sp+3Ch] [bp-2Ch]
  int v42; // [sp+40h] [bp-28h]
  int v43; // [sp+44h] [bp-24h]
  unsigned int v44; // [sp+48h] [bp-20h]

  v35 = a1;
  if ( (a3 & 4) != 0 )
  {
    sub_510558();
    return;
  }
  if ( (a3 & 2) != 0 )
    v5 = 2;
  else
    v5 = (a3 & 0x20) == 0;
  HIDWORD(v6) = a2 << 10;
  LODWORD(v6) = a1 << 10;
  v44 = v5;
  v7 = MiPageTablesNeeded(v6, v5);
  if ( v7 )
  {
    v33 = 0;
    for ( i = a1; i >= 0xC0000000; i <<= 10 )
    {
      if ( i > 0xC03FFFFF )
        break;
    }
    MiInitializeColorBase(i, (int)&v37);
    if ( i > MmHighestUserAddress && (i < 0xC0000000 || i > dword_633894) )
    {
      if ( i >= dword_63389C
        && ((v9 = *((unsigned __int8 *)&MiState[2423]
                  + ((int)(((i >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v9 == 11)
         || v9 == 1) )
      {
        v10 = 1;
      }
      else
      {
        v10 = 2;
      }
      v42 = v10;
      v11 = 0;
    }
    else
    {
      v10 = 0;
      v42 = 0;
      v11 = 128;
      __mrc(15, 0, 13, 0, 3);
    }
    if ( (a3 & 8) == 0 && dword_640714 )
    {
      if ( !MiChargeCommit((int)MiSystemPartition, v7, 1) )
        return;
      if ( !MiChargeResident(MiSystemPartition, v7, v11) )
      {
        MiReturnCommit((int)MiSystemPartition, v7);
        return;
      }
      v33 = 1;
      if ( v10 )
      {
        do
          v12 = __ldrex(&dword_634A2C[9]);
        while ( __strex(v12 + v7, &dword_634A2C[9]) );
        if ( (a3 & 0x40) == 0 && v10 == 2 )
        {
          do
            v13 = __ldrex(&dword_634D98);
          while ( __strex(v13 + v7, &dword_634D98) );
        }
      }
      else
      {
        do
          v25 = __ldrex(&dword_634A2C[7]);
        while ( __strex(v25 + v7, &dword_634A2C[7]) );
      }
    }
    v34 = 0;
    v41 = 0;
    v14 = 0xFFFFF;
    v40 = 0xFFFFF;
    v32 = 0;
    v43 = a3;
    v15 = v38;
    v16 = v39;
    v17 = v37;
    do
    {
      v18 = (unsigned __int16)(*v17 + 1);
      *v17 = v18;
      v19 = v18 & v15;
      v30 = v19;
      while ( 1 )
      {
        v20 = MiGetPage((int)MiSystemPartition, v16 | v19, 10);
        if ( v20 != -1 )
          break;
        if ( (a3 & 0x10) != 0 && (unsigned int)dword_640580 >= 0x60 )
        {
          v20 = MiGetPage((int)MiSystemPartition, v39 | v30, 14);
          if ( v20 != -1 )
            break;
        }
        if ( (a3 & 1) == 0 )
          goto LABEL_35;
        MiWaitForFreePage((int)MiSystemPartition);
        v19 = v30;
        v16 = v39;
      }
      v31 = MmPfnDatabase + 24 * v20;
      MiFinalizePageAttribute(v31, 1, 0);
      v21 = (int *)v31;
      if ( *(_DWORD *)(v31 + 8) )
      {
        MiZeroPfn(v31);
        v21 = (int *)v31;
        *(_DWORD *)(v31 + 8) = 0;
      }
      *v21 = v14;
      v16 = v39;
      v15 = v38;
      v14 = (int)v21;
      v40 = (int)v21;
      v17 = v37;
      ++v32;
    }
    while ( v32 < v7 );
    v22 = (int *)&v37;
    v23 = 2;
    LODWORD(v24) = v35 << 10;
    HIDWORD(v24) = a2 << 10;
    do
    {
      LODWORD(v24) = (((unsigned int)v24 >> 10) & 0x3FFFFC) - 0x40000000;
      HIDWORD(v24) = ((HIDWORD(v24) >> 10) & 0x3FFFFC) - 0x40000000;
      *(_QWORD *)v22 = v24;
      v22 += 2;
      --v23;
    }
    while ( v23 );
    MiMakeZeroedPageTableRange(v24, HIDWORD(v24), (int)&v37, 1u, (int)&v40);
    v10 = v42;
    v14 = v40;
    v34 = v41;
LABEL_35:
    while ( v14 != 0xFFFFF )
    {
      v26 = v14;
      v14 = *(_DWORD *)v14;
      MiReleaseFreshPage(v26);
    }
    if ( v33 == 1 && v34 != v7 )
    {
      v27 = v7 - v34;
      MiReturnCommit((int)MiSystemPartition, v27);
      MiReturnResidentAvailable(v27);
      do
        v28 = __ldrex(&dword_634A2C[10]);
      while ( __strex(v28 + v27, &dword_634A2C[10]) );
      if ( (a3 & 0x40) == 0 && v10 == 2 )
      {
        do
          v29 = __ldrex(&dword_634D98);
        while ( __strex(v29 - v27, &dword_634D98) );
      }
    }
  }
}
