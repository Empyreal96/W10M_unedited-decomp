// PoRequestShutdownEvent 
 
int __fastcall PoRequestShutdownEvent(int a1)
{
  int result; // r0

  if ( a1 )
    return sub_816C40();
  result = PopRequestShutdownWait(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
  if ( result >= 0 )
    result = 0;
  return result;
}
