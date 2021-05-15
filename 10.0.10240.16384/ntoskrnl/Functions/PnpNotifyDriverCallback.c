// PnpNotifyDriverCallback 
 
int __fastcall PnpNotifyDriverCallback(_DWORD *a1, int a2, int *a3)
{
  unsigned int v4; // r5
  int v7; // r0
  int v8; // r10
  int v9; // r5
  int v10; // r0
  int v11; // r9
  int v12; // r8
  int v13; // r5
  int v15; // r0
  int v16; // r2
  int v17; // [sp+8h] [bp-40h]

  v4 = a1[5];
  if ( MmIsSessionAddress(v4) && !a1[4] )
    return -1073741811;
  v7 = MmIsSessionAddress(v4);
  if ( !v7
    || (*(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 192) & 0x10000) != 0
    && (v7 = PsGetCurrentProcessSessionId(), a1[3] == v7) )
  {
    v17 = KeGetCurrentIrql(v7);
    v8 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134);
    v9 = ((int (__fastcall *)(int, _DWORD))a1[5])(a2, a1[6]);
    v10 = KeGetCurrentIrql(v9);
    v11 = v10;
    v12 = *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x134);
    if ( a3 )
      *a3 = v9;
    v13 = 0;
    if ( v17 != v10 || v8 != v12 )
    {
      v15 = a1[7];
      if ( v15 )
      {
        IoAddTriageDumpDataBlock(v15, *(__int16 *)(v15 + 2));
        v16 = a1[7];
        if ( *(_WORD *)(v16 + 28) )
        {
          IoAddTriageDumpDataBlock(v16 + 28, 2);
          IoAddTriageDumpDataBlock(*(_DWORD *)(a1[7] + 32), *(unsigned __int16 *)(a1[7] + 28));
        }
      }
      KeBugCheckEx(202, 10, a1[7], v11, v12);
    }
    return v13;
  }
  return sub_7EE9D4();
}
