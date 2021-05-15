// sub_518A84 
 
void __fastcall sub_518A84(int a1)
{
  unsigned int v1; // r1

  ExFreePoolWithTag(a1, 1648710475);
  __dmb(0xBu);
  do
    v1 = __ldrex(&dword_621724[2]);
  while ( __strex(v1 + 1, &dword_621724[2]) );
  __dmb(0xBu);
  JUMPOUT(0x4D9A4C);
}
