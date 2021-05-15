// PiUEventHashGuidIntoBucket 
 
unsigned int __fastcall PiUEventHashGuidIntoBucket(unsigned __int8 *a1)
{
  unsigned int v1; // r1
  int v2; // r4
  int v3; // r2
  int v4; // r3

  v1 = 314159;
  v2 = 2;
  do
  {
    v3 = 37 * (37 * (37 * (37 * (37 * (37 * a1[1] + a1[2]) + a1[3]) + a1[4]) + a1[5]) + a1[6])
       - 803794207 * v1
       + 442596621 * *a1;
    v4 = a1[7];
    a1 += 8;
    v1 = v3 + v4;
    --v2;
  }
  while ( v2 );
  return v1 % 0xD;
}
