// sub_819CF4 
 
void sub_819CF4()
{
  int v0; // r5
  int v1; // r6
  int v2; // r4
  int v3; // r0
  int v4; // r3

  if ( *(_QWORD *)(v0 + 88) )
  {
    v2 = ExAllocatePoolWithTag(1, 36, 1885957463);
    if ( !v2 )
      JUMPOUT(0x7B651C);
    v3 = *(_DWORD *)(v1 + 32);
    *(_DWORD *)(v1 + 8) |= 0x200000u;
    WmipReferenceEntry(v3);
    *(_DWORD *)(v2 + 24) = 1;
    *(_DWORD *)(v2 + 8) = 2;
    *(_DWORD *)(v2 + 32) = *(_DWORD *)(v1 + 32);
    *(_DWORD *)(v2 + 16) = *(_DWORD *)(v0 + 88);
    v4 = *(_DWORD *)(v0 + 92);
    *(_BYTE *)(v2 + 28) = 1;
    *(_DWORD *)(v2 + 20) = v4;
  }
  JUMPOUT(0x7B6508);
}
