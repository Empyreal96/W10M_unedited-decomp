// sub_50EF9C 
 
void __fastcall sub_50EF9C(int a1, unsigned int *a2, int a3, int a4, int a5, unsigned int *a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14)
{
  int *v14; // r2
  unsigned int v15; // r5
  unsigned int v16; // r5
  int v17; // r3
  char *v18; // r4
  int v19; // r0
  int *v20; // r0
  unsigned int v21; // r4
  int v22; // r3
  unsigned int v23; // r5

  v14 = &dword_640580;
  do
  {
    v15 = __ldrex((unsigned int *)&dword_640580);
    v16 = v15 + 1;
  }
  while ( __strex(v16, (unsigned int *)&dword_640580) );
  if ( v16 <= 0x80 )
  {
    if ( v16 == 128 )
    {
      v17 = 1;
    }
    else
    {
      if ( v16 != 2 )
        goto LABEL_18;
      v17 = 0;
    }
    v18 = (char *)&unk_640284 + 20 * v17;
    KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_640280, &a5);
    KeSetEvent((int)v18, 0, 0);
    ++*((_DWORD *)v18 + 4);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&a5, a14);
    }
    else
    {
      v19 = a5;
      if ( !a5 )
      {
        a2 = a6;
        __dmb(0xBu);
        v14 = &a5;
        do
          v20 = (int *)__ldrex(a2);
        while ( v20 == &a5 && __strex(0, a2) );
        if ( v20 == &a5 )
          goto LABEL_18;
        v19 = KxWaitForLockChainValid(&a5);
      }
      a5 = 0;
      __dmb(0xBu);
      v14 = (int *)(v19 + 4);
      do
      {
        v21 = __ldrex((unsigned int *)v14);
        a2 = (unsigned int *)(v21 ^ 1);
      }
      while ( __strex(v21 ^ 1, (unsigned int *)v14) );
    }
  }
LABEL_18:
  v22 = dword_6402AC;
  v23 = v16 - 1;
  if ( v23 == dword_6402AC || (v22 = dword_6402B0, v23 == dword_6402B0) )
    MiUpdateAvailableEvents(MiSystemPartition, (int)a2, (int)v14, v22);
  JUMPOUT(0x4E69BE);
}
