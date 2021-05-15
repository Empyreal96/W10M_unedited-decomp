// towlower 
 
int __fastcall towlower(int a1)
{
  unsigned __int16 v1; // r4
  int v2; // r0
  unsigned __int16 v3; // r3

  v1 = a1;
  v2 = iswctype(a1, 1);
  v3 = v1 + 32;
  if ( !v2 )
    v3 = v1;
  return v3;
}
