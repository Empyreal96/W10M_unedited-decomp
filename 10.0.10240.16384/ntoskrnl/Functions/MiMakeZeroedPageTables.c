// MiMakeZeroedPageTables 
 
int __fastcall MiMakeZeroedPageTables(unsigned int a1, int a2, int a3)
{
  int v6; // r2
  unsigned int v7; // r6
  int v8; // r10
  unsigned int i; // r4
  int v10; // r3
  int v11; // r5
  int v12; // r4
  unsigned int v13; // r0
  unsigned int v14; // r0
  int v15; // r4
  int v16; // r0
  int v17; // r1
  _WORD *v18; // r2
  int v19; // r3
  int v20; // r3
  int v21; // r0
  int *v22; // r2
  int *v23; // r4
  int v24; // r5
  __int64 v25; // r0
  unsigned int v26; // r0
  int v27; // r0
  unsigned int v28; // r6
  unsigned int v29; // r4
  unsigned int v30; // r5
  int v31; // [sp+8h] [bp-60h]
  int v32; // [sp+8h] [bp-60h]
  unsigned int v33; // [sp+Ch] [bp-5Ch]
  int v34; // [sp+14h] [bp-54h]
  int v35; // [sp+18h] [bp-50h]
  unsigned int v36; // [sp+1Ch] [bp-4Ch]
  _WORD *v38; // [sp+28h] [bp-40h] BYREF
  unsigned __int16 v39; // [sp+2Ch] [bp-3Ch]
  unsigned __int16 v40; // [sp+2Eh] [bp-3Ah]
  int v41; // [sp+38h] [bp-30h]
  int v42; // [sp+3Ch] [bp-2Ch]
  int v43; // [sp+40h] [bp-28h]
  int v44; // [sp+44h] [bp-24h]
  int v45; // [sp+48h] [bp-20h]

  v36 = a1;
  if ( (a3 & 4) != 0 )
    return sub_510558();
  if ( (a3 & 2) != 0 )
    v6 = 2;
  else
    v6 = (a3 & 0x20) == 0;
  v45 = v6;
  v7 = MiPageTablesNeeded(a1 << 10, a2 << 10);
  if ( v7 )
  {
    v34 = 0;
    v8 = 0;
    for ( i = a1; i >= 0xC0000000; i <<= 10 )
    {
      if ( i > 0xC03FFFFF )
        break;
    }
    MiInitializeColorBase(i, &v38);
    if ( i > MmHighestUserAddress && (i < 0xC0000000 || i > dword_633894) )
    {
      if ( i >= dword_63389C
        && ((v10 = *((unsigned __int8 *)&MiState[2423]
                   + ((int)(((i >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)),
             v10 == 11)
         || v10 == 1) )
      {
        v11 = 1;
      }
      else
      {
        v11 = 2;
      }
      v43 = v11;
      v12 = 0;
    }
    else
    {
      v11 = 0;
      v43 = 0;
      v12 = 128;
      __mrc(15, 0, 13, 0, 3);
    }
    if ( (a3 & 8) == 0 && dword_640714 )
    {
      if ( MiChargeCommit(&MiSystemPartition, v7, 1) )
      {
        if ( MiChargeResident(&MiSystemPartition, v7, v12) )
        {
          v34 = 1;
          if ( v11 )
          {
            do
              v13 = __ldrex(&dword_634A2C[9]);
            while ( __strex(v13 + v7, &dword_634A2C[9]) );
            if ( (a3 & 0x40) == 0 && v11 == 2 )
            {
              do
                v14 = __ldrex(&dword_634D98);
              while ( __strex(v14 + v7, &dword_634D98) );
            }
          }
          else
          {
            do
              v26 = __ldrex(&dword_634A2C[7]);
            while ( __strex(v26 + v7, &dword_634A2C[7]) );
          }
          goto LABEL_27;
        }
        MiReturnCommit(&MiSystemPartition, v7);
      }
      return 0;
    }
LABEL_27:
    v35 = 0;
    v42 = 0;
    v15 = 0xFFFFF;
    v41 = 0xFFFFF;
    v33 = 0;
    v44 = a3;
    v16 = v39;
    v17 = v40;
    v18 = v38;
    do
    {
      v19 = (unsigned __int16)(*v18 + 1);
      *v18 = v19;
      v20 = v19 & v16;
      v31 = v20;
      while ( 1 )
      {
        v21 = MiGetPage(&MiSystemPartition, v17 | v20, 10);
        if ( v21 != -1 )
          break;
        if ( (a3 & 0x10) != 0 && (unsigned int)dword_640580 >= 0x60 )
        {
          v21 = MiGetPage(&MiSystemPartition, v40 | v31, 14);
          if ( v21 != -1 )
            break;
        }
        if ( (a3 & 1) == 0 )
          goto LABEL_36;
        MiWaitForFreePage(&MiSystemPartition);
        v20 = v31;
        v17 = v40;
      }
      v32 = MmPfnDatabase + 24 * v21;
      MiFinalizePageAttribute();
      v22 = (int *)v32;
      if ( *(_DWORD *)(v32 + 8) )
      {
        MiZeroPfn(v32);
        v22 = (int *)v32;
        *(_DWORD *)(v32 + 8) = 0;
      }
      *v22 = v15;
      v17 = v40;
      v16 = v39;
      v15 = (int)v22;
      v41 = (int)v22;
      v18 = v38;
      ++v33;
    }
    while ( v33 < v7 );
    v23 = (int *)&v38;
    v24 = 2;
    LODWORD(v25) = v36 << 10;
    HIDWORD(v25) = a2 << 10;
    do
    {
      LODWORD(v25) = (((unsigned int)v25 >> 10) & 0x3FFFFC) - 0x40000000;
      HIDWORD(v25) = ((HIDWORD(v25) >> 10) & 0x3FFFFC) - 0x40000000;
      *(_QWORD *)v23 = v25;
      v23 += 2;
      --v24;
    }
    while ( v24 );
    MiMakeZeroedPageTableRange(v25);
    v11 = v43;
    v15 = v41;
    v8 = 1;
    v35 = v42;
LABEL_36:
    while ( v15 != 0xFFFFF )
    {
      v27 = v15;
      v15 = *(_DWORD *)v15;
      MiReleaseFreshPage(v27);
    }
    if ( v34 == 1 && v35 != v7 )
    {
      v28 = v7 - v35;
      MiReturnCommit(&MiSystemPartition, v28);
      MiReturnResidentAvailable(v28);
      do
        v29 = __ldrex(&dword_634A2C[10]);
      while ( __strex(v29 + v28, &dword_634A2C[10]) );
      if ( (a3 & 0x40) == 0 && v11 == 2 )
      {
        do
          v30 = __ldrex(&dword_634D98);
        while ( __strex(v30 - v28, &dword_634D98) );
      }
    }
    return v8;
  }
  return 1;
}
