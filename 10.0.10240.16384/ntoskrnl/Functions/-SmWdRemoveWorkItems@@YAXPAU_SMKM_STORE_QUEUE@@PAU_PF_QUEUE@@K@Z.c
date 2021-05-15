// -SmWdRemoveWorkItems@@YAXPAU_SMKM_STORE_QUEUE@@PAU_PF_QUEUE@@K@Z 
 
void __fastcall SmWdRemoveWorkItems(struct _SMKM_STORE_QUEUE *a1, struct _PF_QUEUE *a2, unsigned int a3)
{
  char *v5; // r5
  char *v6; // r10
  unsigned int v7; // r2
  unsigned int *v8; // r1
  unsigned int *v9; // r6
  unsigned int v10; // r7
  _DWORD *v11; // r1
  int v12; // r3
  int v14; // [sp+4h] [bp-24h]
  int vars4; // [sp+2Ch] [bp+4h]

  if ( a3 == 2 )
  {
    v5 = (char *)a1 + 8;
    v6 = (char *)a1 + 32;
  }
  else
  {
    v5 = (char *)a1 + 16;
    v6 = (char *)a1 + 36;
  }
  v14 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
  {
    KiAcquireSpinLockInstrumented((int)a1);
  }
  else
  {
    do
      v7 = __ldrex((unsigned int *)a1);
    while ( __strex(1u, (unsigned int *)a1) );
    __dmb(0xBu);
    if ( v7 )
      KxWaitForSpinLockAndAcquire((unsigned int *)a1);
  }
  v8 = (unsigned int *)v5;
  while ( 1 )
  {
    v9 = v8;
    if ( v8 == *((unsigned int **)v5 + 1) )
      break;
    v10 = *v8 & 0xFFFFFFF8;
    v8 = (unsigned int *)v10;
    if ( !v10 )
      break;
    if ( (*(_DWORD *)v10 & 7) == a3 )
    {
      v11 = (_DWORD *)(*v9 & 0xFFFFFFF8);
      *v9 = *v11 & 0xFFFFFFF8 | *v9 & 7;
      if ( *((_DWORD **)v5 + 1) == v11 )
        *((_DWORD *)v5 + 1) = v9;
      **((_DWORD **)v5 + 1) = **((_DWORD **)v5 + 1) & 7 | (8 * (**((_DWORD **)v5 + 1) >> 3) - 8);
      v12 = *(_DWORD *)v6 - 1;
      __dmb(0xBu);
      v8 = v9;
      *(_DWORD *)v6 = v12;
      *(_DWORD *)v10 = *(_DWORD *)v10 & 7 | (8 * ((**((_DWORD **)a2 + 1) >> 3) + 1));
      **((_DWORD **)a2 + 1) = **((_DWORD **)a2 + 1) & 7 | v10;
      *((_DWORD *)a2 + 1) = v10;
    }
  }
  if ( (dword_682604 & 0x10000) != 0 )
  {
    KiReleaseSpinLockInstrumented(a1, vars4);
  }
  else
  {
    __dmb(0xBu);
    *(_DWORD *)a1 = 0;
  }
  KfLowerIrql(v14);
}
