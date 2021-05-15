// PopLoggingInformation 
 
int __fastcall PopLoggingInformation(unsigned int **a1, unsigned int *a2)
{
  int v2; // r7
  unsigned int v3; // r4
  int *v4; // r2
  unsigned int v7; // r5
  int v8; // r3
  unsigned int *v9; // r0
  int v10; // r6
  _DWORD *v11; // r5
  int *v12; // r8
  unsigned int v13; // r4

  v2 = 0;
  v3 = 4;
  v4 = (int *)PowerStateDisableReasonListHead;
  if ( (int *)PowerStateDisableReasonListHead != &PowerStateDisableReasonListHead )
  {
    do
    {
      v7 = v3 + 16;
      ++v2;
      if ( v3 + 16 < v3 )
        return -1073741675;
      v8 = v4[5];
      v3 = v8 + v7;
      if ( v8 + v7 < v7 )
        return -1073741675;
      v4 = (int *)*v4;
    }
    while ( v4 != &PowerStateDisableReasonListHead );
    if ( v2 )
      goto LABEL_7;
  }
  v3 += 16;
LABEL_7:
  v9 = (unsigned int *)ExAllocatePoolWithTag(1, v3, 1718968931);
  if ( !v9 )
    return -1073741670;
  *a2 = v3;
  *a1 = v9;
  v10 = 0;
  v11 = v9 + 1;
  *v9 = v3;
  if ( v2 )
  {
    v12 = (int *)PowerStateDisableReasonListHead;
    while ( v12 != &PowerStateDisableReasonListHead && v2 )
    {
      v13 = v12[5] + 16;
      memmove((int)v11, (int)(v12 + 2), v13);
      v12 = (int *)*v12;
      v11 = (_DWORD *)((char *)v11 + v13);
      --v2;
    }
  }
  else
  {
    *v11 = 0;
    v9[2] = 0;
    v9[3] = 0;
    v9[4] = 0;
    v9[3] = 0;
  }
  return v10;
}
