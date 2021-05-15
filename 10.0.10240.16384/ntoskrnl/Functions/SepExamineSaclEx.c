// SepExamineSaclEx 
 
unsigned int __fastcall SepExamineSaclEx(unsigned int result, int a2, int a3, int a4, int a5, unsigned int a6, unsigned __int8 a7, int *a8, _DWORD *a9, int a10, int a11, _BYTE *a12, _BYTE *a13)
{
  int v13; // r5
  _BYTE *v14; // lr
  _BYTE *v15; // r10
  unsigned int v16; // r4
  int v17; // r6
  unsigned __int16 *v18; // r0
  unsigned __int16 *v19; // r9
  unsigned int v20; // r2
  unsigned __int8 *v21; // r8
  _DWORD *v22; // r4
  unsigned int v23; // r7
  int v24; // r10
  int v25; // r3
  int v26; // r5
  bool v27; // zf
  unsigned int i; // r4
  int v29; // r3
  int v30; // r6
  _DWORD *v31; // r5
  int v32; // r2
  int v33; // r3
  unsigned __int8 *v34; // r4
  int v35; // r2
  unsigned int v36; // r4
  int v37; // r3
  unsigned __int16 *v38; // r4
  int v39; // r7
  int v40; // lr
  int v41; // r6
  _DWORD *v42; // r3
  int v43; // r5
  int v44; // r0
  int v45; // r1
  int v46; // r3
  int v47; // r0
  unsigned int j; // r4
  unsigned int v49; // [sp+20h] [bp-50h]
  int v51; // [sp+28h] [bp-48h]
  int v52; // [sp+2Ch] [bp-44h]
  int v53; // [sp+30h] [bp-40h]
  int v55; // [sp+38h] [bp-38h] BYREF
  unsigned __int8 *v56; // [sp+3Ch] [bp-34h]
  int v57; // [sp+40h] [bp-30h]
  int v58; // [sp+44h] [bp-2Ch] BYREF
  int v59; // [sp+48h] [bp-28h] BYREF
  unsigned int v60; // [sp+4Ch] [bp-24h]
  int v61; // [sp+50h] [bp-20h]

  v13 = 0;
  v52 = 0;
  v14 = a12;
  v15 = a13;
  v58 = 0;
  v59 = -1;
  v16 = result;
  *a12 = 0;
  *a13 = 0;
  v61 = a2;
  v57 = 0;
  if ( result )
  {
    v60 = *(unsigned __int16 *)(result + 4);
    if ( v60 )
    {
      v17 = 0;
      v53 = 0;
      if ( (a4 & 0x2000000) != 0 )
      {
        if ( *a8 < 0 )
          v17 = 128;
        else
          v17 = 64;
        v53 = v17;
      }
      v18 = **(unsigned __int16 ***)(a3 + 148);
      v19 = (unsigned __int16 *)SeWorldSid;
      v51 = SeWorldSid;
      if ( *v18 == *(unsigned __int16 *)SeAnonymousLogonSid )
      {
        v14 = a12;
        if ( !memcmp((unsigned int)v18, SeAnonymousLogonSid, 4 * (*(unsigned __int8 *)(SeAnonymousLogonSid + 1) + 2)) )
          v52 = 4 * (*((unsigned __int8 *)v19 + 1) + 2);
      }
      v20 = 0;
      v21 = (unsigned __int8 *)(v16 + 8);
      v49 = 0;
      v56 = (unsigned __int8 *)(v16 + 8);
      v22 = a9;
      v23 = a6;
      result = 1;
      while ( 1 )
      {
        if ( (*v14 || *v15) && v23 <= 1 )
        {
LABEL_41:
          if ( v13 )
          {
            AuthzBasepFreeSecurityAttributesList(v13);
            result = ExFreePoolWithTag(v13);
          }
          return result;
        }
        v24 = v21[1];
        if ( (v24 & 8) != 0 )
          goto LABEL_39;
        v55 = -1;
        v25 = *v21;
        switch ( v25 )
        {
          case 2:
            if ( !SepSidInToken(a3, a10, (int)(v21 + 8), 1, 0)
              && (!v52
               || *v19 != *((unsigned __int16 *)v21 + 4)
               || memcmp((unsigned int)v19, (unsigned int)(v21 + 8), v52)) )
            {
              goto LABEL_37;
            }
            v26 = *((_DWORD *)v21 + 1);
            if ( v23 )
            {
              for ( i = 0; i < v23; ++i )
                SepSetAuditInfoForObjectType(v24, v26, a4, a5, v23, a7, i, a8, a9, a12, a13);
              goto LABEL_35;
            }
            if ( *a8 >= 0 )
            {
              if ( (v24 & 0x40) == 0 )
                goto LABEL_37;
              if ( (*v22 & v26) == 0 )
              {
                v27 = v17 == 64;
LABEL_26:
                if ( !v27 )
                  goto LABEL_37;
              }
              goto LABEL_28;
            }
            if ( (v24 & 0x80) == 0 || (v26 & a4) == 0 && v17 != 128 )
              goto LABEL_37;
            break;
          case 7:
            v29 = *((_DWORD *)v21 + 2);
            v30 = *((_DWORD *)v21 + 1);
            if ( (v29 & 1) != 0 )
              v31 = v21 + 12;
            else
              v31 = 0;
            if ( (v29 & 1) != 0 )
              v32 = 16;
            else
              v32 = 0;
            if ( (v29 & 2) != 0 )
              v33 = 16;
            else
              v33 = 0;
            v34 = &v21[v33 + v32];
            v35 = (int)(v34 + 12);
            if ( v31 )
            {
              if ( SepSidInToken(a3, a10, v35, 1, 0)
                || v52
                && *v19 == *((unsigned __int16 *)v34 + 6)
                && !memcmp((unsigned int)v19, (unsigned int)(v34 + 12), v52) )
              {
                if ( !AuthzBasepObjectInTypeList(v31, a5, v23, &v55) )
                  goto LABEL_103;
                v37 = v55;
                goto LABEL_104;
              }
              goto LABEL_36;
            }
            if ( SepSidInToken(a3, a10, v35, 1, 0)
              || v52
              && *v19 == *((unsigned __int16 *)v34 + 6)
              && !memcmp((unsigned int)v19, (unsigned int)(v34 + 12), v52) )
            {
              v36 = 0;
              if ( v23 )
              {
                do
                  SepSetAuditInfoForObjectType(v24, v30, a4, a5, v23, a7, v36++, a8, a9, a12, a13);
                while ( v36 < v23 );
LABEL_35:
                v21 = v56;
                v19 = (unsigned __int16 *)v51;
              }
            }
LABEL_36:
            v22 = a9;
            goto LABEL_37;
          case 13:
            v38 = (unsigned __int16 *)(v21 + 8);
            v39 = v21[9] + 2;
            v55 = *((_DWORD *)v21 + 1);
            if ( !v61 || v13 )
            {
              v40 = v57;
            }
            else
            {
              AuthzBasepInitializeResourceClaimsFromSacl(v61, (int)&v58);
              v40 = v58;
              v20 = v49;
              v19 = (unsigned __int16 *)SeWorldSid;
              v57 = v58;
              result = 1;
              v51 = SeWorldSid;
            }
            v41 = *((unsigned __int16 *)v21 + 1);
            if ( v41 - 4 * v39 - 8 <= 0 )
            {
              v14 = a12;
              v22 = a9;
              goto LABEL_39;
            }
            v42 = *(_DWORD **)(a3 + 636);
            if ( v42 )
              v43 = v42[75];
            else
              v43 = 0;
            if ( v42 )
              v44 = v42[73];
            else
              v44 = 0;
            if ( v42 )
              v45 = v42[74];
            else
              v45 = 0;
            if ( v42 )
              v46 = v42[72];
            else
              v46 = 0;
            AuthzBasepEvaluateAceCondition(
              a3,
              *(_DWORD *)(a3 + 476),
              v40,
              v46,
              v45,
              v44,
              v43,
              &v38[2 * v39],
              v41 - 4 * v39 - 8,
              1u,
              0,
              &v59);
            if ( v59 != 1 )
            {
              v19 = (unsigned __int16 *)SeWorldSid;
              v51 = SeWorldSid;
              goto LABEL_36;
            }
            v47 = SepSidInToken(a3, a10, (int)(v21 + 8), 1, 0);
            v19 = (unsigned __int16 *)SeWorldSid;
            v51 = SeWorldSid;
            if ( !v47
              && (!v52 || *(unsigned __int16 *)SeWorldSid != *v38 || memcmp(SeWorldSid, (unsigned int)(v21 + 8), v52)) )
            {
              goto LABEL_36;
            }
            v23 = a6;
            if ( a6 )
            {
              v30 = v55;
              for ( j = 0; j < a6; ++j )
                SepSetAuditInfoForObjectType(v24, v30, a4, a5, a6, a7, j, a8, a9, a12, a13);
              v21 = v56;
              v19 = (unsigned __int16 *)v51;
LABEL_103:
              v37 = -1;
LABEL_104:
              v22 = a9;
              if ( v37 != -1 )
                SepSetAuditInfoForObjectType(v24, v30, a4, a5, v23, a7, v37, a8, a9, a12, a13);
LABEL_37:
              v14 = a12;
              result = 1;
LABEL_38:
              v20 = v49;
LABEL_39:
              v15 = a13;
              goto LABEL_40;
            }
            if ( *a8 >= 0 )
            {
              v22 = a9;
              if ( (v24 & 0x40) == 0 )
                goto LABEL_37;
              if ( (*a9 & v55) == 0 )
              {
                v27 = v53 == 64;
                goto LABEL_26;
              }
LABEL_28:
              v14 = a12;
              result = 1;
              *a12 = 1;
              goto LABEL_38;
            }
            if ( (v24 & 0x80) == 0 || (v55 & a4) == 0 && v53 != 128 )
              goto LABEL_36;
            v22 = a9;
            break;
          default:
            goto LABEL_39;
        }
        v15 = a13;
        result = 1;
        v14 = a12;
        v20 = v49;
        *a13 = 1;
LABEL_40:
        ++v20;
        v23 = a6;
        v21 += *((unsigned __int16 *)v21 + 1);
        v13 = v57;
        v17 = v53;
        v49 = v20;
        v56 = v21;
        if ( v20 >= v60 )
          goto LABEL_41;
      }
    }
  }
  return result;
}
