// SepSetTokenUserAndGroups 
 
int __fastcall SepSetTokenUserAndGroups(_DWORD *a1, int a2, int a3, int a4, int a5)
{
  int v7; // r0
  int v8; // r5
  int v11; // r9
  int v12; // r7
  int v13; // r5
  int v14; // r6
  int v15; // r0
  int v16; // r2
  int v17; // r0
  unsigned int v18; // r0
  bool v19; // zf
  int v20; // r5
  int v21; // r6
  int v22; // r2
  int v23; // r3
  unsigned int v25; // r2
  unsigned __int8 *v26; // r8
  int v27; // r0
  unsigned int v28; // r2
  unsigned int *v29; // r6
  unsigned int v30; // r1
  int v31; // r0
  unsigned int v32; // r1
  int v33; // r3
  unsigned int *v34; // r2
  unsigned int v35; // r1
  signed int v36; // r1
  unsigned int *v37; // r2
  unsigned int v38; // r1
  signed int v39; // r1
  int v40; // [sp+8h] [bp-30h] BYREF
  int v41; // [sp+Ch] [bp-2Ch] BYREF
  int v42; // [sp+10h] [bp-28h]
  int v43; // [sp+14h] [bp-24h]

  v7 = a1[46];
  v8 = -1;
  v42 = a3;
  v43 = a2;
  v40 = 0;
  v41 = 0;
  v11 = 0;
  if ( v7 != -1 )
  {
    v8 = v7 - 1;
    v12 = SepDuplicateSid(*(_DWORD *)(a4 + 8 * (v7 - 1)), &v40);
    if ( v12 < 0 )
      return v12;
    a1[162] = v40;
  }
  v12 = SepCreateSidValuesBlock(&v41, a2, a3, a4, a5, v8);
  if ( v12 < 0 )
    return v12;
  v13 = v41;
  if ( *(_DWORD *)(a1[48] + 68) )
    goto LABEL_6;
  v25 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v25 + 308);
  v26 = (unsigned __int8 *)(a1[48] + 60);
  v27 = KeAbPreAcquire((unsigned int)v26, 0, 0);
  do
    v28 = __ldrex(v26);
  while ( __strex(v28 | 1, v26) );
  __dmb(0xBu);
  if ( (v28 & 1) == 0 )
  {
    if ( v27 )
      *(_BYTE *)(v27 + 14) |= 1u;
    if ( !*(_DWORD *)(a1[48] + 68) )
    {
      v34 = (unsigned int *)(v13 + 4);
      do
      {
        v35 = __ldrex(v34);
        v36 = v35 + 1;
      }
      while ( __strex(v36, v34) );
      if ( v36 <= 1 )
        __fastfail(0xEu);
      v11 = 1;
      *(_DWORD *)(a1[48] + 68) = v13;
    }
    v29 = (unsigned int *)(a1[48] + 60);
    __dmb(0xBu);
    do
      v30 = __ldrex(v29);
    while ( __strex(v30 - 1, v29) );
    if ( (v30 & 2) != 0 && (v30 & 4) == 0 )
      ExfTryToWakePushLock(v29);
    v31 = KeAbPostRelease((unsigned int)v29);
    v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v33 = (__int16)(*(_WORD *)(v32 + 0x134) + 1);
    *(_WORD *)(v32 + 308) = v33;
    if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
      KiCheckForKernelApcDelivery(v31);
    if ( v11 )
    {
      v17 = 0;
      v16 = *(_DWORD *)(a1[48] + 68);
      goto LABEL_10;
    }
LABEL_6:
    v14 = *(_DWORD *)(a1[48] + 68);
    v15 = SepCompareSidValuesBlocks(v13, v14);
    v16 = v14;
    if ( v15 )
    {
      SepLogTokenSidManagement(2, v13, v14, a1);
      v37 = (unsigned int *)(*(_DWORD *)(a1[48] + 68) + 4);
      do
      {
        v38 = __ldrex(v37);
        v39 = v38 + 1;
      }
      while ( __strex(v39, v37) );
      if ( v39 <= 1 )
        __fastfail(0xEu);
      a1[163] = *(_DWORD *)(a1[48] + 68);
      SepDereferenceSidValuesBlock(v13, a1, 0);
      goto LABEL_11;
    }
    v17 = 1;
LABEL_10:
    SepLogTokenSidManagement(v17, v13, v16, a1);
    a1[163] = v13;
LABEL_11:
    a1[37] = a1 + 164;
    v18 = 0;
    v19 = v42 == -1;
    a1[31] = v42 + 1;
    v20 = a1[163] + 12;
    if ( !v19 )
    {
      v21 = v43;
      do
      {
        if ( v18 == a1[46] )
        {
          *(_DWORD *)(a1[37] + 8 * v18) = a1[162];
        }
        else
        {
          *(_DWORD *)(a1[37] + 8 * v18) = v20;
          v20 += (4 * *(unsigned __int8 *)(v20 + 1) + 11) & 0xFFFFFFFC;
        }
        if ( v18 )
        {
          v22 = a1[37] + 8 * v18;
          v23 = *(_DWORD *)(a4 + 8 * v18 - 4);
        }
        else
        {
          v22 = a1[37];
          v23 = *(_DWORD *)(v21 + 4);
        }
        *(_DWORD *)(v22 + 4) = v23;
        ++v18;
      }
      while ( v18 < a1[31] );
    }
    return v12;
  }
  return sub_7DBD2C(v27);
}
