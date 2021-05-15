// sub_7CE728 
 
void __fastcall sub_7CE728(int a1, __int16 a2)
{
  int v2; // r7
  int *v3; // r8
  unsigned int *v4; // r9
  int v5; // r10
  unsigned int v6; // r2
  unsigned int v7; // r2
  int v8; // r3
  int v9; // r3

  __dmb(0xBu);
  do
  {
    v6 = __ldrex(v4);
    v7 = v6 + 1;
  }
  while ( __strex(v7, v4) );
  __dmb(0xBu);
  v8 = v2 + 8 * (v7 & 0x3F);
  *(_DWORD *)(v8 + 4) = v5;
  *(_WORD *)(v8 + 2) = a2;
  v9 = *v3;
  *(_WORD *)(v2 + 8 * (v7 & 0x3F)) = 800;
  if ( (v9 & 4) != 0 )
    RtlAssert((int)"TargetString != NULL", (int)"minkernel\\ntos\\kshim\\ksemisc.c", 800, 0);
  JUMPOUT(0x787D7E);
}
