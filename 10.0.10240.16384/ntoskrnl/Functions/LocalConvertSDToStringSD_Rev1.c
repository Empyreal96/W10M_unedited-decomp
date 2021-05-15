// LocalConvertSDToStringSD_Rev1 
 
unsigned int __fastcall LocalConvertSDToStringSD_Rev1(int a1, int a2, int a3, unsigned __int8 *a4, char a5, unsigned __int16 **a6, unsigned int *a7)
{
  int v8; // r7
  int v9; // r5
  int v10; // r0
  unsigned int v11; // r6
  unsigned __int16 *v12; // r10
  int v13; // r4
  int v14; // r0
  int v15; // r1
  unsigned __int16 *v16; // r8
  unsigned __int16 *v17; // r6
  unsigned int v18; // r3
  unsigned __int16 *v19; // r4
  char *v20; // r9
  char *v21; // r7
  int v22; // r4
  int v23; // r7
  unsigned int v24; // r4
  unsigned int v25; // r4
  unsigned int v26; // r0
  unsigned int v27; // r7
  int v28; // r0
  unsigned int v29; // r4
  int v30; // r1
  unsigned __int16 *v31; // r0
  unsigned int v32; // r7
  unsigned __int16 *v33; // r8
  unsigned int v34; // r0
  int v36; // [sp+Ch] [bp-8Ch]
  bool v37; // [sp+18h] [bp-80h] BYREF
  unsigned __int8 v38; // [sp+19h] [bp-7Fh] BYREF
  char v39[2]; // [sp+1Ah] [bp-7Eh] BYREF
  unsigned __int16 *v40; // [sp+1Ch] [bp-7Ch]
  unsigned __int16 *v41; // [sp+20h] [bp-78h]
  unsigned __int16 *v42; // [sp+24h] [bp-74h]
  unsigned int v43; // [sp+28h] [bp-70h] BYREF
  char *v44; // [sp+2Ch] [bp-6Ch]
  unsigned __int16 v45; // [sp+30h] [bp-68h] BYREF
  char *v46; // [sp+34h] [bp-64h]
  int v47; // [sp+38h] [bp-60h]
  unsigned __int16 *v48; // [sp+3Ch] [bp-5Ch] BYREF
  unsigned __int16 *v49; // [sp+40h] [bp-58h]
  int v50; // [sp+44h] [bp-54h]
  char *v51; // [sp+48h] [bp-50h] BYREF
  int v52; // [sp+4Ch] [bp-4Ch] BYREF
  unsigned __int16 *v53; // [sp+50h] [bp-48h] BYREF
  int v54; // [sp+54h] [bp-44h]
  char *v55; // [sp+58h] [bp-40h] BYREF
  unsigned __int16 *v56; // [sp+5Ch] [bp-3Ch] BYREF
  unsigned __int16 *v57; // [sp+60h] [bp-38h] BYREF
  unsigned __int16 *v58; // [sp+64h] [bp-34h] BYREF
  int v59; // [sp+68h] [bp-30h] BYREF
  int v60; // [sp+6Ch] [bp-2Ch]
  int v61; // [sp+70h] [bp-28h]
  int v62[9]; // [sp+74h] [bp-24h] BYREF

  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  v43 = 0;
  v44 = 0;
  v49 = 0;
  v50 = 0;
  v57 = 0;
  v58 = 0;
  v46 = 0;
  v47 = 0;
  v39[0] = 0;
  v53 = 0;
  v54 = 0;
  v38 = 0;
  v40 = 0;
  v41 = 0;
  v55 = 0;
  v56 = 0;
  v51 = 0;
  v52 = 0;
  v45 = 0;
  v42 = 0;
  v60 = 0;
  v61 = 0;
  v59 = 0;
  v62[0] = 0;
  v12 = 0;
  v48 = 0;
  if ( !a4 || !a6 )
    return 87;
  if ( (a5 & 1) == 0 )
  {
LABEL_6:
    if ( (a5 & 2) != 0 )
    {
      v10 = RtlGetGroupSecurityDescriptor((int)a4, v62, &v37);
      v60 = v62[0];
    }
    if ( v10 < 0 )
      goto LABEL_19;
    if ( (a5 & 4) != 0 )
    {
      v10 = RtlGetDaclSecurityDescriptor((int)a4, &v38, &v58, &v37);
      v49 = v58;
      v54 = v38;
    }
    if ( v10 < 0 )
      goto LABEL_19;
    v13 = a5 & 0xF8;
    if ( (a5 & 0xF8) != 0 )
    {
      v14 = RtlGetSaclSecurityDescriptor((int)a4, v39, &v52, &v37);
      if ( v14 < 0 )
        return RtlNtStatusToDosError(v14, v15);
      v8 = v52;
      v50 = (unsigned __int8)v39[0];
      if ( v39[0] )
      {
        if ( v52 )
        {
          SddlFilterSacl(v52, 0, &v43, v13);
          a2 = SddlpAlloc(v43);
          v47 = a2;
          if ( !a2 )
          {
            v10 = -1073741801;
            goto LABEL_19;
          }
          SddlFilterSacl(v8, a2, &v43, v13);
          v8 = v47;
        }
      }
    }
    v10 = RtlGetControlSecurityDescriptor(a4, &v45, &v58);
    if ( v10 < 0 )
      goto LABEL_19;
    if ( v61 )
    {
      v9 = LocalGetStringForSid(v61, &v53);
      if ( v9 )
      {
        v17 = 0;
        v18 = (unsigned int)v53;
        v19 = 0;
        v20 = 0;
        v21 = 0;
LABEL_83:
        if ( v18 )
          ExFreePoolWithTag(v18);
        if ( v17 )
          ExFreePoolWithTag((unsigned int)v17);
        if ( v20 )
          ExFreePoolWithTag((unsigned int)v20);
        if ( v21 )
          ExFreePoolWithTag((unsigned int)v21);
        if ( v19 )
          ExFreePoolWithTag((unsigned int)v19);
        if ( v12 )
          ExFreePoolWithTag((unsigned int)v12);
        goto LABEL_20;
      }
      v16 = v53;
      v41 = v53;
    }
    else
    {
      v16 = 0;
    }
    if ( v60 )
    {
      v9 = LocalGetStringForSid(v60, &v56);
      if ( v9 )
      {
        v19 = 0;
        v17 = v56;
        v20 = 0;
        v21 = 0;
LABEL_82:
        v18 = (unsigned int)v41;
        goto LABEL_83;
      }
      v40 = v56;
    }
    v22 = v45;
    if ( v45 )
    {
      v9 = LocalGetStringForControl(v45, 1, &v48);
      if ( v9 )
      {
        v12 = v48;
        v19 = 0;
      }
      else
      {
        v9 = LocalGetStringForControl(v22, 2, &v57);
        v12 = v48;
        if ( !v9 )
        {
          v42 = v57;
          goto LABEL_36;
        }
        v19 = v57;
      }
      v20 = 0;
      v21 = 0;
LABEL_81:
      v17 = v40;
      goto LABEL_82;
    }
LABEL_36:
    if ( v50 )
    {
      v9 = LocalConvertAclToString(v8, v50, 0, (unsigned int *)&v55, &v43, 0, 0, v36, 1u);
      if ( v9 )
      {
        v20 = v55;
        v21 = 0;
        goto LABEL_80;
      }
      v11 = v43;
      v44 = v55;
    }
    v23 = v54;
    if ( v54 )
    {
      v9 = LocalConvertAclToString((int)v49, v54, 1, (unsigned int *)&v51, &v43, 0, 0, v36, 1u);
      if ( v9 )
      {
        v21 = v51;
        v20 = v44;
        goto LABEL_80;
      }
      v11 += v43;
      v46 = v51;
    }
    if ( v16 )
    {
      v24 = wcslen(v16);
      v11 += 2 * (wcslen(L"O") + v24 + 1);
    }
    if ( v40 )
    {
      v25 = wcslen(v40);
      v11 += 2 * (wcslen(L"G") + v25 + 1);
    }
    if ( v23 )
    {
      v11 += 2 * (wcslen(L"D") + 1);
      if ( v12 )
        v11 += 2 * wcslen(v12);
    }
    if ( v50 )
    {
      v26 = wcslen(L"S");
      v19 = v42;
      v11 += 2 * (v26 + 1);
      if ( v42 )
        v11 += 2 * wcslen(v42);
    }
    else
    {
      v19 = v42;
    }
    v27 = v11 + 2;
    v28 = SddlpAlloc(v11 + 2);
    *a6 = (unsigned __int16 *)v28;
    if ( !v28 )
    {
      v20 = v44;
      v21 = v46;
      v9 = 8;
      goto LABEL_81;
    }
    v29 = 0;
    if ( v16 )
    {
      swprintf_s(v28, v27 >> 1, (int)L"%ws%wc%ws", L"O", 58, v16);
      v29 = wcslen(*a6);
    }
    if ( v40 )
    {
      swprintf_s((int)&(*a6)[v29], (v27 >> 1) - v29, (int)L"%ws%wc%ws", L"G", 58, v40);
      v29 += wcslen(&(*a6)[v29]);
    }
    if ( v54 )
    {
      v30 = (v27 >> 1) - v29;
      if ( v12 )
        swprintf_s((int)&(*a6)[v29], v30, (int)L"%ws%wc%ws", L"D", 58, v12);
      else
        swprintf_s((int)&(*a6)[v29], v30, (int)L"%ws%wc", L"D", 58);
      v31 = &(*a6)[v29];
      v49 = *a6;
      v29 += wcslen(v31);
      if ( v46 )
      {
        wcscpy_s((char *)&v49[v29], (v27 >> 1) - v29, v46);
        v29 += wcslen(&(*a6)[v29]);
      }
    }
    if ( v50 )
    {
      v32 = v27 >> 1;
      if ( v42 )
        swprintf_s((int)&(*a6)[v29], v32 - v29, (int)L"%ws%wc%ws", L"S", 58, v42);
      else
        swprintf_s((int)&(*a6)[v29], v32 - v29, (int)L"%ws%wc", L"S", 58);
      v33 = *a6;
      v34 = wcslen(&(*a6)[v29]);
      v20 = v44;
      if ( v44 )
        wcscpy_s((char *)&v33[v29 + v34], v32 - (v29 + v34), v44);
    }
    else
    {
      v20 = v44;
    }
    v21 = v46;
    if ( a7 )
      *a7 = v11 >> 1;
LABEL_80:
    v19 = v42;
    goto LABEL_81;
  }
  v10 = RtlGetOwnerSecurityDescriptor((int)a4, &v59, &v37);
  if ( v10 >= 0 )
  {
    v61 = v59;
    goto LABEL_6;
  }
LABEL_19:
  v9 = RtlNtStatusToDosError(v10, a2);
LABEL_20:
  if ( v47 )
    ExFreePoolWithTag(v47);
  return v9;
}
