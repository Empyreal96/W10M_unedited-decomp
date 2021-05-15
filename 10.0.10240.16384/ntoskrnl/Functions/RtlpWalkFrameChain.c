// RtlpWalkFrameChain 
 
unsigned int __fastcall RtlpWalkFrameChain(int a1, unsigned int a2, int a3, unsigned int a4)
{
  int v5; // r5
  unsigned int v6; // r8
  char v7; // r4
  int v8; // r2
  int i; // r1
  int v10; // r1
  unsigned int v11; // r3
  unsigned int v12; // r1
  int *v13; // r2
  char v14; // r2
  int v15; // r3
  unsigned int v16; // lr
  int v17; // r10
  unsigned int v18; // r6
  int v19; // r2
  bool v20; // cf
  int v21; // r10
  int *v22; // r2
  int v23; // r3
  unsigned int v24; // r4
  int v25; // r1
  int v26; // [sp+0h] [bp-B0h]
  unsigned int v27; // [sp+4h] [bp-ACh]
  char v28; // [sp+Ch] [bp-A4h]
  unsigned int v29; // [sp+10h] [bp-A0h] BYREF
  unsigned int v30; // [sp+14h] [bp-9Ch]
  unsigned int v31; // [sp+18h] [bp-98h] BYREF
  _DWORD *v32; // [sp+1Ch] [bp-94h]
  unsigned int v33; // [sp+20h] [bp-90h]
  int v34; // [sp+24h] [bp-8Ch]
  int *v35; // [sp+28h] [bp-88h]
  unsigned int v36; // [sp+2Ch] [bp-84h]
  unsigned int v37; // [sp+30h] [bp-80h]
  char v38; // [sp+34h] [bp-7Ch]
  unsigned int v39; // [sp+38h] [bp-78h]
  unsigned int v40; // [sp+3Ch] [bp-74h]
  unsigned int v41; // [sp+40h] [bp-70h]
  int v42; // [sp+44h] [bp-6Ch]
  int *v43; // [sp+48h] [bp-68h]
  unsigned int v44; // [sp+4Ch] [bp-64h]
  _DWORD *v45; // [sp+50h] [bp-60h]
  BOOL v46; // [sp+54h] [bp-5Ch]
  _DWORD *v47; // [sp+58h] [bp-58h]
  unsigned int v48; // [sp+5Ch] [bp-54h]
  int v49; // [sp+60h] [bp-50h]
  unsigned int v50; // [sp+64h] [bp-4Ch]
  int v51; // [sp+68h] [bp-48h]
  unsigned int v52; // [sp+6Ch] [bp-44h]
  unsigned int v53; // [sp+70h] [bp-40h]
  _DWORD _78[20]; // [sp+78h] [bp-38h] BYREF

  _78[16] = a1;
  _78[17] = a2;
  _78[19] = a4;
  v53 = a4;
  v28 = a3;
  _78[18] = a3;
  v52 = a2;
  v51 = a1;
  v35 = 0;
  v33 = 0;
  v32 = 0;
  v26 = 1;
  v46 = (a3 & 2) != 0;
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v50 = v27;
  v30 = 0;
  v37 = 0;
  v36 = 0;
  v34 = 0;
  if ( !RtlpGetStackLimits(&v29, &v31) )
    return 0;
  v5 = RtlpGetFrameChain();
  v6 = 0;
  v7 = v28;
  if ( (v28 & 1) != 0 )
  {
    if ( (*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x4C) & 0x400) != 0
      || *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16A) == 1 )
    {
      v8 = 0;
    }
    else
    {
      v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x9C);
    }
    for ( i = *(_DWORD *)(v27 + 32); (*(_DWORD *)(i + 4) & 1) != 0; i = *(_DWORD *)(i + 20) )
      ;
    v10 = i - 408;
    v30 = v10;
    v44 = v10;
    if ( !v8 || (*(_WORD *)(v8 + 4042) & 0x100) != 0 )
      return 0;
    v11 = *(_DWORD *)(v10 + 116);
    v36 = v11;
    v12 = *(_DWORD *)(v8 + 4);
    v37 = v12;
    if ( v12 <= v11 )
      return 0;
    if ( v12 != v11 && v12 > MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    v13 = *(int **)(v27 + 32);
    v35 = v13;
    v43 = v13;
    while ( (v13[1] & 1) != 0 )
    {
      v13 = (int *)v13[5];
      v35 = v13;
      v43 = v13;
    }
    v32 = (_DWORD *)v13[4];
    v47 = v32;
    v14 = *(_BYTE *)(v27 + 76);
    *(_BYTE *)(v27 + 76) = v14 | 0x20;
    v26 = (unsigned __int8)(v14 & 0x20) >> 5;
  }
  _78[0] = 0;
  _78[1] = 0;
  _78[2] = 0;
  _78[3] = 0;
  while ( 1 )
  {
    if ( !RtlpIsFrameInBoundsEx(&v29, v5, &v31, _78) )
    {
      v15 = v26;
      v16 = v27;
      goto LABEL_86;
    }
    v17 = v5 + 8;
    v45 = (_DWORD *)(v5 + 8);
    v40 = *(_DWORD *)(v5 + 4);
    v18 = v40;
    v5 = *(_DWORD *)v5;
    v49 = v5;
    if ( (v40 & 1) == 0 || (v5 & 3) != 0 )
    {
      v15 = v26;
      v16 = v27;
      goto LABEL_86;
    }
    if ( !v40 )
      break;
    if ( v34 )
    {
      if ( v34 == 1 )
      {
        if ( v40 > MmHighestUserAddress )
        {
          v15 = v26;
          v16 = v27;
          goto LABEL_86;
        }
        if ( v32 && v40 == *(_DWORD *)(v30 + 128) )
        {
          v34 = 2;
          v42 = 2;
          v33 = 0;
          v41 = 0;
          v18 = v32[13];
          v40 = v18;
          v21 = (int)(v32 + 14);
          v45 = v32 + 14;
          v5 = v32[12];
          v49 = v5;
          v32 = (_DWORD *)v35[4];
          v47 = v32;
          v22 = (int *)v35[5];
          v35 = v22;
          if ( !v22 )
          {
            v15 = v26;
            v16 = v27;
            goto LABEL_86;
          }
          v43 = v22;
          v29 = v21;
          v31 = *v22;
        }
      }
      else
      {
        if ( v34 != 2 )
        {
          v15 = v26;
          v16 = v27;
          goto LABEL_86;
        }
        if ( v40 < MmSystemRangeStart && v40 <= MmHighestUserAddress )
        {
          if ( v40 != *(_DWORD *)(v30 + 128) )
          {
            v15 = v26;
            v16 = v27;
            goto LABEL_86;
          }
          v19 = *(_DWORD *)(v30 + 116);
          if ( (v19 & 3) != 0 )
            ExRaiseDatatypeMisalignment(&MmHighestUserAddress);
          v34 = 1;
          v42 = 1;
          v45 = *(_DWORD **)(v19 + 16);
          v29 = v36;
          v31 = v37;
          if ( v32 )
          {
            v30 = v32[1];
            v44 = v30;
          }
        }
        v20 = v33++ >= 0x3C00;
        v41 = v33;
        if ( v20 )
        {
          v15 = v26;
          v16 = v27;
          goto LABEL_86;
        }
      }
      goto LABEL_80;
    }
    v23 = v7 & 1;
    if ( (v7 & 1) == 0 && v40 < MmSystemRangeStart )
    {
      v15 = v26;
      v16 = v27;
      goto LABEL_86;
    }
    v24 = 0;
    v39 = 0;
    if ( !v23 )
      goto LABEL_69;
    if ( v40 < MmSystemRangeStart )
    {
      if ( v40 > MmHighestUserAddress )
      {
        v7 = v28;
        v15 = v26;
        v16 = v27;
        goto LABEL_86;
      }
      if ( v40 != *(_DWORD *)(v30 + 128) )
      {
        v7 = v28;
        v15 = v26;
        v16 = v27;
        goto LABEL_86;
      }
      v34 = 1;
      v42 = 1;
      v24 = v30;
      v39 = v30;
      if ( v32 )
      {
        v30 = v32[1];
        v44 = v30;
        if ( v30 < MmSystemRangeStart )
        {
          v7 = v28;
          v15 = v26;
          v16 = v27;
          goto LABEL_86;
        }
      }
      v29 = v36;
      v31 = v37;
LABEL_69:
      if ( v24 )
        goto LABEL_76;
      if ( (unsigned int)(v5 - v17) >= 0x7C
        && RtlpIsFrameInBounds(&v29, v5, &v31)
        && RtlpIsFrameInBounds(&v29, v5 - 124, &v31)
        && (v24 = v25, v39 = v25, *(_DWORD *)(v25 + 12) != ((unsigned int)KiResetException & 0xFFFFFFFE)) )
      {
        v39 = 0;
      }
      else if ( v24 )
      {
LABEL_76:
        v46 = 0;
        v38 = 0;
        goto LABEL_79;
      }
      if ( v46 )
        goto LABEL_78;
LABEL_79:
      v7 = v28;
LABEL_80:
      if ( v6 >= v53 )
        *(_DWORD *)(v51 + 4 * (v6 - v53)) = v18;
      v48 = ++v6;
      if ( v6 >= v52 )
      {
        v15 = v26;
        v16 = v27;
        goto LABEL_86;
      }
    }
    else
    {
      if ( !v6 )
        goto LABEL_79;
      v20 = v33++ >= 0x3C00;
      v41 = v33;
      if ( v20 )
      {
        v7 = v28;
        v15 = v26;
        v16 = v27;
        goto LABEL_86;
      }
LABEL_78:
      v7 = v28;
    }
  }
  v15 = v26;
  v16 = v27;
LABEL_86:
  if ( (v7 & 1) != 0 && !v15 )
    *(_BYTE *)(v16 + 76) &= 0xDFu;
  return v6;
}
