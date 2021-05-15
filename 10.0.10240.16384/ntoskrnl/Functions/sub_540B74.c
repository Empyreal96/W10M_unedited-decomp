// sub_540B74 
 
void sub_540B74()
{
  int v0; // r4
  int v1; // lr

  if ( (*(_DWORD *)(v0 + 72) & v1) != 0 && *(_QWORD *)(v0 + 80) == (*(_DWORD *)(v0 + 80) & v1) )
    JUMPOUT(0x4ADAC4);
  JUMPOUT(0x4ADAB8);
}
