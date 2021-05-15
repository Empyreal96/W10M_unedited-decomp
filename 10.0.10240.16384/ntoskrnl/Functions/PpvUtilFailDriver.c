// PpvUtilFailDriver 
 
int __fastcall PpvUtilFailDriver(int result)
{
  int v1; // r0

  if ( PpvUtilVerifierEnabled )
  {
    if ( result )
    {
      if ( result == 1 )
      {
        v1 = 587;
      }
      else
      {
        if ( result != 2 )
          return result;
        v1 = 589;
      }
      result = VfErrorReport8(v1);
    }
    else
    {
      result = VfErrorReport7();
    }
  }
  return result;
}
