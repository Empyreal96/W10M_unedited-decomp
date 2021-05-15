// NtCreateWnfStateName 
 
int __fastcall NtCreateWnfStateName(_BYTE *a1, unsigned int a2, unsigned int a3, int a4, unsigned int a5, unsigned int a6, int a7)
{
  _DWORD *v9; // r9
  unsigned int v10; // r5
  int v11; // lr
  unsigned __int8 *v12; // r0
  int v13; // r8
  int v14; // r6
  int v15; // r1
  int v16; // r2
  int v17; // r3
  unsigned int *v18; // r4
  unsigned int v19; // r5
  int v20; // r6
  int v21; // r5
  int v22; // r1
  int v23; // r4
  int v24; // lr
  int v25; // r9
  int v26; // r4
  char v27; // r3
  unsigned int v28; // r4
  unsigned int v29; // r1
  unsigned int v30; // r5
  unsigned int v31; // r4
  unsigned int v32; // r1
  __int16 v33; // r3
  int v35; // [sp+10h] [bp-70h]
  int v36; // [sp+18h] [bp-68h]
  int v37; // [sp+1Ch] [bp-64h] BYREF
  int v38; // [sp+20h] [bp-60h] BYREF
  int v39; // [sp+24h] [bp-5Ch]
  int v40; // [sp+28h] [bp-58h] BYREF
  int v41; // [sp+2Ch] [bp-54h]
  _DWORD v42[3]; // [sp+30h] [bp-50h] BYREF
  unsigned int v43; // [sp+3Ch] [bp-44h]
  int v44; // [sp+40h] [bp-40h]
  _DWORD *v45; // [sp+44h] [bp-3Ch]
  int v46; // [sp+48h] [bp-38h]
  int v47; // [sp+4Ch] [bp-34h]
  _DWORD _50[17]; // [sp+50h] [bp-30h] BYREF
  int varg_r3; // [sp+94h] [bp+14h]

  _50[14] = a1;
  varg_r3 = a4;
  v39 = a4;
  LOBYTE(varg_r3) = a4;
  v43 = a3;
  _50[16] = a3;
  _50[15] = a2;
  v42[0] = a1;
  v40 = (int)a1;
  v9 = (_DWORD *)a5;
  v44 = a7;
  v46 = a7;
  v10 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v10 + 0x134);
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v35 = v11;
  v12 = 0;
  v38 = 0;
  v13 = 0;
  v37 = 0;
  v45 = (_DWORD *)a5;
  if ( v11 )
  {
    if ( (unsigned int)a1 >= MmUserProbeAddress )
      *(_BYTE *)MmUserProbeAddress = 0;
    *a1 = *a1;
    a1[7] = a1[7];
    if ( a5 )
    {
      if ( a5 >= MmUserProbeAddress )
        v9 = (_DWORD *)MmUserProbeAddress;
      _50[0] = *v9;
      _50[1] = v9[1];
      _50[2] = v9[2];
      _50[3] = v9[3];
      v9 = _50;
      v45 = _50;
    }
    if ( !a7 )
    {
      v14 = -1073741819;
      v47 = -1073741819;
LABEL_44:
      v23 = 0;
      goto LABEL_45;
    }
    v12 = (unsigned __int8 *)SeCaptureSecurityDescriptor(a7, v11, 1, 1, &v37);
    v14 = (int)v12;
    v47 = (int)v12;
    if ( (int)v12 < 0 )
    {
      v13 = v37;
      goto LABEL_44;
    }
    v13 = v37;
    v18 = (unsigned int *)v42[0];
  }
  else
  {
    v12 = (unsigned __int8 *)SeCaptureSecurityDescriptor(a7, 0, 1, 1, &v37);
    v14 = (int)v12;
    v13 = v37;
    if ( (int)v12 < 0 )
    {
      v23 = 0;
      goto LABEL_45;
    }
    v18 = (unsigned int *)v42[0];
  }
  v12 = (unsigned __int8 *)ExpWnfSpecializeSecurityDescriptor(v13, v15, v16, v17);
  if ( a2 > 3 )
    goto LABEL_42;
  if ( !a2 )
    goto LABEL_42;
  v19 = v43;
  if ( v43 > 3 )
    goto LABEL_42;
  v20 = v39;
  if ( v39 )
  {
    if ( v43 || a2 != 1 )
      goto LABEL_42;
  }
  if ( a6 > 0x1000 )
    goto LABEL_42;
  if ( a2 == 3 )
  {
    if ( v43 != 3 )
      goto LABEL_27;
LABEL_42:
    v14 = -1073741811;
    goto LABEL_44;
  }
  v12 = (unsigned __int8 *)SeSinglePrivilegeCheck(
                             SeCreatePermanentPrivilege,
                             dword_9227A4,
                             v11,
                             (int)&SeCreatePermanentPrivilege);
  if ( !v12 )
  {
    v14 = -1073741727;
    goto LABEL_44;
  }
LABEL_27:
  v12 = (unsigned __int8 *)ExpWnfGenerateStateName(&v40, a2, v19, v20);
  v14 = (int)v12;
  if ( (int)v12 < 0 )
    goto LABEL_44;
  v21 = v40;
  v22 = v41;
  v39 = v41;
  *v18 = v40 ^ 0xA3BC0074;
  v18[1] = v22 ^ 0x41C64E6D;
  v23 = 0;
  v24 = v43;
  v42[0] = a6;
  v42[1] = v9;
  v42[2] = v13;
  if ( a2 != 3 )
  {
    v12 = (unsigned __int8 *)ExpWnfRegisterPermanentName(v21, v22, v42, &MmUserProbeAddress);
    v14 = (int)v12;
LABEL_45:
    v25 = v35;
    goto LABEL_46;
  }
  v25 = v35;
  if ( v35 )
  {
    v26 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74);
    v27 = 0;
  }
  else
  {
    v26 = PsInitialSystemProcess;
    v27 = 1;
  }
  v12 = (unsigned __int8 *)ExpWnfResolveScopeInstance(&v38, v26, 0, v24, 0, v27);
  v14 = (int)v12;
  if ( (int)v12 < 0 )
  {
    v23 = v38;
  }
  else
  {
    v36 = v38;
    v12 = (unsigned __int8 *)ExpWnfCreateNameInstance(v38, v38, v21, v39, v42, v26, &v40);
    v14 = (int)v12;
    if ( (int)v12 >= 0 )
    {
      v12 = (unsigned __int8 *)(v40 + 4);
      __pld((void *)(v40 + 4));
      v28 = *(_DWORD *)v12 & 0xFFFFFFFE;
      __dmb(0xBu);
      do
        v29 = __ldrex((unsigned int *)v12);
      while ( v29 == v28 && __strex(v28 - 2, (unsigned int *)v12) );
      if ( v29 != v28 )
        v12 = ExfReleaseRundownProtection(v12);
    }
    v23 = v36;
  }
LABEL_46:
  if ( v23 )
  {
    v12 = (unsigned __int8 *)(v23 + 4);
    __pld((void *)(v23 + 4));
    v30 = *(_DWORD *)(v23 + 4) & 0xFFFFFFFE;
    __dmb(0xBu);
    do
      v31 = __ldrex((unsigned int *)v12);
    while ( v31 == v30 && __strex(v30 - 2, (unsigned int *)v12) );
    if ( v31 != v30 )
      v12 = ExfReleaseRundownProtection(v12);
  }
  if ( v13 && v13 != v44 )
    v12 = (unsigned __int8 *)SeReleaseSecurityDescriptor(v13, v25, 1);
  v32 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v33 = *(_WORD *)(v32 + 0x134) + 1;
  *(_WORD *)(v32 + 308) = v33;
  if ( !v33 && *(_DWORD *)(v32 + 100) != v32 + 100 && !*(_WORD *)(v32 + 310) )
    KiCheckForKernelApcDelivery((int)v12);
  return v14;
}
