// PspSetNetRateControl 
 
int __fastcall PspSetNetRateControl(int a1, int a2, unsigned int a3, _DWORD *a4)
{
  int v5; // r4
  int v6; // r2
  int v7; // r3
  unsigned int v8; // r8
  int v9; // r3
  int v10; // r3
  int v11; // r2
  int v12; // r3
  int v13; // r2
  int *v14; // r1
  int v15; // r3
  _DWORD *v16; // t1
  int v17; // r3
  int v18; // r3
  int v19; // r0
  int v20; // r2
  int v21; // r2
  int v22; // r2
  int *v23; // r1
  _DWORD *v24; // t1
  int v25; // r0
  __int16 v26; // r3
  int v28; // [sp+14h] [bp-8Ch]
  int v29; // [sp+18h] [bp-88h] BYREF
  _DWORD *v30; // [sp+1Ch] [bp-84h]
  int v31; // [sp+20h] [bp-80h]
  int v32; // [sp+24h] [bp-7Ch]
  int v33; // [sp+28h] [bp-78h]
  _DWORD v34[8]; // [sp+30h] [bp-70h] BYREF
  int v35; // [sp+50h] [bp-50h]
  _DWORD v36[2]; // [sp+58h] [bp-48h] BYREF
  int v37; // [sp+60h] [bp-40h]
  unsigned __int8 v38; // [sp+64h] [bp-3Ch]
  _DWORD v39[14]; // [sp+68h] [bp-38h] BYREF

  v33 = a1;
  v29 = a1;
  v30 = a4;
  v31 = 0;
  memmove((int)v36, a2, a3);
  if ( (v37 & 0xFFFFFFF8) != 0 )
    return -1073741811;
  v30 = (_DWORD *)(v37 & 1);
  if ( (v37 & 1) != 0 && ((v37 & 4) != 0 && v38 > 0x40u || (v37 & 6) == 0) )
    return -1073741811;
  memset(v34, 0, sizeof(v34));
  v34[4] = a4 + 176;
  v34[1] = 0;
  v35 = v37 & 2;
  if ( (v37 & 2) != 0 )
  {
    v6 = v34[5] | 0x10;
    v34[5] |= 0x10u;
    v34[2] = v36[0];
    v34[3] = v36[1];
  }
  else
  {
    v6 = v34[5];
  }
  v32 = v37 & 4;
  if ( (v37 & 4) != 0 )
  {
    v34[5] = v6 | 8;
    LOBYTE(v34[6]) = v38;
  }
  v7 = __mrc(15, 0, 13, 0, 3);
  v8 = v7 & 0xFFFFFFC0;
  if ( (v7 & 0xFFFFFFC0) != 0 )
    --*(_WORD *)((v7 & 0xFFFFFFC0) + 0x136);
  while ( 1 )
  {
    v10 = a4[144];
    __dmb(0xBu);
    v28 = v10;
    __dmb(0xBu);
    ExAcquireResourceExclusiveLite(v10 + 32, 1, v6, v10);
    v11 = v28;
    __dmb(0xBu);
    v12 = a4[144];
    __dmb(0xBu);
    if ( v11 == v12 )
      break;
    v9 = v28;
    __dmb(0xBu);
    ExReleaseResourceLite(v9 + 32);
  }
  v29 = v28;
  __dmb(0xBu);
  v13 = 0;
  v14 = &v29;
  while ( 1 )
  {
    v16 = (_DWORD *)*v14++;
    v15 = (int)v16;
    if ( a4 == v16 )
      break;
    if ( ++v13 )
    {
      ExAcquireResourceExclusiveLite((int)(a4 + 8), 1, v13, v15);
      break;
    }
  }
  v17 = a4[186];
  if ( (v17 & 0x4000000) != 0 )
    v34[0] = *(_DWORD *)(a4[184] + 36);
  if ( v30 )
  {
    if ( (v17 & 0x2000000) == 0 )
    {
      v18 = v34[5] | 1;
      v34[5] |= 1u;
      goto LABEL_32;
    }
    if ( (v17 & 0x4000000) != 0 )
    {
      v18 = v34[5] | 2;
      goto LABEL_25;
    }
  }
  else if ( (v17 & 0x4000000) != 0 )
  {
    v18 = v34[5] | 4;
LABEL_25:
    v34[5] = v18;
    goto LABEL_32;
  }
  v18 = v34[5];
LABEL_32:
  if ( (v18 & 1) != 0 )
  {
    v5 = PspSetJobRateControl((int)a4, 0, v37, v18, 0, 0);
    if ( v5 < 0 )
      goto LABEL_49;
    v31 = 1;
    v19 = PspNetRateControlDispatch((int)v34);
  }
  else
  {
    if ( (v18 & 7) != 0 )
    {
      v5 = PspNetRateControlDispatch((int)v34);
      if ( v5 < 0 )
        goto LABEL_48;
    }
    v19 = PspSetJobRateControl((int)a4, 0, v37, v18, 0, 0);
  }
  v5 = v19;
  if ( v19 >= 0 )
  {
    if ( v30 )
    {
      if ( v35 )
      {
        *(_DWORD *)(a4[184] + 32) |= 1u;
        v20 = a4[184];
        *(_DWORD *)(v20 + 24) = v34[2];
        *(_DWORD *)(v20 + 28) = v34[3];
      }
      if ( v32 )
      {
        *(_DWORD *)(a4[184] + 32) |= 2u;
        *(_BYTE *)(a4[184] + 40) = v34[6];
      }
      *(_DWORD *)(a4[184] + 36) = v34[0];
      v21 = a4[184];
      v39[0] = *(_DWORD *)(v21 + 32);
      v39[2] = *(_DWORD *)(v21 + 24);
      v39[3] = *(_DWORD *)(v21 + 28);
      LOBYTE(v39[4]) = *(_BYTE *)(v21 + 40);
    }
    else
    {
      memset(v39, 0, 24);
    }
    if ( (PerfGlobalGroupMask[0] & 0x80000) != 0 )
      EtwTraceJobSetQuery(a4, v33, 32, v39, 0, v5, 1829);
LABEL_48:
    if ( v5 >= 0 )
      goto LABEL_51;
  }
LABEL_49:
  if ( v31 )
    PspSetJobRateControl((int)a4, 0, 0, v31, 0, 0);
LABEL_51:
  v22 = 0;
  v23 = &v29;
  while ( 1 )
  {
    v24 = (_DWORD *)*v23++;
    if ( a4 == v24 )
      break;
    if ( ++v22 )
    {
      ExReleaseResourceLite((int)(a4 + 8));
      break;
    }
  }
  v25 = ExReleaseResourceLite(v28 + 32);
  if ( v8 )
  {
    v26 = *(_WORD *)(v8 + 310) + 1;
    *(_WORD *)(v8 + 310) = v26;
    if ( !v26 && *(_DWORD *)(v8 + 100) != v8 + 100 )
      KiCheckForKernelApcDelivery(v25);
  }
  return v5;
}
