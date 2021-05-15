// MiMapLockedPagesInUserSpace 
 
unsigned int MiMapLockedPagesInUserSpace(int a1, __int16 a2, int a3, ...)
{
  int v3; // r4
  unsigned int v4; // r4
  unsigned int v5; // r5
  int *v6; // r9
  _BYTE *v7; // r0
  _DWORD *v8; // r6
  unsigned int v9; // r4
  unsigned int i; // r8
  int v11; // r4
  unsigned int v12; // r0
  int v13; // r4
  int v14; // r8
  int v16; // r2
  int *v17; // r10
  int v18; // r7
  int v19; // r8
  unsigned int v20; // r7
  unsigned int v21; // r5
  int v22; // r8
  unsigned int v23; // t1
  __int64 v24; // [sp+10h] [bp-40h]
  unsigned int v25; // [sp+10h] [bp-40h]
  int *v26; // [sp+14h] [bp-3Ch]
  unsigned int v27; // [sp+18h] [bp-38h] BYREF
  int v28; // [sp+1Ch] [bp-34h]
  unsigned int v29; // [sp+20h] [bp-30h]
  int v30; // [sp+24h] [bp-2Ch]
  int v31; // [sp+28h] [bp-28h]
  int v32; // [sp+2Ch] [bp-24h]
  unsigned int varg_r3; // [sp+64h] [bp+14h] BYREF
  va_list varg_r3a; // [sp+64h] [bp+14h]
  int v35; // [sp+68h] [bp+18h]
  va_list va1; // [sp+6Ch] [bp+1Ch] BYREF

  va_start(va1, a3);
  va_start(varg_r3a, a3);
  varg_r3 = va_arg(va1, _DWORD);
  v35 = va_arg(va1, _DWORD);
  v3 = *(_DWORD *)(a1 + 20);
  v28 = a3;
  v4 = ((a2 & 0xFFFu) + v3 + 4095) >> 12;
  v5 = varg_r3;
  v32 = a1;
  v6 = (int *)(a1 + 28);
  LODWORD(v24) = v4;
  HIDWORD(v24) = a1 + 28;
  v7 = (_BYTE *)ExAllocatePoolWithTag(512, 76, 1818517846);
  v8 = v7;
  if ( !v7 )
    sub_7E63C4();
  memset(v7, 0, 76);
  v8[2] = -2;
  v8[6] = 0;
  if ( v35 >= 0 )
    v19 = 4;
  else
    v19 = 1;
  v8[7] = v8[7] & 0xFFFFFF01 | (8 * (v19 & 0x1F)) | 0x8001;
  v16 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v29 = 0;
  v30 = v16;
  v27 = 0;
  v17 = 0;
  v18 = *(_DWORD *)(v16 + 0x74);
  v31 = MiPlatformCacheAttributes[v28 + 6];
  if ( v5 )
  {
    if ( (v5 & 0xFFF) != 0
      || v5 < 0x10000 && !*(_DWORD *)(v18 + 780)
      || (v9 = v5 + (v4 << 12) - 1, v9 <= v5)
      || v9 > MmHighestUserAddress - 0x10000 )
    {
      v13 = -1073741503;
      goto LABEL_39;
    }
  }
  else
  {
    v9 = 0;
  }
  LOCK_ADDRESS_SPACE(v16, v18);
  if ( (*(_DWORD *)(v18 + 192) & 0x20) != 0 )
  {
    v13 = -1073741558;
    goto LABEL_28;
  }
  if ( v5 )
  {
    if ( !MiCheckForConflictingVadExistence() )
      goto LABEL_11;
    v13 = -1073741800;
LABEL_28:
    UNLOCK_ADDRESS_SPACE(v30, v18);
    if ( v17 )
    {
      v20 = 1;
      v21 = v6 > v17 ? 0 : (unsigned int)((char *)v17 - (char *)v6 + 4) >> 2;
      if ( v21 )
      {
        do
        {
          v23 = *v6++;
          v22 = v23;
          if ( !MI_IS_PFN(v23) )
            MiDereferenceIoPages(1, v22, 1);
          ++v20;
        }
        while ( v20 <= v21 );
      }
    }
LABEL_39:
    ExFreePoolWithTag((unsigned int)v8);
    RtlRaiseStatus(v13);
  }
  v13 = MiFindEmptyAddressRange(v25 << 12, 0x10000, MmHighestUserAddress - 0x10000, v19, (unsigned int *)varg_r3a, &v27);
  if ( v13 < 0 )
    goto LABEL_28;
  v5 = varg_r3;
  v9 = varg_r3 + (v25 << 12) - 1;
  v29 = v27;
LABEL_11:
  v8[3] = v5 >> 12;
  v27 = v9 >> 12;
  v8[4] = v9 >> 12;
  for ( i = 0; i < v25; ++i )
  {
    v11 = *v26;
    v12 = *v26++;
    if ( !MI_IS_PFN(v12) )
    {
      v13 = MiReferenceIoPages(1, v11, 1, v31, 0, 0);
      if ( v13 < 0 )
        goto LABEL_28;
      v17 = v26 - 1;
    }
  }
  v13 = MiInsertVadCharges(v8, v18);
  if ( v13 < 0 )
    goto LABEL_28;
  v14 = v30;
  MiLockVad(v30, (int)v8);
  MiMapLockedPagesInUserSpaceHelper(v5, v6, 0, v28, v25, (int)v8, v35);
  MiUnlockVad(v14, (int)v8);
  if ( v29 == 1 )
    MiAdvanceVadHint(v5 >> 12, v27);
  UNLOCK_ADDRESS_SPACE(v14, v18);
  return *(_DWORD *)(v32 + 24) + v5;
}
