// IopGetSetStreamIdentifier 
 
int __fastcall IopGetSetStreamIdentifier(int a1, int a2, int a3, _DWORD *a4, unsigned __int8 a5)
{
  int v7; // r4
  _DWORD *v8; // r6
  unsigned int *v9; // r5
  int v10; // r7
  unsigned int v11; // r2
  _DWORD *v12; // r2
  int v13; // r3
  _DWORD *v14; // r7
  int v15; // r10
  unsigned int v16; // r2
  _DWORD *v17; // r2
  _DWORD *v20; // [sp+Ch] [bp-2Ch] BYREF
  int v21; // [sp+10h] [bp-28h]
  int v22[9]; // [sp+14h] [bp-24h] BYREF
  int vars4; // [sp+3Ch] [bp+4h]

  v21 = a2;
  v7 = IopGetSetSpecificExtension(a1, 4, 8, a5, (int *)&v20, v22);
  if ( v7 >= 0 )
  {
    v8 = v20;
    if ( !v20 )
    {
      *a4 = 0;
      return 0;
    }
    v9 = (unsigned int *)(a1 + 112);
    v10 = KfRaiseIrql(2);
    if ( (dword_682604 & 0x210000) != 0 )
    {
      KiAcquireSpinLockInstrumented((int)v9);
    }
    else
    {
      do
        v11 = __ldrex(v9);
      while ( __strex(1u, v9) );
      __dmb(0xBu);
      if ( v11 )
        KxWaitForSpinLockAndAcquire(v9);
    }
    v12 = (_DWORD *)*v8;
    if ( !*v8 )
    {
      *v8 = v8;
      v8[1] = v8;
      v12 = v8;
    }
    if ( v12 == v8 )
    {
LABEL_14:
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v9, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v9 = 0;
      }
      KfLowerIrql(v10);
      if ( a5 )
      {
        v14 = (_DWORD *)ExAllocatePoolWithTag(512, v21 + 16);
        if ( v14 )
        {
          v15 = KfRaiseIrql(2);
          if ( (dword_682604 & 0x210000) != 0 )
          {
            KiAcquireSpinLockInstrumented((int)v9);
          }
          else
          {
            do
              v16 = __ldrex(v9);
            while ( __strex(1u, v9) );
            __dmb(0xBu);
            if ( v16 )
              KxWaitForSpinLockAndAcquire(v9);
          }
          v17 = (_DWORD *)v8[1];
          *v14 = v8;
          v14[1] = v17;
          if ( (_DWORD *)*v17 != v8 )
            __fastfail(3u);
          *v17 = v14;
          v8[1] = v14;
          v14[2] = v14 + 4;
          v14[3] = a3;
          *a4 = v14 + 4;
          if ( (dword_682604 & 0x10000) != 0 )
          {
            KiReleaseSpinLockInstrumented(v9, vars4);
          }
          else
          {
            __dmb(0xBu);
            *v9 = 0;
          }
          KfLowerIrql(v15);
          return 0;
        }
        v13 = -1073741670;
      }
      else
      {
        v13 = 0;
      }
      *a4 = 0;
      v7 = v13;
    }
    else
    {
      while ( v12[3] != a3 )
      {
        v12 = (_DWORD *)*v12;
        if ( v12 == v8 )
          goto LABEL_14;
      }
      if ( a5 )
      {
        *a4 = 0;
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v9, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v9 = 0;
        }
        v7 = -1073741791;
      }
      else
      {
        v7 = 0;
        *a4 = v12[2];
        if ( (dword_682604 & 0x10000) != 0 )
        {
          KiReleaseSpinLockInstrumented(v9, vars4);
        }
        else
        {
          __dmb(0xBu);
          *v9 = 0;
        }
      }
      KfLowerIrql(v10);
    }
  }
  return v7;
}
