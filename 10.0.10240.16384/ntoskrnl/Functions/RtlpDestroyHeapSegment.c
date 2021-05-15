// RtlpDestroyHeapSegment 
 
int __fastcall RtlpDestroyHeapSegment(int a1)
{
  int v2; // r1
  __int64 v3; // kr00_8
  int v4; // r4
  __int64 v5; // kr08_8
  int v6; // r4
  int v8; // [sp+Ch] [bp-14h]

  if ( (*(_DWORD *)(a1 + 12) & 1) != 0 )
    return 0;
  v2 = a1 + 16;
  v3 = *(_QWORD *)(a1 + 16);
  v4 = *(_DWORD *)HIDWORD(v3);
  if ( *(_DWORD *)HIDWORD(v3) == *(_DWORD *)(v3 + 4) && v4 == v2 )
  {
    *(_DWORD *)HIDWORD(v3) = v3;
    *(_DWORD *)(v3 + 4) = HIDWORD(v3);
  }
  else
  {
    RtlpLogHeapFailure(12, 0, v2, *(_DWORD *)(v3 + 4), v4);
  }
  v5 = *(_QWORD *)(a1 + 24);
  v8 = *(_DWORD *)(a1 + 28);
  v6 = ZwFreeVirtualMemory();
  if ( (dword_682608 & 0x20) != 0 )
    RtlpHeapLogRangeRelease(v5, v8, 0);
  return v6;
}
