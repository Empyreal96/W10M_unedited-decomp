// KeSetAutoAlignmentProcess 
 
int __fastcall KeSetAutoAlignmentProcess(int a1, int a2, int a3)
{
  unsigned __int8 *v3; // r3
  unsigned int v5; // r1

  __dmb(0xBu);
  v3 = (unsigned __int8 *)(a1 + 100);
  if ( a2 )
    return sub_7BDE88(a1, a2, a3, v3);
  do
    v5 = __ldrex(v3);
  while ( __strex(v5 & 0xFE, v3) );
  __dmb(0xBu);
  return v5 & 1;
}
