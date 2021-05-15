// sub_8061E8 
 
void sub_8061E8()
{
  int v0; // r8
  int v1; // r4
  unsigned int v2; // r6

  v1 = *(_DWORD *)(v0 + 288);
  __dmb(0xBu);
  if ( v1 )
  {
    v2 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    __dmb(0xBu);
    __dmb(0xBu);
    __dmb(0xBu);
    if ( v2 )
      --*(_WORD *)(v2 + 310);
    JUMPOUT(0x7533C8);
  }
  JUMPOUT(0x7533C4);
}
