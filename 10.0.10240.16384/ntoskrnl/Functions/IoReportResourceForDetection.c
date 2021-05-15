// IoReportResourceForDetection 
 
int __fastcall IoReportResourceForDetection(int a1, int a2, int a3, int a4)
{
  int v6; // r3
  int v7; // r0
  int v8; // r2
  int v9; // r3
  int v10; // r6
  int v11; // r2
  int v12; // r2
  int v13; // r3

  if ( a4 )
  {
    v6 = *(_DWORD *)(*(_DWORD *)(a4 + 176) + 20);
    if ( v6 )
    {
      if ( (*(_DWORD *)(v6 + 268) & 0x20000) == 0 )
      {
        if ( a1 )
        {
          IoAddTriageDumpDataBlock(a1, *(__int16 *)(a1 + 2));
          if ( *(_WORD *)(a1 + 28) )
          {
            IoAddTriageDumpDataBlock(a1 + 28, 2);
            IoAddTriageDumpDataBlock(*(_DWORD *)(a1 + 32), *(unsigned __int16 *)(a1 + 28));
          }
        }
        IoAddTriageDumpDataBlock(a4, *(unsigned __int16 *)(a4 + 2));
        v7 = *(_DWORD *)(a4 + 8);
        if ( v7 )
        {
          IoAddTriageDumpDataBlock(v7, *(__int16 *)(v7 + 2));
          v8 = *(_DWORD *)(a4 + 8);
          if ( *(_WORD *)(v8 + 28) )
          {
            IoAddTriageDumpDataBlock(v8 + 28, 2);
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(a4 + 8) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(a4 + 8) + 28));
          }
        }
        v9 = *(_DWORD *)(a4 + 176);
        v10 = *(_DWORD *)(v9 + 20);
        if ( v10 )
        {
          IoAddTriageDumpDataBlock(*(_DWORD *)(v9 + 20), 460);
          if ( *(_WORD *)(v10 + 20) )
          {
            IoAddTriageDumpDataBlock(v10 + 20, 2);
            IoAddTriageDumpDataBlock(*(_DWORD *)(v10 + 24), *(unsigned __int16 *)(v10 + 20));
          }
          v11 = *(_DWORD *)(*(_DWORD *)(a4 + 176) + 20);
          if ( *(_WORD *)(v11 + 28) )
          {
            IoAddTriageDumpDataBlock(v11 + 28, 2);
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 28));
          }
          v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 8);
          if ( v12 )
          {
            if ( *(_WORD *)(v12 + 28) )
            {
              IoAddTriageDumpDataBlock(v12 + 28, 2);
              v13 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 8);
              IoAddTriageDumpDataBlock(*(_DWORD *)(v13 + 32), *(unsigned __int16 *)(v13 + 28));
            }
          }
        }
        KeBugCheckEx(202, 2, a4, a1, 0);
      }
    }
  }
  return IoReportResourceUsageInternal(3, a2, a1, a2);
}
