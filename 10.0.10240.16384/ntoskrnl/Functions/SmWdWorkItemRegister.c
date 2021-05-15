// SmWdWorkItemRegister 
 
unsigned int __fastcall SmWdWorkItemRegister(int a1, int a2, int a3, __int16 a4)
{
  unsigned int *v5; // r5
  unsigned int v7; // r2
  unsigned int v8; // r2
  unsigned int result; // r0
  unsigned int *v10; // r4
  int v11; // r5
  unsigned int v12; // r2
  unsigned int v13; // [sp+0h] [bp-20h]
  int v14; // [sp+0h] [bp-20h]
  int vars4; // [sp+24h] [bp+4h]

  v5 = (unsigned int *)(a3 + 4);
  if ( *(_BYTE *)(a3 + 5) )
  {
    v7 = *v5;
    __dmb(0xBu);
    v13 = v7;
    do
    {
      v8 = v13;
      __dmb(0xBu);
      v14 = ((unsigned __int16)((v13 & 0xFF00) + (a4 << 8)) ^ (unsigned __int16)v13) & 0xFF00 ^ v13;
      __dmb(0xBu);
      __dmb(0xBu);
      do
        result = __ldrex(v5);
      while ( result == v8 && __strex(v14, v5) );
      __dmb(0xBu);
      v13 = result;
      __dmb(0xBu);
      __dmb(0xBu);
    }
    while ( result != v8 );
  }
  else
  {
    v10 = (unsigned int *)(a1 + 88);
    *v5 ^= (*v5 ^ (a2 << 19)) & 0xF80000;
    *(_BYTE *)(a3 + 5) = a4 + 1;
    v11 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented(a1 + 88);
    }
    else
    {
      do
        v12 = __ldrex(v10);
      while ( __strex(1u, v10) );
      __dmb(0xBu);
      if ( v12 )
        KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 88));
    }
    *(_DWORD *)a3 = *(_DWORD *)a3 & 7 | (8 * ((**(_DWORD **)(a1 + 84) >> 3) + 1));
    **(_DWORD **)(a1 + 84) = **(_DWORD **)(a1 + 84) & 7 | a3;
    *(_DWORD *)(a1 + 84) = a3;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 88), vars4);
    }
    else
    {
      __dmb(0xBu);
      *v10 = 0;
    }
    result = KfLowerIrql(v11);
  }
  return result;
}
