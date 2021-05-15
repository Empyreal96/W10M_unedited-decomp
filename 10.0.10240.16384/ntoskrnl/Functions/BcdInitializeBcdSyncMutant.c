// BcdInitializeBcdSyncMutant 
 
int BcdInitializeBcdSyncMutant()
{
  int result; // r0
  unsigned int v1; // [sp+0h] [bp-28h]

  result = ZwCreateMutant();
  if ( result >= 0 )
  {
    __dmb(0xBu);
    do
      result = __ldrex((unsigned int *)&BcdMutantHandle);
    while ( !result && __strex(v1, (unsigned int *)&BcdMutantHandle) );
    __dmb(0xBu);
    if ( result )
      result = sub_9705BC(result, &BcdMutantHandle);
  }
  return result;
}
