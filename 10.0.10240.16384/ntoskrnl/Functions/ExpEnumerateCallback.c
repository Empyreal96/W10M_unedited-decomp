// ExpEnumerateCallback 
 
int __fastcall ExpEnumerateCallback(int a1, int **a2)
{
  unsigned int *v4; // r4
  int v5; // r9
  unsigned int v6; // r2
  int **v7; // r3
  int *v8; // r1
  int *v9; // r2
  int v10; // r6
  int v11; // r2
  int v12; // r3
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = (unsigned int *)(a1 + 4);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented(a1 + 4);
  }
  else
  {
    do
      v6 = __ldrex(v4);
    while ( __strex(1u, v4) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire((unsigned int *)(a1 + 4));
  }
  v7 = (int **)*a2;
  if ( *a2 )
  {
    v8 = *a2;
  }
  else
  {
    v7 = (int **)(a1 + 8);
    v8 = 0;
  }
  v9 = *v7;
  v10 = 0;
  while ( v9 != (int *)(a1 + 8) )
  {
    if ( !*((_BYTE *)v9 + 24) )
    {
      v10 = v9[3];
      ++v9[5];
      *a2 = v9;
      break;
    }
    v9 = (int *)*v9;
  }
  if ( v8 )
  {
    v11 = v8[5] - 1;
    v12 = *((unsigned __int8 *)v8 + 24);
    v8[5] = v11;
    if ( v12 )
    {
      if ( !v11 )
        KeSetEvent((int)&ExpCallbackEvent, 0, 0);
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented((_DWORD *)(a1 + 4), vars4);
  }
  else
  {
    __dmb(0xBu);
    *v4 = 0;
  }
  KfLowerIrql(v5);
  return v10;
}
