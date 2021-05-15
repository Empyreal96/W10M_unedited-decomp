// IoSynchronousInvalidateDeviceRelations 
 
int __fastcall IoSynchronousInvalidateDeviceRelations(int a1, int a2)
{
  int result; // r0
  int v4; // r2
  int v5; // r0
  int v6; // r2
  int v7; // r3
  int v8; // r5
  int v9; // r2
  int v10; // r2
  int v11; // r3
  char v12[24]; // [sp+8h] [bp-18h] BYREF

  result = 0;
  if ( !a1 )
    goto LABEL_24;
  v4 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v4 || (*(_DWORD *)(v4 + 268) & 0x20000) != 0 )
  {
    IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
    v5 = *(_DWORD *)(a1 + 8);
    if ( v5 )
    {
      IoAddTriageDumpDataBlock(v5, *(__int16 *)(v5 + 2));
      v6 = *(_DWORD *)(a1 + 8);
      if ( *(_WORD *)(v6 + 28) )
      {
        IoAddTriageDumpDataBlock(v6 + 28, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
      }
    }
    v7 = *(_DWORD *)(a1 + 176);
    v8 = *(_DWORD *)(v7 + 20);
    if ( v8 )
    {
      IoAddTriageDumpDataBlock(*(_DWORD *)(v7 + 20), 460);
      if ( *(_WORD *)(v8 + 20) )
      {
        IoAddTriageDumpDataBlock(v8 + 20, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v8 + 24), *(unsigned __int16 *)(v8 + 20));
      }
      v9 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      if ( *(_WORD *)(v9 + 28) )
      {
        IoAddTriageDumpDataBlock(v9 + 28, 2);
        IoAddTriageDumpDataBlock(
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 32),
          *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 28));
      }
      v10 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
      if ( v10 && *(_WORD *)(v10 + 28) )
      {
        IoAddTriageDumpDataBlock(v10 + 28, 2);
        v11 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v11 + 32), *(unsigned __int16 *)(v11 + 28));
      }
    }
LABEL_24:
    KeBugCheckEx(202, 2, a1, 0, 0);
  }
  if ( a2 )
  {
    if ( (unsigned int)(a2 - 1) <= 1 )
      result = -1073741637;
  }
  else if ( PnPInitialized && *(_DWORD *)(v4 + 172) == 776 )
  {
    KeInitializeEvent((int)v12, 0, 0);
    result = PnpRequestDeviceAction((int *)a1, 9, 0, 0, (int)v12, 0);
    if ( result >= 0 )
      result = KeWaitForSingleObject((unsigned int)v12, 0, 0, 0, 0);
  }
  else
  {
    result = -1073741823;
  }
  return result;
}
