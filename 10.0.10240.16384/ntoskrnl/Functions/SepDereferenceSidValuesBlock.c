// SepDereferenceSidValuesBlock 
 
int __fastcall SepDereferenceSidValuesBlock(int result)
{
  unsigned int *v1; // r4
  unsigned int v2; // r5
  signed int v3; // r5

  if ( result )
  {
    __dmb(0xBu);
    v1 = (unsigned int *)(result + 4);
    do
    {
      v2 = __ldrex(v1);
      v3 = v2 - 1;
    }
    while ( __strex(v3, v1) );
    if ( v3 <= 0 )
      result = sub_80A6B8();
  }
  return result;
}
