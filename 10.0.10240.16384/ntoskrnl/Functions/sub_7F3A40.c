// sub_7F3A40 
 
void sub_7F3A40()
{
  int v0; // r4
  int v1; // r7
  int v2; // r9
  int v3; // [sp+0h] [bp-A8h]
  int v4; // [sp+14h] [bp-94h]

  SetFailureLocation(v1, 0, 6, -1073741670, v3);
  *(_BYTE *)(v0 + 72) &= 0xFBu;
  HvViewMapCleanup(v0 + 152, v0, 1);
  if ( v4 )
    (*(void (__fastcall **)(int, _DWORD))(v0 + 16))(v4, *(_DWORD *)(v0 + 64));
  *(_DWORD *)(v0 + 32) = v2;
  *(_DWORD *)(v0 + 44) = v2;
  JUMPOUT(0x70EE56);
}
