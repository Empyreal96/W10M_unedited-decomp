// EtwpSetProviderTraitsKm 
 
int __fastcall EtwpSetProviderTraitsKm(int a1, int a2, unsigned int a3)
{
  int v6; // r0
  _DWORD *v7; // r4
  int v8; // r4
  int *v9; // r0
  unsigned int v11; // [sp+8h] [bp-30h] BYREF
  int v12[10]; // [sp+10h] [bp-28h] BYREF

  if ( (*(_BYTE *)(a1 + 50) & 8) != 0 )
    return -1073741811;
  if ( *(_DWORD *)(a1 + 56) )
    return -1073741823;
  v6 = ExAllocatePoolWithTag(512, a3 + 16, 1417114693);
  v7 = (_DWORD *)v6;
  if ( !v6 )
    return -1073741670;
  memmove(v6 + 16, a2, a3);
  v8 = EtwpSetProviderTraitsCommon(a1, v7, (unsigned int)&EtwpProviderTraitsKmMutex, EtwpProviderTraitsKmTree);
  if ( !*(_DWORD *)(a1 + 20) )
  {
    v9 = (int *)EtwpGetProviderGroupFromTraits((char *)(*(_DWORD *)(a1 + 56) + 16));
    if ( v9 )
    {
      v12[0] = *v9;
      v12[1] = v9[1];
      v12[2] = v9[2];
      v12[3] = v9[3];
      v8 = EtwpAddRegEntryToGroup(a1, (unsigned int)v12, 0, 0, &v11);
    }
  }
  if ( !v8 )
    *(_BYTE *)(a1 + 53) = 1;
  return v8;
}
