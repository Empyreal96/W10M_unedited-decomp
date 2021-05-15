// PopIntSteerSetTimeUnparkTrigger 
 
int __fastcall PopIntSteerSetTimeUnparkTrigger(int a1, int *a2, int a3)
{
  if ( a3 != 4 )
    return -1073741811;
  PpmIntSteerTriggerMax = *a2;
  dword_60EA84 = 0;
  return 0;
}
