// ExfAcquirePushLockExclusiveEx 
 
int __fastcall ExfAcquirePushLockExclusiveEx(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned int v6; // r5
  int result; // r0
  unsigned int v8; // r2
  unsigned int v9; // r1
  int v10; // r2
  _BYTE *v11; // r1
  unsigned int v12; // r6
  int i; // r2
  unsigned int v14; // r1
  _BYTE v15[3]; // [sp+10h] [bp-58h] BYREF
  _BYTE v16[5]; // [sp+13h] [bp-55h] BYREF
  _DWORD v17[3]; // [sp+18h] [bp-50h] BYREF
  _BYTE *v18; // [sp+24h] [bp-44h]
  int v19; // [sp+28h] [bp-40h]
  unsigned int v20; // [sp+2Ch] [bp-3Ch]
  _DWORD v21[4]; // [sp+30h] [bp-38h] BYREF
  int v22[8]; // [sp+48h] [bp-20h] BYREF

  __pld(a1);
  v22[0] = 0;
  v6 = *a1;
  result = 2;
  while ( (v6 & 1) != 0 )
  {
    if ( a2 )
      KeAbPreWait(a2, -1, 1);
    v21[0] = 3;
    v21[1] = a2;
    v10 = 0;
    v19 = 0;
    if ( (v6 & 2) != 0 )
    {
      v17[2] = v6 & 0xFFFFFFF0;
      v18 = 0;
      v20 = -1;
      v11 = (_BYTE *)(v6 & 8 | (unsigned int)v15 | 7);
      if ( (v6 & 4) == 0 )
        v10 = 1;
    }
    else
    {
      v18 = v15;
      v20 = v6 >> 4;
      if ( v6 >> 4 > 1 )
        v11 = (_BYTE *)((unsigned int)v15 | 0xB);
      else
        v11 = v16;
      if ( !v20 )
        v20 = -2;
    }
    __dmb(0xBu);
    do
      v12 = __ldrex(a1);
    while ( v12 == v6 && __strex((unsigned int)v11, a1) );
    __dmb(0xBu);
    if ( v12 != v6 )
      goto LABEL_19;
    if ( v10 )
      ExpOptimizePushLockList(a1, v11);
    v15[0] = 1;
    v15[1] = 0;
    v15[2] = 4;
    *(_DWORD *)&v16[1] = 0;
    v17[1] = v17;
    v17[0] = v17;
    if ( MEMORY[0xFFFF936A] > 1u )
    {
      for ( i = ExpSpinCount; i; --i )
      {
        if ( (v21[0] & 2) == 0 )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    __dmb(0xBu);
    do
      v14 = __ldrex((unsigned __int8 *)v21);
    while ( __strex(v14 & 0xFD, (unsigned __int8 *)v21) );
    __dmb(0xBu);
    if ( (unsigned __int8)(v14 & 2) >> 1 )
      KeWaitForSingleObject((unsigned int)v15, 28, 0, 0, 0);
LABEL_20:
    if ( a2 )
      a2 = KeAbPreAcquire(a3, a2, 0);
    v6 = v12;
    result = 2;
  }
  __dmb(0xBu);
  v8 = v6 + 1;
  do
    v9 = __ldrex(a1);
  while ( v9 == v6 && __strex(v8, a1) );
  __dmb(0xBu);
  if ( v9 != v6 )
  {
    if ( a2 )
      KeAbPreWait(a2, v9, v8);
LABEL_19:
    RtlBackoff(v22);
    v12 = *a1;
    __pld(a1);
    goto LABEL_20;
  }
  return result;
}
