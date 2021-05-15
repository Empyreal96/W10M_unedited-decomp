// RtlpGenericBasicMATSPlus 
 
int __fastcall RtlpGenericBasicMATSPlus(int a1)
{
  int result; // r0

  if ( RtlpGenericMATSPlusWorker(0, -1, a1) )
    result = RtlpGenericMATSPlusWorker(-1, 0, a1);
  else
    result = 0;
  return result;
}
