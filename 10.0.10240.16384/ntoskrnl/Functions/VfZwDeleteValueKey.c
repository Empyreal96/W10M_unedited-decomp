// VfZwDeleteValueKey 
 
int __fastcall VfZwDeleteValueKey(int a1, int a2)
{
  if ( ViZwShouldCheck(a1, a2) )
    ViZwCheckUnicodeString(a2);
  return pXdvZwDeleteValueKey(a1, a2);
}
