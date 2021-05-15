// CcPurgeAndClearCacheSection 
 
int __fastcall CcPurgeAndClearCacheSection(int a1, int a2)
{
  int *v2; // r6
  int v4; // r1
  int v5; // r5
  int v6; // r10
  int v7; // r9
  __int64 v8; // r2
  int v9; // r3
  int v10; // r0
  unsigned int *v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r1
  int v14; // r0
  int result; // r0
  int v16; // r8
  unsigned int *v17; // r6
  unsigned int v18; // r4
  unsigned int i; // r3
  unsigned int v20; // r1
  int v21; // [sp+14h] [bp-44h]
  _BYTE *v22; // [sp+18h] [bp-40h]
  _BYTE *v23; // [sp+20h] [bp-38h] BYREF
  int v24; // [sp+24h] [bp-34h] BYREF
  int v25; // [sp+28h] [bp-30h] BYREF
  int v26; // [sp+2Ch] [bp-2Ch]
  int v27; // [sp+30h] [bp-28h]
  int anonymous5; // [sp+60h] [bp+8h]
  int *anonymous6; // [sp+64h] [bp+Ch]

  anonymous6 = (int *)a2;
  v2 = (int *)a2;
  anonymous5 = a1;
  if ( (*(_DWORD *)(a1 + 96) & 0x2000) != 0 )
  {
    if ( (a2 & 1) == 0 )
      return -1073740747;
    v2 = (int *)(a2 ^ 1);
  }
  v5 = ObFastReferenceObject(a1 + 68);
  if ( !v5 )
    v5 = CcSlowReferenceSharedCacheMapFileObject(a1);
  if ( (*v2 & 0xFFF) != 0 )
  {
    v6 = *v2;
    v25 = *v2;
    v21 = v2[1];
    v26 = v21;
    v2 = &v25;
    anonymous6 = &v25;
    if ( *(_DWORD *)(a1 + 108) && *(_DWORD *)(a1 + 64) )
    {
      v7 = 4096 - (v6 & 0xFFF);
      v22 = (_BYTE *)CcGetVirtualAddress(a1, v4, v25, v26, &v24, &v23, 1, 0, v5);
      v23 = v22;
      memset(v22, 0, v7);
      v8 = *(_QWORD *)(a1 + 40);
      if ( __SPAIR64__(v21, v6) > v8 )
      {
        MmSetAddressRangeModified(v22, 1, v8);
        CcUpdateSharedCacheMapFlag(a1, 0x20000, 1);
      }
      else
      {
        CcSetDirtyInMask(a1, &v25, 4096 - (v6 & 0xFFF), 0);
      }
      v25 = v7 + v6;
      v26 = __CFADD__(v7, v6) + v21;
      v9 = v24;
      v10 = *(_DWORD *)(v24 + 4);
      __dmb(0xBu);
      v11 = (unsigned int *)(v9 + 8);
      do
      {
        v12 = __ldrex(v11);
        v13 = v12 - 1;
      }
      while ( __strex(v13, v11) );
      __dmb(0xBu);
      if ( !(_WORD)v13 )
      {
        v14 = *(_DWORD *)(v10 + 116);
        if ( v14 )
          KeSetEvent(v14, 0, 0);
      }
    }
    else
    {
      MmFlushSection(*(_DWORD *)(v5 + 20), &v25, 1);
      result = v27;
      if ( v27 < 0 )
        return result;
    }
  }
  v16 = CcPurgeCacheSection(*(_DWORD *)(v5 + 20), v2, 0, 0);
  v17 = (unsigned int *)(a1 + 68);
  __pld((void *)(a1 + 68));
  v18 = *(_DWORD *)(a1 + 68);
  for ( i = v18 ^ v5; i < 7; i = v20 ^ v5 )
  {
    __dmb(0xBu);
    do
      v20 = __ldrex(v17);
    while ( v20 == v18 && __strex(v18 + 1, v17) );
    if ( v20 == v18 )
      goto LABEL_26;
    v18 = v20;
  }
  ObDereferenceObjectDeferDeleteWithTag(v5, 1953261124);
LABEL_26:
  if ( v16 )
    return 0;
  return -1073740747;
}
