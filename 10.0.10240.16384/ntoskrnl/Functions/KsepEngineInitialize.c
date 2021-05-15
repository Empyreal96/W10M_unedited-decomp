// KsepEngineInitialize 
 
int __fastcall KsepEngineInitialize(_DWORD *a1)
{
  int result; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r1
  int v6; // r2

  if ( !a1 )
    return sub_96580C();
  a1[3] = a1 + 3;
  a1[4] = a1 + 3;
  a1[5] = a1 + 5;
  a1[6] = a1 + 5;
  a1[7] = 0;
  v3 = KsepCacheInitialize((int)a1, (int)KsepCacheDeviceEqual, (int)KsepCacheDeviceHash, (int)KsepCacheDeviceFree);
  a1[10] = v3;
  if ( !v3 )
    return -1073741801;
  v4 = KsepCacheInitialize(v3, (int)KsepCacheHwIdEqual, (int)KsepCacheHwIdHash, (int)KsepCacheHwIdFree);
  a1[11] = v4;
  if ( !v4 )
    return -1073741801;
  a1[8] = KseGetIoCallbacks;
  a1[9] = KseSetCompletionHook;
  result = KsepEngineReadFlags(&KseEngine, v5, v6, (int)KseSetCompletionHook);
  if ( result >= 0 && (KseEngine & 3) == 3 )
    result = -1073741637;
  return result;
}
