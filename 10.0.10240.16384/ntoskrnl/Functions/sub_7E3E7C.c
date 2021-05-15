// sub_7E3E7C 
 
void __fastcall sub_7E3E7C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, const __int16 *a16, int a17, int a18, int *a19, int a20, int a21, int a22)
{
  int v22; // r5
  int v23; // r6
  unsigned __int16 *v24; // r9
  int v25; // r10
  unsigned __int16 *v26; // r7
  unsigned __int16 *v27; // r8
  int v28; // r9
  int v29; // r3
  unsigned __int16 *i; // r4
  unsigned __int16 *v31; // r4
  unsigned __int16 *v32; // r5
  unsigned __int16 *v33; // r6
  unsigned __int16 *v34; // r5
  int v35; // r2
  int v36; // r7
  int v37; // r1
  int v38; // r8
  unsigned __int16 *v39; // r4
  int v40; // r3
  unsigned __int16 *j; // r9
  int v42; // r3
  unsigned __int16 *k; // r9
  char v44[4]; // [sp+0h] [bp-70h] BYREF
  int v45; // [sp+4h] [bp-6Ch]
  int v46; // [sp+8h] [bp-68h]
  int v47; // [sp+Ch] [bp-64h]
  int v48; // [sp+10h] [bp-60h]
  unsigned __int16 *v49; // [sp+14h] [bp-5Ch] BYREF
  unsigned __int16 *v50; // [sp+18h] [bp-58h] BYREF
  unsigned __int16 *v51; // [sp+1Ch] [bp-54h] BYREF
  int v52[2]; // [sp+20h] [bp-50h] BYREF
  __int16 v53[2]; // [sp+28h] [bp-48h] BYREF
  const __int16 *v54; // [sp+2Ch] [bp-44h]
  int v55; // [sp+30h] [bp-40h]
  int v56; // [sp+34h] [bp-3Ch]
  __int16 *v57; // [sp+38h] [bp-38h]
  int v58; // [sp+3Ch] [bp-34h]
  int v59; // [sp+40h] [bp-30h]
  int v60; // [sp+44h] [bp-2Ch]

  a15 = 6422624;
  a16 = L"\\Registry\\Machine\\System\\DriverDatabase\\Policies";
  a17 = 24;
  a18 = 0;
  a19 = &a15;
  a21 = 0;
  a22 = 0;
  if ( ZwOpenKey() < 0 )
    goto LABEL_73;
  v53[1] = 26;
  v53[0] = 24;
  v54 = L"Restrictions";
  v45 = 0;
  v55 = 24;
  v58 = v22;
  v56 = v46;
  v57 = v53;
  v59 = 0;
  v60 = 0;
  if ( ZwOpenKey() < 0 )
LABEL_73:
    JUMPOUT(0x77C688);
  v25 = 0;
  v48 = 0;
  if ( PiDevCfgQueryPolicyEnabled(v45, L"DenyRemovableDevices", v44) >= 0
    && v44[0]
    && (*(_DWORD *)(v23 + 368) & 0x10) != 0 )
  {
    v25 = 1;
  }
  if ( PiDevCfgQueryPolicyStringList(v45, L"AllowDeviceClasses", &v49) >= 0 )
    v26 = v49;
  else
    v26 = 0;
  v49 = v26;
  if ( PiDevCfgQueryPolicyStringList(v45, L"DenyDeviceClasses", &v50) >= 0 )
    v27 = v50;
  else
    v27 = 0;
  v50 = v27;
  if ( v24 )
  {
    if ( v26 )
    {
      v29 = *v26;
      for ( i = v26; ; v29 = *i )
      {
        if ( !v29 )
        {
          v28 = 0;
          goto LABEL_23;
        }
        if ( !wcsicmp((int)i, v24) )
          break;
        i += wcslen(i) + 1;
      }
      v28 = 1;
      v48 = 1;
LABEL_23:
      if ( v27 )
      {
        v31 = v27;
        if ( *v27 )
        {
          v32 = (unsigned __int16 *)v52[1];
          while ( wcsicmp((int)v31, v32) )
          {
            v31 += wcslen(v31) + 1;
            if ( !*v31 )
              goto LABEL_31;
          }
          v25 = 1;
        }
      }
    }
    else
    {
      v28 = 0;
      if ( v27 )
        goto LABEL_23;
    }
  }
  else
  {
    v28 = 0;
  }
LABEL_31:
  if ( PiDevCfgQueryPolicyStringList(v45, L"AllowDeviceIDs", &v51) >= 0 )
    v33 = v51;
  else
    v33 = 0;
  if ( PiDevCfgQueryPolicyStringList(v45, L"DenyDeviceIDs", v52) >= 0 )
    v34 = (unsigned __int16 *)v52[0];
  else
    v34 = 0;
  if ( v33 || v34 )
  {
    v35 = 2;
    v36 = 0;
    v37 = v47;
    v38 = 0;
    v52[0] = 2;
    do
    {
      v39 = *(unsigned __int16 **)(v37 + 16);
      if ( v39 && *v39 )
      {
        do
        {
          if ( v33 && !v38 )
          {
            v40 = *v33;
            for ( j = v33; ; v40 = *j )
            {
              if ( !v40 )
                goto LABEL_50;
              if ( !wcsicmp((int)j, v39) )
                break;
              j += wcslen(j) + 1;
            }
            v48 = 1;
            v38 = 1;
          }
LABEL_50:
          if ( v34 && !v36 )
          {
            v42 = *v34;
            for ( k = v34; ; v42 = *k )
            {
              if ( !v42 )
                goto LABEL_58;
              if ( !wcsicmp((int)k, v39) )
                break;
              k += wcslen(k) + 1;
            }
            v36 = 1;
            v25 = 1;
          }
LABEL_58:
          v39 += wcslen(v39) + 1;
        }
        while ( *v39 );
        v35 = v52[0];
        v37 = v47;
      }
      v37 += 8;
      v52[0] = --v35;
      v47 = v37;
    }
    while ( v35 );
    v26 = v49;
    v27 = v50;
    v28 = v48;
  }
  if ( !v25 && !v28 )
    PiDevCfgQueryPolicyEnabled(v45, L"DenyUnspecified", v44);
  if ( v26 )
    ExFreePoolWithTag((unsigned int)v26);
  if ( v27 )
    ExFreePoolWithTag((unsigned int)v27);
  if ( v33 )
    ExFreePoolWithTag((unsigned int)v33);
  if ( v34 )
    ExFreePoolWithTag((unsigned int)v34);
  JUMPOUT(0x77C68A);
}
