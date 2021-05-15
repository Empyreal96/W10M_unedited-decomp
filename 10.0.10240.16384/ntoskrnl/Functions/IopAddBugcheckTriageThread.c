// IopAddBugcheckTriageThread 
 
int __fastcall IopAddBugcheckTriageThread(int a1, int a2, int a3)
{
  int v4; // r8
  int v5; // r5
  int v6; // r2
  int v7; // r0
  int v8; // r2
  unsigned int v9; // r1
  unsigned int v10; // r4
  int v11; // r0
  _DWORD *v12; // r4
  _DWORD *v13; // r6
  _DWORD *v14; // r7
  int v15; // r2

  v4 = 0;
  v5 = 0;
  if ( !IopIsAddressRangeValid(a1, 1104, a3) )
    return -1073741823;
  IoAddTriageDumpDataBlock(a1, 1104);
  if ( (*(_WORD *)(a1 + 82) & 1) != 0 )
  {
    v7 = *(_DWORD *)(a1 + 64);
    v8 = *(_DWORD *)(a1 + 40);
    __dmb(0xBu);
    v9 = v8 - v7;
    if ( (unsigned int)(v8 - v7) >= 0x1FFF )
      v9 = 0x1FFF;
    v10 = (unsigned int)(v7 + 7) >> 3;
    v11 = IopGetMaxValidMemorySize(8 * v10, v9, v8);
    if ( v11 )
      IoAddTriageDumpDataBlock(8 * v10, v11);
  }
  v12 = *(_DWORD **)(a1 + 908);
  v13 = (_DWORD *)(a1 + 908);
  v14 = v13;
  while ( v12 && v12 != v13 && v4 < 10 )
  {
    ++v4;
    if ( !IopIsAddressRangeValid((int)(v12 - 4), 112, v6) || (_DWORD *)v12[1] != v14 )
      return -1073741823;
    IopAddBugcheckTriageIrp((int)(v12 - 4), 1, v15);
    v14 = v12;
    v12 = (_DWORD *)*v12;
  }
  return v5;
}
