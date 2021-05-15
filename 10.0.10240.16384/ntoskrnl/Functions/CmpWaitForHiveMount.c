// CmpWaitForHiveMount 
 
int __fastcall CmpWaitForHiveMount(__int64 *a1, unsigned int a2, __int64 a3)
{
  _DWORD *v3; // r8
  __int64 v4; // r4
  int v5; // r9
  unsigned int v6; // r2
  int v7; // r6
  int v9; // r2
  __int16 *v10; // r0
  unsigned int v11; // r2
  unsigned int v12; // r2
  int v13; // r0
  unsigned __int8 *v14; // r4
  unsigned int v15; // r3
  unsigned int *v16; // r2
  unsigned int v17; // r1
  __int16 **v18; // r5
  int v19; // r0
  __int16 *v20; // r2
  unsigned int v21; // r3
  unsigned int v22; // r3
  __int64 v23; // [sp+8h] [bp-20h] BYREF

  v23 = a3;
  v4 = *a1;
  v3 = (_DWORD *)HIDWORD(a3);
  v23 = *a1;
  LODWORD(v4) = (unsigned __int16)v23;
  v5 = a3;
  if ( (_WORD)v23 )
  {
    do
    {
      if ( *(_WORD *)HIDWORD(v4) != 92 )
        break;
      LODWORD(v4) = (unsigned __int16)(v4 - 2);
      HIDWORD(v4) += 2;
    }
    while ( (_DWORD)v4 );
    HIDWORD(v23) = HIDWORD(v4);
  }
  if ( a2 < 2 )
  {
    if ( !(_DWORD)v4 )
      goto LABEL_9;
    do
    {
      if ( *(_WORD *)HIDWORD(v4) == 92 )
        break;
      LODWORD(v4) = (unsigned __int16)(v4 - 2);
      HIDWORD(v4) += 2;
    }
    while ( (_DWORD)v4 );
    HIDWORD(v23) = HIDWORD(v4);
    if ( !(_DWORD)v4 )
    {
LABEL_9:
      __dmb(0xBu);
      do
        v6 = __ldrex((unsigned __int8 *)algn_60E6F4);
      while ( __strex(v6 | 1, (unsigned __int8 *)algn_60E6F4) );
LABEL_11:
      __dmb(0xBu);
      return 0;
    }
    do
    {
      if ( *(_WORD *)HIDWORD(v4) != 92 )
        break;
      LODWORD(v4) = (unsigned __int16)(v4 - 2);
      HIDWORD(v4) += 2;
    }
    while ( (_DWORD)v4 );
    HIDWORD(v23) = HIDWORD(v4);
  }
  if ( !(_DWORD)v4 )
    goto LABEL_9;
  v9 = 0;
  do
  {
    if ( *(_WORD *)(HIDWORD(v4) + 2 * v9) == 92 )
      break;
    LODWORD(v4) = (unsigned __int16)(v4 - 2);
    v9 = (unsigned __int16)(v9 + 1);
  }
  while ( (_DWORD)v4 );
  LOWORD(v23) = 2 * v9;
  v10 = (__int16 *)CmpComputeHashKey(0, (unsigned __int16 *)&v23);
  v11 = 0;
  while ( (&CmpBootLoadControl)[5 * v11 + 1] != v10 )
  {
    v11 = (unsigned __int16)(v11 + 1);
    if ( v11 >= 7 )
    {
      __dmb(0xBu);
      do
        v12 = __ldrex((unsigned __int8 *)algn_60E6F4);
      while ( __strex(v12 | 4, (unsigned __int8 *)algn_60E6F4) );
      goto LABEL_11;
    }
  }
  __dmb(0xBu);
  v13 = 5 * v11;
  v14 = (unsigned __int8 *)&algn_60E6F4[20 * v11];
  do
    v15 = __ldrex(v14);
  while ( __strex(v15 | 8, v14) );
  __dmb(0xBu);
  v16 = (unsigned int *)((char *)&unk_60E6F8 + 20 * v11);
  do
    v17 = __ldrex(v16);
  while ( __strex(v17 + 1, v16) );
  __dmb(0xBu);
  v18 = &(&CmpBootLoadControl)[v13];
  v19 = KeSetEvent((int)&unk_60E7A0 + 96 * (_DWORD)v18[1], 0, 0);
  v20 = v18[1];
  if ( CmpMachineHiveList[24 * (_DWORD)v20 + 19] )
    return sub_8175DC(v19);
  v7 = 1;
  if ( v5 )
  {
    CmpUnlockRegistry();
    __dmb(0xBu);
    do
      v21 = __ldrex(v14);
    while ( __strex(v21 | 0x10, v14) );
    __dmb(0xBu);
    KeWaitForSingleObject((unsigned int)&unk_60E7C0 + 96 * (_DWORD)v18[1], 0, 0, 0, 0);
    CmpLockRegistry();
  }
  else
  {
    *v3 = v20;
    __dmb(0xBu);
    do
      v22 = __ldrex(v14);
    while ( __strex(v22 | 0x20, v14) );
    __dmb(0xBu);
  }
  return v7;
}
