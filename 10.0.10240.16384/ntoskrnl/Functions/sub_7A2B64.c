// sub_7A2B64 
 
int __fastcall sub_7A2B64(_DWORD *a1)
{
  int result; // r0

  *a1 = 0;
  result = RtlCheckPortableOperatingSystem();
  if ( result >= 0 )
    result = sub_811DBC();
  return result;
}
