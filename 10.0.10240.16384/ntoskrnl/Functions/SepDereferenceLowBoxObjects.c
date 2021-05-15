// SepDereferenceLowBoxObjects 
 
int __fastcall SepDereferenceLowBoxObjects(int a1, int a2)
{
  int v2; // r4
  int i; // r5
  int v6; // r0

  v2 = a1;
  for ( i = 0; v2; --v2 )
  {
    a2 += 4;
    v6 = ZwClose();
    if ( v6 < 0 )
      i = v6;
  }
  return i;
}
