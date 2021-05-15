// sub_511310 
 
void __fastcall sub_511310(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22)
{
  _DWORD *v22; // r6
  int v23; // r9
  int v24; // r10
  unsigned int *v25; // r5
  unsigned int *v26; // r7
  int v27; // r4
  unsigned int v28; // r2
  int *v29; // r0
  _DWORD *v30; // r8
  bool v31; // zf
  int v32; // r4
  int v33; // r0

  if ( !a1 )
  {
    KeResetEvent(a11);
    v25 = v22 + 962;
    v26 = v22 + 964;
    while ( 1 )
    {
      v27 = KfRaiseIrql(2);
      if ( (*(_DWORD *)(v24 + 4) & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)(v22 + 964));
      }
      else
      {
        do
          v28 = __ldrex(v26);
        while ( __strex(1u, v26) );
        __dmb(0xBu);
        if ( v28 )
          KxWaitForSpinLockAndAcquire(v22 + 964);
      }
      v29 = (int *)v22[963];
      if ( v29 == (int *)v25 )
      {
        v30 = 0;
      }
      else
      {
        v30 = (_DWORD *)*v25;
        v31 = *v25 == (_DWORD)v29;
        *v25 = *(_DWORD *)*v25 & 0xFFFFFFF8;
        if ( v31 )
        {
          *v25 = 0;
          v22[963] = v22 + 962;
        }
        else
        {
          *v29 = *v29 & 7 | (8 * ((unsigned int)*v29 >> 3) - 8);
        }
      }
      if ( (*(_DWORD *)(v24 + 4) & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v22 + 964, a22);
      }
      else
      {
        __dmb(0xBu);
        *v26 = 0;
      }
      KfLowerIrql(v27);
      if ( !v30 )
        break;
      v32 = SmFpAllocate(a9, 3, v22 + 953, 0);
      v33 = SMKM_STORE<SM_TRAITS>::SmStDirectReadIssue(v22, v30, v23);
      SMKM_STORE<SM_TRAITS>::SmStDirectReadComplete(v22, v30, v33);
      SmFpFree(a9, 3, v22 + 953, v32);
    }
  }
  JUMPOUT(0x429ECC);
}
