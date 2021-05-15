// sub_7C2308 
 
void __fastcall sub_7C2308(int a1)
{
  int v1; // r4
  unsigned __int16 *v2; // r5
  int v3; // t1

  for ( ; a1; v1 = 65599 * v1 + v3 )
  {
    v3 = *v2++;
    --a1;
  }
  JUMPOUT(0x6AAF86);
}
