// PpmEventTraceControlCallback 
 
int __fastcall PpmEventTraceControlCallback(int a1, int a2)
{
  int result; // r0

  if ( a2 == 2 )
    JUMPOUT(0x81CAA0);
  if ( !a2 )
    result = sub_81CA9C();
  return result;
}
