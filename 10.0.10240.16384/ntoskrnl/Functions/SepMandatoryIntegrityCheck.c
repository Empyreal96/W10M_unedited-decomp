// SepMandatoryIntegrityCheck 
 
int __fastcall SepMandatoryIntegrityCheck(_DWORD *a1, int a2, int a3, _DWORD *a4, char a5, int a6)
{
  int v7; // r5
  int v8; // r10
  int v9; // r3
  int v10; // r3
  unsigned int v11; // r0
  int v12; // r2
  unsigned __int16 *v13; // r5
  int v14; // r2
  int *v15; // r3
  unsigned __int16 *v16; // r6
  int v17; // r3
  int v18; // r7
  int v19; // r9
  int result; // r0
  unsigned int v21; // r2
  int v22; // r0
  int v23; // r2
  int v24; // r7
  char v25; // r5
  int v26; // r0
  int v27; // r0
  unsigned int v28; // r1
  int v29; // r3
  unsigned int v30; // r2
  int v31; // r2
  int v32; // r3
  int v33; // r3
  int v34; // r0
  int v36; // [sp+4h] [bp-3Ch]
  int v37; // [sp+4h] [bp-3Ch]
  int v38; // [sp+8h] [bp-38h]
  int v39; // [sp+Ch] [bp-34h]
  int v40; // [sp+10h] [bp-30h]
  char v41[40]; // [sp+18h] [bp-28h] BYREF

  v7 = a4[47];
  *(_DWORD *)(a6 + 8) = v7;
  v8 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  if ( !v7 || v7 == 2 )
  {
    v33 = a1[3];
    *(_BYTE *)(a6 + 4) = 1;
    *(_DWORD *)a6 = v33;
    *(_BYTE *)(a6 + 5) = 1;
    *(_BYTE *)(a6 + 6) = 1;
    return 0;
  }
  if ( a3 || (*(_WORD *)(a2 + 2) & 0x10) == 0 )
    goto LABEL_15;
  if ( (*(_WORD *)(a2 + 2) & 0x8000) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 12);
    if ( !v9 )
    {
LABEL_15:
      LOBYTE(v40) = 1;
      v13 = (unsigned __int16 *)SepDefaultMandatorySid;
      goto LABEL_16;
    }
    v10 = v9 + a2;
  }
  else
  {
    v10 = *(_DWORD *)(a2 + 12);
  }
  if ( !v10 )
    goto LABEL_15;
  v11 = 0;
  v12 = v10 + 8;
  if ( !*(_WORD *)(v10 + 4) )
    goto LABEL_15;
  while ( *(_BYTE *)v12 != 17 )
  {
    ++v11;
    v12 += *(unsigned __int16 *)(v12 + 2);
    if ( v11 >= *(unsigned __int16 *)(v10 + 4) )
      goto LABEL_15;
  }
  if ( !v12 || (*(_BYTE *)(v12 + 1) & 8) != 0 )
    goto LABEL_15;
  v13 = (unsigned __int16 *)(v12 + 8);
  v40 = *(_DWORD *)(v12 + 4);
LABEL_16:
  if ( a5 )
  {
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v30 + 308);
    ExAcquireResourceSharedLite(a4[12], 1);
  }
  v14 = a4[46];
  if ( v14 == -1 || (v15 = (int *)(a4[37] + 8 * v14)) == 0 )
    v15 = &SeUntrustedMandatorySid;
  v16 = (unsigned __int16 *)*v15;
  if ( a5 )
  {
    v27 = ExpReleaseResourceForThreadLite(a4[12], __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
    *(_WORD *)(v28 + 308) = v29;
    if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
      KiCheckForKernelApcDelivery(v27);
  }
  if ( *((_BYTE *)v13 + 1) )
    v17 = *(_DWORD *)&v13[2 * *((unsigned __int8 *)v13 + 1) + 2];
  else
    v17 = 0;
  *(_DWORD *)(a6 + 12) = v17;
  v18 = *v13;
  v19 = *v16;
  if ( v18 == v19 && !memcmp((unsigned int)v13, (unsigned int)v16, 4 * (*((unsigned __int8 *)v13 + 1) + 2)) )
    goto LABEL_34;
  v41[2] = 0;
  v41[5] = 16;
  v41[1] = 0;
  v41[4] = 0;
  v41[0] = 0;
  v41[3] = 0;
  if ( memcmp((unsigned int)(v16 + 1), (unsigned int)v41, 6) || memcmp((unsigned int)(v13 + 1), (unsigned int)v41, 6) )
    return sub_52E0BC();
  if ( v19 == v18 && !memcmp((unsigned int)v16, (unsigned int)v13, 4 * (*((unsigned __int8 *)v16 + 1) + 2))
    || (!*((_BYTE *)v16 + 1) ? (v21 = 0) : (v21 = *(_DWORD *)&v16[2 * *((unsigned __int8 *)v16 + 1) + 2]),
        !*((_BYTE *)v13 + 1) || v21 >= *(_DWORD *)&v13[2 * *((unsigned __int8 *)v13 + 1) + 2]) )
  {
LABEL_34:
    v22 = 1;
  }
  else
  {
    v22 = 0;
  }
  if ( (*(_DWORD *)(a6 + 8) & 1) != 0 )
  {
    v36 = 1;
    v23 = 1;
    v38 = 1;
    v8 = a1[2] & ~*a1 | *a1 | 0x120000;
    if ( !v22 )
      goto LABEL_45;
    v8 |= a1[3] | 0x11FFFFF;
    v39 = 1;
  }
  if ( v22 )
  {
    LOBYTE(v24) = v36;
    goto LABEL_40;
  }
  v23 = v38;
LABEL_45:
  if ( (v40 & 2) != 0 )
  {
    v23 = 0;
    v38 = 0;
  }
  if ( (v40 & 4) != 0 )
    v24 = 0;
  else
    v24 = v36;
  if ( (v40 & 1) != 0 )
    v39 = 0;
  if ( (v40 & 2) != 0 )
  {
    v31 = 0;
    v37 = 0;
    if ( v39 )
    {
      v31 = a1[1] | 0x10D0000;
      v37 = v31;
    }
    if ( v24 )
    {
      v31 = a1[2] & ~*a1 | v37 | 0x100000;
      v37 = v31;
    }
    v32 = ~(~v37 & 0x20000) & ~(*a1 & ~v31);
    v23 = v38;
    v8 &= v32;
  }
  if ( (v40 & 4) != 0 )
  {
    v34 = 0;
    if ( v39 )
      v34 = a1[1] | 0x10D0000;
    if ( v23 )
      v34 |= *a1 | 0x20000;
    v8 &= ~(~v34 & 0x100000) & ~(a1[2] & ~*a1 & ~v34);
  }
  if ( (v40 & 1) != 0 )
  {
    v26 = 0;
    if ( v24 )
      v26 = a1[2] & ~*a1 | 0x100000;
    v25 = v38;
    if ( v38 )
      v26 |= *a1 | 0x20000;
    v8 &= ~(~v26 & 0x10D0000) & ~(a1[1] & ~v26);
    goto LABEL_41;
  }
LABEL_40:
  v25 = v38;
LABEL_41:
  if ( (a4[19] & 1) != 0 )
    v8 |= 0x80000u;
  result = 0;
  *(_DWORD *)a6 = v8;
  *(_BYTE *)(a6 + 5) = v25;
  *(_BYTE *)(a6 + 4) = v39;
  *(_BYTE *)(a6 + 6) = v24;
  return result;
}
