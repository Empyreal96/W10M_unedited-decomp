// PpmResetInterruptRate 
 
int __fastcall PpmResetInterruptRate(_DWORD *a1)
{
  __disable_irq();
  a1[446] = 0;
  a1[445] = a1[576];
  __enable_irq();
  return 0;
}
