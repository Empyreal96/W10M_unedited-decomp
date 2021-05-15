// PspWritePebAffinityInfo 
 
unsigned int *__fastcall PspWritePebAffinityInfo(unsigned int *result, _DWORD *a2)
{
  int v3; // r5
  int v4; // r9
  unsigned int *v5; // r0
  unsigned int v6; // r4
  unsigned int v7; // r1
  int v8; // r2
  int v9; // r2
  unsigned int *v10; // r1
  unsigned int v11; // r4
  unsigned int v12; // r1
  unsigned int v13; // [sp+10h] [bp-40h]
  _BYTE v14[56]; // [sp+18h] [bp-38h] BYREF

  v3 = 0;
  v4 = a2[80];
  if ( !v4 )
    return result;
  if ( !a2[44] )
    goto LABEL_15;
  if ( a2 == (_DWORD *)result[29] )
  {
    if ( a2 != (_DWORD *)result[84] )
      v3 = 2;
  }
  else
  {
    v3 = 3;
  }
  if ( (v3 & 2) == 0 )
    goto LABEL_13;
  v5 = a2 + 43;
  __pld(a2 + 43);
  v6 = a2[43] & 0xFFFFFFFE;
  do
    v7 = __ldrex(v5);
  while ( v7 == v6 && __strex(v6 + 2, v5) );
  __dmb(0xBu);
  if ( v7 == v6 || (result = (unsigned int *)ExfAcquireRundownProtection(v5)) != 0 )
  {
LABEL_13:
    if ( (v3 & 1) != 0 )
      KiStackAttachProcess((int)a2, 0, (int)v14);
    do
    {
      do
      {
LABEL_15:
        v13 = __clz(__rbit(KeQueryGroupMaskProcess((int)a2)));
        v8 = a2[v13 + 18];
      }
      while ( !v8 );
      *(_DWORD *)(v4 + 192) = v8;
      __dmb(0xFu);
      result = (unsigned int *)KeQueryGroupMaskProcess((int)a2);
    }
    while ( v10 != result || v9 != a2[v13 + 18] );
    if ( v3 )
    {
      if ( (v3 & 1) != 0 )
        result = (unsigned int *)KiUnstackDetachProcess((unsigned int)v14, 0);
      if ( (v3 & 2) != 0 )
      {
        result = a2 + 43;
        __pld(a2 + 43);
        v11 = a2[43] & 0xFFFFFFFE;
        __dmb(0xBu);
        do
          v12 = __ldrex(result);
        while ( v12 == v11 && __strex(v11 - 2, result) );
        if ( v12 != v11 )
          result = (unsigned int *)ExfReleaseRundownProtection((unsigned __int8 *)result);
      }
    }
  }
  return result;
}
