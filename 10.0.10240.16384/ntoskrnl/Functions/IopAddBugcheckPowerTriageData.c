// IopAddBugcheckPowerTriageData 
 
int __fastcall IopAddBugcheckPowerTriageData(int a1, int *a2, int a3)
{
  int v5; // r8
  int v6; // r5
  int v7; // r2
  int v8; // r2
  _DWORD **v9; // r6
  _DWORD *i; // r4
  _DWORD **v11; // r6
  int v12; // r8
  int v13; // r2
  _DWORD *v14; // r4
  int v15; // r0

  v5 = 0;
  v6 = 0;
  ((void (*)(void))IopAddBugcheckTriageDevice)();
  IopAddBugcheckTriageIrp(a3, 1);
  if ( !IopIsAddressRangeValid((int)a2, 16, v7) || *(unsigned __int16 *)a2 != 0x8000 )
    return -1073741823;
  IoAddTriageDumpDataBlock((int)a2, 16);
  v9 = (_DWORD **)a2[1];
  if ( v9 )
  {
    if ( IopIsAddressRangeValid(a2[1], 8, v8) )
    {
      IoAddTriageDumpDataBlock((int)v9, 8);
      for ( i = *v9; i && i != (_DWORD *)a2[1] && v5 < 10; i = (_DWORD *)*i )
      {
        ++v5;
        if ( !IopIsAddressRangeValid((int)i, 16, v8) )
          goto LABEL_14;
        IoAddTriageDumpDataBlock((int)i, 16);
        if ( (_DWORD **)i[1] != v9 )
          goto LABEL_14;
        IopAddBugcheckTriageIrp(i[2], 1);
        IopAddBugcheckTriageDevice(i[3]);
        v9 = (_DWORD **)i;
      }
    }
    else
    {
LABEL_14:
      v6 = -1073741823;
    }
  }
  v11 = (_DWORD **)a2[2];
  if ( v11 )
  {
    v12 = 0;
    if ( IopIsAddressRangeValid(a2[2], 8, v8) )
    {
      IoAddTriageDumpDataBlock((int)v11, 8);
      v14 = *v11;
      while ( v14 && v14 != (_DWORD *)a2[2] && v12 < 10 )
      {
        ++v12;
        if ( !IopIsAddressRangeValid((int)v14, 16, v13) )
          goto LABEL_25;
        IoAddTriageDumpDataBlock((int)v14, 16);
        if ( (_DWORD **)v14[1] != v11 )
          goto LABEL_25;
        v15 = IopAddBugcheckTriageThread(v14[2]);
        v11 = (_DWORD **)v14;
        v14 = (_DWORD *)*v14;
        v6 = v15;
      }
    }
    else
    {
LABEL_25:
      v6 = -1073741823;
    }
  }
  IopAddBugcheckTriageWorkQueue(a2[3]);
  return v6;
}
