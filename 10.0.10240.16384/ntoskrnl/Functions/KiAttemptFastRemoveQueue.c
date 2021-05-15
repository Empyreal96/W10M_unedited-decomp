// KiAttemptFastRemoveQueue 
 
unsigned int __fastcall KiAttemptFastRemoveQueue(int a1, int **a2, unsigned int a3)
{
  unsigned int result; // r0
  int *v7; // r1
  int v8; // r5
  int **v9; // r4

  result = 0;
  v7 = *(int **)(a1 + 16);
  do
  {
    --*(_DWORD *)(a1 + 4);
    v8 = *v7;
    if ( !*v7 )
      KeBugCheck2(150, v7, a1, ExWorkerQueue, v7[2], 0);
    v9 = (int **)v7[1];
    if ( *(int **)(v8 + 4) != v7 || *v9 != v7 )
      sub_522338();
    *v9 = (int *)v8;
    *(_DWORD *)(v8 + 4) = v9;
    *v7 = 0;
    *a2++ = v7;
    v7 = *(int **)(a1 + 16);
    ++result;
  }
  while ( v7 != (int *)(a1 + 16) && result < a3 );
  return result;
}
