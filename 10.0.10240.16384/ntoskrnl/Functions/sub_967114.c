// sub_967114 
 
void __fastcall sub_967114(_BYTE *a1)
{
  int v1; // r6
  int v2; // r7
  _BYTE *v3; // r0
  unsigned int v4; // r1

  v3 = strstr(a1, "=");
  if ( v3 )
  {
    v4 = atol((int)(v3 + 1)) << 8;
    if ( *(_DWORD *)(*(_DWORD *)(v2 + 132) + 2288) )
    {
      *(_DWORD *)(v1 + 176) = v4;
    }
    else if ( v4 )
    {
      *(_DWORD *)(v1 + 176) = ExBurnMemory(v2, v4, 23);
    }
  }
  JUMPOUT(0x94DAD4);
}
