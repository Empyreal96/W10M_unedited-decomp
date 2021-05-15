// FstubCreateDiskRaw 
 
int __fastcall FstubCreateDiskRaw(int a1, int a2, int a3, int a4)
{
  int v4; // r4
  int *v5; // r5
  int v6; // r4
  __int64 v7; // r0
  __int64 v8; // r2
  int v10; // [sp+8h] [bp-10h] BYREF
  int v11[3]; // [sp+Ch] [bp-Ch] BYREF

  v11[0] = a4;
  v10 = 0;
  v4 = FstubAllocateDiskInformation(a1, (unsigned int *)&v10);
  if ( v4 >= 0 )
  {
    v5 = (int *)v10;
    v4 = FstubDetectPartitionStyle(v10, v11);
    if ( v4 >= 0 )
    {
      v4 = FstubReadSectors(*v5, v5[1], 0i64, 1, v5[10]);
      if ( v4 >= 0 )
      {
        v6 = v5[10];
        memset((_BYTE *)(v6 + 446), 0, 64);
        *(_WORD *)(v6 + 510) = 0;
        *(_DWORD *)(v6 + 440) = 0;
        v4 = FstubWriteSector(*v5, v5[1], 0, 0);
        if ( v11[0] == 1 )
        {
          memset((_BYTE *)v5[10], 0, v5[1]);
          v4 = FstubWriteSector(*v5, v5[1], 1, 0);
          if ( v4 >= 0 )
          {
            HIDWORD(v7) = v5[13];
            LODWORD(v7) = -1;
            v8 = ((unsigned int)v5[12] | 0xFFFFFFFF00000000ui64) + v7;
            v4 = FstubWriteSector(*v5, v5[1], v8, HIDWORD(v8));
          }
        }
      }
    }
    if ( v5 )
      FstubFreeDiskInformation((unsigned int)v5);
  }
  return v4;
}
