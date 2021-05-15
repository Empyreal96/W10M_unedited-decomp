// NtOpenThreadTokenEx 
 
int __fastcall NtOpenThreadTokenEx(int a1, int a2, int a3, int a4, unsigned int a5)
{
  int v6; // r1
  int v7; // r3
  _DWORD *v8; // r10
  _DWORD *v9; // r2
  int v10; // r3
  int v11; // r0
  _DWORD *v13; // r8
  int v14; // r9
  int v15; // r4
  int v16; // r5
  unsigned int *v17; // r5
  int v18; // r0
  int v19; // r4
  unsigned int v20; // r2
  int v21; // r3
  int v22; // r3
  unsigned int *v23; // r1
  unsigned int v24; // r2
  int v25; // r0
  int v26; // r1
  __int16 v27; // r3
  int v28; // r3
  int v29; // r3
  int v30; // r5
  unsigned int v31; // r4
  int v32; // r4
  int v33; // r4
  _BYTE *v34; // r3
  int v35; // r5
  unsigned int v36; // r0
  unsigned __int8 v38; // [sp+10h] [bp-A8h]
  _DWORD *v40; // [sp+18h] [bp-A0h] BYREF
  int v41; // [sp+1Ch] [bp-9Ch]
  char v42; // [sp+20h] [bp-98h]
  char v43; // [sp+21h] [bp-97h]
  unsigned int v44; // [sp+24h] [bp-94h]
  int v45; // [sp+28h] [bp-90h]
  int v46; // [sp+2Ch] [bp-8Ch]
  int v47; // [sp+30h] [bp-88h] BYREF
  unsigned int v48; // [sp+34h] [bp-84h] BYREF
  int v49; // [sp+38h] [bp-80h]
  int v50; // [sp+3Ch] [bp-7Ch]
  _DWORD *v51; // [sp+40h] [bp-78h]
  int v52; // [sp+44h] [bp-74h]
  int v53; // [sp+48h] [bp-70h] BYREF
  int v54; // [sp+4Ch] [bp-6Ch]
  int v55; // [sp+50h] [bp-68h]
  int v56; // [sp+54h] [bp-64h]
  _DWORD v57[4]; // [sp+60h] [bp-58h] BYREF
  _DWORD v58[6]; // [sp+70h] [bp-48h] BYREF
  _BYTE _88[52]; // [sp+88h] [bp-30h] BYREF
  int varg_r0; // [sp+C0h] [bp+8h]
  int varg_r1; // [sp+C4h] [bp+Ch]
  int varg_r2; // [sp+C8h] [bp+10h]
  int varg_r3; // [sp+CCh] [bp+14h]

  varg_r2 = a3;
  varg_r3 = a4;
  LOBYTE(varg_r2) = a3;
  v55 = a2;
  varg_r1 = a2;
  varg_r0 = a1;
  v46 = 0;
  v47 = 0;
  v57[0] = 0;
  v57[1] = 0;
  v57[2] = 0;
  v56 = 0;
  v42 = 0;
  v53 = 0;
  v44 = 0;
  v48 = 0;
  v50 = 0;
  v45 = 0;
  v52 = 0;
  v43 = 0;
  v6 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v51 = (_DWORD *)v6;
  v38 = v6;
  if ( v6 )
    v7 = 3570;
  else
    v7 = 69618;
  v40 = (_DWORD *)(a4 & v7);
  v49 = a4 & v7;
  if ( v6 )
  {
    v8 = (_DWORD *)a5;
    v9 = (_DWORD *)a5;
    if ( a5 >= MmUserProbeAddress )
      v9 = (_DWORD *)MmUserProbeAddress;
    *v9 = *v9;
  }
  else
  {
    v8 = (_DWORD *)a5;
  }
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v11 = ObReferenceObjectByHandle(a1, 2048, PsThreadType, v10, &v40, 0);
  if ( v11 < 0 )
    return v11;
  v13 = v40;
  if ( (v40[240] & 8) == 0 )
  {
    v14 = 0;
    v15 = (int)v51;
    v40 = v51;
    v45 = v38;
    v16 = v38;
    v41 = v38;
    goto LABEL_35;
  }
  v54 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v54 + 0x134);
  v17 = v13 + 236;
  v18 = KeAbPreAcquire((unsigned int)(v13 + 236), 0, 0);
  v19 = v18;
  do
    v20 = __ldrex(v17);
  while ( !v20 && __strex(0x11u, v17) );
  __dmb(0xBu);
  if ( v20 )
    ExfAcquirePushLockSharedEx(v13 + 236, v18, (unsigned int)(v13 + 236));
  if ( v19 )
    *(_BYTE *)(v19 + 14) |= 1u;
  if ( (v13[240] & 8) != 0 )
  {
    v14 = v13[226] & 0xFFFFFFF8;
    v16 = (v13[240] & 0x100) != 0;
    v41 = v16;
    ObfReferenceObject(v14);
    v21 = v13[226];
    v15 = v21 & 3;
    v40 = (_DWORD *)v15;
    if ( (v21 & 4) == 0 )
    {
      v45 = 0;
      goto LABEL_26;
    }
    v22 = 1;
  }
  else
  {
    v14 = 0;
    v15 = (int)v51;
    v40 = v51;
    v22 = v38;
    v16 = v38;
    v41 = v38;
  }
  v45 = v22;
LABEL_26:
  __dmb(0xBu);
  v23 = v13 + 236;
  do
    v24 = __ldrex(v23);
  while ( v24 == 17 && __strex(0, v23) );
  if ( v24 != 17 )
  {
    ExfReleasePushLockShared(v13 + 236);
    v23 = v13 + 236;
  }
  v25 = KeAbPostRelease((unsigned int)v23);
  v26 = v54;
  v27 = *(_WORD *)(v54 + 308) + 1;
  *(_WORD *)(v54 + 308) = v27;
  if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
    KiCheckForKernelApcDelivery(v25);
LABEL_35:
  if ( !v14 )
  {
    ObfDereferenceObject((int)v13);
    return -1073741700;
  }
  if ( v15 <= 0 )
  {
    ObfDereferenceObject(v14);
    ObfDereferenceObject((int)v13);
    return -1073741658;
  }
  v28 = a3;
  if ( a3 )
  {
    v56 = PsDisableImpersonation(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v57);
    v28 = a3;
  }
  if ( v16 )
  {
    if ( v28 )
    {
      v29 = v57[0];
      if ( v57[0] )
      {
LABEL_46:
        v50 = *(_DWORD *)(v29 + 640);
        v52 = 1;
        goto LABEL_47;
      }
    }
    else
    {
      v29 = v13[263];
      if ( v29 )
        goto LABEL_46;
    }
LABEL_47:
    v30 = v13[84];
    v31 = PsReferencePrimaryToken(v30);
    v54 = SepCreateImpersonationTokenDacl(v14, v31, &v48);
    ObFastDereferenceObject((_DWORD *)(v30 + 244), v31);
    v32 = v54;
    if ( v54 < 0 )
    {
      v36 = v48;
    }
    else
    {
      v33 = v48;
      v44 = v48;
      if ( v48 )
      {
        RtlCreateSecurityDescriptor(_88, 1);
        RtlSetDaclSecurityDescriptor((int)_88, 1, v33, 0);
      }
      v58[0] = 24;
      v34 = 0;
      v58[1] = 0;
      v58[3] = v49;
      v58[2] = 0;
      if ( v33 )
        v34 = _88;
      v58[4] = v34;
      v58[5] = 0;
      v32 = SepDuplicateToken(v14, v58, v45, 2, v40, 0, 0, &v47);
      if ( v32 < 0 )
      {
        v46 = v47;
      }
      else
      {
        v35 = v47;
        v46 = v47;
        if ( v52 )
          v32 = SepSetTokenTrust(v47, v50);
        if ( v32 >= 0 )
        {
          ObfReferenceObject(v35);
          v32 = ObInsertObjectEx(v35, 0, v55, 0, 0, 0, &v53);
        }
      }
      v36 = v44;
    }
    v16 = v41;
    goto LABEL_62;
  }
  v32 = ObOpenObjectByPointer(v14, v49, 0, v55, SeTokenObjectType, v51, &v53);
  v36 = v44;
LABEL_62:
  if ( v36 )
    ExFreePoolWithTag(v36);
  if ( v56 )
    PsRestoreImpersonation(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0, v57);
  if ( v32 >= 0 && v16 )
    PsSwapImpersonationToken(v13, v14, v46);
  ObfDereferenceObject(v14);
  if ( v46 )
    ObfDereferenceObject(v46);
  ObfDereferenceObject((int)v13);
  if ( v32 >= 0 )
    *v8 = v53;
  return v32;
}
