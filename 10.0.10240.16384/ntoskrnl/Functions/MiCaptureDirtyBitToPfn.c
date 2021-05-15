// MiCaptureDirtyBitToPfn 
 
unsigned int __fastcall MiCaptureDirtyBitToPfn(int a1)
{
  unsigned int v1; // r2
  int v3; // r3
  int v4; // r2

  v1 = 0;
  if ( (*(_BYTE *)(a1 + 18) & 0x10) != 0 )
    return 0;
  v3 = *(_DWORD *)(a1 + 8);
  if ( (v3 & 0x400) == 0 && (*(_BYTE *)(a1 + 18) & 8) == 0 )
  {
    v4 = *(_DWORD *)(a1 + 8);
    if ( (v3 & 0x10) != 0 )
    {
      *(_DWORD *)(a1 + 8) = v3 & 0xFFFFFFEF;
      v1 = v4 & 0xFFFFFFF7;
    }
    else
    {
      v1 = 0;
    }
  }
  *(_BYTE *)(a1 + 18) |= 0x10u;
  return v1;
}
