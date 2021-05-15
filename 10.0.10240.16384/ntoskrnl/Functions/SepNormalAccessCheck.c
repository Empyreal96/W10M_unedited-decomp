// SepNormalAccessCheck 
 
int __fastcall SepNormalAccessCheck(int result, int a2, int a3, int a4, int a5, int *a6, unsigned __int16 *a7, unsigned int a8, int a9, int a10, unsigned __int8 a11, char a12, int a13)
{
  int v13; // r4
  int v14; // r2
  BOOL v16; // r1
  unsigned int v17; // r4
  unsigned int v18; // r7
  int v19; // r10
  int v20; // r3
  unsigned int v21; // r2
  int v22; // lr
  unsigned int v23; // r9
  unsigned __int8 *v24; // r3
  int v25; // r6
  unsigned __int8 *v26; // r8
  int v27; // r3
  unsigned int *v28; // r5
  unsigned __int16 *v29; // r7
  int v30; // r3
  int v31; // r10
  int v32; // r9
  int v33; // lr
  unsigned int v34; // r0
  unsigned int v35; // r8
  unsigned int v36; // r6
  int v37; // r4
  unsigned __int16 **v38; // r5
  unsigned int v39; // r1
  unsigned __int16 *v40; // t1
  unsigned __int16 **v41; // r2
  int v42; // r4
  unsigned int v43; // r5
  int v44; // r7
  unsigned __int16 *v45; // r1
  unsigned __int8 *v46; // r1
  int v47; // r0
  int v48; // r2
  int v49; // t1
  unsigned __int8 *v50; // r1
  int v51; // r0
  int v52; // r2
  int v53; // t1
  int v54; // r3
  int v55; // r2
  int v56; // r4
  _DWORD *v57; // r8
  int v58; // r6
  int v59; // r4
  int v60; // r2
  int v61; // r7
  _DWORD *v62; // r3
  int v63; // r6
  int v64; // r5
  int v65; // r4
  int v66; // r3
  int v67; // r0
  int v68; // r4
  int v69; // r4
  int v70; // r4
  int v71; // r2
  int v72; // r2
  int v73; // r4
  _DWORD *v74; // r8
  int v75; // r6
  int v76; // r6
  int v77; // r3
  int v78; // r3
  int v79; // r2
  int v80; // r3
  int v81; // r3
  int v82; // r2
  int v83; // r3
  int v84; // [sp+20h] [bp-58h]
  BOOL v85; // [sp+24h] [bp-54h]
  unsigned int v86; // [sp+28h] [bp-50h]
  unsigned int v88; // [sp+30h] [bp-48h]
  int v89; // [sp+34h] [bp-44h]
  unsigned __int8 *v90; // [sp+38h] [bp-40h]
  unsigned int v91; // [sp+3Ch] [bp-3Ch]
  unsigned int *v92; // [sp+40h] [bp-38h]
  int v93; // [sp+44h] [bp-34h] BYREF
  int v94; // [sp+48h] [bp-30h]
  int v95; // [sp+4Ch] [bp-2Ch]
  int v96; // [sp+50h] [bp-28h] BYREF
  int v97; // [sp+54h] [bp-24h]

  v13 = *(_DWORD *)(a2 + 176);
  v97 = a3;
  v14 = 0;
  v84 = 0;
  v89 = 0;
  v16 = (v13 & 0x2000) == 0;
  v17 = *(unsigned __int16 *)(a4 + 4);
  v18 = a8;
  v19 = a9;
  v85 = v16;
  v86 = v17;
  v96 = -1;
  if ( a8 )
  {
    v20 = a9;
    v21 = a8;
    do
    {
      *(_DWORD *)(v20 + 24) = result;
      v20 += 44;
      --v21;
    }
    while ( v21 );
    v14 = 0;
  }
  v22 = a11;
  if ( v16 && !a11 )
  {
    v14 = *(_DWORD *)a13 | result;
    v84 = v14;
    v89 = v14;
  }
  v23 = 0;
  v24 = (unsigned __int8 *)(a4 + 8);
  v88 = 0;
  v90 = (unsigned __int8 *)(a4 + 8);
  if ( v17 )
  {
    result = (int)a7;
    while ( 1 )
    {
      v25 = *(_DWORD *)(v19 + 24);
      v95 = v25;
      if ( !v25 && !v14 )
        return result;
      if ( (v24[1] & 8) == 0 )
      {
        v26 = v90;
        if ( v25 || !*v90 || *v90 == 9 )
          break;
      }
LABEL_44:
      v88 = ++v23;
      v90 += *((unsigned __int16 *)v90 + 1);
      v18 = a8;
      v24 = v90;
      v22 = a11;
      if ( v23 >= v17 )
        return result;
    }
    v27 = *v90;
    if ( *v90 )
    {
      if ( v27 == 5 )
      {
        v77 = *((_DWORD *)v90 + 2);
        if ( (v77 & 1) != 0 )
        {
          if ( v90 != (unsigned __int8 *)-12 )
          {
            if ( !a10 )
            {
              v17 = v86;
              goto LABEL_43;
            }
            if ( (v77 & 2) != 0 )
              v78 = 16;
            else
              v78 = 0;
            if ( SepSidInToken(a2, result, (int)&v90[v78 + 28], 0, v22)
              && AuthzBasepObjectInTypeList(v90 + 12, v19, v18, &v93) )
            {
              AuthzBasepAddAccessTypeList(v19, v18, v93, v23, *((_DWORD *)v90 + 1), 0);
            }
            goto LABEL_41;
          }
          v17 = v86;
        }
        if ( (v77 & 1) != 0 )
          v79 = 16;
        else
          v79 = 0;
        if ( (v77 & 2) != 0 )
          v80 = 16;
        else
          v80 = 0;
        if ( !SepSidInToken(a2, result, (int)&v90[v80 + 12 + v79], 0, v22) )
          goto LABEL_42;
        if ( v18 == 1 )
        {
          *(_DWORD *)(v19 + 24) &= ~*((_DWORD *)v90 + 1);
          goto LABEL_42;
        }
      }
      else
      {
        if ( v27 != 4 )
        {
          switch ( v27 )
          {
            case 1:
              result = SepSidInToken(a2, result, (int)(v90 + 8), 1, v22);
              if ( !result )
                goto LABEL_42;
              break;
            case 6:
              v81 = *((_DWORD *)v90 + 2);
              if ( (v81 & 1) != 0 )
                v82 = 16;
              else
                v82 = 0;
              if ( (v81 & 2) != 0 )
                v83 = 16;
              else
                v83 = 0;
              result = SepSidInToken(a2, result, (int)&v90[v83 + 12 + v82], 1, v22);
              if ( !result )
                goto LABEL_42;
              if ( (*((_DWORD *)v90 + 2) & 1) != 0 )
              {
                result = (int)(v90 + 12);
                if ( v90 != (unsigned __int8 *)-12 )
                {
                  if ( a10 )
                  {
                    result = AuthzBasepObjectInTypeList(result, v19, v18, &v93);
                    if ( result && (*(_DWORD *)(v19 + 44 * v93 + 24) & *((_DWORD *)v90 + 1)) != 0 )
                      return result;
                    goto LABEL_42;
                  }
                }
              }
              break;
            case 9:
              v61 = v90[9] + 2;
              if ( *((unsigned __int16 *)v90 + 1) - 4 * v61 == 8 )
                goto LABEL_44;
              if ( a5 && !*a6 )
              {
                AuthzBasepInitializeResourceClaimsFromSacl(a5, (int)a6);
                LOBYTE(v22) = a11;
              }
              v62 = *(_DWORD **)(a2 + 636);
              if ( v62 )
                v63 = v62[75];
              else
                v63 = 0;
              if ( v62 )
                v64 = v62[73];
              else
                v64 = 0;
              if ( v62 )
                v65 = v62[74];
              else
                v65 = 0;
              if ( v62 )
                v66 = v62[72];
              else
                v66 = 0;
              AuthzBasepEvaluateAceCondition(
                a2,
                *(_DWORD *)(a2 + 476),
                *a6,
                v66,
                v65,
                v64,
                v63,
                &v90[4 * v61 + 8],
                *((unsigned __int16 *)v90 + 1) - 4 * v61 - 8,
                0,
                v22,
                &v96);
              if ( v96 != 1 )
                goto LABEL_41;
              if ( v85 && !a11 && v84 )
              {
                v68 = SePackagePrefixSid;
                if ( v90[9] >= 2u && v90[8] == *(unsigned __int8 *)SePackagePrefixSid && RtlCompareMemory(v90 + 10) == 6 )
                {
                  v72 = *((_DWORD *)v90 + 4);
                  if ( v72 == *(_DWORD *)(v68 + 8) )
                  {
                    v73 = *((_DWORD *)v90 + 1);
                    if ( v72 == 2 && v90[9] == 2 && *((_DWORD *)v90 + 5) == 1 )
                    {
                      *(_DWORD *)(a13 + 4) |= v73 & v89;
                      *(_BYTE *)(a13 + 17) = 1;
                      v76 = v84 & ~*(_DWORD *)(a13 + 4);
                      *(_DWORD *)a13 &= ~*(_DWORD *)(a13 + 4);
                      v84 = v76;
                    }
                    else
                    {
                      *(_BYTE *)(a13 + 16) = 1;
                      if ( (*(_DWORD *)(a2 + 176) & 0x4000) != 0 )
                      {
                        v74 = (_DWORD *)a13;
                        if ( RtlEqualSid(*(unsigned __int16 **)(a2 + 480), (unsigned __int16 *)v90 + 4) )
                        {
                          *(_DWORD *)(a13 + 4) |= v73 & v89;
                          *(_BYTE *)(a13 + 17) = 1;
                        }
                      }
                      else
                      {
                        v74 = (_DWORD *)a13;
                      }
                      v75 = v84 & ~v74[1];
                      *v74 &= ~v74[1];
                      v84 = v75;
                    }
                    goto LABEL_41;
                  }
                }
                v69 = SeCapabilityPrefixSid;
                if ( v90[9] >= 2u
                  && v90[8] == *(unsigned __int8 *)SeCapabilityPrefixSid
                  && RtlCompareMemory(v90 + 10) == 6
                  && *((_DWORD *)v90 + 4) == *(_DWORD *)(v69 + 8) )
                {
                  v70 = *((_DWORD *)v90 + 1);
                  if ( SepSidInTokenSidHash(a2 + 492, 0, (unsigned __int16 *)v90 + 4, 0, 1, 0) )
                  {
                    *(_DWORD *)(a13 + 8) |= v70 & v89;
                    *(_BYTE *)(a13 + 18) = 1;
                  }
                  v71 = *(_DWORD *)(a13 + 8);
                  *(_DWORD *)a13 &= ~v71;
                  v84 &= ~v71;
                  goto LABEL_41;
                }
              }
              if ( *(_DWORD *)(v19 + 24) )
              {
                v67 = a11 ? a2 + 340 : a2 + 204;
                if ( SepSidInTokenSidHash(v67, a7, (unsigned __int16 *)v90 + 4, 0, a11, a12) )
                  AuthzBasepAddAccessTypeList(v19, a8, 0, v23, *((_DWORD *)v90 + 1), 0);
              }
              goto LABEL_41;
            default:
              goto LABEL_44;
          }
          if ( (*((_DWORD *)v90 + 1) & *(_DWORD *)(v19 + 24)) != 0 )
            return result;
          goto LABEL_42;
        }
        if ( !SepSidInToken(a2, result, (int)&v90[4 * v90[13] + 20], 0, v22)
          || !SepSidInToken(v97, 0, (int)(v90 + 12), 0, a11) )
        {
          goto LABEL_42;
        }
        if ( v18 == 1 )
        {
          *(_DWORD *)(v19 + 24) &= ~*((_DWORD *)v90 + 1);
          goto LABEL_42;
        }
      }
      AuthzBasepAddAccessTypeList(v19, v18, 0, v23, *((_DWORD *)v90 + 1), 0);
      goto LABEL_42;
    }
    if ( v16 && v14 && !v22 )
    {
      if ( v90[9] >= 2u && v90[8] == *(unsigned __int8 *)SePackagePrefixSid )
      {
        v46 = v90 + 10;
        v47 = 6;
        do
        {
          v48 = v46[SePackagePrefixSid - (_DWORD)(v90 + 10) + 2];
          v49 = *v46++;
          if ( v49 != v48 )
            break;
          --v47;
        }
        while ( v47 );
        if ( v47 == 0 )
        {
          v55 = *((_DWORD *)v90 + 4);
          if ( v55 == *(_DWORD *)(SePackagePrefixSid + 8) )
          {
            v56 = *((_DWORD *)v90 + 1);
            if ( v55 == 2 && v90[9] == 2 && *((_DWORD *)v90 + 5) == 1 )
            {
              v57 = (_DWORD *)a13;
              *(_DWORD *)(a13 + 4) |= v56 & v89;
              *(_BYTE *)(a13 + 17) = 1;
            }
            else
            {
              *(_BYTE *)(a13 + 16) = 1;
              if ( (*(_DWORD *)(a2 + 176) & 0x4000) == 0 )
                return sub_52E11C();
              v57 = (_DWORD *)a13;
              if ( RtlEqualSid(*(unsigned __int16 **)(a2 + 480), (unsigned __int16 *)v90 + 4) )
              {
                *(_DWORD *)(a13 + 4) |= v56 & v89;
                *(_BYTE *)(a13 + 17) = 1;
              }
            }
            v58 = v84 & ~v57[1];
            *v57 &= ~v57[1];
            v84 = v58;
            goto LABEL_41;
          }
        }
      }
      if ( v90[9] >= 2u && v90[8] == *(unsigned __int8 *)SeCapabilityPrefixSid )
      {
        v50 = v90 + 10;
        v51 = 6;
        do
        {
          v52 = v50[SeCapabilityPrefixSid - (_DWORD)(v90 + 10) + 2];
          v53 = *v50++;
          if ( v53 != v52 )
            break;
          --v51;
        }
        while ( v51 );
        if ( v51 == 0 && *((_DWORD *)v90 + 4) == *(_DWORD *)(SeCapabilityPrefixSid + 8) )
        {
          v59 = *((_DWORD *)v90 + 1);
          if ( SepSidInTokenSidHash(a2 + 492, 0, (unsigned __int16 *)v90 + 4, 0, 1, 0) )
          {
            *(_DWORD *)(a13 + 8) |= v59 & v89;
            *(_BYTE *)(a13 + 18) = 1;
          }
          v60 = *(_DWORD *)(a13 + 8);
          *(_DWORD *)a13 &= ~v60;
          v84 &= ~v60;
          goto LABEL_41;
        }
      }
      v17 = v86;
    }
    if ( !v25 )
    {
LABEL_42:
      result = (int)a7;
      v16 = v85;
LABEL_43:
      v14 = v84;
      goto LABEL_44;
    }
    if ( v22 )
      v28 = (unsigned int *)(a2 + 340);
    else
      v28 = (unsigned int *)(a2 + 204);
    v29 = (unsigned __int16 *)(v90 + 8);
    v91 = (unsigned int)(v90 + 8);
    v92 = v28;
    if ( a7 && RtlEqualSid((unsigned __int16 *)SePrincipalSelfSid, (unsigned __int16 *)v90 + 4) )
    {
      v29 = a7;
      v91 = (unsigned int)a7;
    }
    if ( a12
      && *(unsigned __int16 *)SeOwnerRightsSid == *v29
      && !memcmp(SeOwnerRightsSid, (unsigned int)v29, 4 * (*(unsigned __int8 *)(SeOwnerRightsSid + 1) + 2)) )
    {
      goto LABEL_39;
    }
    if ( !v28 || !v29 )
      goto LABEL_42;
    v30 = *((unsigned __int8 *)v29 + 1);
    v31 = *v29;
    v32 = 0;
    v33 = v30 + 2;
    v34 = LOBYTE(v29[2 * v30 + 2]);
    v94 = v30 + 2;
    v35 = v28[(v34 >> 4) + 18] & v28[(v34 & 0xF) + 2];
    if ( v35 )
    {
      do
      {
        v42 = (unsigned __int8)v35;
        if ( (_BYTE)v35 )
        {
          v43 = v28[1];
          do
          {
            v44 = *((unsigned __int8 *)SidHashByteToIndexLookupTable + v42);
            v45 = *(unsigned __int16 **)(v43 + 8 * (v44 + v32));
            if ( *v45 == v31 )
            {
              if ( !memcmp(v91, (unsigned int)v45, 4 * v33) )
              {
                v41 = (unsigned __int16 **)(v43 + 8 * (v44 + v32));
                goto LABEL_34;
              }
              v33 = v94;
            }
            v54 = (1 << v44) ^ v42;
            v42 = (unsigned __int8)v54;
          }
          while ( (_BYTE)v54 );
          v28 = v92;
        }
        v32 = (unsigned __int8)(v32 + 8);
        v35 >>= 8;
      }
      while ( v35 );
      v29 = (unsigned __int16 *)v91;
    }
    v36 = *v28;
    if ( *v28 <= 0x20 )
      goto LABEL_63;
    v37 = 32;
    if ( v36 <= 0x20 )
      goto LABEL_63;
    v38 = (unsigned __int16 **)(v28[1] + 256);
    while ( 1 )
    {
      v40 = *v38;
      v38 += 2;
      v39 = (unsigned int)v40;
      if ( *v40 == v31 && !memcmp((unsigned int)v29, v39, 4 * v33) )
        break;
      if ( ++v37 >= v36 )
        goto LABEL_63;
      v33 = v94;
    }
    v41 = v38 - 2;
LABEL_34:
    if ( v41 )
    {
      if ( !a11 && v41 == (unsigned __int16 **)v92[1] && ((unsigned int)v41[1] & 0x10) == 0 )
      {
        v23 = v88;
        v19 = a9;
        goto LABEL_38;
      }
      v23 = v88;
      v19 = a9;
      if ( ((unsigned int)v41[1] & 4) != 0 )
      {
LABEL_38:
        v25 = v95;
        v26 = v90;
LABEL_39:
        if ( a8 == 1 )
          *(_DWORD *)(v19 + 24) = v25 & ~*((_DWORD *)v26 + 1);
        else
          AuthzBasepAddAccessTypeList(v19, a8, 0, v23, *((_DWORD *)v26 + 1), 0);
        goto LABEL_41;
      }
    }
    else
    {
LABEL_63:
      v23 = v88;
      v19 = a9;
    }
LABEL_41:
    v17 = v86;
    goto LABEL_42;
  }
  return result;
}
