// FstubCreateDiskMBR 
 
int __fastcall FstubCreateDiskMBR(int a1, _DWORD *a2)
{
  int v3; // r4
  _DWORD *v4; // r5
  int v5; // r4
  unsigned int v7[4]; // [sp+8h] [bp-10h] BYREF

  v7[0] = 0;
  v3 = FstubAllocateDiskInformation(a1, v7);
  if ( v3 >= 0 )
  {
    v4 = (_DWORD *)v7[0];
    v3 = FstubReadSectors(*(_DWORD *)v7[0], *(_DWORD *)(v7[0] + 4), 0i64, 1, *(_DWORD *)(v7[0] + 40));
    if ( v3 >= 0 )
    {
      v5 = v4[10];
      memset((_BYTE *)(v5 + 446), 0, 64);
      *(_WORD *)(v5 + 510) = -21931;
      *(_DWORD *)(v5 + 440) = *a2;
      v3 = FstubWriteSector(*v4, v4[1], 0, 0);
    }
    FstubFreeDiskInformation((unsigned int)v4);
  }
  return v3;
}
