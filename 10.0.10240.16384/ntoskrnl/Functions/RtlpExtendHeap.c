// RtlpExtendHeap 
 
int __fastcall RtlpExtendHeap(_DWORD *a1, int a2)
{
  int v4; // r0
  unsigned __int8 *v5; // r5
  int v6; // r0
  unsigned int v8; // r2
  unsigned int v9; // r5
  int v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r3
  unsigned int v13; // r2
  int v14; // r5
  char v15; // r3
  unsigned __int8 *v16; // r1
  unsigned int v17; // [sp+10h] [bp-28h]
  unsigned int v18; // [sp+18h] [bp-20h] BYREF
  unsigned int v19; // [sp+1Ch] [bp-1Ch]

  v18 = (a2 + 4095) & 0xFFFFF000;
  v4 = RtlpFindAndCommitPages(a1, &v18);
  if ( !v4 )
  {
    if ( (a1[16] & 2) != 0 )
    {
      v8 = a1[25];
      v9 = a2 + 0x2000;
      if ( a2 + 0x2000 > v8 )
        v8 = a2 + 0x2000;
      v17 = (v8 + 0xFFFF) & 0xFFFF0000;
      if ( v17 >= 0xFD0000 )
        v17 = 16580608;
      v10 = ZwAllocateVirtualMemory();
      if ( v10 >= 0 )
      {
        v11 = v17;
LABEL_13:
        v12 = a1[25] + v11;
        v13 = a1[26];
        a1[25] = v12;
        if ( a2 + 4096 <= v13 )
          v19 = v13;
        else
          v19 = a2 + 4096;
        v14 = ZwAllocateVirtualMemory();
        if ( v14 >= 0 )
        {
          if ( !RtlpInitializeHeapSegment(a1) )
            v14 = -1073741801;
          if ( v14 >= 0 )
          {
            v15 = dword_682608;
            if ( (dword_682608 & 0x20) != 0 )
            {
              RtlpLogHeapCommit(a1, 0, v19, 4, 2, 0);
              RtlpLogHeapExtendEvent(a1, MEMORY[0x24], v19, 8 * a1[29]);
              v15 = dword_682608;
            }
            if ( (v15 & 0x20) != 0 )
              RtlpHeapLogRangeReserve(a1, 0, v17);
            v16 = (unsigned __int8 *)MEMORY[0x24];
            if ( a1[19] )
            {
              *MEMORY[0x24] ^= a1[20];
              if ( v16[3] != (v16[2] ^ v16[1] ^ *v16) )
                RtlpAnalyzeHeapFailure(a1, v16);
            }
            return MEMORY[0x24];
          }
        }
        ZwFreeVirtualMemory();
        return 0;
      }
      while ( 1 )
      {
        v11 = v17;
        if ( v17 == v9 )
          break;
        v17 >>= 1;
        if ( v11 >> 1 < v9 )
          v17 = a2 + 0x2000;
        v10 = ZwAllocateVirtualMemory();
        if ( v10 >= 0 )
        {
          v11 = v17;
          break;
        }
      }
      if ( v10 >= 0 )
        goto LABEL_13;
      ++a1[132];
    }
    return 0;
  }
  v18 >>= 3;
  v5 = (unsigned __int8 *)RtlpCoalesceFreeBlocks(a1, v4, &v18);
  v6 = RtlpInsertFreeBlock(a1, v5, v18);
  if ( a1[19] )
  {
    *(_DWORD *)v5 ^= a1[20];
    if ( v5[3] != (v5[2] ^ v5[1] ^ *v5) )
      return sub_553C0C(v6);
  }
  return (int)v5;
}
