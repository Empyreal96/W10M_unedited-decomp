// SepMaximumAccessCheckEx 
 
int __fastcall SepMaximumAccessCheckEx(int result, int a2, int a3, int a4, int *a5, int a6, unsigned int a7, _DWORD *a8, int a9, int a10, unsigned __int8 a11, unsigned __int8 a12, char a13, int a14)
{
  int v14; // r4
  int v15; // lr
  _DWORD *v16; // r8
  unsigned int v17; // r9
  int v19; // r10
  _DWORD *v20; // r2
  unsigned int v21; // r4
  int v22; // r6
  int v23; // r1
  unsigned int v24; // r7
  unsigned __int8 *v25; // r4
  int v26; // r2
  int *v27; // r6
  int v28; // r3
  int v29; // r6
  int v30; // r2
  int v31; // r6
  int v32; // r2
  int v33; // r6
  int v34; // r6
  int v35; // r0
  int v36; // r3
  int v37; // r2
  int v38; // r1
  unsigned __int8 *v39; // r6
  int v40; // r2
  int v41; // r3
  int v42; // r0
  int v43; // r2
  int v44; // r2
  int v45; // r3
  int v46; // r0
  int v47; // r3
  int v48; // r2
  int v49; // r3
  unsigned __int8 *v50; // r0
  int v51; // r1
  int v52; // r0
  unsigned int *v53; // r2
  int v54; // r7
  _DWORD *v55; // r3
  int v56; // r6
  int v57; // r0
  int v58; // r1
  int v59; // r3
  int v60; // r6
  int v61; // r2
  int v62; // r6
  int v63; // r3
  int v64; // r2
  int v65; // r6
  int v66; // r6
  int v67; // r7
  _DWORD *v68; // r3
  int v69; // r6
  int v70; // r0
  int v71; // r1
  int v72; // r3
  int v73; // [sp+8h] [bp-50h]
  unsigned int v74; // [sp+20h] [bp-38h]
  int v75; // [sp+24h] [bp-34h] BYREF
  BOOL v76; // [sp+28h] [bp-30h]
  int v77; // [sp+2Ch] [bp-2Ch] BYREF
  int v78; // [sp+30h] [bp-28h]
  int v79; // [sp+34h] [bp-24h]
  unsigned int v80; // [sp+38h] [bp-20h]

  v14 = *(_DWORD *)(result + 176);
  v78 = a4;
  v79 = a2;
  v15 = a11;
  v76 = (v14 & 0x2000) == 0;
  v16 = a8;
  v17 = a7;
  v19 = result;
  if ( a11 && a7 )
  {
    v20 = a8;
    v21 = a7;
    do
    {
      result = v20[10];
      v22 = v20[7];
      v23 = 1;
      if ( result )
      {
        while ( v23 )
        {
          if ( (v23 & v22) != 0 )
            *(_DWORD *)result = 0x800000;
          result += 4;
          v23 *= 2;
        }
      }
      v20[6] = v20[7];
      v20[7] = 0;
      v20 += 11;
      --v21;
    }
    while ( v21 );
  }
  v24 = 0;
  v25 = (unsigned __int8 *)(a3 + 8);
  v80 = *(unsigned __int16 *)(a3 + 4);
  v74 = 0;
  if ( v80 )
  {
    result = a12;
    v26 = a9;
    v27 = a5;
    while ( (v25[1] & 8) != 0 )
    {
LABEL_30:
      v74 = ++v24;
      v25 += *((unsigned __int16 *)v25 + 1);
      if ( v24 >= v80 )
        goto LABEL_31;
    }
    v28 = *v25;
    if ( !*v25 )
    {
      if ( !v76 || v15 )
        goto LABEL_43;
      v29 = SePackagePrefixSid;
      if ( v25[9] >= 2u
        && v25[8] == *(unsigned __int8 *)SePackagePrefixSid
        && RtlCompareMemory(v25 + 10, SePackagePrefixSid + 2, 6) == 6
        && (v30 = *((_DWORD *)v25 + 4), v30 == *(_DWORD *)(v29 + 8)) )
      {
        v31 = *((_DWORD *)v25 + 1);
        if ( v30 == 2 && v25[9] == 2 && *((_DWORD *)v25 + 5) == 1
          || (*(_BYTE *)(a14 + 16) = 1, (*(_DWORD *)(v19 + 176) & 0x4000) != 0)
          && RtlEqualSid(*(unsigned __int16 **)(v19 + 480), (unsigned __int16 *)v25 + 4) )
        {
          *(_DWORD *)(a14 + 4) |= v31;
          *(_BYTE *)(a14 + 17) = 1;
        }
        v32 = *(_DWORD *)(a14 + 4);
      }
      else
      {
        v33 = SeCapabilityPrefixSid;
        if ( v25[9] < 2u
          || v25[8] != *(unsigned __int8 *)SeCapabilityPrefixSid
          || RtlCompareMemory(v25 + 10, SeCapabilityPrefixSid + 2, 6) != 6
          || *((_DWORD *)v25 + 4) != *(_DWORD *)(v33 + 8) )
        {
          v27 = a5;
LABEL_43:
          v35 = SepSidInToken(v19, 0, (int)(v25 + 8), 0, a11);
LABEL_44:
          if ( v35 )
          {
            v36 = 1;
            goto LABEL_46;
          }
          goto LABEL_48;
        }
        v34 = *((_DWORD *)v25 + 1);
        if ( SepSidInTokenSidHash(v19 + 492, 0, (unsigned __int16 *)v25 + 4, 0, 1, 0) )
        {
          *(_DWORD *)(a14 + 8) |= v34;
          *(_BYTE *)(a14 + 18) = 1;
        }
        v32 = *(_DWORD *)(a14 + 8);
      }
      *(_DWORD *)a14 &= ~v32;
      goto LABEL_28;
    }
    switch ( v28 )
    {
      case 5:
        v38 = *((_DWORD *)v25 + 2);
        if ( (v38 & 1) != 0 )
          v39 = v25 + 12;
        else
          v39 = 0;
        if ( v39 )
        {
          if ( !v26 )
            goto LABEL_29;
          if ( (v38 & 1) != 0 )
            v44 = 16;
          else
            v44 = 0;
          if ( (v38 & 2) != 0 )
            v45 = 16;
          else
            v45 = 0;
          if ( SepSidInToken(v19, 0, (int)&v25[v45 + 12 + v44], 0, v15) && AuthzBasepObjectInTypeList(v39, a8, a7, &v75) )
          {
            v43 = v75;
            goto LABEL_63;
          }
LABEL_28:
          v15 = a11;
          result = a12;
          v26 = a9;
LABEL_29:
          v27 = a5;
          goto LABEL_30;
        }
        if ( (v38 & 1) != 0 )
          v40 = 16;
        else
          v40 = 0;
        if ( (v38 & 2) != 0 )
          v41 = 16;
        else
          v41 = 0;
        v42 = SepSidInToken(v19, 0, (int)&v25[v41 + 12 + v40], 0, v15);
LABEL_61:
        if ( v42 )
        {
          v43 = 0;
LABEL_63:
          AuthzBasepAddAccessTypeList((int)a8, a7, v43, v24, *((_DWORD *)v25 + 1), 1);
          goto LABEL_28;
        }
        goto LABEL_28;
      case 4:
        if ( SepSidInToken(v19, 0, (int)&v25[4 * v25[13] + 20], 0, v15) )
        {
          v35 = SepSidInToken(v79, 0, (int)(v25 + 12), 0, 0);
          goto LABEL_44;
        }
        goto LABEL_48;
      case 1:
        v46 = SepSidInToken(v19, 0, (int)(v25 + 8), 1, v15);
LABEL_79:
        if ( !v46 )
          goto LABEL_48;
LABEL_80:
        v36 = 2;
LABEL_46:
        v37 = 0;
LABEL_47:
        AuthzBasepAddAccessTypeList((int)a8, a7, v37, v24, *((_DWORD *)v25 + 1), v36);
        goto LABEL_48;
      case 6:
        v47 = *((_DWORD *)v25 + 2);
        if ( (v47 & 1) != 0 )
          v48 = 16;
        else
          v48 = 0;
        if ( (v47 & 2) != 0 )
          v49 = 16;
        else
          v49 = 0;
        if ( !SepSidInToken(v19, 0, (int)&v25[v49 + 12 + v48], 1, v15) )
          goto LABEL_48;
        if ( (*((_DWORD *)v25 + 2) & 1) != 0 )
          v50 = v25 + 12;
        else
          v50 = 0;
        if ( !v50 )
          goto LABEL_80;
        if ( !a9 )
        {
          v51 = 1;
          v52 = *((_DWORD *)v25 + 1) & ~a8[7];
          v53 = (unsigned int *)a8[10];
          a8[8] |= v52;
          if ( v53 )
          {
            while ( v51 )
            {
              if ( (v51 & v52) != 0 && !*v53 )
                *v53 = v24 | 0x20000;
              ++v53;
              v51 *= 2;
            }
          }
          goto LABEL_48;
        }
        if ( AuthzBasepObjectInTypeList(v50, a8, a7, &v75) )
        {
          v37 = v75;
          v36 = 2;
          goto LABEL_47;
        }
LABEL_48:
        v15 = a11;
        result = a12;
        v26 = a9;
        goto LABEL_30;
    }
    if ( v28 != 9 )
    {
      if ( !a13 || v28 != 10 )
        goto LABEL_30;
      if ( (unsigned int)KeGetCurrentIrql(result) >= 2 )
        goto LABEL_48;
      v67 = v25[9] + 2;
      if ( *((unsigned __int16 *)v25 + 1) - 4 * v67 == 8 )
        goto LABEL_167;
      if ( v78 && !*v27 )
        AuthzBasepInitializeResourceClaimsFromSacl(v78, (int)v27);
      v68 = *(_DWORD **)(v19 + 636);
      v69 = v68 ? v68[75] : 0;
      v70 = v68 ? v68[73] : 0;
      v71 = v68 ? v68[74] : 0;
      v72 = v68 ? v68[72] : 0;
      v73 = v69;
      v27 = a5;
      AuthzBasepEvaluateAceCondition(
        v19,
        *(_DWORD *)(v19 + 476),
        *a5,
        v72,
        v71,
        v70,
        v73,
        &v25[4 * v67 + 8],
        *((unsigned __int16 *)v25 + 1) - 4 * v67 - 8,
        1u,
        a11,
        &v77);
      if ( v77 != 1 && v77 != -1 )
      {
LABEL_167:
        v24 = v74;
        goto LABEL_48;
      }
      v46 = SepSidInToken(v19, 0, (int)(v25 + 8), 1, a11);
      v24 = v74;
      goto LABEL_79;
    }
    v54 = v25[9] + 2;
    if ( *((unsigned __int16 *)v25 + 1) - 4 * v54 == 8 )
    {
      v24 = v74;
      goto LABEL_30;
    }
    if ( v78 && !*v27 )
    {
      AuthzBasepInitializeResourceClaimsFromSacl(v78, (int)v27);
      LOBYTE(v15) = a11;
    }
    v55 = *(_DWORD **)(v19 + 636);
    if ( v55 )
      v56 = v55[75];
    else
      v56 = 0;
    if ( v55 )
      v57 = v55[73];
    else
      v57 = 0;
    if ( v55 )
      v58 = v55[74];
    else
      v58 = 0;
    if ( v55 )
      v59 = v55[72];
    else
      v59 = 0;
    AuthzBasepEvaluateAceCondition(
      v19,
      *(_DWORD *)(v19 + 476),
      *a5,
      v59,
      v58,
      v57,
      v56,
      &v25[4 * v54 + 8],
      *((unsigned __int16 *)v25 + 1) - 4 * v54 - 8,
      0,
      v15,
      &v77);
    if ( v77 != 1 )
    {
LABEL_136:
      v24 = v74;
      goto LABEL_28;
    }
    if ( v76 && !a11 )
    {
      v60 = SePackagePrefixSid;
      if ( v25[9] >= 2u
        && v25[8] == *(unsigned __int8 *)SePackagePrefixSid
        && RtlCompareMemory(v25 + 10, SePackagePrefixSid + 2, 6) == 6 )
      {
        v61 = *((_DWORD *)v25 + 4);
        if ( v61 == *(_DWORD *)(v60 + 8) )
        {
          v62 = *((_DWORD *)v25 + 1);
          if ( v61 == 2 && v25[9] == 2 && *((_DWORD *)v25 + 5) == 1 )
          {
            v63 = *(_DWORD *)(a14 + 4) | v62;
          }
          else
          {
            *(_BYTE *)(a14 + 16) = 1;
            if ( (*(_DWORD *)(v19 + 176) & 0x4000) == 0
              || !RtlEqualSid(*(unsigned __int16 **)(v19 + 480), (unsigned __int16 *)v25 + 4) )
            {
              goto LABEL_134;
            }
            v63 = *(_DWORD *)(a14 + 4) | v62;
          }
          *(_DWORD *)(a14 + 4) = v63;
          *(_BYTE *)(a14 + 17) = 1;
LABEL_134:
          v64 = *(_DWORD *)(a14 + 4);
LABEL_135:
          *(_DWORD *)a14 &= ~v64;
          goto LABEL_136;
        }
      }
      v65 = SeCapabilityPrefixSid;
      if ( v25[9] >= 2u
        && v25[8] == *(unsigned __int8 *)SeCapabilityPrefixSid
        && RtlCompareMemory(v25 + 10, SeCapabilityPrefixSid + 2, 6) == 6
        && *((_DWORD *)v25 + 4) == *(_DWORD *)(v65 + 8) )
      {
        v66 = *((_DWORD *)v25 + 1);
        if ( SepSidInTokenSidHash(v19 + 492, 0, (unsigned __int16 *)v25 + 4, 0, 1, 0) )
        {
          *(_DWORD *)(a14 + 8) |= v66;
          *(_BYTE *)(a14 + 18) = 1;
        }
        v64 = *(_DWORD *)(a14 + 8);
        goto LABEL_135;
      }
    }
    v42 = SepSidInToken(v19, 0, (int)(v25 + 8), 0, a11);
    v24 = v74;
    goto LABEL_61;
  }
LABEL_31:
  if ( v15 && a7 )
  {
    do
    {
      v16[7] = v16[6] & (~a10 | v16[7]);
      v16 += 11;
      --v17;
    }
    while ( v17 );
  }
  return result;
}
