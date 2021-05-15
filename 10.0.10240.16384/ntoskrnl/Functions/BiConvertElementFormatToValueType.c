// BiConvertElementFormatToValueType 
 
int __fastcall BiConvertElementFormatToValueType(unsigned int a1)
{
  int result; // r0

  if ( a1 == 1 || a1 <= 1 )
    goto LABEL_7;
  if ( a1 <= 3 )
    return 1;
  if ( a1 != 4 )
LABEL_7:
    result = 3;
  else
    result = 7;
  return result;
}
