// MiDeleteProcessPageDirectories 
 
int __fastcall MiDeleteProcessPageDirectories(int a1)
{
  int result; // r0

  if ( (unsigned __int16)word_620D24 >= 8u )
    result = MiFreeHardwarePageDirectory(a1);
  else
    result = RtlpInterlockedPushEntrySList((unsigned __int64 *)&MiArmPageDirectorySlist, *(_DWORD **)(a1 + 32));
  return result;
}
