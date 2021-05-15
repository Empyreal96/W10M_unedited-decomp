// IopCancelIrpsInCurrentThreadListSpecialApc 
 
int __fastcall IopCancelIrpsInCurrentThreadListSpecialApc(_DWORD *a1, int a2, int a3, _BYTE **a4)
{
  _BYTE *v4; // r9
  int v6; // r10
  unsigned int v7; // r6
  unsigned int *v8; // r4
  int v9; // r8
  unsigned int v11; // r2
  int *v12; // r1
  int v13; // r2
  int v14; // r2
  int v15; // r3

  v4 = *a4;
  v6 = 0;
  v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v8 = (unsigned int *)(v7 + 1024);
  v9 = KfRaiseIrql(2);
  if ( (dword_682604 & 0x210000) != 0 )
    return sub_5265AC();
  do
    v11 = __ldrex(v8);
  while ( __strex(1u, v8) );
  __dmb(0xBu);
  if ( v11 )
    KxWaitForSpinLockAndAcquire(v8);
  v12 = *(int **)(v7 + 908);
  *v4 = 0;
  if ( (int *)(v7 + 908) == v12 )
  {
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v8);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
    KfLowerIrql(v9);
    a1[19] = 0;
  }
  else
  {
    do
    {
      if ( *((char *)v12 + 19) < *((char *)v12 + 18) + 2 )
      {
        v13 = a1[13];
        if ( !v13 || v12[6] == v13 )
        {
          v14 = a1[12];
          if ( !v14 || v12[21] == v14 )
          {
            v15 = *(v12 - 2);
            if ( (v15 & 0x400) == 0 && ((v15 & 0x84) != 0 || (*((_BYTE *)v12 + 23) & 2) != 0) )
            {
              *((_BYTE *)v12 + 20) = 1;
              *v4 = 1;
              a1[19] = 1;
              v6 = 1;
            }
          }
        }
      }
      v12 = (int *)*v12;
    }
    while ( (int *)(v7 + 908) != v12 );
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseSpinLockInstrumented(v8);
    }
    else
    {
      __dmb(0xBu);
      *v8 = 0;
    }
    KfLowerIrql(v9);
    if ( v6 )
      KeAlertThread(v7, 0);
  }
  return KeSetEvent(a1 + 14, 0, 0);
}
