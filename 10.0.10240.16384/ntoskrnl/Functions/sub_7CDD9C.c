// sub_7CDD9C 
 
void sub_7CDD9C()
{
  int v0; // r4
  _DWORD *v1; // r5

  DbgPrintEx(102, 0, (int)"Image %wZ has unrecognized unwind information causing a charge of %u pages\n", v0 + 44);
  RtlSetAllBits(v1);
  JUMPOUT(0x772CD2);
}
