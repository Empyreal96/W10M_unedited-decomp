// sub_80313C 
 
void __fastcall sub_80313C(int a1, int a2, int a3, int a4, int a5, int a6, int a7, unsigned int a8, int a9)
{
  int v9; // r5
  unsigned int v10; // r7
  int v11; // r0

  v11 = ExAllocatePoolWithTag(512, a8 + 36 * a9, 1953985605);
  if ( v11 )
  {
    memmove(v11, v10, a8);
    ExFreePoolWithTag(v10);
    JUMPOUT(0x745576);
  }
  ObfDereferenceObjectWithTag(v9);
  JUMPOUT(0x74578E);
}
