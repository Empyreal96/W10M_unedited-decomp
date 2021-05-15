// sub_81A674 
 
void sub_81A674()
{
  int v0; // r5
  int v1; // r9
  int v2; // lr
  int v3; // r2

  v3 = *(_DWORD *)(v1 + 12);
  if ( v3 != v0 && v3 != -2147483136 && v3 != v2 && v3 != 0x80000000 && v3 != -2147483646 )
    JUMPOUT(0x7B7AA4);
  JUMPOUT(0x7B7B42);
}
