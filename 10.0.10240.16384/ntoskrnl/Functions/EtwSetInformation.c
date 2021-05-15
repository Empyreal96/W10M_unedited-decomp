// EtwSetInformation 
 
int __fastcall EtwSetInformation(int a1, int a2, int a3, int a4, int a5)
{
  if ( !a1 )
    return -1073741816;
  if ( a3 != 2 )
    return sub_815AF8();
  if ( a4 && (unsigned int)(a5 - 3) <= 0x7FFC )
    return EtwpSetProviderTraitsKm();
  return -1073741811;
}
