// KeQueryNodeMaximumProcessorCount 
 
int __fastcall KeQueryNodeMaximumProcessorCount(unsigned int a1)
{
  int result; // r0

  if ( a1 >= (unsigned __int16)KeNumberNodes )
    result = 0;
  else
    result = *((unsigned __int8 *)*(&KeNodeBlock + a1) + 288);
  return result;
}
