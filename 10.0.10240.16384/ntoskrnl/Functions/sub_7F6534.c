// sub_7F6534 
 
void sub_7F6534(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KiStackAttachProcess(a1, 0, (int)va);
  SmpKeyedStoreCreate(v4 + 5956, v4, *(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74));
  KiUnstackDetachProcess((unsigned int)va, 0);
  JUMPOUT(0x7197E8);
}
