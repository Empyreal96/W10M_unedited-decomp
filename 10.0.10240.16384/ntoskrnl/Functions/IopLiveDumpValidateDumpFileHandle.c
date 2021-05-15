// IopLiveDumpValidateDumpFileHandle 
 
int __fastcall IopLiveDumpValidateDumpFileHandle(int a1)
{
  int result; // r0
  char v2; // [sp+8h] [bp-18h]
  int v3; // [sp+10h] [bp-10h]

  if ( !a1 )
    return -1073741811;
  result = ZwQueryInformationFile();
  if ( result >= 0 )
  {
    result = v3;
    if ( v3 >= 0 )
    {
      if ( (v2 & 0x30) == 0 )
        return -1073741811;
      result = 0;
    }
  }
  return result;
}
