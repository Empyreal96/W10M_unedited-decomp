// ObDuplicateObject 
 
int __fastcall ObDuplicateObject(int a1, int a2, int a3, int *a4, int a5, int a6, char a7, char a8)
{
  int v8; // r8
  int v10; // r9
  char v12; // r7
  int v13; // r10
  int v14; // r6
  int v15; // r0
  int v16; // r4
  int v17; // r9
  int v18; // r9
  int v19; // r3
  int result; // r0
  int v21; // r0
  int v22; // r8
  int v23; // r4
  int v24; // r6
  int v25; // lr
  int v26; // r0
  int v27; // r1
  char *v28; // r10
  int v29; // r9
  int v30; // r4
  int v31; // r2
  bool v32; // zf
  int v33; // r7
  int v34; // r7
  int v35; // r6
  int v36; // r8
  unsigned int *v37; // r0
  unsigned int v38; // r4
  unsigned int v39; // r1
  int v40; // r3
  int v41; // r3
  int v42; // r0
  unsigned int *v43; // r0
  unsigned int v44; // r4
  unsigned int v45; // r1
  unsigned int *v46; // r0
  unsigned int v47; // r4
  unsigned int v48; // r1
  BOOL v49; // r4
  int v50; // r5
  unsigned int *v51; // r0
  unsigned int v52; // r4
  unsigned int v53; // r1
  unsigned int *v54; // r0
  unsigned int v55; // r4
  unsigned int v56; // r1
  int v57; // r0
  int v58; // r6
  unsigned int *v59; // r0
  unsigned int v60; // r4
  unsigned int v61; // r1
  unsigned int *v62; // r0
  unsigned int v63; // r5
  unsigned int v64; // r4
  int v65; // r4
  unsigned int *v66; // r0
  unsigned int v67; // r4
  unsigned int v68; // r1
  int v69; // [sp+0h] [bp-1C0h]
  int v70; // [sp+10h] [bp-1B0h] BYREF
  int v71; // [sp+14h] [bp-1ACh] BYREF
  unsigned int v72; // [sp+18h] [bp-1A8h]
  BOOL v73; // [sp+1Ch] [bp-1A4h]
  int v74; // [sp+20h] [bp-1A0h]
  int v75; // [sp+24h] [bp-19Ch] BYREF
  int v76; // [sp+28h] [bp-198h] BYREF
  int v77; // [sp+2Ch] [bp-194h]
  int v78; // [sp+30h] [bp-190h]
  int v79; // [sp+34h] [bp-18Ch]
  int v80; // [sp+38h] [bp-188h]
  int v81[2]; // [sp+40h] [bp-180h] BYREF
  char v82[24]; // [sp+48h] [bp-178h] BYREF
  char v83[120]; // [sp+60h] [bp-160h] BYREF
  char v84[232]; // [sp+D8h] [bp-E8h] BYREF
  int varg_r0; // [sp+1C8h] [bp+8h]
  int varg_r1; // [sp+1CCh] [bp+Ch]
  int varg_r2; // [sp+1D0h] [bp+10h]
  int *varg_r3; // [sp+1D4h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v8 = a3;
  v78 = a2;
  v79 = a3;
  v10 = a8;
  v74 = a1;
  if ( (a6 & 0x200) != 0 && !a8 )
  {
    v8 = PsInitialSystemProcess;
    v79 = PsInitialSystemProcess;
  }
  v72 = a6 & 0xFFFFFDFF;
  if ( a4 )
    *a4 = 0;
  v12 = a7;
  v13 = a5;
  v14 = a7 & 2;
  if ( (a7 & 2) == 0 )
  {
    result = ObpValidateDesiredAccess(a5);
    if ( result < 0 )
      return result;
  }
  v15 = ObReferenceProcessHandleTable(a1);
  if ( !v15 )
    return -1073741558;
  v16 = v74;
  v17 = ObpReferenceProcessObjectByHandle(v78, v74, v15, v10, 1850237519, &v70, &v76, &v75);
  v73 = v17;
  if ( v17 < 0 )
  {
    v66 = (unsigned int *)(v16 + 172);
    __pld((void *)(v16 + 172));
    v67 = *(_DWORD *)(v16 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v68 = __ldrex(v66);
    while ( v68 == v67 && __strex(v67 - 2, v66) );
    if ( v68 != v67 )
      ExfReleaseRundownProtection((unsigned __int8 *)v66);
    return v17;
  }
  v18 = v76;
  if ( (v76 & 4) != 0 )
    v19 = v75;
  else
    v19 = 0;
  v80 = v19;
  if ( !v8 )
    return sub_7F71B8();
  v21 = ObReferenceProcessHandleTable(v8);
  v22 = v21;
  if ( !v21 )
  {
    if ( (v12 & 1) != 0 )
    {
      KiStackAttachProcess(v16, 0, (int)v82);
      NtClose();
      KiUnstackDetachProcess((unsigned int)v82, 0);
    }
    v43 = (unsigned int *)(v16 + 172);
    __pld((void *)(v16 + 172));
    v44 = *(_DWORD *)(v16 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v45 = __ldrex(v43);
    while ( v45 == v44 && __strex(v44 - 2, v43) );
    if ( v45 != v44 )
      ExfReleaseRundownProtection((unsigned __int8 *)v43);
    ObfDereferenceObjectWithTag(v70);
    return -1073741558;
  }
  v73 = v21 == ObpKernelHandleTable;
  v23 = v77;
  if ( v14 )
  {
    v13 = v77;
    a5 = v77;
  }
  if ( (v12 & 4) != 0 )
    v24 = v18;
  else
    v24 = v18 & 0xC | v72;
  if ( (v12 & 8) != 0 )
    v24 |= 8u;
  v25 = v70;
  v26 = ObTypeIndexTable[(unsigned __int8)((unsigned __int16)(v70 - 24) >> 8) ^ (unsigned __int8)ObHeaderCookie ^ *(unsigned __int8 *)(v70 - 12)];
  v72 = v26;
  if ( (v13 & 0xF0000000) != 0 )
  {
    RtlMapGenericMask(&a5, v26 + 52);
    v25 = v70;
    v13 = a5;
    v26 = v72;
  }
  v27 = (*(_DWORD *)(v26 + 68) | 0x1000000) & v13;
  v75 = 0;
  v71 = v27;
  v28 = 0;
  if ( (v27 & ~v23) == 0 )
  {
    v29 = v79;
    v30 = a8;
LABEL_22:
    v31 = ObpIncrementHandleCountEx(2, &v71, v29, v25, v30, v24, 0);
    v76 = v31;
    goto LABEL_23;
  }
  if ( (v18 & 8) != 0 || *(int (**)(int, int, int, int))(v26 + 108) != SeDefaultObjectMethod )
  {
    v31 = -1073741790;
    v29 = v79;
    v76 = -1073741790;
    goto LABEL_26;
  }
  v40 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
  v29 = v79;
  if ( v40 != v79 )
  {
    KiStackAttachProcess(v79, 0, (int)v82);
    v26 = v72;
    v75 = 1;
  }
  SeCreateAccessState((int)v83, (int)v84, v71, (_DWORD *)(v26 + 52));
  v30 = a8;
  v28 = v83;
  v31 = ObpGrantAccess(2, v70, (int)v83, a8, v24, &v71);
  v76 = v31;
  if ( v31 >= 0 )
  {
    v25 = v70;
    goto LABEL_22;
  }
LABEL_23:
  if ( v75 )
  {
    KiUnstackDetachProcess((unsigned int)v82, 0);
    v31 = v76;
  }
  v27 = v71;
  v26 = v72;
  v25 = v70;
LABEL_26:
  v32 = (v12 & 1) == 0;
  v33 = v74;
  if ( !v32 )
  {
    KiStackAttachProcess(v74, 0, (int)v82);
    NtClose();
    KiUnstackDetachProcess((unsigned int)v82, 0);
    v25 = v70;
    v27 = v71;
    v31 = v76;
    v26 = v72;
  }
  if ( v31 < 0 )
  {
    if ( v28 )
    {
      SepDeleteAccessState((int)v28);
      SeReleaseSubjectContext((int)(v28 + 28));
      v25 = v70;
    }
    v46 = (unsigned int *)(v33 + 172);
    __pld((void *)(v33 + 172));
    v47 = *(_DWORD *)(v33 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v48 = __ldrex(v46);
    while ( v48 == v47 && __strex(v47 - 2, v46) );
    if ( v48 != v47 )
    {
      ExfReleaseRundownProtection((unsigned __int8 *)v46);
      v25 = v70;
    }
    v37 = (unsigned int *)(v29 + 172);
    __pld((void *)(v29 + 172));
    v38 = *(_DWORD *)(v29 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v39 = __ldrex(v37);
    while ( v39 == v38 && __strex(v38 - 2, v37) );
    if ( v39 != v38 )
    {
      ExfReleaseRundownProtection((unsigned __int8 *)v37);
      v25 = v70;
    }
    ObfDereferenceObjectWithTag(v25);
    result = v76;
  }
  else
  {
    if ( v28 && v28[10] )
    {
      LOBYTE(v24) = v24 | 4;
      v80 = *(_DWORD *)(*((_DWORD *)v28 + 12) + 24);
    }
    v81[1] = (int)v81;
    v81[0] = (int)v81;
    v49 = v73;
    if ( (*(_BYTE *)(v26 + 42) & 0x40) != 0 && *(_DWORD *)(v26 + 136) != v26 + 136 )
    {
      v75 = v27;
      v76 = ObpPreInterceptHandleDuplicate(v25, v73);
      if ( v76 < 0 )
      {
        v50 = v70;
        ObpDecrementHandleCount(v29, v70 - 24);
        if ( v28 )
        {
          SepDeleteAccessState((int)v28);
          SeReleaseSubjectContext((int)(v28 + 28));
        }
        v51 = (unsigned int *)(v33 + 172);
        __pld((void *)(v33 + 172));
        v52 = *(_DWORD *)(v33 + 172) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v53 = __ldrex(v51);
        while ( v53 == v52 && __strex(v52 - 2, v51) );
        if ( v53 != v52 )
          ExfReleaseRundownProtection((unsigned __int8 *)v51);
        v54 = (unsigned int *)(v29 + 172);
        __pld((void *)(v29 + 172));
        v55 = *(_DWORD *)(v29 + 172) & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v56 = __ldrex(v54);
        while ( v56 == v55 && __strex(v55 - 2, v54) );
        if ( v56 != v55 )
          ExfReleaseRundownProtection((unsigned __int8 *)v54);
        ObfDereferenceObjectWithTag(v50);
        return v76;
      }
      if ( !v49 )
        v71 = v75;
    }
    v69 = v80;
    v34 = ExCreateHandleEx(v22);
    if ( v34 )
    {
      if ( v28 )
      {
        v42 = 0;
        v41 = *(unsigned __int8 *)(v70 - 10);
        if ( (v41 & 0x20) != 0 )
        {
          v41 = v70 - 24 - ObpInfoMaskToOffset[v41 & 0x3F];
          if ( v41 )
            v42 = *(_DWORD *)v41;
        }
        SeAuditHandleCreation((int)v28, v34, v42, v41);
      }
      if ( (v24 & 4) != 0 )
      {
        v57 = SeAuditingWithTokenForSubcategory(123);
        v35 = v74;
        if ( v57 )
          SeAuditHandleDuplication(v78, v34, v74, v29, v69);
      }
      else
      {
        v35 = v74;
      }
      v36 = v76;
    }
    else
    {
      v58 = v70;
      ObpDecrementHandleCount(v29, v70 - 24);
      ObfDereferenceObjectWithTag(v58);
      v36 = -1073741670;
      v35 = v74;
    }
    if ( v49 )
      v34 |= 0x80000000;
    if ( a4 )
      *a4 = v34;
    if ( v28 )
    {
      SepDeleteAccessState((int)v28);
      SeReleaseSubjectContext((int)(v28 + 28));
    }
    v59 = (unsigned int *)(v35 + 172);
    __pld((void *)(v35 + 172));
    v60 = *(_DWORD *)(v35 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v61 = __ldrex(v59);
    while ( v61 == v60 && __strex(v60 - 2, v59) );
    if ( v61 != v60 )
      ExfReleaseRundownProtection((unsigned __int8 *)v59);
    v62 = (unsigned int *)(v29 + 172);
    __pld((void *)(v29 + 172));
    v63 = *(_DWORD *)(v29 + 172) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v64 = __ldrex(v62);
    while ( v64 == v63 && __strex(v63 - 2, v62) );
    if ( v64 != v63 )
      ExfReleaseRundownProtection((unsigned __int8 *)v62);
    v65 = v70;
    if ( (int *)v81[0] != v81 )
      ObpPostInterceptHandleDuplicate(v70, v73, v36, v71, v81);
    if ( (dword_682610 & 0x40) != 0 && v36 >= 0 )
      EtwTraceDuplicateHandle(v78, v34, v65, *(_DWORD *)(v35 + 176), *(_DWORD *)(v29 + 176), v72);
    result = v36;
  }
  return result;
}
