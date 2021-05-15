// ViFilterIoCallDriverWithExpandStack 
 
int __fastcall ViFilterIoCallDriverWithExpandStack(int *a1)
{
  int result; // r0

  result = IofCallDriver(*a1, a1[1]);
  a1[2] = result;
  return result;
}
