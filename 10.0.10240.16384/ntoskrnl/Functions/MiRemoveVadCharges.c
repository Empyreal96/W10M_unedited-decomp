// MiRemoveVadCharges 
 
int __fastcall MiRemoveVadCharges(int a1, int a2)
{
  int v4; // r6
  __int16 *v5; // r9
  unsigned int v6; // r7
  int result; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r1
  unsigned int v11; // r3
  int v12; // r1
  int v13; // r0
  unsigned int v14; // r4
  int v15; // r0
  unsigned int v16; // r4
  int v17; // r3
  _DWORD *v18; // r0
  _DWORD *v19; // r4
  __int64 v20; // kr00_8
  unsigned int v21; // r0
  int v22; // r4
  unsigned int v23; // r0
  unsigned int *v24; // r2
  unsigned int v25; // r4
  int v26; // r3
  int v27; // [sp+0h] [bp-30h] BYREF
  unsigned int v28; // [sp+4h] [bp-2Ch]
  char v29[4]; // [sp+8h] [bp-28h] BYREF
  int v30; // [sp+Ch] [bp-24h]
  int v31; // [sp+10h] [bp-20h]

  v4 = 0;
  v5 = MiGetThreadPartition();
  if ( (*(_DWORD *)(a1 + 28) & 0x8000) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 28) & 7) != 5 )
      goto LABEL_3;
  }
  else if ( (*(_BYTE *)(a1 + 43) & 1) == 0 )
  {
    goto LABEL_3;
  }
  v4 = 1;
LABEL_3:
  v6 = *(_DWORD *)(a1 + 32) & 0x7FFFFFFF;
  if ( v6 >= 0x7FFFE )
    return sub_8015EC();
  v30 = *(_DWORD *)(a1 + 4);
  v31 = *(_DWORD *)a1;
  MiFillCommitReturnInfo(v6, (int)v29, &v27);
  if ( v27 )
    MiReturnFullProcessCharges(a2, v27, v8, v9);
  v10 = v28;
  if ( v28 )
  {
    v11 = *(_DWORD *)(a2 + 608);
    if ( !v11 )
      goto LABEL_9;
    if ( v28 > v11 )
    {
      v10 = v28 - v11;
      *(_DWORD *)(a2 + 608) = 0;
LABEL_9:
      if ( v10 )
        MiReturnCommit((int)v5, v10);
      goto LABEL_11;
    }
    *(_DWORD *)(a2 + 608) = v11 - v28;
  }
LABEL_11:
  v12 = 0;
  if ( (*(_DWORD *)(a1 + 28) & 0x4000) != 0 )
    v12 = 2;
  if ( v4 == 1 )
    v12 |= 0x10u;
  if ( v12 )
  {
    v18 = (_DWORD *)MiGetVadWakeList(a1, v12);
    if ( v18 )
    {
      do
      {
        v19 = (_DWORD *)*v18;
        ExFreePoolWithTag((unsigned int)v18);
        v18 = v19;
      }
      while ( v19 );
    }
  }
  v13 = MiGetVadWakeList(a1, 8);
  v14 = v13;
  if ( v13 )
  {
    v23 = *(_DWORD *)(v13 + 8);
    if ( v23 )
      ExFreePoolWithTag(v23);
    ExFreePoolWithTag(v14);
  }
  v15 = MiGetVadWakeList(a1, 4);
  v16 = v15;
  if ( v15 )
  {
    PsReturnProcessNonPagedPoolQuota(a2, 4 * (((*(_DWORD *)(v15 + 8) & 0x1F) != 0) + (*(_DWORD *)(v15 + 8) >> 5) + 6));
    ExFreePoolWithTag(v16);
  }
  result = MiFreePhysicalView(a2, a1);
  if ( v4 == 1 && (*(_DWORD *)(a1 + 28) & 7) != 7 )
  {
    result = -v6;
    v24 = (unsigned int *)(a2 + 648);
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 - v6, v24) );
  }
  v17 = *(_DWORD *)(a1 + 28) & 7;
  if ( v17 == 6 || v17 == 1 || v17 == 3 || v4 == 1 )
  {
    v20 = *(_QWORD *)(a1 + 12);
    v21 = MiResidentPagesForSpan((_DWORD)v20 << 12, (HIDWORD(v20) << 12) | 0xFFF);
    v22 = v21;
    if ( v4 == 1 )
    {
      v26 = ((int)(4 * (HIDWORD(v20) & 0xFFFFF) - 4 * (v20 & 0xFFFFF)) >> 2) + 1;
      v22 = v21
          - ((((4 * (_WORD)v26) & 0xFFF) + 4 * (unsigned int)(v20 & 0x3FF) + 4095) >> 12)
          - ((unsigned int)(4 * v26) >> 12);
    }
    if ( v5 == MiSystemPartition )
    {
      MiReturnResidentAvailable(v22);
      do
        result = __ldrex(&dword_634A2C[35]);
      while ( __strex(result + v22, &dword_634A2C[35]) );
    }
    else
    {
      result = MiReturnPartitionResidentAvailable((int)v5, v22);
    }
  }
  return result;
}
