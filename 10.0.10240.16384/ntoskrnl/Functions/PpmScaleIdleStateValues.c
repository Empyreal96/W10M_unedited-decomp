// PpmScaleIdleStateValues 
 
int __fastcall PpmScaleIdleStateValues(int result)
{
  if ( *(_BYTE *)(result + 52) )
    result = sub_53FBB8();
  return result;
}
