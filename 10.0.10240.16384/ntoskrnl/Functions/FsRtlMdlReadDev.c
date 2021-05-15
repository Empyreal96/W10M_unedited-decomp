// FsRtlMdlReadDev 
 
int __fastcall FsRtlMdlReadDev(_DWORD *a1, unsigned int *a2, unsigned int a3, int a4, int *a5, _DWORD *a6, int a7)
{
  _DWORD *v9; // r4
  int v10; // r5
  __int64 v11; // kr00_8
  int v12; // r6
  unsigned int v13; // r2
  unsigned int *v14; // r2
  unsigned int v15; // r1
  int v16; // r0
  unsigned int v17; // r1
  __int16 v18; // r3
  unsigned int *v19; // r2
  unsigned int v20; // r1
  unsigned int v21; // r2
  unsigned int v22; // r0
  int v23; // r0
  unsigned int v24; // r1
  int v25; // r3
  int v26; // r0
  unsigned int v27; // r1
  __int16 v28; // r3
  int v29; // r0
  unsigned int v30; // r1
  __int16 v31; // r3
  unsigned int *v32; // r2
  unsigned int v33; // r1

  v9 = a1;
  v10 = 1;
  if ( IoGetTopLevelIrp() )
    return 0;
  if ( !a3 )
  {
    *a6 = 0;
    a6[1] = 0;
    return 1;
  }
  v11 = *(_QWORD *)a2 + a3;
  v12 = v9[3];
  v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v13 + 308);
  v14 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4228);
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 + 1, v14) );
  ExAcquireResourceSharedLite(*(_DWORD *)(v12 + 8), 1);
  if ( !v9[6] || !*(_BYTE *)(v12 + 5) )
  {
    v29 = ExReleaseResourceLite(*(_DWORD *)(v12 + 8));
    v30 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v31 = *(_WORD *)(v30 + 0x134) + 1;
    *(_WORD *)(v30 + 308) = v31;
    if ( !v31 && *(_DWORD *)(v30 + 100) != v30 + 100 && !*(_WORD *)(v30 + 310) )
      KiCheckForKernelApcDelivery(v29);
    v32 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4232);
    do
      v33 = __ldrex(v32);
    while ( __strex(v33 + 1, v32) );
    return 0;
  }
  if ( *(_BYTE *)(v12 + 5) == 2 )
  {
    if ( !(*(int (__fastcall **)(_DWORD *, unsigned int *, unsigned int, int, int, int, _DWORD *, int))(*(_DWORD *)(*(_DWORD *)(a7 + 8) + 40) + 4))(
            a1,
            a2,
            a3,
            1,
            a4,
            1,
            a6,
            a7) )
    {
      v16 = ExReleaseResourceLite(*(_DWORD *)(v12 + 8));
      v17 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v18 = *(_WORD *)(v17 + 0x134) + 1;
      *(_WORD *)(v17 + 308) = v18;
      if ( !v18 && *(_DWORD *)(v17 + 100) != v17 + 100 && !*(_WORD *)(v17 + 310) )
        KiCheckForKernelApcDelivery(v16);
      v19 = (unsigned int *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 4232);
      do
        v20 = __ldrex(v19);
      while ( __strex(v20 + 1, v19) );
      return 0;
    }
    v9 = a1;
  }
  v21 = *(_DWORD *)(v12 + 24);
  v22 = *(_DWORD *)(v12 + 28);
  if ( v11 > __SPAIR64__(v22, v21) )
  {
    if ( *(_QWORD *)a2 >= __SPAIR64__(v22, v21) )
    {
      *a6 = -1073741807;
      a6[1] = 0;
      v23 = ExReleaseResourceLite(*(_DWORD *)(v12 + 8));
      v24 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
      v25 = (__int16)(*(_WORD *)(v24 + 0x134) + 1);
      *(_WORD *)(v24 + 308) = v25;
      if ( !v25 && *(_DWORD *)(v24 + 100) != v24 + 100 && !*(_WORD *)(v24 + 310) )
        KiCheckForKernelApcDelivery(v23);
      return 1;
    }
    a3 = v21 - *a2;
  }
  IoSetTopLevelIrp(4);
  CcMdlRead((int)v9, a2, a3, a5, a6);
  v9[11] |= 0x80000u;
  IoSetTopLevelIrp(0);
  v26 = ExReleaseResourceLite(*(_DWORD *)(v12 + 8));
  v27 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v28 = *(_WORD *)(v27 + 0x134) + 1;
  *(_WORD *)(v27 + 308) = v28;
  if ( !v28 && *(_DWORD *)(v27 + 100) != v27 + 100 && !*(_WORD *)(v27 + 310) )
    KiCheckForKernelApcDelivery(v26);
  return v10;
}
