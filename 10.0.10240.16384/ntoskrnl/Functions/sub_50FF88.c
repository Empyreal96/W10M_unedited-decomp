// sub_50FF88 
 
void sub_50FF88(int a1, int a2, unsigned int a3, int a4, int a5, int a6, ...)
{
  int v6; // r4
  int v7; // r7
  int v8; // lr
  va_list va; // [sp+8h] [bp+8h] BYREF

  va_start(va, a6);
  if ( v8 + v7 > a3 )
  {
    ++*(_DWORD *)(v6 + 10208);
    KeReleaseInStackQueuedSpinLock((int)va);
    MiReclaimSystemVa(1);
    JUMPOUT(0x426784);
  }
  JUMPOUT(0x42662E);
}
