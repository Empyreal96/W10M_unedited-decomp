// sub_7F3D9C 
 
void sub_7F3D9C()
{
  int v0; // r4
  int v1; // r6
  _BYTE *v2; // r0
  int v3; // r5

  v2 = (_BYTE *)ExAllocatePoolWithTag(1, v0, 1867074883);
  v3 = (int)v2;
  if ( v2 )
  {
    memset(v2, 0, v0);
    memmove(v3, *(_DWORD *)(v1 + 32), 0x200u);
    JUMPOUT(0x70F0F2);
  }
  JUMPOUT(0x70F146);
}
