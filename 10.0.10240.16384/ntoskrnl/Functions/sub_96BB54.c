// sub_96BB54 
 
void sub_96BB54()
{
  int v0; // r6
  unsigned int v1; // r9
  _DWORD *v2; // r5
  int v3; // r2
  _DWORD *v4; // r0
  _DWORD *v5; // r5
  int v6; // r2
  _DWORD *v7; // r0

  while ( *(_DWORD *)(v0 + 52) )
  {
    v2 = *(_DWORD **)(v0 + 52);
    if ( v2 )
      *(_DWORD *)(v0 + 52) = *v2;
    v3 = *(v2 - 1);
    v4 = *(_DWORD **)(v3 + 28);
    if ( *(v4 - 1) == v0 )
    {
      if ( v4 )
        *(_DWORD *)(v3 + 28) = *v4;
      ExFreePoolWithTag((unsigned int)(v4 - 1));
    }
    ExFreePoolWithTag((unsigned int)(v2 - 1));
  }
  while ( *(_DWORD *)(v0 + 48) )
  {
    v5 = *(_DWORD **)(v0 + 48);
    if ( v5 )
      *(_DWORD *)(v0 + 48) = *v5;
    v6 = *(v5 - 1);
    v7 = *(_DWORD **)(v6 + 32);
    if ( *(v7 - 1) == v0 )
    {
      if ( v7 )
        *(_DWORD *)(v6 + 32) = *v7;
      ExFreePoolWithTag((unsigned int)(v7 - 1));
    }
    ExFreePoolWithTag((unsigned int)(v5 - 1));
  }
  if ( v1 )
    ExFreePoolWithTag(v1);
  JUMPOUT(0x957EAA);
}
