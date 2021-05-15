// PopGetDope 
 
int __fastcall PopGetDope(int a1)
{
  int v1; // r6
  _BYTE *v3; // r0
  _DWORD *v4; // r5
  int v5; // r8
  unsigned int v7; // r2

  v1 = *(_DWORD *)(a1 + 176);
  if ( !*(_DWORD *)(v1 + 12) )
  {
    v3 = (_BYTE *)ExAllocatePoolWithTag(512, 68);
    v4 = v3;
    if ( v3 )
    {
      memset(v3, 0, 68);
      v4[10] = 0;
      v4[11] = 0;
      v4[6] = a1;
      v4[7] = v4 + 7;
      v4[8] = v4 + 7;
      v5 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
        return sub_528E84();
      do
        v7 = __ldrex((unsigned int *)&PopDopeGlobalLock);
      while ( __strex(1u, (unsigned int *)&PopDopeGlobalLock) );
      __dmb(0xBu);
      if ( v7 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&PopDopeGlobalLock);
      if ( !*(_DWORD *)(v1 + 12) )
      {
        *(_DWORD *)(v1 + 12) = v4;
        v4 = 0;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&PopDopeGlobalLock);
      }
      else
      {
        __dmb(0xBu);
        PopDopeGlobalLock = 0;
      }
      KfLowerIrql(v5);
      if ( v4 )
        ExFreePoolWithTag(v4, 1162891076);
    }
  }
  return *(_DWORD *)(v1 + 12);
}
