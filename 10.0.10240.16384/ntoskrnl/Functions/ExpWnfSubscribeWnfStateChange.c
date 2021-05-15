// ExpWnfSubscribeWnfStateChange 
 
int __fastcall ExpWnfSubscribeWnfStateChange(unsigned __int64 *a1, unsigned int *a2, int a3, int a4, int a5, int a6, int a7, char a8)
{
  unsigned int v8; // r8
  int v9; // r10
  _DWORD *v10; // r5
  int v11; // r9
  int v12; // r6
  int v13; // r10
  int v14; // r6
  int v15; // r4
  int v16; // r1
  int v17; // r2
  int v18; // r0
  int v19; // r0
  unsigned int *v20; // r0
  unsigned int v21; // r4
  unsigned int v22; // r1
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  unsigned int *v26; // r0
  unsigned int v27; // r4
  unsigned int v28; // r1
  int v29; // r2
  unsigned int v30; // r3
  unsigned int *v31; // r0
  unsigned int v32; // r4
  unsigned int v33; // r1
  unsigned int *v34; // r0
  unsigned int v35; // r4
  unsigned int v36; // r1
  unsigned int *v37; // r0
  unsigned int v38; // r5
  unsigned int v39; // r4
  unsigned int v41; // [sp+20h] [bp-68h]
  _DWORD *v42; // [sp+24h] [bp-64h] BYREF
  unsigned int v43; // [sp+28h] [bp-60h]
  int v44; // [sp+2Ch] [bp-5Ch] BYREF
  unsigned int v45; // [sp+30h] [bp-58h] BYREF
  int v46; // [sp+34h] [bp-54h]
  int v47; // [sp+38h] [bp-50h]
  int v48; // [sp+3Ch] [bp-4Ch]
  int v49; // [sp+40h] [bp-48h]
  unsigned int v50; // [sp+44h] [bp-44h] BYREF
  __int64 v51; // [sp+48h] [bp-40h] BYREF
  int v52; // [sp+50h] [bp-38h]
  int v53; // [sp+54h] [bp-34h]
  unsigned __int64 *v54; // [sp+58h] [bp-30h]
  unsigned int *v55; // [sp+5Ch] [bp-2Ch]
  int v56; // [sp+60h] [bp-28h]
  int v57; // [sp+64h] [bp-24h]
  unsigned __int64 *varg_r0; // [sp+90h] [bp+8h]
  unsigned int *varg_r1; // [sp+94h] [bp+Ch]
  int varg_r2; // [sp+98h] [bp+10h]
  int varg_r3; // [sp+9Ch] [bp+14h]

  varg_r2 = a3;
  v53 = a4;
  varg_r3 = a4;
  v55 = a2;
  varg_r1 = a2;
  v54 = a1;
  varg_r0 = a1;
  v8 = 0;
  v43 = 0;
  v9 = 0;
  v44 = 0;
  v10 = 0;
  v42 = 0;
  v11 = 0;
  v41 = 0;
  v45 = 0;
  v46 = 0;
  v49 = 0;
  v47 = a8;
  v12 = ExpCaptureWnfStateName(a3, &v51, a8);
  v57 = v12;
  if ( v12 < 0 )
  {
LABEL_72:
    v30 = v41;
    goto LABEL_73;
  }
  if ( (a7 & 0xFFFFFFE0) != 0 )
  {
    v12 = -1073741811;
    goto LABEL_72;
  }
  v13 = v51;
  v50 = ((unsigned int)v51 >> 4) & 3;
  v56 = v51 >> 6;
  if ( a8 )
  {
    v52 = 0;
    if ( (a7 & 0x11) != 0 )
    {
      v11 = 1;
      v46 = 1;
    }
    if ( (a7 & 0xFFFFFFEE) != 0 )
      v46 = v11 | 2;
  }
  else
  {
    v52 = 1;
  }
  if ( a8 )
    v14 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  else
    v14 = PsInitialSystemProcess;
  v48 = v14;
  v15 = !PsIsCurrentThreadInServerSilo();
  v12 = ExpWnfResolveScopeInstance(&v44, v14, 0, v56 & 0xF, 0, v15);
  if ( v12 < 0 )
  {
LABEL_54:
    v9 = v44;
    goto LABEL_72;
  }
  while ( 1 )
  {
    v17 = v13;
    v9 = v44;
    v18 = ExpWnfLookupNameInstance(v44, v16, v17, HIDWORD(v51), &v42);
    v12 = v18;
    if ( v18 == -1073741772 && v50 != 3 )
    {
      v19 = ExpWnfLookupPermanentName(v51);
      v12 = v19;
      if ( v19 >= 0 )
      {
        v8 = v43;
        if ( !v52 )
        {
          v12 = ExpWnfCheckCallerAccess(*(_DWORD *)(v43 + 8), v46);
          if ( v12 < 0 )
            goto LABEL_49;
        }
        v12 = ExpWnfCreateNameInstance(v9, &v42, v51, HIDWORD(v51), v8, v48, &v42);
        ExFreePoolWithTag(v8);
        v8 = 0;
        v10 = v42;
        goto LABEL_51;
      }
      if ( v19 != -1073741772 || v15 )
        goto LABEL_55;
      v49 = 1;
      if ( v9 )
      {
        v20 = (unsigned int *)(v9 + 4);
        __pld((void *)(v9 + 4));
        v21 = *(_DWORD *)(v9 + 4) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v22 = __ldrex(v20);
        while ( v22 == v21 && __strex(v21 - 2, v20) );
        if ( v22 != v21 )
          ExfReleaseRundownProtection((unsigned __int8 *)v20);
      }
      v10 = v42;
      if ( v42 )
      {
        v23 = v42 + 1;
        __pld(v42 + 1);
        v24 = v42[1] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v25 = __ldrex(v23);
        while ( v25 == v24 && __strex(v24 - 2, v23) );
        goto LABEL_43;
      }
      goto LABEL_45;
    }
    if ( v18 >= 0 )
      break;
    if ( v18 != -1073741772 || v15 )
    {
LABEL_55:
      v8 = v43;
LABEL_49:
      v10 = v42;
      goto LABEL_72;
    }
    v49 = 1;
    if ( v9 )
    {
      v26 = (unsigned int *)(v9 + 4);
      __pld((void *)(v9 + 4));
      v27 = *(_DWORD *)(v9 + 4) & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v28 = __ldrex(v26);
      while ( v28 == v27 && __strex(v27 - 2, v26) );
      if ( v28 != v27 )
        ExfReleaseRundownProtection((unsigned __int8 *)v26);
    }
    v10 = v42;
    if ( v42 )
    {
      v23 = v42 + 1;
      __pld(v42 + 1);
      v24 = v42[1] & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v25 = __ldrex(v23);
      while ( v25 == v24 && __strex(v24 - 2, v23) );
LABEL_43:
      if ( v25 != v24 )
        ExfReleaseRundownProtection((unsigned __int8 *)v23);
    }
LABEL_45:
    v12 = ExpWnfResolveScopeInstance(&v44, v48, 0, v56 & 0xF, 0, 1);
    if ( v12 < 0 )
    {
      v8 = v43;
      goto LABEL_54;
    }
    v15 = v49;
    v13 = v51;
  }
  v10 = v42;
  if ( v52 )
  {
    v8 = v43;
    goto LABEL_59;
  }
  v12 = ExpWnfCheckCallerAccess(v42[11], v46);
  v8 = v43;
LABEL_51:
  if ( v12 < 0 )
    goto LABEL_72;
LABEL_59:
  v12 = ExpWnfSubscribeNameInstance((int)v10, v48, a5, a6, v53, a7, v47, v54, v55, &v45, &v50);
  if ( v12 >= 0 )
  {
    v29 = 0;
    if ( v53 != v10[14] && v10[13] )
      v29 = 1;
    if ( !v10[23] )
      v29 |= 8u;
    if ( !v50 )
    {
      if ( v10[22] )
        v29 |= 2u;
      else
        v29 |= 4u;
    }
    if ( (v29 & a7) != 0 )
    {
      v41 = v45;
      ExpWnfNotifySubscription(v10);
      goto LABEL_72;
    }
  }
  v30 = v45;
LABEL_73:
  if ( v30 )
  {
    v31 = (unsigned int *)(v30 + 4);
    __pld((void *)(v30 + 4));
    v32 = *(_DWORD *)(v30 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v33 = __ldrex(v31);
    while ( v33 == v32 && __strex(v32 - 2, v31) );
    if ( v33 != v32 )
      ExfReleaseRundownProtection((unsigned __int8 *)v31);
  }
  if ( v10 )
  {
    v34 = v10 + 1;
    __pld(v10 + 1);
    v35 = v10[1] & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v36 = __ldrex(v34);
    while ( v36 == v35 && __strex(v35 - 2, v34) );
    if ( v36 != v35 )
      ExfReleaseRundownProtection((unsigned __int8 *)v34);
  }
  if ( v9 )
  {
    v37 = (unsigned int *)(v9 + 4);
    __pld((void *)(v9 + 4));
    v38 = *(_DWORD *)(v9 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v39 = __ldrex(v37);
    while ( v39 == v38 && __strex(v38 - 2, v37) );
    if ( v39 != v38 )
      ExfReleaseRundownProtection((unsigned __int8 *)v37);
  }
  if ( v8 )
    ExFreePoolWithTag(v8);
  return v12;
}
