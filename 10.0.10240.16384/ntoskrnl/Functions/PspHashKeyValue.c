// PspHashKeyValue 
 
int __fastcall PspHashKeyValue(int a1, unsigned int a2)
{
  char v3; // r2
  unsigned int i; // r1
  char v5; // r3

  if ( !a1 )
    return 0;
  v3 = 0;
  for ( i = 0; i < a2; v3 += v5 )
  {
    v5 = *(_BYTE *)(i + a1);
    ++i;
  }
  return v3 & 0x1F;
}
