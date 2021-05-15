// PpmRemoveIdleStates 
 
int __fastcall PpmRemoveIdleStates(_DWORD *a1)
{
  int v1; // r6
  unsigned int v3; // r2
  __int16 v5[2]; // [sp+0h] [bp-28h] BYREF
  int v6; // [sp+4h] [bp-24h]
  int v7; // [sp+8h] [bp-20h]
  int vars4; // [sp+2Ch] [bp+4h]

  v1 = a1[736];
  if ( v1 )
  {
    v5[0] = 1;
    v5[1] = 1;
    v6 = 0;
    v7 = 1 << a1[5];
    off_6179FC(1, v5);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)&PpmIdleVetoLock);
    }
    else
    {
      do
        v3 = __ldrex((unsigned int *)&PpmIdleVetoLock);
      while ( __strex(1u, (unsigned int *)&PpmIdleVetoLock) );
      __dmb(0xBu);
      if ( v3 )
        KxWaitForSpinLockAndAcquire((unsigned int *)&PpmIdleVetoLock);
    }
    a1[736] = 0;
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(&PpmIdleVetoLock, vars4);
    }
    else
    {
      __dmb(0xBu);
      PpmIdleVetoLock = 0;
    }
    a1[737] = 0;
    ExFreePoolWithTag(v1);
  }
  return 0;
}
