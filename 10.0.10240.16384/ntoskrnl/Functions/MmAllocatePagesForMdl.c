// MmAllocatePagesForMdl 
 
int __fastcall MmAllocatePagesForMdl(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  return MiAllocatePagesForMdl(
           &MiSystemPartition,
           a2,
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           3,
           *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock
                                             + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C))
                                 + 590)
                               + 266),
           0);
}
