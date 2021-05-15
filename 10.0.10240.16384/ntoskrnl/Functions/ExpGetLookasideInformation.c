// ExpGetLookasideInformation 
 
int __fastcall ExpGetLookasideInformation(int a1, unsigned int a2, int a3)
{
  _DWORD *v3; // r5
  int v4; // r6
  int v5; // r8
  unsigned int v6; // r10
  int v7; // r4
  int *v8; // r1
  int *v9; // r2
  int *v10; // r5
  int v11; // r9
  unsigned int v12; // r2
  int *v13; // r2
  unsigned int v14; // r2
  int *v15; // r2
  int v17; // [sp+8h] [bp-28h] BYREF
  _DWORD *v18; // [sp+Ch] [bp-24h]
  int v19[8]; // [sp+10h] [bp-20h] BYREF
  int vars4; // [sp+34h] [bp+4h]

  v3 = (_DWORD *)a3;
  v4 = 0;
  v18 = (_DWORD *)a3;
  v5 = 0;
  v6 = a2 >> 5;
  if ( a2 >> 5 )
  {
    v5 = ExLockUserBuffer(a1, a2, *(char *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x15A), 1, &v17, v19);
    if ( v5 >= 0 )
    {
      v7 = v17;
      v5 = 0;
      v8 = (int *)ExPoolLookasideListHead;
      while ( v8 != &ExPoolLookasideListHead )
      {
        ++v4;
        *(_WORD *)v7 = *((_WORD *)v8 - 22);
        *(_WORD *)(v7 + 2) = *((_WORD *)v8 - 20);
        *(_DWORD *)(v7 + 4) = *(v8 - 9);
        *(_DWORD *)(v7 + 8) = *(v8 - 9) - *(v8 - 8);
        *(_DWORD *)(v7 + 12) = *(v8 - 7);
        *(_DWORD *)(v7 + 16) = *(v8 - 7) - *(v8 - 6);
        *(_DWORD *)(v7 + 20) = *(v8 - 5);
        *(_DWORD *)(v7 + 24) = *(v8 - 4);
        *(_DWORD *)(v7 + 28) = *(v8 - 3);
        if ( v4 == v6 )
          goto LABEL_36;
        v8 = (int *)*v8;
        v7 += 32;
      }
      v9 = (int *)ExSystemLookasideListHead;
      while ( v9 != &ExSystemLookasideListHead )
      {
        ++v4;
        *(_WORD *)v7 = *((_WORD *)v9 - 22);
        *(_WORD *)(v7 + 2) = *((_WORD *)v9 - 20);
        *(_DWORD *)(v7 + 4) = *(v9 - 9);
        *(_DWORD *)(v7 + 8) = *(v9 - 8);
        *(_DWORD *)(v7 + 12) = *(v9 - 7);
        *(_DWORD *)(v7 + 16) = *(v9 - 6);
        *(_DWORD *)(v7 + 20) = *(v9 - 5);
        *(_DWORD *)(v7 + 24) = *(v9 - 4);
        *(_DWORD *)(v7 + 28) = *(v9 - 3);
        if ( v4 == v6 )
          goto LABEL_36;
        v9 = (int *)*v9;
        v7 += 32;
      }
      v10 = &ExNPagedLookasideLock;
      v11 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)&ExNPagedLookasideLock);
      }
      else
      {
        do
          v12 = __ldrex((unsigned int *)&ExNPagedLookasideLock);
        while ( __strex(1u, (unsigned int *)&ExNPagedLookasideLock) );
        __dmb(0xBu);
        if ( v12 )
          KxWaitForSpinLockAndAcquire((unsigned int *)&ExNPagedLookasideLock);
      }
      v13 = (int *)ExNPagedLookasideListHead;
      while ( v13 != &ExNPagedLookasideListHead )
      {
        ++v4;
        *(_WORD *)v7 = *((_WORD *)v13 - 22);
        *(_WORD *)(v7 + 2) = *((_WORD *)v13 - 20);
        *(_DWORD *)(v7 + 4) = *(v13 - 9);
        *(_DWORD *)(v7 + 8) = *(v13 - 8);
        *(_DWORD *)(v7 + 12) = *(v13 - 7);
        *(_DWORD *)(v7 + 16) = *(v13 - 6);
        *(_DWORD *)(v7 + 20) = 0;
        *(_DWORD *)(v7 + 24) = *(v13 - 4);
        *(_DWORD *)(v7 + 28) = *(v13 - 3);
        if ( v4 == v6 )
          goto LABEL_32;
        v13 = (int *)*v13;
        v7 += 32;
      }
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(&ExNPagedLookasideLock, vars4);
      }
      else
      {
        __dmb(0xBu);
        ExNPagedLookasideLock = 0;
      }
      KfLowerIrql(v11);
      v10 = &ExPagedLookasideLock;
      v11 = KfRaiseIrql(2);
      if ( (dword_682604 & 0x210000) != 0 )
      {
        KiAcquireSpinLockInstrumented((int)&ExPagedLookasideLock);
      }
      else
      {
        do
          v14 = __ldrex((unsigned int *)&ExPagedLookasideLock);
        while ( __strex(1u, (unsigned int *)&ExPagedLookasideLock) );
        __dmb(0xBu);
        if ( v14 )
          KxWaitForSpinLockAndAcquire((unsigned int *)&ExPagedLookasideLock);
      }
      v15 = (int *)ExPagedLookasideListHead;
      while ( v15 != &ExPagedLookasideListHead )
      {
        ++v4;
        *(_WORD *)v7 = *((_WORD *)v15 - 22);
        *(_WORD *)(v7 + 2) = *((_WORD *)v15 - 20);
        *(_DWORD *)(v7 + 4) = *(v15 - 9);
        *(_DWORD *)(v7 + 8) = *(v15 - 8);
        *(_DWORD *)(v7 + 12) = *(v15 - 7);
        *(_DWORD *)(v7 + 16) = *(v15 - 6);
        *(_DWORD *)(v7 + 20) = 1;
        *(_DWORD *)(v7 + 24) = *(v15 - 4);
        *(_DWORD *)(v7 + 28) = *(v15 - 3);
        if ( v4 == v6 )
          break;
        v15 = (int *)*v15;
        v7 += 32;
      }
LABEL_32:
      if ( (dword_682604 & 0x10000) != 0 )
      {
        KiReleaseSpinLockInstrumented(v10, vars4);
      }
      else
      {
        __dmb(0xBu);
        *v10 = 0;
      }
      KfLowerIrql(v11);
      v3 = v18;
LABEL_36:
      ExUnlockUserBuffer(v19[0]);
    }
  }
  *v3 = 32 * v4;
  return v5;
}
