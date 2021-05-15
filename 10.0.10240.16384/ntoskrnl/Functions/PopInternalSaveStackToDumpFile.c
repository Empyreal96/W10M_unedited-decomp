// PopInternalSaveStackToDumpFile 
 
int __fastcall PopInternalSaveStackToDumpFile(int result, int a2, int a3)
{
  int i; // r4
  int v4; // r5
  int v5; // r5
  int v6; // r0
  int v7; // r6
  int v8; // r0

  for ( i = result; i; i = *(_DWORD *)(i + 16) )
  {
    result = IopIsAddressRangeValid(i, 184, a3);
    if ( !result )
      break;
    result = IoAddTriageDumpDataBlock(i, *(unsigned __int16 *)(i + 2));
    v4 = *(_DWORD *)(i + 8);
    if ( v4 )
    {
      result = IopIsAddressRangeValid(*(_DWORD *)(i + 8), 168, a3);
      if ( result )
      {
        IoAddTriageDumpDataBlock(v4, *(__int16 *)(v4 + 2));
        result = *(_DWORD *)(v4 + 32);
        if ( result )
          result = IoAddTriageDumpDataBlock(result, *(unsigned __int16 *)(v4 + 28));
      }
    }
    v5 = *(_DWORD *)(i + 176);
    if ( v5 )
    {
      result = IopIsAddressRangeValid(*(_DWORD *)(i + 176), 4, a3);
      if ( result )
      {
        IoAddTriageDumpDataBlock(v5, *(unsigned __int16 *)(v5 + 2));
        v6 = *(_DWORD *)(v5 + 20);
        if ( v6 )
          IoAddTriageDumpDataBlock(v6 & 0xFFFFF000, ((*(_DWORD *)(v5 + 20) & 0xFFFu) + 4607) >> 12 << 12);
        v7 = *(_DWORD *)(v5 + 24);
        if ( v7 && IopIsAddressRangeValid(*(_DWORD *)(v5 + 24), 184, a3) )
          IoAddTriageDumpDataBlock(v7, *(unsigned __int16 *)(v7 + 2));
        v8 = *(_DWORD *)(v5 + 40);
        if ( v8 && IopIsAddressRangeValid(v8, 88, a3) )
          IoAddTriageDumpDataBlock(*(_DWORD *)(v5 + 40), *(__int16 *)(*(_DWORD *)(v5 + 40) + 2));
        result = *(_DWORD *)(v5 + 12);
        if ( result )
          result = IoAddTriageDumpDataBlock(result, 68);
      }
    }
  }
  return result;
}
