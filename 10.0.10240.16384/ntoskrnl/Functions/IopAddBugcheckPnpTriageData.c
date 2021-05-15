// IopAddBugcheckPnpTriageData 
 
int __fastcall IopAddBugcheckPnpTriageData(int a1, unsigned __int16 *a2)
{
  int v3; // r9
  int v4; // r4
  int v5; // r2
  _DWORD **v6; // r7
  int v7; // r2
  int v8; // r2
  _DWORD *v9; // r5
  _DWORD *v10; // r8
  int v11; // r0

  v3 = 0;
  v4 = 0;
  IopAddBugcheckTriageThread();
  if ( !IopIsAddressRangeValid((int)a2, 16, v5) || *a2 != 32769 )
    return -1073741823;
  IoAddTriageDumpDataBlock((int)a2, 16);
  v6 = (_DWORD **)*((_DWORD *)a2 + 1);
  if ( IopIsAddressRangeValid((int)v6, 8, v7) )
  {
    IoAddTriageDumpDataBlock((int)v6, 8);
    v9 = *v6;
    if ( *v6 && v9 != *((_DWORD **)a2 + 1) )
    {
      v10 = v6;
      while ( v9 != v6 && v3 < 10 )
      {
        ++v3;
        if ( !IopIsAddressRangeValid((int)v9, 16, v8) )
          goto LABEL_14;
        IoAddTriageDumpDataBlock((int)v9, 16);
        if ( (_DWORD *)v9[1] != v10 )
          goto LABEL_14;
        v11 = IopAddBugcheckTriageDeviceNode(v9[2]);
        v10 = v9;
        v9 = (_DWORD *)*v9;
        v4 = v11;
        if ( !v9 )
          break;
      }
    }
  }
  else
  {
LABEL_14:
    v4 = -1073741823;
  }
  IopAddBugcheckTriageWorkQueue(*((_DWORD *)a2 + 2));
  return v4;
}
