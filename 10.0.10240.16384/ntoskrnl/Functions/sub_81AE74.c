// sub_81AE74 
 
void sub_81AE74()
{
  int v0; // r5
  unsigned int v1; // r6
  __int64 v2; // r0

  if ( !*(_BYTE *)(v0 + 4) )
  {
    if ( *(_DWORD *)(v1 + 12) != *(_DWORD *)(v0 + 12) )
      JUMPOUT(0x7B8F46);
    v2 = *(_QWORD *)(v1 + 16);
    if ( *(_DWORD *)(v2 + 4) != v1 + 16 || *(_DWORD *)HIDWORD(v2) != v1 + 16 )
      __fastfail(3u);
    *(_DWORD *)HIDWORD(v2) = v2;
    *(_DWORD *)(v2 + 4) = HIDWORD(v2);
    ObfDereferenceObject(*(_DWORD *)(v1 + 12));
    ExFreePoolWithTag(v1);
  }
  JUMPOUT(0x7B8F10);
}
