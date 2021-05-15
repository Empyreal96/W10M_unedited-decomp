// PopResetCBTriggers 
 
int __fastcall PopResetCBTriggers(int result)
{
  int *v1; // r2
  int v2; // r1

  v1 = PopCB;
  v2 = 4;
  do
  {
    v1[53] &= ~result;
    v1 += 4;
    --v2;
  }
  while ( v2 );
  return result;
}
