// AlpcpViewSearchCallbackFunction 
 
int __fastcall AlpcpViewSearchCallbackFunction(int a1, _DWORD *a2)
{
  int v3; // r6
  unsigned int *v4; // r7
  int v5; // r5
  unsigned int v6; // r4

  if ( *(_DWORD *)(a1 + 20) != *a2 )
    return 0;
  v3 = *(_DWORD *)(a1 - 12);
  if ( v3 <= 0 )
    JUMPOUT(0x7F5D78);
  v4 = (unsigned int *)(a1 - 12);
  v5 = *(_DWORD *)(a1 - 12);
  __dmb(0xBu);
  do
    v6 = __ldrex(v4);
  while ( v6 == v3 && __strex(v3 + 1, v4) );
  __dmb(0xBu);
  if ( v6 != v5 )
    return sub_7F5D70();
  if ( v6 == -1 )
    return -1073741267;
  a2[1] = a1;
  return -1073741823;
}
