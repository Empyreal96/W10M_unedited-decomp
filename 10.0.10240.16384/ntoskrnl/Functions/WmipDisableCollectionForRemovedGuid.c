// WmipDisableCollectionForRemovedGuid 
 
int *__fastcall WmipDisableCollectionForRemovedGuid(int *a1, int a2)
{
  int *result; // r0
  int *v5; // r5
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r1
  int v11; // r2
  int v12; // r3
  _DWORD v13[2]; // [sp+8h] [bp-50h] BYREF
  int v14[18]; // [sp+10h] [bp-48h] BYREF

  result = WmipFindGEByGuid((unsigned int)a1, 0);
  v5 = result;
  if ( result )
  {
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    if ( v5[14] )
    {
      v6 = *(_DWORD *)(a2 + 8);
      if ( (v6 & 0x2000) != 0 && (v6 & 0x80000) == 0 )
      {
        *(_DWORD *)(a2 + 8) = v6 & 0xFFFFDFFF;
        v5[2] |= 2u;
        KeReleaseMutex((int)&WmipSMMutex);
        memset(v14, 0, 48);
        v7 = a1[1];
        v8 = a1[2];
        v9 = a1[3];
        v14[6] = *a1;
        v14[7] = v7;
        v14[8] = v8;
        v14[9] = v9;
        v14[0] = 48;
        WmipSendWmiIrp(5, *(_DWORD *)(*(_DWORD *)(a2 + 32) + 28), (int)&v14[6], 48, (int)v14, v13);
        KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
        if ( v5[14] )
          v5[2] &= 0xFFFFFFFD;
        else
          WmipDoDisableRequest(v5, 1, 2);
      }
    }
    if ( v5[15] && (*(_DWORD *)(a2 + 8) & 0x4000) != 0 )
    {
      v5[2] |= 4u;
      *(_DWORD *)(a2 + 8) &= 0xFFFFBFFF;
      KeReleaseMutex((int)&WmipSMMutex);
      memset(v14, 0, 48);
      v10 = a1[1];
      v11 = a1[2];
      v12 = a1[3];
      v14[6] = *a1;
      v14[7] = v10;
      v14[8] = v11;
      v14[9] = v12;
      v14[0] = 48;
      WmipSendWmiIrp(7, *(_DWORD *)(*(_DWORD *)(a2 + 32) + 28), (int)&v14[6], 48, (int)v14, v13);
      KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
      if ( v5[15] )
      {
        v5[2] &= 0xFFFFFFFB;
        WmipReleaseCollectionEnabled((int)v5);
      }
      else
      {
        WmipDoDisableRequest(v5, 0, 4);
      }
    }
    WmipUnreferenceEntry((int *)&WmipGEChunkInfo, v5);
    result = (int *)KeReleaseMutex((int)&WmipSMMutex);
  }
  return result;
}
