// PspTerminateAllThreads 
 
int __fastcall PspTerminateAllThreads(unsigned int *a1, _DWORD *a2, int a3, char a4)
{
  unsigned int *v8; // r10
  _DWORD *v9; // r6
  unsigned int v10; // r2
  unsigned int v11; // r7
  int v12; // r8
  int v13; // r10
  int v14; // r0
  int v15; // r4
  int v16; // r6
  _DWORD *v17; // r0
  unsigned int v18; // r4
  unsigned int v19; // r1
  int v20; // r6
  unsigned __int8 *v21; // r3
  unsigned int v22; // r1
  unsigned int *v23; // r0
  unsigned int v24; // r4
  unsigned int v25; // r1
  _DWORD *v27; // [sp+4h] [bp-2Ch]
  unsigned int *v28; // [sp+Ch] [bp-24h]

  if ( (a1[48] & 0x2000) != 0 )
    return sub_7F7B70();
  v8 = (unsigned int *)a2[29];
  v28 = v8;
  v9 = (_DWORD *)PspGetPreviousProcessThread(a1, 0);
  v10 = ((unsigned int)v28 ^ ((unsigned __int8)v28 ^ (unsigned __int8)(2 * ((a4 & 1) != 0))) & 2) & 0xFFFFFFFE | ((a4 & 2) != 0);
  v11 = (v10 ^ (4 * ((a4 & 4) != 0))) & 4 ^ v10;
  v12 = 290;
  if ( !v9 )
    goto LABEL_30;
  if ( (v11 & 1) != 0 )
  {
    ObfDereferenceObjectWithTag((int)v9);
    v12 = -1073741558;
  }
  else
  {
    v27 = v9;
    ObfReferenceObject((int)v9);
    v13 = 0;
    do
    {
      if ( v9 != a2 )
      {
        if ( (v11 & 4) != 0 )
        {
          v11 ^= (v11 ^ (8 * ((v9[241] & 0x10) != 0))) & 8;
        }
        else
        {
          v23 = v9 + 235;
          __pld(v9 + 235);
          v24 = v9[235] & 0xFFFFFFFE;
          do
            v25 = __ldrex(v23);
          while ( v25 == v24 && __strex(v24 + 2, v23) );
          __dmb(0xBu);
          if ( v25 == v24 || ExfAcquireRundownProtection(v23) )
          {
            v11 |= 8u;
          }
          else
          {
            __dmb(0xBu);
            v21 = (unsigned __int8 *)v9 + 961;
            do
              v22 = __ldrex(v21);
            while ( __strex(v22 | 0x80, v21) );
            __dmb(0xBu);
            v11 = v11 & 0xFFFFFFE7 | (16 * ((v22 >> 7) & 1));
          }
        }
        if ( (v11 & 8) != 0 )
        {
          ++v13;
          PspTerminateThreadByPointer(v9, a3, 0);
        }
      }
      v9 = (_DWORD *)PspGetPreviousProcessThread(a1, v9);
    }
    while ( v9 );
    if ( v13 && a1 == v28 )
      KeFlushProcessWriteBuffers(0);
    v14 = PsGetNextProcessThread(a1, 0);
    v15 = (int)v27;
    while ( 1 )
    {
      v16 = v14;
      if ( (_DWORD *)v14 != a2 && (v11 & 4) == 0 && (*(_DWORD *)(v14 + 960) & 0x8000) == 0 )
      {
        v17 = (_DWORD *)(v14 + 940);
        __pld(v17);
        v18 = *v17 & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v19 = __ldrex(v17);
        while ( v19 == v18 && __strex(v18 - 2, v17) );
        if ( v19 != v18 )
          ExfReleaseRundownProtection((unsigned __int8 *)v17);
        v15 = (int)v27;
      }
      if ( v16 == v15 )
        break;
      v14 = PsGetNextProcessThread(a1, v16);
    }
    ObfDereferenceObjectWithTag(v16);
    ObfDereferenceObject(v15);
    v12 = 0;
    v8 = v28;
  }
  if ( (v11 & 2) != 0 )
  {
    v20 = a3;
    if ( (unsigned int *)a2[84] == a1 )
      PspTerminateThreadByPointer(a2, a3, 0);
  }
  else
  {
LABEL_30:
    v20 = a3;
  }
  if ( a1 != v8 && v20 == 1073807364 )
    DbgkClearProcessDebugObject(a1, 0);
  if ( (v12 == 290 || a1[85] && a1 != v8) && !PspRundownSingleProcess(a1, 0) && v12 == 290 )
    v12 = -1073741558;
  return v12;
}
