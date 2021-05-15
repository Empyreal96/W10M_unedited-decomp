// AlpcpCaptureMessageDataSafe 
 
int __fastcall AlpcpCaptureMessageDataSafe(int result, int a2)
{
  _DWORD *v2; // r4
  int v3; // r5
  unsigned int v4; // r6
  unsigned int v5; // r1
  unsigned int *v6; // r5
  int v7; // r3
  unsigned int v8; // r2
  unsigned int v9; // r9
  unsigned int v10; // r0
  int v11; // r0
  unsigned int *v12; // r1
  int v13; // r3
  unsigned int v14; // r2
  unsigned int v15; // r3
  unsigned int v16; // r2
  unsigned int *v17; // lr
  unsigned int v18; // r3
  unsigned int *v19; // r1
  int v20; // r3
  unsigned int v21; // r2
  unsigned int v22; // r2
  unsigned int v23; // r1
  unsigned int v24; // [sp+0h] [bp-28h]
  int v25; // [sp+4h] [bp-24h]
  unsigned int v26; // [sp+8h] [bp-20h]
  int vars8; // [sp+30h] [bp+8h]

  v2 = (_DWORD *)result;
  vars8 = result;
  v3 = *(_DWORD *)(result + 88);
  v4 = *(unsigned __int16 *)(result + 120);
  if ( v4 <= 0x100 )
  {
    if ( v3 )
      memmove(result + 144, v3, *(unsigned __int16 *)(result + 120));
    result = v2[27];
    if ( result )
    {
      ExFreePoolWithTag(result);
      v2[27] = 0;
      result = v2[7];
      if ( result )
      {
        v5 = v2[28];
        v6 = (unsigned int *)(result + 668);
        v7 = *(_DWORD *)(result + 668);
        __dmb(0xBu);
        if ( v7 + v5 >= 0x1000 )
        {
          result = PsReturnProcessPagedPoolQuota(result, v5);
        }
        else
        {
          __dmb(0xBu);
          do
            v8 = __ldrex(v6);
          while ( __strex(v8 + v5, v6) );
          __dmb(0xBu);
        }
      }
      v2[28] = 0;
    }
    return result;
  }
  if ( v4 > 0xFFD7 )
    return result;
  v9 = *(_DWORD *)(result + 112);
  if ( v4 > v9 + 256 )
  {
    v10 = *(_DWORD *)(result + 108);
    if ( v10 )
    {
      ExFreePoolWithTag(v10);
      v2[28] = 0;
    }
    v11 = ExAllocatePoolWithTag(1, v4 - 256, 1111845953);
    v2[27] = v11;
    if ( !v11 )
    {
      result = v2[7];
      if ( !result )
        return result;
      v12 = (unsigned int *)(result + 668);
      v13 = *(_DWORD *)(result + 668);
      __dmb(0xBu);
      if ( v13 + v9 < 0x1000 )
      {
        __dmb(0xBu);
        do
          v14 = __ldrex(v12);
        while ( __strex(v14 + v9, v12) );
LABEL_21:
        __dmb(0xBu);
        return result;
      }
      return PsReturnProcessPagedPoolQuota(result, v9);
    }
    v15 = v4 - 256;
    v2[28] = v4 - 256;
    result = v2[7];
    v25 = result;
    if ( result )
    {
      v16 = v15 - v9;
      v26 = v15 - v9;
      v17 = (unsigned int *)(result + 668);
      __pld((void *)(result + 668));
      while ( 1 )
      {
        v18 = *v17;
        v24 = *v17;
        __dmb(0xBu);
        if ( v18 < v16 )
          break;
        __dmb(0xBu);
        v22 = v18 - v16;
        do
          v23 = __ldrex(v17);
        while ( v23 == v24 && __strex(v22, v17) );
        __dmb(0xBu);
        result = v25;
        if ( v23 == v24 )
          goto LABEL_37;
        v16 = v26;
      }
      result = PsChargeProcessPagedPoolQuota(result, v16);
      if ( result < 0 )
      {
        ExFreePoolWithTag(v2[27]);
        v2[27] = 0;
        v2[28] = 0;
        result = v2[7];
        if ( !result )
          return result;
        v19 = (unsigned int *)(result + 668);
        v20 = *(_DWORD *)(result + 668);
        __dmb(0xBu);
        if ( v20 + v9 < 0x1000 )
        {
          __dmb(0xBu);
          do
            v21 = __ldrex(v19);
          while ( __strex(v21 + v9, v19) );
          goto LABEL_21;
        }
        return PsReturnProcessPagedPoolQuota(result, v9);
      }
    }
  }
LABEL_37:
  if ( v3 )
  {
    memmove((int)(v2 + 36), v3, 0x100u);
    result = memmove(v2[27], v3 + 256, v4 - 256);
  }
  return result;
}
