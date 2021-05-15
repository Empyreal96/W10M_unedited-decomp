// PopPepUpdateIdleStateRefCount 
 
int __fastcall PopPepUpdateIdleStateRefCount(int result, int a2, int a3)
{
  unsigned int v3; // r4
  int v4; // r10
  int v6; // r3
  int v7; // lr
  int v8; // r6
  unsigned int v9; // r2
  _DWORD *v10; // r8
  char *v11; // r5
  unsigned int *v12; // r7
  int v13; // r0
  unsigned int v14; // r1
  unsigned int v15; // r2
  signed int v16; // r2
  unsigned int v17; // r2
  unsigned int v18; // r7
  _DWORD *v19; // r5
  _DWORD *v20; // r0
  unsigned int *v21; // lr
  unsigned int v22; // r6
  unsigned int v23; // r2
  unsigned int v24; // r1
  _DWORD v25[40]; // [sp+8h] [bp-A0h] BYREF

  v3 = 0;
  v4 = 0;
  v6 = result ^ a2;
  v7 = 0;
  if ( a3 )
    v8 = v6 & a2;
  else
    v8 = v6 & result;
  v9 = __clz(__rbit(v8));
  if ( 1 == (unsigned __int8)(v9 >> 5) )
    return result;
  v10 = v25;
  result = -1;
  do
  {
    v8 &= v8 - 1;
    v11 = (char *)PopPepPlatformState + 256 * v9;
    v12 = (unsigned int *)(v11 + 128);
    if ( a3 )
    {
      v13 = *v12;
      if ( (int)*v12 <= 0 )
        goto LABEL_41;
      do
        v14 = __ldrex(v12);
      while ( v14 == v13 && __strex(v13 + 1, v12) );
      if ( v14 != v13 )
      {
LABEL_41:
        *v10++ = v11;
        ++v3;
      }
      result = -1;
    }
    else
    {
      do
      {
        v15 = __ldrex(v12);
        v16 = v15 - 1;
      }
      while ( __strex(v16, v12) );
      if ( v16 < 0 )
        JUMPOUT(0x54B2C4);
      if ( !v16 )
      {
        if ( !v7 )
        {
          v4 = KfRaiseIrql(2);
          result = -1;
          v7 = 1;
        }
        do
          v17 = __ldrex(v12);
        while ( !v17 && __strex(0xFFFFFFFF, v12) );
        __dmb(0xBu);
        if ( !v17 )
        {
          if ( *v12 != -1 )
            sub_54B2B8(-1);
          __dmb(0xBu);
          *v12 = 0;
        }
      }
    }
    v9 = __clz(__rbit(v8));
  }
  while ( 1 != (unsigned __int8)(v9 >> 5) );
  if ( v3 )
  {
    v4 = KfRaiseIrql(2);
    while ( 1 )
    {
      __dmb(0xAu);
      v18 = 0;
      v19 = v25;
      __yield();
      v20 = &v25[v3];
      do
      {
        v21 = (unsigned int *)(*v19 + 128);
        v22 = *v21;
        if ( (int)*v21 > 0 )
        {
          do
            v24 = __ldrex(v21);
          while ( v24 == v22 && __strex(v22 + 1, v21) );
          if ( v24 == v22 )
            goto LABEL_37;
        }
        else if ( !*v21 )
        {
          do
            v23 = __ldrex(v21);
          while ( !v23 && __strex(0xFFFFFFFF, v21) );
          __dmb(0xBu);
          if ( !v23 )
          {
            if ( *v21 != -1 )
              JUMPOUT(0x54B2D0);
            __dmb(0xBu);
            *v21 = 1;
LABEL_37:
            --v3;
            *v19 = *--v20;
            continue;
          }
        }
        ++v18;
        ++v19;
      }
      while ( v18 < v3 );
      if ( !v3 )
        return KfLowerIrql(v4);
    }
  }
  if ( v7 )
    return KfLowerIrql(v4);
  return result;
}
