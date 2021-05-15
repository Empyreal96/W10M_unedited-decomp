// SeLogAccessFailure 
 
unsigned int __fastcall SeLogAccessFailure(int a1, int a2, int a3, int a4)
{
  unsigned int result; // r0

  result = KeGetCurrentIrql(a1);
  if ( result < 2 && EtwKernelProvRegHandle )
  {
    if ( byte_6417CC )
      result = sub_521C94();
  }
  return result;
}
