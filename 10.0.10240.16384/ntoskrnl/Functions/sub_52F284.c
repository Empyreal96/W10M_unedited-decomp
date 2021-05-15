// sub_52F284 
 
void sub_52F284(int a1, int a2, int a3, int a4, int a5, ...)
{
  int v5; // r4
  va_list va; // [sp+4h] [bp+4h] BYREF

  va_start(va, a5);
  if ( (a2 & *(_DWORD *)(a1 + 4)) == 0 )
  {
    if ( KiReduceByEffectiveIdleSmtSet(v5, (int *)va) )
      JUMPOUT(0x480B2A);
  }
  JUMPOUT(0x480B1E);
}
