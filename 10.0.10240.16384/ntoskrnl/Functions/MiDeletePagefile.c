// MiDeletePagefile 
 
unsigned int __fastcall MiDeletePagefile(unsigned int a1)
{
  unsigned int v1; // r4
  unsigned int v2; // r5
  int v3; // r6
  int v4; // r0
  unsigned int v5; // r0
  int v6; // r0
  int v7; // r0
  unsigned int v8; // r0

  v1 = a1;
  v2 = a1;
  v3 = 2;
  do
  {
    if ( *(_DWORD *)(v2 + 36) )
      return sub_7BF7BC();
    v2 += 4;
    --v3;
  }
  while ( v3 );
  v4 = *(_DWORD *)(a1 + 64);
  if ( v4 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v4);
  v5 = *(_DWORD *)(v1 + 108);
  if ( v5 )
    MiReleasePageHash(v5, *(_DWORD *)(v1 + 4));
  MiFreePageFileHashPfns(*(_DWORD *)(v1 + 128));
  if ( (*(_WORD *)(v1 + 96) & 0x100) != 0 )
    MiUpdatePageFileList(v1, 0);
  if ( (*(_WORD *)(v1 + 96) & 0x200) != 0 )
    PiPagePathSetState(*(_DWORD *)(v1 + 32), 0);
  v6 = *(_DWORD *)(v1 + 112);
  if ( v6 )
    ObCloseHandle(v6);
  v7 = *(_DWORD *)(v1 + 32);
  if ( v7 )
    ObfDereferenceObject(v7);
  v8 = *(_DWORD *)(v1 + 60);
  if ( v8 )
    ExFreePoolWithTag(v8);
  return ExFreePoolWithTag(v1);
}
