// SmEtwEnableCallback 
 
unsigned __int8 *__fastcall SmEtwEnableCallback(int a1, int a2, int a3, int a4, int a5)
{
  unsigned __int8 *result; // r0
  _DWORD v6[228]; // [sp-4h] [bp-390h] BYREF

  if ( (!a2 || a2 == 1) && (dword_636E9C = a5 | 0x40, a2 == 1) || a2 == 2 )
  {
    SmKmEtwLogStoreRundown((unsigned __int8 *)&qword_636E90, (int)SmGlobals);
    SmpCacheStatsCopy((int)SmGlobals, v6, dword_636EA8);
    result = (unsigned __int8 *)SmKmEtwLogGlobalStats(&qword_636E90, (int)v6);
    if ( (dword_636E9C & 0x80) != 0 )
      result = SMKM_STORE_MGR<SM_TRAITS>::SmStoresContentsRundown((unsigned __int8 *)SmGlobals);
  }
  return result;
}
