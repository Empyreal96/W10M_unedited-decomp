// MiPurgeTransitionList 
 
int *__fastcall MiPurgeTransitionList(int a1, int a2, int a3, int a4)
{
  int i; // r0
  int *result; // r0
  int *v7; // r4

  for ( i = 0; ; i = (int)v7 )
  {
    result = MiGetNextPartition(i, a2, a3, a4);
    v7 = result;
    if ( !result )
      break;
    MiPurgePartitionStandby((int)result, a1);
  }
  return result;
}
