// VerifierBugCheckIfAppropriate 
 
// local variable allocation has failed, the output may be wrong!
int __fastcall VerifierBugCheckIfAppropriate(int result, int a2, int a3, int a4, int a5)
{
  int *v5; // r5
  unsigned int v8; // r6
  unsigned int v9; // r1
  unsigned int v10; // r1
  char *v11; // r2

  v5 = &ViVerifierBugcheckAttributes;
  v8 = 0;
  while ( *v5 != result || v5[1] != a2 )
  {
    ++v8;
    v5 += 3;
    if ( v8 >= 0xD )
      goto LABEL_5;
  }
  if ( VfVerifyMode >= v5[2] )
LABEL_5:
    KeBugCheckEx(result, a2, a3, a4, a5);
  __dmb(0xBu);
  do
  {
    v9 = __ldrex(&ViBugcheckLogIndex);
    v10 = v9 + 1;
  }
  while ( __strex(v10, &ViBugcheckLogIndex) );
  __dmb(0xBu);
  ViBugcheckLog[5 * (v10 & 0xF)] = result;
  v11 = (char *)&ViBugcheckLog[5 * (v10 & 0xF)];
  *(_QWORD *)(v11 + 4) = *(_QWORD *)&a2;
  *((_DWORD *)v11 + 3) = a4;
  *((_DWORD *)v11 + 4) = a5;
  return result;
}
