// PsIsSiloInSilo 
 
int __fastcall PsIsSiloInSilo(int a1, int a2)
{
  bool i; // zf

  for ( i = a2 == 0; !i; i = a1 == a2 )
  {
    if ( !a1 )
      return 0;
    a1 = *(_DWORD *)(a1 + 84);
  }
  return 1;
}
