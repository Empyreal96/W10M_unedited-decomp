// VfDriverInitSuccess 
 
int __fastcall VfDriverInitSuccess(int result)
{
  if ( ViActiveVerifierThunks != result )
    result = sub_8E533C();
  return result;
}
