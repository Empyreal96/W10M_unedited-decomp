// SepMaximumAccessCheck 
 
int *__fastcall SepMaximumAccessCheck(int *result, int a2, int a3, int a4, int *a5, int a6, unsigned int a7, int a8, int a9, int a10, unsigned __int8 a11, char a12, int a13)
{
  int v13; // r4
  int v14; // r7
  int v15; // r9
  int v16; // r5
  int v17; // r4
  unsigned int v18; // lr
  unsigned __int8 *v19; // r8
  unsigned int v20; // r6
  int v21; // lr
  int v22; // r10
  int *v23; // r1
  int v24; // r3
  unsigned int *v25; // r5
  unsigned __int16 *v26; // r4
  unsigned int v27; // lr
  int v28; // r3
  int v29; // r10
  int v30; // r9
  unsigned int v31; // r0
  unsigned int v32; // r7
  unsigned int v33; // r6
  int v34; // r4
  unsigned __int16 **v35; // r5
  unsigned int v36; // r1
  unsigned __int16 *v37; // t1
  unsigned __int16 **v38; // r2
  int v39; // r4
  unsigned int v40; // r5
  int v41; // r8
  unsigned __int16 *v42; // r1
  int v43; // r3
  unsigned __int8 *v44; // r1
  int v45; // r0
  int v46; // r2
  int v47; // t1
  unsigned __int8 *v48; // r1
  int v49; // r4
  int v50; // r2
  int v51; // t1
  int v52; // r4
  int v53; // r2
  int v54; // r4
  int v55; // r3
  int v56; // r1
  int v57; // r5
  _DWORD *v58; // r3
  int v59; // r4
  int v60; // r0
  int v61; // r1
  int v62; // r3
  int v63; // r4
  int v64; // r4
  int v65; // r3
  int v66; // r3
  int v67; // r2
  int v68; // r3
  unsigned int v69; // r1
  int v70; // r3
  int v71; // r2
  int v72; // r3
  int v73; // r2
  int v74; // r4
  int v75; // r4
  unsigned int v76; // [sp+20h] [bp-50h]
  unsigned __int8 *v77; // [sp+24h] [bp-4Ch]
  unsigned __int16 *v78; // [sp+28h] [bp-48h]
  unsigned int *v79; // [sp+2Ch] [bp-44h]
  int v80; // [sp+30h] [bp-40h] BYREF
  int v81; // [sp+34h] [bp-3Ch]
  int v82; // [sp+38h] [bp-38h] BYREF
  int v83; // [sp+3Ch] [bp-34h]
  int v84; // [sp+40h] [bp-30h]
  int v85; // [sp+44h] [bp-2Ch]
  unsigned int v86; // [sp+48h] [bp-28h]
  int *v87; // [sp+4Ch] [bp-24h]

  v13 = result[44];
  v14 = (int)result;
  v84 = a2;
  v85 = a4;
  v87 = result;
  v15 = (v13 & 0x2000) == 0;
  v16 = a11;
  v17 = a8;
  v18 = a7;
  v82 = -1;
  v83 = v15;
  if ( a11 && a7 )
  {
    v56 = a8;
    result = (int *)a7;
    do
    {
      *(_DWORD *)(v56 + 24) = *(_DWORD *)(v56 + 28);
      *(_DWORD *)(v56 + 28) = 0;
      v56 += 44;
      result = (int *)((char *)result - 1);
    }
    while ( result );
  }
  v19 = (unsigned __int8 *)(a3 + 8);
  v20 = 0;
  v86 = *(unsigned __int16 *)(a3 + 4);
  v76 = 0;
  v77 = (unsigned __int8 *)(a3 + 8);
  if ( v86 )
  {
    result = &SePrincipalSelfSid;
    v21 = a13;
    v22 = a6;
    v23 = a5;
    while ( (v19[1] & 8) != 0 )
    {
LABEL_26:
      ++v20;
      v14 = (int)v87;
      v19 += *((unsigned __int16 *)v19 + 1);
      v76 = v20;
      v77 = v19;
      v15 = v83;
      v22 = a6;
      if ( v20 >= v86 )
      {
        v17 = a8;
        v18 = a7;
        goto LABEL_28;
      }
    }
    v24 = *v19;
    if ( !*v19 )
    {
      if ( !v15 )
      {
        if ( !v16 )
        {
LABEL_8:
          v25 = (unsigned int *)(v14 + 204);
LABEL_9:
          v26 = (unsigned __int16 *)(v19 + 8);
          v78 = (unsigned __int16 *)(v19 + 8);
          v79 = v25;
          if ( v22 && RtlEqualSid((unsigned __int16 *)SePrincipalSelfSid, (unsigned __int16 *)v19 + 4) )
          {
            v26 = (unsigned __int16 *)v22;
            v78 = (unsigned __int16 *)v22;
          }
          if ( a12 && RtlEqualSid((unsigned __int16 *)SeOwnerRightsSid, v26) )
          {
LABEL_39:
            if ( a7 != 1 )
              return (int *)sub_52D7B4();
            *(_DWORD *)(a8 + 28) |= *((_DWORD *)v19 + 1) & ~*(_DWORD *)(a8 + 32);
            goto LABEL_23;
          }
          if ( v25 )
          {
            v27 = (unsigned int)v78;
            if ( v78 )
            {
              v28 = *((unsigned __int8 *)v78 + 1);
              v29 = *v78;
              v30 = 0;
              v31 = LOBYTE(v78[2 * v28 + 2]);
              v81 = v28 + 2;
              v32 = v25[(v31 >> 4) + 18] & v25[(v31 & 0xF) + 2];
              if ( v32 )
              {
                do
                {
                  v39 = (unsigned __int8)v32;
                  if ( (_BYTE)v32 )
                  {
                    v40 = v25[1];
                    do
                    {
                      v41 = *((unsigned __int8 *)SidHashByteToIndexLookupTable + v39);
                      v42 = *(unsigned __int16 **)(v40 + 8 * (v30 + v41));
                      if ( *v42 == v29 )
                      {
                        if ( !memcmp(v27, (unsigned int)v42, 4 * v81) )
                        {
                          v38 = (unsigned __int16 **)(v40 + 8 * (v30 + v41));
                          goto LABEL_35;
                        }
                        v27 = (unsigned int)v78;
                      }
                      v43 = (1 << v41) ^ v39;
                      v39 = (unsigned __int8)v43;
                    }
                    while ( (_BYTE)v43 );
                    v25 = v79;
                  }
                  v30 = (unsigned __int8)(v30 + 8);
                  v32 >>= 8;
                }
                while ( v32 );
                v19 = v77;
              }
              v33 = *v25;
              if ( *v25 > 0x20 )
              {
                v34 = 32;
                if ( v33 > 0x20 )
                {
                  v35 = (unsigned __int16 **)(v25[1] + 256);
                  while ( 1 )
                  {
                    v37 = *v35;
                    v35 += 2;
                    v36 = (unsigned int)v37;
                    if ( *v37 == v29 && !memcmp(v27, v36, 4 * v81) )
                      break;
                    if ( ++v34 >= v33 )
                      goto LABEL_22;
                    v27 = (unsigned int)v78;
                  }
                  v38 = v35 - 2;
LABEL_35:
                  v16 = a11;
                  if ( !v38 )
                  {
                    v20 = v76;
                    v19 = v77;
                    goto LABEL_24;
                  }
                  if ( a11 || v38 != (unsigned __int16 **)v79[1] || ((unsigned int)v38[1] & 0x10) != 0 )
                  {
                    v20 = v76;
                    v19 = v77;
                    if ( ((unsigned int)v38[1] & 4) == 0 )
                      goto LABEL_24;
                  }
                  else
                  {
                    v20 = v76;
                    v19 = v77;
                  }
                  goto LABEL_39;
                }
              }
LABEL_22:
              v20 = v76;
            }
          }
LABEL_23:
          v16 = a11;
          goto LABEL_24;
        }
LABEL_75:
        v25 = (unsigned int *)(v14 + 340);
        goto LABEL_9;
      }
      if ( v16 )
        goto LABEL_75;
      if ( v19[9] < 2u || v19[8] != *(unsigned __int8 *)SePackagePrefixSid )
        goto LABEL_60;
      v44 = v19 + 10;
      v45 = 6;
      do
      {
        v46 = v44[SePackagePrefixSid - (_DWORD)(v19 + 10) + 2];
        v47 = *v44++;
        if ( v47 != v46 )
          break;
        --v45;
      }
      while ( v45 );
      if ( v45 != 0 || (v53 = *((_DWORD *)v19 + 4), v53 != *(_DWORD *)(SePackagePrefixSid + 8)) )
      {
LABEL_60:
        if ( v19[9] >= 2u && v19[8] == *(unsigned __int8 *)SeCapabilityPrefixSid )
        {
          v48 = v19 + 10;
          v49 = 6;
          do
          {
            v50 = v48[SeCapabilityPrefixSid - (_DWORD)(v19 + 10) + 2];
            v51 = *v48++;
            if ( v51 != v50 )
              break;
            --v49;
          }
          while ( v49 );
          if ( v49 == 0 && *((_DWORD *)v19 + 4) == *(_DWORD *)(SeCapabilityPrefixSid + 8) )
          {
            v52 = *((_DWORD *)v19 + 1);
            v21 = a13;
            if ( SepSidInTokenSidHash(v14 + 492, 0, (unsigned __int16 *)v19 + 4, 0, 1, 0) )
            {
              *(_DWORD *)(a13 + 8) |= v52;
              *(_BYTE *)(a13 + 18) = 1;
            }
            v16 = a11;
            *(_DWORD *)a13 &= ~*(_DWORD *)(a13 + 8);
            goto LABEL_25;
          }
        }
        goto LABEL_8;
      }
      v54 = *((_DWORD *)v19 + 1);
      if ( v53 == 2 && v19[9] == 2 && *((_DWORD *)v19 + 5) == 1 )
      {
        v55 = *(_DWORD *)(v21 + 4) | v54;
      }
      else
      {
        *(_BYTE *)(v21 + 16) = 1;
        if ( (*(_DWORD *)(v14 + 176) & 0x4000) == 0 )
          goto LABEL_74;
        v21 = a13;
        if ( !RtlEqualSid(*(unsigned __int16 **)(v14 + 480), (unsigned __int16 *)v19 + 4) )
          goto LABEL_74;
        v55 = *(_DWORD *)(a13 + 4) | v54;
      }
      *(_DWORD *)(v21 + 4) = v55;
      *(_BYTE *)(v21 + 17) = 1;
LABEL_74:
      v16 = a11;
      *(_DWORD *)v21 &= ~*(_DWORD *)(v21 + 4);
      goto LABEL_25;
    }
    switch ( v24 )
    {
      case 5:
        v65 = *((_DWORD *)v19 + 2);
        if ( (v65 & 1) != 0 && v19 != (unsigned __int8 *)-12 )
        {
          if ( !a9 )
            goto LABEL_26;
          if ( (v65 & 2) != 0 )
            v66 = 16;
          else
            v66 = 0;
          if ( SepSidInToken(v14, v22, (int)&v19[v66 + 28], 0, v16)
            && AuthzBasepObjectInTypeList(v19 + 12, a8, a7, &v80) )
          {
            AuthzBasepAddAccessTypeList(a8, a7, v80, v20, *((_DWORD *)v19 + 1), 1);
          }
          goto LABEL_24;
        }
        if ( (v65 & 1) != 0 )
          v67 = 16;
        else
          v67 = 0;
        if ( (v65 & 2) != 0 )
          v68 = 16;
        else
          v68 = 0;
        if ( !SepSidInToken(v14, v22, (int)&v19[v68 + 12 + v67], 0, v16) )
        {
LABEL_24:
          v21 = a13;
LABEL_25:
          result = &SePrincipalSelfSid;
          v23 = a5;
          goto LABEL_26;
        }
        v69 = a7;
        if ( a7 == 1 )
        {
          *(_DWORD *)(a8 + 28) |= *((_DWORD *)v19 + 1) & ~*(_DWORD *)(a8 + 32);
          goto LABEL_24;
        }
        break;
      case 4:
        if ( !SepSidInToken(v14, v22, (int)&v19[4 * v19[13] + 20], 0, v16)
          || !SepSidInToken(v84, 0, (int)(v19 + 12), 0, 0) )
        {
          goto LABEL_24;
        }
        v69 = a7;
        if ( a7 == 1 )
        {
          *(_DWORD *)(a8 + 28) |= *((_DWORD *)v19 + 1) & ~*(_DWORD *)(a8 + 32);
          goto LABEL_24;
        }
        break;
      case 1:
        if ( !SepSidInToken(v14, v22, (int)(v19 + 8), 1, v16) )
          goto LABEL_24;
LABEL_89:
        if ( a7 == 1 )
          *(_DWORD *)(a8 + 32) |= *((_DWORD *)v19 + 1) & ~*(_DWORD *)(a8 + 28);
        else
          AuthzBasepAddAccessTypeList(a8, a7, 0, v20, *((_DWORD *)v19 + 1), 2);
        goto LABEL_24;
      case 6:
        v70 = *((_DWORD *)v19 + 2);
        if ( (v70 & 1) != 0 )
          v71 = 16;
        else
          v71 = 0;
        if ( (v70 & 2) != 0 )
          v72 = 16;
        else
          v72 = 0;
        if ( !SepSidInToken(v14, v22, (int)&v19[v72 + 12 + v71], 1, v16) )
          goto LABEL_24;
        if ( (*((_DWORD *)v19 + 2) & 1) != 0 && v19 != (unsigned __int8 *)-12 )
        {
          if ( a9 )
          {
            if ( AuthzBasepObjectInTypeList(v19 + 12, a8, a7, &v80) )
              AuthzBasepAddAccessTypeList(a8, a7, v80, v20, *((_DWORD *)v19 + 1), 2);
          }
          else
          {
            *(_DWORD *)(a8 + 32) |= *((_DWORD *)v19 + 1) & ~*(_DWORD *)(a8 + 28);
          }
          goto LABEL_24;
        }
        goto LABEL_89;
      case 9:
        v57 = v19[9] + 2;
        if ( *((unsigned __int16 *)v19 + 1) - 4 * v57 - 8 <= 0 )
        {
          v16 = a11;
          goto LABEL_26;
        }
        if ( v85 && !*v23 )
          AuthzBasepInitializeResourceClaimsFromSacl(v85, (int)v23);
        v58 = *(_DWORD **)(v14 + 636);
        if ( v58 )
          v59 = v58[75];
        else
          v59 = 0;
        if ( v58 )
          v60 = v58[73];
        else
          v60 = 0;
        if ( v58 )
          v61 = v58[74];
        else
          v61 = 0;
        if ( v58 )
          v62 = v58[72];
        else
          v62 = 0;
        AuthzBasepEvaluateAceCondition(
          v14,
          *(_DWORD *)(v14 + 476),
          *a5,
          v62,
          v61,
          v60,
          v59,
          &v19[4 * v57 + 8],
          *((unsigned __int16 *)v19 + 1) - 4 * v57 - 8,
          0,
          a11,
          &v82);
        v16 = a11;
        if ( v82 != 1 )
          goto LABEL_24;
        if ( v15 && !a11 )
        {
          v63 = SePackagePrefixSid;
          if ( v19[9] >= 2u && v19[8] == *(unsigned __int8 *)SePackagePrefixSid && RtlCompareMemory(v19 + 10) == 6 )
          {
            v73 = *((_DWORD *)v19 + 4);
            if ( v73 == *(_DWORD *)(v63 + 8) )
            {
              v74 = *((_DWORD *)v19 + 1);
              if ( v73 == 2 && v19[9] == 2 && *((_DWORD *)v19 + 5) == 1 )
              {
                v21 = a13;
              }
              else
              {
                v21 = a13;
                *(_BYTE *)(a13 + 16) = 1;
                if ( (*(_DWORD *)(v14 + 176) & 0x4000) == 0 )
                  goto LABEL_167;
                v21 = a13;
                if ( !RtlEqualSid(*(unsigned __int16 **)(v14 + 480), (unsigned __int16 *)v19 + 4) )
                  goto LABEL_167;
              }
              *(_DWORD *)(v21 + 4) |= v74;
              *(_BYTE *)(v21 + 17) = 1;
LABEL_167:
              *(_DWORD *)v21 &= ~*(_DWORD *)(v21 + 4);
              goto LABEL_25;
            }
          }
          v64 = SeCapabilityPrefixSid;
          if ( v19[9] >= 2u
            && v19[8] == *(unsigned __int8 *)SeCapabilityPrefixSid
            && RtlCompareMemory(v19 + 10) == 6
            && *((_DWORD *)v19 + 4) == *(_DWORD *)(v64 + 8) )
          {
            v75 = *((_DWORD *)v19 + 1);
            v21 = a13;
            if ( SepSidInTokenSidHash(v14 + 492, 0, (unsigned __int16 *)v19 + 4, 0, 1, 0) )
            {
              *(_DWORD *)(a13 + 8) |= v75;
              *(_BYTE *)(a13 + 18) = 1;
            }
            *(_DWORD *)a13 &= ~*(_DWORD *)(a13 + 8);
            goto LABEL_25;
          }
        }
        if ( SepSidInToken(v14, v22, (int)(v19 + 8), 0, a11) )
          AuthzBasepAddAccessTypeList(a8, a7, 0, v20, *((_DWORD *)v19 + 1), 1);
        goto LABEL_24;
      default:
        goto LABEL_26;
    }
    AuthzBasepAddAccessTypeList(a8, v69, 0, v20, *((_DWORD *)v19 + 1), 1);
    goto LABEL_24;
  }
LABEL_28:
  if ( v16 && v18 )
  {
    do
    {
      *(_DWORD *)(v17 + 28) = *(_DWORD *)(v17 + 24) & (*(_DWORD *)(v17 + 28) | ~a10);
      v17 += 44;
      --v18;
    }
    while ( v18 );
  }
  return result;
}
