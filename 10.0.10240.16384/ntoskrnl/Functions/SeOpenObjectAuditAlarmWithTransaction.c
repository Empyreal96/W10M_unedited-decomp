// SeOpenObjectAuditAlarmWithTransaction 
 
_DWORD *__fastcall SeOpenObjectAuditAlarmWithTransaction(_DWORD *result, int a2, _WORD *a3, int a4, int a5, int a6, unsigned __int8 a7, char a8, _DWORD *a9, _BYTE *a10)
{
  _WORD *v10; // r1
  int v11; // r8
  int v12; // r7
  int v13; // r5
  int v14; // r6
  int v15; // r9
  int v16; // r7
  int v17; // r5
  int v18; // r4
  int v19; // r0
  int v20; // r0
  int v21; // r4
  unsigned int v22; // r2
  unsigned int v23; // r6
  BOOL v24; // r3
  int *v25; // r9
  int v26; // r1
  int v27; // lr
  int v28; // r8
  unsigned int i; // r0
  __int64 v30; // kr00_8
  __int16 v31; // r2
  int v32; // r1
  int v33; // r3
  int v34; // r5
  int v35; // r0
  int v36; // r3
  int v37; // r1
  int v38; // r3
  int v39; // r0
  int v40; // r3
  _WORD *v41; // lr
  unsigned int v42; // r7
  int v43; // r0
  int v44; // r4
  unsigned int v45; // r8
  _DWORD *v46; // r3
  unsigned int v47; // r0
  unsigned __int16 *v48; // r1
  unsigned __int16 *v49; // r6
  unsigned int v50; // r0
  int v51; // r2
  int v52; // r3
  int v53; // r4
  _DWORD *v54; // r5
  unsigned __int8 v55; // [sp+40h] [bp-68h] BYREF
  unsigned __int8 v56; // [sp+41h] [bp-67h] BYREF
  unsigned __int16 v57; // [sp+42h] [bp-66h]
  _WORD *v58; // [sp+44h] [bp-64h]
  int v59; // [sp+48h] [bp-60h]
  int v60; // [sp+4Ch] [bp-5Ch]
  _DWORD *v61; // [sp+50h] [bp-58h]
  int v62; // [sp+54h] [bp-54h]
  _WORD *v63; // [sp+58h] [bp-50h]
  unsigned __int16 *v64; // [sp+5Ch] [bp-4Ch]
  _WORD *v65; // [sp+60h] [bp-48h] BYREF
  int v66; // [sp+64h] [bp-44h]
  _DWORD *v67; // [sp+68h] [bp-40h] BYREF
  int v68; // [sp+6Ch] [bp-3Ch]
  _WORD *v69; // [sp+70h] [bp-38h]
  _DWORD v70[12]; // [sp+78h] [bp-30h] BYREF

  v60 = a2;
  v69 = a3;
  v10 = result;
  v11 = 0;
  v12 = 0;
  v62 = a4;
  v63 = result;
  v56 = 0;
  v55 = 0;
  v64 = 0;
  v65 = 0;
  v67 = 0;
  v58 = 0;
  v59 = 999;
  v61 = 0;
  v57 = 999;
  if ( !a8 )
    return result;
  v13 = *(_DWORD *)(a5 + 48);
  v14 = *(_DWORD *)(a5 + 28);
  v66 = v13;
  if ( !v14 )
    v14 = *(_DWORD *)(a5 + 36);
  v15 = a7;
  if ( a4 )
  {
    v16 = a7 == 0;
    v17 = 0;
    if ( a7 )
      v17 = 3;
    v59 = 118;
    v57 = 118;
    if ( !a7 )
      v17 |= 0x30u;
    if ( dword_61D468 )
    {
      if ( (dword_61D468 & v17) != 0 )
        return (_DWORD *)sub_7FC568();
      v18 = 0;
      if ( dword_61D5A8 )
      {
        if ( a5 == -28 )
        {
          v25 = v70;
          v70[0] = 0;
          v70[1] = 0;
          v70[2] = 0;
          v70[3] = 0;
          SeCaptureSubjectContext(v70, (int)result, 0, 0);
        }
        else
        {
          v25 = (int *)(a5 + 28);
        }
        v26 = *v25;
        if ( *v25 || (v26 = v25[2]) != 0 )
        {
          if ( *(_BYTE *)(v26 + 118) == 2 )
          {
            v27 = 0;
            v28 = 0;
            for ( i = 16; i < 0x1E; ++i )
            {
              if ( ((*(unsigned __int8 *)(v26 + (i >> 1) + 88) >> (4 * (i & 1))) & 1) != 0 )
              {
                if ( (v17 & 2) != 0 )
                  goto LABEL_59;
                v27 = (unsigned __int16)(v27 + 1);
              }
              if ( ((*(unsigned __int8 *)(v26 + (i >> 1) + 88) >> (4 * (i & 1))) & 4) != 0 )
              {
                if ( (v17 & 0x20) != 0 )
                  goto LABEL_59;
                v28 = (unsigned __int16)(v28 + 1);
              }
            }
            if ( (v17 & 1) != 0 && v27 == 14 || (v17 & 0x10) != 0 && v28 == 14 )
LABEL_59:
              v18 = 1;
            v11 = 0;
          }
        }
        else
        {
          SepAuditFailed(-1073741700);
        }
        if ( a5 == -28 )
          SeReleaseSubjectContext((int)v25);
        v15 = a7;
        v10 = v63;
      }
    }
    else
    {
      v18 = 0;
    }
    if ( v18 )
    {
      v59 = SepAdtClassifyObjectIntoSubCategory(v60, v10, v15, v16);
      v57 = v59;
      v19 = SepAdtAuditThisEventWithContext(v59, v15, v16, (_DWORD *)(a5 + 28));
    }
    else
    {
      v19 = 0;
    }
    if ( v19 )
    {
      v30 = *(_QWORD *)(a5 + 16);
      v31 = *(_WORD *)(v62 + 2);
      if ( (v31 & 0x10) != 0 )
      {
        if ( (*(_WORD *)(v62 + 2) & 0x8000) != 0 )
        {
          v33 = *(_DWORD *)(v62 + 12);
          if ( v33 )
            v32 = v62 + v33;
          else
            v32 = 0;
        }
        else
        {
          v32 = *(_DWORD *)(v62 + 12);
        }
      }
      else
      {
        v32 = 0;
      }
      v34 = v62;
      if ( (v31 & 0x10) != 0 )
      {
        if ( (*(_WORD *)(v62 + 2) & 0x8000) != 0 )
        {
          v36 = *(_DWORD *)(v62 + 12);
          if ( v36 )
            v35 = v36 + v62;
          else
            v35 = 0;
        }
        else
        {
          v35 = *(_DWORD *)(v62 + 12);
        }
      }
      else
      {
        v35 = 0;
      }
      SeExamineSacl(v35, v32, v14, HIDWORD(v30) | v30, v15, &v56, &v55);
      if ( (*(_WORD *)(v34 + 2) & 0x10) != 0 )
      {
        if ( (*(_WORD *)(v34 + 2) & 0x8000) != 0 )
        {
          v38 = *(_DWORD *)(v34 + 12);
          if ( v38 )
            v37 = v38 + v34;
          else
            v37 = 0;
        }
        else
        {
          v37 = *(_DWORD *)(v34 + 12);
        }
      }
      else
      {
        v37 = 0;
      }
      SeExamineGlobalSacl(v63, v37, v14, HIDWORD(v30) | v30, v15, &v56, &v55);
      v68 = v56;
      if ( v56 )
      {
        *a10 = 1;
        if ( v15 )
        {
          if ( (*(_WORD *)(v34 + 2) & 0x10) != 0 )
          {
            if ( (*(_WORD *)(v34 + 2) & 0x8000) != 0 )
            {
              v40 = *(_DWORD *)(v34 + 12);
              if ( v40 )
                v39 = v40 + v34;
              else
                v39 = 0;
            }
            else
            {
              v39 = *(_DWORD *)(v34 + 12);
            }
          }
          else
          {
            v39 = 0;
          }
          v13 = v66;
          SeMaximumAuditMask(v39, HIDWORD(v30) | v30, v14, (_DWORD *)(v66 + 24));
          SeMaximumAuditMaskFromGlobalSacl(v63, HIDWORD(v30) | v30, v14, v13 + 24);
          v12 = v55;
          v11 = v68;
LABEL_18:
          v20 = v15 == 0;
          v21 = v15;
          if ( (*(_DWORD *)(a5 + 24) & 0x2000000) != 0 )
          {
            v21 = 0;
            v20 = 1;
          }
          v22 = 0;
          while ( *(int *)(*(_DWORD *)(a5 + 48) + 4 * v22 + 64) >= 0 )
          {
            v22 = (unsigned __int8)(v22 + 1);
            if ( v22 >= 0x20 )
            {
              result = 0;
              goto LABEL_24;
            }
          }
          result = (_DWORD *)SepAdtAuditThisEventWithContext(0x81u, v21, v20, (_DWORD *)(a5 + 28));
LABEL_24:
          *(_BYTE *)(v13 + 192) = (_BYTE)result;
          goto LABEL_25;
        }
      }
      v12 = v55;
      v11 = v68;
    }
    else
    {
      v12 = 0;
    }
    v13 = v66;
    goto LABEL_18;
  }
LABEL_25:
  if ( v15 && !v11 && (result = *(_DWORD **)v13) != 0 && *result )
  {
    result = (_DWORD *)SepAdtAuditPrivilegeUseWithContext((int)result, v15, 0, a5 + 28);
    v23 = v57;
    if ( result )
    {
      v11 = 1;
      *(_BYTE *)(a5 + 96) = 1;
    }
  }
  else
  {
    v23 = v59;
  }
  v24 = v11 || v12;
  *(_BYTE *)(a5 + 9) = v24;
  if ( v24 || *(_BYTE *)(v13 + 192) )
  {
    v41 = v69;
    if ( v69 && *v69 )
    {
      v58 = v69;
      v42 = 0;
LABEL_110:
      v43 = v60;
LABEL_111:
      if ( v63 && *v63 )
      {
        result = v63;
        v64 = v63;
        v45 = 0;
LABEL_120:
        if ( v15 )
        {
          if ( v41 )
          {
            v47 = *(_DWORD *)(a5 + 104);
            if ( v47 )
            {
              ExFreePoolWithTag(v47);
              v41 = v58;
              *(_WORD *)(a5 + 100) = 0;
              *(_WORD *)(a5 + 102) = 0;
            }
            result = (_DWORD *)ExAllocatePoolWithTag(1, (unsigned __int16)v41[1], 538994003);
            *(_DWORD *)(a5 + 104) = result;
            if ( result )
            {
              v48 = v58;
              *(_WORD *)(a5 + 102) = v58[1];
              result = (_DWORD *)RtlCopyUnicodeString((unsigned __int16 *)(a5 + 100), v48);
            }
          }
          v49 = v64;
          if ( v64 )
          {
            v50 = *(_DWORD *)(a5 + 112);
            if ( v50 )
            {
              ExFreePoolWithTag(v50);
              *(_WORD *)(a5 + 108) = 0;
              *(_WORD *)(a5 + 110) = 0;
            }
            result = (_DWORD *)ExAllocatePoolWithTag(1, v49[1], 538994003);
            *(_DWORD *)(a5 + 112) = result;
            if ( result )
            {
              *(_WORD *)(a5 + 110) = v49[1];
              result = (_DWORD *)RtlCopyUnicodeString((unsigned __int16 *)(a5 + 108), v49);
            }
          }
          if ( a9 )
          {
            v51 = a9[1];
            v52 = a9[2];
            v53 = a9[3];
            v54 = (_DWORD *)(v13 + 28);
            *v54 = *a9;
            v54[1] = v51;
            v54[2] = v52;
            v54[3] = v53;
          }
        }
        else
        {
          v46 = a9;
          if ( !a9 )
            v46 = (_DWORD *)(v13 + 28);
          SepAdtOpenObjectAuditAlarm(
            v23,
            &SeSubsystemName,
            0,
            result,
            v41,
            v62,
            *(_DWORD *)(a5 + 28),
            *(_DWORD *)(a5 + 36),
            *(_DWORD *)(a5 + 24),
            *(_DWORD *)(a5 + 20),
            *(_DWORD *)v13,
            0,
            *(_DWORD *)(a5 + 40),
            2,
            0,
            0,
            0,
            v46,
            a5);
          result = (_DWORD *)SepAdtStagingEvent(
                               v23,
                               v58,
                               0,
                               v64,
                               v58,
                               *(_DWORD *)(a5 + 28),
                               *(_DWORD *)(a5 + 36),
                               *(_DWORD *)(a5 + 24),
                               *(_DWORD *)(a5 + 20),
                               0,
                               0,
                               a5);
        }
        v44 = (int)v61;
        goto LABEL_137;
      }
      if ( !v43 )
      {
        v45 = 0;
        goto LABEL_119;
      }
      result = (_DWORD *)SepQueryTypeString(v43, &v67);
      v44 = (int)result;
      v45 = (unsigned int)v67;
      v61 = result;
      if ( (int)result >= 0 )
      {
        v41 = v58;
        if ( v67 )
        {
          result = v67;
          v64 = (unsigned __int16 *)v67;
          goto LABEL_120;
        }
LABEL_119:
        result = 0;
        goto LABEL_120;
      }
LABEL_137:
      if ( v42 )
        result = (_DWORD *)ExFreePoolWithTag(v42);
      if ( v45 )
        result = (_DWORD *)ExFreePoolWithTag(v45);
      if ( v44 < 0 )
        result = (_DWORD *)SepAuditFailed(v44);
      return result;
    }
    v43 = v60;
    if ( v60 )
    {
      result = (_DWORD *)SepQueryNameString(v60, &v65);
      v44 = (int)result;
      v42 = (unsigned int)v65;
      v61 = result;
      if ( (int)result < 0 )
      {
        v45 = 0;
        goto LABEL_137;
      }
      if ( !v65 )
      {
        v41 = 0;
        goto LABEL_110;
      }
      v43 = v60;
      if ( v65[1] )
      {
        v41 = v65;
        v58 = v65;
        goto LABEL_111;
      }
    }
    else
    {
      v42 = 0;
    }
    v41 = 0;
    goto LABEL_111;
  }
  return result;
}
