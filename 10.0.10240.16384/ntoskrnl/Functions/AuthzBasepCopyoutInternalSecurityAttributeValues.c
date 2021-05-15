// AuthzBasepCopyoutInternalSecurityAttributeValues 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall AuthzBasepCopyoutInternalSecurityAttributeValues(int a1, int a2, unsigned int a3, int a4, _DWORD *a5)
{
  int v6; // r7
  unsigned int v7; // r9
  int v8; // r4
  unsigned int v10; // r1
  int *v11; // r6
  unsigned int v12; // r5
  int *v13; // lr
  unsigned int v14; // r0
  int v15; // r1 OVERLAPPED
  unsigned int *v16; // r2 OVERLAPPED
  int v18; // r3
  unsigned int v19; // r7
  int v20; // [sp+0h] [bp-28h]

  v6 = a2;
  v7 = a3 + a4;
  v8 = 0;
  if ( a3 + a4 < a3 )
    return -2147483643;
  v10 = a3 + 7;
  *a5 = 0;
  if ( ((a3 + 7) & 0xFFFFFFF8) + 40 * *(_DWORD *)(a1 + 36) > v7 )
    return -2147483643;
  v11 = *(int **)(a1 + 44);
  v12 = v10 & 0xFFFFFFF8;
  v13 = (int *)(a1 + 44);
  v14 = (v10 & 0xFFFFFFF8) + 40 * *(_DWORD *)(a1 + 36);
  if ( v11 == (int *)(a1 + 44) )
  {
LABEL_10:
    *a5 = v14 - a3;
  }
  else
  {
    v15 = v6 + 44;
    v20 = v6 + 44;
    while ( 1 )
    {
      *(_DWORD *)(v12 + 16) = 0;
      if ( !*(_WORD *)(a1 + 24) )
        break;
      if ( *(unsigned __int16 *)(a1 + 24) > 2u )
      {
        if ( *(_WORD *)(a1 + 24) != 3 )
          return sub_520994(v14);
        v18 = *((unsigned __int16 *)v11 + 12);
        v19 = v18 + v14;
        if ( v18 + v14 > v7 )
          return -2147483643;
        *(_DWORD *)(v12 + 28) = v14;
        *(_WORD *)(v12 + 24) = 0;
        *(_WORD *)(v12 + 26) = v18;
        RtlCopyUnicodeString(v12 + 24, v11 + 6);
        v15 = v20;
        v14 = v19;
        v6 = a2;
        v13 = (int *)(a1 + 44);
      }
      else
      {
        *(_DWORD *)(v12 + 24) = v11[6];
        *(_DWORD *)(v12 + 28) = v11[7];
      }
      v16 = *(unsigned int **)(v15 + 4);
      *(_QWORD *)v12 = *(_QWORD *)&v15;
      if ( *v16 != v15 )
        __fastfail(3u);
      *v16 = v12;
      *(_DWORD *)(v15 + 4) = v12;
      v12 += 40;
      ++*(_DWORD *)(v6 + 36);
      v11 = (int *)*v11;
      if ( v11 == v13 )
        goto LABEL_10;
    }
    v8 = -1073741811;
  }
  return v8;
}
