// _MapCmClassPropertyToRegValue 
 
const __int16 *__fastcall MapCmClassPropertyToRegValue(int a1, int a2)
{
  if ( a2 > 24 )
  {
    switch ( a2 )
    {
      case 26:
        return L"DeviceType";
      case 27:
        return L"Exclusive";
      case 28:
        return L"DeviceCharacteristics";
    }
    return 0;
  }
  switch ( a2 )
  {
    case 24:
      return L"Security";
    case 18:
      return L"UpperFilters";
    case 8:
      return L"Class";
    case 13:
      return L"ClassDesc";
  }
  if ( a2 != 19 )
    return 0;
  return L"LowerFilters";
}
