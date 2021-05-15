// SepReferenceLowBoxObjects 
 
int __fastcall SepReferenceLowBoxObjects(unsigned int a1, int a2)
{
  int v3; // r6
  int v4; // r4

  v3 = 0;
  v4 = 0;
  if ( !a1 )
    return v3;
  while ( 1 )
  {
    a2 += 4;
    v3 = ZwDuplicateObject();
    if ( v3 < 0 )
      break;
    if ( ++v4 >= a1 )
      return v3;
  }
  return sub_51BB00();
}
