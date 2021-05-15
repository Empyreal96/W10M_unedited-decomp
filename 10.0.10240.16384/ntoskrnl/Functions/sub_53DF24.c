// sub_53DF24 
 
void sub_53DF24()
{
  int v0; // r7
  _DWORD *v1; // r8
  int v2; // r9

  if ( (*v1 & 0x10) != 0
    && (*(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v2 + 92) + 36) * v0 + *(_DWORD *)(*(_DWORD *)(v2 + 92) + 252)) & 0xE00) != 3584 )
  {
    MiLogPageAccess(v2, v1);
  }
  JUMPOUT(0x4A56C8);
}
