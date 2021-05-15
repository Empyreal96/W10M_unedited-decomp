// PnpCopyDevProperty 
 
int __fastcall PnpCopyDevProperty(int a1, int a2, _DWORD *a3)
{
  int v7; // r1
  int v8; // r0

  memmove((int)a3, a1, 0x28u);
  a3[6] = 0;
  a3[9] = 0;
  if ( *(_DWORD *)(a1 + 24) )
    return sub_817128();
  v7 = a3[8];
  if ( v7 )
  {
    v8 = ExAllocatePoolWithTag(1, v7, a2);
    a3[9] = v8;
    if ( !v8 )
      JUMPOUT(0x817140);
  }
  memmove(a3[9], *(_DWORD *)(a1 + 36), a3[8]);
  return 0;
}
