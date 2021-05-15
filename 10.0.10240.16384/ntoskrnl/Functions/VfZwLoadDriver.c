// VfZwLoadDriver 
 
int __fastcall VfZwLoadDriver(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckUnicodeString(a1);
  return pXdvZwLoadDriver(a1);
}
