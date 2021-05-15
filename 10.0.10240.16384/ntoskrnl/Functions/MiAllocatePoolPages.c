// MiAllocatePoolPages 
 
int __fastcall MiAllocatePoolPages(int a1, unsigned int a2, int a3, int a4)
{
  unsigned int v5; // r4
  unsigned int v7; // r7
  int v8; // r8
  int v9; // r2
  int v10; // r0
  int v11; // r0
  int v12; // r0
  int v13[6]; // [sp+8h] [bp-18h] BYREF

  v13[0] = a4;
  if ( (a1 & 1) != 0 )
    return MiAllocatePagedPoolPages();
  v7 = ((a2 & 0xFFF) != 0) + (a2 >> 12);
  v8 = *(unsigned __int16 *)(*((_DWORD *)*(&KiProcessorBlock + *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x16C))
                             + 590)
                           + 266);
  if ( v7 > 3
    || ((a1 & 0x200) == 0 ? (v9 = v7 + 22 * v8) : (v9 = v7 - 1 + 22 * v8 + 4),
        (v10 = dword_6337E8 + 8 * v9, !*(_WORD *)(v10 + 4))
     || (v11 = RtlpInterlockedPopEntrySList((unsigned __int64 *)v10)) == 0) )
  {
    v5 = MiFindNonPagedPoolVa(a1, v7, v8, v13);
    if ( v5 || (MiFreeExcessSegments(1), (v5 = MiFindNonPagedPoolVa(a1, v7, v8, v13)) != 0) )
    {
      if ( (*(_DWORD *)(((v5 >> 20) & 0xFFC) - 1070596096) & 0x400) != 0 )
        return v5;
      if ( v13[0] == 2 )
        MiFlushTbAsNeeded(((v5 >> 10) & 0x3FFFFC) - 0x40000000, v7, 0);
      v12 = MiFindNonPagedPoolPages(v8, v7);
      if ( v12 )
      {
        MiAssignNonPagedPoolPtes(v5, v7, a1, v12);
        return v5;
      }
      ++dword_632A98;
      MiTrimSegmentCache(0);
      MiReturnNonPagedPoolVa(v5, v7, a1);
    }
    else
    {
      ++dword_632A98;
      ++dword_632ABC;
      MiTrimSegmentCache(0);
    }
    return 0;
  }
  v5 = v11 - 8;
  if ( *(_DWORD *)(v11 - 8) != (dword_634C80 ^ (v11 - 8)) )
    sub_50EA20();
  return v5;
}
