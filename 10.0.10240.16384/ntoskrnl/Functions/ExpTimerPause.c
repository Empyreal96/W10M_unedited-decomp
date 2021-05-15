// ExpTimerPause 
 
int __fastcall ExpTimerPause(int a1, int a2, unsigned __int64 a3, unsigned __int64 a4)
{
  unsigned int v4; // r8
  unsigned int v5; // r9
  unsigned int *v7; // r5
  unsigned int v9; // r2
  char v10; // r1
  int v11; // r2
  int v12; // r3
  int v13[2]; // [sp+0h] [bp-28h] BYREF
  unsigned __int64 v14[4]; // [sp+8h] [bp-20h] BYREF

  v13[0] = a1;
  v13[1] = a2;
  v14[0] = a3;
  v4 = HIDWORD(a3);
  v5 = a3;
  v7 = (unsigned int *)(a1 + 48);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_525488();
  do
    v9 = __ldrex(v7);
  while ( __strex(1u, v7) );
  __dmb(0xBu);
  if ( v9 )
    KxWaitForSpinLockAndAcquire(a1 + 48);
  *(_BYTE *)(a1 + 144) |= 2u;
  if ( !KeCancelTimerInternal(a1, v14, v13, a1 + 184) )
  {
    v10 = 0;
    goto LABEL_11;
  }
  v10 = v13[0];
  if ( v13[0] != 2 )
  {
    if ( v13[0] != 1 )
    {
      if ( v13[0] == 3 )
        *(_QWORD *)(a1 + 176) = v14[0];
      goto LABEL_11;
    }
    if ( v14[0] > a4 )
    {
      v11 = (v14[0] - a4 + __PAIR64__(v4, v5)) >> 32;
      v12 = LODWORD(v14[0]) - a4 + v5;
      goto LABEL_10;
    }
LABEL_14:
    *(_DWORD *)(a1 + 176) = 0;
    *(_DWORD *)(a1 + 180) = 0;
    goto LABEL_11;
  }
  if ( v14[0] <= a4 )
    goto LABEL_14;
  v11 = (a4 - v14[0]) >> 32;
  v12 = a4 - LODWORD(v14[0]);
LABEL_10:
  *(_DWORD *)(a1 + 176) = v12;
  *(_DWORD *)(a1 + 180) = v11;
LABEL_11:
  *(_BYTE *)(a1 + 145) = v10;
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(v7);
  }
  else
  {
    __dmb(0xBu);
    *v7 = 0;
  }
  return v13[0];
}
