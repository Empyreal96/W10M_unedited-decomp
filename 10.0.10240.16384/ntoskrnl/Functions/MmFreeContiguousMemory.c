// MmFreeContiguousMemory 
 
int __fastcall MmFreeContiguousMemory(unsigned int a1)
{
  int v2; // r3
  unsigned int v4; // r6
  int v5; // r0
  unsigned int v6; // r5
  int v7; // r7
  int v8; // r0
  int v9; // [sp+8h] [bp-20h] BYREF
  unsigned int v10[7]; // [sp+Ch] [bp-1Ch] BYREF

  if ( a1 >= dword_63389C )
  {
    v2 = *((unsigned __int8 *)&MiState[2423]
         + ((int)(((a1 >> 20) & 0xFFC) - (((unsigned int)dword_63389C >> 20) & 0xFFC)) >> 2));
    if ( v2 == 5 || v2 == 13 )
      return sub_514380();
  }
  v4 = *(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096);
  if ( (v4 & 0x400) == 0 )
    v4 = *(_DWORD *)(((a1 >> 10) & 0x3FFFFC) - 0x40000000);
  if ( (v4 & 1) != 0 )
    v5 = 512;
  else
    v5 = 0;
  if ( (a1 & 0xFFF) != 0 )
    KeBugCheckEx(194, 97, a1);
  ExFreeLargePool(a1, &v9, v10, v5);
  v6 = v10[0];
  if ( v10[0] < 0x1000 || (v10[0] & 0xFFF) != 0 || v9 != 1416523587 )
    KeBugCheckEx(194, 96, a1);
  v7 = v10[0];
  if ( MmProtectFreedNonPagedPool == 1 )
    v7 = v10[0] + 4096;
  if ( ViVerifierEnabled )
    VfFreeMemoryNotification(a1, v10[0], 1416523587);
  MmUnmapIoSpace(a1, v7);
  if ( (dword_682604 & 1) != 0 )
  {
    v8 = MiInitPerfMemoryFlags(0, 6);
    MiLogPerfMemoryRangeEvent(a1, 0, v8, v6 >> 12);
  }
  return MiFreeContiguousPages(MiSystemPartition, v4 >> 12, v6 >> 12);
}
