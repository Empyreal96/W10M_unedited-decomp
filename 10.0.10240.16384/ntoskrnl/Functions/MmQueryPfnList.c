// MmQueryPfnList 
 
int __fastcall MmQueryPfnList(int a1, int *a2)
{
  int *v2; // r4
  unsigned int v3; // r6
  int v4; // r5
  unsigned int v5; // r7

  v2 = a2;
  v3 = (unsigned int)&a2[4 * a1];
  v4 = 0;
  if ( (unsigned int)a2 < v3 )
  {
    while ( 1 )
    {
      v5 = v2[2];
      if ( !MI_IS_PFN(v5) )
        break;
      MiIdentifyPfnWrapper((int *)(MmPfnDatabase + 24 * v5), v2);
      v2 += 4;
      if ( (unsigned int)v2 >= v3 )
        return v4;
    }
    v4 = -1073741584;
    v2[3] |= 2u;
  }
  return v4;
}
