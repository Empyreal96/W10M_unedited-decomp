// FsRtlCopyRead 
 
int __fastcall FsRtlCopyRead(int a1, _DWORD *a2, unsigned int a3, int a4, int a5, int a6, _DWORD *a7, int a8)
{
  int v8; // r8
  int v12; // r4
  unsigned int v13; // r4
  int v14; // r5
  unsigned int v15; // r2
  unsigned int v16; // r3
  unsigned int *v17; // r2
  unsigned int v18; // r1
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r1
  __int16 v22; // r3
  unsigned int *v23; // r2
  unsigned int v24; // r1
  unsigned int v25; // r2
  unsigned int v26; // r0
  int v27; // r0
  unsigned int v28; // r1
  int v29; // r3
  int v30; // r0
  unsigned int v31; // r1
  __int16 v32; // r3
  int v33; // r0
  unsigned int v34; // r1
  __int16 v35; // r3
  __int64 v38; // [sp+18h] [bp-28h]

  v8 = a4;
  if ( IoGetTopLevelIrp() )
    return 0;
  if ( !a3 )
  {
    *a7 = 0;
    a7[1] = 0;
    return 1;
  }
  if ( 0x7FFFFFFF - a2[1] <= 0 && (0x7FFFFFFF - a2[1] < 0 || -1 - *a2 < a3) )
  {
    *a7 = -1073741811;
    a7[1] = 0;
    return 0;
  }
  v38 = *(_QWORD *)a2 + a3;
  v13 = a3 + *a2;
  v14 = *(_DWORD *)(a1 + 12);
  v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v15 + 0x134);
  v16 = ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408;
  if ( v8 )
  {
    v17 = (unsigned int *)(v16 + 1596);
    do
      v18 = __ldrex(v17);
    while ( __strex(v18 + 1, v17) );
    ExAcquireResourceSharedLite(*(_DWORD *)(v14 + 8), 1);
  }
  else
  {
    v19 = (unsigned int *)(v16 + 1592);
    do
      v20 = __ldrex(v19);
    while ( __strex(v20 + 1, v19) );
    if ( !ExAcquireResourceSharedLite(*(_DWORD *)(v14 + 8), 0) )
    {
      v21 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v22 = *(_WORD *)(v21 + 0x134) + 1;
      *(_WORD *)(v21 + 308) = v22;
      if ( !v22 && *(_DWORD *)(v21 + 100) != v21 + 100 && !*(_WORD *)(v21 + 310) )
        KiCheckForKernelApcDelivery(0);
      v23 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4288);
      goto LABEL_20;
    }
  }
  if ( !*(_DWORD *)(a1 + 24) || !*(_BYTE *)(v14 + 5) )
    goto LABEL_40;
  if ( *(_BYTE *)(v14 + 5) != 2 )
    goto LABEL_27;
  if ( !(*(int (__fastcall **)(int, _DWORD *, unsigned int, int, int, int, _DWORD *, int))(*(_DWORD *)(*(_DWORD *)(a8 + 8) + 40)
                                                                                         + 4))(
          a1,
          a2,
          a3,
          a4,
          a5,
          1,
          a7,
          a8) )
  {
LABEL_40:
    v33 = ExReleaseResourceLite(*(_DWORD *)(v14 + 8));
    v34 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v35 = *(_WORD *)(v34 + 0x134) + 1;
    *(_WORD *)(v34 + 308) = v35;
    if ( !v35 && *(_DWORD *)(v34 + 100) != v34 + 100 && !*(_WORD *)(v34 + 310) )
      KiCheckForKernelApcDelivery(v33);
    v23 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 3008);
    do
LABEL_20:
      v24 = __ldrex(v23);
    while ( __strex(v24 + 1, v23) );
    return 0;
  }
  v13 = v38;
LABEL_27:
  v25 = *(_DWORD *)(v14 + 24);
  v26 = *(_DWORD *)(v14 + 28);
  if ( __SPAIR64__(HIDWORD(v38), v13) > __SPAIR64__(v26, v25) )
  {
    if ( *(_QWORD *)a2 >= __SPAIR64__(v26, v25) )
    {
      *a7 = -1073741807;
      a7[1] = 0;
      v27 = ExReleaseResourceLite(*(_DWORD *)(v14 + 8));
      v28 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v29 = (__int16)(*(_WORD *)(v28 + 0x134) + 1);
      *(_WORD *)(v28 + 308) = v29;
      if ( !v29 && *(_DWORD *)(v28 + 100) != v28 + 100 && !*(_WORD *)(v28 + 310) )
        KiCheckForKernelApcDelivery(v27);
      return 1;
    }
    a3 = v25 - *a2;
  }
  IoSetTopLevelIrp(4);
  v12 = CcCopyReadEx(a1, a2, a3, a4, a6, a7, 0);
  *(_DWORD *)(a1 + 44) |= 0x80000u;
  if ( v12 )
    *(_QWORD *)(a1 + 56) = *(_QWORD *)a2 + (unsigned int)a7[1];
  IoSetTopLevelIrp(0);
  v30 = ExReleaseResourceLite(*(_DWORD *)(v14 + 8));
  v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = *(_WORD *)(v31 + 0x134) + 1;
  *(_WORD *)(v31 + 308) = v32;
  if ( !v32 && *(_DWORD *)(v31 + 100) != v31 + 100 && !*(_WORD *)(v31 + 310) )
    KiCheckForKernelApcDelivery(v30);
  return v12;
}
