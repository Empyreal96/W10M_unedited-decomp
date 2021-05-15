// PopStateIsSessionSpecific 
 
int __fastcall PopStateIsSessionSpecific(unsigned int a1)
{
  unsigned int *v1; // r6
  int v2; // r4
  int v3; // r5
  unsigned int v5; // t1

  v1 = (unsigned int *)PopSessionSpecificGuids;
  v2 = 0;
  v3 = 0;
  while ( 1 )
  {
    v5 = *v1++;
    if ( !memcmp(v5, a1, 16) )
      break;
    if ( (unsigned int)++v3 >= 2 )
      return v2;
  }
  return 1;
}
