// sub_554FBC 
 
void sub_554FBC()
{
  int v0; // r4
  int v1; // r5
  unsigned int v2; // r0
  int v3; // r2
  unsigned int v4; // r3
  int v5; // r3

  v1 = 0;
  v2 = KfRaiseIrql(2);
  v3 = *(_DWORD *)(v0 + 68);
  v4 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( v3 )
  {
    v5 = *(_DWORD *)(v4 + 3760) + v3;
    if ( v5 )
      v1 = (*(unsigned __int8 *)(v5 + 92) >> 3) & 1;
  }
  if ( v2 < 2 )
    KfLowerIrql(v2);
  if ( !v1 )
    JUMPOUT(0x4F755A);
  JUMPOUT(0x4F755E);
}
