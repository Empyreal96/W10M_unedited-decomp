// PopPepRequestWork 
 
unsigned int __fastcall PopPepRequestWork(unsigned int result, unsigned int a2)
{
  int v2; // r4

  if ( a2 > result )
  {
    v2 = a2 - result;
    if ( a2 != result )
    {
      do
      {
        result = PopFxRequestWorker(0);
        --v2;
      }
      while ( v2 );
    }
  }
  return result;
}
