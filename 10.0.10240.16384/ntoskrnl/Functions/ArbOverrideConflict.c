// ArbOverrideConflict 
 
int __fastcall ArbOverrideConflict(int a1, int a2)
{
  int v3; // r5
  int v4; // r1
  unsigned __int64 v5; // kr00_8
  unsigned __int64 v6; // kr08_8
  int v7; // r3
  int v9[2]; // [sp+0h] [bp-30h] BYREF
  _DWORD v10[10]; // [sp+8h] [bp-28h] BYREF

  v3 = 0;
  if ( (*(_DWORD *)(*(_DWORD *)(a2 + 36) + 36) & 2) == 0 )
    return 0;
  RtlGetFirstRange(*(_DWORD **)(a1 + 24), v10, v9);
  v4 = v9[0];
  if ( v9[0] )
  {
    v5 = *(_QWORD *)(a2 + 16);
    do
    {
      v6 = *(_QWORD *)v4;
      if ( (*(_QWORD *)v4 >= v5 || *(_QWORD *)(v4 + 8) >= v5)
        && (v5 >= v6 || *(_QWORD *)(a2 + 24) >= v6)
        && (*(_BYTE *)(v4 + 24) & *(_BYTE *)(a2 + 51)) == 0 )
      {
        if ( *(_DWORD *)(v4 + 20) != *(_DWORD *)(*(_DWORD *)(a2 + 32) + 16)
          || (*(_DWORD *)(*(_DWORD *)(a2 + 36) + 36) & 2) == 0 )
        {
          return 0;
        }
        v7 = *(_DWORD *)(a2 + 24);
        *(_QWORD *)a2 = v5;
        v3 = 1;
        *(_DWORD *)(a2 + 8) = v7;
        *(_DWORD *)(a2 + 12) = *(_DWORD *)(a2 + 28);
      }
      RtlGetNextRange(v10, v9, 1);
      v4 = v9[0];
    }
    while ( v9[0] );
  }
  return v3;
}
