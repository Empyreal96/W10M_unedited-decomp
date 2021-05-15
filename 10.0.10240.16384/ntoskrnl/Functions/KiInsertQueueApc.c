// KiInsertQueueApc 
 
int __fastcall KiInsertQueueApc(int a1)
{
  int v1; // r1
  int v2; // r5
  int v3; // r4
  _DWORD *v4; // r2
  _DWORD *i; // r1
  __int64 v6; // r0
  _DWORD *v7; // r2
  _QWORD *v8; // r2

  v1 = *(_DWORD *)(a1 + 8);
  if ( !*(_BYTE *)(a1 + 44) && *(_BYTE *)(v1 + 362) )
  {
    v2 = v1 + 372;
  }
  else
  {
    v2 = v1 + 100;
    *(_BYTE *)(a1 + 44) = *(_BYTE *)(v1 + 362);
  }
  v3 = *(char *)(a1 + 45);
  if ( *(_DWORD *)(a1 + 28) )
  {
    if ( *(_BYTE *)(a1 + 45) && *(int (**)())(a1 + 20) == KiSchedulerApcTerminate )
    {
      *(_BYTE *)(v1 + 122) = 1;
      v8 = (_QWORD *)(a1 + 12);
      LODWORD(v6) = *(_DWORD *)(v2 + 8 * v3);
      HIDWORD(v6) = v2 + 8 * v3;
      *v8 = v6;
      if ( *(_DWORD *)(v6 + 4) != HIDWORD(v6) )
        sub_52C7D4();
      *(_DWORD *)(v6 + 4) = v8;
      *(_DWORD *)HIDWORD(v6) = v8;
    }
    else
    {
      HIDWORD(v6) = v2 + 8 * v3;
      v7 = (_DWORD *)(a1 + 12);
      LODWORD(v6) = *(_DWORD *)(HIDWORD(v6) + 4);
      *v7 = HIDWORD(v6);
      v7[1] = v6;
      if ( *(_DWORD *)v6 != HIDWORD(v6) )
        __fastfail(3u);
      *(_DWORD *)v6 = v7;
      *(_DWORD *)(HIDWORD(v6) + 4) = v7;
    }
  }
  else
  {
    v4 = *(_DWORD **)(v2 + 8 * v3 + 4);
    for ( i = (_DWORD *)(v2 + 8 * v3); v4 != i; v4 = (_DWORD *)v4[1] )
    {
      if ( !v4[4] )
        break;
    }
    HIDWORD(v6) = a1 + 12;
    LODWORD(v6) = *v4;
    *(_DWORD *)HIDWORD(v6) = *v4;
    *(_DWORD *)(HIDWORD(v6) + 4) = v4;
    if ( *(_DWORD **)(v6 + 4) != v4 )
      __fastfail(3u);
    *(_DWORD *)(v6 + 4) = HIDWORD(v6);
    *v4 = HIDWORD(v6);
  }
  return v6;
}
