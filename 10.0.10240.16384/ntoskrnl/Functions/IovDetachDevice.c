// IovDetachDevice 
 
int __fastcall IovDetachDevice(int result)
{
  int v1; // r4
  int v2; // r3

  v1 = result;
  v2 = VfIoDisabled;
  __dmb(0xBu);
  if ( !v2 )
  {
    if ( !*(_DWORD *)(result + 16) )
      VfErrorReport8(514);
    result = IovUtilFlushStackCache(v1);
  }
  return result;
}
