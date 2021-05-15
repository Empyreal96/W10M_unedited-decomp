// RtlpFunctionAddressTableEntry 
 
void (__fastcall __noreturn *__fastcall RtlpFunctionAddressTableEntry(int a1))(int a1)
{
  switch ( a1 )
  {
    case 0:
      return (void (__fastcall __noreturn *)(int))RtlUnwindEx;
    case 1:
      return (void (__fastcall __noreturn *)(int))_C_specific_handler;
    case 2:
      return (void (__fastcall __noreturn *)(int))RtlpExecuteHandlerForException;
    case 3:
      return (void (__fastcall __noreturn *)(int))RtlDispatchException;
    case 4:
      return RtlRaiseStatus;
    case 5:
      return (void (__fastcall __noreturn *)(int))KiDispatchException;
    case 6:
      return (void (__fastcall __noreturn *)(int))KiExceptionDispatch;
  }
  return 0;
}
