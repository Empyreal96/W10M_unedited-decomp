// sub_81C414 
 
void __fastcall sub_81C414(int a1, unsigned int *a2)
{
  unsigned int v2; // r2
  unsigned int v3; // r0

  if ( dword_61ED68 )
    v2 = 2;
  else
    v2 = 1;
  __dmb(0xBu);
  do
    v3 = __ldrex(a2);
  while ( !v3 && __strex(v2, a2) );
  __dmb(0xBu);
  JUMPOUT(0x7BC6D4);
}
