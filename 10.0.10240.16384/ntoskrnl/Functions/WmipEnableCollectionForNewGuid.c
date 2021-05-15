// WmipEnableCollectionForNewGuid 
 
int *__fastcall WmipEnableCollectionForNewGuid(int *a1, int a2)
{
  int *result; // r0
  int *v5; // r5
  int v6; // r3
  int v7; // r1
  int v8; // r2
  int v9; // r3
  int v10; // r0
  int v11; // r3
  int v12; // r1
  int v13; // r2
  int v14; // r3
  char v15[8]; // [sp+8h] [bp-58h] BYREF
  int v16[20]; // [sp+10h] [bp-50h] BYREF

  result = WmipFindGEByGuid((unsigned int)a1, 0);
  v5 = result;
  if ( result )
  {
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    if ( v5[14] )
    {
      v6 = *(_DWORD *)(a2 + 8);
      if ( (v6 & 0x2000) == 0 && (v6 & 0x80000) == 0 )
      {
        *(_DWORD *)(a2 + 8) = v6 | 0x2000;
        v5[2] |= 2u;
        KeReleaseMutex((int)&WmipSMMutex);
        memset(v16, 0, 48);
        v7 = a1[1];
        v8 = a1[2];
        v9 = a1[3];
        v16[6] = *a1;
        v16[7] = v7;
        v16[8] = v8;
        v16[9] = v9;
        v16[0] = 48;
        WmipSendWmiIrp(4, *(_DWORD *)(*(_DWORD *)(a2 + 32) + 28), &v16[6], 48, v16, v15);
        v10 = KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
        if ( !v5[14] )
          return (int *)sub_7CBBC8(v10);
        v5[2] &= 0xFFFFFFFD;
      }
    }
    if ( v5[15] )
    {
      v11 = *(_DWORD *)(a2 + 8);
      if ( (v11 & 0x4000) == 0 && (v11 & 4) != 0 )
      {
        v5[2] |= 4u;
        *(_DWORD *)(a2 + 8) |= 0x4000u;
        KeReleaseMutex((int)&WmipSMMutex);
        memset(v16, 0, 48);
        v12 = a1[1];
        v13 = a1[2];
        v14 = a1[3];
        v16[6] = *a1;
        v16[7] = v12;
        v16[8] = v13;
        v16[9] = v14;
        v16[0] = 48;
        WmipSendWmiIrp(6, *(_DWORD *)(*(_DWORD *)(a2 + 32) + 28), &v16[6], 48, v16, v15);
        KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
        if ( v5[15] )
        {
          v5[2] &= 0xFFFFFFFB;
          WmipReleaseCollectionEnabled(v5);
        }
        else
        {
          WmipDoDisableRequest(v5, 0, 4);
        }
      }
    }
    WmipUnreferenceEntry((int *)&WmipGEChunkInfo, v5);
    result = (int *)KeReleaseMutex((int)&WmipSMMutex);
  }
  return result;
}
