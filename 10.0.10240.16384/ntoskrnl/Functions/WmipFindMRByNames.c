// WmipFindMRByNames 
 
int __fastcall WmipFindMRByNames(char *a1)
{
  int v2; // r5
  int *i; // r4

  KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
  v2 = WmipMRHeadPtr;
  for ( i = *(int **)WmipMRHeadPtr; i != (int *)v2; i = (int *)*i )
  {
    if ( !wcscmp((char *)i[5], a1) )
      return sub_80C584();
  }
  KeReleaseMutex((int)&WmipSMMutex);
  return 0;
}
