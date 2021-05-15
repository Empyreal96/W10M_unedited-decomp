// sub_517030 
 
void sub_517030()
{
  int v0; // r4
  int v1; // r7
  unsigned int v2; // r10
  unsigned int v3; // lr
  __int64 v4; // r0
  unsigned int v5; // r6
  unsigned int v6; // lr
  unsigned __int64 v7; // kr00_8
  bool v8; // cf
  unsigned int v9; // r0

  __dmb(0xFu);
  if ( v3 > v2 )
    goto LABEL_8;
  do
  {
    v4 = MEMORY[0xFFFF93B0];
    while ( 1 )
    {
      v5 = MEMORY[0xFFFF900C];
      __dmb(0xBu);
      v6 = MEMORY[0xFFFF9008];
      __dmb(0xBu);
      if ( v5 == MEMORY[0xFFFF9010] )
        break;
      __dmb(0xAu);
      __yield();
    }
  }
  while ( v4 != MEMORY[0xFFFF93B0] );
  v7 = __PAIR64__(v5, v6) - *(_QWORD *)(v0 + 32);
  v8 = (unsigned int)v7 >= (unsigned int)v4;
  LODWORD(v4) = v7 - v4;
  if ( HIDWORD(v7) != HIDWORD(v4) + !v8 || v9 >= 0x47868C00 )
  {
LABEL_8:
    *(_WORD *)(v0 + 44) &= 0xFFFEu;
    MiUpdateReserveClusterInfo(v1, 0);
  }
  JUMPOUT(0x436636);
}
