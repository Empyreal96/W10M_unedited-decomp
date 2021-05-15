// MiCreateNodeLists 
 
int __fastcall MiCreateNodeLists(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r4
  _DWORD *v5; // r6
  _DWORD *v6; // r7
  __int64 v7; // t1
  _DWORD *v8; // r0
  int v10[2]; // [sp+0h] [bp-20h] BYREF
  int v11; // [sp+8h] [bp-18h]
  int v12; // [sp+Ch] [bp-14h]

  v12 = a4;
  v11 = 0;
  v10[1] = (int)v10;
  v4 = 0;
  v10[0] = (int)v10;
  v5 = a1;
  v6 = a1;
  do
  {
    v7 = *((_QWORD *)v6 + 1);
    v6 += 2;
    if ( !MiDescribePageRun((int)v10, v7, SHIDWORD(v7)) )
      goto LABEL_6;
    ++v4;
  }
  while ( v4 != *v5 );
  v8 = (_DWORD *)ExAllocatePoolWithTag(512, 10 * v11 + 16, 1817013581);
  if ( !v8 )
LABEL_6:
    JUMPOUT(0x96B55E);
  v8[1] = 1;
  *v8 = MiSystemPartition;
  v8[2] = v11;
  v8[3] = v5[1];
  return sub_96B520();
}
