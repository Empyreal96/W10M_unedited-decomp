// PiSwValidatePropertyArray 
 
int __fastcall PiSwValidatePropertyArray(_DWORD *a1, unsigned int a2)
{
  int result; // r0
  unsigned int v5; // r5

  result = 0;
  v5 = 0;
  if ( a2 )
  {
    while ( !a1[5] )
    {
      result = PnpValidatePropertyData(a1[9], a1[8], a1[7], 0);
      if ( result < 0 )
        break;
      ++v5;
      a1 += 10;
      if ( v5 >= a2 )
        return result;
    }
    result = -1073741811;
  }
  return result;
}
