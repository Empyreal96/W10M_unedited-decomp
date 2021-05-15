// MmAllocatePagesForMdlEx 
 
int __fastcall MmAllocatePagesForMdlEx(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
  return MmAllocateNodePagesForMdlEx(
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock
                                             + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C))
                                 + 590)
                               + 266),
           a9);
}
