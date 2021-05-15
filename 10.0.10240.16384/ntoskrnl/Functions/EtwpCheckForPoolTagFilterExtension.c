// EtwpCheckForPoolTagFilterExtension 
 
int __fastcall EtwpCheckForPoolTagFilterExtension(int a1, int a2, int a3)
{
  int v3; // r4

  v3 = *(unsigned __int8 *)(a1 + 610);
  if ( EtwpGetFlagExtension(a2, 4) )
    return sub_81B79C();
  if ( a3 )
    EtwpUpdateTagFilter(0, 0, &EtwpPoolTagFilter[10 * v3]);
  return 0;
}
