// _CmGetDeviceMappedPropertyFromRegProp 
 
int __fastcall CmGetDeviceMappedPropertyFromRegProp(int a1, int a2, unsigned int a3, unsigned int a4, _DWORD *a5, _DWORD *a6, unsigned int a7, int *a8)
{
  unsigned int v9; // r8
  int v11; // r9
  int (**v12)[5]; // r6
  unsigned int i; // r5
  int (**v14)[5]; // r4
  unsigned int v15; // r1
  int (*v16)[5]; // t1
  int (*v17)[5]; // r6
  unsigned int v18; // r10
  unsigned __int16 *v19; // r8
  int v20; // r0
  int v21; // r5
  int (*v22)[5]; // r3
  _DWORD *v23; // r9
  unsigned __int16 *v24; // r4
  int v25; // r6
  int v26; // r8
  int v27; // r0
  int (*v28)[5]; // r3
  _DWORD *v29; // r2
  int v30; // r1
  int v31; // r2
  int v32; // r3
  _DWORD *v33; // r6
  unsigned int v34; // r10
  int (*v35)[5]; // r3
  int v36; // r0
  int v37; // r2
  unsigned __int16 *v38; // r1
  int v39; // r8
  unsigned __int16 *v40; // r2
  int v41; // r3
  int j; // r6
  int v43; // r1
  unsigned __int16 *v44; // r2
  int k; // r3
  _DWORD *v46; // r2
  char v47; // r3
  int v48; // r0
  unsigned int v51; // [sp+18h] [bp-B0h] BYREF
  _DWORD *v52; // [sp+1Ch] [bp-ACh]
  int (*v53)[5]; // [sp+20h] [bp-A8h] BYREF
  int v54; // [sp+24h] [bp-A4h] BYREF
  int v55[2]; // [sp+28h] [bp-A0h] BYREF
  int v56; // [sp+30h] [bp-98h] BYREF
  int v57; // [sp+34h] [bp-94h] BYREF
  unsigned int v58[2]; // [sp+38h] [bp-90h] BYREF
  int v59; // [sp+40h] [bp-88h] BYREF
  _DWORD v60[4]; // [sp+48h] [bp-80h] BYREF
  unsigned __int16 v61[56]; // [sp+58h] [bp-70h] BYREF

  v51 = a3;
  v52 = a6;
  *a5 = 0;
  v55[0] = (int)a5;
  *a8 = 0;
  v53 = 0;
  v59 = 0;
  v57 = 0;
  v58[0] = 0;
  v56 = 0;
  if ( a6 )
  {
    v9 = a7;
    if ( !a7 )
      return sub_7C6030();
  }
  else
  {
    v9 = 0;
  }
  v11 = *(_DWORD *)(a4 + 16);
  v12 = &CmDeviceRegPropMap;
  for ( i = 0; i < 0x21; ++i )
  {
    v14 = v12;
    v16 = *v12;
    v12 += 4;
    v15 = (unsigned int)v16;
    if ( v11 == (*v16)[4] && !memcmp(a4, v15, 16) )
      break;
    v14 = 0;
  }
  if ( !v14 )
    return -1073741802;
  v17 = v14[2];
  if ( v17 == (int (*)[5])37 || v17 == (int (*)[5])9 )
  {
    v54 = 78;
    v28 = v17;
    v25 = a2;
    v21 = CmGetDeviceRegProp(a1, a2, v51, v28, &v53, v61, &v54, 0);
    if ( v21 >= 0 )
    {
      if ( v53 != v14[3] )
        return -1073741811;
      v29 = (_DWORD *)v55[0];
      *a8 = 16;
      *v29 = v14[1];
      if ( v9 < *a8 )
        return -1073741789;
      v61[38] = 0;
      v21 = RtlInitUnicodeStringEx((int)v58, v61);
      if ( v21 >= 0 )
      {
        v21 = RtlGUIDFromString(v58, v60);
        v26 = a1;
        if ( v21 >= 0 )
        {
          v30 = v60[1];
          v31 = v60[2];
          v32 = v60[3];
          v33 = v52;
          *v52 = v60[0];
          v33[1] = v30;
          v33[2] = v31;
          v33[3] = v32;
          v25 = a2;
        }
LABEL_29:
        if ( v21 == -1073741810 )
        {
          v48 = CmOpenDeviceRegKey(v26, v25, 16, 0, 1, 0, &v56, 0);
          v21 = v48;
          if ( v48 )
          {
            if ( v48 != -1073741810 && v48 != -1073741632 )
              v21 = -1073741823;
            return v21;
          }
          ZwClose();
          return -1073741275;
        }
        return v21;
      }
    }
LABEL_48:
    v26 = a1;
    goto LABEL_29;
  }
  if ( v17 == (int (*)[5])25 )
    return -1073741637;
  if ( v17 == (int (*)[5])27 )
  {
    v54 = 4;
    v25 = a2;
    v21 = CmGetDeviceRegProp(a1, a2, v51, 27, &v53, &v57, &v54, 0);
    if ( v21 >= 0 )
    {
      if ( v53 == v14[3] )
      {
        v46 = (_DWORD *)v55[0];
        *a8 = 1;
        *v46 = v14[1];
        if ( v9 >= *a8 )
        {
          if ( v57 )
            v47 = -1;
          else
            v47 = 0;
          v26 = a1;
          *(_BYTE *)v52 = v47;
          v25 = a2;
          goto LABEL_29;
        }
        return -1073741789;
      }
      return -1073741811;
    }
    goto LABEL_48;
  }
  v18 = v51;
  *a8 = v9;
  v19 = (unsigned __int16 *)v52;
  v20 = CmGetDeviceRegProp(a1, a2, v18, v17, &v53, v52, a8, 0);
  v21 = v20;
  if ( v20 && v20 != -1073741789 )
  {
    v23 = (_DWORD *)v55[0];
    goto LABEL_16;
  }
  v22 = v14[1];
  v23 = (_DWORD *)v55[0];
  *(_DWORD *)v55[0] = v22;
  if ( v22 != (int (*)[5])18 )
    goto LABEL_16;
  if ( !v20 )
  {
    v24 = v19;
    goto LABEL_22;
  }
  v24 = (unsigned __int16 *)ExAllocatePoolWithTag(1, *a8, 1380994640);
  v58[0] = (unsigned int)v24;
  if ( !v24 )
    return -1073741801;
  v54 = *a8;
  v26 = a1;
  v35 = v17;
  v25 = a2;
  v36 = CmGetDeviceRegProp(a1, a2, v18, v35, &v59, v24, &v54, 0);
  if ( v36 < 0 )
  {
    v21 = v36;
    ExFreePoolWithTag((unsigned int)v24);
    goto LABEL_29;
  }
LABEL_22:
  if ( v24 )
  {
    if ( !PnpParseIndirectInfString(v24) )
    {
      if ( RtlUnalignedStringCchLengthW(v24, 0x7FFF, &v51) < 0 )
        goto LABEL_25;
      v34 = v51;
      if ( v51 < 5 || *v24 != 64 )
        goto LABEL_25;
      v37 = 1;
      if ( v24[1] )
      {
        v38 = v24 + 1;
        do
        {
          if ( *v38 == 44 )
            break;
          v38 = &v24[++v37];
        }
        while ( *v38 );
      }
      if ( v24[v37] != 44 )
        goto LABEL_25;
      v39 = v37 + 1;
      v40 = &v24[v37 + 1];
      v41 = *v40;
      if ( v41 != 45 && v41 != 35 )
        goto LABEL_25;
      for ( j = v39 + 1; v24[j] && v24[j] != 59; ++j )
        ;
      if ( v24[j] != 59 )
        j = 0;
      if ( RtlInitUnicodeStringEx((int)v55, v40 + 1) < 0 )
        goto LABEL_25;
      if ( j )
      {
        LOWORD(v55[0]) = 2 * (j - v39 - 1);
        HIWORD(v55[0]) = v55[0];
      }
      if ( RtlUnicodeStringToInteger(v55, 10, &v51) < 0 )
        goto LABEL_25;
      if ( j )
      {
        v43 = j + 1;
        v44 = &v24[j + 1];
        for ( k = *v44; *v44; k = *v44 )
        {
          if ( k == 59 && v44[1] == 40 && v24[v34 - 1] == 41 )
            break;
          v44 = &v24[++v43];
        }
      }
    }
    *v23 = 25;
  }
LABEL_25:
  if ( v58[0] )
    ExFreePoolWithTag(v58[0]);
  v19 = (unsigned __int16 *)v52;
LABEL_16:
  if ( v21 )
  {
    v26 = a1;
    v25 = a2;
    goto LABEL_29;
  }
  if ( *v23 != 8210 )
    goto LABEL_18;
  v27 = PnpMultiSzGetLen(v19);
  if ( 2 * v27 <= (unsigned int)*a8 )
  {
    *a8 = 2 * v27;
LABEL_18:
    if ( *v23 != 18 || *a8 )
      return v21;
    *a8 = 0;
    *v23 = 0;
    return -1073741275;
  }
  v21 = -1073741595;
  *a8 = 0;
  return v21;
}
