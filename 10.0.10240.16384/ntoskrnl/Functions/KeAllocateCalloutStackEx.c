// KeAllocateCalloutStackEx 
 
int __fastcall KeAllocateCalloutStackEx(int a1, unsigned int a2, int a3, char **a4)
{
  char **v4; // r8
  int result; // r0
  int v7; // r0
  char *v8; // r4
  unsigned int v9; // r5
  int v10; // r8
  int v11; // r0
  char *v12; // r6

  v4 = a4;
  if ( a1 )
    return sub_8173B8();
  if ( !a2 )
    return -1073741584;
  if ( a3 )
    return -1073741583;
  v7 = ExAllocatePoolWithTag(512, 4 * (a2 + 10), 1666409803);
  v8 = (char *)v7;
  if ( !v7 )
    return -1073741801;
  v9 = 0;
  if ( a2 )
  {
    v10 = v7;
    while ( 1 )
    {
      v11 = MmCreateKernelStack(0, 0, 0);
      if ( !v11 )
        break;
      ++v9;
      *(_DWORD *)(v10 + 40) = v11;
      v10 += 4;
      if ( v9 >= a2 )
      {
        v4 = a4;
        goto LABEL_11;
      }
    }
    if ( v9 )
    {
      v12 = &v8[4 * v9];
      do
      {
        MmDeleteKernelStack(*((_DWORD *)v12 + 9), 0);
        --v9;
        v12 -= 4;
      }
      while ( v9 );
    }
    ExFreePoolWithTag((unsigned int)v8);
    result = -1073741670;
  }
  else
  {
LABEL_11:
    strcpy(v8, "Stak");
    v8[6] = 0;
    v8[5] = a2;
    KeInitializeMutex((int)(v8 + 8));
    *v4 = v8;
    result = 0;
  }
  return result;
}
