// MiUnmapLargeDriver 
 
int __fastcall MiUnmapLargeDriver(unsigned int a1, int a2)
{
  int v2; // r5
  unsigned int v3; // r4

  v2 = (a2 + 1023) & 0xFFFFFC00;
  v3 = *(_DWORD *)(((a1 >> 20) & 0xFFC) - 1070596096);
  MiUnmapLargePages(a1, v2 << 12, 12);
  return MiFreeContiguousPages((int)MiSystemPartition, v3 >> 12, v2);
}
