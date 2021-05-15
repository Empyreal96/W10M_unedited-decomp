// FsRtlGetSupportedFeatures 
 
int __fastcall FsRtlGetSupportedFeatures(int a1, _DWORD *a2)
{
  int result; // r0

  *a2 = 0;
  result = 0;
  if ( FltMgrCallbacks )
    result = (*(int (__fastcall **)(int))(FltMgrCallbacks + 4))(a1);
  return result;
}
