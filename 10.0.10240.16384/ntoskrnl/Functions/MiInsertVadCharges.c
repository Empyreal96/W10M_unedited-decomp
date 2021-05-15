// MiInsertVadCharges 
 
int __fastcall MiInsertVadCharges(int a1, int a2)
{
  __int64 v3; // kr00_8
  unsigned int v4; // r9
  unsigned int v6; // r10
  int result; // r0
  int v8; // r4
  int v9; // r1
  int v10; // r0
  int v11; // r5
  int v12; // r3
  unsigned int v13; // r3
  int v14; // r4
  int v15; // r5
  unsigned int v16; // r1
  __int16 *v17; // r4
  unsigned int v18; // r1
  unsigned int v19; // r5
  int v20; // r4
  int v21; // r3
  unsigned int v22; // r0
  unsigned int v23; // [sp+0h] [bp-28h]
  unsigned int v24; // [sp+4h] [bp-24h]

  v3 = *(_QWORD *)(a1 + 12);
  v4 = (_DWORD)v3 << 12;
  v6 = HIDWORD(v3) << 12;
  v23 = 0;
  v24 = 0;
  if ( (*(_DWORD *)(a1 + 32) & 0x7FFFFFFFu) >= 0x7FFFE )
    goto LABEL_13;
  result = PsChargeProcessNonPagedPoolQuota(a2, 76);
  if ( result < 0 )
    return result;
  v8 = 0;
  if ( (*(_DWORD *)(a1 + 28) & 0x8000) != 0 )
  {
    if ( (*(_DWORD *)(a1 + 28) & 7) == 5 )
      v8 = 1;
  }
  else if ( !MiVadPureReserve(a1) )
  {
    if ( (*(_BYTE *)(a1 + 43) & 1) != 0 )
      return sub_8018D8();
    v9 = 4 * (*(_DWORD *)(a1 + 16) - *(_DWORD *)(a1 + 12) + 1);
    v24 = v9;
    if ( a2 != PsInitialSystemProcess )
    {
      v10 = *(_DWORD *)(a2 + 332);
      __dmb(0xBu);
      v11 = PspChargeQuota(v10, a2, 1, v9);
      if ( v11 < 0 )
      {
        PsReturnProcessNonPagedPoolQuota(a2, 0x4Cu);
        return v11;
      }
    }
  }
  v12 = *(_DWORD *)(a1 + 28) & 7;
  if ( v12 != 6 && v12 != 1 && v12 != 3 && v8 != 1 )
    goto LABEL_13;
  v16 = MiResidentPagesForSpan(v4, v6);
  v23 = v16;
  if ( v8 == 1 )
  {
    v21 = ((int)(((4 * HIDWORD(v3)) & 0x3FFFFC) - ((4 * v3) & 0x3FFFFC)) >> 2) + 1;
    v16 = v16
        - ((((4 * (_DWORD)v3) & 0xFFC) + ((4 * (_WORD)v21) & 0xFFFu) + 4095) >> 12)
        - ((unsigned int)(4 * v21) >> 12);
    v23 = v23
        - ((((4 * (_DWORD)v3) & 0xFFC) + ((4 * (_WORD)v21) & 0xFFFu) + 4095) >> 12)
        - ((unsigned int)(4 * v21) >> 12);
  }
  if ( !v16 )
    goto LABEL_13;
  v17 = MiGetThreadPartition();
  if ( MiChargeResident(v17, v18, 128) )
  {
    if ( v17 == MiSystemPartition )
    {
      do
        v19 = __ldrex(&dword_634A2C[34]);
      while ( __strex(v19 + v23, &dword_634A2C[34]) );
    }
LABEL_13:
    v13 = *(_DWORD *)(a1 + 32) & 0x7FFFFFFF;
    if ( v13 >= 0x7FFFE && v13 != 524286
      || (v14 = __mrc(15, 0, 13, 0, 3),
          LOCK_PAGE_TABLE_COMMITMENT(v14 & 0xFFFFFFC0, a2),
          v15 = MiCommitPageTablesForVad(a1, v4, v6),
          UNLOCK_PAGE_TABLE_COMMITMENT(v14 & 0xFFFFFFC0, a2),
          v15 >= 0) )
    {
      MiSetVadBits(a1);
      return 0;
    }
    v20 = v23;
    goto LABEL_31;
  }
  v15 = -1073741670;
  v20 = 0;
LABEL_31:
  PsReturnProcessNonPagedPoolQuota(a2, 0x4Cu);
  if ( v24 )
    PsReturnProcessPagedPoolQuota(a2, v24);
  if ( v20 )
  {
    MiReturnResidentAvailable(v20);
    do
      v22 = __ldrex(&dword_634A2C[36]);
    while ( __strex(v22 + v20, &dword_634A2C[36]) );
  }
  return v15;
}
