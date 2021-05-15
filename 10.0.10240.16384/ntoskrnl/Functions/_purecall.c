// _purecall 
 
void __noreturn purecall()
{
  RtlRaiseStatus(-1073741822);
}
