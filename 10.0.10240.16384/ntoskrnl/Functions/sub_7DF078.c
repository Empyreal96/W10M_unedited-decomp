// sub_7DF078 
 
void __noreturn sub_7DF078()
{
  int v0; // r4
  int v1; // r0
  int v2; // r2
  int v3; // r3
  int v4; // r5
  int v5; // r2
  int v6; // r2
  int v7; // r3

  IoAddTriageDumpDataBlock(v0, *(unsigned __int16 *)(v0 + 2));
  v1 = *(_DWORD *)(v0 + 8);
  if ( v1 )
  {
    IoAddTriageDumpDataBlock(v1, *(__int16 *)(v1 + 2));
    v2 = *(_DWORD *)(v0 + 8);
    if ( *(_WORD *)(v2 + 28) )
    {
      IoAddTriageDumpDataBlock(v2 + 28, 2);
      IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(v0 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(v0 + 8) + 28));
    }
  }
  v3 = *(_DWORD *)(v0 + 176);
  v4 = *(_DWORD *)(v3 + 20);
  if ( v4 )
  {
    IoAddTriageDumpDataBlock(*(_DWORD *)(v3 + 20), 460);
    if ( *(_WORD *)(v4 + 20) )
    {
      IoAddTriageDumpDataBlock(v4 + 20, 2);
      IoAddTriageDumpDataBlock(*(_DWORD *)(v4 + 24), *(unsigned __int16 *)(v4 + 20));
    }
    v5 = *(_DWORD *)(*(_DWORD *)(v0 + 176) + 20);
    if ( *(_WORD *)(v5 + 28) )
    {
      IoAddTriageDumpDataBlock(v5 + 28, 2);
      IoAddTriageDumpDataBlock(
        *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v0 + 176) + 20) + 32),
        *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v0 + 176) + 20) + 28));
    }
    v6 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v0 + 176) + 20) + 8);
    if ( v6 )
    {
      if ( *(_WORD *)(v6 + 28) )
      {
        IoAddTriageDumpDataBlock(v6 + 28, 2);
        v7 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v0 + 176) + 20) + 8);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v7 + 32), *(unsigned __int16 *)(v7 + 28));
      }
    }
  }
  KeBugCheckEx(202, 2, v0, 0, 0);
}
