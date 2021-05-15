// KeDeregisterNmiCallback 
 
int __fastcall KeDeregisterNmiCallback(int a1)
{
  int result; // r0

  if ( a1 == -1 )
    result = 0;
  else
    result = -1073741816;
  return result;
}
