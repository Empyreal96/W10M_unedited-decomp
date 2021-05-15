// RtlpGenericBasicInverseCoupling 
 
int __fastcall RtlpGenericBasicInverseCoupling(int a1)
{
  int result; // r0

  if ( RtlpGenericInverseCouplingWorker(0, -1, a1) )
    result = RtlpGenericInverseCouplingWorker(-1, 0, a1);
  else
    result = 0;
  return result;
}
