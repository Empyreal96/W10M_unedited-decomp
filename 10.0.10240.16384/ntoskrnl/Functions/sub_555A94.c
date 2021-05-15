// sub_555A94 
 
void __fastcall sub_555A94(int a1, int *a2, __int16 a3)
{
  int v3; // r5
  int v4; // r4
  unsigned int v5; // r0
  unsigned int *v6; // r2
  unsigned int v7; // r1

  v4 = *a2;
  v5 = *a2 & 0xFFFFF800 | a3 & 0x7FF;
  v6 = (unsigned int *)(v3 + 512);
  do
    v7 = __ldrex(v6);
  while ( v7 == v4 && __strex(v5, v6) );
  JUMPOUT(0x4F8AB6);
}
