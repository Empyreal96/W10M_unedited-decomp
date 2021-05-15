// FstubDetectPartitionStyle 
 
int __fastcall FstubDetectPartitionStyle(int a1, int *a2)
{
  int result; // r0
  int v5; // r1
  int v6; // r3

  result = FstubReadSectors(*(_DWORD *)a1, *(_DWORD *)(a1 + 4), 0i64, 1, *(_DWORD *)(a1 + 40));
  if ( result >= 0 )
  {
    v5 = *(_DWORD *)(a1 + 40);
    *a2 = -1;
    if ( *(unsigned __int16 *)(v5 + 510) == 43605 )
    {
      if ( *(unsigned __int8 *)(v5 + 450) == 238
        && !*(_BYTE *)(v5 + 466)
        && !*(_BYTE *)(v5 + 482)
        && !*(_BYTE *)(v5 + 498) )
      {
        *a2 = 1;
        goto LABEL_6;
      }
      v6 = 0;
    }
    else
    {
      v6 = 2;
    }
    *a2 = v6;
LABEL_6:
    result = 0;
  }
  return result;
}
