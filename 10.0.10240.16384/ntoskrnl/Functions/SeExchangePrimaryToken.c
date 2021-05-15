// SeExchangePrimaryToken 
 
int __fastcall SeExchangePrimaryToken(int a1, int a2, int *a3)
{
  int v6; // r5
  int v7; // r7
  int v8; // r2
  int v9; // r3
  int v10; // r0
  unsigned int v11; // r1
  __int16 v12; // r3
  unsigned int v13; // r0
  int v14; // r1
  int v15; // r2
  int v16; // r3
  int v17; // r0
  unsigned int v18; // r1
  int v19; // r3
  int v20; // r0
  unsigned int v21; // r1
  __int16 v22; // r3
  int v23; // r0
  int v24; // r4
  int v25; // r2
  int v26; // r3
  int v27; // r0
  unsigned int v28; // r1
  __int16 v29; // r3

  if ( *(_DWORD *)(a2 + 168) != 1 )
    return -1073741656;
  v7 = MmGetSessionId(a1);
  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v9 = *(__int16 *)(v8 + 0x134) - 1;
  *(_WORD *)(v8 + 308) = v9;
  ExAcquireResourceExclusiveLite(*(_DWORD *)(a2 + 48), 1, v8, v9);
  __dmb(0xFu);
  if ( *(_BYTE *)(a2 + 180) )
  {
    __dmb(0xFu);
    v10 = ExReleaseResourceLite(*(_DWORD *)(a2 + 48));
    v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v12 = *(_WORD *)(v11 + 0x134) + 1;
    *(_WORD *)(v11 + 308) = v12;
    if ( !v12 && *(_DWORD *)(v11 + 100) != v11 + 100 && !*(_WORD *)(v11 + 310) )
      KiCheckForKernelApcDelivery(v10);
    v6 = -1073741525;
  }
  else
  {
    *(_BYTE *)(a2 + 180) = 1;
    if ( (*(_DWORD *)(a2 + 176) & 0x4000) == 0
      || (v13 = *(_DWORD *)(a2 + 120), v13 == v7)
      || (SepDereferenceLowBoxNumberEntry(v13, *(_DWORD **)(a2 + 628)),
          v14 = *(_DWORD *)(a2 + 480),
          *(_DWORD *)(a2 + 628) = 0,
          *(_DWORD *)(a2 + 120) = v7,
          v6 = SepSetTokenLowboxNumber(a2, v14, v15, v16),
          v6 >= 0) )
    {
      *(_DWORD *)(a2 + 120) = v7;
      __dmb(0xFu);
      v20 = ExReleaseResourceLite(*(_DWORD *)(a2 + 48));
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = *(_WORD *)(v21 + 0x134) + 1;
      *(_WORD *)(v21 + 308) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery(v20);
      if ( SeAuditingWithTokenForSubcategory(133) )
        SepAuditAssignPrimaryToken();
      ObfReferenceObject(a2);
      v23 = ObFastReplaceObject((unsigned int *)(a1 + 244), a2);
      v24 = v23;
      if ( v23 )
      {
        v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v26 = *(__int16 *)(v25 + 0x134) - 1;
        *(_WORD *)(v25 + 308) = v26;
        ExAcquireResourceExclusiveLite(*(_DWORD *)(v23 + 48), 1, v25, v26);
        __dmb(0xFu);
        *(_BYTE *)(v24 + 180) = 0;
        __dmb(0xFu);
        v27 = ExReleaseResourceLite(*(_DWORD *)(v24 + 48));
        v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v29 = *(_WORD *)(v28 + 0x134) + 1;
        *(_WORD *)(v28 + 308) = v29;
        if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
          KiCheckForKernelApcDelivery(v27);
        *a3 = v24;
        v6 = 0;
      }
      else
      {
        v6 = -1073741700;
      }
    }
    else
    {
      __dmb(0xFu);
      v17 = ExReleaseResourceLite(*(_DWORD *)(a2 + 48));
      v18 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v19 = (__int16)(*(_WORD *)(v18 + 0x134) + 1);
      *(_WORD *)(v18 + 308) = v19;
      if ( !v19 && *(_DWORD *)(v18 + 100) != v18 + 100 && !*(_WORD *)(v18 + 310) )
        KiCheckForKernelApcDelivery(v17);
    }
  }
  return v6;
}
