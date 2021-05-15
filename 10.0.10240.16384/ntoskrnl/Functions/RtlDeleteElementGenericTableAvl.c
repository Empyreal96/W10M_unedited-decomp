// RtlDeleteElementGenericTableAvl 
 
int __fastcall RtlDeleteElementGenericTableAvl(int a1, int a2, int a3, int a4)
{
  if ( FindNodeOrParent(a1) != 1 )
    return 0;
  RtlDeleteElementGenericTableAvlEx(a1, a4);
  return 1;
}
