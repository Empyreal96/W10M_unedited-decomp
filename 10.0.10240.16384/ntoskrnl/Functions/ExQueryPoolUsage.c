// ExQueryPoolUsage 
 
int *__fastcall ExQueryPoolUsage(_DWORD *a1, _DWORD *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5, int *a6, int *a7, _DWORD *a8)
{
  int *v8; // r10
  unsigned int v9; // r7
  _DWORD *v10; // t1
  int v11; // r9
  int v12; // lr
  int *result; // r0
  int *i; // r1
  int v15; // r2

  *a1 = 0;
  *a3 = 0;
  *a4 = 0;
  v8 = &ExpPagedPoolDescriptor;
  v9 = 0;
  if ( ExpNumberOfPagedPools != -1 )
  {
    do
    {
      v10 = (_DWORD *)*v8++;
      ++v9;
      *a1 += v10[34] + v10[96];
      *a3 += v10[32];
      *a4 += v10[33];
    }
    while ( v9 < ExpNumberOfPagedPools + 1 );
  }
  v11 = dword_645000 + dword_643D80;
  v12 = dword_645004 + unk_643D84;
  if ( (unsigned int)ExpNumberOfNonPagedPools > 1 )
    return (int *)sub_517330();
  *a2 = dword_643E80 + dword_645008 + dword_643D88 + dword_645100;
  result = &ExPoolLookasideListHead;
  *a6 = v11;
  *a7 = v12;
  *a5 = 0;
  *a8 = 0;
  for ( i = (int *)ExPoolLookasideListHead; i != &ExPoolLookasideListHead; i = (int *)*i )
  {
    v15 = *(i - 8);
    if ( *(i - 5) )
      *a5 += v15;
    else
      *a8 += v15;
  }
  return result;
}
