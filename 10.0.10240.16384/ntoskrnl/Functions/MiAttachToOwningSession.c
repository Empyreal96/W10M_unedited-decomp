// MiAttachToOwningSession 
 
int __fastcall MiAttachToOwningSession(int a1, int a2, int a3, int a4)
{
  int v7; // r0
  _DWORD *v9; // r4
  unsigned int *v10; // r2
  unsigned int v11; // r0
  int *v12; // r4
  int v13; // r0
  unsigned int *v14; // r1
  int *v15; // r0
  unsigned int *v16; // r2
  unsigned int v17; // r0
  unsigned int *v18; // r6
  unsigned int v19; // r1
  int v20; // r0
  unsigned int *v21; // r1
  int *v22; // r0
  unsigned int *v23; // r2
  unsigned int v24; // r0
  int v25; // r2
  int v26; // r3
  int v27; // [sp+0h] [bp-20h] BYREF
  unsigned int *v28; // [sp+4h] [bp-1Ch]
  int v29; // [sp+8h] [bp-18h]

  v27 = a2;
  v28 = (unsigned int *)a3;
  v29 = a4;
  v7 = MiGetTopLevelPfn(a1, 0, a3, a4);
  if ( (*(_DWORD *)(v7 + 12) & 0x40000000) != 0 )
    return sub_54F7B4();
  v9 = *(_DWORD **)v7;
  if ( v7 != a1 )
  {
    __dmb(0xBu);
    v10 = (unsigned int *)(v7 + 12);
    do
      v11 = __ldrex(v10);
    while ( __strex(v11 & 0x7FFFFFFF, v10) );
  }
  if ( !KeTryToAcquireInStackQueuedSpinLockAtDpcLevel((unsigned int *)&dword_634980, &v27) )
    JUMPOUT(0x54F892);
  v12 = MiSelectSessionAttachProcess(v9);
  if ( a2 != 17 )
  {
    __dmb(0xBu);
    v18 = (unsigned int *)(a1 + 12);
    do
      v19 = __ldrex(v18);
    while ( __strex(v19 & 0x7FFFFFFF, v18) );
    if ( (dword_682604 & 0x10000) != 0 )
      JUMPOUT(0x54F7DE);
    v20 = v27;
    if ( !v27 )
    {
      v21 = v28;
      __dmb(0xBu);
      do
        v22 = (int *)__ldrex(v21);
      while ( v22 == &v27 && __strex(0, v21) );
      if ( v22 == &v27 )
        goto LABEL_30;
      v20 = KxWaitForLockChainValid(&v27);
    }
    v27 = 0;
    __dmb(0xBu);
    v23 = (unsigned int *)(v20 + 4);
    do
      v24 = __ldrex(v23);
    while ( __strex(v24 ^ 1, v23) );
LABEL_30:
    KfLowerIrql(a2);
    if ( !v12 )
      JUMPOUT(0x54F7EA);
    if ( MmAttachSession((int)v12, a3, v25, v26) < 0 )
      JUMPOUT(0x54F840);
    return (int)v12;
  }
  if ( (dword_682604 & 0x10000) != 0 )
    JUMPOUT(0x54F7D2);
  v13 = v27;
  if ( !v27 )
  {
    v14 = v28;
    __dmb(0xBu);
    do
      v15 = (int *)__ldrex(v14);
    while ( v15 == &v27 && __strex(0, v14) );
    if ( v15 == &v27 )
      return (int)v12;
    v13 = KxWaitForLockChainValid(&v27);
  }
  v27 = 0;
  __dmb(0xBu);
  v16 = (unsigned int *)(v13 + 4);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 ^ 1, v16) );
  return (int)v12;
}
