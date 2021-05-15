// PspDeleteCreateProcessContext 
 
unsigned int __fastcall PspDeleteCreateProcessContext(int a1)
{
  int v2; // r0
  int v3; // r0
  int v4; // r0
  int v5; // r0
  int v6; // r0
  int v7; // r0
  int v8; // r0
  unsigned int v10; // r0
  unsigned int v11; // r0

  v2 = *(_DWORD *)(a1 + 100);
  if ( v2 )
    ObCloseHandle(v2);
  v3 = *(_DWORD *)(a1 + 104);
  if ( v3 )
    ObfDereferenceObject(v3);
  v4 = *(_DWORD *)(a1 + 92);
  if ( v4 )
    ObfDereferenceObject(v4);
  v5 = *(_DWORD *)(a1 + 80);
  if ( v5 )
    ObfDereferenceObjectWithTag(v5);
  v6 = *(_DWORD *)(a1 + 108);
  if ( v6 )
    ObCloseHandle(v6);
  v7 = *(_DWORD *)(a1 + 112);
  if ( v7 )
    ObCloseHandle(v7);
  v8 = *(_DWORD *)(a1 + 116);
  if ( v8 )
    ObfDereferenceObject(v8);
  if ( (*(_BYTE *)(a1 + 8) & 4) != 0 )
    ExFreePoolWithTag(*(_DWORD *)(a1 + 120));
  if ( *(_DWORD *)(a1 + 164) )
    return sub_8036B4();
  v10 = *(_DWORD *)(a1 + 176);
  if ( v10 )
    ExFreePoolWithTag(v10);
  v11 = *(_DWORD *)(a1 + 232);
  if ( v11 )
    ExFreePoolWithTag(v11);
  return RtlFreeAnsiString((_DWORD *)(a1 + 136));
}
