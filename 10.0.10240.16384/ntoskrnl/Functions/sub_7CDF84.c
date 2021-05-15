// sub_7CDF84 
 
void sub_7CDF84()
{
  int v0; // r4
  int v1; // r6
  int v2; // r7
  unsigned __int16 *v3; // r8
  int v4; // r9
  int v5; // r10
  int v6; // r2
  unsigned int v7; // r5
  unsigned int v8; // r4
  unsigned int v9; // r8
  int v10; // r0
  int v11; // r4
  _DWORD *v12; // r0
  _DWORD *v13; // r8
  int v14; // r2
  int v15; // r3
  int v16; // r0
  int v17; // r0
  int v18; // [sp+Ch] [bp-4Ch]
  unsigned int v19; // [sp+18h] [bp-40h]
  unsigned int v20; // [sp+1Ch] [bp-3Ch] BYREF
  int v21; // [sp+20h] [bp-38h] BYREF

  if ( !RtlEqualUnicodeString(v3, (unsigned __int16 *)(v0 + 8), 1) )
    JUMPOUT(0x773758);
  if ( v4 )
  {
    v5 = MiSectionControlArea(v4);
    v6 = v5 + 80;
    if ( v5 != -80 )
    {
      while ( (*(_WORD *)(v6 + 16) & 0x3E) != 0 )
      {
        v6 = *(_DWORD *)(v6 + 8);
        if ( !v6 )
          goto LABEL_8;
      }
LABEL_25:
      JUMPOUT(0x773760);
    }
  }
  else
  {
    v5 = 0;
  }
LABEL_8:
  v7 = (v1 + 1023) & 0xFFFFFC00;
  v8 = MiRoundUpToPowerOf2SizeT(v7);
  if ( MiFindContiguousPages(
         MiSystemPartition,
         1024,
         *(_DWORD *)(v2 + 3536),
         v8,
         v8,
         1,
         0x80000000,
         v18,
         0x200000,
         &v20) < 0 )
    goto LABEL_25;
  v9 = v20;
  if ( v8 > v7 )
    MiFreeContiguousPages((int)MiSystemPartition, v20 + v7, v8 - v7);
  v10 = MiMapWithLargePages(v9, (v1 + 1023) & 0xFFFFFC00, 6, 1, 12);
  v11 = v10;
  if ( !v10 )
  {
    MiFreeContiguousPages((int)MiSystemPartition, v9, (v1 + 1023) & 0xFFFFFC00);
    goto LABEL_25;
  }
  memmove(v10, v19, v1 << 12);
  v12 = (_DWORD *)RtlImageNtHeader(v11);
  v13 = v12;
  if ( v12[29] <= 5u )
    goto LABEL_17;
  v14 = v12[40];
  if ( v14 )
  {
    v15 = v12[41];
    v16 = v11;
    if ( v15 + v14 > (unsigned int)(v1 << 12) )
    {
LABEL_18:
      MiUnmapLargeDriver(v16, v1);
      goto LABEL_25;
    }
    if ( LdrRelocateImage(v11) < 0 )
    {
LABEL_17:
      v16 = v11;
      goto LABEL_18;
    }
  }
  v13[13] = v11;
  if ( v4 )
  {
    MiDeleteSystemPagableVm((int *)(v2 + 9344), v5, ((v19 >> 10) & 0x3FFFFC) - 0x40000000, v1, 1, &v21);
    MiChargeSystemImageCommitment(v4);
  }
  if ( (dword_682604 & 1) != 0 )
  {
    v17 = MiInitPerfMemoryFlags(1, 6);
    MiLogPerfMemoryRangeEvent(v11, 0, v17, (v1 + 1023) & 0xFFFFFC00);
  }
  KeSweepIcacheRange(0, v11, v7 << 12);
  JUMPOUT(0x773762);
}
