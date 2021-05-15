// sub_7D25C4 
 
void sub_7D25C4(int a1, int a2, int a3, int a4, ...)
{
  int v4; // r4
  int v5; // r6
  int v6; // r7
  int v7; // r0
  int v8; // r5
  int v9; // r3
  va_list va; // [sp+0h] [bp+0h] BYREF

  va_start(va, a4);
  if ( v6 )
  {
    while ( 1 )
    {
      v7 = CmListGetNextElement(v6 + 108, (int *)va, 16);
      v8 = v7;
      if ( !v7 )
        break;
      if ( CmEqualTrans(*(_DWORD *)(v7 + 28), v5) )
      {
        v9 = *(_DWORD *)(v8 + 36);
        if ( v9 == 1 )
        {
          ++v4;
        }
        else if ( v9 == 3 )
        {
          --v4;
        }
      }
    }
  }
  JUMPOUT(0x6D1768);
}
