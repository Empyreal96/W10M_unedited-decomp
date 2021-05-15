// SeCaptureSecurityDescriptor 
 
int __fastcall SeCaptureSecurityDescriptor(unsigned int a1, int a2, int a3, int a4, unsigned int *a5)
{
  int v5; // r10
  unsigned int v6; // r4
  __int16 v8; // r3
  int v9; // r2
  unsigned int v10; // r0
  int v11; // r2
  unsigned int v12; // r1
  unsigned int v13; // r2
  int v14; // r2
  unsigned int v15; // r9
  int v16; // r3
  char v17; // r2
  unsigned int v18; // r8
  unsigned __int16 *v19; // r3
  unsigned int v20; // r3
  unsigned int v21; // r3
  _WORD *v22; // r2
  unsigned int v23; // r5
  unsigned __int8 *v24; // r2
  int v25; // lr
  unsigned int v26; // r4
  unsigned __int8 *v27; // r2
  int v28; // lr
  unsigned int v29; // r3
  unsigned int v30; // r5
  _BYTE *v31; // r0
  int v32; // r5
  char v33; // r3
  unsigned int v34; // r2
  int v35; // r9
  int v36; // r1
  int v37; // r8
  int v38; // r1
  unsigned int v40; // [sp+4h] [bp-9Ch]
  int v41; // [sp+8h] [bp-98h]
  int v42; // [sp+Ch] [bp-94h]
  unsigned int v43; // [sp+10h] [bp-90h]
  unsigned int v44; // [sp+14h] [bp-8Ch]
  unsigned int v45; // [sp+1Ch] [bp-84h]
  unsigned int v46; // [sp+20h] [bp-80h]
  unsigned int v47; // [sp+24h] [bp-7Ch]
  unsigned int v48; // [sp+30h] [bp-70h]
  int v49; // [sp+40h] [bp-60h]
  unsigned int v50; // [sp+54h] [bp-4Ch]
  char v51; // [sp+5Ch] [bp-44h]
  unsigned int v52; // [sp+64h] [bp-3Ch]
  unsigned int v53; // [sp+68h] [bp-38h]
  int varg_r1; // [sp+ACh] [bp+Ch]

  varg_r1 = a2;
  v41 = a3;
  a2 = (char)a2;
  v5 = a2;
  LOBYTE(varg_r1) = a2;
  v6 = a1;
  LOBYTE(v47) = 0;
  v45 = 0;
  LOBYTE(v44) = 0;
  v43 = 0;
  if ( a1 )
  {
    if ( (_BYTE)a2 )
    {
      if ( (a1 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a1);
      v49 = *(_DWORD *)a1;
    }
    else
    {
      if ( !a4 )
        goto LABEL_126;
      v49 = *(_DWORD *)a1;
    }
    if ( (unsigned __int8)v49 != 1 )
      return -1073741736;
    v8 = *(_WORD *)(a1 + 2);
    if ( (v8 & 0x8000) != 0 )
    {
      v9 = *(_DWORD *)(a1 + 4);
      if ( v9 )
        v10 = v9 + a1;
      else
        v10 = 0;
    }
    else
    {
      v10 = *(_DWORD *)(a1 + 4);
    }
    v42 = v10;
    if ( (v8 & 0x8000) != 0 )
    {
      v11 = *(_DWORD *)(v6 + 8);
      if ( v11 )
        v12 = v11 + v6;
      else
        v12 = 0;
    }
    else
    {
      v12 = *(_DWORD *)(v6 + 8);
    }
    v40 = v12;
    if ( (v8 & 0x10) != 0 )
    {
      if ( (v8 & 0x8000) != 0 )
      {
        v14 = *(_DWORD *)(v6 + 12);
        if ( v14 )
          v13 = v14 + v6;
        else
          v13 = 0;
      }
      else
      {
        v13 = *(_DWORD *)(v6 + 12);
      }
    }
    else
    {
      v13 = 0;
    }
    v48 = v13;
    if ( (v8 & 4) != 0 )
    {
      if ( (v8 & 0x8000) != 0 )
      {
        v16 = *(_DWORD *)(v6 + 16);
        if ( v16 )
          v15 = v16 + v6;
        else
          v15 = 0;
      }
      else
      {
        v15 = *(_DWORD *)(v6 + 16);
      }
    }
    else
    {
      v15 = 0;
    }
    v17 = BYTE2(v49);
    v51 = BYTE2(v49);
    HIWORD(v49) &= 0x7FFFu;
    v46 = 0;
    v50 = 0;
    v53 = 0;
    v18 = 0;
    v52 = 0;
    if ( (v17 & 0x10) != 0 && v48 )
    {
      if ( v5 )
      {
        v19 = (unsigned __int16 *)(v48 + 2);
        if ( v48 + 2 >= MmUserProbeAddress )
          v19 = (unsigned __int16 *)MmUserProbeAddress;
        v20 = *v19;
        v46 = v20;
        if ( v20 )
        {
          if ( (v48 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v10);
          if ( v20 + v48 > MmUserProbeAddress || v20 + v48 < v48 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
      else
      {
        v20 = *(unsigned __int16 *)(v48 + 2);
        v46 = v20;
      }
      v21 = (v20 + 3) & 0xFFFFFFFC;
      v53 = v21;
      if ( v21 > 0xFFFF || v21 < 8 )
        return -1073741705;
    }
    else
    {
      v48 = 0;
    }
    if ( (v17 & 4) != 0 && v15 )
    {
      if ( v5 )
      {
        v22 = (_WORD *)(v15 + 2);
        if ( v15 + 2 >= MmUserProbeAddress )
          v22 = (_WORD *)MmUserProbeAddress;
        v23 = (unsigned __int16)*v22;
        v50 = v23;
        if ( *v22 )
        {
          if ( (v15 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v10);
          if ( v23 + v15 > MmUserProbeAddress || v23 + v15 < v15 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
      else
      {
        v23 = *(unsigned __int16 *)(v15 + 2);
        v50 = v23;
      }
      v18 = (v23 + 3) & 0xFFFFFFFC;
      if ( v18 > 0xFFFF )
        return -1073741705;
      if ( v18 < 8 )
        return -1073741705;
    }
    else
    {
      v15 = 0;
    }
    if ( v10 )
    {
      if ( v5 )
      {
        v24 = (unsigned __int8 *)(v10 + 1);
        if ( v10 + 1 >= MmUserProbeAddress )
          v24 = (unsigned __int8 *)MmUserProbeAddress;
        v47 = *v24;
        v25 = 4 * (v47 + 2);
        v45 = v25;
        if ( v25 )
        {
          if ( (v10 & 3) != 0 )
            ExRaiseDatatypeMisalignment(v10);
          if ( v25 + v10 > MmUserProbeAddress || v25 + v10 < v10 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
      else
      {
        v47 = *(unsigned __int8 *)(v10 + 1);
        v25 = RtlLengthRequiredSid(v47);
        v45 = v25;
        v12 = v40;
      }
      v26 = (v25 + 3) & 0xFFFFFFFC;
      v52 = v26;
    }
    else
    {
      v26 = 0;
    }
    if ( v12 )
    {
      if ( v5 )
      {
        v27 = (unsigned __int8 *)(v12 + 1);
        if ( v12 + 1 >= MmUserProbeAddress )
          v27 = (unsigned __int8 *)MmUserProbeAddress;
        v44 = *v27;
        v28 = 4 * (v44 + 2);
        v43 = v28;
        if ( v28 )
        {
          if ( (v12 & 3) != 0 )
            ExRaiseDatatypeMisalignment(&MmUserProbeAddress);
          if ( v28 + v12 > MmUserProbeAddress || v28 + v12 < v12 )
            *(_BYTE *)MmUserProbeAddress = 0;
        }
      }
      else
      {
        v44 = *(unsigned __int8 *)(v12 + 1);
        v28 = RtlLengthRequiredSid(v44);
        v43 = v28;
      }
      v29 = (v28 + 3) & 0xFFFFFFFC;
    }
    else
    {
      v29 = 0;
    }
    v30 = v29 + v26 + v18 + v53;
    v31 = (_BYTE *)ExAllocatePoolWithTag(v41, v30 + 20, 1666409811);
    v6 = (unsigned int)v31;
    if ( !v31 )
      return -1073741670;
    memset(v31, 0, v30 + 20);
    *(_DWORD *)v6 = v49;
    *(_DWORD *)(v6 + 4) = v42;
    *(_DWORD *)(v6 + 8) = v40;
    *(_DWORD *)(v6 + 12) = v48;
    *(_DWORD *)(v6 + 16) = v15;
    v32 = v6 + 20;
    *(_WORD *)(v6 + 2) |= 0x8000u;
    v33 = v51;
    if ( (v51 & 0x10) != 0 && v48 )
    {
      memmove(v6 + 20, v48, v46);
      v34 = v53;
      if ( v5 )
      {
        if ( !SepCheckAcl(v6 + 20, v46) )
        {
LABEL_103:
          ExFreePoolWithTag(v6);
          return -1073741705;
        }
        v34 = v53;
      }
      *(_DWORD *)(v6 + 12) = 20;
      *(_WORD *)(v6 + 22) = v34;
      v32 += v34;
      v33 = v51;
    }
    else
    {
      *(_DWORD *)(v6 + 12) = 0;
    }
    if ( (v33 & 4) != 0 && v15 )
    {
      memmove(v32, v15, v50);
      v35 = v42;
      if ( v5 && (v50 < 8 || v50 != *(unsigned __int16 *)(v32 + 2) || !RtlValidAcl(v32)) )
        goto LABEL_103;
      *(_DWORD *)(v6 + 16) = v32 - v6;
      *(_WORD *)(v32 + 2) = v18;
      v32 += v18;
    }
    else
    {
      *(_DWORD *)(v6 + 16) = 0;
      v35 = v42;
    }
    if ( v35 )
    {
      memmove(v32, v35, v45);
      *(_BYTE *)(v32 + 1) = v47;
      v37 = v40;
      if ( v5 && !RtlValidSid(v32, v36) )
        goto LABEL_118;
      *(_DWORD *)(v6 + 4) = v32 - v6;
      v32 += v52;
    }
    else
    {
      *(_DWORD *)(v6 + 4) = 0;
      v37 = v40;
    }
    if ( v37 )
    {
      memmove(v32, v37, v43);
      *(_BYTE *)(v32 + 1) = v44;
      if ( v5 && !RtlValidSid(v32, v38) )
      {
LABEL_118:
        ExFreePoolWithTag(v6);
        return -1073741704;
      }
      *(_DWORD *)(v6 + 8) = v32 - v6;
    }
    else
    {
      *(_DWORD *)(v6 + 8) = 0;
    }
LABEL_126:
    *a5 = v6;
    return 0;
  }
  *a5 = 0;
  return 0;
}
