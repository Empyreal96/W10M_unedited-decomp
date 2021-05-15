// ViLookupThunkArray 
 
int __fastcall ViLookupThunkArray(int *a1, int a2, unsigned int *a3)
{
  while ( 1 )
  {
    if ( !*a1 )
      return 0;
    if ( !strcmp(*a1, a3) )
      break;
    a1 = (int *)((char *)a1 + a2);
  }
  return a1[1];
}
