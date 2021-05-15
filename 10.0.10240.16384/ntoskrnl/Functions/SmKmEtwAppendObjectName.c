// SmKmEtwAppendObjectName 
 
int __fastcall SmKmEtwAppendObjectName(int *a1, int a2)
{
  int v2; // r8
  int v4; // r2
  int v5; // r10
  unsigned __int16 *v6; // r4
  int v7; // r3
  int v8; // r6
  int v9; // r5
  int v10; // r7
  int v11; // r6
  char *v12; // r1
  int v13; // r3
  int v14; // r4
  int result; // r0
  _WORD *v16; // r1
  _DWORD *v17; // r3
  int v18; // r1
  int v19; // r3
  int v20; // r2
  int v21; // r3
  _DWORD *v22; // r1
  int v23; // r3
  __int16 v24; // [sp+0h] [bp-48h]
  char v25[4]; // [sp+4h] [bp-44h] BYREF
  char v26[64]; // [sp+8h] [bp-40h] BYREF

  v2 = a2;
  qmemcpy(v26, "\\Device\\Unknown", 30);
  v4 = a1[4];
  v5 = v4 + a1[1];
  v6 = (unsigned __int16 *)((v5 + 5) & 0xFFFFFFFC);
  v7 = a1[5];
  v6[1] = 0;
  *v6 = 0;
  v8 = v7 - v4 - (_DWORD)v6;
  *((_DWORD *)v6 + 1) = 0;
  if ( (a2 & 1) != 0 )
  {
    v2 = IoGetDeviceAttachmentBaseRef(a2 & 0xFFFFFFFE);
    v9 = v2;
  }
  else
  {
    v9 = 0;
  }
  if ( v2 )
  {
    v10 = IoSetThreadHardErrorMode(0);
    v11 = ObQueryNameString(v2, (v5 + 5) & 0xFFFFFFFC, v8 + v5, v25);
    if ( v9 )
      ObfDereferenceObjectWithTag(v9);
    IoSetThreadHardErrorMode(v10);
  }
  else
  {
    v11 = -1073741809;
  }
  if ( v11 >= 0 && *v6 )
  {
    v12 = (char *)*((_DWORD *)v6 + 1);
    v13 = *v6 >> 1;
  }
  else
  {
    v12 = v26;
    v13 = 15;
  }
  v14 = 2 * v13;
  v24 = v13;
  result = memmove(v5 + 2, (int)v12, 2 * v13);
  v16 = (_WORD *)(a1[4] + a1[1]);
  *v16 = v24;
  v17 = (_DWORD *)(*a1 + 16 * a1[2]);
  v17[1] = 0;
  v17[2] = 2;
  *v17 = v16;
  v17[3] = 0;
  v18 = a1[2] + 1;
  v19 = a1[4];
  a1[2] = v18;
  v20 = v19 + 2;
  v21 = *a1;
  a1[4] = v20;
  v22 = (_DWORD *)(v21 + 16 * v18);
  v23 = a1[1];
  v22[1] = 0;
  v22[2] = v14;
  v22[3] = 0;
  *v22 = v23 + v20;
  ++a1[2];
  a1[4] += v14;
  return result;
}
