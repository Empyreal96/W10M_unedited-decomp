// IopRetestConfiguration 
 
int __fastcall IopRetestConfiguration(int *a1, unsigned int a2, int ***a3)
{
  int **v4; // r5
  int result; // r0
  int *v8; // r2
  int v9; // r3
  int v10; // r4
  int v11[10]; // [sp+8h] [bp-28h] BYREF

  v4 = *a3;
  result = 0;
  while ( v4 != (int **)a3 )
  {
    v8 = (int *)(v4 - 11);
    v9 = *((unsigned __int8 *)v4 + 9);
    v4 = (int **)*v4;
    if ( v9 )
    {
      v10 = v8[3];
      v11[0] = (int)(v8 + 5);
      v11[1] = 0;
      v11[2] = 0;
      PnpLookupArbitersNewResources(a1, a2, v8[4]);
      result = (*(int (__fastcall **)(_DWORD, int, int *))(v10 + 16))(*(_DWORD *)(v10 + 4), 1, v11);
      if ( result < 0 )
        break;
    }
  }
  return result;
}
