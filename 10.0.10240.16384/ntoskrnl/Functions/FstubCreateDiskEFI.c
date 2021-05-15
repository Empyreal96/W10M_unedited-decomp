// FstubCreateDiskEFI 
 
int __fastcall FstubCreateDiskEFI(int a1, _DWORD *a2)
{
  int v3; // r4
  unsigned int v4; // r5
  unsigned int v5; // r4
  int v6; // r7
  unsigned int v7; // r1
  __int64 v8; // r8
  __int64 v9; // kr00_8
  int v11[8]; // [sp+28h] [bp-20h] BYREF

  v11[0] = 0;
  v3 = FstubAllocateDiskInformation(a1, (unsigned int *)v11);
  if ( v3 >= 0 )
  {
    v4 = v11[0];
    v3 = FstubWriteBootSectorEFI(v11[0]);
    if ( v3 >= 0 )
    {
      v5 = *(_DWORD *)(v4 + 4);
      v11[0] = a2[4];
      FstubAdjustPartitionCount(v5, v11);
      v6 = v11[0];
      v7 = v11[0] << 7;
      if ( !v5 )
        __brkdiv0();
      v8 = v7 / v5 + 2i64;
      v9 = *(_QWORD *)(v4 + 48) - v7 / v5 - 2i64;
      v11[0] = HIDWORD(v9);
      v3 = FstubWritePartitionTableEFI(v4, *a2, a2[1], a2[2], a2[3], v6, v8, HIDWORD(v8), v9, HIDWORD(v9), 0, 0, 0);
      if ( v3 >= 0 )
        v3 = FstubWritePartitionTableEFI(v4, *a2, a2[1], a2[2], a2[3], v6, v8, HIDWORD(v8), v9, v11[0], 1, 0, 0);
    }
    FstubFreeDiskInformation(v4);
  }
  return v3;
}
