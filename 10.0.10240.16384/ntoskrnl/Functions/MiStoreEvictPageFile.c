// MiStoreEvictPageFile 
 
int *__fastcall MiStoreEvictPageFile(int *result, int a2, int a3)
{
  int *v3; // r4
  int v4; // r10
  int v5; // r3
  unsigned int v6; // r9
  unsigned int v7; // r1
  int v8; // r3
  unsigned int v9; // r5
  unsigned int v10; // r7
  int v11; // r0
  unsigned int v12; // r8
  unsigned int v13; // [sp+0h] [bp-48h]
  unsigned int v14; // [sp+4h] [bp-44h] BYREF
  char v15[16]; // [sp+8h] [bp-40h] BYREF
  int *v16[3]; // [sp+18h] [bp-30h] BYREF
  unsigned int v17[9]; // [sp+24h] [bp-24h] BYREF

  v3 = result;
  v4 = result[24] & 0xF;
  v5 = result[23];
  if ( v5 )
  {
    MiRefPageFileSpaceBitmaps(result, v16, a3, v5);
    v6 = v14;
    v7 = 0;
    do
    {
      v9 = RtlFindNextForwardRunClearCapped(v17, v7, 0xFFFFFFFF, &v14);
      if ( !v9 )
        break;
      v10 = v14;
      if ( ((v14 & 0xFFFFFFF | (v4 << 28)) & 0xF0000000) != -268435456 )
        v6 = v14 & 0xFFFFFFF | (v4 << 28);
      v13 = v6;
      v11 = SMKM_STORE_MGR<SM_TRAITS>::SmpPageEvict();
      v12 = v9 - v11;
      if ( v9 != v11 )
      {
        do
        {
          v13 += v11;
          v11 = SMKM_STORE_MGR<SM_TRAITS>::SmpPageEvict();
          v12 -= v11;
        }
        while ( v12 );
      }
      KeAcquireInStackQueuedSpinLock((unsigned int *)v3 + 29, (unsigned int)v15);
      RtlSetBits((_BYTE *)(v3[16] + 12), v10, v9);
      v3[23] -= v9;
      RtlClearBits((_BYTE *)(v3[16] + 4), v10, v9);
      v3[3] += v9;
      KeReleaseInStackQueuedSpinLock((int)v15);
      v8 = v3[23];
      if ( !v8 )
        break;
      v8 = v17[0];
      v7 = v10 + v9;
    }
    while ( v10 + v9 < v17[0] );
    result = MiDerefPageFileSpaceBitmaps((int)v3, v16, 0, v8);
    if ( result )
      result = (int *)ExFreePoolWithTag(result);
  }
  return result;
}
