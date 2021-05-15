// sub_80A2BC 
 
void sub_80A2BC()
{
  int v0; // r5
  int v1; // r6
  unsigned int v2; // r8
  int v3; // r9
  int v4; // r10
  int v5; // r4
  _BYTE *v6; // r0
  _DWORD *v7; // r7
  int v8; // r7

  if ( !v0 )
  {
    v5 = v1 + v3 * v4;
    if ( *(_DWORD *)(v5 + 956) == v5 + 960 )
    {
      v6 = (_BYTE *)(*(int (__fastcall **)(int, _DWORD, int))(v1 + 12))(4096, 0, 942755139);
      v7 = v6;
      if ( !v6 )
        JUMPOUT(0x75FA38);
      memset(v6, 0, 4096);
      *v7 = *(_DWORD *)(v5 + 960);
      __dmb(0xBu);
      *(_DWORD *)(v5 + 956) = v7;
    }
  }
  v8 = v1 + v3 * v4;
  if ( !HvpAllocateMap(v1, *(_DWORD *)(v8 + 956), v0 + 1, v2) )
  {
    HvpFreeMap(v1, *(_DWORD *)(v8 + 956), v0 + 1, v2);
    JUMPOUT(0x75FA04);
  }
  JUMPOUT(0x75FA02);
}
