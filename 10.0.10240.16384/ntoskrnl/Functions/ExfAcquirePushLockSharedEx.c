// ExfAcquirePushLockSharedEx 
 
int __fastcall ExfAcquirePushLockSharedEx(_DWORD *a1, int a2, unsigned int a3)
{
  unsigned int v6; // r4
  int result; // r0
  int v8; // r1
  unsigned int v9; // r2
  int v10; // r5
  int v11; // r2
  _BYTE *v12; // r1
  unsigned int v13; // r5
  int i; // r2
  unsigned int v15; // r1
  _BYTE v16[3]; // [sp+10h] [bp-58h] BYREF
  _BYTE v17[5]; // [sp+13h] [bp-55h] BYREF
  _DWORD v18[3]; // [sp+18h] [bp-50h] BYREF
  _BYTE *v19; // [sp+24h] [bp-44h]
  int v20; // [sp+28h] [bp-40h]
  int v21; // [sp+2Ch] [bp-3Ch]
  _DWORD v22[4]; // [sp+30h] [bp-38h] BYREF
  int v23[8]; // [sp+48h] [bp-20h] BYREF

  __pld(a1);
  v23[0] = 0;
  v6 = *a1;
  for ( result = 2; (v6 & 1) != 0; result = 2 )
  {
    v10 = (v6 >> 1) & 1;
    if ( !v10 && (v6 & 0xFFFFFFF0) != 0 )
      break;
    if ( a2 )
      KeAbPreWait(a2, -2, 1);
    v22[0] = 2;
    v22[1] = a2;
    v11 = 0;
    v20 = 0;
    if ( v10 )
    {
      v18[2] = v6 & 0xFFFFFFF0;
      v19 = 0;
      v21 = -1;
      v12 = (_BYTE *)(v6 & 8 | (unsigned int)v16 | 7);
      if ( (v6 & 4) == 0 )
        v11 = 1;
    }
    else
    {
      v19 = v16;
      v21 = -2;
      v12 = v17;
    }
    __dmb(0xBu);
    do
      v13 = __ldrex(a1);
    while ( v13 == v6 && __strex((unsigned int)v12, a1) );
    __dmb(0xBu);
    if ( v13 != v6 )
      goto LABEL_20;
    if ( v11 )
      ExpOptimizePushLockList(a1, v12);
    v16[0] = 1;
    v16[1] = 0;
    v16[2] = 4;
    *(_DWORD *)&v17[1] = 0;
    v18[1] = v18;
    v18[0] = v18;
    if ( MEMORY[0xFFFF936A] > 1u )
    {
      for ( i = ExpSpinCount; i; --i )
      {
        if ( (v22[0] & 2) == 0 )
          break;
        __dmb(0xAu);
        __yield();
      }
    }
    __dmb(0xBu);
    do
      v15 = __ldrex((unsigned __int8 *)v22);
    while ( __strex(v15 & 0xFD, (unsigned __int8 *)v22) );
    __dmb(0xBu);
    if ( (unsigned __int8)(v15 & 2) >> 1 )
      KeWaitForSingleObject((unsigned int)v16, 28, 0, 0, 0);
LABEL_21:
    if ( a2 )
      a2 = KeAbPreAcquire(a3, a2, 0);
    v6 = v13;
  }
  v8 = v6 | 1;
  if ( (v6 & 2) == 0 )
    v8 += 16;
  __dmb(0xBu);
  do
    v9 = __ldrex(a1);
  while ( v9 == v6 && __strex(v8, a1) );
  __dmb(0xBu);
  if ( v9 != v6 )
  {
    if ( a2 )
      KeAbPreWait(a2, v8, v9);
LABEL_20:
    RtlBackoff(v23);
    v13 = *a1;
    __pld(a1);
    goto LABEL_21;
  }
  return result;
}
