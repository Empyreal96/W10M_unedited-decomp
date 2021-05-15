// PopIntSteerSetPerProcTrigger 
 
int __fastcall PopIntSteerSetPerProcTrigger(int a1, int *a2, int a3)
{
  int result; // r0

  if ( a3 != 4 )
    return -1073741811;
  result = 0;
  PpmIntSteerLoadMax = *a2;
  return result;
}
