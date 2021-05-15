// XpressDecodeCreate 
 
int XpressDecodeCreate()
{
  int result; // r0

  if ( !CMFAllocFn )
    return 0;
  result = CMFAllocFn(0, 60);
  if ( !result )
    return 0;
  *(_DWORD *)(result + 56) = 903790814;
  return result;
}
