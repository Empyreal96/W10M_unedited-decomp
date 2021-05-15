// IoGetDmaAdapter 
 
int __fastcall IoGetDmaAdapter(int a1, int a2, int a3)
{
  int v3; // r4
  int v4; // r6
  int v7; // r3
  unsigned int v9; // r0
  int v10; // r0
  int v11; // r3
  unsigned int v13; // r0
  int v14; // r0
  int v15; // r2
  int v16; // r3
  int v17; // r5
  int v18; // r2
  int v19; // r2
  int v20; // r3
  char v21[4]; // [sp+10h] [bp-78h] BYREF
  int v22; // [sp+14h] [bp-74h]
  void (__fastcall *v23)(int); // [sp+1Ch] [bp-6Ch]
  int (__fastcall *v24)(int, int, int); // [sp+24h] [bp-64h]

  v3 = a1;
  v4 = 0;
  if ( a1 )
  {
    v7 = *(_DWORD *)(*(_DWORD *)(a1 + 176) + 20);
    if ( !v7 || (*(_DWORD *)(v7 + 268) & 0x20000) != 0 )
    {
      IoAddTriageDumpDataBlock(a1, *(unsigned __int16 *)(a1 + 2));
      v14 = *(_DWORD *)(v3 + 8);
      if ( v14 )
      {
        IoAddTriageDumpDataBlock(v14, *(__int16 *)(v14 + 2));
        v15 = *(_DWORD *)(v3 + 8);
        if ( *(_WORD *)(v15 + 28) )
        {
          IoAddTriageDumpDataBlock(v15 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(v3 + 8) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(v3 + 8) + 28));
        }
      }
      v16 = *(_DWORD *)(v3 + 176);
      v17 = *(_DWORD *)(v16 + 20);
      if ( v17 )
      {
        IoAddTriageDumpDataBlock(*(_DWORD *)(v16 + 20), 460);
        if ( *(_WORD *)(v17 + 20) )
        {
          IoAddTriageDumpDataBlock(v17 + 20, 2);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v17 + 24), *(unsigned __int16 *)(v17 + 20));
        }
        v18 = *(_DWORD *)(*(_DWORD *)(v3 + 176) + 20);
        if ( *(_WORD *)(v18 + 28) )
        {
          IoAddTriageDumpDataBlock(v18 + 28, 2);
          IoAddTriageDumpDataBlock(
            *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 176) + 20) + 32),
            *(unsigned __int16 *)(*(_DWORD *)(*(_DWORD *)(v3 + 176) + 20) + 28));
        }
        v19 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 176) + 20) + 8);
        if ( v19 && *(_WORD *)(v19 + 28) )
        {
          IoAddTriageDumpDataBlock(v19 + 28, 2);
          v20 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 176) + 20) + 8);
          IoAddTriageDumpDataBlock(*(_DWORD *)(v20 + 32), *(unsigned __int16 *)(v20 + 28));
        }
      }
      KeBugCheckEx(202, 2, v3, 0, 0);
    }
    v9 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v10 = off_617B2C(v9, a1);
    v11 = *(_DWORD *)(a2 + 20);
    if ( v11 == -1 || v11 == 15 )
      return sub_81964C(v10);
    if ( PnpQueryInterface(v3, (int)&GUID_BUS_INTERFACE_STANDARD, 1, 0x20u, 0, (int)v21) >= 0 )
    {
      if ( v24 )
        v4 = v24(v22, a2, a3);
      v23(v22);
    }
    v13 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    off_617B2C(v13, 0);
  }
  return v4;
}
