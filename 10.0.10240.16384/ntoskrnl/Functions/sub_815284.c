// sub_815284 
 
void __fastcall sub_815284(int a1, _DWORD *a2)
{
  unsigned int v2; // r5
  int v3; // [sp+0h] [bp-68h]
  unsigned int v4; // [sp+28h] [bp-40h]

  if ( *(_DWORD *)(v2 + 8) != *a2 )
  {
    ExFreePoolWithTag(v2);
    if ( v3 + 1 < v4 )
      JUMPOUT(0x7AA390);
    JUMPOUT(0x7AA400);
  }
  JUMPOUT(0x7AA3BE);
}
