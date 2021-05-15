// AlpcpConnectPort 
 
int __fastcall AlpcpConnectPort(unsigned int a1, int a2, int a3, int a4, unsigned int a5, int a6, int a7, int a8, int a9, int *a10, int a11, int a12, int a13)
{
  int v13; // lr
  _DWORD *v14; // r8
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r9
  int v20; // r6
  _DWORD *v21; // r2
  int v22; // r1
  int v23; // r0
  int v24; // r4
  int v25; // r1
  _BYTE *v26; // r3
  char v27; // r3
  int v28; // r5
  int v29; // r0
  _DWORD *v30; // r3
  unsigned int v31; // r1
  __int16 v32; // r3
  char v34; // [sp+20h] [bp-C0h]
  int v35; // [sp+24h] [bp-BCh] BYREF
  int v36; // [sp+28h] [bp-B8h] BYREF
  int v37; // [sp+2Ch] [bp-B4h]
  unsigned int v38; // [sp+30h] [bp-B0h]
  int v39; // [sp+34h] [bp-ACh] BYREF
  int v40; // [sp+38h] [bp-A8h]
  int v41; // [sp+3Ch] [bp-A4h]
  int v42; // [sp+40h] [bp-A0h]
  _DWORD *v43; // [sp+44h] [bp-9Ch]
  int v44; // [sp+48h] [bp-98h]
  int v45; // [sp+4Ch] [bp-94h]
  int v46; // [sp+50h] [bp-90h]
  int *v47; // [sp+54h] [bp-8Ch]
  int v48; // [sp+58h] [bp-88h]
  int v49; // [sp+5Ch] [bp-84h]
  int v50; // [sp+60h] [bp-80h]
  unsigned int v51; // [sp+64h] [bp-7Ch]
  int v52; // [sp+68h] [bp-78h]
  int v53; // [sp+6Ch] [bp-74h]
  int v54; // [sp+70h] [bp-70h]
  int *v55; // [sp+74h] [bp-6Ch]
  int v56; // [sp+78h] [bp-68h]
  unsigned int v57; // [sp+7Ch] [bp-64h]
  int v58; // [sp+80h] [bp-60h]
  int v59; // [sp+84h] [bp-5Ch]
  int v60; // [sp+88h] [bp-58h]
  int v61; // [sp+8Ch] [bp-54h]
  _BYTE v62[80]; // [sp+90h] [bp-50h] BYREF

  v13 = a4;
  v36 = a4;
  v35 = a3;
  v52 = a2;
  v14 = (_DWORD *)a1;
  v43 = (_DWORD *)a1;
  v51 = a1;
  v60 = a2;
  v54 = a3;
  v59 = a4;
  v57 = a5;
  v41 = a7;
  v44 = a7;
  v42 = a8;
  v45 = a8;
  v49 = a9;
  v61 = a9;
  v47 = a10;
  v55 = a10;
  v50 = a11;
  v56 = a11;
  v46 = a12;
  v58 = a12;
  v53 = a13;
  v48 = a13;
  v17 = __mrc(15, 0, 13, 0, 3);
  --*(_WORD *)((v17 & 0xFFFFFFC0) + 0x134);
  v34 = *(_BYTE *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  v18 = a6 & 0xFFFF0000;
  v38 = a6 & 0xFFFF0000;
  v19 = a8;
  v37 = a8;
  v20 = a7;
  v39 = a7;
  if ( v34 )
  {
    v21 = (_DWORD *)a1;
    if ( a1 >= MmUserProbeAddress )
      v21 = (_DWORD *)MmUserProbeAddress;
    *v21 = *v21;
    if ( a5 )
    {
      v22 = a5;
      if ( a5 >= MmUserProbeAddress )
        v22 = MmUserProbeAddress;
      memmove((int)v62, v22, 0x2Cu);
    }
    if ( a8 )
    {
      v23 = SeCaptureSid(a8, v34);
      v24 = v23;
      v40 = v23;
      if ( v23 < 0 )
      {
        v19 = v37;
        goto LABEL_35;
      }
      v19 = v37;
    }
    if ( v41 )
    {
      v23 = SeCaptureSecurityDescriptor(v41, v34, 1, 0, &v39);
      v24 = v23;
      v40 = v23;
      if ( v23 < 0 )
      {
        v20 = v39;
        goto LABEL_35;
      }
      v20 = v39;
    }
    v18 = v38;
    v13 = v36;
    v25 = v35;
  }
  else
  {
    if ( a5 )
    {
      memmove((int)v62, a5, 0x2Cu);
      v18 = v38;
      v13 = v36;
    }
    v25 = v35;
  }
  if ( a5 )
    v26 = v62;
  else
    v26 = 0;
  v23 = AlpcpCreateClientPort(&v35, &v36, v18, v52, v25, v13, v26, v20, v19, 0, 0);
  v24 = v23;
  if ( v23 >= 0 )
  {
    if ( (v38 & 0x100000) != 0 )
      v27 = 1;
    else
      v27 = v34;
    v28 = v36;
    v29 = AlpcpProcessConnectionRequest(v36, v38, v49, v47, v50, v46, v53, v34, v27);
    v24 = v29;
    v40 = v29;
    if ( v29 == -1073741759 && (*(_DWORD *)(v28 + 244) & 0x100) != 0 )
    {
      *v14 = *(_DWORD *)(v28 + 28);
      v30 = v43;
    }
    else
    {
      v30 = v43;
    }
    if ( !v29 )
      *v30 = v35;
    v23 = ObfDereferenceObject(v28);
    if ( v24 )
      v23 = NtClose();
  }
LABEL_35:
  if ( v19 && v19 != v42 )
    v23 = SeReleaseSid(v19, v34, 1);
  if ( v20 && v20 != v41 )
    v23 = SeReleaseSecurityDescriptor(v20, v34, 0);
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x134) + 1;
  *(_WORD *)(v31 + 308) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
    KiCheckForKernelApcDelivery(v23);
  return v24;
}
