// sub_524580 
 
void __fastcall sub_524580(int a1, int a2, int a3, int a4, unsigned __int8 a5, int a6, int a7, int a8, int a9, int a10)
{
  int v10; // r4
  char v11; // r5
  _DWORD *v12; // r3

  KiAcquireProcessLockExclusive(v10, &a5);
  v12 = *(_DWORD **)(v10 + 40);
  *(_BYTE *)(v10 + 105) = v11;
  while ( v12 != (_DWORD *)(v10 + 40) )
  {
    *((_BYTE *)v12 - 65) = v11;
    v12 = (_DWORD *)*v12;
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    ExpReleaseSpinLockExclusiveFromDpcLevelInstrumented((_DWORD *)(v10 + 48), a10);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)(v10 + 48) = 0;
  }
  KfLowerIrql(a5);
  JUMPOUT(0x45CEDC);
}
