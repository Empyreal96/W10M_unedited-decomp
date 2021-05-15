// AlpcpCaptureMessageData 
 
int __fastcall AlpcpCaptureMessageData(_DWORD *a1, unsigned int a2, int a3)
{
  unsigned int v6; // r6
  unsigned int v7; // r0
  unsigned int v8; // r5
  int v9; // r0
  int v10; // lr
  int v11; // r5
  unsigned int v13; // r0
  int v14; // r0
  unsigned int v15; // r1
  unsigned int *v16; // r5
  int v17; // r3
  unsigned int v18; // r2
  int v19; // r0
  unsigned int *v20; // r1
  int v21; // r3
  unsigned int v22; // r2
  unsigned int v23; // r3
  unsigned int *v24; // r5
  unsigned int v25; // r0
  unsigned int v26; // r1
  int v27; // r0
  unsigned int *v28; // r1
  int v29; // r3
  unsigned int v30; // r2
  unsigned int v31; // [sp+0h] [bp-20h]

  if ( a2 > 0x100 )
  {
    if ( a2 > 0xFFD7 )
      return -2147483643;
    v6 = a1[28];
    if ( a2 > v6 + 256 )
    {
      v7 = a1[27];
      if ( v7 )
      {
        ExFreePoolWithTag(v7);
        a1[28] = 0;
      }
      v8 = a2 - 256;
      v9 = ExAllocatePoolWithTag(1, a2 - 256, 1111845953);
      a1[27] = v9;
      if ( !v9 )
      {
        v19 = a1[7];
        if ( v19 )
        {
          v20 = (unsigned int *)(v19 + 668);
          v21 = *(_DWORD *)(v19 + 668);
          __dmb(0xBu);
          if ( v21 + v6 >= 0x1000 )
          {
            PsReturnProcessPagedPoolQuota(v19, v6);
          }
          else
          {
            __dmb(0xBu);
            do
              v22 = __ldrex(v20);
            while ( __strex(v22 + v6, v20) );
            __dmb(0xBu);
          }
        }
        return -1073741670;
      }
      v10 = a1[7];
      a1[28] = v8;
      if ( v10 )
      {
        v23 = v8 - v6;
        v24 = (unsigned int *)(v10 + 668);
        __pld((void *)(v10 + 668));
        v31 = v23;
        v25 = *(_DWORD *)(v10 + 668);
        __dmb(0xBu);
        while ( 1 )
        {
          if ( v25 < v23 )
          {
            v11 = PsChargeProcessPagedPoolQuota(v10, v23);
            goto LABEL_39;
          }
          __dmb(0xBu);
          do
            v26 = __ldrex(v24);
          while ( v26 == v25 && __strex(v25 - v23, v24) );
          __dmb(0xBu);
          if ( v26 == v25 )
            break;
          v25 = *v24;
          __dmb(0xBu);
          v23 = v31;
        }
        v11 = 0;
LABEL_39:
        if ( v11 < 0 )
        {
          ExFreePoolWithTag(a1[27]);
          v27 = a1[7];
          a1[27] = 0;
          a1[28] = 0;
          if ( v27 )
          {
            v28 = (unsigned int *)(v27 + 668);
            v29 = *(_DWORD *)(v27 + 668);
            __dmb(0xBu);
            if ( v29 + v6 >= 0x1000 )
            {
              PsReturnProcessPagedPoolQuota(v27, v6);
            }
            else
            {
              __dmb(0xBu);
              do
                v30 = __ldrex(v28);
              while ( __strex(v30 + v6, v28) );
              __dmb(0xBu);
            }
          }
          return v11;
        }
      }
    }
    if ( a3 )
    {
      memmove((int)(a1 + 36), a3, 0x100u);
      memmove(a1[27], a3 + 256, a2 - 256);
    }
    return 0;
  }
  if ( !a3 )
  {
    v13 = a1[27];
    if ( v13 )
    {
      ExFreePoolWithTag(v13);
      v14 = a1[7];
      a1[27] = 0;
      if ( v14 )
      {
        v15 = a1[28];
        v16 = (unsigned int *)(v14 + 668);
        v17 = *(_DWORD *)(v14 + 668);
        __dmb(0xBu);
        if ( v17 + v15 >= 0x1000 )
        {
          PsReturnProcessPagedPoolQuota(v14, v15);
        }
        else
        {
          __dmb(0xBu);
          do
            v18 = __ldrex(v16);
          while ( __strex(v18 + v15, v16) );
          __dmb(0xBu);
        }
      }
      a1[28] = 0;
    }
    return 0;
  }
  return sub_7F7FFC();
}
