// MiParseImageCfgBits 
 
int __fastcall MiParseImageCfgBits(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int *a6)
{
  int v7; // lr
  int v8; // r4
  unsigned int v9; // r9
  unsigned int v10; // r5
  unsigned int v11; // r10
  int v12; // r0
  unsigned int v13; // r2
  unsigned int v14; // r1
  int v15; // r6
  unsigned int *v16; // r1
  _DWORD *v17; // lr
  unsigned int v18; // r2
  unsigned int v19; // r3
  unsigned int v20; // r6
  unsigned int v21; // r9
  unsigned int v22; // r6
  int v23; // r0
  int v24; // r8
  int v25; // r3
  unsigned int v26; // r1
  unsigned int v27; // r3
  int v28; // r9
  unsigned int v29; // r2
  int v30; // r3
  int v31; // r6
  unsigned int v32; // r4
  _DWORD *v33; // r0
  int v36; // [sp+14h] [bp-E4h]
  unsigned int v37; // [sp+18h] [bp-E0h] BYREF
  unsigned int v38; // [sp+1Ch] [bp-DCh]
  unsigned int v39; // [sp+20h] [bp-D8h]
  int v40; // [sp+24h] [bp-D4h]
  unsigned int v41; // [sp+28h] [bp-D0h]
  unsigned int v42; // [sp+2Ch] [bp-CCh]
  unsigned int v43; // [sp+30h] [bp-C8h]
  unsigned int *v44; // [sp+34h] [bp-C4h]
  unsigned int v45; // [sp+38h] [bp-C0h]
  int v46; // [sp+3Ch] [bp-BCh]
  unsigned int v47; // [sp+40h] [bp-B8h]
  int v48; // [sp+44h] [bp-B4h]
  unsigned int *v49; // [sp+48h] [bp-B0h]
  unsigned int v50; // [sp+4Ch] [bp-ACh]
  int v51; // [sp+50h] [bp-A8h]
  unsigned int *v52; // [sp+54h] [bp-A4h]
  _DWORD *v53; // [sp+58h] [bp-A0h]
  int v54; // [sp+5Ch] [bp-9Ch]
  int v55; // [sp+60h] [bp-98h]
  unsigned int v56; // [sp+64h] [bp-94h]
  unsigned int v57; // [sp+68h] [bp-90h]
  int v58; // [sp+70h] [bp-88h] BYREF
  unsigned int v59; // [sp+C0h] [bp-38h]
  unsigned int v60; // [sp+C4h] [bp-34h]
  unsigned int v61; // [sp+C8h] [bp-30h]
  _DWORD *varg_r0; // [sp+100h] [bp+8h]
  int varg_r1; // [sp+104h] [bp+Ch]
  int varg_r2; // [sp+108h] [bp+10h]
  int varg_r3; // [sp+10Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r3 = a4;
  v39 = a3;
  varg_r2 = a3;
  v46 = a2;
  v7 = (int)a1;
  v53 = a1;
  v54 = a2;
  v50 = a4;
  v44 = a6;
  v52 = a6;
  if ( !dword_68124C )
  {
    *a6 = 0;
    return 0;
  }
  v41 = 0;
  v48 = 0;
  v42 = 0;
  v45 = 0;
  v9 = 0;
  v40 = 0;
  v43 = 0;
  v38 = 0;
  v55 = 0;
  v10 = 0;
  v36 = 0;
  v37 = 0;
  v11 = 0;
  v51 = 0;
  v12 = 0;
  if ( v7 )
    v12 = *(_DWORD *)(*(_DWORD *)v7 + 36);
  v47 = *(_DWORD *)a4;
  v56 = v47;
  v8 = 0;
  v13 = *(_DWORD *)(a4 + 88);
  v57 = v13;
  v14 = *(_DWORD *)(a4 + 84);
  if ( v14 )
  {
    v15 = 0;
    if ( *(_WORD *)(a4 + 36) == 267 )
    {
      if ( v14 + 92 <= v14 || v14 + 92 > *(_DWORD *)(a4 + 12) )
        goto LABEL_59;
      v16 = (unsigned int *)(v14 + v46);
      v49 = v16;
      if ( v13 >= 0x5C )
        goto LABEL_15;
      if ( !v12 || *(_WORD *)(v12 + 32) != 332 )
        goto LABEL_59;
      if ( v13 > 4 )
      {
        v13 = *v16;
        v57 = *v16;
      }
      v7 = (int)a1;
      if ( v13 >= 0x5C )
      {
LABEL_15:
        memmove((int)&v58, (int)v16, 0x5Cu);
        v17 = a1;
        if ( a1 )
        {
          v15 = MI_REFERENCE_CONTROL_AREA_FILE((int)a1);
          v41 = v15;
          v48 = v15;
          v17 = a1;
        }
        if ( v15 )
          MiLogRelocationRva(*(_DWORD *)(a4 + 84), 92, v15, v17);
        if ( *(_WORD *)(a4 + 36) == 267 )
        {
          v18 = v59;
          v42 = v59;
          v9 = v60;
          v40 = v60;
          v43 = v60;
          v19 = v61;
        }
        else
        {
          v18 = v42;
          v19 = v38;
        }
        if ( (v19 & 0x400) == 0 || !v18 )
          goto LABEL_58;
        v20 = (v19 >> 28) + 4;
        v38 = v20;
        v49 = (unsigned int *)v20;
        if ( v18 < v47 || !v9 )
          goto LABEL_57;
        if ( v19 >> 28 == -4 )
          __brkdiv0();
        if ( v9 >= 0xFFFFFFFF / v20 )
        {
LABEL_57:
          v8 = -1073741819;
          v25 = 4;
          goto LABEL_37;
        }
        v21 = v42 - v47;
        v45 = v21;
        v22 = v20 * v40;
        v50 = v22;
        if ( v22 + v21 <= v21 || v22 + v42 - v47 > *(_DWORD *)(a4 + 12) || v22 + 4 < v22 )
        {
          v8 = -1073741819;
          v25 = 5;
          goto LABEL_37;
        }
        v23 = ExAllocatePoolWithTag(1, v22, 1413704013);
        v24 = v23;
        v36 = v23;
        v37 = v23;
        if ( v23 )
        {
          memmove(v23, v46 + v21, v22);
          if ( v41 )
            MiLogRelocationRva(v21, v22, v41, a1);
          v26 = 0;
          v27 = 0;
          v28 = v38;
          if ( v22 )
          {
            while ( 1 )
            {
              v29 = *(_DWORD *)(v27 + v24);
              if ( v29 >= v39 )
                break;
              if ( v27 && v29 < v26 )
              {
                v30 = 9;
                goto LABEL_48;
              }
              v26 = *(_DWORD *)(v27 + v24);
              v27 += v38;
              if ( v27 >= v22 )
                goto LABEL_49;
            }
            v30 = 8;
LABEL_48:
            dword_632EF0 = v30;
            v8 = -1073741701;
          }
LABEL_49:
          if ( v8 < 0 )
            goto LABEL_58;
          v37 = 0;
          v31 = v40;
          v8 = MiCompressRvaList(v24, v40, v39, v38, 0, 0, &v37);
          if ( v8 < 0 )
            goto LABEL_58;
          v32 = v37 + 4;
          if ( v37 + 4 < v37 )
          {
            v8 = -1073741789;
            v25 = 10;
            goto LABEL_37;
          }
          v33 = (_DWORD *)ExAllocatePoolWithTag(1, v37 + 4, 1715693901);
          v11 = (unsigned int)v33;
          if ( v33 )
          {
            v37 = v32 - 4;
            *v33 = v32 - 4;
            v8 = MiCompressRvaList(v24, v31, v39, v28, 0, v33 + 1, &v37);
            goto LABEL_58;
          }
          v25 = 11;
        }
        else
        {
          v25 = 6;
        }
        v8 = -1073741670;
LABEL_37:
        dword_632EF0 = v25;
LABEL_58:
        v10 = v36;
LABEL_59:
        v7 = (int)a1;
        goto LABEL_60;
      }
      v10 = 0;
    }
  }
LABEL_60:
  if ( v41 )
    MI_DEREFERENCE_CONTROL_AREA_FILE(v7, v41);
  if ( v10 )
    ExFreePoolWithTag(v10);
  if ( v8 < 0 && v11 )
  {
    ExFreePoolWithTag(v11);
    v11 = 0;
  }
  *v44 = v11;
  return v8;
}
