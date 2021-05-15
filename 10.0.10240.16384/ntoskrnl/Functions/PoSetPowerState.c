// PoSetPowerState 
 
int __fastcall PoSetPowerState(int a1, int a2, int a3, int a4)
{
  int v4; // r5
  int v6; // r4
  int v7; // r9
  unsigned int v9; // r2
  int v10; // r2
  unsigned int v11; // r2
  int v12; // r3
  unsigned int v13; // r2
  int varg_r1; // [sp+24h] [bp+Ch]

  varg_r1 = a2;
  v4 = *(_DWORD *)(a1 + 176);
  v6 = 0;
  v7 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_52046C();
  do
    v9 = __ldrex((unsigned int *)&PopIrpSerialLock);
  while ( __strex(1u, (unsigned int *)&PopIrpSerialLock) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(&PopIrpSerialLock);
  if ( !a2 )
  {
    v6 = *(_DWORD *)(v4 + 8) & 0xF;
    if ( v6 == a3 )
      goto LABEL_11;
    v13 = *(_DWORD *)(v4 + 8) & 0xFFFFFFF0;
    *(_DWORD *)(v4 + 8) = v13;
    v12 = a3 & 0xF | v13;
    goto LABEL_10;
  }
  if ( a2 == 1 )
  {
    v10 = *(_DWORD *)(v4 + 8);
    v6 = (unsigned __int8)v10 >> 4;
    if ( v6 != a3 )
    {
      v11 = v10 & 0xFFFFFF0F;
      *(_DWORD *)(v4 + 8) = v11;
      v12 = v11 | (16 * (a3 & 0xF));
LABEL_10:
      *(_DWORD *)(v4 + 8) = v12;
      goto LABEL_11;
    }
  }
LABEL_11:
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(&PopIrpSerialLock);
  }
  else
  {
    __dmb(0xBu);
    PopIrpSerialLock = 0;
  }
  KfLowerIrql(v7);
  return v6;
}
