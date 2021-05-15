// sub_80A3CC 
 
void __fastcall sub_80A3CC(_DWORD *a1)
{
  int *v1; // r4
  int v2; // r2
  _DWORD *v3; // r1
  int v4; // r2
  unsigned int *v5; // r2
  unsigned int v6; // r1
  _DWORD *v7; // r2
  _DWORD *v8; // r3
  int v9; // r0

  v2 = (a1[240] >> 9) & 7;
  if ( (*(_DWORD *)(a1[84] + 192) & 0x100000) != 0 )
    v2 = 0;
  if ( v2 < 2 )
  {
    if ( a1 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && a1[250] )
      v2 = 2;
    if ( v2 < 2 )
    {
      v3 = (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0);
      v4 = (v3[240] >> 9) & 7;
      if ( (*(_DWORD *)(v3[84] + 192) & 0x100000) != 0 )
        v4 = 0;
      if ( v4 >= 2 )
        goto LABEL_15;
      if ( v3 == (_DWORD *)(__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) && v3[250] )
        v4 = 2;
      if ( v4 >= 2 )
      {
LABEL_15:
        v5 = (unsigned int *)(v1 + 2);
        do
          v6 = __ldrex(v5);
        while ( !v6 && __strex(1u, v5) );
        if ( !v6 )
        {
          PsBoostThreadIo(*v1, 0);
          IoBoostThreadIoPriority(*v1, 2, 0);
          v9 = KeSetPriorityBoost(*v1, 12, v7, v8);
          CmpTraceHiveFlushBoostedActiveFlusher(v9);
        }
      }
    }
  }
  JUMPOUT(0x75FB2A);
}
