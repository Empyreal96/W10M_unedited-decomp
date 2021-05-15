// VfZwUnloadDriver 
 
int __fastcall VfZwUnloadDriver(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckUnicodeString(a1);
  return pXdvZwUnloadDriver(a1);
}
