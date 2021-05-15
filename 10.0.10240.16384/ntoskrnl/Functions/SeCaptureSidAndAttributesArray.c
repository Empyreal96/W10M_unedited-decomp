// SeCaptureSidAndAttributesArray 
 
int __fastcall SeCaptureSidAndAttributesArray(unsigned int a1, unsigned int a2, int a3, int a4, unsigned int a5, int a6, int a7, int *a8, unsigned int *a9)
{
  unsigned int v9; // r10
  int v10; // r8
  int v12; // r5
  int v13; // r3
  unsigned int v14; // r4
  int v15; // r0
  unsigned int v16; // r6
  unsigned int v17; // r3
  unsigned int v18; // lr
  unsigned __int8 *v19; // r2
  unsigned int v20; // r0
  unsigned int *v21; // r4
  int v22; // r0
  unsigned int v23; // r3
  int v24; // r2
  int v25; // lr
  unsigned int i; // r5
  int v27; // t1
  int *v28; // r6
  int v29; // r0
  int v30; // r4
  int v31; // r0
  unsigned int v32; // r2
  unsigned int v33; // r4
  int *v34; // r1
  int v35; // r4
  int v36; // r4
  int v37; // r4
  unsigned int v38; // r10
  int v39; // r9
  int v40; // r4
  unsigned int v41; // r5
  int v43; // [sp+0h] [bp-58h]
  int v44; // [sp+8h] [bp-50h]
  unsigned int v45; // [sp+Ch] [bp-4Ch]
  unsigned int v46; // [sp+10h] [bp-48h]
  unsigned int v47; // [sp+14h] [bp-44h]
  int v48; // [sp+14h] [bp-44h]
  unsigned int v49; // [sp+1Ch] [bp-3Ch]
  int v50; // [sp+20h] [bp-38h]
  int v51; // [sp+24h] [bp-34h]
  int v52; // [sp+24h] [bp-34h]
  int v53; // [sp+28h] [bp-30h]
  int v54; // [sp+30h] [bp-28h]
  int v55; // [sp+34h] [bp-24h]
  int varg_r2; // [sp+68h] [bp+10h]

  varg_r2 = a3;
  v44 = a4;
  v43 = (char)a3;
  LOBYTE(varg_r2) = a3;
  v49 = a2;
  v9 = a1;
  v51 = a1;
  v45 = 0;
  v10 = 0;
  if ( !a2 )
  {
    *a8 = 0;
    *a9 = 0;
    return 0;
  }
  if ( a2 > 0x1000 )
    return -1073741811;
  v12 = 8 * a2;
  v47 = 8 * a2;
  v13 = 8 * a2 + 3;
  v14 = v13 & 0xFFFFFFFC;
  v46 = v13 & 0xFFFFFFFC;
  if ( (_BYTE)a3 )
  {
    v15 = ExAllocatePoolWithTag(1, v13 & 0xFFFFFFFC, 1632920915);
    v16 = v15;
    v45 = v15;
    if ( !v15 )
      return -1073741670;
    if ( v12 )
    {
      if ( (v9 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v15);
      if ( v12 + v9 > MmUserProbeAddress || v12 + v9 < v9 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v17 = 0;
    v50 = 0;
    while ( v17 < v49 )
    {
      v18 = *(_DWORD *)(v9 + 8 * v17);
      __dmb(0xBu);
      v19 = (unsigned __int8 *)(v18 + 1);
      if ( v18 + 1 >= MmUserProbeAddress )
        v19 = (unsigned __int8 *)MmUserProbeAddress;
      v20 = *v19;
      if ( v20 > 0xF )
      {
        v10 = -1073741704;
        v14 = v46;
        break;
      }
      v21 = (unsigned int *)(v16 + 8 * v17);
      *v21 = v18;
      v22 = RtlLengthRequiredSid(v20);
      v21[1] = v22;
      if ( v22 )
      {
        v23 = *v21;
        if ( (*v21 & 3) != 0 )
          ExRaiseDatatypeMisalignment(v22);
        if ( v23 + v22 > MmUserProbeAddress || v23 + v22 < v23 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      v14 = ((v21[1] + 3) & 0xFFFFFFFC) + v46;
      v46 = v14;
      v17 = ++v50;
      v10 = 0;
    }
    v24 = v43;
    v25 = v44;
    if ( v10 < 0 )
    {
      ExFreePoolWithTag(v16);
      return v10;
    }
  }
  else
  {
    for ( i = 0; i < v49; ++i )
    {
      v27 = *(_DWORD *)v9;
      v9 += 8;
      v14 += (RtlLengthRequiredSid(*(unsigned __int8 *)(v27 + 1)) + 3) & 0xFFFFFFFC;
    }
    v16 = 0;
    v24 = v43;
    v25 = v44;
  }
  *a9 = v14;
  if ( !v25 )
  {
    v29 = ExAllocatePoolWithTag(1, v14, 1632855379);
    v28 = a8;
    *a8 = v29;
    if ( !v29 )
    {
      if ( v43 )
        ExFreePoolWithTag(v45);
      return -1073741670;
    }
    goto LABEL_42;
  }
  if ( v14 <= a5 )
  {
    v28 = a8;
    *a8 = v25;
LABEL_42:
    if ( v43 )
    {
      v30 = *v28;
      memmove(*v28, v51, v47);
      v31 = ((v47 + 3) & 0xFFFFFFFC) + v30;
      v48 = v31;
      v32 = 0;
      v52 = 0;
      v55 = *v28;
      while ( v32 < v49 && !v10 )
      {
        v33 = v45 + 8 * v32;
        memmove(v31, *(_DWORD *)v33, *(_DWORD *)(v33 + 4));
        v34 = (int *)(v55 + 8 * v52);
        *v34 = v48;
        v54 = *(_DWORD *)(v33 + 4);
        v31 = v48 + ((v54 + 3) & 0xFFFFFFFC);
        v48 = v31;
        if ( (v34[1] & 0x1FFFFF80) != 0 )
        {
          v10 = -1073741811;
        }
        else
        {
          v35 = *v34;
          if ( !RtlValidSid(*v34, v34) || RtlLengthSid(v35) != v54 )
            v10 = -1073741704;
          v31 = v48;
        }
        v32 = ++v52;
      }
      v36 = v44;
    }
    else
    {
      v37 = *v28;
      memmove(*v28, v51, v47);
      v53 = ((v47 + 3) & 0xFFFFFFFC) + v37;
      v38 = 0;
      v39 = *v28;
      while ( v38 < v49 )
      {
        v40 = *(_DWORD *)v39;
        v41 = RtlLengthRequiredSid(*(unsigned __int8 *)(*(_DWORD *)v39 + 1));
        memmove(v53, v40, v41);
        *(_DWORD *)v39 = v53;
        v39 += 8;
        ++v38;
        v53 += (v41 + 3) & 0xFFFFFFFC;
      }
      v28 = a8;
      v36 = v44;
    }
    if ( v43 )
      ExFreePoolWithTag(v45);
    if ( !v36 && v10 < 0 )
    {
      ExFreePoolWithTag(*v28);
      *v28 = 0;
    }
    return v10;
  }
  if ( v24 )
    ExFreePoolWithTag(v16);
  return -1073741789;
}
