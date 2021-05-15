// sub_96E534 
 
void sub_96E534()
{
  int v0; // r4
  _DWORD *v1; // r6
  int v2; // r8
  int v3; // r0
  int v4; // r3
  _DWORD *v5; // r2

  v3 = ExAllocatePoolWithTag(512, *(_DWORD *)(v2 + 16), 1682989378);
  if ( v3 )
  {
    v4 = *(_DWORD *)(v2 + 16);
    v1[2] = v3;
    v1[4] = v4;
    memmove(v3, *(_DWORD *)(v2 + 8), *(_DWORD *)(v2 + 16));
    v5 = *(_DWORD **)(v0 + 4);
    *v1 = v0;
    v1[1] = v5;
    if ( *v5 == v0 )
    {
      *v5 = v1;
      *(_DWORD *)(v0 + 4) = v1;
      JUMPOUT(0x960738);
    }
    __fastfail(3u);
  }
  ExFreePoolWithTag((unsigned int)v1);
  JUMPOUT(0x96075C);
}
