// ViCheckAdapterBuffers 
 
int __fastcall ViCheckAdapterBuffers(int result)
{
  int v1; // r6
  __int16 v2; // r7
  int v3; // r5
  unsigned int *v4; // r4
  int v5; // r9
  unsigned int v6; // r2
  int i; // r3
  unsigned int v8; // r2
  int v9; // r5
  int vars4; // [sp+1Ch] [bp+4h]

  v1 = result + 44;
  v2 = 0;
  v3 = result;
  if ( *(_DWORD *)(result + 44) != result + 44 )
  {
    v4 = (unsigned int *)(result + 52);
    v5 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v4);
    }
    else
    {
      do
        v6 = __ldrex(v4);
      while ( __strex(1u, v4) );
      __dmb(0xBu);
      if ( v6 )
        KxWaitForSpinLockAndAcquire(v4);
    }
    for ( i = *(_DWORD *)(v3 + 44); ; i = *(_DWORD *)(v9 + 36) )
    {
      v9 = i - 36;
      if ( v1 == i )
        break;
      v8 = *(_DWORD *)(i - 20) - *(_DWORD *)(i - 24);
      if ( v8 >= 8 )
        v2 |= 1u;
      if ( *(_DWORD *)(i - 28) + v8 + 8 <= *(_DWORD *)(i - 32) )
        v2 |= 2u;
      ViCheckTag();
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v4, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v4 = 0;
    }
    result = KfLowerIrql(v5);
  }
  return result;
}
