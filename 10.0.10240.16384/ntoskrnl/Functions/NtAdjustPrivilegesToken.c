// NtAdjustPrivilegesToken 
 
int __fastcall NtAdjustPrivilegesToken(int a1, int a2, unsigned int a3, int a4, _DWORD *a5, unsigned int a6)
{
  int v8; // r2
  unsigned int v9; // r5
  int v10; // r4
  int v11; // r9
  int v12; // r3
  _DWORD *v13; // r8
  _DWORD *v14; // r10
  _DWORD *v15; // r2
  int v16; // r0
  int v17; // r1
  int v18; // r6
  int v19; // r2
  int v20; // r3
  int v21; // r6
  unsigned int v22; // r3
  int v23; // r0
  unsigned int v24; // r1
  __int16 v25; // r3
  int v26; // r10
  int v27; // r3
  int v28; // r0
  unsigned int v29; // r1
  __int16 v30; // r3
  _BYTE v32[3]; // [sp+19h] [bp-4Fh] BYREF
  int v33; // [sp+1Ch] [bp-4Ch]
  int v34; // [sp+20h] [bp-48h]
  int v35; // [sp+28h] [bp-40h]
  unsigned int v36; // [sp+2Ch] [bp-3Ch] BYREF
  unsigned int v37; // [sp+30h] [bp-38h]
  unsigned int v38; // [sp+34h] [bp-34h]
  int v39; // [sp+38h] [bp-30h]
  int v40; // [sp+3Ch] [bp-2Ch]
  int v41; // [sp+40h] [bp-28h] BYREF
  _DWORD _44[12]; // [sp+44h] [bp-24h] BYREF
  int varg_r1; // [sp+74h] [bp+Ch]
  unsigned int varg_r2; // [sp+78h] [bp+10h]
  int varg_r3; // [sp+7Ch] [bp+14h]

  varg_r1 = a2;
  v38 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  v8 = a2;
  v34 = a2;
  LOBYTE(varg_r1) = a2;
  v40 = a1;
  _44[11] = a1;
  v33 = 0;
  v35 = 0;
  v9 = 0;
  v37 = 0;
  v36 = 0;
  v41 = 0;
  v32[0] = 0;
  if ( !a2 && !a3 )
    return -1073741811;
  v11 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v11 )
  {
    if ( !a2 )
    {
      if ( (a3 & 3) != 0 )
        ExRaiseDatatypeMisalignment(0);
      v33 = *(_DWORD *)a3;
      v35 = v33;
      v12 = 12 * (v33 - 1) + 16;
      if ( 12 * (v33 - 1) != -16 && (v12 + a3 > MmUserProbeAddress || v12 + a3 < a3) )
        *(_BYTE *)MmUserProbeAddress = 0;
    }
    v13 = a5;
    if ( a5 )
    {
      ProbeForWrite(a5, a4, 4);
      v14 = (_DWORD *)a6;
      v15 = (_DWORD *)a6;
      if ( a6 >= MmUserProbeAddress )
        v15 = (_DWORD *)MmUserProbeAddress;
      *v15 = *v15;
    }
    else
    {
      v14 = (_DWORD *)a6;
    }
    v8 = v34;
LABEL_20:
    if ( !v8 )
    {
      v16 = SeCaptureLuidAndAttributesArray(a3 + 4);
      v39 = v16;
      if ( v16 < 0 )
        return v16;
      v9 = v37;
    }
    goto LABEL_24;
  }
  v14 = (_DWORD *)a6;
  v13 = a5;
  if ( !a2 )
  {
    v33 = *(_DWORD *)a3;
    v35 = v33;
    goto LABEL_20;
  }
LABEL_24:
  if ( v13 )
    v17 = 40;
  else
    v17 = 32;
  v18 = ObReferenceObjectByHandle(v40, v17, SeTokenObjectType, v11, _44);
  if ( v18 >= 0 )
  {
    v19 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v20 = *(__int16 *)(v19 + 0x134) - 1;
    *(_WORD *)(v19 + 308) = v20;
    v21 = _44[0];
    ExAcquireResourceExclusiveLite(*(_DWORD *)(_44[0] + 48), 1, v19, v20);
    __dmb(0xFu);
    v39 = SepAdjustPrivileges(v21, 0, v34, v33, v9, v13, &v36, &v41, v32);
    v22 = v36;
    if ( v13 )
      *v14 = v36;
    if ( v13 && v22 > v38 )
    {
      __dmb(0xFu);
      v23 = ExReleaseResourceLite(*(_DWORD *)(v21 + 48));
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = *(_WORD *)(v24 + 0x134) + 1;
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(v23);
      ObfDereferenceObject(v21);
      if ( v9 )
        SeReleaseLuidAndAttributesArray(v9, v11);
      v10 = -1073741789;
    }
    else
    {
      v26 = SepAdjustPrivileges(v21, 1, v34, v33, v9, v13, &v36, &v41, v32);
      v39 = v26;
      if ( v13 )
      {
        v27 = v41;
        *v13 = v41;
        if ( !v27 )
        {
          v13[1] = 0;
          v13[2] = 0;
          v13[3] = 0;
        }
      }
      if ( v32[0] )
        ExAllocateLocallyUniqueId((int *)(v21 + 52));
      __dmb(0xFu);
      v28 = ExReleaseResourceLite(*(_DWORD *)(v21 + 48));
      v29 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v30 = *(_WORD *)(v29 + 0x134) + 1;
      *(_WORD *)(v29 + 308) = v30;
      if ( !v30 && *(_DWORD *)(v29 + 100) != v29 + 100 && !*(_WORD *)(v29 + 310) )
        KiCheckForKernelApcDelivery(v28);
      ObfDereferenceObject(v21);
      if ( v9 )
        SeReleaseLuidAndAttributesArray(v9, v11);
      v10 = v26;
    }
  }
  else
  {
    if ( v9 )
      SeReleaseLuidAndAttributesArray(v9, v11);
    v10 = v18;
  }
  return v10;
}
