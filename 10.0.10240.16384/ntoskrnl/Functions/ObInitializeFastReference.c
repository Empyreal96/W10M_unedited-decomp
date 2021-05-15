// ObInitializeFastReference 
 
int __fastcall ObInitializeFastReference(int result, int a2)
{
  int *v3; // r4
  int v4; // r3

  v3 = (int *)result;
  if ( a2 )
  {
    result = ObReferenceObjectExWithTag(a2, 7);
    v4 = a2 + 7;
  }
  else
  {
    v4 = 0;
  }
  *v3 = v4;
  return result;
}
