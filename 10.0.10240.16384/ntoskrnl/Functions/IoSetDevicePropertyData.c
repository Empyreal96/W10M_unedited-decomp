// IoSetDevicePropertyData 
 
int __fastcall IoSetDevicePropertyData(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
  int v8; // r3
  int result; // r0
  int v10; // r0
  int v11; // r2
  int v12; // r3
  int v13; // r5
  int v14; // r2
  int v15; // r2
  int v16; // r3

  if ( !a1 )
    goto LABEL_18;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v8 || (*(_DWORD *)(v8 + 268) & 0x20000) != 0 )
  {
    IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
    v10 = *(_DWORD *)(a1 + 8);
    if ( v10 )
    {
      IoAddTriageDumpDataBlock(v10, *(__int16 *)(v10 + 2));
      v11 = *(_DWORD *)(a1 + 8);
      if ( *(_WORD *)(v11 + 28) )
      {
        IoAddTriageDumpDataBlock(v11 + 28, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
      }
    }
    v12 = *(_DWORD *)(a1 + 176);
    v13 = *(_DWORD *)(v12 + 20);
    if ( v13 )
    {
      IoAddTriageDumpDataBlock(*(_DWORD *)(v12 + 20), 460);
      if ( *(_WORD *)(v13 + 20) )
      {
        IoAddTriageDumpDataBlock(v13 + 20, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v13 + 24), *(unsigned __int16 *)(v13 + 20));
      }
      v14 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      if ( *(_WORD *)(v14 + 28) )
      {
        IoAddTriageDumpDataBlock(v14 + 28, 2);
        IoAddTriageDumpDataBlock(
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 32),
          *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 28));
      }
      v15 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
      if ( v15 && *(_WORD *)(v15 + 28) )
      {
        IoAddTriageDumpDataBlock(v15 + 28, 2);
        v16 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v16 + 32), *(unsigned __int16 *)(v16 + 28));
      }
    }
LABEL_18:
    KeBugCheckEx(202, 2, a1, 0, 0);
  }
  if ( a7 )
    result = PnpSetDevicePropertyData(a1);
  else
    result = sub_7DED68();
  return result;
}
