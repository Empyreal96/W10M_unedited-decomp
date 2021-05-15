// sub_7C5938 
 
void sub_7C5938(int a1, int a2, int a3, int a4, ...)
{
  _DWORD *v4; // r5
  int v5; // r7
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( !RtlGetNextEntryHashTable(v5, (int)va) )
  {
    *v4 = 0;
    JUMPOUT(0x6C3FCE);
  }
  JUMPOUT(0x6C3FB8);
}
