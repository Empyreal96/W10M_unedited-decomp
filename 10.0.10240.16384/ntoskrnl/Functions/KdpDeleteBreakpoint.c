// KdpDeleteBreakpoint 
 
int __fastcall KdpDeleteBreakpoint(unsigned int a1)
{
  int result; // r0

  if ( a1 && a1 <= 0x20 && KdpBreakpointTable[8 * a1 - 2] )
    result = sub_903EB0();
  else
    result = 0;
  return result;
}
