// MiAllocateContiguousMemory 
 
int __fastcall MiAllocateContiguousMemory(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4, unsigned int a5, int a6)
{
  unsigned int v7; // lr
  unsigned int v10; // r8
  unsigned int v11; // r4
  int v12; // r2
  int v13; // r1
  int v14; // r2
  int v15; // r0
  int v16; // r3
  int v17; // r0
  unsigned __int16 *v18; // r5
  unsigned int v19; // r6
  unsigned int v20; // r2
  unsigned __int16 *v21; // r5
  unsigned int i; // r3
  unsigned int v23; // r10
  unsigned int v24; // r6
  unsigned int v25; // r7
  int v26; // r9
  int *v27; // r4
  unsigned int v28; // r10
  int v29; // r0
  unsigned __int8 *v30; // r1
  unsigned int v31; // r2
  unsigned int v32; // r5
  int v33; // r6
  int v34; // r8
  int v35; // t1
  int v36; // r3
  int v37; // r3
  int v38; // r0
  int v39; // [sp+4h] [bp-54h]
  int v40; // [sp+8h] [bp-50h]
  int v41; // [sp+Ch] [bp-4Ch]
  int v42; // [sp+18h] [bp-40h]
  unsigned int *v45; // [sp+20h] [bp-38h]
  unsigned int v46; // [sp+24h] [bp-34h] BYREF
  int v47; // [sp+28h] [bp-30h]
  int v48; // [sp+2Ch] [bp-2Ch]
  int v49; // [sp+30h] [bp-28h]
  int v50; // [sp+34h] [bp-24h]

  v7 = a4;
  if ( MmProtectFreedNonPagedPool == 1 )
    return sub_512584();
  v10 = ((a1 & 0xFFF) != 0) + (a1 >> 12);
  v11 = a5;
  v50 = v10;
  if ( (a5 & 2) != 0 && (MiFlags & 0x30000) != 0 )
    v11 = a5 & 0xFFFFFFFD;
  if ( (!a4 || v10 <= a4) && a2 <= a3 && v10 + a2 > a2 && v10 + a2 - 1 <= a3 )
  {
    v12 = 1;
    if ( v11 >> 3 == 1 )
    {
      v12 = 0;
    }
    else if ( v11 >> 3 == 3 && (v11 & 7) != 0 )
    {
      v12 = 2;
    }
    v13 = (unsigned __int16)KeNumberNodes;
    v42 = MiPlatformCacheAttributes[v12];
    if ( (unsigned __int16)KeNumberNodes > 1u )
      v14 = a6;
    else
      v14 = 0;
    if ( v14 == 0x80000000 )
    {
      v36 = __mrc(15, 0, 13, 0, 3);
      v13 = (unsigned __int16)KeNumberNodes;
      v15 = *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)((v36 & 0xFFFFFFC0) + 0x16C)) + 590) + 266);
    }
    else
    {
      v15 = (unsigned __int16)v14;
    }
    v49 = v15;
    v16 = v15 * v13;
    v17 = dword_6337E4;
    v18 = (unsigned __int16 *)(dword_6337E4 + 2 * v16);
    if ( v14 == 0x80000000 )
      v19 = (unsigned int)&v18[v13];
    else
      v19 = (unsigned int)(v18 + 1);
    v48 = 512;
    v46 = v19;
    if ( (v11 & 2) != 0 )
    {
      v48 = 0;
    }
    else if ( v42 == 1 )
    {
      while ( 1 )
      {
        v35 = *v18++;
        v33 = MiFindContiguousMemoryInPool(a2, a3, v7, a1, v35);
        if ( v33 )
          break;
        v19 = v46;
        v7 = a4;
        if ( v18 == (unsigned __int16 *)v46 )
        {
          v13 = (unsigned __int16)KeNumberNodes;
          v17 = dword_6337E4;
          goto LABEL_18;
        }
      }
      if ( ExInsertPoolTag(1953394499, v33, a1, 512, 0) )
        return v33;
      MiFreePoolPages(v33, a1, 1953394499);
      return 0;
    }
LABEL_18:
    v20 = 136314880;
    v21 = (unsigned __int16 *)(v17 + 2 * v13 * v49);
    v40 = *v21;
    v39 = v42;
    for ( i = v7; ; i = a4 )
    {
      v47 = v20;
      if ( MiFindContiguousPages(&MiSystemPartition, a2, a3, i, v10, v39, v40, v41, v20, &v46) >= 0 )
        break;
      if ( ++v21 == (unsigned __int16 *)v19 )
        return 0;
      v40 = *v21;
      v20 = v47 & 0xF7FFFFFF;
      v39 = v42;
    }
    v23 = v46;
    v24 = MiMapContiguousMemory(v46 << 12, v46 >> 20, v10 << 12, v11);
    v47 = v24;
    if ( v24 && !ExInsertPoolTag(1416523587, v24, a1, v48, 1) )
    {
      MmUnmapIoSpace(v24, v10 << 12);
      v24 = 0;
      v47 = 0;
    }
    v25 = MmPfnDatabase + 24 * v23;
    v49 = v25 + 24 * v10;
    if ( v24 )
      v26 = ((v24 >> 10) & 0x3FFFFC) - 0x40000000;
    else
      v26 = 0;
    v27 = (int *)(v25 + 12);
    v28 = v49;
    v45 = (unsigned int *)(v25 + 12);
    do
    {
      *(_DWORD *)(v25 + 20) = *(_DWORD *)(v25 + 20) & 0xFFF00000 | 0xFFFFD;
      v29 = KfRaiseIrql(2);
      v30 = (unsigned __int8 *)v27 + 3;
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 | 0x80, v30) );
      while ( 1 )
      {
        __dmb(0xBu);
        if ( !(v31 >> 7) )
          break;
        do
        {
          __dmb(0xAu);
          __yield();
          v37 = *v27;
          __dmb(0xBu);
        }
        while ( (v37 & 0x80000000) != 0 );
        do
          v31 = __ldrex(v30);
        while ( __strex(v31 | 0x80, v30) );
      }
      *(_DWORD *)(v25 + 4) = v26;
      __dmb(0xBu);
      do
        v32 = __ldrex(v45);
      while ( __strex(v32 & 0x7FFFFFFF, v45) );
      KfLowerIrql(v29);
      v25 += 24;
      v27 = (int *)(v45 + 6);
      v45 += 6;
      if ( v26 )
        v26 += 4;
    }
    while ( v25 < v28 );
    v33 = v47;
    v34 = v50;
    if ( v47 )
    {
      if ( (dword_682604 & 1) != 0 )
      {
        v38 = MiInitPerfMemoryFlags(1, 6);
        MiLogPerfMemoryRangeEvent(v33, 0, v38, v34);
      }
      return v33;
    }
    MiFreeContiguousPages(&MiSystemPartition, v46, v50);
  }
  return 0;
}
