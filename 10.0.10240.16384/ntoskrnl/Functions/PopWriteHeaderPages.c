// PopWriteHeaderPages 
 
int __fastcall PopWriteHeaderPages(int a1, _DWORD *a2)
{
  uint32x4_t *v3; // r7
  int v5; // r3
  unsigned int v7; // r2
  unsigned int v8; // r3
  int v9; // r4
  int v10; // r3
  __int64 v11; // kr00_8
  int v12; // r2
  int v13; // r0
  int v14; // r1
  int v15; // r4
  int v16; // r0
  int v17; // r1
  int v18; // r4
  int v19; // r0
  int v20; // r1
  int v21; // r4

  v3 = *(uint32x4_t **)(a1 + 96);
  *(_DWORD *)(a1 + 116) = 0;
  memset(v3, 0, *(_DWORD *)(a1 + 100) << 12);
  v5 = *(_DWORD *)(a1 + 76);
  if ( !v5 )
  {
    if ( (PoDebug & 0x10) != 0 )
      DbgPrint("PopWriteHiberImage: No free pages to pass to the loader!\n");
    return -1073741801;
  }
  v7 = PopHiberScratchPages;
  v8 = *(_DWORD *)(v5 + 20) >> 12;
  a2[14] = v8;
  if ( v8 < v7 )
  {
    if ( (PoDebug & 0x10) != 0 )
      DbgPrint(
        "PopWriteHiberImage: Attempting to hibernate more pages (0x%08lx) than we have free (0x%08lx)\n",
        PopHiberScratchPages,
        a2[14]);
    return -1073741801;
  }
  v9 = 4 * v7;
  memmove((int)v3, *(_DWORD *)(a1 + 76) + 28, 4 * v7);
  PopWriteHiberPages(a1, v3, (unsigned int)(v9 + 4095) >> 12, *(_DWORD *)(a1 + 156) + 2);
  v10 = PopHiberScratchPages;
  a2[14] = PopHiberScratchPages;
  a2[15] = tcpxsum(0, v3, (4 * v10 + 4095) & 0xFFFFF000);
  if ( *(_DWORD *)(a1 + 152) )
  {
    *(_DWORD *)(a1 + 116) = 1;
    memset(v3, 0, *(_DWORD *)(a1 + 100) << 12);
    v11 = *(_QWORD *)(a1 + 152);
    memmove((int)v3, v11, HIDWORD(v11) << 12);
    a2[175] = tcpxsum(0, v3, HIDWORD(v11) << 12);
    v12 = *(_DWORD *)(a1 + 156);
    a2[176] = v12;
    PopWriteHiberPages(a1, v3, v12, 2);
    v13 = tcpxsum(0, v3, HIDWORD(v11) << 12);
    v14 = a2[175];
    v15 = v13;
    if ( v14 != v13 )
    {
      DbgPrint("Checksum for resume context page changed from %lx to %lx\n", v14, v13);
      KeBugCheckEx(160, 3, a2[175], v15, 7148);
    }
  }
  *(_DWORD *)(a1 + 116) = 2;
  memset(v3, 0, *(_DWORD *)(a1 + 100) << 12);
  memmove((int)v3, *(_DWORD *)(a1 + 112), 0x3A0u);
  a2[16] = tcpxsum(0, v3, 0x3A0u);
  PopWriteHiberPages(a1, v3, 1, 1);
  v16 = tcpxsum(0, v3, 0x3A0u);
  v17 = a2[16];
  v18 = v16;
  if ( v17 != v16 )
  {
    DbgPrint("Checksum for context page changed from %lx to %lx\n", v17, v16);
    KeBugCheckEx(160, 3, a2[16], v18, 7170);
  }
  v19 = tcpxsum(0, v3, 0x1000u);
  v20 = a2[16];
  v21 = v19;
  if ( v20 != v19 )
  {
    DbgPrint("Checksum for partial context page %lx doesn't match full %lx\n", v20, v19);
    KeBugCheckEx(160, 4, a2[16], v21, 7177);
  }
  return 0;
}
