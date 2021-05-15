// PiDqConvertQueryTypeToString 
 
int __fastcall PiDqConvertQueryTypeToString(int a1, const __int16 **a2)
{
  int result; // r0
  const __int16 *v4; // r3

  result = 0;
  *a2 = 0;
  if ( a1 )
  {
    if ( a1 == 1 )
    {
      v4 = L"Instance";
    }
    else
    {
      if ( a1 != 2 )
        return -1073741811;
      v4 = L"Instances";
    }
  }
  else
  {
    v4 = L"Type";
  }
  *a2 = v4;
  return result;
}
