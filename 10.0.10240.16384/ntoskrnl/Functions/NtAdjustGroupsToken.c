// NtAdjustGroupsToken 
 
int __fastcall NtAdjustGroupsToken(int a1, int a2, unsigned int *a3, int a4, _DWORD *a5, unsigned int a6)
{
  int v7; // r2
  int v8; // r4
  int v9; // r5
  int v10; // r8
  _DWORD *v11; // r9
  _DWORD *v12; // r10
  _DWORD *v13; // r2
  int v14; // r0
  int v15; // r1
  int v16; // r6
  int v17; // r2
  int v18; // r3
  int v19; // r6
  int v20; // r0
  unsigned int v21; // r3
  int v22; // r0
  unsigned int v23; // r1
  __int16 v24; // r3
  int v25; // r0
  unsigned int v26; // r1
  __int16 v27; // r3
  int v28; // r3
  int v29; // r10
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  bool v34[3]; // [sp+19h] [bp-57h] BYREF
  int v35; // [sp+1Ch] [bp-54h]
  int v36; // [sp+20h] [bp-50h]
  unsigned int v37; // [sp+24h] [bp-4Ch]
  int v38; // [sp+28h] [bp-48h]
  unsigned int v39; // [sp+2Ch] [bp-44h]
  unsigned int v40; // [sp+30h] [bp-40h]
  int v41; // [sp+34h] [bp-3Ch]
  _DWORD v42[2]; // [sp+38h] [bp-38h] BYREF
  int v43; // [sp+40h] [bp-30h] BYREF
  int v44; // [sp+44h] [bp-2Ch] BYREF
  int v45; // [sp+48h] [bp-28h]
  int v46; // [sp+4Ch] [bp-24h]
  int varg_r0; // [sp+78h] [bp+8h]
  int varg_r1; // [sp+7Ch] [bp+Ch]
  unsigned int *varg_r2; // [sp+80h] [bp+10h]
  int varg_r3; // [sp+84h] [bp+14h]

  varg_r1 = a2;
  v40 = a4;
  varg_r3 = a4;
  varg_r2 = a3;
  v7 = a2;
  v35 = a2;
  LOBYTE(varg_r1) = a2;
  v42[0] = a1;
  varg_r0 = a1;
  v37 = 0;
  v39 = 0;
  v8 = 0;
  v38 = 0;
  v41 = 0;
  v42[1] = 0;
  if ( !a2 && !a3 )
    return -1073741811;
  v10 = *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A);
  if ( v10 )
  {
    if ( !a2 && ((unsigned __int8)a3 & 3) != 0 )
      ExRaiseDatatypeMisalignment(0);
    v11 = a5;
    if ( a5 )
    {
      ProbeForWrite(a5, a4, 4);
      v12 = (_DWORD *)a6;
      v13 = (_DWORD *)a6;
      if ( a6 >= MmUserProbeAddress )
        v13 = (_DWORD *)MmUserProbeAddress;
      *v13 = *v13;
    }
    else
    {
      v12 = (_DWORD *)a6;
    }
    v7 = v35;
  }
  else
  {
    v12 = (_DWORD *)a6;
    v11 = a5;
  }
  if ( !v7 )
  {
    v37 = *a3;
    v39 = v37;
    v14 = SeCaptureSidAndAttributesArray(a3 + 1, v37, v10, 0, 0);
    if ( v14 < 0 )
    {
      v9 = v14;
      v36 = v14;
      return v9;
    }
    v8 = v38;
  }
  if ( v11 )
    v15 = 72;
  else
    v15 = 64;
  v16 = ObReferenceObjectByHandle(v42[0], v15, SeTokenObjectType, v10, &v44);
  if ( v16 < 0 )
  {
    if ( v8 )
      SeReleaseLuidAndAttributesArray(v8, v10);
    return v16;
  }
  v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v18 = *(__int16 *)(v17 + 0x134) - 1;
  *(_WORD *)(v17 + 308) = v18;
  v19 = v44;
  ExAcquireResourceExclusiveLite(*(_DWORD *)(v44 + 48), 1, v17, v18);
  __dmb(0xFu);
  v20 = SepAdjustGroups(v19, 0, v35, v37, v8, (int)v11, 0, v42, &v43, v34);
  v46 = v20;
  v45 = v20;
  v21 = v42[0];
  if ( v11 )
    *v12 = v42[0];
  if ( v20 < 0 )
  {
    __dmb(0xFu);
    v22 = ExReleaseResourceLite(*(_DWORD *)(v19 + 48));
    v23 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v24 = *(_WORD *)(v23 + 0x134) + 1;
    *(_WORD *)(v23 + 308) = v24;
    if ( !v24 && *(_DWORD *)(v23 + 100) != v23 + 100 && !*(_WORD *)(v23 + 310) )
      KiCheckForKernelApcDelivery(v22);
    ObfDereferenceObject(v19);
    if ( v8 )
      SeReleaseLuidAndAttributesArray(v8, v10);
    return v46;
  }
  if ( v11 )
  {
    if ( v21 > v40 )
    {
      __dmb(0xFu);
      v25 = ExReleaseResourceLite(*(_DWORD *)(v19 + 48));
      v26 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v27 = *(_WORD *)(v26 + 0x134) + 1;
      *(_WORD *)(v26 + 308) = v27;
      if ( !v27 && *(_DWORD *)(v26 + 100) != v26 + 100 && !*(_WORD *)(v26 + 310) )
        KiCheckForKernelApcDelivery(v25);
      ObfDereferenceObject(v19);
      if ( v8 )
        SeReleaseLuidAndAttributesArray(v8, v10);
      return -1073741789;
    }
    v28 = ((unsigned int)&v11[2 * v43 + 1] + 3) & 0xFFFFFFFC;
  }
  else
  {
    v28 = v41;
  }
  v29 = SepAdjustGroups(v19, 1, v35, v37, v8, (int)v11, v28, v42, &v43, v34);
  v45 = v29;
  if ( v11 )
    *v11 = v43;
  if ( v34[0] )
    ExAllocateLocallyUniqueId((int *)(v19 + 52));
  __dmb(0xFu);
  v30 = ExReleaseResourceLite(*(_DWORD *)(v19 + 48));
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x134) + 1;
  *(_WORD *)(v31 + 308) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
    KiCheckForKernelApcDelivery(v30);
  ObfDereferenceObject(v19);
  if ( v8 )
    SeReleaseLuidAndAttributesArray(v8, v10);
  return v29;
}
