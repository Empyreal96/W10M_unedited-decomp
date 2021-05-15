// sub_96B2E8 
 
int sub_96B2E8()
{
  int v0; // r2
  unsigned int v1; // r2
  int v2; // r3
  char v3; // r1
  unsigned int *v4; // r2
  unsigned int v5; // r0
  int v6; // r0
  unsigned __int8 *v8; // r4
  int v9; // r5
  int v10; // r6
  int v11; // r7
  int v12; // r9
  int v13; // r3
  unsigned int v14; // r2
  int (__fastcall *v15)(int); // [sp-4h] [bp-4h]

  do
  {
    do
    {
      __dmb(0xAu);
      __yield();
      v13 = *(_DWORD *)(v9 + 12);
      __dmb(0xBu);
    }
    while ( v13 < 0 );
    do
      v14 = __ldrex(v8);
    while ( __strex(v14 | 0x80, v8) );
    __dmb(0xBu);
  }
  while ( v14 >> 7 );
  v0 = *(_DWORD *)(v9 + 20);
  *(_DWORD *)(v9 + 8) = 128;
  v1 = v0 & 0xFFF00000 | 0xFFFFD;
  *(_WORD *)(v9 + 16) = 2;
  v2 = *(_DWORD *)(v9 + 12);
  *(_DWORD *)(v9 + 20) = v1;
  *(_DWORD *)(v9 + 12) = v2 & 0xC0000000 | 1;
  LOBYTE(v2) = *(_BYTE *)(v9 + 18);
  *(_DWORD *)v9 = v11;
  v3 = v2 & 0x3F | 0x40;
  *(_BYTE *)(v9 + 18) = v3;
  if ( v10 == 29 )
  {
    *(_DWORD *)(v9 + 4) = 0;
    *(_DWORD *)(v9 + 20) = v1 & 0xF8FFFFFF | 0x3000000;
  }
  else
  {
    *(_DWORD *)(v9 + 4) = -1073741824;
  }
  *(_BYTE *)(v9 + 18) = v3 & 0xF8 | 6;
  *(_DWORD *)(v9 + 20) = *(_DWORD *)(v9 + 20) & 0xFFFFFFF | (MiPageToNode() << 28);
  *(_DWORD *)(v9 + 12) |= 0x40000000u;
  __dmb(0xBu);
  v4 = (unsigned int *)(v9 + 12);
  do
    v5 = __ldrex(v4);
  while ( __strex(v5 & 0x7FFFFFFF, v4) );
  v6 = KfLowerIrql(v12);
  ++dword_634D94;
  return v15(v6);
}
