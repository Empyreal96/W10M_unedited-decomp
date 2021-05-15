// MiAllocateDriverPage 
 
int MiAllocateDriverPage()
{
  unsigned int v1; // r4
  int v2; // r3
  int v3; // [sp+Ch] [bp-24h]
  unsigned int v4[6]; // [sp+18h] [bp-18h] BYREF

  if ( MiFindContiguousPages(MiSystemPartition, 0, dword_632F30, 0, 1u, 1, 0x80000000, v3, 0x20000000, v4) < 0 )
    return sub_7CD9CC();
  v1 = v4[0];
  if ( (++dword_632F4C & 0x1FF) != 0 )
    v2 = v4[0] - 1;
  else
    v2 = -1;
  dword_632F30 = v2;
  MiPreInitializeSystemImagePage(MmPfnDatabase + 24 * v4[0]);
  return v1;
}
