// SepCaptureTokenSecurityAttributesInformation 
 
int __fastcall SepCaptureTokenSecurityAttributesInformation(unsigned int a1, int a2, int a3, int *a4)
{
  int v4; // r8
  int v6; // r4
  unsigned int v7; // r10
  unsigned int v8; // r9
  int result; // r0
  int v10; // r0
  unsigned int v11; // r6
  unsigned int v12; // r3
  unsigned int v13; // r5
  int v14; // r0
  unsigned int v15; // r8
  unsigned int v16; // r3
  unsigned int v17; // r5
  unsigned __int16 *v18; // r8
  int v19; // r0
  int v20; // r2
  unsigned int v21; // r3
  unsigned int v22; // r8
  unsigned int v23; // r5
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r0
  unsigned int *v27; // r2
  unsigned int v28; // r5
  unsigned int v29; // r8
  unsigned int v30; // r10
  unsigned int v31; // r5
  unsigned int v32; // r8
  unsigned int v33; // r6
  unsigned int v34; // [sp+0h] [bp-60h]
  unsigned int v35; // [sp+4h] [bp-5Ch] BYREF
  int v36; // [sp+8h] [bp-58h]
  int v37; // [sp+Ch] [bp-54h] BYREF
  int *v38; // [sp+10h] [bp-50h]
  int v39; // [sp+14h] [bp-4Ch]
  unsigned int v40; // [sp+18h] [bp-48h]
  unsigned int v41; // [sp+1Ch] [bp-44h]
  unsigned int i; // [sp+20h] [bp-40h]
  int v43; // [sp+24h] [bp-3Ch]
  int v44; // [sp+28h] [bp-38h]
  unsigned int v45; // [sp+2Ch] [bp-34h]
  unsigned int v46; // [sp+30h] [bp-30h]
  int v47; // [sp+34h] [bp-2Ch]
  int v48; // [sp+38h] [bp-28h]
  int v49; // [sp+3Ch] [bp-24h]
  unsigned int varg_r0; // [sp+68h] [bp+8h]
  int varg_r1; // [sp+6Ch] [bp+Ch]
  int varg_r2; // [sp+70h] [bp+10h]
  int *varg_r3; // [sp+74h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v38 = a4;
  varg_r3 = a4;
  v48 = a3;
  v4 = (char)a2;
  v6 = 0;
  v7 = 0;
  v34 = 0;
  v44 = 0;
  v39 = 0;
  v43 = 0;
  v37 = 0;
  v40 = 0;
  v45 = 0;
  v41 = 0;
  v46 = 0;
  v8 = 0;
  v35 = 0;
  if ( !(_BYTE)a2 )
    return -1073741637;
  v10 = ExAllocatePoolWithTag(1, 12, 1950442835);
  v11 = v10;
  v47 = v10;
  v49 = v10;
  if ( !v10 )
    return -1073741670;
  *(_DWORD *)v10 = 0;
  *(_DWORD *)(v10 + 4) = 0;
  *(_DWORD *)(v10 + 8) = 0;
  if ( v4 == 1 )
  {
    if ( (a1 & 3) != 0 )
      ExRaiseDatatypeMisalignment(v10);
    if ( a1 + 12 > MmUserProbeAddress || a1 + 12 < a1 )
      *(_BYTE *)MmUserProbeAddress = 0;
    *(_WORD *)v10 = *(_WORD *)a1;
    *(_WORD *)(v10 + 2) = *(_WORD *)(a1 + 2);
    v12 = *(_DWORD *)(a1 + 4);
    *(_DWORD *)(v10 + 4) = v12;
    if ( !v12 )
    {
      *v38 = v10;
      result = 0;
      v37 = 0;
      return result;
    }
    *(_DWORD *)(v10 + 8) = *(_DWORD *)(a1 + 8);
    v6 = RtlULongLongToULong(24 * v12, (24 * (unsigned __int64)v12) >> 32, &v37);
    v36 = v6;
    if ( v6 < 0 )
    {
      ExFreePoolWithTag(v11);
      result = v6;
      v37 = v6;
      return result;
    }
    v13 = v37;
    v14 = ExAllocatePoolWithTag(1, v37, 1950442835);
    v15 = v14;
    v34 = v14;
    v44 = v14;
    if ( !v14 )
    {
      ExFreePoolWithTag(v11);
      result = -1073741670;
      v37 = -1073741670;
      return result;
    }
    if ( v13 )
    {
      v16 = *(_DWORD *)(v11 + 8);
      if ( (v16 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v14);
      if ( v16 + v13 > MmUserProbeAddress || v16 + v13 < v16 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    memmove(v14, *(_DWORD *)(v11 + 8), v13);
    v17 = 0;
    i = 0;
    while ( 1 )
    {
      if ( v17 >= *(_DWORD *)(v11 + 4) )
        goto LABEL_36;
      v18 = (unsigned __int16 *)(v15 + 24 * v17);
      if ( !*v18 )
      {
LABEL_26:
        v6 = -1073741811;
        v36 = -1073741811;
LABEL_61:
        v7 = v34;
LABEL_62:
        v27 = (unsigned int *)v38;
        goto LABEL_64;
      }
      v19 = ExAllocatePoolWithTag(1, *v18, 1950442835);
      v39 = v19;
      v43 = v19;
      if ( !v19 )
        break;
      v20 = *v18;
      if ( *v18 )
      {
        v21 = *((_DWORD *)v18 + 1);
        if ( (v21 & 1) != 0 )
          ExRaiseDatatypeMisalignment(v19);
        if ( v20 + v21 > MmUserProbeAddress || v20 + v21 < v21 )
          *(_BYTE *)MmUserProbeAddress = 0;
      }
      memmove(v19, *((_DWORD *)v18 + 1), *v18);
      *((_DWORD *)v18 + 1) = v39;
      v45 = ++v40;
      v39 = 0;
      v43 = 0;
      i = ++v17;
      v15 = v34;
    }
    v6 = -1073741670;
    v36 = -1073741670;
LABEL_36:
    if ( v6 < 0 )
      goto LABEL_61;
    v22 = 0;
    for ( i = 0; ; i = v22 )
    {
      if ( v22 >= *(_DWORD *)(v11 + 4) )
      {
LABEL_60:
        v7 = v34;
        *(_DWORD *)(v11 + 8) = v34;
        goto LABEL_62;
      }
      v23 = v34 + 24 * v22;
      v24 = *(_DWORD *)(v23 + 16);
      if ( !v24 )
      {
        if ( !v48 )
          goto LABEL_26;
        *(_DWORD *)(v23 + 20) = 0;
        goto LABEL_59;
      }
      v25 = *(unsigned __int16 *)(v23 + 8);
      if ( *(_WORD *)(v23 + 8) )
      {
        if ( *(unsigned __int16 *)(v23 + 8) <= 2u )
          goto LABEL_52;
        switch ( v25 )
        {
          case 3:
            v26 = SepCaptureUnicodeStringArray(*(_DWORD *)(v23 + 20), v24, 1, (int *)&v35);
            goto LABEL_53;
          case 4:
            v26 = SepCaptureFqbnArray(*(_DWORD *)(v23 + 20));
            goto LABEL_53;
          case 5:
            goto LABEL_49;
          case 6:
LABEL_52:
            v26 = SepCaptureInt64Array(*(_DWORD *)(v23 + 20));
LABEL_53:
            v6 = v26;
            v36 = v26;
            v8 = v35;
            if ( v26 >= 0 )
              *(_DWORD *)(v23 + 20) = v35;
            goto LABEL_57;
          case 16:
LABEL_49:
            v26 = SepCaptureOctetStringArray(*(_DWORD *)(v23 + 20));
            goto LABEL_53;
        }
      }
      v6 = -1073741637;
      v36 = -1073741637;
LABEL_57:
      if ( v6 < 0 )
        goto LABEL_60;
      v46 = ++v41;
      v8 = 0;
      v35 = 0;
LABEL_59:
      ++v22;
    }
  }
  v27 = (unsigned int *)v38;
LABEL_64:
  if ( v6 >= 0 )
  {
    *v27 = v11;
  }
  else
  {
    if ( v7 )
    {
      v28 = 0;
      v29 = v7;
      v30 = v40;
      while ( v28 < v30 )
      {
        ExFreePoolWithTag(*(_DWORD *)(v29 + 4));
        ++v28;
        v29 += 24;
      }
      v31 = 0;
      v32 = v34;
      v33 = v41;
      while ( v31 < v33 )
      {
        ExFreePoolWithTag(*(_DWORD *)(v32 + 20));
        ++v31;
        v32 += 24;
      }
      ExFreePoolWithTag(v34);
      v11 = v47;
    }
    if ( v39 )
      ExFreePoolWithTag(v39);
    if ( v8 )
      ExFreePoolWithTag(v8);
    ExFreePoolWithTag(v11);
  }
  return v6;
}
