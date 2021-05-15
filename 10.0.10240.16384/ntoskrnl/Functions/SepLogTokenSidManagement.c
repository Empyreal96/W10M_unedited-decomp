// SepLogTokenSidManagement 
 
int __fastcall SepLogTokenSidManagement(int result, int a2)
{
  if ( EtwKernelProvRegHandle )
  {
    if ( SepTokenSidManagementLoggingEnabled )
      result = sub_7DBDE4(result, a2, result);
  }
  return result;
}
