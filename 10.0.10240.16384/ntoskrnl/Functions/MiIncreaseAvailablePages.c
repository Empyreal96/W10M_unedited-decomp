// MiIncreaseAvailablePages 
 
int __fastcall MiIncreaseAvailablePages(int a1, int a2, int a3, int a4)
{
  unsigned int v6; // r0
  unsigned int v7; // r5
  int v8; // r2
  char *v9; // r4
  int v10; // r0
  unsigned int *v11; // r1
  int *v12; // r0
  unsigned int *v13; // r2
  unsigned int v14; // r4
  int v15; // [sp+0h] [bp-20h] BYREF
  unsigned int *v16; // [sp+4h] [bp-1Ch]
  int v17; // [sp+8h] [bp-18h]
  int v18; // [sp+Ch] [bp-14h]

  v15 = a1;
  v16 = (unsigned int *)a2;
  v17 = a3;
  v18 = a4;
  if ( a2 == 1 )
    return sub_50EF9C();
  do
    v6 = __ldrex((unsigned int *)&dword_640580);
  while ( __strex(v6 + a2, (unsigned int *)&dword_640580) );
  v7 = v6 + a2;
  v8 = 2;
  if ( v6 + a2 >= 0x80 && v6 < 0x80 )
    v8 = 1;
  if ( v7 >= 2 && v6 < 2 )
    v8 = 0;
  if ( v8 != 2 )
  {
    v9 = (char *)&unk_640284 + 20 * v8;
    KeAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_640280, &v15);
    KeSetEvent((int)v9, 0, 0);
    ++*((_DWORD *)v9 + 4);
    if ( (dword_682604 & 0x10000) != 0 )
    {
      KiReleaseQueuedSpinLockInstrumented(&v15);
    }
    else
    {
      v10 = v15;
      if ( !v15 )
      {
        v11 = v16;
        __dmb(0xBu);
        do
          v12 = (int *)__ldrex(v11);
        while ( v12 == &v15 && __strex(0, v11) );
        if ( v12 == &v15 )
          goto LABEL_11;
        v10 = KxWaitForLockChainValid(&v15);
      }
      v15 = 0;
      __dmb(0xBu);
      v13 = (unsigned int *)(v10 + 4);
      do
        v14 = __ldrex(v13);
      while ( __strex(v14 ^ 1, v13) );
    }
  }
LABEL_11:
  if ( v7 > dword_6402B0 && v7 - a2 <= dword_6402B0 || v7 > dword_6402AC && v7 - a2 <= dword_6402AC )
    JUMPOUT(0x50F054);
  return v15;
}
