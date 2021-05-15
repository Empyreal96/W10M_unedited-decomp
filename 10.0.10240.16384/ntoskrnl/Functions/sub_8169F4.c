// sub_8169F4 
 
void __fastcall sub_8169F4(int a1, int a2, int a3, int a4, int a5, int a6, unsigned int a7)
{
  unsigned int *v7; // r7
  int *v8; // r8
  int v9; // r0
  int v10; // r6
  int v11; // r0
  unsigned int v12; // [sp+8h] [bp+8h]

  v9 = ZwQueryValueKey();
  if ( (v9 >= 0 || v9 == -1073741789) && a7 <= 0x1000B )
  {
    if ( a7 > 0xC )
    {
      v10 = ExAllocatePoolWithTag(1, a7, 1818448711);
      if ( !v10 )
        JUMPOUT(0x7AD9E2);
      if ( ZwQueryValueKey() >= 0 )
      {
        v12 = a7 - 12;
        v11 = ExAllocatePoolWithTag(1, v12, 1818448711);
        *v8 = v11;
        if ( v11 )
        {
          memmove(v11, v10 + 12, v12);
          *v7 = v12;
        }
      }
      ExFreePoolWithTag(v10);
    }
    else
    {
      *v7 = 0;
      *v8 = 0;
    }
  }
  JUMPOUT(0x7AD9C8);
}
