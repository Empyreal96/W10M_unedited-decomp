// WdiUpdateSem 
 
int WdiUpdateSem()
{
  int result; // r0

  result = WdipAccessCheck();
  if ( result >= 0 )
    result = WdipSemUpdate();
  return result;
}
