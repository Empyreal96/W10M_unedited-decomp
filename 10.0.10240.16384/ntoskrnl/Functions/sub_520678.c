// sub_520678 
 
void sub_520678()
{
  int v0; // r4
  int v1; // r6

  if ( !*(_BYTE *)(v1 + 36) || !*(_BYTE *)(v0 + 14) )
  {
    if ( *(_BYTE *)(v1 + 33) )
      *(_BYTE *)(*(_DWORD *)(v1 + 96) + 3) |= 1u;
    ExFreePoolWithTag(v0, 0);
    JUMPOUT(0x4523E0);
  }
  JUMPOUT(0x452396);
}
