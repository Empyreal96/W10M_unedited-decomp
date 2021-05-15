// ObGetObjectInformation 
 
int __fastcall ObGetObjectInformation(int a1, int a2, int a3, unsigned int *a4)
{
  unsigned int v4; // r4
  int v5; // r8
  int v6; // r0
  unsigned int v7; // r9
  unsigned __int16 *v9; // r10
  unsigned int v10; // r6
  unsigned int *v11; // r1
  unsigned int v12; // r2
  unsigned int v13; // r3
  _DWORD *v14; // r5
  unsigned int *v15; // r1
  int v16; // r0
  unsigned int v17; // r2
  int v18; // r2
  int v19; // r9
  int v20; // lr
  _DWORD *v21; // r2
  int v22; // r3
  _DWORD *v23; // r5
  int v24; // r1
  int v25; // r2
  int v26; // r3
  int v27; // r1
  int v28; // r0
  unsigned int v29; // r2
  __int16 v30; // r3
  int v31; // r2
  int *v32; // r3
  int v33; // r2
  int v34; // r1
  int *v35; // r3
  int v36; // r3
  int v37; // r5
  int v38; // r3
  int v39; // r2
  unsigned int v40; // r3
  unsigned int v41; // r1
  unsigned int v42; // r9
  unsigned int v43; // r4
  int v44; // r9
  __int16 v45; // r2
  __int16 v46; // r5
  unsigned int v48; // [sp+8h] [bp-90h] BYREF
  int v49; // [sp+Ch] [bp-8Ch]
  _DWORD *v50; // [sp+10h] [bp-88h]
  char v51; // [sp+14h] [bp-84h]
  unsigned int v52; // [sp+18h] [bp-80h]
  int v53; // [sp+1Ch] [bp-7Ch]
  int v54; // [sp+20h] [bp-78h]
  unsigned int *v55; // [sp+24h] [bp-74h]
  unsigned int v56; // [sp+28h] [bp-70h]
  int v57; // [sp+2Ch] [bp-6Ch]
  int v58; // [sp+30h] [bp-68h]
  unsigned int v59; // [sp+34h] [bp-64h]
  unsigned int v60; // [sp+38h] [bp-60h]
  int v61; // [sp+3Ch] [bp-5Ch]
  unsigned int *v62; // [sp+40h] [bp-58h]
  int v63; // [sp+44h] [bp-54h]
  unsigned int *v64; // [sp+48h] [bp-50h]
  unsigned int v65; // [sp+4Ch] [bp-4Ch]
  unsigned int *v66; // [sp+50h] [bp-48h]
  int v67; // [sp+54h] [bp-44h]
  int v68; // [sp+58h] [bp-40h]
  int v69; // [sp+5Ch] [bp-3Ch]
  unsigned int *v70; // [sp+60h] [bp-38h]
  int v71; // [sp+64h] [bp-34h]
  unsigned int v72; // [sp+68h] [bp-30h]
  unsigned int i; // [sp+6Ch] [bp-2Ch]
  int v74; // [sp+70h] [bp-28h]
  unsigned int v75; // [sp+74h] [bp-24h]
  int v76; // [sp+78h] [bp-20h]

  v70 = a4;
  v4 = a3;
  v53 = a3;
  v58 = a2;
  v61 = a1;
  v5 = 0;
  v55 = 0;
  v63 = 528;
  v6 = ExAllocatePoolWithTag(1, 528, 1916887631);
  v7 = v6;
  v59 = v6;
  v56 = v6;
  if ( !v6 )
    return -1073741670;
  v9 = (unsigned __int16 *)v6;
  v49 = 0;
  v10 = 0;
  v57 = 0;
  v68 = 0;
  v11 = (unsigned int *)ObpCreateTypeArray(ObpTypeObjectType);
  v64 = v11;
  v66 = v11;
  if ( !v11 )
  {
    ExFreePoolWithTag(v7);
    return -1073741823;
  }
  v12 = 0;
  v72 = 0;
LABEL_7:
  v60 = v12;
  if ( v12 < *v11 )
  {
    v13 = v11[v12 + 1];
    if ( !v13 )
      goto LABEL_78;
    v14 = (_DWORD *)(v13 + 40);
    v50 = (_DWORD *)(v13 + 40);
    if ( v13 + 40 == ObpTypeObjectType )
      goto LABEL_78;
    v15 = (unsigned int *)ObpCreateTypeArray(v14);
    v62 = v15;
    v55 = v15;
    if ( !v15 )
      goto LABEL_77;
    v16 = 1;
    v67 = 1;
    v51 = 1;
    v17 = 0;
    for ( i = 0; ; i = v65 + 1 )
    {
      v65 = v17;
      if ( v17 >= *v15 )
      {
LABEL_76:
        ObpDestroyTypeArray(v62);
        v55 = 0;
LABEL_77:
        v11 = v64;
        v12 = v60;
LABEL_78:
        v72 = ++v12;
        goto LABEL_7;
      }
      v18 = v15[v17 + 1];
      v69 = v18;
      if ( v18 )
        break;
LABEL_75:
      v17 = v65 + 1;
    }
    v19 = v18 + 16;
    v20 = v18 + 40;
    v71 = v18 + 40;
    if ( v16 )
    {
      v67 = 0;
      v51 = 0;
      if ( v57 && v10 < v4 )
        *(_DWORD *)v57 = v10;
      v21 = (_DWORD *)(v10 + v58);
      v57 = v10 + v58;
      v68 = v10 + v58;
      v10 += 48;
      v52 = v10;
      if ( v10 < 0x30 )
        goto LABEL_19;
      if ( v10 >= v4 )
        goto LABEL_22;
      *v21 = 0;
      v21[1] = v14[6];
      v21[2] = v14[7];
      v21[3] = *((unsigned __int8 *)v14 + 20);
      v21[4] = v14[12];
      v23 = v21 + 5;
      v24 = v50[14];
      v25 = v50[15];
      v26 = v50[16];
      *v23 = v50[13];
      v23[1] = v24;
      v23[2] = v25;
      v23[3] = v26;
      v14 = v50;
      v27 = v57;
      *(_DWORD *)(v57 + 36) = v50[17];
      *(_DWORD *)(v27 + 40) = v14[19];
      *(_BYTE *)(v27 + 44) = (unsigned __int8)(*((_BYTE *)v14 + 42) & 8) >> 3;
      v4 = v53;
      v48 = 0;
      v28 = ObQueryTypeName(v20, v27 + 48, v53 - v10, &v48);
      v54 = v28;
      v29 = (v48 + 3) & 0xFFFFFFFC;
      v48 = v29;
      if ( v28 < 0 )
      {
        v49 = v28;
      }
      else
      {
        v30 = v29 - 8;
        v31 = v57;
        *(_WORD *)(v57 + 50) = v30;
        *(_DWORD *)(v31 + 52) = *(_DWORD *)(v31 + 52) - v58 + v61;
        v29 = v48;
      }
      v10 += v29;
      v52 = v10;
      if ( v10 < v29 )
      {
LABEL_19:
        v22 = -1073741675;
LABEL_20:
        v49 = v22;
        goto LABEL_76;
      }
      v18 = v69;
      v20 = v19 + 24;
    }
    else if ( v10 < v4 )
    {
      *(_DWORD *)v5 = v10;
    }
    v5 = v10 + v58;
    v74 = v10 + v58;
    v10 += 40;
    v52 = v10;
    if ( v10 < 0x28 )
      goto LABEL_19;
    if ( v10 >= v4 )
    {
LABEL_22:
      v22 = -1073741820;
      goto LABEL_20;
    }
    *(_DWORD *)v5 = 0;
    *(_DWORD *)(v5 + 4) = v20;
    *(_DWORD *)(v5 + 8) = *(_DWORD *)(v18 + 8);
    *(_WORD *)(v5 + 12) = *(_WORD *)(v18 + 12);
    *(_DWORD *)(v5 + 16) = *(_DWORD *)v19;
    *(_DWORD *)(v5 + 20) = *(_DWORD *)(v19 + 4);
    *(_WORD *)(v5 + 14) = *(unsigned __int8 *)(v19 + 15);
    *(_DWORD *)(v5 + 36) = *(_DWORD *)(v19 + 20) & 0xFFFFFFF8;
    if ( (*(_BYTE *)(v19 + 14) & 8) != 0 )
      v32 = (int *)(v19 - ObpInfoMaskToOffset[*(_BYTE *)(v19 + 14) & 0xF]);
    else
      v32 = 0;
    v33 = v14[20];
    v34 = v14[21];
    if ( v32 )
    {
      v33 = *v32;
      v34 = v32[1];
    }
    *(_DWORD *)(v5 + 24) = v33;
    *(_DWORD *)(v5 + 28) = v34;
    if ( (*(_BYTE *)(v19 + 14) & 0x10) != 0 )
      v35 = (int *)(v19 - ObpInfoMaskToOffset[*(_BYTE *)(v19 + 14) & 0x1F]);
    else
      v35 = 0;
    if ( v35 )
    {
      v36 = *v35;
      if ( v36 )
        *(_DWORD *)(v5 + 32) = *(_DWORD *)(v36 + 176);
    }
    v48 = 0;
    v37 = 0;
    v54 = 0;
    if ( v50[28] && v50 == IoFileObjectType )
    {
      *(_DWORD *)v9 = *(_DWORD *)(v20 + 48);
      v38 = *(_DWORD *)(v20 + 52);
      *((_DWORD *)v9 + 1) = v38;
      v39 = *v9;
      if ( *v9 && v38 )
      {
        v40 = v39 + 2;
        v48 = v39 + 2;
        if ( (unsigned int)(v39 + 2) > 0x208 )
        {
          v48 = 520;
          *v9 = 518;
          v40 = v48;
        }
        memmove((int)(v9 + 4), *((_DWORD *)v9 + 1), v40 - 2);
        *((_DWORD *)v9 + 1) = v9 + 4;
        v9[1] = v48;
        *(_WORD *)(*((_DWORD *)v9 + 1) + 2 * (*v9 >> 1)) = 0;
        v41 = v48 + 8;
        v48 += 8;
        v4 = v53;
LABEL_59:
        if ( v41 )
        {
          v48 = (v41 + 3) & 0xFFFFFFFC;
          v10 += v48;
          v52 = v10;
          if ( v10 < v48 )
            goto LABEL_19;
          if ( v37 < 0 )
          {
            v10 += 8;
            v52 = v10;
            if ( v10 < 8 )
              goto LABEL_19;
            if ( v10 < v4 )
            {
              RtlInitUnicodeString(v5 + 40, 0);
              v49 = v37;
              goto LABEL_74;
            }
          }
          else
          {
            v45 = *v9;
            if ( *v9 && v10 < v4 )
            {
              v46 = v45 + 2;
              *(_WORD *)(v5 + 40) = v45;
              memmove(v5 + 48, *((_DWORD *)v9 + 1), (unsigned __int16)(v45 + 2));
              *(_DWORD *)(v5 + 44) = v5 + 48 - v58 + v61;
              *(_WORD *)(v5 + 42) = v46;
LABEL_74:
              v4 = v53;
              v14 = v50;
              v15 = v62;
              v16 = v67;
              goto LABEL_75;
            }
            if ( !*v9 )
              goto LABEL_71;
          }
LABEL_72:
          v49 = -1073741820;
          goto LABEL_74;
        }
        v10 += 8;
        v52 = v10;
        if ( v10 < 8 )
          goto LABEL_19;
LABEL_71:
        if ( v10 < v4 )
        {
          RtlInitUnicodeString(v5 + 40, 0);
          goto LABEL_74;
        }
        goto LABEL_72;
      }
    }
    else
    {
      v42 = v63;
      v37 = ObQueryNameStringMode(v20, (int)v9, v63, &v48, 0);
      v54 = v37;
      if ( v37 == -1073741820 )
      {
        v41 = v48;
        if ( v48 <= v42 || v48 + v10 >= v4 )
          goto LABEL_59;
        v43 = v59;
        v44 = ExAllocatePoolWithTag(1, v48, 1916887631);
        v59 = v44;
        v56 = v44;
        if ( v44 )
        {
          ExFreePoolWithTag(v43);
          v63 = v48;
          v75 = v48;
          v9 = (unsigned __int16 *)v44;
          v76 = v44;
          v37 = ObQueryNameStringMode(v71, v44, v48, &v48, 0);
          v54 = v37;
        }
        else
        {
          v59 = v43;
          v56 = v43;
          v37 = -1073741670;
          v54 = -1073741670;
        }
        v4 = v53;
      }
    }
    v41 = v48;
    goto LABEL_59;
  }
  if ( v70 )
    *v70 = v10;
  if ( v55 )
    ObpDestroyTypeArray(v55);
  ObpDestroyTypeArray(v66);
  ExFreePoolWithTag(v56);
  if ( v68 )
    return v49;
  return -1073741823;
}
