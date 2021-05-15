// HvSyncHive 
 
int __fastcall HvSyncHive(int a1, int a2, int a3, unsigned int a4)
{
  int v5; // r3
  int v6; // r7
  unsigned int v7; // r6
  int v8; // r8
  int v9; // r5
  int v10; // r10
  int v11; // r9
  int v12; // r2
  int v13; // r0
  unsigned int v14; // r2
  unsigned int v16[8]; // [sp+0h] [bp-20h] BYREF

  v16[0] = a4;
  v5 = *(_DWORD *)(a1 + 44);
  v6 = 0;
  v7 = 0;
  v8 = 0;
  v16[0] = 0;
  if ( !v5 && !*(_DWORD *)(a1 + 60) && !*(_BYTE *)(a1 + 123) )
    return 1;
  if ( (*(_DWORD *)(a1 + 92) & 0x8000) != 0 )
    return 1;
  v10 = HvpTruncateBins(a1);
  if ( (*(_DWORD *)(a1 + 92) & 1) != 0 )
    return 1;
  v11 = IoSetThreadHardErrorMode(0);
  if ( *(_DWORD *)(a1 + 44) || *(_BYTE *)(a1 + 123) )
  {
    if ( !HvpMarkDirty(a1, 0, 0x1000u) )
      goto LABEL_18;
    if ( *(_DWORD *)(a1 + 96) )
    {
      v13 = HvWriteLogFile((_DWORD *)a1, 0, v12, v16);
      v7 = v16[0];
      if ( v13 < 0 )
        goto LABEL_18;
      v6 = 1;
    }
    HvUpdateUnreconciledVector((unsigned int *)a1, 0);
    if ( *(_BYTE *)(a1 + 122) && HvValidateOrInvalidatePrimaryFileHeader(a1, 0, 0, 0) < 0 )
      goto LABEL_18;
  }
  if ( HvWriteHivePrimaryFile(a1, 0, 0) >= 0 && HvValidateOrInvalidatePrimaryFileHeader(a1, 1, 0, 0) >= 0 )
  {
    v9 = 1;
    v8 = 1;
    *(_DWORD *)(*(_DWORD *)(a1 + 32) + 8) = *(_DWORD *)(*(_DWORD *)(a1 + 32) + 4);
    goto LABEL_19;
  }
LABEL_18:
  v9 = 0;
LABEL_19:
  IoSetThreadHardErrorMode(v11);
  if ( v9 )
  {
    v14 = *(_DWORD *)(a1 + 952);
    if ( *(_DWORD *)(a1 + 1936) < v14 || v10 == 1 )
      *(_DWORD *)(a1 + 1936) = v14;
  }
  if ( v8 )
  {
    if ( *(_DWORD *)(a1 + 96) )
      HvResetLogFileStatusAll(a1);
    HvResetDirtyData((_BYTE *)a1);
    HvResetUnreconciledData((_BYTE *)a1);
    *(_DWORD *)(a1 + 108) = 0;
  }
  else if ( v6 )
  {
    *(_DWORD *)(a1 + 108) -= v7;
    --*(_DWORD *)(a1 + 100);
  }
  return v9;
}
