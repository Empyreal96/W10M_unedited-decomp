// PpmUpdateProcessorPolicyCallback 
 
int __fastcall PpmUpdateProcessorPolicyCallback(int a1, _DWORD *a2)
{
  int v2; // r5
  int v3; // r4
  int *v5; // r6
  void (__fastcall *v7)(_DWORD, int); // r2
  void (__fastcall *v8)(_DWORD, int); // r2
  void (__fastcall *v9)(_DWORD, int); // r2
  void (__fastcall *v10)(_DWORD, _DWORD); // r2
  void (__fastcall *v11)(_DWORD, int); // r2

  v2 = *(_DWORD *)(a1 + 3204);
  v3 = *(_DWORD *)(a1 + 3200);
  v5 = &PpmCurrentProfile[44 * dword_61EC0C];
  if ( *(_DWORD *)(v3 + 44) )
    return sub_554AFC();
  v7 = *(void (__fastcall **)(_DWORD, int))(v3 + 48);
  if ( v7 && (*a2 & 0x100) != 0 )
    v7(*(_DWORD *)(v2 + 4), v5[20]);
  v8 = *(void (__fastcall **)(_DWORD, int))(v3 + 52);
  if ( v8 && (*a2 & 0x40) != 0 )
    v8(*(_DWORD *)(v2 + 4), v5[22]);
  v9 = *(void (__fastcall **)(_DWORD, int))(v3 + 56);
  if ( v9 && (PpmAllowedActions & 0x400) != 0 )
    v9(*(_DWORD *)(v2 + 4), v5[23]);
  v10 = *(void (__fastcall **)(_DWORD, _DWORD))(v3 + 60);
  if ( v10 && (*a2 & 0x200) != 0 )
  {
    *(_BYTE *)(v3 + 116) = *((_BYTE *)v5 + 96);
    v10(*(_DWORD *)(v2 + 4), *((unsigned __int8 *)v5 + 96));
  }
  v11 = *(void (__fastcall **)(_DWORD, int))(v3 + 40);
  if ( v11 )
  {
    if ( (*a2 & 0x800) != 0 )
      v11(*(_DWORD *)(v2 + 4), PpmPerfTimeWindow);
  }
  return 0;
}
