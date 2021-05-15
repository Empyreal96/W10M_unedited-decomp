// IoGetStackLimits 
 
int __fastcall IoGetStackLimits(int a1, int a2)
{
  int result; // r0

  result = RtlpGetStackLimits(a1, a2);
  if ( !result )
    result = sub_50EBEC();
  return result;
}
