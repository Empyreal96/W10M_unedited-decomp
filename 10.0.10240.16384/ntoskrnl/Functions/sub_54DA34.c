// sub_54DA34 
 
void sub_54DA34(int a1, int a2, int a3, int a4, int a5, ...)
{
  int v5; // r5
  int v6; // r7
  va_list va; // [sp+4h] [bp+4h] BYREF

  va_start(va, a5);
  if ( FioFwReadBytesAtOffset(*(_DWORD **)(*(_DWORD *)(v5 + 8) + 8), *(_DWORD *)(v5 + 48) + 4 * (v6 - 1), 4u, (int)va) < 0 )
    JUMPOUT(0x4E2F3A);
  JUMPOUT(0x4E2ED6);
}
