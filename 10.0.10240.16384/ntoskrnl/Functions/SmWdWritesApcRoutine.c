// SmWdWritesApcRoutine 
 
unsigned __int8 *__fastcall SmWdWritesApcRoutine(int a1, int a2, int a3, int **a4)
{
  int *v4; // r6
  int v5; // r4
  unsigned int v6; // r3
  unsigned int *v7; // r2
  unsigned int v8; // r1
  unsigned __int8 *result; // r0
  unsigned int v10; // r4
  unsigned int v11; // r1
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[0] = 0;
  v12[1] = v12;
  v4 = *a4;
  v5 = **a4;
  SmWdRemoveWorkItems((struct _SMKM_STORE_QUEUE *)(v5 + 3536), (struct _PF_QUEUE *)v12, 0);
  SmWdCompleteWorkItems((struct _PF_QUEUE *)v12, (void *)v5, -1073741536, v6);
  __dmb(0xBu);
  v7 = (unsigned int *)(v4 + 22);
  do
    v8 = __ldrex(v7);
  while ( __strex(0, v7) );
  __dmb(0xBu);
  result = (unsigned __int8 *)(v4 + 2);
  __pld(v4 + 2);
  v10 = v4[2] & 0xFFFFFFFE;
  __dmb(0xBu);
  do
    v11 = __ldrex((unsigned int *)result);
  while ( v11 == v10 && __strex(v10 - 2, (unsigned int *)result) );
  if ( v11 != v10 )
    result = ExfReleaseRundownProtection(result);
  return result;
}
