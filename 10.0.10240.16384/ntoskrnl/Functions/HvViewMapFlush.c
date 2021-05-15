// HvViewMapFlush 
 
int __fastcall HvViewMapFlush(_DWORD *a1, int a2, int a3, int a4)
{
  unsigned int v6; // r4
  unsigned int *v7; // r6
  int v8; // r0
  int v9; // r5
  unsigned int v10; // r4
  unsigned int v11; // r4
  unsigned int v12; // r6
  unsigned int v13; // r8
  unsigned int *v14; // r4
  unsigned int v15; // r2
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  int v19; // r5
  int v21; // [sp+8h] [bp-50h]
  int *v23; // [sp+14h] [bp-44h] BYREF
  unsigned int v24; // [sp+18h] [bp-40h]
  unsigned int v25; // [sp+1Ch] [bp-3Ch]
  int v26; // [sp+20h] [bp-38h]
  int v27; // [sp+28h] [bp-30h] BYREF
  unsigned int v28; // [sp+30h] [bp-28h] BYREF
  int v29; // [sp+34h] [bp-24h]
  _DWORD *varg_r0; // [sp+60h] [bp+8h]
  int varg_r1; // [sp+64h] [bp+Ch]
  int varg_r2; // [sp+68h] [bp+10h]
  int varg_r3; // [sp+6Ch] [bp+14h]

  varg_r3 = a4;
  v26 = a3;
  varg_r2 = a3;
  varg_r1 = a2;
  varg_r0 = a1;
  v6 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v6 + 308);
  v7 = a1 + 1;
  v8 = KeAbPreAcquire((unsigned int)(a1 + 1), 0, 0);
  v9 = v8;
  do
    v10 = __ldrex(v7);
  while ( !v10 && __strex(0x11u, v7) );
  __dmb(0xBu);
  if ( v10 )
    ExfAcquirePushLockSharedEx(v7, v8, (unsigned int)v7);
  if ( v9 )
    *(_BYTE *)(v9 + 14) |= 1u;
  LOBYTE(v21) = 1;
  v11 = a3;
  v25 = a3;
  v12 = a2;
  v24 = a2;
  while ( v11 )
  {
    v13 = *(_DWORD *)(*(_DWORD *)(a1[3] + 4 * (HIBYTE(v12) & 0x7F)) + 24 * ((v12 >> 18) & 0x3F) + 16) - (v12 & 0x3FFFF);
    if ( v13 > v11 )
      v13 = v11;
    v28 = v12;
    v29 = 0;
    CcPinRead(a1[2], &v28, v13, 1, &v23, &v27, v21);
    CcSetDirtyPinnedData(v23, 0);
    CcUnpinData(v23);
    v12 += v13;
    v24 = v12;
    v11 -= v13;
    v25 = v11;
  }
  v14 = a1 + 1;
  __dmb(0xBu);
  do
    v15 = __ldrex(v14);
  while ( v15 == 17 && __strex(0, v14) );
  if ( v15 != 17 )
    ExfReleasePushLockShared(a1 + 1);
  v16 = KeAbPostRelease((unsigned int)(a1 + 1));
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(_WORD *)(v17 + 0x134) + 1;
  *(_WORD *)(v17 + 308) = v18;
  if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
    KiCheckForKernelApcDelivery(v16);
  v28 = a2;
  v29 = 0;
  CcFlushCache(*(_DWORD *)(a1[2] + 20), (int)&v28 + 1, v26);
  v19 = v27;
  if ( v27 >= 0 )
    v19 = 0;
  return v19;
}
