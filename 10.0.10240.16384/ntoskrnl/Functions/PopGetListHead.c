// PopGetListHead 
 
int *__fastcall PopGetListHead(unsigned int a1)
{
  int v2; // r5
  unsigned int *v4; // r6
  int v5; // r4
  unsigned int v6; // t1

  v2 = 0;
  if ( !PopStateIsSessionSpecific(a1) )
    return &PopPowerSettings;
  v4 = (unsigned int *)PopSessionSpecificGuids;
  v5 = 0;
  while ( 1 )
  {
    v6 = *v4++;
    if ( !memcmp(v6, a1, 16) )
      break;
    if ( (unsigned int)++v5 >= 2 )
      return (int *)v2;
  }
  return (int *)((char *)&PopSessionSpecificLists + 8 * v5);
}
