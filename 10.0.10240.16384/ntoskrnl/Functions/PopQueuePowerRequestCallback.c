// PopQueuePowerRequestCallback 
 
int __fastcall PopQueuePowerRequestCallback(int result, int a2, int a3, int a4)
{
  if ( PopPowerRequestAttributes[2 * a2 + 1] )
  {
    if ( a3 )
      ++*(_BYTE *)(a2 + result + 52);
    else
      --*(_BYTE *)(result + a2 + 52);
    result = PopQueuePowerRequestCallbacks(result, a4);
  }
  return result;
}
