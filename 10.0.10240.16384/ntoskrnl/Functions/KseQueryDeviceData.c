// KseQueryDeviceData 
 
int __fastcall KseQueryDeviceData(int a1, int a2, _DWORD *a3, int a4)
{
  int v7; // r4
  int v9; // r2
  int v10; // r4
  int v12[8]; // [sp+8h] [bp-20h] BYREF

  v12[0] = 0;
  v7 = dword_6416D4;
  v9 = 0;
  __dmb(0xBu);
  if ( v7 != 2 || (KseEngine & 2) != 0 )
    return -1073741275;
  if ( !a2 || !a3 || !a4 )
    return -1073741811;
  if ( (*a3 & 0x20000000) != 0 )
    v9 = 1;
  *a3 = 0;
  if ( !v9 && KsepDbQueryRegistryDeviceData(a1, a2, a3, a4) != -1073741275 )
    goto LABEL_18;
  if ( !KsepShimDbChanged() )
  {
    if ( KsepDbCacheQueryDevice(a1, a2, a3, a4) == -1073741275 )
      goto LABEL_12;
LABEL_18:
    JUMPOUT(0x7CE3B8);
  }
  KseResetDeviceCache();
LABEL_12:
  v10 = KsepDbCacheReadDevice(a1, v12);
  if ( v10 >= 0 )
    return sub_7CE394();
  return v10;
}
