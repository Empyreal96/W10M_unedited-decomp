// MmEnablePeriodicAccessClearing 
 
int *__fastcall MmEnablePeriodicAccessClearing(char a1, int a2, int a3, int a4)
{
  int *result; // r0

  result = 0;
  while ( 1 )
  {
    result = MiGetNextPartition((int)result, a2, a3, a4);
    if ( !result )
      break;
    a4 = result[878];
    *(_BYTE *)(a4 + 47) = a1;
  }
  return result;
}
