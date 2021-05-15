// sub_4E23A8 
 
int __fastcall sub_4E23A8(int a1, int a2, int *a3)
{
  unsigned int v3; // r5
  int v5; // r0

  v3 = a2 - 1;
  v5 = vsnprintf(a1, a2 - 1);
  if ( v5 < 0 || v5 > v3 )
    JUMPOUT(0x54D994);
  if ( v5 == v3 )
    return sub_54D990();
  if ( a3 )
    *a3 = v5;
  return 0;
}
