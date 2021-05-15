// PopReadProducerConsumerBuffer 
 
int __fastcall PopReadProducerConsumerBuffer(int a1, int a2, int a3, _DWORD *a4, int a5, char a6)
{
  int v10; // r0
  unsigned int v11; // r1
  unsigned int v12; // r6
  int v13; // r5
  __int64 v14; // r0

  if ( !a6 && (unsigned int)(a1 - *a4 + a2) <= a4[1] )
    return a1;
  v10 = ReadTimeStampCounter();
  v12 = v11;
  v13 = v10;
  ProducerConsumerCopyFromContextBuffer(a3, a2, a4, a1);
  LODWORD(v14) = ReadTimeStampCounter();
  *(_QWORD *)(a5 + 56) = *(_QWORD *)(a5 + 56) - __PAIR64__(v12, v13) + v14;
  return a3;
}
