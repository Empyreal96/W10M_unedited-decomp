// ExpAssignPasid 
 
int __fastcall ExpAssignPasid(int a1, unsigned int a2)
{
  int v4; // r1
  int v5; // r3
  unsigned int *v6; // r2
  unsigned int v7; // r4

  ObfReferenceObject(a1);
  __dmb(0xBu);
  v6 = (unsigned int *)(a1 + 740);
  do
  {
    v7 = __ldrex(v6);
    if ( v7 )
      break;
    v5 = __strex(a2, v6);
  }
  while ( v5 );
  __dmb(0xBu);
  if ( !v7 )
    return 1;
  ExpFreeAsid(a2 - 1, v4, (int)v6, v5);
  ObfDereferenceObject(a1);
  return 0;
}
