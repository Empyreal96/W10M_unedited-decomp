// VF_FIND_BUFFER 
 
unsigned __int16 *__fastcall VF_FIND_BUFFER(_DWORD **a1, int a2)
{
  unsigned int *v3; // r4
  int v5; // r9
  unsigned int v6; // r2
  _DWORD *i; // r3
  unsigned __int16 *v8; // r5
  int vars4; // [sp+1Ch] [bp+4h]

  v3 = (unsigned int *)(a1 + 2);
  v5 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)v3);
  }
  else
  {
    do
      v6 = __ldrex(v3);
    while ( __strex(1u, v3) );
    __dmb(0xBu);
    if ( v6 )
      KxWaitForSpinLockAndAcquire(v3);
  }
  for ( i = *a1; ; i = (_DWORD *)*i )
  {
    v8 = (unsigned __int16 *)(i - 9);
    if ( a1 == i )
      break;
    if ( *(i - 6) + *v8 == a2 )
    {
      if ( (dword_682604 & 0x10000) != 0 )
        goto LABEL_14;
LABEL_11:
      __dmb(0xBu);
      *v3 = 0;
      goto LABEL_12;
    }
  }
  v8 = 0;
  if ( (dword_682604 & 0x10000) == 0 )
    goto LABEL_11;
LABEL_14:
  KiReleaseSpinLockInstrumented(v3, vars4);
LABEL_12:
  KfLowerIrql(v5);
  return v8;
}
