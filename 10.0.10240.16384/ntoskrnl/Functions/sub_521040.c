// sub_521040 
 
void sub_521040()
{
  int v0; // r7
  int v1; // r8
  int v2; // r8
  __int64 v3; // kr00_8
  int v4; // r0

  ++*(_DWORD *)(v1 + 16);
  v2 = *(_DWORD *)(v0 + 2868);
  ++*(_DWORD *)(v2 + 12);
  if ( !RtlpInterlockedPopEntrySList((unsigned __int64 *)v2) )
  {
    v3 = *(_QWORD *)(v2 + 32);
    v4 = *(_DWORD *)(v2 + 28);
    ++*(_DWORD *)(v2 + 16);
    if ( !(*(int (__fastcall **)(int, _DWORD, _DWORD))(v2 + 40))(v4, HIDWORD(v3), v3) )
      JUMPOUT(0x4543EE);
  }
  JUMPOUT(0x4543E8);
}
