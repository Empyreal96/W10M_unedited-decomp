// IoAssignResources 
 
int __fastcall IoAssignResources(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v8; // r3
  int v9; // r0
  int v10; // r2
  int v11; // r3
  int v12; // r6
  int v13; // r2
  int v14; // r2
  int v15; // r3
  int v16; // r2

  if ( a4 )
  {
    v8 = *(_DWORD *)(*(_DWORD *)(a4 + 176) + 20);
    if ( v8 )
    {
      if ( (*(_DWORD *)(v8 + 268) & 0x20000) == 0 )
      {
        if ( a3 )
        {
          IoAddTriageDumpDataBlock(a3, *(__int16 *)(a3 + 2));
          if ( *(_WORD *)(a3 + 28) )
          {
            IoAddTriageDumpDataBlock(a3 + 28, 2);
            IoAddTriageDumpDataBlock(*(_DWORD *)(a3 + 32), *(unsigned __int16 *)(a3 + 28));
          }
        }
        IoAddTriageDumpDataBlock(a4, *(unsigned __int16 *)(a4 + 2));
        v9 = *(_DWORD *)(a4 + 8);
        if ( v9 )
        {
          IoAddTriageDumpDataBlock(v9, *(__int16 *)(v9 + 2));
          v10 = *(_DWORD *)(a4 + 8);
          if ( *(_WORD *)(v10 + 28) )
          {
            IoAddTriageDumpDataBlock(v10 + 28, 2);
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(a4 + 8) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(a4 + 8) + 28));
          }
        }
        v11 = *(_DWORD *)(a4 + 176);
        v12 = *(_DWORD *)(v11 + 20);
        if ( v12 )
        {
          IoAddTriageDumpDataBlock(*(_DWORD *)(v11 + 20), 460);
          if ( *(_WORD *)(v12 + 20) )
          {
            IoAddTriageDumpDataBlock(v12 + 20, 2);
            IoAddTriageDumpDataBlock(*(_DWORD *)(v12 + 24), *(unsigned __int16 *)(v12 + 20));
          }
          v13 = *(_DWORD *)(*(_DWORD *)(a4 + 176) + 20);
          if ( *(_WORD *)(v13 + 28) )
          {
            IoAddTriageDumpDataBlock(v13 + 28, 2);
            IoAddTriageDumpDataBlock(
              *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 32),
              *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 28));
          }
          v14 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 8);
          if ( v14 )
          {
            if ( *(_WORD *)(v14 + 28) )
            {
              IoAddTriageDumpDataBlock(v14 + 28, 2);
              v15 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a4 + 176) + 20) + 8);
              IoAddTriageDumpDataBlock(*(_DWORD *)(v15 + 32), *(unsigned __int16 *)(v15 + 28));
            }
          }
        }
        KeBugCheckEx(202, 2, a4, a3, 0);
      }
    }
  }
  v16 = a5;
  if ( a5 && (!*(_DWORD *)(a5 + 28) || !*(_DWORD *)(a5 + 36)) )
    v16 = 0;
  if ( a6 )
    *a6 = 0;
  return IopLegacyResourceAllocation(2, a3, a4, v16, a6);
}
