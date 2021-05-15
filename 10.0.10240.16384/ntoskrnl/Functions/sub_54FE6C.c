// sub_54FE6C 
 
void sub_54FE6C()
{
  unsigned int v0; // r5
  unsigned int *v1; // r6
  int v2; // r7
  char v3; // r8
  unsigned int v4; // r2
  unsigned int v5; // r3
  int v6; // r4
  unsigned int *v7; // r2
  unsigned int v8; // r4
  char v9[16]; // [sp+0h] [bp+0h]

  v4 = __clz(__rbit(v0));
  v9[0] = v4;
  if ( v4 >= *v1 )
    v5 = 0;
  else
    v5 = v1[v4 + 13];
  v6 = *(_DWORD *)(v5 + 2944);
  PpmIdleUnlockProcessor((_DWORD *)(v5 + 3000));
  __dmb(0xBu);
  v7 = (unsigned int *)(v6 + 64);
  do
    v8 = __ldrex(v7);
  while ( __strex(v8 & ~(1 << v3), v7) );
  __dmb(0xBu);
  *(_DWORD *)(v2 + 8) &= ~(1 << v9[0]);
  JUMPOUT(0x4EB220);
}
