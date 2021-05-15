// IoRequestDeviceEjectEx 
 
int __fastcall IoRequestDeviceEjectEx(int a1, int a2, int a3, int a4)
{
  int v8; // r0
  _DWORD *v9; // r0
  _DWORD *v10; // r6
  int v12; // r4
  int v13; // r0
  int v14; // r2
  int v15; // r3
  int v16; // r4
  int v17; // r2
  int v18; // r2
  int v19; // r3

  if ( !a1 )
    goto LABEL_20;
  v8 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  if ( !v8 || (*(_DWORD *)(v8 + 268) & 0x20000) != 0 )
  {
    IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
    v13 = *(_DWORD *)(a1 + 8);
    if ( v13 )
    {
      IoAddTriageDumpDataBlock(v13, *(__int16 *)(v13 + 2));
      v14 = *(_DWORD *)(a1 + 8);
      if ( *(_WORD *)(v14 + 28) )
      {
        IoAddTriageDumpDataBlock(v14 + 28, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(*(_DWORD *)(a1 + 8) + 32), *(unsigned __int16 *)(*(_DWORD *)(a1 + 8) + 28));
      }
    }
    v15 = *(_DWORD *)(a1 + 176);
    v16 = *(_DWORD *)(v15 + 20);
    if ( v16 )
    {
      IoAddTriageDumpDataBlock(*(_DWORD *)(v15 + 20), 460);
      if ( *(_WORD *)(v16 + 20) )
      {
        IoAddTriageDumpDataBlock(v16 + 20, 2);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v16 + 24), *(unsigned __int16 *)(v16 + 20));
      }
      v17 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
      if ( *(_WORD *)(v17 + 28) )
      {
        IoAddTriageDumpDataBlock(v17 + 28, 2);
        IoAddTriageDumpDataBlock(
          *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 32),
          *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 28));
      }
      v18 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
      if ( v18 && *(_WORD *)(v18 + 28) )
      {
        IoAddTriageDumpDataBlock(v18 + 28, 2);
        v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 176) + 20) + 8);
        IoAddTriageDumpDataBlock(*(_DWORD *)(v19 + 32), *(unsigned __int16 *)(v19 + 28));
      }
    }
LABEL_20:
    KeBugCheckEx(202, 2, a1, 0, 0);
  }
  v9 = (_DWORD *)ExAllocatePoolWithTag(512, 1460);
  v10 = v9;
  if ( !v9 )
    return -1073741670;
  v12 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
  *v9 = a2;
  v9[1] = a3;
  memmove((int)(v9 + 8), *(_DWORD *)(v12 + 24), *(unsigned __int16 *)(v12 + 20));
  *((_WORD *)v10 + (*(unsigned __int16 *)(v12 + 20) >> 1) + 16) = 0;
  if ( a4 )
    ObfReferenceObjectWithTag(a4);
  v10[2] = a4;
  v10[108] = 0;
  *((_WORD *)v10 + 218) = 0;
  v10[6] = PnpRequestDeviceEjectExWorker;
  v10[7] = v10;
  v10[4] = 0;
  ExQueueWorkItem(v10 + 4, 1);
  return 0;
}
