// KsepDbCacheReadDevice 
 
int __fastcall KsepDbCacheReadDevice(unsigned __int16 *a1, _DWORD *a2)
{
  int v3; // r0
  int v4; // r5
  int v5; // r4
  int v6; // r6
  int v8[15]; // [sp+14h] [bp-3Ch] BYREF

  v8[0] = 0;
  *a2 = 0;
  v3 = KsepPoolAllocatePaged(36);
  v4 = v3;
  if ( !v3 )
    return -1073741801;
  *(_DWORD *)(v3 + 28) = v3 + 28;
  *(_DWORD *)(v3 + 32) = v3 + 28;
  v5 = KsepStringDuplicate(v3 + 20, a1);
  if ( v5 >= 0 )
  {
    v5 = KseShimDatabaseOpen(v8);
    v6 = v8[0];
    if ( v5 >= 0 )
    {
      if ( SdbGetDatabaseMatchEx(v8[0], 1, a1, (int)&KsepMatchMachineInfo, 0, 0, (int)&KsepMatchMachineInfo) )
        return sub_7CE434();
      v5 = -1073741275;
    }
    if ( v6 )
      KseShimDatabaseClose(v6);
  }
  if ( v4 )
    KsepCacheDeviceFree(v4);
  return v5;
}
