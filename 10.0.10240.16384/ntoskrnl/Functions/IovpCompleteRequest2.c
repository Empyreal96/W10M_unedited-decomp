// IovpCompleteRequest2 
 
int __fastcall IovpCompleteRequest2(int result, int a2)
{
  _DWORD *v2; // r8
  __int64 v4; // r4
  unsigned int *v5; // r6
  char v6; // r7
  unsigned int v7; // r2
  int v8; // r9
  int v9; // r2
  int v10; // r3
  int v11; // r7
  int v12; // r1
  int v13; // r3
  bool v14; // zf
  int v15; // r2
  int v16; // r6
  int v17; // r2
  int v18; // r3
  _DWORD **v19; // r6
  _DWORD *v20; // r1
  __int64 v21; // r2
  _DWORD *v22; // r7
  int v23; // r2
  int v24; // r2
  int v25; // r2
  int v26; // r3
  _DWORD *v27; // r3
  unsigned int v28; // r6
  int v29; // r0
  unsigned int *v30; // r2
  unsigned int v31; // r1
  int v32; // [sp+8h] [bp-28h] BYREF
  int v33; // [sp+Ch] [bp-24h]
  int v34; // [sp+10h] [bp-20h]

  v2 = *(_DWORD **)a2;
  HIDWORD(v4) = result;
  if ( *(_DWORD *)a2 )
  {
    LODWORD(v4) = *(_DWORD *)(a2 + 4);
    v5 = (unsigned int *)(v4 + 4);
    v6 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(v4 + 4);
    }
    else
    {
      do
        v7 = __ldrex(v5);
      while ( __strex(1u, v5) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(v4 + 4));
    }
    *(_BYTE *)(v4 + 8) = v6;
    if ( *(_DWORD *)(v4 + 144) )
      ViWdIrpBeforeCompletionRoutine(v4 + 144);
    v32 = *(_DWORD *)(HIDWORD(v4) + 24);
    v8 = (int)&v2[20 * *(char *)(HIDWORD(v4) + 35) - 10];
    v9 = v2[20 * *(char *)(HIDWORD(v4) + 35) - 8];
    v10 = *(_DWORD *)(v9 + 4);
    if ( (v10 & 0x40000000) != 0 )
    {
      v11 = 0;
    }
    else
    {
      *(_DWORD *)(v9 + 4) = v10 | 0x40000000;
      v11 = 1;
    }
    v12 = *(_DWORD *)(HIDWORD(v4) + 96);
    v13 = *(char *)(HIDWORD(v4) + 34);
    v14 = v8 == v9;
    v15 = *(char *)(HIDWORD(v4) + 35);
    v16 = v14;
    v33 = *(_DWORD *)(HIDWORD(v4) + 96);
    if ( v15 <= v13 )
    {
      v17 = *(unsigned __int8 *)(v12 - 40);
      if ( (v17 == 4 || v17 == 3) && *(_DWORD *)(HIDWORD(v4) + 4) && (MmVerifierData & 0x6000) != 0 )
      {
        MdlInvariantPostProcessing1(v4, v12 - 40);
        v12 = v33;
      }
    }
    VfMajorVerifyIrpStackUpward(v4, v12 - 40, v8, v11, v16);
    v18 = v2[4];
    v34 = v32;
    if ( (v18 & 2) == 0 && (*(_DWORD *)(v8 + 4) & 0x4000000) != 0 && !*(_BYTE *)(HIDWORD(v4) + 33) )
    {
      if ( (*(_DWORD *)(HIDWORD(v4) + 8) & 0x800) != 0 )
        VfErrorReport6(574, *(_DWORD *)(v8 + 24), HIDWORD(v4), v32);
      v2[4] |= 2u;
    }
    v19 = (_DWORD **)(v8 + 12);
    while ( *v19 != v19 )
    {
      LODWORD(v21) = *v19;
      HIDWORD(v21) = (*v19)[1];
      v20 = (_DWORD *)**v19;
      if ( v21 != __PAIR64__((unsigned int)v19, v20[1]) )
        __fastfail(3u);
      *v19 = v20;
      v22 = (_DWORD *)(v21 - 16);
      v20[1] = v19;
      v23 = *(_DWORD *)(v21 - 4) | 0x40000000;
      v22[3] = v23;
      v22[7] = v32;
      if ( *(_BYTE *)(HIDWORD(v4) + 33) )
        v22[3] = v23 | 0x2000000;
      IovpValidateStatusInformation(v4, v22[10], v22 + 12, *(_DWORD *)(a2 + 20));
      if ( (*(_DWORD *)(v4 + 36) & 0x20) == 0 )
      {
        if ( VfMajorAdvanceIrpStatus(v33 - 40, v34, &v32) )
        {
          v22[3] |= 0x8000000u;
          v22[8] = v32;
        }
      }
    }
    *(_DWORD *)(HIDWORD(v4) + 24) = v32;
    memset((_BYTE *)v8, 0, 80);
    *v19 = v19;
    *(_DWORD *)(v8 + 16) = v8 + 12;
    v24 = *(unsigned __int8 *)(v4 + 108);
    *(_BYTE *)(v4 + 110) = *(_BYTE *)(HIDWORD(v4) + 35) + 1;
    if ( v24 == *(char *)(HIDWORD(v4) + 35) )
    {
      *(_DWORD *)a2 = 0;
      *(_DWORD *)(a2 + 4) = 0;
      VfMajorVerifyFinalIrpStack(v4, *(_DWORD *)(HIDWORD(v4) + 96) - 40);
      v25 = *v2;
      v26 = *(_DWORD *)(*v2 + 36);
      *(_DWORD *)(v25 + 140) = 0;
      *(_DWORD *)(v25 + 36) = v26 & 0xFFFFFFFE;
      IovpSessionDataDereference(v2);
      VfIrpDatabaseEntryDereference(v4, 1);
      v27 = *(_DWORD **)(v4 + 132);
      if ( v27 )
      {
        v28 = 0;
        if ( *v27 )
        {
          HIDWORD(v4) = 0;
          do
          {
            v29 = *(_DWORD *)(*(_DWORD *)(v4 + 132) + 4);
            if ( *(_DWORD *)(v29 + HIDWORD(v4)) )
              memset((_BYTE *)(v29 + HIDWORD(v4)), 0, 32);
            ++v28;
            HIDWORD(v4) += 32;
          }
          while ( v28 < **(_DWORD **)(v4 + 132) );
        }
        *(_DWORD *)(*(_DWORD *)(v4 + 132) + 8) = 0;
      }
    }
    else
    {
      IovpSessionDataReference(v2);
      __dmb(0xBu);
      v30 = (unsigned int *)(v4 + 12);
      do
        v31 = __ldrex(v30);
      while ( __strex(v31 + 1, v30) );
      __dmb(0xBu);
    }
    result = VfIrpDatabaseEntryReleaseLock(v4);
    --*(_DWORD *)(a2 + 12);
  }
  return result;
}
