// MiCopyToCfgBitMap 
 
int __fastcall MiCopyToCfgBitMap(int a1, _DWORD *a2, _DWORD *a3, int a4, unsigned int *a5, unsigned int a6, int a7)
{
  int v7; // r10
  unsigned int v8; // r1
  unsigned int v9; // lr
  int *v10; // r5
  int v11; // r3
  int v12; // r8
  unsigned int v13; // r9
  int v14; // r4
  unsigned int v15; // r0
  unsigned int v16; // r6
  unsigned int v17; // r1
  unsigned int v18; // r2
  unsigned int v19; // r2
  int v20; // r10
  unsigned int *v21; // r9
  _DWORD *v22; // r2
  unsigned int v23; // r1
  unsigned int v24; // r0
  unsigned int v25; // r4
  int v26; // r0
  int *v27; // r2
  unsigned int v28; // r0
  unsigned int v29; // r5
  unsigned __int8 *v30; // r9
  unsigned int v31; // r2
  int v32; // r1
  unsigned int v33; // r6
  int v34; // r3
  int v36; // [sp-100h] [bp-188h] BYREF
  unsigned int v37; // [sp+0h] [bp-88h]
  unsigned int v38; // [sp+4h] [bp-84h]
  unsigned int v39; // [sp+8h] [bp-80h]
  int *v40; // [sp+Ch] [bp-7Ch]
  int *v41; // [sp+10h] [bp-78h]
  unsigned int v42; // [sp+14h] [bp-74h]
  unsigned int *v43; // [sp+18h] [bp-70h]
  unsigned int v44; // [sp+1Ch] [bp-6Ch]
  unsigned int v45; // [sp+20h] [bp-68h]
  int v46; // [sp+24h] [bp-64h]
  unsigned __int8 *v47; // [sp+28h] [bp-60h]
  int v48; // [sp+2Ch] [bp-5Ch]
  int v49; // [sp+30h] [bp-58h]
  unsigned int v50; // [sp+34h] [bp-54h]
  unsigned int v51; // [sp+38h] [bp-50h] BYREF
  int *v52; // [sp+3Ch] [bp-4Ch]
  int v53; // [sp+40h] [bp-48h]
  unsigned int v54; // [sp+44h] [bp-44h]
  unsigned int v55; // [sp+48h] [bp-40h]
  int v56; // [sp+4Ch] [bp-3Ch]
  unsigned int v57; // [sp+50h] [bp-38h]
  _DWORD *v58; // [sp+54h] [bp-34h]
  unsigned int v59; // [sp+58h] [bp-30h]
  _DWORD *v60; // [sp+5Ch] [bp-2Ch]
  _DWORD *v61; // [sp+60h] [bp-28h]
  int varg_r0; // [sp+90h] [bp+8h]
  _DWORD *varg_r1; // [sp+94h] [bp+Ch]
  _DWORD *varg_r2; // [sp+98h] [bp+10h]
  unsigned int varg_r3; // [sp+9Ch] [bp+14h]

  v42 = a4;
  varg_r3 = a4;
  v50 = (unsigned int)a3;
  varg_r2 = a3;
  v58 = a2;
  varg_r1 = a2;
  v7 = a1;
  v46 = a1;
  varg_r0 = a1;
  v47 = (unsigned __int8 *)a3;
  v60 = a3;
  v43 = a3;
  v61 = a3;
  v8 = 0;
  v39 = 0;
  v57 = 0;
  v37 = a4;
  v45 = a4;
  v48 = 0;
  v56 = 0;
  v9 = 4096;
  v44 = 4096;
  v53 = 4096;
  if ( (unsigned int)a3 <= 1 )
  {
    if ( a3 )
      v11 = 1953;
    else
      v11 = 1954;
    v10 = (int *)MiState[v11];
    goto LABEL_9;
  }
  v10 = (int *)ExAllocatePoolWithTag(512, 4096, 1700030797);
  v40 = v10;
  v41 = v10;
  if ( !v10 )
  {
    v9 = 256;
    v44 = 256;
    v53 = 256;
    v10 = &v36;
    v8 = 0;
LABEL_9:
    v40 = v10;
    v41 = v10;
    goto LABEL_10;
  }
  v48 = 1;
  v56 = 1;
  v8 = 0;
  v9 = 4096;
LABEL_10:
  v12 = v7;
  v49 = v7;
  v13 = a6;
  v54 = (a6 >> 12) + (((a6 & 0xFFF) + (v7 & 0xFFF) + 4095) >> 12);
  v59 = v54;
  v14 = 0;
  while ( 1 )
  {
    v38 = v13;
    if ( !v13 )
      break;
    v15 = v9 - 1;
    v16 = v9 - ((v9 - 1) & v12);
    if ( v16 >= v13 )
      v16 = v13;
    if ( v50 > 1 )
    {
      if ( a7 == 1 )
      {
        if ( v8 < *v43 )
        {
          v17 = *(_DWORD *)(v43[1] + 8 * v8) - v37;
          v18 = (2 * ((v17 >> 4) & (~v15 >> 4))) >> 3;
          if ( v18 >= v9 )
          {
            v37 += ~v15 & v17;
            v45 = v37;
            v12 += v18;
            v49 = v12;
            v13 -= v18;
            v38 = v13;
          }
        }
        v16 = v9 - (v15 & v12);
        if ( v16 >= v13 )
        {
          v16 = v13;
          v55 = v13;
        }
        else
        {
          v55 = v9 - (v15 & v12);
        }
        memmove((int)v10, v12, v16);
        v19 = v39;
        v52 = v10;
        v51 = 8 * v16;
        v20 = v37;
        v21 = v43;
        while ( v19 < *v21 )
        {
          v22 = (_DWORD *)(v21[1] + 8 * v19);
          v23 = *v22 - v20;
          if ( v23 >= v16 >> 1 << 7 )
            break;
          if ( (v22[1] & 1) != 0 )
          {
            v24 = 2 * (v23 >> 4);
            *((_BYTE *)v10 + ((v24 + 1) >> 3)) &= ~(unsigned __int8)(1 << ((v24 + 1) & 7));
            *((_BYTE *)v10 + (v24 >> 3)) |= 1 << (v24 & 7);
          }
          else
          {
            RtlClearBits(&v51, 2 * (v23 >> 4), 2u);
          }
          v19 = v39 + 1;
          v39 = v19;
          v57 = v19;
        }
        v37 = v20 + (v16 >> 1 << 7);
        v45 = v37;
LABEL_42:
        v7 = v46;
        v13 = v38;
        goto LABEL_43;
      }
      if ( !a7 )
      {
        v52 = v10;
        v51 = 8 * v16;
        RtlClearAllBits((int)&v51);
        v25 = v42 + (v16 >> 1 << 7);
        if ( !*a5 )
        {
          v26 = MiCompressedRvaListFirst(v47, a5 + 1);
          *v27 = v26;
        }
        v28 = *a5;
        v29 = v42;
        v30 = v47;
        while ( v28 )
        {
          if ( v28 >= v29 )
          {
            if ( v28 >= v25 )
              break;
            v31 = 1;
            if ( (v28 & 0xF) > 1 )
              v31 = 2;
            RtlSetBits(&v51, 2 * ((v28 - v29) >> 4), v31);
          }
          v28 = MiCompressedRvaListNext(v30, (int *)a5 + 1);
        }
        v42 = v25;
        varg_r3 = v25;
        *a5 = v28;
        v10 = v40;
        goto LABEL_42;
      }
    }
LABEL_43:
    v14 = MiSplitPrivatePage(v12, v58);
    if ( v14 < 0 )
      break;
    v14 = MiCopyToUserVa(v12, v32, (int)v10, v16);
    if ( v14 < 0 )
      break;
    v8 = v39;
    if ( v39 )
      *(_DWORD *)v43[2] = v39;
    v12 += v16;
    v49 = v12;
    v13 -= v16;
    v9 = v44;
  }
  if ( v48 )
    ExFreePoolWithTag((unsigned int)v10);
  if ( v50 )
  {
    if ( v14 >= 0 )
    {
      v33 = v54;
LABEL_56:
      v34 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
      MiCfgEliminateZeroPages(v34 + 492, v7 & 0xFFFFF000, v33 << 12, v34);
    }
    else if ( v12 != v7 && v14 != -1073741818 )
    {
      v33 = (v12 - (v7 & 0xFFFFF000)) >> 12;
      goto LABEL_56;
    }
  }
  return v14;
}
