// MmAllocateNodePagesForMdlEx 
 
int __fastcall MmAllocateNodePagesForMdlEx(int a1, int a2, int a3, int a4, __int64 a5, unsigned int a6, int a7, unsigned int a8, int a9)
{
  int v9; // lr
  int v10; // r7
  int v11; // r4
  int result; // r0
  int varg_r0; // [sp+50h] [bp+8h]

  varg_r0 = a1;
  v9 = a1;
  if ( a8 >= (unsigned __int16)KeNumberNodes )
    return 0;
  v10 = a7 == -1 || a7 > 2 ? 3 : MiPlatformCacheAttributes[a7];
  v11 = a9;
  if ( (a9 & 0xFFFFFC00) != 0 )
    return 0;
  if ( (a9 & 0x20) == 0 )
    goto LABEL_9;
  v11 = a9 | 0x10;
  if ( !a5 )
  {
    v11 = a9 | 0x14;
    goto LABEL_9;
  }
  if ( ((a5 - 1) & a5) != 0 || a5 < 4096 )
    return 0;
  if ( !(_DWORD)a5 )
    __brkdiv0();
  if ( a6 % (unsigned int)a5 )
    return 0;
  v9 = a1;
LABEL_9:
  if ( (v11 & 0x100) != 0 )
    result = sub_511990();
  else
    result = MiAllocatePagesForMdl(
               &MiSystemPartition,
               a2,
               v9,
               a2,
               a3,
               a4,
               a5,
               HIDWORD(a5),
               a6,
               v10,
               (unsigned __int16)a8,
               v11);
  return result;
}
