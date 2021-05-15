// KeGetPrcb 
 
int __fastcall KeGetPrcb(unsigned int a1)
{
  int result; // r0

  if ( a1 >= KeNumberProcessors_0 )
    result = 0;
  else
    result = (int)*(&KiProcessorBlock + a1);
  return result;
}
