// MmGetPhysicalMemoryRanges 
 
int MmGetPhysicalMemoryRanges()
{
  unsigned int *v0; // r4
  int v1; // r0
  int v2; // r5
  unsigned int v3; // r6
  int v4; // r1
  unsigned int *v5; // r0
  unsigned int v6; // t1

  v0 = (unsigned int *)MiReferencePageRuns((int)MiSystemPartition, 0);
  v1 = ExAllocatePoolWithTag(512, 16 * (*v0 + 1), 1750101325);
  v2 = v1;
  if ( v1 )
  {
    v3 = 0;
    v4 = v1;
    if ( *v0 )
    {
      v5 = v0;
      do
      {
        v6 = v5[2];
        v5 += 2;
        ++v3;
        *(_QWORD *)v4 = (unsigned __int64)v6 << 12;
        *(_QWORD *)(v4 + 8) = (unsigned __int64)v5[1] << 12;
        v4 += 16;
      }
      while ( v3 < *v0 );
    }
    *(_DWORD *)v4 = 0;
    *(_DWORD *)(v4 + 4) = 0;
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 12) = 0;
  }
  MiDereferencePageRuns((int)v0);
  return v2;
}
