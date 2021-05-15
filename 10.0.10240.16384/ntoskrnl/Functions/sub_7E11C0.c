// sub_7E11C0 
 
void __fastcall sub_7E11C0(int a1, int a2, int a3)
{
  _DWORD *v3; // r4
  unsigned __int8 *v4; // r5
  int v5; // r3
  int v6; // r7
  unsigned int v7; // r2

  v5 = v3[1];
  v3[6] = a3;
  if ( (v5 & a2) == 0 )
  {
    v3[7] = a3;
    v3[8] = a3;
    v6 = KeAbPreAcquire((unsigned int)v4, 0, 0);
    KfRaiseIrql(1);
    do
      v7 = __ldrex(v4);
    while ( __strex(v7 & 0xFE, v4) );
    __dmb(0xBu);
    if ( (v7 & 1) == 0 )
      ExpAcquireFastMutexContended((int)v4, v6);
    if ( v6 )
      *(_BYTE *)(v6 + 14) |= 1u;
    JUMPOUT(0x778764);
  }
  JUMPOUT(0x7787C4);
}
