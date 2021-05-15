// EtwpAllocatePayloadFilterData 
 
int __fastcall EtwpAllocatePayloadFilterData(int a1, int *a2, _DWORD *a3)
{
  int v4; // r5
  int v6; // r4
  _DWORD *v7; // r0
  _DWORD *v8; // r5
  unsigned int v9; // r2
  int v10; // r1

  v4 = a2[2];
  v6 = EtwpValidatePayloadFilter(a1, *a2, v4);
  if ( v6 >= 0 )
  {
    v7 = (_DWORD *)ExAllocatePoolWithTag(512, v4 + 8, 1182233669);
    v8 = v7;
    if ( v7 )
    {
      v9 = a2[2];
      v10 = *a2;
      *v7 = 1;
      memmove((int)(v7 + 2), v10, v9);
      *a3 = v8;
    }
    else
    {
      v6 = -1073741801;
    }
  }
  return v6;
}
