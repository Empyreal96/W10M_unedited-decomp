// SepNormalAccessCheckEx 
 
int __fastcall SepNormalAccessCheckEx(int result, int a2, int a3, int a4, int a5, int *a6, int a7, unsigned int a8, int a9, int a10, unsigned __int8 a11, unsigned __int8 a12, char a13, int a14)
{
  int v15; // r4
  int v17; // r1
  bool v18; // zf
  unsigned int v19; // r10
  unsigned int v20; // r3
  int v21; // r6
  int v22; // r3
  unsigned int v23; // r2
  int v24; // lr
  unsigned __int8 *v25; // r4
  int *v26; // r2
  int v27; // r5
  int v28; // r8
  int v29; // r3
  int v30; // r5
  int v31; // r2
  int v32; // r5
  int v33; // r2
  int v34; // r5
  int v35; // r5
  int v36; // r0
  unsigned int v37; // r5
  _DWORD *v38; // r2
  int v39; // r1
  int v40; // r1
  unsigned __int8 *v41; // r5
  int v42; // r2
  int v43; // r3
  int v44; // r2
  int v45; // r3
  int v46; // r2
  int v47; // r3
  int *v48; // r1
  int v49; // r4
  int v50; // r2
  int v51; // r3
  int v52; // r2
  int v53; // r3
  int v54; // r2
  int v55; // r8
  _DWORD *v56; // r3
  int v57; // r5
  int v58; // r0
  int v59; // r1
  int v60; // r3
  char v61; // r5
  int v62; // r5
  int v63; // r2
  int v64; // r5
  int v65; // r8
  int *v66; // lr
  _DWORD *v67; // r3
  int v68; // r5
  int v69; // r0
  int v70; // r1
  int v71; // r3
  int v72; // r2
  int v73; // r3
  unsigned int *v74; // r1
  int v75; // r4
  int v76; // r2
  int v77; // [sp+20h] [bp-40h]
  unsigned int v78; // [sp+24h] [bp-3Ch]
  int v79; // [sp+28h] [bp-38h]
  int v80; // [sp+2Ch] [bp-34h] BYREF
  int v81; // [sp+30h] [bp-30h]
  int v82; // [sp+34h] [bp-2Ch] BYREF
  unsigned int v83; // [sp+38h] [bp-28h]
  int v84; // [sp+3Ch] [bp-24h]

  v15 = *(_DWORD *)(a2 + 176);
  v17 = 0;
  v18 = (v15 & 0x2000) == 0;
  if ( (v15 & 0x2000) == 0 )
    v15 = 1;
  v19 = a8;
  if ( !v18 )
    v15 = 0;
  v79 = 0;
  v20 = *(unsigned __int16 *)(a4 + 4);
  v81 = v15;
  v83 = v20;
  v84 = a3;
  v21 = a9;
  v77 = 0;
  if ( a8 )
  {
    v22 = a9;
    v23 = a8;
    do
    {
      *(_DWORD *)(v22 + 24) = result;
      v22 += 44;
      --v23;
    }
    while ( v23 );
  }
  v24 = a11;
  if ( v15 && !a11 )
  {
    v17 = *(_DWORD *)a14 | result;
    v77 = v17;
    v79 = v17;
  }
  v78 = 0;
  v25 = (unsigned __int8 *)(a4 + 8);
  if ( !v83 )
  {
    v37 = 0;
    goto LABEL_50;
  }
  result = a12;
  v26 = a6;
  v27 = 0;
  while ( 1 )
  {
    v28 = *(_DWORD *)(a9 + 24);
    if ( !v28 && !v17 )
      goto LABEL_49;
    if ( (v25[1] & 8) == 0 && (v28 || !*v25 || *v25 == 9) )
      break;
LABEL_48:
    v27 = ++v78;
    v25 += *((unsigned __int16 *)v25 + 1);
    if ( v78 >= v83 )
      goto LABEL_49;
  }
  v29 = *v25;
  if ( !*v25 )
  {
    if ( v81 && !v24 && v17 )
    {
      v30 = SePackagePrefixSid;
      if ( v25[9] >= 2u
        && v25[8] == *(unsigned __int8 *)SePackagePrefixSid
        && RtlCompareMemory(v25 + 10, SePackagePrefixSid + 2, 6) == 6 )
      {
        v31 = *((_DWORD *)v25 + 4);
        if ( v31 == *(_DWORD *)(v30 + 8) )
        {
          v32 = *((_DWORD *)v25 + 1);
          if ( v31 == 2 && v25[9] == 2 && *((_DWORD *)v25 + 5) == 1 )
          {
LABEL_32:
            *(_DWORD *)(a14 + 4) |= v32 & v79;
            *(_BYTE *)(a14 + 17) = 1;
LABEL_33:
            v33 = *(_DWORD *)(a14 + 4);
LABEL_34:
            v17 = v77 & ~v33;
            *(_DWORD *)a14 &= ~v33;
            v77 = v17;
LABEL_47:
            v24 = a11;
            result = a12;
            v26 = a6;
            goto LABEL_48;
          }
LABEL_30:
          *(_BYTE *)(a14 + 16) = 1;
          if ( (*(_DWORD *)(a2 + 176) & 0x4000) == 0
            || !RtlEqualSid(*(unsigned __int16 **)(a2 + 480), (unsigned __int16 *)v25 + 4) )
          {
            goto LABEL_33;
          }
          goto LABEL_32;
        }
      }
      v34 = SeCapabilityPrefixSid;
      if ( v25[9] >= 2u
        && v25[8] == *(unsigned __int8 *)SeCapabilityPrefixSid
        && RtlCompareMemory(v25 + 10, SeCapabilityPrefixSid + 2, 6) == 6
        && *((_DWORD *)v25 + 4) == *(_DWORD *)(v34 + 8) )
      {
        goto LABEL_39;
      }
    }
    if ( !v28 )
    {
      v24 = a11;
      result = a12;
      v26 = a6;
LABEL_178:
      v17 = v77;
      goto LABEL_48;
    }
    v36 = SepSidInToken(a2, 0, (int)(v25 + 8), 0, a11);
    goto LABEL_44;
  }
  switch ( v29 )
  {
    case 5:
      v40 = *((_DWORD *)v25 + 2);
      v41 = v25 + 12;
      if ( (v40 & 1) == 0 )
        v41 = 0;
      if ( v41 )
      {
        if ( !a10 )
          goto LABEL_178;
        if ( (v40 & 1) != 0 )
          v44 = 16;
        else
          v44 = 0;
        if ( (v40 & 2) != 0 )
          v45 = 16;
        else
          v45 = 0;
        if ( SepSidInToken(a2, 0, (int)&v25[v45 + 12 + v44], 0, v24) && AuthzBasepObjectInTypeList(v41, a9, a8, &v80) )
          AuthzBasepAddAccessTypeList(a9, a8, v80, v78, *((_DWORD *)v25 + 1), 0);
        goto LABEL_46;
      }
      if ( (v40 & 1) != 0 )
        v42 = 16;
      else
        v42 = 0;
      if ( (v40 & 2) != 0 )
        v43 = 16;
      else
        v43 = 0;
      v36 = SepSidInToken(a2, 0, (int)&v25[v43 + 12 + v42], 0, v24);
      goto LABEL_44;
    case 4:
      if ( SepSidInToken(a2, 0, (int)&v25[4 * v25[13] + 20], 0, v24) && SepSidInToken(v84, 0, (int)(v25 + 12), 0, a11) )
        AuthzBasepAddAccessTypeList(a9, a8, 0, v27, *((_DWORD *)v25 + 1), 0);
      goto LABEL_46;
    case 1:
      result = SepSidInToken(a2, 0, (int)(v25 + 8), 1, v24);
      if ( result )
      {
        v46 = *(_DWORD *)(a9 + 24);
        v47 = *((_DWORD *)v25 + 1);
        if ( (v46 & v47) != 0 )
        {
          v48 = *(int **)(a9 + 40);
          v49 = v46 & v47;
          v50 = 1;
          if ( v48 )
          {
            result = 0x20000;
            while ( v50 )
            {
              if ( (v50 & v49) != 0 && !*v48 )
                *v48 = v27 | 0x20000;
              ++v48;
              v50 *= 2;
            }
          }
LABEL_49:
          v37 = v78;
          goto LABEL_50;
        }
      }
      goto LABEL_46;
    case 6:
      v51 = *((_DWORD *)v25 + 2);
      if ( (v51 & 1) != 0 )
        v52 = 16;
      else
        v52 = 0;
      if ( (v51 & 2) != 0 )
        v53 = 16;
      else
        v53 = 0;
      if ( SepSidInToken(a2, 0, (int)&v25[v53 + 12 + v52], 1, v24) )
      {
        result = (int)(v25 + 12);
        if ( (*((_DWORD *)v25 + 2) & 1) == 0 )
          result = 0;
        if ( !result || !a10 )
        {
          v54 = *(_DWORD *)(a9 + 24);
LABEL_108:
          if ( (v54 & *((_DWORD *)v25 + 1)) != 0 )
            goto LABEL_49;
          goto LABEL_46;
        }
        result = AuthzBasepObjectInTypeList(result, a9, a8, &v80);
        if ( result )
        {
          v54 = *(_DWORD *)(a9 + 44 * v80 + 24);
          goto LABEL_108;
        }
      }
LABEL_46:
      v17 = v77;
      goto LABEL_47;
    case 9:
      v55 = v25[9] + 2;
      if ( *((unsigned __int16 *)v25 + 1) - 4 * v55 == 8 )
        goto LABEL_48;
      if ( a5 && !*v26 )
      {
        AuthzBasepInitializeResourceClaimsFromSacl(a5, (int)v26);
        LOBYTE(v24) = a11;
      }
      v56 = *(_DWORD **)(a2 + 636);
      if ( v56 )
        v57 = v56[75];
      else
        v57 = 0;
      if ( v56 )
        v58 = v56[73];
      else
        v58 = 0;
      if ( v56 )
        v59 = v56[74];
      else
        v59 = 0;
      if ( v56 )
        v60 = v56[72];
      else
        v60 = 0;
      AuthzBasepEvaluateAceCondition(
        a2,
        *(_DWORD *)(a2 + 476),
        *a6,
        v60,
        v59,
        v58,
        v57,
        &v25[4 * v55 + 8],
        *((unsigned __int16 *)v25 + 1) - 4 * v55 - 8,
        0,
        v24,
        &v82);
      if ( v82 == 1 )
      {
        v61 = a11;
        if ( v81 && !a11 && v77 )
        {
          v62 = SePackagePrefixSid;
          if ( v25[9] >= 2u
            && v25[8] == *(unsigned __int8 *)SePackagePrefixSid
            && RtlCompareMemory(v25 + 10, SePackagePrefixSid + 2, 6) == 6 )
          {
            v63 = *((_DWORD *)v25 + 4);
            if ( v63 == *(_DWORD *)(v62 + 8) )
            {
              v32 = *((_DWORD *)v25 + 1);
              if ( v63 == 2 && v25[9] == 2 && *((_DWORD *)v25 + 5) == 1 )
              {
                *(_DWORD *)(a14 + 4) |= v32 & v79;
                *(_BYTE *)(a14 + 17) = 1;
                goto LABEL_33;
              }
              goto LABEL_30;
            }
          }
          v64 = SeCapabilityPrefixSid;
          if ( v25[9] >= 2u
            && v25[8] == *(unsigned __int8 *)SeCapabilityPrefixSid
            && RtlCompareMemory(v25 + 10, SeCapabilityPrefixSid + 2, 6) == 6
            && *((_DWORD *)v25 + 4) == *(_DWORD *)(v64 + 8) )
          {
LABEL_39:
            v35 = *((_DWORD *)v25 + 1);
            if ( SepSidInTokenSidHash(a2 + 492, 0, (unsigned __int16 *)v25 + 4, 0, 1, 0) )
            {
              *(_DWORD *)(a14 + 8) |= v35 & v79;
              *(_BYTE *)(a14 + 18) = 1;
            }
            v33 = *(_DWORD *)(a14 + 8);
            goto LABEL_34;
          }
          v61 = 0;
        }
        if ( *(_DWORD *)(a9 + 24) )
        {
          v36 = SepSidInToken(a2, 0, (int)(v25 + 8), 0, v61);
LABEL_44:
          if ( v36 )
            AuthzBasepAddAccessTypeList(a9, a8, 0, v78, *((_DWORD *)v25 + 1), 0);
          goto LABEL_46;
        }
      }
      goto LABEL_46;
  }
  if ( !a13 || v29 != 10 )
    goto LABEL_48;
  if ( (unsigned int)KeGetCurrentIrql(result) >= 2 )
    goto LABEL_46;
  v65 = v25[9] + 2;
  if ( *((unsigned __int16 *)v25 + 1) - 4 * v65 == 8 )
    goto LABEL_46;
  v66 = a6;
  if ( a5 && !*a6 )
  {
    AuthzBasepInitializeResourceClaimsFromSacl(a5, (int)a6);
    v66 = a6;
  }
  v67 = *(_DWORD **)(a2 + 636);
  v68 = v67 ? v67[75] : 0;
  v69 = v67 ? v67[73] : 0;
  v70 = v67 ? v67[74] : 0;
  v71 = v67 ? v67[72] : 0;
  AuthzBasepEvaluateAceCondition(
    a2,
    *(_DWORD *)(a2 + 476),
    *v66,
    v71,
    v70,
    v69,
    v68,
    &v25[4 * v65 + 8],
    *((unsigned __int16 *)v25 + 1) - 4 * v65 - 8,
    1u,
    a11,
    &v82);
  if ( v82 != 1 && v82 != -1 )
    goto LABEL_46;
  result = SepSidInToken(a2, 0, (int)(v25 + 8), 1, a11);
  if ( !result )
    goto LABEL_46;
  v72 = *(_DWORD *)(a9 + 24);
  v73 = *((_DWORD *)v25 + 1);
  if ( (v72 & v73) == 0 )
    goto LABEL_46;
  v74 = *(unsigned int **)(a9 + 40);
  v75 = v72 & v73;
  v37 = v78;
  v76 = 1;
  if ( v74 )
  {
    result = 0x20000;
    while ( v76 )
    {
      if ( (v76 & v75) != 0 && !*v74 )
        *v74 = v78 | 0x20000;
      ++v74;
      v76 *= 2;
    }
  }
LABEL_50:
  if ( v37 == v83 && *(_DWORD *)(a9 + 24) && a8 )
  {
    do
    {
      v38 = *(_DWORD **)(v21 + 40);
      result = *(_DWORD *)(v21 + 24);
      v39 = 1;
      if ( v38 )
      {
        while ( v39 )
        {
          if ( (v39 & result) != 0 && !*v38 )
            *v38 = 0x800000;
          ++v38;
          v39 *= 2;
        }
      }
      v21 += 44;
      --v19;
    }
    while ( v19 );
  }
  return result;
}
