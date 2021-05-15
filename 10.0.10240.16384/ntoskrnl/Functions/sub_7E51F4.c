// sub_7E51F4 
 
void __fastcall sub_7E51F4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
  int v8; // r5
  int *v9; // r8
  int v10; // r9
  int v11; // r4

  v11 = ZwQuerySecurityObject();
  if ( v11 == v10 )
  {
    ExFreePoolWithTag(v8);
    v8 = ExAllocatePoolWithTag(1, a8, 1667526736);
    if ( !v8 )
      JUMPOUT(0x77D5A0);
    v11 = ZwQuerySecurityObject();
  }
  if ( v11 >= 0 )
  {
    *v9 = v8;
    JUMPOUT(0x77D592);
  }
  JUMPOUT(0x77D58A);
}
