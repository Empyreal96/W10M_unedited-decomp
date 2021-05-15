// sub_50E1CC 
 
void __fastcall __noreturn sub_50E1CC(int a1, unsigned int *a2)
{
  int v2; // r4
  unsigned int v3; // r2
  unsigned int v4; // r2

  __dmb(0xBu);
  do
  {
    v3 = __ldrex(a2);
    v4 = v3 - 1;
  }
  while ( __strex(v4, a2) );
  __dmb(0xBu);
  if ( !v4 )
    KeSetEvent(v2 + 116, 0, 0);
  PopFxBugCheck(1543, v2, -1073741738, 0);
}
