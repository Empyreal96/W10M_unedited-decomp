// ViDdiDispatchWmiQueryAllData 
 
int __fastcall ViDdiDispatchWmiQueryAllData(int a1, int a2)
{
  int v2; // r4
  int v5; // r4
  unsigned int v6; // r8
  _DWORD *v7; // r7
  unsigned int *v8; // r5
  unsigned int v9; // r6
  int v10; // r8
  int v11; // r0
  unsigned int v12; // r3
  int v13; // r3
  unsigned int v15; // [sp+8h] [bp-28h] BYREF
  int v16; // [sp+Ch] [bp-24h] BYREF
  unsigned int v17; // [sp+10h] [bp-20h] BYREF
  int v18[7]; // [sp+14h] [bp-1Ch] BYREF

  v2 = *(_DWORD *)(a2 + 96);
  if ( *(_DWORD *)(v2 + 8) != a1 )
    return -1073741637;
  if ( RtlCompareMemory(*(unsigned __int8 **)(v2 + 12), (int)&GUID_VERIFIER_WMI_INTERFACE, 16) != 16 )
    return -1073741163;
  v6 = *(_DWORD *)(v2 + 16);
  v7 = *(_DWORD **)(a1 + 40);
  if ( v6 < 0x38 )
    return -1073741789;
  v8 = *(unsigned int **)(v2 + 20);
  KeQuerySystemTime(v8 + 4);
  v5 = VfIrpLogLockDatabase(*v7);
  if ( v5 < 0 )
    return v5;
  v5 = VfIrpLogRetrieveWmiData(*v7, 0, v18, &v16, &v17, &v15);
  if ( v5 < 0 )
  {
    VfIrpLogUnlockDatabase(*v7);
    return v5;
  }
  v9 = v15 + 72;
  v15 = v9;
  if ( v9 > v6 )
  {
    VfIrpLogUnlockDatabase(*v7);
    v8[11] |= 0x20u;
    v8[12] = v9;
    *(_DWORD *)(a2 + 28) = 56;
    return 0;
  }
  v10 = v16;
  if ( v16 )
  {
    v11 = VfIrpLogRetrieveWmiData(*v7, v8, v18, &v16, &v17, &v15);
    v9 = v15;
    v10 = v16;
    v5 = v11;
  }
  VfIrpLogUnlockDatabase(*v7);
  if ( v5 >= 0 )
  {
    if ( v10 )
    {
      *v8 = 72;
      v9 = 72;
      v13 = 0;
      v8[12] = 0;
      v8[13] = 0;
      v8[15] = 0;
    }
    else
    {
      v12 = v8[11];
      *v8 = v9;
      v8[11] = v12 & 0xFFFFFFEF | 1;
      v8[13] = 0;
      v8[12] = v17;
      v13 = v18[0];
    }
    v8[14] = v13;
    *(_DWORD *)(a2 + 28) = v9;
    return 0;
  }
  return v5;
}
