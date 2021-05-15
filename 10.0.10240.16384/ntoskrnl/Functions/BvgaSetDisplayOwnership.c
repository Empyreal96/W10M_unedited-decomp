// BvgaSetDisplayOwnership 
 
int __fastcall BvgaSetDisplayOwnership(int result)
{
  int v1; // r2

  if ( result )
    v1 = 0;
  else
    v1 = 2;
  BvgaDisplayState = v1;
  return result;
}
