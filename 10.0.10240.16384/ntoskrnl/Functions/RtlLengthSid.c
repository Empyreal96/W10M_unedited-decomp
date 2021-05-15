// RtlLengthSid 
 
int __fastcall RtlLengthSid(int a1)
{
  return 4 * (*(unsigned __int8 *)(a1 + 1) + 2);
}
