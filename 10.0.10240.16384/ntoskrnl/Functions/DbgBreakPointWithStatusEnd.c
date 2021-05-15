// DbgBreakPointWithStatusEnd 
 
void __noreturn DbgBreakPointWithStatusEnd()
{
  __debugservice();
  JUMPOUT(0x423312);
}
