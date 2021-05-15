// BiAddBootEntryToNvramDisplayOrder 
 
int __fastcall BiAddBootEntryToNvramDisplayOrder(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r4
  int v6; // r6
  int v7; // r7
  int v8; // r5
  int *v9; // r1
  int v10; // t1
  int v11; // r0
  int *v13; // [sp+0h] [bp-20h] BYREF
  int v14[7]; // [sp+4h] [bp-1Ch] BYREF

  v14[0] = a3;
  v14[1] = a4;
  v13 = 0;
  v5 = 0;
  v6 = BiQueryBootEntryOrder((int *)&v13, v14, a3, 0);
  v7 = (int)v13;
  if ( v6 >= 0 )
  {
    v8 = 0;
    if ( v14[0] )
    {
      v9 = v13;
      while ( 1 )
      {
        v10 = *v9++;
        if ( v10 == *(_DWORD *)(*(_DWORD *)(a1 + 28) + 8) )
          break;
        if ( (unsigned int)++v8 >= v14[0] )
          goto LABEL_6;
      }
    }
    else
    {
LABEL_6:
      v11 = ExAllocatePoolWithTag(1, 4 * v8 + 4, 1262764866);
      v5 = (_DWORD *)v11;
      if ( v11 )
      {
        if ( v8 )
          memmove(v11 + 4, v7, 4 * v8);
        *v5 = *(_DWORD *)(*(_DWORD *)(a1 + 28) + 8);
        v6 = BiSetBootEntryOrder(v5, v8 + 1);
      }
      else
      {
        v6 = -1073741801;
      }
    }
  }
  if ( v7 )
    ExFreePoolWithTag(v7);
  if ( v5 )
    ExFreePoolWithTag((unsigned int)v5);
  return v6;
}
