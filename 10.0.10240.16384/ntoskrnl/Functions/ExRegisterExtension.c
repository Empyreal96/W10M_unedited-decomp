// ExRegisterExtension 
 
int __fastcall ExRegisterExtension(int a1, int a2, int a3)
{
  int result; // r0

  if ( (a2 & 0xFFFF0000) == 0x10000 && *(_DWORD *)(a3 + 8) )
    result = sub_8111F8();
  else
    result = -1073741811;
  return result;
}
