// PipAddRequestToEdge 
 
int __fastcall PipAddRequestToEdge(int a1, int *a2)
{
  _DWORD *v2; // r7
  _DWORD *v3; // r9
  _DWORD *v4; // r4
  _DWORD *v5; // r5
  _DWORD *v8; // r0
  int v9; // r3
  int v10; // r0
  _DWORD *v11; // r8
  int v12; // r2
  _DWORD *v14; // r2

  v2 = (_DWORD *)(a1 + 28);
  v3 = *(_DWORD **)(a1 + 28);
  v4 = 0;
  v5 = 0;
  if ( v3 != (_DWORD *)(a1 + 28) )
  {
    while ( !v5 )
    {
      v11 = v3;
      v12 = v3[2];
      v3 = (_DWORD *)*v3;
      if ( v12 == *a2 )
      {
        if ( !v12 )
          return sub_811520();
        if ( v12 == 1 && RtlEqualUnicodeString((unsigned __int16 *)v11[3], (unsigned __int16 *)a2[1], 0) )
          v5 = v11;
      }
      if ( v3 == v2 )
      {
        if ( !v5 )
          goto LABEL_2;
        break;
      }
    }
    v5[4] |= a2[2];
    goto LABEL_17;
  }
LABEL_2:
  v8 = (_DWORD *)ExAllocatePoolWithTag(1, 20, 1399877200);
  v4 = v8;
  if ( v8 )
  {
    v8[4] = a2[2];
    v9 = *a2;
    v8[2] = *a2;
    if ( !v9 )
    {
      v8[3] = a2[1];
LABEL_24:
      v14 = (_DWORD *)v2[1];
      *v4 = v2;
      v4[1] = v14;
      if ( (_DWORD *)*v14 != v2 )
        __fastfail(3u);
      *v14 = v4;
      v2[1] = v4;
LABEL_17:
      if ( v5 )
        v4 = v5;
      if ( v4 )
        PipMergeDependencyTypes(a1, a2[2]);
      return (int)v4;
    }
    if ( v9 != 1 )
      goto LABEL_24;
    v10 = ExAllocatePoolWithTag(1, 8, 1399877200);
    v4[3] = v10;
    if ( RtlDuplicateUnicodeString(0, a2[1], v10) >= 0 )
      goto LABEL_24;
    PipFreeBindingRequestEntry(v4);
    v4 = 0;
  }
  return (int)v4;
}
