// ExRaiseAccessViolation 
 
void __noreturn ExRaiseAccessViolation()
{
  RtlRaiseStatus(-1073741819);
}
