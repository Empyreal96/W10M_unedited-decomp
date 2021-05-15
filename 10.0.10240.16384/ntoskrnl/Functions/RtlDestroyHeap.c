// RtlDestroyHeap 
 
int __fastcall RtlDestroyHeap(int a1)
{
  int v2; // r2
  _DWORD *v3; // r6
  unsigned int v4; // r3
  int v5; // r3
  int v6; // r4
  char v7; // r3
  int v9; // [sp+4h] [bp-1Ch]

  if ( a1 )
  {
    v2 = *(_DWORD *)(a1 + 88);
    if ( v2 && (_WORD)v2 == 1 )
      MEMORY[0](a1, 0, 8, 0);
    v3 = *(_DWORD **)(a1 + 156);
    while ( (_DWORD *)(a1 + 156) != v3 )
    {
      v4 = (unsigned int)v3;
      v3 = (_DWORD *)*v3;
      v9 = v4 & 0xFFFF0000;
      ZwFreeVirtualMemory();
      if ( (dword_682608 & 0x20) != 0 )
        RtlpHeapLogRangeRelease(a1, v9, 0);
    }
    v5 = *(_DWORD *)(a1 + 64);
    if ( (v5 & 1) == 0 )
    {
      if ( v5 >= 0 )
        ExDeleteResourceLite(*(_DWORD **)(a1 + 200));
      *(_DWORD *)(a1 + 200) = 0;
    }
    do
    {
      v6 = *(_DWORD *)(a1 + 168) - 16;
      RtlpDestroyHeapSegment(v6);
    }
    while ( v6 != a1 );
    v7 = dword_682608;
    if ( (dword_682608 & 0x20) != 0 )
    {
      RtlpLogHeapDestroyEvent(a1);
      v7 = dword_682608;
    }
    if ( (v7 & 0x20) != 0 )
      RtlpHeapLogRangeDestroy(a1);
  }
  else if ( RtlpHeapErrorHandlerThreshold >= 2 )
  {
    DbgPrint("(HeapHandle != NULL)");
    RtlpHeapHandleError();
  }
  return 0;
}
