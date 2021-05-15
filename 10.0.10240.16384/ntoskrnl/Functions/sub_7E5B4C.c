// sub_7E5B4C 
 
void __fastcall sub_7E5B4C(int a1, int a2)
{
  int v2; // r9
  int *v3; // r2
  int v4; // t1

  v3 = *(int **)(a1 + 152);
  do
  {
    v4 = *v3;
    v3 += 2;
    v2 += (4 * *(unsigned __int8 *)(v4 + 1) + 11) & 0xFFFFFFFC;
    --a2;
  }
  while ( a2 );
  JUMPOUT(0x6F032A);
}
