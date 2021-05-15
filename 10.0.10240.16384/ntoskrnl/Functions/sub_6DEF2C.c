// sub_6DEF2C 
 
__int64 __fastcall sub_6DEF2C(__int64 a1, unsigned int a2, int a3)
{
  if ( EtwRegister(MS_Windows_LicensingStartServiceTrigger_Provider, 0, 0) >= 0 )
  {
    a1 = 0i64;
    EtwWrite(a2, a3, (int)KERNEL_AUDIT_API_PSSETLOADIMAGENOTIFYROUTINE, 0);
    EtwUnregister(a2);
  }
  return a1;
}
