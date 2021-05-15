// SmKmIssueVolumeIo 
 
int __fastcall SmKmIssueVolumeIo(int a1, _DWORD *a2, _DWORD *a3, int a4, int a5)
{
  int v8; // r8
  int v10; // r4
  __int64 v12; // kr00_8
  int v13; // r7
  int v14; // r2
  int v15; // r2
  char v16; // r3
  int v17; // r2

  v8 = *(_DWORD *)(a1 + 12);
  if ( (*a2 & 1) != 0 )
  {
    v13 = a2[1];
    v10 = *a2 & 0xFFFFFFFE;
  }
  else
  {
    v10 = IoAllocateIrp(*(_BYTE *)(v8 + 48), 0);
    if ( !v10 )
      return -1073741670;
    v12 = *(_QWORD *)(a2 + 1);
    v13 = *a2;
    v14 = v12 & 0xFFF;
    *(_DWORD *)(v13 + 16) = v12 & 0xFFFFF000;
    *(_DWORD *)(v13 + 20) = HIDWORD(v12);
    *(_WORD *)(v13 + 4) = 4 * (((unsigned int)(v14 + HIDWORD(v12) + 4095) >> 12) + 7);
    *(_DWORD *)v13 = 0;
    *(_WORD *)(v13 + 6) = 0;
    *(_DWORD *)(v13 + 24) = v14;
    MmBuildMdlForNonPagedPool(v13);
    MmMdlPageContentsState(v13, 1);
  }
  *(_DWORD *)(v10 + 4) = v13;
  *(_DWORD *)(v10 + 80) = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  *(_BYTE *)(v10 + 32) = 0;
  *(_DWORD *)(v10 + 40) = v10 + 24;
  v15 = *(_DWORD *)(v10 + 96);
  *(_DWORD *)(v10 + 100) = *(_DWORD *)(a1 + 4);
  if ( (a2[6] & 1) != 0 )
    v16 = 3;
  else
    v16 = 4;
  *(_BYTE *)(v15 - 40) = v16;
  *(_DWORD *)(v15 - 24) = *a3;
  *(_DWORD *)(v15 - 20) = a3[1];
  *(_DWORD *)(v15 - 32) = a2[2];
  *(_DWORD *)(v15 - 28) = 1397572723;
  v17 = *(_DWORD *)(v10 + 96);
  *(_DWORD *)(v17 - 8) = a4;
  *(_DWORD *)(v17 - 4) = a5;
  *(_BYTE *)(v17 - 37) = -32;
  IofCallDriver(v8, v10);
  return 259;
}
