// sub_816C54 
 
void __fastcall sub_816C54(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r4
  unsigned int v9; // [sp+20h] [bp-518h]

  if ( v8 == a3 || v8 == a4 )
  {
    if ( !ExAllocatePoolWithTag(1, a8, 1884513619) )
    {
      if ( a7 )
        ZwClose();
      if ( v9 )
        ExFreePoolWithTag(v9);
      JUMPOUT(0x7ADE1E);
    }
    if ( ZwQueryKey() < 0 )
      JUMPOUT(0x7ADE38);
    JUMPOUT(0x7ADE00);
  }
  JUMPOUT(0x7ADE16);
}
