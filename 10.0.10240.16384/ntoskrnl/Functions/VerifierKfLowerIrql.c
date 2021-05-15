// VerifierKfLowerIrql 
 
int *__fastcall VerifierKfLowerIrql(int a1, int a2, int a3, int a4)
{
  int (__fastcall *v5)(int); // r5
  int v6; // r0
  unsigned int *v7; // r4
  int *result; // r0
  int v9[6]; // [sp+0h] [bp-18h] BYREF

  v9[1] = a3;
  v9[2] = a4;
  v5 = (int (__fastcall *)(int))pXdvKfLowerIrql;
  v6 = KeGetCurrentIrql(a1);
  v7 = (unsigned int *)ViKeLowerIrqlSanityChecks(v6, a1);
  if ( dword_61D04C )
    v5 = (int (__fastcall *)(int))dword_61D04C;
  result = (int *)v5(a1);
  if ( v7 )
  {
    *v7 = __mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0;
    result = KeQueryTickCount(v9);
    v7[2] = v9[0];
    if ( (VfOptionFlags & 0x40) != 0 )
    {
      v7[3] = 0;
    }
    else
    {
      result = (int *)RtlCaptureStackBackTrace(1u, 5u, (int)(v7 + 3), 0);
      if ( (unsigned int)result < 5 )
        v7[(_DWORD)result + 3] = 0;
    }
  }
  return result;
}
