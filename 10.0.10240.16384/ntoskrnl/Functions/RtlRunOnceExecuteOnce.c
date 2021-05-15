// RtlRunOnceExecuteOnce 
 
int __fastcall RtlRunOnceExecuteOnce(int a1, int (__fastcall *a2)(int, int, int *), int a3, int *a4)
{
  unsigned int v8; // r5
  int v9; // r0
  int v10; // r5
  unsigned int v11; // r1
  __int16 v12; // r3
  int result; // r0
  int v14; // r2
  unsigned int v15; // r1
  __int16 v16; // r3

  v8 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  --*(_WORD *)(v8 + 308);
  v9 = RtlRunOnceBeginInitialize(a1, 0, a4);
  v10 = v9;
  if ( v9 < 0 )
    goto LABEL_15;
  if ( v9 == 259 )
  {
    if ( a2(a1, a3, a4) )
    {
      if ( a4 )
        v14 = *a4;
      else
        v14 = 0;
      v9 = RtlRunOnceComplete(a1, 0, v14);
      v10 = v9;
      if ( v9 >= 0 )
      {
        v10 = 0;
        goto LABEL_3;
      }
    }
    else
    {
      v10 = -1073741823;
      v9 = RtlRunOnceComplete(a1, 4, 0);
      if ( v9 >= 0 )
        goto LABEL_3;
      v10 = v9;
    }
LABEL_15:
    v15 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    v16 = *(_WORD *)(v15 + 0x134) + 1;
    *(_WORD *)(v15 + 308) = v16;
    if ( !v16 && *(_DWORD *)(v15 + 100) != v15 + 100 && !*(_WORD *)(v15 + 310) )
      KiCheckForKernelApcDelivery(v9);
    RtlRaiseStatus(v10);
  }
LABEL_3:
  v11 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
  v12 = *(_WORD *)(v11 + 0x134) + 1;
  *(_WORD *)(v11 + 308) = v12;
  if ( v12 || *(_DWORD *)(v11 + 100) == v11 + 100 )
    result = v10;
  else
    result = sub_7D5258();
  return result;
}
