// RtlpInsertUCRBlock 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlpInsertUCRBlock(unsigned int a1, int *a2)
{
  int v3; // r1
  unsigned int v4; // r5
  int v5; // r0
  int **v6; // r3
  int result; // r0
  _DWORD *v8; // r2 OVERLAPPED
  int v9; // r1 OVERLAPPED
  _QWORD *v10; // r3

  v3 = a2[5];
  v4 = a1;
  if ( v3 )
  {
    v5 = RtlpFindUCREntry(a1, v3);
    v6 = *(int ***)(v5 + 4);
    if ( *v6 != (int *)v5 )
      return sub_5540D4();
    *a2 = v5;
    a2[1] = (int)v6;
    *v6 = a2;
    *(_DWORD *)(v5 + 4) = a2;
  }
  if ( *((_BYTE *)a2 - 2) )
    v4 = ((unsigned int)(a2 - 2) & 0xFFFF0000) - (*((unsigned __int8 *)a2 - 2) << 16) + 0x10000;
  v8 = (_DWORD *)(v4 + 56);
  v9 = *(_DWORD *)(v4 + 56);
  v10 = a2 + 2;
  result = *(_DWORD *)(v9 + 4);
  if ( result != v4 + 56 )
    return RtlpLogHeapFailure(12, 0);
  *v10 = *(_QWORD *)&v9;
  *(_DWORD *)(v9 + 4) = v10;
  *v8 = v10;
  return result;
}
