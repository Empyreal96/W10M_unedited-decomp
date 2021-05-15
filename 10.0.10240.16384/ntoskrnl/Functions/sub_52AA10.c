// sub_52AA10 
 
void __fastcall sub_52AA10(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r8
  _BYTE *v11; // r0
  _BYTE *v12; // r7

  v11 = (_BYTE *)ExAllocatePoolWithTag(1, a10, 538994003);
  v12 = v11;
  if ( v11 && RtlCreateSecurityDescriptor(v11, 1) >= 0 )
  {
    ObQuerySecurityObject(v10, 16, v12, a10);
    JUMPOUT(0x46A99A);
  }
  JUMPOUT(0x46A9D8);
}
