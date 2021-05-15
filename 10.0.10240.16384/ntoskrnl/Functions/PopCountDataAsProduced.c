// PopCountDataAsProduced 
 
int __fastcall PopCountDataAsProduced(int a1, int a2, _DWORD *a3, int a4, int a5, int a6)
{
  int v7; // r6
  int v9; // r8
  int v10; // r9
  int v11; // r0
  int v12; // r7
  __int64 v14; // r0
  __int64 v15; // r4
  __int64 v16; // r0
  int varg_r0; // [sp+30h] [bp+8h]
  int varg_r1; // [sp+34h] [bp+Ch]
  _DWORD *varg_r2; // [sp+38h] [bp+10h]
  int varg_r3; // [sp+3Ch] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  v7 = dword_61EF00;
  v9 = (unsigned __int8)*a3;
  v10 = ((*a3 >> 8) & 0x3FFFFF) + 4 * v9;
  v11 = ProducerGetBuffer(dword_61EF00, v10 + 4, a5 << 12, a6);
  v12 = v11;
  if ( !v11 )
    return 0;
  ProducerConsumerCopyToContextBuffer(a3, 4, v7, v11);
  ProducerConsumerCopyToContextBuffer(a4, 4 * v9, v7, v12 + 4);
  ProducerConsumerCopyToContextBuffer(a2, (*a3 >> 8) & 0x3FFFFF, v7, v12 + 4 * v9 + 4);
  LODWORD(v14) = ReadTimeStampCounter();
  v15 = v14;
  ProducerConsumerBufferComplete(v7, v7 + 24, v12, v10 + 4);
  LODWORD(v16) = ReadTimeStampCounter();
  *(_QWORD *)(a1 + 64) = *(_QWORD *)(a1 + 64) - v15 + v16;
  return 1;
}
