// IoFreeSfioStreamIdentifier 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall IoFreeSfioStreamIdentifier(int a1, int a2)
{
  _DWORD **v4; // r5
  int v5; // r6
  unsigned int *v6; // r4
  int v7; // r9
  unsigned int v8; // r2
  _DWORD *i; // r0
  int v10; // r1 OVERLAPPED
  _DWORD *v11; // r2 OVERLAPPED
  int vars4; // [sp+1Ch] [bp+4h]

  v4 = (_DWORD **)IopGetFileObjectExtension(a1, 4, 0);
  v5 = -1073741275;
  if ( v4 )
  {
    v6 = (unsigned int *)(a1 + 112);
    v7 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v6);
    }
    else
    {
      do
        v8 = __ldrex(v6);
      while ( __strex(1u, v6) );
      __dmb(0xBu);
      if ( v8 )
        KxWaitForSpinLockAndAcquire(v6);
    }
    for ( i = *v4; i != v4; i = (_DWORD *)*i )
    {
      if ( i[3] == a2 )
      {
        *(_QWORD *)&v10 = *(_QWORD *)i;
        if ( *(_DWORD **)(*i + 4) != i || (_DWORD *)*v11 != i )
          __fastfail(3u);
        *v11 = v10;
        *(_DWORD *)(v10 + 4) = v11;
        ExFreePoolWithTag(i);
        v5 = 0;
        break;
      }
    }
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v6, vars4);
    }
    else
    {
      __dmb(0xBu);
      *v6 = 0;
    }
    KfLowerIrql(v7);
  }
  return v5;
}
