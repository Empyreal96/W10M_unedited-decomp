// IoRegisterFsRegistrationChange 
 
int __fastcall IoRegisterFsRegistrationChange(int a1, int a2)
{
  return IoRegisterFsRegistrationChangeMountAware(a1, a2, 0);
}
