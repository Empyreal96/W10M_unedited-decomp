// IopAddBugcheckTriageDeviceNode 
 
int __fastcall IopAddBugcheckTriageDeviceNode(_DWORD *a1, int a2, int a3)
{
  int v3; // r7
  int v4; // r6
  int v6; // r1
  int v7; // r2
  int v8; // r0
  int v9; // r5
  int v10; // r0

  v3 = 0;
  v4 = 0;
  while ( 1 )
  {
    ++v3;
    if ( !IopIsAddressRangeValid((int)a1, 48, a3) )
      break;
    IoAddTriageDumpDataBlock((int)a1, 48);
    IopAddBugcheckTriageUnicodeString(a1[5], a1[6]);
    IopAddBugcheckTriageUnicodeString(a1[7], a1[8]);
    v8 = a1[9];
    if ( v8 )
      IopAddBugcheckTriageIrp(v8, 0);
    v9 = a1[10];
    if ( v9 )
    {
      if ( IopIsAddressRangeValid(a1[10], 32, v7) )
      {
        IoAddTriageDumpDataBlock(v9, 32);
        v10 = *(_DWORD *)(v9 + 8);
        if ( v10 )
          IopAddBugcheckTriageIrp(v10, 0);
      }
    }
    IopAddBugcheckTriageDevice(a1[4], v6, v7);
    a1 = (_DWORD *)a1[2];
    if ( !a1 || v3 >= 10 )
      return v4;
  }
  return -1073741823;
}
