// IoInvalidateDeviceRelations 
 
int __fastcall IoInvalidateDeviceRelations(int a1, int a2)
{
  int v3; // r3
  int v4; // r1
  int v6; // r0
  int v7; // r2
  int v8; // r3
  int v9; // r5
  int v10; // r2
  int v11; // r2
  int v12; // r3

  if ( !a1 )
    goto LABEL_23;
  v3 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v3 || (*(_DWORD *)(v3 + 268) & 0x20000) != 0 )
  {
    IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
    v6 = *(_DWORD *)(a1 + 8);
    if ( v6 )
    {
      IoAddTriageDumpDataBlock(v6, *(__int16 *)(v6 + 2));
      v7 = *(_DWORD *)(a1 + 8);
      if ( *(_WORD *)(v7 + 28) )
      {
        IoAddTriageDumpDataBlock(v7 + 28, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
      }
    }
    v8 = *(_DWORD *)(a1 + 176);
    v9 = *(_DWORD *)(v8 + 20);
    if ( v9 )
    {
      IoAddTriageDumpDataBlock(*(_DWORD *)(v8 + 20), 460);
      if ( *(_WORD *)(v9 + 20) )
      {
        IoAddTriageDumpDataBlock(v9 + 20, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v9 + 24), *(unsigned __int16 *)(v9 + 20));
      }
      v10 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      if ( *(_WORD *)(v10 + 28) )
      {
        IoAddTriageDumpDataBlock(v10 + 28, 2);
        IoAddTriageDumpDataBlock(
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 32),
          *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 28));
      }
      v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
      if ( v11 )
      {
        if ( *(_WORD *)(v11 + 28) )
        {
          IoAddTriageDumpDataBlock(v11 + 28, 2);
          v12 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v12 + 32), *(unsigned __int16 *)(v12 + 28));
        }
      }
    }
LABEL_23:
    KeBugCheckEx(202, 2, a1);
  }
  switch ( a2 )
  {
    case 5:
      v4 = 8;
      return PnpRequestDeviceAction(a1, v4, 0);
    case 2:
      v4 = 5;
      return PnpRequestDeviceAction(a1, v4, 0);
    case 0:
      v4 = 9;
      return PnpRequestDeviceAction(a1, v4, 0);
  }
  return sub_51FF38();
}
