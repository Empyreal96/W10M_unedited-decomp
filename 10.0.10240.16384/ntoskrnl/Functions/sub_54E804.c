// sub_54E804 
 
void sub_54E804(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  KeAcquireInStackQueuedSpinLock((unsigned int *)(v4 + 3224), (unsigned int)va);
  JUMPOUT(0x4E6F64);
}
