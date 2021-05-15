// PspQueryJobHierarchyAccountingInformation 
 
int __fastcall PspQueryJobHierarchyAccountingInformation(int a1, int a2)
{
  unsigned int v4; // r7
  _BYTE *v5; // r0
  int v6; // r3
  int v7; // r2
  int v8; // r3
  int v9; // r10
  int v10; // r2
  int *v11; // r1
  int v12; // t1
  __int64 v13; // kr00_8
  __int64 v14; // kr10_8
  unsigned int v15; // r2
  int v16; // r3
  int v17; // r3
  unsigned int v18; // lr
  int v19; // r7
  unsigned int v20; // r5
  _QWORD *v21; // r8
  int v22; // r9
  int v23; // r2
  int *v24; // r1
  int v25; // t1
  int result; // r0
  __int16 v27; // r3
  int v28; // r3
  int v29; // [sp+8h] [bp-190h]
  int v30; // [sp+8h] [bp-190h]
  int v31; // [sp+Ch] [bp-18Ch] BYREF
  unsigned int v32; // [sp+10h] [bp-188h]
  __int64 v33[48]; // [sp+18h] [bp-180h] BYREF

  v4 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v32 = v4;
  v5 = memset(v33, 0, 352);
  if ( v4 )
    return sub_7C2328(v5);
  while ( 1 )
  {
    v6 = *(_DWORD *)(a1 + 576);
    __dmb(0xBu);
    v29 = v6;
    __dmb(0xBu);
    ExAcquireResourceSharedLite(v6 + 32, 1);
    v7 = v29;
    __dmb(0xBu);
    v8 = *(_DWORD *)(a1 + 576);
    __dmb(0xBu);
    if ( v7 == v8 )
      break;
    v28 = v29;
    __dmb(0xBu);
    ExReleaseResourceLite(v28 + 32);
  }
  v9 = v29;
  v31 = v29;
  __dmb(0xBu);
  v10 = 0;
  v11 = &v31;
  while ( 1 )
  {
    v12 = *v11++;
    if ( a1 == v12 )
      break;
    if ( ++v10 )
    {
      ExAcquireResourceSharedLite(a1 + 32, 1);
      break;
    }
  }
  PspEnumJobsAndProcessesInJobHierarchy(a1, 0, 0, PspQueryProcessAccountingInformationCallback, v33, 1, v29);
  v13 = v33[11];
  *(_QWORD *)a2 = *(_QWORD *)(a1 + 88) + v33[11];
  v14 = v33[10];
  *(_QWORD *)(a2 + 16) = *(_QWORD *)(a1 + 112) + v13;
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(a1 + 96) + v14;
  *(_QWORD *)(a2 + 24) = *(_QWORD *)(a1 + 120) + v14;
  *(_DWORD *)(a2 + 32) = LODWORD(v33[25]) + *(_DWORD *)(a1 + 136);
  v15 = HIDWORD(v33[14]);
  *(_DWORD *)(a2 + 36) = *(_DWORD *)(a1 + 140);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(a1 + 144);
  *(_DWORD *)(a2 + 44) = *(_DWORD *)(a1 + 148);
  *(_QWORD *)(a2 + 48) = __PAIR64__(v15, v33[14]) + *(_QWORD *)(a1 + 240);
  *(_QWORD *)(a2 + 56) = v33[15] + *(_QWORD *)(a1 + 248);
  *(_QWORD *)(a2 + 64) = v33[16] + *(_QWORD *)(a1 + 256);
  *(_QWORD *)(a2 + 72) = v33[17] + *(_QWORD *)(a1 + 264);
  *(_QWORD *)(a2 + 80) = v33[18] + *(_QWORD *)(a1 + 272);
  *(_QWORD *)(a2 + 88) = v33[19] + *(_QWORD *)(a1 + 280);
  *(_QWORD *)(a2 + 96) = v33[20] + *(_QWORD *)(a1 + 288);
  *(_QWORD *)(a2 + 104) = v33[21] + *(_QWORD *)(a1 + 296);
  *(_QWORD *)(a2 + 112) = v33[22] + *(_QWORD *)(a1 + 304);
  *(_QWORD *)(a2 + 120) = v33[23] + *(_QWORD *)(a1 + 312);
  *(_QWORD *)(a2 + 128) = v33[24] + *(_QWORD *)(a1 + 320);
  *(_QWORD *)(a2 + 136) = v33[13] + *(_QWORD *)(a1 + 128);
  *(_QWORD *)(a2 + 144) = v33[12] + *(_QWORD *)(a1 + 104);
  *(_DWORD *)(a2 + 152) = *(_DWORD *)(a1 + 544);
  *(_DWORD *)(a2 + 156) = *(_DWORD *)(a1 + 548);
  v16 = *(_DWORD *)(a1 + 532);
  if ( v16 )
    *(_QWORD *)(a2 + 152) += KeQuerySchedulingGroupReadyTime(v16 + 128);
  v17 = *(_DWORD *)(a1 + 752);
  if ( v17 )
  {
    v18 = 0;
    v19 = a2 + 160;
    *(_QWORD *)(a2 + 224) = v33[34] + *(_QWORD *)(v17 + 64);
    *(_QWORD *)(a2 + 232) = v33[35] + *(_QWORD *)(*(_DWORD *)(a1 + 752) + 72);
    *(_QWORD *)(a2 + 240) = v33[36] + *(_QWORD *)(*(_DWORD *)(a1 + 752) + 80);
    *(_QWORD *)(a2 + 248) = v33[37] + *(_QWORD *)(*(_DWORD *)(a1 + 752) + 88);
    *(_QWORD *)(a2 + 256) = v33[38] + *(_QWORD *)(*(_DWORD *)(a1 + 752) + 96);
    *(_QWORD *)(a2 + 296) = v33[43] + *(_QWORD *)(*(_DWORD *)(a1 + 752) + 136);
    *(_QWORD *)(a2 + 280) = v33[41] + *(_QWORD *)(*(_DWORD *)(a1 + 752) + 120);
    do
    {
      v20 = v18;
      v21 = (_QWORD *)(v18 + v19);
      v22 = 2;
      do
      {
        *v21 = *(_QWORD *)(*(_DWORD *)(a1 + 752) + v20) + *(__int64 *)((char *)&v33[26] + v20);
        v20 += 8;
        ++v21;
        --v22;
      }
      while ( v22 );
      v18 += 16;
    }
    while ( v18 < 0x40 );
    v4 = v32;
    v9 = v30;
  }
  else
  {
    memset((_BYTE *)(a2 + 160), 0, 144);
  }
  v23 = 0;
  v24 = &v31;
  while ( 1 )
  {
    v25 = *v24++;
    if ( a1 == v25 )
      break;
    if ( ++v23 )
    {
      ExReleaseResourceLite(a1 + 32);
      break;
    }
  }
  result = ExReleaseResourceLite(v9 + 32);
  if ( v4 )
  {
    v27 = *(_WORD *)(v4 + 310) + 1;
    *(_WORD *)(v4 + 310) = v27;
    if ( !v27 && *(_DWORD *)(v4 + 100) != v4 + 100 )
      result = KiCheckForKernelApcDelivery(result);
  }
  return result;
}
