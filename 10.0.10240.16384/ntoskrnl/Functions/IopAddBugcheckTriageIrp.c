// IopAddBugcheckTriageIrp 
 
int __fastcall IopAddBugcheckTriageIrp(int a1, int a2, int a3)
{
  int v5; // r4
  int v6; // r2
  unsigned int v7; // r6
  int v8; // r8
  unsigned int v9; // r7
  int v10; // r7
  unsigned int v11; // r1
  int v12; // r2
  int v13; // r6
  int v14; // r9
  int v15; // r10
  int v16; // r3
  int v17; // r1
  int v18; // r3
  int v20; // [sp+0h] [bp-28h]
  unsigned int v21; // [sp+4h] [bp-24h]

  v20 = 0;
  v5 = 0;
  if ( !IopIsAddressRangeValid(a1, 112, a3) )
    return -1073741823;
  v7 = *(unsigned __int16 *)(a1 + 2);
  v8 = *(char *)(a1 + 34);
  if ( v7 > 0x800 || v8 > 64 || (v9 = (v7 + 7) >> 3, !IopIsAddressRangeValid(a1, 8 * v9, v6)) )
  {
    IoAddTriageDumpDataBlock(a1, 112);
    return -1073741823;
  }
  IoAddTriageDumpDataBlock(a1, 8 * v9);
  if ( a2 == 1 )
  {
    v10 = 0;
    if ( v8 > 0 )
    {
      v11 = v7 + a1;
      v21 = v7 + a1;
      while ( 1 )
      {
        v12 = a1 + 40 * (char)v10;
        if ( v12 + 152 > v11 )
          return -1073741823;
        v13 = *(_DWORD *)(v12 + 136);
        v14 = 0;
        v15 = 0;
        if ( v13 )
        {
          v16 = v20;
          while ( 1 )
          {
            v20 = v16 + 1;
            if ( !IopIsAddressRangeValid(v13, 184, v12) )
              break;
            v14 = *(_DWORD *)(v13 + 176);
            if ( !IopIsAddressRangeValid(v14, 56, v12) )
              break;
            v18 = *(_DWORD *)(v14 + 24);
            if ( v18 )
              v13 = *(_DWORD *)(v14 + 24);
            else
              v15 = 1;
            if ( v18 )
            {
              v16 = v20;
              if ( v20 < 10 )
                continue;
            }
            goto LABEL_20;
          }
          v5 = -1073741823;
LABEL_20:
          if ( v15 )
            v5 = IopAddBugcheckTriageDeviceNode(*(_DWORD **)(v14 + 20), v17, v12);
          v11 = v21;
        }
        if ( ++v10 >= v8 )
          return v5;
      }
    }
  }
  return v5;
}
