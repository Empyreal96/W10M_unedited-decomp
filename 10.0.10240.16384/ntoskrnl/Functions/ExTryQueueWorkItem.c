// ExTryQueueWorkItem 
 
int __fastcall ExTryQueueWorkItem(_DWORD *a1, int a2)
{
  int v3; // r7
  int v4; // r10
  int v5; // r9
  unsigned int v6; // r8
  unsigned int v7; // r1
  unsigned int v8; // r2
  int v9; // r4
  int v10; // r3
  int v11; // r3
  int v12; // r2
  BOOL v13; // r1
  int v14; // r2
  _DWORD *v15; // r5
  unsigned int v17; // r3
  int v18; // r1
  int v19; // r2
  int v20; // r3
  int v21; // [sp+8h] [bp-28h] BYREF
  int v22; // [sp+Ch] [bp-24h]

  v21 = 0;
  v3 = 0;
  if ( *a1 )
    sub_52D38C();
  if ( a2 < 32 && a2 >= 7 || a2 >= 64 )
    KeBugCheckEx(228, 6, a1);
  if ( a1[2] <= (unsigned int)MmUserProbeAddress )
    KeBugCheckEx(228, 7, a1);
  if ( (unsigned int)a2 < 7 )
    v4 = ExpBuiltinPriorities[a2];
  else
    v4 = a2 - 32;
  v5 = KfRaiseIrql(2);
  v22 = v5;
  v6 = *(unsigned __int16 *)(*(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xEB8) + 266);
  v7 = v6;
  if ( v6 < (unsigned __int16)KeNumberNodes )
  {
    v8 = v6;
    while ( 1 )
    {
      v9 = (int)*(&KeNodeBlock + v7);
      if ( (_UNKNOWN *)v9 != (_UNKNOWN *)((char *)&KiNodeInit + 384 * v8) )
      {
        if ( v9 )
        {
          v10 = *(_DWORD *)(v9 + 1016);
          __dmb(0xBu);
          if ( (v10 & 1) != 0 )
          {
            v11 = *(_DWORD *)(v9 + 384);
            if ( (v11 & 1) == 0 )
            {
              if ( v11 )
              {
                v12 = *(_DWORD *)(v11 + 424);
                __dmb(0xBu);
                v13 = (v12 & 0x4000) != 0;
                v14 = v12 & 0x3FFF;
                if ( v13 )
                  --v14;
                if ( v14 >= (2 * *(_DWORD *)(v11 + 428)) >> 1 )
                {
                  v15 = *(_DWORD **)(v9 + 384);
                  if ( ((unsigned __int8)v15 & 1) != 0 )
                    v15 = 0;
                  v3 = KeInsertPriQueue(v15, a1, v4);
                  if ( v3 )
                  {
LABEL_21:
                    v5 = v22;
                    break;
                  }
                  v17 = v15[107] | 0x80000000;
                  __dmb(0xBu);
                  v15[107] = v17;
                  v18 = v15[108];
                  v19 = v15[106];
                  __dmb(0xBu);
                  if ( v19 < (2 * v15[107]) >> 1
                    || v19 < v18
                    && (_DWORD *)v15[2] == v15 + 2
                    && (v15[1] || (v20 = v15[107], __dmb(0xBu), (v20 & 0x80000000) != 0)) )
                  {
                    KeSetEvent(v9 + 856, 0, 0);
                  }
                }
              }
            }
          }
        }
      }
      v7 = (unsigned __int16)MmGetNextNode(v6, &v21);
      v8 = v7;
      if ( v7 >= (unsigned __int16)KeNumberNodes )
        goto LABEL_21;
    }
  }
  KfLowerIrql(v5);
  return v3;
}
