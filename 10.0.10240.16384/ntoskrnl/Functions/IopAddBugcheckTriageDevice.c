// IopAddBugcheckTriageDevice 
 
int __fastcall IopAddBugcheckTriageDevice(int a1, int a2, int a3)
{
  int v3; // r7
  int v4; // r5
  int v6; // r2
  unsigned int v7; // r3
  unsigned int v8; // r6
  int v9; // r1
  int v10; // r6
  int v11; // r2
  int v12; // r2
  int v13; // r6

  v3 = 0;
  v4 = 0;
  while ( 1 )
  {
    ++v3;
    if ( !IopIsAddressRangeValid(a1, 184, a3) )
      break;
    v7 = *(unsigned __int16 *)(a1 + 2);
    if ( v7 <= 0x3000 && (v8 = (v7 + 7) >> 3, IopIsAddressRangeValid(a1, 8 * v8, v6)) )
      v9 = 8 * v8;
    else
      v9 = 184;
    IoAddTriageDumpDataBlock(a1, v9);
    v10 = *(_DWORD *)(a1 + 176);
    if ( IopIsAddressRangeValid(v10, 56, v11) )
      IoAddTriageDumpDataBlock(v10, 56);
    v13 = *(_DWORD *)(a1 + 8);
    if ( IopIsAddressRangeValid(v13, 168, v12) )
    {
      IoAddTriageDumpDataBlock(v13, 168);
      IopAddBugcheckTriageUnicodeString(*(_DWORD *)(v13 + 28), *(_DWORD *)(v13 + 32));
    }
    a1 = *(_DWORD *)(a1 + 16);
    if ( !a1 || v3 >= 10 )
      return v4;
  }
  return -1073741823;
}
