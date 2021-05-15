// DrvDbSetRegValueMappedProperty 
 
int __fastcall DrvDbSetRegValueMappedProperty(int a1, int a2, int a3, int a4, int a5, int a6)
{
  int result; // r0
  char v7[16]; // [sp+10h] [bp-10h] BYREF

  if ( a4 )
  {
    if ( a4 == 5 )
    {
      if ( a6 != 2 )
        return -1073741811;
    }
    else if ( a4 == 17 && a6 != 1 )
    {
      return -1073741811;
    }
    result = RegRtlSetValue(a2, *(unsigned __int16 **)(a3 + 8));
  }
  else
  {
    result = RtlInitUnicodeStringEx((int)v7, *(unsigned __int16 **)(a3 + 8));
    if ( result >= 0 )
      result = ZwDeleteValueKey();
    if ( result == -1073741772 )
      result = -1073741275;
  }
  return result;
}
