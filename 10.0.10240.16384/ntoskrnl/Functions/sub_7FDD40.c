// sub_7FDD40 
 
void sub_7FDD40(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r5
  int v6; // r0
  int v7; // r3
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  while ( 1 )
  {
    v6 = CmListGetNextElement(v5 + 108, (int *)va, 16);
    if ( !v6 )
      break;
    v7 = *(_DWORD *)(v6 + 36);
    if ( v7 == 2 || v7 == 11 )
    {
      if ( CmEqualTrans(*(_DWORD *)(v6 + 28), v4) )
        JUMPOUT(0x733C90);
      JUMPOUT(0x733C8A);
    }
  }
  JUMPOUT(0x733C8C);
}
