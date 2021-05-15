// sub_50DC10 
 
void sub_50DC10()
{
  int v0; // r4
  int v1; // r5
  int v2; // r8
  unsigned int v3; // lr
  void **v4; // r2
  int v5; // r1
  int v6; // r0
  int v7; // t1
  int v8; // [sp+18h] [bp+18h]

  __mcr(15, 0, 0, 8, 3, 1);
  __dsb(0xFu);
  v2 = KfRaiseIrql(12);
  v3 = (unsigned int)KeGetPcr() & 0xFFFFF000;
  if ( v1 )
    v8 = *(_DWORD *)(v0 + 8);
  else
    v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(v3 + 1412) + 116) + 96);
  v4 = &KeNodeBlock;
  if ( !KeNodeBlock )
    goto LABEL_8;
  v5 = (unsigned __int16)KeNumberNodes;
  v6 = 0;
  if ( KeNumberNodes )
  {
    do
    {
      v7 = (int)*v4++;
      v6 |= *(_DWORD *)(v7 + 128);
      --v5;
    }
    while ( v5 );
  }
  if ( (v8 & ~v6) != 0 )
  {
LABEL_8:
    KiIpiSendRequestEx(v3 + 1408);
    KfLowerIrql(v2);
  }
  JUMPOUT(0x49BCDE);
}
