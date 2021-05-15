// IopGetRegistryValues 
 
int __fastcall IopGetRegistryValues(int a1, int *a2)
{
  int result; // r0

  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  result = IopGetRegistryValue(a1, L"Identifier", 40, a2);
  if ( result >= 0 || result == -1073741772 )
  {
    result = IopGetRegistryValue(a1, L"Configuration Data", 32, a2 + 1);
    if ( result >= 0 || result == -1073741772 )
    {
      result = IopGetRegistryValue(a1, L"Component Information", 16, a2 + 2);
      if ( result >= 0 || result == -1073741772 )
        result = 0;
    }
  }
  return result;
}
