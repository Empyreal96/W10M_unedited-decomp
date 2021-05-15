// sub_7EE554 
 
void __fastcall sub_7EE554(int a1, int a2)
{
  unsigned int *v2; // r4
  int v3; // r6
  int v4; // r7

  memmove(v3, a2, 40 * v4);
  ExFreePoolWithTag(*v2);
  JUMPOUT(0x780098);
}
