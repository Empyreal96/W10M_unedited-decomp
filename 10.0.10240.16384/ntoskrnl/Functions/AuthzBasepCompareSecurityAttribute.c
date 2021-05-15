// AuthzBasepCompareSecurityAttribute 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AuthzBasepCompareSecurityAttribute(int a1, int a2)
{
  int v4; // r6
  __int64 *v5; // r9 OVERLAPPED
  int v6; // r10 OVERLAPPED
  int *v7; // r4
  int *v8; // r8
  int v9; // r3

  v4 = 0;
  v5 = 0;
  v6 = 0;
  if ( *(_DWORD *)(a1 + 36) == *(_DWORD *)(a2 + 36)
    && *(unsigned __int16 *)(a1 + 24) == *(unsigned __int16 *)(a2 + 24)
    && *(_DWORD *)(a1 + 28) == *(_DWORD *)(a2 + 28) )
  {
    v7 = *(int **)(a1 + 44);
    v8 = (int *)(a1 + 44);
    while ( 1 )
    {
      if ( v7 == v8 )
        return 1;
      v9 = *(unsigned __int16 *)(a1 + 24);
      if ( *(_WORD *)(a1 + 24) )
      {
        if ( *(unsigned __int16 *)(a1 + 24) > 2u )
        {
          if ( *(unsigned __int16 *)(a1 + 24) <= 5u )
            goto LABEL_10;
          if ( v9 != 6 )
          {
            if ( v9 != 16 )
              goto LABEL_12;
LABEL_10:
            v5 = (__int64 *)(v7 + 6);
            v6 = 0;
            goto LABEL_12;
          }
        }
        *(_QWORD *)&v5 = *((_QWORD *)v7 + 3);
      }
LABEL_12:
      if ( !AuthzBasepFindSecurityAttributeValue(a2, a2, v5, v6, *(_WORD *)(a1 + 24)) )
        return v4;
      v7 = (int *)*v7;
    }
  }
  return v4;
}
