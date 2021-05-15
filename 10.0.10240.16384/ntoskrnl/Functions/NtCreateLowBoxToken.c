// NtCreateLowBoxToken 
 
int __fastcall NtCreateLowBoxToken(_DWORD *a1, int a2, int a3, int a4, int a5, unsigned int a6, int a7, unsigned int a8, unsigned int a9)
{
  unsigned int v9; // r8
  int *v10; // r5
  int v11; // r2
  _DWORD *v12; // r2
  unsigned int v13; // r0
  int v14; // r9
  unsigned int v15; // r3
  int v17; // r0
  int v18; // r4
  unsigned __int16 *v19; // r3
  unsigned int v20; // r4
  unsigned int v21; // r8
  unsigned __int16 **v22; // r9
  unsigned __int16 **i; // r2
  int v24; // r8
  unsigned __int16 *v25; // t1
  int v26; // r2
  int v27; // r3
  int *v28; // r0
  int v29; // r0
  int v30; // r0
  int v31; // r3
  int v32; // r3
  int v33; // r3
  int v34; // r0
  __int16 v35; // r3
  int v36; // r3
  int v37; // r0
  unsigned int v38; // r1
  __int16 v39; // r3
  int v40; // r5
  int v42; // [sp+0h] [bp-A0h]
  int v43; // [sp+0h] [bp-A0h]
  int v44; // [sp+4h] [bp-9Ch]
  int v45; // [sp+4h] [bp-9Ch]
  unsigned __int16 **v46; // [sp+18h] [bp-88h]
  unsigned __int16 *v47; // [sp+1Ch] [bp-84h]
  unsigned int v48; // [sp+20h] [bp-80h] BYREF
  char v49; // [sp+24h] [bp-7Ch]
  int v50; // [sp+28h] [bp-78h]
  char v51; // [sp+2Ch] [bp-74h]
  char v52; // [sp+2Dh] [bp-73h]
  char v53; // [sp+2Eh] [bp-72h]
  unsigned __int16 *v54; // [sp+30h] [bp-70h]
  int v55; // [sp+34h] [bp-6Ch]
  int *v56; // [sp+38h] [bp-68h] BYREF
  int v57; // [sp+3Ch] [bp-64h] BYREF
  int v58; // [sp+44h] [bp-5Ch]
  unsigned __int16 *v59; // [sp+48h] [bp-58h]
  unsigned int v60; // [sp+4Ch] [bp-54h]
  int v61; // [sp+50h] [bp-50h] BYREF
  int v62; // [sp+54h] [bp-4Ch] BYREF
  _DWORD *v63; // [sp+58h] [bp-48h]
  int v64; // [sp+5Ch] [bp-44h]
  int v65; // [sp+60h] [bp-40h]
  int v66; // [sp+64h] [bp-3Ch]
  int v67; // [sp+68h] [bp-38h]
  int v68; // [sp+6Ch] [bp-34h]
  int v69; // [sp+70h] [bp-30h] BYREF
  int v70; // [sp+78h] [bp-28h] BYREF
  unsigned __int16 *v71; // [sp+7Ch] [bp-24h]
  _DWORD *varg_r0; // [sp+A8h] [bp+8h]
  int varg_r1; // [sp+ACh] [bp+Ch]
  int varg_r2; // [sp+B0h] [bp+10h]
  int varg_r3; // [sp+B4h] [bp+14h]

  v64 = a4;
  varg_r3 = a4;
  v59 = (unsigned __int16 *)a3;
  varg_r2 = a3;
  varg_r1 = a2;
  v63 = a1;
  varg_r0 = a1;
  v47 = 0;
  v54 = 0;
  v9 = 0;
  v48 = 0;
  v70 = 0;
  v71 = 0;
  v61 = 0;
  v10 = 0;
  v56 = 0;
  v69 = 1;
  v58 = 0;
  v51 = 0;
  v55 = 0;
  v52 = 0;
  v67 = 0;
  v68 = 0;
  v65 = 0;
  v66 = 0;
  v62 = 0;
  v49 = 0;
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v50 = v11;
  v53 = v11;
  if ( v11 )
  {
    v12 = a1;
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      v12 = (_DWORD *)MmUserProbeAddress;
    *v12 = *v12;
    v13 = a8;
    v60 = a8;
    v14 = a9;
    if ( 4 * a8 )
    {
      if ( (a9 & 3) != 0 )
        ExRaiseDatatypeMisalignment(a8);
      v15 = 4 * a8 + a9;
      if ( v15 > MmUserProbeAddress || v15 < a9 )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v11 = v50;
  }
  else
  {
    v14 = a9;
    v13 = a8;
    v60 = a8;
  }
  if ( a5 )
  {
    if ( v13 )
    {
      if ( v14 )
      {
LABEL_19:
        v17 = ObReferenceObjectByHandle(a2, 2, SeTokenObjectType, v11, &v57, &v70);
        if ( v17 < 0 )
          return v17;
        v17 = SeCaptureSid(a5, v50);
        if ( v17 < 0 )
          return v17;
        v18 = SepCheckCreateLowBox(0);
        if ( v18 < 0 )
          return v18;
        if ( *(_DWORD *)(v57 + 168) != 1 && *(int *)(v57 + 172) < 2 )
        {
          ObfDereferenceObject(v57);
          return -1073741659;
        }
        v19 = v59;
        if ( !v59 )
        {
          v19 = v71;
          v59 = v71;
        }
        if ( a7 )
        {
          v18 = SeCaptureSidAndAttributesArray(a7, a6, v50, 0, 0);
          v19 = v54;
          v47 = v54;
        }
        if ( v18 < 0 )
          goto LABEL_79;
        v18 = SepCaptureHandles(v60, v14, (int *)&v48, (int)v19);
        if ( v18 < 0 )
          goto LABEL_78;
        if ( !RtlIsPackageSid(0) )
          goto LABEL_33;
        if ( MEMORY[1] != 8 && MEMORY[1] != 12 )
        {
          v18 = -1073700350;
          goto LABEL_78;
        }
        v20 = 0;
        v21 = a6;
        if ( a6 )
        {
          v22 = (unsigned __int16 **)v47;
          for ( i = (unsigned __int16 **)v47; ; i = v46 )
          {
            v46 = i + 2;
            v54 = *i;
            if ( !RtlIsCapabilitySid(v54) )
            {
              v18 = -1073741811;
              goto LABEL_47;
            }
            v24 = 0;
            if ( v20 )
              break;
LABEL_44:
            ++v20;
            v21 = a6;
            if ( v20 >= a6 )
              goto LABEL_48;
          }
          while ( 1 )
          {
            v25 = *v22;
            v22 += 2;
            if ( RtlEqualSid(v54, v25) )
              break;
            if ( ++v24 >= v20 )
            {
              v22 = (unsigned __int16 **)v47;
              goto LABEL_44;
            }
          }
LABEL_33:
          v18 = -1073741811;
LABEL_78:
          v9 = v48;
          goto LABEL_79;
        }
LABEL_48:
        v18 = RtlGetAppContainerSidType(0, &v62);
        if ( v18 < 0 )
          goto LABEL_78;
        if ( v62 == 1 )
        {
          v22 = (unsigned __int16 **)v47;
          v18 = SepCheckCapabilities(v57, v21, v47);
          if ( !v49 )
          {
            v18 = -1073741790;
LABEL_47:
            v9 = v48;
            goto LABEL_80;
          }
        }
        if ( v18 < 0 )
          goto LABEL_78;
        v18 = SepDuplicateToken(v57, v64, 0, 1, 0, v50, 0, &v56);
        v10 = v56;
        if ( v18 < 0 )
          goto LABEL_78;
        v55 = 1;
        v18 = SeSetMandatoryPolicyToken(v56, &v69);
        if ( v18 < 0 )
          goto LABEL_78;
        v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v27 = *(__int16 *)(v26 + 0x134) - 1;
        *(_WORD *)(v26 + 308) = v27;
        ExAcquireResourceExclusiveLite(v10[12], 1, v26, v27);
        __dmb(0xFu);
        v58 = 1;
        v28 = (int *)SepLocateTokenIntegrity((int)v10);
        if ( v28 )
        {
          v29 = *v28;
          if ( *(_BYTE *)(v29 + 1) )
            *(_DWORD *)RtlSubAuthoritySid(v29, *(unsigned __int8 *)(v29 + 1) - 1) = 4096;
          v30 = AppContainerPrivilegesEnabledExt_0();
          v18 = v30;
          if ( v30 == -1073741637 )
          {
            v31 = v10[19] & 2;
            v10[18] &= 0x800000u;
            v10[19] = v31;
            v32 = v10[21] & 2;
            v10[20] &= 0x800000u;
            v18 = 0;
          }
          else
          {
            if ( v30 < 0 )
              goto LABEL_78;
            v33 = v68 & v10[19];
            v10[18] &= v67;
            v10[19] = v33;
            v32 = v66 & v10[21];
            v10[20] &= v65;
          }
          v10[21] = v32;
          v10[44] = v10[44] & 0xFFFF9FFF | 0x4000;
        }
        else
        {
          v18 = -1073740730;
        }
        if ( v18 < 0 )
          goto LABEL_78;
        v18 = SepSetTokenCapabilities((int)v10, 0, (int)v47, a6);
        if ( v18 < 0 )
          goto LABEL_78;
        v18 = SepSetTokenLowboxNumber(v10, 0);
        if ( v18 < 0 )
          goto LABEL_78;
        v9 = v48;
        v18 = SepSetTokenLowboxHandles((int)v10, 0, v60, v48);
        if ( v18 < 0 )
          goto LABEL_79;
        v18 = SepSetTokenPackage((int)v10, 0);
        if ( v18 < 0 )
          goto LABEL_79;
        v18 = SepAppendAceToTokenDefaultDacl((int)v10, 0);
        if ( v18 < 0 )
          goto LABEL_79;
        ExAllocateLocallyUniqueId(v10 + 13);
        __dmb(0xFu);
        ExReleaseResourceLite(v10[12]);
        v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
        v35 = *(_WORD *)(v34 + 0x134) + 1;
        *(_WORD *)(v34 + 308) = v35;
        if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
          KiCheckForKernelApcDelivery(v34);
        v58 = 0;
        v18 = ObInsertObject(v10, 0, v59, 1, 0, &v61);
        if ( v18 >= 0 )
        {
          v18 = SepAppendAceToTokenObjectAcl((int)v10, 983551, 0, v36, v42, v44);
          if ( v18 < 0 )
            goto LABEL_79;
          SepAppendAceToTokenObjectAcl(
            (int)v10,
            8,
            (unsigned __int16 *)SeAliasAdminsSid,
            (int)&SeAliasAdminsSid,
            v43,
            v45);
          ObfDereferenceObject((int)v10);
        }
        v55 = 0;
LABEL_79:
        v22 = (unsigned __int16 **)v47;
LABEL_80:
        if ( v58 )
        {
          if ( v18 >= 0 )
            ExAllocateLocallyUniqueId(v10 + 13);
          __dmb(0xFu);
          v37 = ExReleaseResourceLite(v10[12]);
          v38 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
          v39 = *(_WORD *)(v38 + 0x134) + 1;
          *(_WORD *)(v38 + 308) = v39;
          if ( !v39 && *(_DWORD *)(v38 + 100) != v38 + 100 && !*(_WORD *)(v38 + 310) )
            KiCheckForKernelApcDelivery(v37);
        }
        if ( v18 >= 0 )
        {
          v40 = v50;
        }
        else
        {
          if ( v55 )
            ObfDereferenceObject((int)v10);
          v40 = v50;
          if ( v61 )
            ObCloseHandle(v61);
        }
        if ( v22 )
          SeReleaseLuidAndAttributesArray(v22, v40);
        ObfDereferenceObject(v57);
        if ( v9 )
          ExFreePoolWithTag(v9);
        if ( v18 >= 0 )
          *v63 = v61;
        return v18;
      }
    }
    else if ( !v14 )
    {
      goto LABEL_19;
    }
    return -1073741776;
  }
  return -1073741811;
}
