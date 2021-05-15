// RtlInitEnumerationHashTable 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall RtlInitEnumerationHashTable(int a1, int a2, int a3, int a4)
{
  int v6; // r0
  int *v7; // r2 OVERLAPPED
  _DWORD *v8; // r1 OVERLAPPED
  int *v10; // [sp+0h] [bp-18h]
  int v11; // [sp+4h] [bp-14h]
  int v12; // [sp+8h] [bp-10h]
  int v13; // [sp+Ch] [bp-Ch]

  v10 = (int *)a1;
  v11 = a2;
  v12 = a3;
  v13 = a4;
  v6 = RtlpPopulateContext();
  v7 = v10;
  ++*(_DWORD *)(a1 + 28);
  if ( (int *)*v7 == v7 )
    ++*(_DWORD *)(a1 + 24);
  v8 = (_DWORD *)*v7;
  *(_QWORD *)a2 = *(_QWORD *)(&v7 - 1);
  if ( (int *)v8[1] != v7 )
    sub_50B828(v6);
  v8[1] = a2;
  *v7 = a2;
  *(_QWORD *)(a2 + 12) = (unsigned int)v7;
  *(_DWORD *)(a2 + 8) = 0;
  return 1;
}
