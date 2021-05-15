// sub_7D4FA0 
 
void __fastcall sub_7D4FA0(int a1, unsigned int a2)
{
  int v2; // r4

  MiUnmapViewOfSection(*(_DWORD *)(a1 + 1324), a2, 0);
  KiUnstackDetachProcess(v2 + 12, 0);
  JUMPOUT(0x6D75BA);
}
