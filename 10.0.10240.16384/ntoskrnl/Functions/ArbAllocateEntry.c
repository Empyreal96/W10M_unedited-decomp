// ArbAllocateEntry 
 
int __fastcall ArbAllocateEntry(int a1, unsigned int a2)
{
  unsigned int v2; // r5
  unsigned int v4; // r4
  __int64 v5; // r0
  int v6; // r6
  int v7; // r3
  unsigned int v8; // r4
  __int64 v9; // r2
  __int16 v11; // r2
  int v12; // [sp+4h] [bp-2Ch]
  int v13; // [sp+8h] [bp-28h]
  char *v14; // [sp+Ch] [bp-24h]

  v2 = a2;
  v4 = a2;
  LODWORD(v5) = KeQueryInterruptTime();
  v14 = (char *)dword_989680 + v5;
  v13 = ((unsigned __int64)(unsigned int)dword_989680 + v5) >> 32;
  while ( v4 >= v2 && *(_DWORD *)(v4 + 32) )
  {
    v6 = (*(int (__fastcall **)(int, unsigned int))(a1 + 112))(a1, v4);
    if ( v6 < 0 )
      return v6;
    do
    {
      if ( !(*(int (__fastcall **)(int, unsigned int))(a1 + 120))(a1, v4) )
        JUMPOUT(0x80E416);
    }
    while ( !(*(int (__fastcall **)(int, unsigned int))(a1 + 124))(a1, v4) );
    if ( !*(_QWORD *)(*(_DWORD *)(v4 + 36) + 16) )
      JUMPOUT(0x80E40C);
    (*(void (__fastcall **)(int, unsigned int))(a1 + 128))(a1, v4);
    v4 += 56;
  }
  v7 = *(_DWORD *)(v2 + 32);
  v8 = v2;
  while ( v7 )
  {
    (*(void (__fastcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, int, int, char *))(a1 + 64))(
      *(_DWORD *)(*(_DWORD *)(v8 + 36) + 40),
      *(_DWORD *)(a1 + 64),
      *(_DWORD *)v8,
      *(_DWORD *)(v8 + 4),
      *(_DWORD *)(v7 + 44),
      v12,
      v13,
      v14);
    v9 = *(_QWORD *)(v8 + 32);
    v8 += 56;
    *(_DWORD *)(v9 + 48) = *(_DWORD *)(HIDWORD(v9) + 40);
    v7 = *(_DWORD *)(v8 + 32);
  }
  v6 = 0;
  while ( *(_DWORD *)(v2 + 32) )
  {
    if ( (*(_WORD *)(v2 + 48) & 0x10) != 0 )
    {
      ExFreePoolWithTag(*(_DWORD *)(v2 + 52));
      v11 = *(_WORD *)(v2 + 48);
      *(_DWORD *)(v2 + 52) = 0;
      *(_WORD *)(v2 + 48) = v11 & 0xFFEF;
    }
    v2 += 56;
  }
  return v6;
}
