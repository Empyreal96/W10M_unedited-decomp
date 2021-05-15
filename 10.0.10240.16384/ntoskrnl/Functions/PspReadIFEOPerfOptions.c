// PspReadIFEOPerfOptions 
 
__int64 __fastcall PspReadIFEOPerfOptions(int a1, int *a2, int a3, int a4)
{
  __int64 v7; // [sp+0h] [bp-20h]
  int v8[6]; // [sp+8h] [bp-18h] BYREF

  v8[0] = a3;
  v8[1] = a4;
  if ( RtlQueryImageFileKeyOption(a1, L"IoPriority", 4, a2 + 2, 4u, 0) >= 0 )
    *a2 |= 1u;
  if ( RtlQueryImageFileKeyOption(a1, L"PagePriority", 4, a2 + 3, 4u, 0) >= 0 )
    *a2 |= 2u;
  if ( RtlQueryImageFileKeyOption(a1, L"CpuPriorityClass", 4, a2 + 4, 4u, 0) >= 0 )
    *a2 |= 4u;
  if ( RtlQueryImageFileKeyOption(a1, L"WorkingSetLimitInKB", 4, v8, 4u, 0) >= 0 )
  {
    a2[5] = (unsigned int)v8[0] >> 2;
    a2[1] |= 1u;
  }
  return v7;
}
