// KeCapturePersistentThreadState 
 
int __fastcall KeCapturePersistentThreadState(int a1, int a2, unsigned int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r8
  int v11; // r3
  unsigned int v12; // r3
  int v13; // r3
  int v14; // r3
  int v15; // r3
  int v16; // r3
  int v17; // r3
  unsigned int v18; // r7
  unsigned int v19; // r9
  unsigned int v20; // r4
  unsigned int v21; // r9
  unsigned int v22; // r4
  unsigned int v23; // r9
  unsigned int v24; // r0
  unsigned int v25; // r4
  __int64 v26; // r2
  unsigned int v27; // r8
  unsigned int v28; // r1
  unsigned int v29; // r4
  __int64 v30; // r8
  unsigned int v31; // r2
  unsigned int v32; // r4
  unsigned int v33; // r3
  int v34; // r0
  unsigned int v35; // r1
  __int16 v36; // r3
  unsigned int v37; // r7
  int v38; // r2
  int v39; // r8
  unsigned int v40; // r4
  unsigned int v41; // r0
  int v42; // r2
  int v43; // r3
  int v44; // r8
  unsigned int v45; // r0
  unsigned int v46; // r4
  unsigned int v47; // r2
  unsigned int v48; // [sp+0h] [bp-30h] BYREF
  int v49; // [sp+4h] [bp-2Ch]
  int v50; // [sp+8h] [bp-28h] BYREF
  int v51[9]; // [sp+Ch] [bp-24h] BYREF

  v49 = a1;
  v50 = a4;
  v48 = a3;
  v8 = a2;
  if ( !a8 )
    return 0;
  if ( !a2 )
    v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  memset((_BYTE *)a8, 0, 0x20000);
  RtlFillMemoryUlong((_DWORD *)a8, 0x1000u, 1162297680);
  *(_DWORD *)a8 = 1162297680;
  *(_DWORD *)(a8 + 4) = 1347245380;
  *(_DWORD *)(a8 + 12) = 10240;
  *(_DWORD *)(a8 + 8) = 15;
  *(_DWORD *)(a8 + 16) = *(_DWORD *)(*(_DWORD *)(v8 + 116) + 24);
  *(_DWORD *)(a8 + 20) = MmPfnDatabase;
  *(_DWORD *)(a8 + 24) = &PsLoadedModuleList;
  *(_DWORD *)(a8 + 28) = &PsActiveProcessHead;
  *(_DWORD *)(a8 + 32) = 452;
  v11 = KeNumberProcessors_0;
  *(_DWORD *)(a8 + 2008) = 0;
  *(_DWORD *)(a8 + 36) = v11;
  v12 = v48;
  *(_DWORD *)(a8 + 2016) = 0;
  *(_DWORD *)(a8 + 2004) = 1;
  *(_DWORD *)(a8 + 40) = v12;
  *(_DWORD *)(a8 + 44) = v50;
  *(_DWORD *)(a8 + 48) = a5;
  *(_DWORD *)(a8 + 52) = a6;
  *(_DWORD *)(a8 + 56) = a7;
  *(_DWORD *)(a8 + 2000) = -2147483645;
  v13 = *(_DWORD *)(a1 + 64);
  *(_DWORD *)(a8 + 4000) = 0x20000;
  *(_DWORD *)(a8 + 4004) = 0;
  *(_DWORD *)(a8 + 2012) = v13;
  v14 = MEMORY[0xFFFF9014];
  __dmb(0xBu);
  *(_DWORD *)(a8 + 4032) = v14;
  v15 = MEMORY[0xFFFF9018];
  __dmb(0xBu);
  *(_DWORD *)(a8 + 4036) = v15;
  v16 = MEMORY[0xFFFF9008];
  __dmb(0xBu);
  *(_DWORD *)(a8 + 4024) = v16;
  v17 = MEMORY[0xFFFF900C];
  __dmb(0xBu);
  *(_DWORD *)(a8 + 4028) = v17;
  *(_DWORD *)(a8 + 3976) = 4;
  *(_DWORD *)(a8 + 3980) = 130;
  *(_DWORD *)(a8 + 2208) |= 0x10u;
  *(_DWORD *)(a8 + 3988) = MEMORY[0xFFFF9264];
  *(_DWORD *)(a8 + 3992) = MEMORY[0xFFFF92D0];
  v18 = 4200;
  *(_DWORD *)(a8 + 2212) = MEMORY[0xFFFF92C4];
  *(_DWORD *)(a8 + 4164) = 0;
  *(_DWORD *)(a8 + 4096) = CmNtCSDVersion;
  *(_DWORD *)(a8 + 4100) = 0x20000;
  *(_DWORD *)(a8 + 4112) = 2000;
  *(_DWORD *)(a8 + 4160) = 0;
  *(_DWORD *)(a8 + 3980) |= 1u;
  *(_DWORD *)(a8 + 4108) = 800;
  memmove(a8 + 800, a1, 0x1A0u);
  v48 = 864;
  if ( sub_56449C(0x1068u, &v48) )
  {
    *(_DWORD *)(a8 + 3980) |= 0x400u;
    *(_DWORD *)(a8 + 96) = &KdDebuggerDataBlock;
    *(_DWORD *)(a8 + 4184) = 4200;
    *(_DWORD *)(a8 + 4188) = 864;
    KdCopyDataBlock(a8 + 4200);
    v18 = 5064;
  }
  v48 = 18560;
  v19 = (v18 + 7) & 0xFFFFFFF8;
  if ( sub_56449C(v19, &v48) )
  {
    *(_DWORD *)(a8 + 3980) |= 4u;
    *(_DWORD *)(a8 + 4124) = v19;
    v20 = v48;
    memmove(v19 + a8, ((unsigned int)KeGetPcr() & 0xFFFFF000) + 1408, v48);
    v18 = v20 + v19;
  }
  v48 = 888;
  v21 = (v18 + 7) & 0xFFFFFFF8;
  if ( sub_56449C(v21, &v48) )
  {
    v22 = v48;
    *(_DWORD *)(a8 + 3980) |= 8u;
    *(_DWORD *)(a8 + 4128) = v21;
    memmove(v21 + a8, *(_DWORD *)(v8 + 116), v22);
    v18 = v22 + v21;
  }
  v48 = 1104;
  v23 = (v18 + 7) & 0xFFFFFFF8;
  v24 = sub_56449C(v23, &v48);
  if ( v24 )
  {
    v25 = v48;
    *(_DWORD *)(a8 + 3980) |= 0x10u;
    *(_DWORD *)(a8 + 4132) = v23;
    v24 = memmove(v23 + a8, v8, v25);
    v18 = v25 + v23;
  }
  if ( (*(_WORD *)(v8 + 82) & 1) != 0 )
  {
    v26 = *(_QWORD *)(v8 + 36);
    __dmb(0xBu);
    v27 = *(_DWORD *)(v49 + 56);
    if ( ((unsigned int)v26 > v27 || v27 >= HIDWORD(v26)) && (v27 = v26, HIDWORD(v26) <= (unsigned int)v26) )
      v28 = 0;
    else
      v28 = HIDWORD(v26) - v27;
    if ( v28 >= 0x3FFF )
      v28 = 0x3FFF;
    v24 = sub_563FE8(v27, v28, v26, 0x3FFF);
    v48 = v24;
    if ( v24 )
    {
      if ( !sub_56449C(v18, &v48) )
        *(_DWORD *)(a8 + 4164) |= 0x100u;
      v29 = v48;
      *(_DWORD *)(a8 + 3980) |= 0x20u;
      *(_DWORD *)(a8 + 4136) = v18;
      *(_DWORD *)(a8 + 4140) = v29;
      *(_DWORD *)(a8 + 4168) = v27;
      v24 = memmove(v18 + a8, v27, v29);
      v18 += v29;
    }
  }
  if ( (unsigned int)KeGetCurrentIrql(v24) < 2 )
  {
    LODWORD(v30) = (v18 + 7) & 0xFFFFFFF8;
    v31 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    --*(_WORD *)(v31 + 308);
    ExAcquireResourceSharedLite((int)&PsLoadedModuleResource, 1);
    if ( IoGetLoadedDriverInfo(0, &v50, v51) >= 0 )
    {
      HIDWORD(v30) = v50;
      v48 = (76 * v50 + 7) & 0xFFFFFFF8;
      if ( v48
        && sub_56449C((v18 + 7) & 0xFFFFFFF8, &v48)
        && (v32 = v30 + v48, (v48 = (v51[0] + 6 * HIDWORD(v30) + 7) & 0xFFFFFFF8) != 0)
        && sub_56449C(v32, &v48) )
      {
        if ( IopWriteDriverList(a8, 0, (v18 + 7) & 0xFFFFFFF8, v32) >= 0 )
        {
          *(_DWORD *)(a8 + 3980) |= 0x40u;
          v33 = v48;
          *(_QWORD *)(a8 + 4144) = v30;
          *(_DWORD *)(a8 + 4152) = v32;
          *(_DWORD *)(a8 + 4156) = v33;
          v18 = v32 + v33;
        }
      }
      else
      {
        *(_DWORD *)(a8 + 4164) |= 0x100u;
      }
    }
    v34 = ExpReleaseResourceForThreadLite((int)&PsLoadedModuleResource, __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
    v35 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v36 = *(_WORD *)(v35 + 0x134) + 1;
    *(_WORD *)(v35 + 308) = v36;
    if ( !v36 && *(_DWORD *)(v35 + 100) != v35 + 100 && !*(_WORD *)(v35 + 310) )
      KiCheckForKernelApcDelivery(v34);
  }
  v48 = 4112;
  v37 = (v18 + 7) & 0xFFFFFFF8;
  sub_56449C(v37, &v48);
  if ( v48 > 0x10 )
  {
    v39 = v49;
    v40 = v48 - 16;
    v41 = sub_564010(*(_DWORD *)(v49 + 64), (v48 - 16) >> 1, v38, v48);
    if ( v41 )
    {
      v43 = *(_DWORD *)(v39 + 64) - v41;
      v44 = v43 + 1;
      v45 = sub_563FE8(v43 + 1, v40, v42, v43);
      if ( v45 )
      {
        v46 = v37 + a8;
        *(_DWORD *)(a8 + 3980) |= 0x800u;
        v47 = (v37 + 23) & 0xFFFFFFF8;
        *(_DWORD *)(a8 + 4192) = v37;
        *(_DWORD *)(a8 + 4196) = 1;
        *(_DWORD *)(v46 + 8) = v47;
        *(_DWORD *)(v46 + 12) = v45;
        *(_QWORD *)(v37 + a8) = v44;
        memmove(v47 + a8, v44, v45);
      }
    }
  }
  *(_DWORD *)(a8 + 4104) = 131068;
  *(_DWORD *)(a8 + 131068) = 1145524820;
  return 0x20000;
}
