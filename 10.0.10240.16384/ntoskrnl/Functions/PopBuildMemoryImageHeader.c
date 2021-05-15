// PopBuildMemoryImageHeader 
 
int __fastcall PopBuildMemoryImageHeader(int a1, int a2)
{
  int v3; // r6
  int v4; // r2
  int v5; // r3
  __int64 v6; // r0
  int v7; // r3
  int v8; // r3
  int v9; // r2
  int v10; // r1
  int v11; // r1
  int v12; // r4
  int *v13; // r4
  int *v14; // r5
  __int64 v15; // kr00_8
  const void *v16; // r0
  int v18; // [sp+8h] [bp-28h] BYREF
  int v19; // [sp+Ch] [bp-24h]
  __int64 v20[4]; // [sp+10h] [bp-20h] BYREF

  v18 = 0;
  v19 = 0;
  if ( a2 )
    return *(_DWORD *)(a1 + 120);
  v3 = *(_DWORD *)(a1 + 128);
  PoSetHiberRange(a1, 2, (const void *)v3, (const void *)0x310, 1735223629);
  memset((_BYTE *)v3, 0, 4096);
  *(_DWORD *)(v3 + 20) = 4096;
  *(_DWORD *)(v3 + 12) = 784;
  MmGetPhysicalAddress((int)v20, v3, v4, v5);
  *(_DWORD *)(v3 + 16) = v20[0] >> 12;
  KeQuerySystemTime((_DWORD *)(v3 + 24));
  LODWORD(v6) = KeQueryInterruptTime();
  *(_QWORD *)(v3 + 32) = v6;
  *(_DWORD *)(v3 + 52) = dword_61EEC0;
  *(_DWORD *)(v3 + 48) = 7;
  *(_DWORD *)(v3 + 40) = KeFeatureBits;
  *(_DWORD *)(v3 + 4) = (unsigned __int16)KeProcessorArchitecture;
  *(_BYTE *)(v3 + 44) = *(_BYTE *)(a1 + 1);
  *(_BYTE *)(v3 + 708) = byte_61EED0;
  *(_DWORD *)(v3 + 760) = MmGetHighestPhysicalPage(0);
  v7 = *(_DWORD *)(a1 + 76);
  if ( v7 )
    *(_DWORD *)(v3 + 56) = *(_DWORD *)(v7 + 20) >> 12;
  v8 = *(_DWORD *)(a1 + 192);
  if ( v8 )
  {
    v9 = v3 + 4;
    v10 = 3;
    *(_DWORD *)(v3 + 764) = v8;
    do
    {
      *(_DWORD *)(v9 + 764) = *(_DWORD *)(v9 + 760) + 1;
      v9 += 4;
      --v10;
    }
    while ( v10 );
  }
  off_617AAC(&v18);
  *(_DWORD *)(v3 + 752) = v18;
  *(_DWORD *)(v3 + 756) = v19;
  v11 = *(_DWORD *)(a1 + 136);
  if ( v11 )
  {
    v12 = *(_DWORD *)(v11 + 20) >> 12;
    memmove(v3 + 600, v11 + 28, 4 * v12);
    *(_DWORD *)(v3 + 596) = v12;
  }
  else
  {
    *(_DWORD *)(v3 + 596) = 0;
  }
  PopCopyFirmwareRuntimeInformationPfnList(a1, v3);
  v13 = *(int **)(a1 + 40);
  do
  {
    if ( v13 == (int *)(a1 + 40) )
    {
      *(_DWORD *)(v3 + 780) = *(_DWORD *)(a1 + 304);
      return *(_DWORD *)(a1 + 120);
    }
    v14 = v13;
    v15 = *(_QWORD *)(v13 + 3);
    v13 = (int *)*v13;
    v16 = PopAllocateOwnMemory(a1, (HIDWORD(v15) - (_DWORD)v15) << 12);
    v14[5] = (int)v16;
  }
  while ( v16 );
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopBuildImage: Could not allocate clone for %p - %p\n", v14[3], v14[4]);
  return -1073741670;
}
