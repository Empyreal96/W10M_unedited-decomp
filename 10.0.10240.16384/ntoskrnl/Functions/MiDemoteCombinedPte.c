// MiDemoteCombinedPte 
 
int __fastcall MiDemoteCombinedPte(unsigned int a1, int a2)
{
  unsigned int v5; // r9
  int v6; // r5
  int v7; // r0
  _DWORD *v8; // r7
  int *v9; // r6
  int v10; // r0
  int v11; // r1
  int v12; // r8
  unsigned __int8 *v13; // r1
  unsigned int v14; // r2
  int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  unsigned int v18; // r0
  int v19; // r3
  unsigned int v20; // r1
  unsigned int *v21; // r2
  unsigned int v22; // r0
  int v23; // r8
  unsigned int *v24; // r2
  unsigned int v25; // r0
  unsigned int v26; // lr
  int v27; // r3
  int v28; // r8
  int v29; // r3
  unsigned int *v30; // r2
  unsigned int v31; // r0
  int v32; // r0
  unsigned int v33; // [sp+8h] [bp-60h]
  BOOL v34; // [sp+Ch] [bp-5Ch]
  int v35; // [sp+10h] [bp-58h]
  int v36; // [sp+14h] [bp-54h]
  int v37; // [sp+18h] [bp-50h]
  int v38; // [sp+1Ch] [bp-4Ch]
  int v39; // [sp+20h] [bp-48h]
  int v40; // [sp+24h] [bp-44h]
  _DWORD v41[4]; // [sp+28h] [bp-40h] BYREF
  int v42[12]; // [sp+38h] [bp-30h] BYREF

  v37 = *(_DWORD *)a1;
  if ( *(_DWORD *)(a2 - 8) > 1u )
    return 0;
  v5 = a1 << 10;
  v6 = MmPfnDatabase + 24 * (*(_DWORD *)a1 >> 12);
  v7 = *(_DWORD *)v6;
  if ( a1 << 10 >= dword_63389C )
  {
    if ( *((_BYTE *)&MiState[2423] + ((int)(((v5 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2)) != 6 )
      return sub_51A39C(v7);
    v8 = 0;
    v9 = &dword_634E80;
  }
  else
  {
    v8 = *(_DWORD **)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    if ( v8[66] )
      return 0;
    v9 = v8 + 123;
  }
  v10 = MiLocateWsle(a1 << 10, v9, v7);
  v11 = v9[23];
  v33 = v10;
  v39 = v11;
  v36 = *(_DWORD *)(v11 + 36) * v10;
  v38 = *(_DWORD *)(v11 + 252);
  v40 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000) >> 12;
  v34 = (dword_682604 & 0x8000001) != 0;
  v12 = KfRaiseIrql(2);
  v13 = (unsigned __int8 *)(v6 + 15);
  do
    v14 = __ldrex(v13);
  while ( __strex(v14 | 0x80, v13) );
  while ( 1 )
  {
    __dmb(0xBu);
    if ( !(v14 >> 7) )
      break;
    do
    {
      __dmb(0xAu);
      __yield();
      v29 = *(_DWORD *)(v6 + 12);
      __dmb(0xBu);
    }
    while ( v29 < 0 );
    do
      v14 = __ldrex(v13);
    while ( __strex(v14 | 0x80, v13) );
  }
  v15 = *(unsigned __int16 *)(v6 + 16);
  if ( v15 != 1 && (v15 != 2 || (*(_BYTE *)(v6 + 18) & 8) == 0) )
    goto LABEL_48;
  v16 = (unsigned int *)(a2 - 8);
  do
    v17 = __ldrex(v16);
  while ( v17 == 1 && __strex(0, v16) );
  if ( v17 != 1 )
  {
LABEL_48:
    __dmb(0xBu);
    v30 = (unsigned int *)(v6 + 12);
    do
      v31 = __ldrex(v30);
    while ( __strex(v31 & 0x7FFFFFFF, v30) );
    KfLowerIrql(v12);
    return 0;
  }
  do
    v18 = __ldrex((unsigned int *)&dword_6404B0);
  while ( __strex(v18 - 1, (unsigned int *)&dword_6404B0) );
  v19 = *(_DWORD *)(v6 + 20);
  v20 = *(_DWORD *)(v6 + 8);
  *(_DWORD *)(v6 + 4) = a1;
  v19 &= 0xF7FFFFFF;
  v35 = v19 & 0xFFFFF;
  *(_DWORD *)(v6 + 20) = v19 & 0xFFF00000 | v40 & 0xFFFFF;
  if ( ((v20 >> 5) & 5) == 5 )
    *(_DWORD *)(v6 + 8) = v20 & 0xFFFFFC1F | (32 * ((v20 >> 5) & 0x1E));
  if ( v34 )
  {
    v41[0] = 0;
    v41[1] = 0;
    v41[2] = 0;
    v41[3] = 0;
    MiIdentifyPfn(v6, v41);
  }
  __dmb(0xBu);
  v21 = (unsigned int *)(v6 + 12);
  do
    v22 = __ldrex(v21);
  while ( __strex(v22 & 0x7FFFFFFF, v21) );
  KfLowerIrql(v12);
  if ( (v37 & 0x100) != 0 )
  {
    v26 = v37 & 0xFFFFFEFF | 0x90;
    if ( a1 + 0x40000000 > 0x3FFFFF )
    {
      *(_DWORD *)a1 = v26;
    }
    else
    {
      v27 = *(_DWORD *)a1;
      v28 = 0;
      __dmb(0xBu);
      *(_DWORD *)a1 = v26;
      if ( (v27 & 2) == 0 && (((unsigned __int8)v37 | 0x90) & 2) != 0 )
        v28 = 1;
      if ( a1 >= 0xC0300000 && a1 <= 0xC0300FFF )
      {
        v32 = *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 32);
        MiArmWriteConvertedHardwarePde(v32, v32 + 4 * (a1 & 0xFFF), v26);
      }
      if ( v28 == 1 )
      {
        __dsb(0xFu);
        __isb(0xFu);
      }
    }
  }
  v23 = MmPfnDatabase;
  if ( v33 < *(_DWORD *)(v39 + 4) )
    MiUnlockPageTableCharges(MmPfnDatabase + 24 * v35, 2, 0);
  MiLockAndDecrementShareCount(v23 + 24 * v35, 0);
  if ( (*(_DWORD *)(v36 + v38) & 4) != 0 )
    MiUpdateWsleHash(v5, v33, v9, 1);
  *(_DWORD *)v6 = v33;
  *(_DWORD *)(v36 + v38) |= 8u;
  ++v9[16];
  if ( v5 < 0xC0000000 || v5 > 0xC03FFFFF )
    ++v9[14];
  if ( v8 )
  {
    v24 = v8 + 69;
    do
      v25 = __ldrex(v24);
    while ( __strex(v25 + 1, v24) );
  }
  if ( v34 )
  {
    MiLogCombinedPteDelete(a2);
    v42[0] = (int)v41;
    v42[1] = 0;
    v42[2] = 16;
    v42[3] = 0;
    EtwTraceKernelEvent(v42, 1, 671088641, 630, 289413890);
  }
  MiFreeCombineBlock(a2 - 32);
  return 1;
}
