// SeOpenObjectForDeleteAuditAlarmWithTransaction 
 
unsigned __int16 *__fastcall SeOpenObjectForDeleteAuditAlarmWithTransaction(unsigned __int16 *result, int a2, _WORD *a3, int a4, int a5, int a6, unsigned __int8 a7, char a8, unsigned __int16 **a9, _BYTE *a10)
{
  int v11; // lr
  unsigned int v12; // r7
  int v13; // r5
  int v14; // r9
  unsigned int v15; // r8
  int v16; // r3
  __int16 v17; // r3
  __int64 v18; // kr00_8
  int v19; // r1
  int v20; // r2
  unsigned __int16 *v21; // r0
  int v22; // r3
  int v23; // r1
  int v24; // r3
  _WORD *v25; // r2
  unsigned __int16 *v26; // r1
  int v27; // r0
  int v28; // r3
  unsigned __int16 *v29; // r9
  unsigned __int16 **v30; // r10
  unsigned __int16 *v31; // r7
  unsigned int v32; // r0
  int v33; // r0
  unsigned int v34; // r0
  int v35; // r0
  unsigned __int16 *v36; // r2
  unsigned __int16 *v37; // r3
  unsigned __int16 *v38; // r4
  int v39; // [sp+Ch] [bp-84h]
  int v40; // [sp+18h] [bp-78h]
  unsigned __int8 v41; // [sp+40h] [bp-50h] BYREF
  unsigned __int8 v42; // [sp+41h] [bp-4Fh] BYREF
  unsigned __int16 v43; // [sp+42h] [bp-4Eh] BYREF
  unsigned __int16 **v44; // [sp+44h] [bp-4Ch]
  unsigned __int16 *v45; // [sp+48h] [bp-48h]
  unsigned __int16 *v46; // [sp+4Ch] [bp-44h] BYREF
  int v47; // [sp+50h] [bp-40h]
  unsigned __int16 *v48; // [sp+54h] [bp-3Ch]
  int v49; // [sp+58h] [bp-38h]
  unsigned __int16 *v50; // [sp+5Ch] [bp-34h] BYREF
  unsigned __int16 *v51; // [sp+60h] [bp-30h]
  unsigned __int16 *v52; // [sp+64h] [bp-2Ch]
  int v53; // [sp+68h] [bp-28h]
  _WORD *v54; // [sp+6Ch] [bp-24h]

  v51 = 0;
  v54 = a3;
  v11 = a2;
  v48 = result;
  v49 = a2;
  v12 = 999;
  v13 = 0;
  v43 = 999;
  v41 = 0;
  v14 = 0;
  v42 = 0;
  v15 = 0;
  v50 = 0;
  v52 = 0;
  v53 = 0;
  v45 = 0;
  v46 = 0;
  if ( a8 )
  {
    v44 = *(unsigned __int16 ***)(a5 + 48);
    v16 = *(_DWORD *)(a5 + 28);
    v47 = v16;
    if ( !v16 )
    {
      v16 = *(_DWORD *)(a5 + 36);
      v47 = v16;
    }
    if ( result && (v16 = *result) != 0 )
    {
      v45 = result;
    }
    else if ( a2 )
    {
      v53 = SepQueryTypeString(a2, (unsigned int *)&v46);
      if ( v53 < 0 )
      {
        result = v46;
LABEL_72:
        if ( result )
          result = (unsigned __int16 *)ExFreePoolWithTag((unsigned int)result);
LABEL_74:
        if ( v53 < 0 )
          result = (unsigned __int16 *)SepAuditFailed();
        return result;
      }
      result = v48;
      v11 = v49;
      v52 = v46;
      if ( v46 )
        v45 = v46;
    }
    if ( !a4 )
      goto LABEL_37;
    result = (unsigned __int16 *)SepAdtAuditObjectAccessWithContext(v11, (int)result, a7, a7 == 0, a5 + 28, 1, &v43);
    if ( !result )
    {
      v12 = v43;
      goto LABEL_37;
    }
    v17 = *(_WORD *)(a4 + 2);
    v18 = *(_QWORD *)(a5 + 16);
    if ( (v17 & 0x10) == 0 )
      goto LABEL_16;
    if ( (*(_WORD *)(a4 + 2) & 0x8000) == 0 )
    {
      v19 = *(_DWORD *)(a4 + 12);
      goto LABEL_21;
    }
    v20 = *(_DWORD *)(a4 + 12);
    if ( v20 )
      v19 = v20 + a4;
    else
LABEL_16:
      v19 = 0;
    if ( (v17 & 0x10) == 0 )
      goto LABEL_22;
LABEL_21:
    if ( (*(_WORD *)(a4 + 2) & 0x8000) == 0 )
    {
      v21 = *(unsigned __int16 **)(a4 + 12);
      goto LABEL_27;
    }
    v22 = *(_DWORD *)(a4 + 12);
    if ( v22 )
      v21 = (unsigned __int16 *)(v22 + a4);
    else
LABEL_22:
      v21 = 0;
LABEL_27:
    SeExamineSacl(v21, v19, v47, HIDWORD(v18) | v18, a7, &v41, &v42);
    if ( (*(_WORD *)(a4 + 2) & 0x10) == 0 )
      goto LABEL_28;
    if ( (*(_WORD *)(a4 + 2) & 0x8000) == 0 )
    {
      v23 = *(_DWORD *)(a4 + 12);
      goto LABEL_33;
    }
    v24 = *(_DWORD *)(a4 + 12);
    if ( v24 )
      v23 = v24 + a4;
    else
LABEL_28:
      v23 = 0;
LABEL_33:
    result = (unsigned __int16 *)SeExamineGlobalSacl(v48, v23, v47, HIDWORD(v18) | v18, a7, &v41, &v42);
    v13 = v41;
    v12 = v43;
    if ( v41 )
    {
      v16 = (int)a10;
      *a10 = 1;
      goto LABEL_44;
    }
    v14 = v42;
LABEL_37:
    if ( a7 )
    {
      v16 = (int)v44;
      result = *v44;
      if ( *v44 )
      {
        v16 = *(_DWORD *)result;
        if ( *(_DWORD *)result )
        {
          result = (unsigned __int16 *)SepAdtAuditPrivilegeUseWithContext((int)result, a7, 0, a5 + 28);
          v12 = v43;
          if ( result )
          {
            v13 = 1;
            *(_BYTE *)(a5 + 96) = 1;
          }
        }
      }
    }
    if ( !v13 && !v14 )
      goto LABEL_74;
LABEL_44:
    *(_BYTE *)(a5 + 9) = 1;
    v25 = v54;
    if ( v54 && (v16 = (unsigned __int16)*v54, *v54) )
    {
      v26 = v54;
    }
    else
    {
      if ( !v49 )
        goto LABEL_52;
      v27 = SepQueryNameString(v49, (unsigned int *)&v50, (int)v54, v16);
      v15 = (unsigned int)v50;
      v53 = v27;
      if ( v27 < 0 )
      {
LABEL_69:
        if ( v15 )
          ExFreePoolWithTag(v15);
        result = v52;
        goto LABEL_72;
      }
      if ( !v50 )
      {
LABEL_52:
        v26 = 0;
LABEL_53:
        if ( a7 )
        {
          v30 = v44;
          v29 = v45;
          SepAdtOpenObjectForDeleteAuditAlarm(
            v12,
            (int)v26,
            (int)v25,
            v45,
            v26,
            *(_DWORD *)(a5 + 28),
            *(_DWORD *)(a5 + 36),
            v39,
            *(_DWORD *)(a5 + 20),
            *v44,
            v40,
            *(_DWORD *)(a5 + 40),
            a9);
          v31 = v51;
          if ( v51 )
          {
            v32 = *(_DWORD *)(a5 + 104);
            if ( v32 )
            {
              ExFreePoolWithTag(v32);
              *(_WORD *)(a5 + 100) = 0;
              *(_WORD *)(a5 + 102) = 0;
            }
            v33 = ExAllocatePoolWithTag(1, v31[1], 538994003);
            *(_DWORD *)(a5 + 104) = v33;
            if ( v33 )
            {
              *(_WORD *)(a5 + 102) = v31[1];
              RtlCopyUnicodeString((unsigned __int16 *)(a5 + 100), v31);
            }
          }
          if ( v29 )
          {
            v34 = *(_DWORD *)(a5 + 112);
            if ( v34 )
            {
              ExFreePoolWithTag(v34);
              *(_WORD *)(a5 + 108) = 0;
              *(_WORD *)(a5 + 110) = 0;
            }
            v35 = ExAllocatePoolWithTag(1, v29[1], 538994003);
            *(_DWORD *)(a5 + 112) = v35;
            if ( v35 )
            {
              *(_WORD *)(a5 + 110) = v29[1];
              RtlCopyUnicodeString((unsigned __int16 *)(a5 + 108), v29);
            }
          }
          if ( a9 )
          {
            v36 = a9[1];
            v37 = a9[2];
            v38 = a9[3];
            v30[7] = *a9;
            v30[8] = v36;
            v30[9] = v37;
            v30[10] = v38;
          }
        }
        else
        {
          v28 = (int)a9;
          if ( !a9 )
            v28 = (int)(v44 + 7);
          SepAdtOpenObjectAuditAlarm(
            v12,
            &SeSubsystemName,
            0,
            v45,
            v26,
            a4,
            *(_DWORD *)(a5 + 28),
            *(_DWORD *)(a5 + 36),
            *(_DWORD *)(a5 + 24),
            *(_DWORD *)(a5 + 20),
            *v44,
            0,
            *(_DWORD *)(a5 + 40),
            2,
            0,
            0,
            0,
            v28,
            a5);
        }
        goto LABEL_69;
      }
      v26 = v50;
    }
    v51 = v26;
    goto LABEL_53;
  }
  return result;
}
