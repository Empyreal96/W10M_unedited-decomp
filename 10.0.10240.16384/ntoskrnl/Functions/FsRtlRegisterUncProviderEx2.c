// FsRtlRegisterUncProviderEx2 
 
int __fastcall FsRtlRegisterUncProviderEx2(int a1, int a2, int a3)
{
  int result; // r0

  if ( *(unsigned __int16 *)(a3 + 2) >= 0x200u )
    result = FsRtlpRegisterUncProvider();
  else
    result = sub_819CC4();
  return result;
}
