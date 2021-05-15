// VfZwDisplayString 
 
int __fastcall VfZwDisplayString(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckUnicodeString(a1);
  return pXdvZwDisplayString(a1);
}
