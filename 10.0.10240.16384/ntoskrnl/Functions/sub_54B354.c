// sub_54B354 
 
void sub_54B354()
{
  int v0; // r7
  _DWORD **v1; // r8
  _DWORD *v2; // r4
  _DWORD *v3; // r0

  v1 = *(_DWORD ***)(v0 + 20);
  v2 = *v1;
  while ( v2 != v1 )
  {
    v3 = v2;
    v2 = (_DWORD *)*v2;
    ExFreePoolWithTag(v3, 0);
  }
  JUMPOUT(0x4D2FDC);
}
