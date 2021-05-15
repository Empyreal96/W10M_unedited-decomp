// WheapInitializeErrorSource 
 
int __fastcall WheapInitializeErrorSource(_DWORD *a1)
{
  int v1; // r3
  int (__fastcall *v4)(char *, _DWORD *); // r3
  int v5; // r7
  int v6; // r6
  _BYTE *v7; // r0
  _BYTE *v8; // r5
  int v9; // r7
  unsigned int i; // r8

  v1 = *(_DWORD *)((char *)a1 + 81);
  if ( v1 >= 12 )
    return -1073741811;
  v4 = (int (__fastcall *)(char *, _DWORD *))dword_649F5C[7 * v1];
  __dmb(0xBu);
  if ( v4((char *)a1 + 73, a1 + 12) >= 0 )
  {
    a1[3] = *(_DWORD *)((char *)a1 + 105);
    a1[5] = *(_DWORD *)((char *)a1 + 93);
    v5 = a1[5];
    v6 = ((a1[12] + 72) * *(_DWORD *)((char *)a1 + 97) + 159) & 0xFFFFFFFC;
    a1[6] = v6;
    a1[7] = 1634035799;
    a1[8] = *(_DWORD *)((char *)a1 + 81);
    a1[11] = *(_DWORD *)((char *)a1 + 97);
    if ( v5 )
    {
      v7 = (_BYTE *)ExAllocatePoolWithTag(512, v5 * v6, 1634035799);
      v8 = v7;
      if ( !v7 )
        return -1073741670;
      memset(v7, 0, v5 * v6);
      v9 = (int)v8;
      for ( i = 0; i < a1[5]; v9 += v6 )
      {
        WheapInitializeErrorRecordWrapper(v9, v6, (int)a1);
        ++i;
      }
      a1[9] = v8;
    }
  }
  return 0;
}
