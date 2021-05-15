// PnpQueryRebalanceWorker 
 
int __fastcall PnpQueryRebalanceWorker(int a1, int a2, _DWORD *a3, _DWORD *a4, unsigned __int16 *a5, unsigned __int8 a6)
{
  int v7; // r0
  int v8; // r7
  int v12; // r0
  int v13; // r4
  unsigned int v14; // r5
  int v15; // r1
  int v17[8]; // [sp+0h] [bp-20h] BYREF

  v17[0] = (int)a4;
  v7 = *(_DWORD *)(a1 + 172);
  v8 = 0;
  if ( v7 != 776 || (*(_DWORD *)(a1 + 268) & 0x1000) != 0 )
  {
    if ( v7 == 769
      || v7 == 770
      || v7 == 771
      || v7 == 777
      || v7 == 785
      || v7 == 786
      || (*(_DWORD *)(a1 + 268) & 0x40000) != 0 )
    {
      return v8;
    }
    v8 = -1073741823;
  }
  else
  {
    v12 = PnpQueryStopDeviceNode(a1, a6);
    v8 = v12;
    if ( v12 >= 0 )
    {
      if ( v12 == 281 )
        PipSetDevNodeFlags(a1, 1024);
      v13 = *(_DWORD *)(a1 + 16);
      v14 = a2 + 40 * *a3;
      memset((_BYTE *)v14, 0, 40);
      *(_DWORD *)(v14 + 20) = 0;
      *(_DWORD *)(v14 + 8) = 4;
      *(_DWORD *)v14 = v13;
      PnpGetResourceRequirementsForAssignTable(v14, v14 + 40, v17);
      v15 = a2 + 40 * *a3;
      if ( *(int *)(v15 + 36) >= 0 )
      {
        if ( (*(_DWORD *)(v15 + 4) & 0x20) == 0 )
          ++*a3;
        goto LABEL_19;
      }
      v8 = *(_DWORD *)(v15 + 36);
    }
    PnpCancelStopDeviceNode((int *)a1);
  }
LABEL_19:
  if ( v8 < 0 )
  {
    if ( a4 )
      *a4 = 6;
    if ( a5 && a5[1] >= (unsigned int)*(unsigned __int16 *)(a1 + 20) )
      RtlCopyUnicodeString(a5, (unsigned __int16 *)(a1 + 20));
  }
  return v8;
}
